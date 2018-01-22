/*  RetroArch - A frontend for libretro.
 *  Copyright (C) 2010-2014 - Hans-Kristian Arntzen
 *  Copyright (C) 2011-2017 - Daniel De Matteis
 *
 *  RetroArch is free software: you can redistribute it and/or modify it under the terms
 *  of the GNU General Public License as published by the Free Software Found-
 *  ation, either version 3 of the License, or (at your option) any later version.
 *
 *  RetroArch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *  PURPOSE.  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along with RetroArch.
 *  If not, see <http://www.gnu.org/licenses/>.
 */

#include <string.h>
#include <retro_inline.h>
#include <retro_math.h>

#include "../drivers/d3d.h"
#include "../common/d3d_common.h"

#include "../video_driver.h"

#include "../../configuration.h"
#include "../../verbosity.h"

typedef struct d3d8_renderchain
{
   unsigned pixel_size;
   LPDIRECT3DDEVICE dev;
   const video_info_t *video_info;
   LPDIRECT3DTEXTURE tex;
   LPDIRECT3DVERTEXBUFFER vertex_buf;
   unsigned last_width;
   unsigned last_height;
   void *vertex_decl;
   unsigned tex_w;
   unsigned tex_h;
   uint64_t frame_count;
} d3d8_renderchain_t;

static void d3d8_renderchain_set_mvp(
      void *data,
      void *chain_data,
      void *shader_data,
      const void *mat_data)
{
   D3DMATRIX matrix;
   d3d_video_t      *d3d = (d3d_video_t*)data;

   d3d_matrix_identity(&matrix);

   d3d_set_transform(d3d->dev, D3DTS_PROJECTION, &matrix);
   d3d_set_transform(d3d->dev, D3DTS_VIEW, &matrix);

   if (mat_data)
      d3d_matrix_transpose(&matrix, mat_data);

   d3d_set_transform(d3d->dev, D3DTS_WORLD, &matrix);
}

static bool d3d8_renderchain_create_first_pass(void *data,
      const video_info_t *info)
{
   d3d_video_t *d3d          = (d3d_video_t*)data;
   LPDIRECT3DDEVICE d3dr     = (LPDIRECT3DDEVICE)d3d->dev;
   d3d8_renderchain_t *chain = (d3d8_renderchain_t*)d3d->renderchain_data;

   chain->vertex_buf         = d3d_vertex_buffer_new(d3dr, 4 * sizeof(Vertex),
         D3DUSAGE_WRITEONLY, D3DFVF_CUSTOMVERTEX, D3DPOOL_MANAGED,
         NULL);

   if (!chain->vertex_buf)
      return false;

   chain->tex = d3d_texture_new(d3dr, NULL,
         chain->tex_w, chain->tex_h, 1, 0,
         info->rgb32
         ?
         d3d_get_xrgb8888_format() : d3d_get_rgb565_format(),
         D3DPOOL_MANAGED, 0, 0, 0, NULL, NULL,
         false);

   if (!chain->tex)
      return false;

   d3d_set_sampler_address_u(d3dr, 0, D3DTADDRESS_BORDER);
   d3d_set_sampler_address_v(d3dr, 0, D3DTADDRESS_BORDER);
   d3d_set_render_state(d3dr, D3DRS_LIGHTING, 0);
   d3d_set_render_state(d3dr, D3DRS_CULLMODE, D3DCULL_NONE);
   d3d_set_render_state(d3dr, D3DRS_ZENABLE, FALSE);

   return true;
}

static void d3d8_renderchain_set_vertices(void *data, unsigned pass,
      unsigned vert_width, unsigned vert_height, uint64_t frame_count)
{
   unsigned width, height;
   d3d_video_t *d3d         = (d3d_video_t*)data;
   d3d8_renderchain_t *chain = d3d ? (d3d8_renderchain_t*)d3d->renderchain_data : NULL;

   video_driver_get_size(&width, &height);

   if (!chain)
      return;

   if (chain->last_width != vert_width || chain->last_height != vert_height)
   {
      Vertex vert[4];
      float tex_w, tex_h;
      void *verts        = NULL;

      chain->last_width  = vert_width;
      chain->last_height = vert_height;

      tex_w              = vert_width;
      tex_h              = vert_height;

      vert[0].x        = -1.0f;
      vert[0].y        =  1.0f;
      vert[0].z        =  1.0f;


      vert[1].x        =  1.0f;
      vert[1].y        =  1.0f;
      vert[1].z        =  1.0f;

      vert[2].x        = -1.0f;
      vert[2].y        = -1.0f;
      vert[2].z        =  1.0f;

      vert[3].x        =  1.0f;
      vert[3].y        = -1.0f;
      vert[3].z        =  1.0f;

      vert[0].u        = 0.0f;
      vert[0].v        = 0.0f;
      vert[1].v        = 0.0f;
      vert[2].u        = 0.0f;
      vert[1].u        = tex_w;
      vert[2].v        = tex_h;
      vert[3].u        = tex_w;
      vert[3].v        = tex_h;
#ifndef _XBOX1
      vert[1].u       /= chain->tex_w;
      vert[2].v       /= chain->tex_h;
      vert[3].u       /= chain->tex_w;
      vert[3].v       /= chain->tex_h;
#endif

      vert[0].color    = 0xFFFFFFFF;
      vert[1].color    = 0xFFFFFFFF;
      vert[2].color    = 0xFFFFFFFF;
      vert[3].color    = 0xFFFFFFFF;

      verts = d3d_vertex_buffer_lock(chain->vertex_buf);
      memcpy(verts, vert, sizeof(vert));
      d3d_vertex_buffer_unlock(chain->vertex_buf);
   }
}

static void d3d8_renderchain_blit_to_texture(void *data, const void *frame,
   unsigned width, unsigned height, unsigned pitch)
{
   D3DLOCKED_RECT d3dlr;
   d3d8_renderchain_t *chain = (d3d8_renderchain_t*)data;
   LPDIRECT3DDEVICE d3dr     = (LPDIRECT3DDEVICE)chain->dev;

   d3d_frame_postprocess(chain);

   if (chain->last_width != width || chain->last_height != height)
   {
      d3d_lock_rectangle(chain->tex,
            0, &d3dlr, NULL, chain->tex_h, D3DLOCK_NOSYSLOCK);
      d3d_lock_rectangle_clear(chain->tex,
            0, &d3dlr, NULL, chain->tex_h, D3DLOCK_NOSYSLOCK);
   }

   /* Set the texture to NULL so D3D doesn't complain about it being in use... */
   d3d_set_texture(d3dr, 0, NULL);

   if (d3d_lock_rectangle(chain->tex, 0, &d3dlr, NULL, 0, 0))
   {
      d3d_texture_blit(chain->pixel_size, chain->tex,
            &d3dlr, frame, width, height, pitch);
      d3d_unlock_rectangle(chain->tex);
   }
}

static void d3d8_renderchain_free(void *data)
{
   d3d8_renderchain_t *chain = (d3d8_renderchain_t*)data;

   if (!chain)
      return;

   if (chain->tex)
      d3d_texture_free(chain->tex);
   d3d_vertex_buffer_free(chain->vertex_buf, chain->vertex_decl);

#if 0
   if (chain->tracker)
      state_tracker_free(chain->tracker);
#endif

   free(chain);
}


void *d3d8_renderchain_new(void)
{
   d3d8_renderchain_t *renderchain = (d3d8_renderchain_t*)calloc(1, sizeof(*renderchain));
   if (!renderchain)
      return NULL;

   return renderchain;
}

static bool d3d8_renderchain_init(void *data,
      const void *_video_info,
      void *dev_data,
      const void *final_viewport_data,
      const void *info_data,
      bool rgb32
      )
{
   unsigned width, height;
   d3d_video_t *d3d                       = (d3d_video_t*)data;
   LPDIRECT3DDEVICE d3dr                  = (LPDIRECT3DDEVICE)d3d->dev;
   const video_info_t *video_info         = (const video_info_t*)_video_info;
   const struct LinkInfo *link_info       = (const struct LinkInfo*)info_data;
   d3d8_renderchain_t *chain              = (d3d8_renderchain_t*)d3d->renderchain_data;
   unsigned fmt                           = (rgb32) ? RETRO_PIXEL_FORMAT_XRGB8888 : RETRO_PIXEL_FORMAT_RGB565;
   struct video_viewport *custom_vp       = video_viewport_get_custom();
   (void)final_viewport_data;

   video_driver_get_size(&width, &height);

   chain->dev                   = (LPDIRECT3DDEVICE)dev_data;
   //chain->video_info            = video_info;
   chain->pixel_size            = (fmt == RETRO_PIXEL_FORMAT_RGB565) ? 2 : 4;
   chain->tex_w                 = link_info->tex_w;
   chain->tex_h                 = link_info->tex_h;

   if (!d3d8_renderchain_create_first_pass(d3d, video_info))
      return false;

   /* FIXME */
   if (custom_vp->width == 0)
      custom_vp->width = width;

   if (custom_vp->height == 0)
      custom_vp->height = height;

   return true;
}

static void d3d8_renderchain_set_final_viewport(void *data,
      void *renderchain_data, const void *viewport_data)
{
   d3d_video_t                  *d3d = (d3d_video_t*)data;
   d3d8_renderchain_t *chain         = (d3d8_renderchain_t*)renderchain_data;
   const D3DVIEWPORT *final_viewport = (const D3DVIEWPORT*)viewport_data;

#if 0
   d3d_recompute_pass_sizes(chain, d3d);
#endif
}

static void d3d8_renderchain_render_pass(
      d3d_video_t *d3d, LPDIRECT3DDEVICE d3dr,
      d3d8_renderchain_t *chain,
      unsigned pass_index,
      unsigned rotation)
{
   settings_t *settings      = config_get_ptr();

   d3d_set_texture(d3dr, 0, chain->tex);
   d3d_set_sampler_magfilter(d3dr, pass_index, settings->bools.video_smooth ?
         D3DTEXF_LINEAR : D3DTEXF_POINT);
   d3d_set_sampler_minfilter(d3dr, pass_index, settings->bools.video_smooth ?
         D3DTEXF_LINEAR : D3DTEXF_POINT);

   d3d_set_viewports(chain->dev, &d3d->final_viewport);
   d3d_set_vertex_shader(d3dr, D3DFVF_CUSTOMVERTEX, NULL);
   d3d_set_stream_source(d3dr, 0, chain->vertex_buf, 0, sizeof(Vertex));
   d3d8_renderchain_set_mvp(d3d, chain, NULL, NULL);
   d3d_draw_primitive(d3dr, D3DPT_TRIANGLESTRIP, 0, 2);
}

static bool d3d8_renderchain_render(void *data, const void *frame,
      unsigned frame_width, unsigned frame_height,
      unsigned pitch, unsigned rotation)
{
   d3d_video_t      *d3d     = (d3d_video_t*)data;
   LPDIRECT3DDEVICE d3dr     = (LPDIRECT3DDEVICE)d3d->dev;
   d3d8_renderchain_t *chain = (d3d8_renderchain_t*)d3d->renderchain_data;

   d3d8_renderchain_blit_to_texture(chain, frame, frame_width, frame_height, pitch);
   d3d8_renderchain_set_vertices(d3d, 1, frame_width, frame_height, chain->frame_count);

   d3d8_renderchain_render_pass(d3d, d3dr, chain, 0, rotation);

   chain->frame_count++;

   return true;
}

static bool d3d8_renderchain_add_pass(void *data, const void *info_data)
{
   (void)data;
   (void)info_data;

   /* stub */
   return true;
}

static void d3d8_renderchain_add_state_tracker(void *data, void *tracker_data)
{
   (void)data;
   (void)tracker_data;

   /* stub */
}

static void d3d8_renderchain_convert_geometry(
	  void *data, const void *info_data,
      unsigned *out_width, unsigned *out_height,
      unsigned width, unsigned height,
      void *final_viewport_data)
{
   (void)data;
   (void)info_data;
   (void)out_width;
   (void)out_height;
   (void)width;
   (void)height;
   (void)final_viewport_data;

   /* stub */
}

static bool d3d8_renderchain_reinit(void *data,
      const void *video_data)
{
   d3d_video_t *d3d           = (d3d_video_t*)data;
   const video_info_t *video  = (const video_info_t*)video_data;
   d3d8_renderchain_t *chain  = (d3d8_renderchain_t*)d3d->renderchain_data;

   if (!d3d)
      return false;

   chain->pixel_size         = video->rgb32 ? sizeof(uint32_t) : sizeof(uint16_t);
   chain->tex_w = chain->tex_h = RARCH_SCALE_BASE * video->input_scale;
   RARCH_LOG(
         "Reinitializing renderchain - and textures (%u x %u @ %u bpp)\n",
         chain->tex_w, chain->tex_h, chain->pixel_size * CHAR_BIT);

   return true;
}

static void d3d8_renderchain_viewport_info(void *data,
      struct video_viewport *vp)
{
   unsigned width, height;
   d3d_video_t *d3d = (d3d_video_t*)data;

   if (!d3d || !vp)
      return;

   video_driver_get_size(&width, &height);

   vp->x            = d3d->final_viewport.X;
   vp->y            = d3d->final_viewport.Y;
   vp->width        = d3d->final_viewport.Width;
   vp->height       = d3d->final_viewport.Height;

   vp->full_width   = width;
   vp->full_height  = height;
}

d3d_renderchain_driver_t d3d8_d3d_renderchain = {
   d3d8_renderchain_set_mvp,
   d3d8_renderchain_free,
   d3d8_renderchain_new,
   d3d8_renderchain_reinit,
   d3d8_renderchain_init,
   d3d8_renderchain_set_final_viewport,
   d3d8_renderchain_add_pass,
   NULL,
   d3d8_renderchain_add_state_tracker,
   d3d8_renderchain_render,
   d3d8_renderchain_convert_geometry,
   NULL,
   NULL,
   d3d8_renderchain_viewport_info,
   "d3d8",
};
