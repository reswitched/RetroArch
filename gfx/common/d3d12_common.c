/*  RetroArch - A frontend for libretro.
 *  Copyright (C) 2014-2018 - Ali Bouhlel
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

#include <dynamic/dylib.h>

#include "d3d12_common.h"
#include "dxgi_common.h"
#include "d3dcompiler_common.h"

#include "verbosity.h"

static dylib_t d3d12_dll;
static const char *d3d12_dll_name = "d3d12.dll";

HRESULT WINAPI
D3D12CreateDevice(IUnknown *pAdapter,
                  D3D_FEATURE_LEVEL MinimumFeatureLevel,
                  REFIID riid, void **ppDevice)
{
   if (!d3d12_dll)
      d3d12_dll = dylib_load(d3d12_dll_name);

   if (d3d12_dll)
   {
      static PFN_D3D12_CREATE_DEVICE fp;

      if (!fp)
         fp = (PFN_D3D12_CREATE_DEVICE)dylib_proc(d3d12_dll, "D3D12CreateDevice");

      if (fp)
         return fp(pAdapter, MinimumFeatureLevel, riid, ppDevice);
   }

   return TYPE_E_CANTLOADLIBRARY;
}

HRESULT WINAPI
D3D12GetDebugInterface(REFIID riid, void **ppvDebug)
{
   if (!d3d12_dll)
      d3d12_dll = dylib_load(d3d12_dll_name);

   if (d3d12_dll)
   {
      static PFN_D3D12_GET_DEBUG_INTERFACE fp;

      if (!fp)
         fp = (PFN_D3D12_GET_DEBUG_INTERFACE)dylib_proc(d3d12_dll, "D3D12GetDebugInterface");

      if (fp)
         return fp(riid, ppvDebug);
   }

   return TYPE_E_CANTLOADLIBRARY;
}

HRESULT WINAPI
D3D12SerializeRootSignature(const D3D12_ROOT_SIGNATURE_DESC *pRootSignature,
                            D3D_ROOT_SIGNATURE_VERSION Version,
                            ID3DBlob **ppBlob, ID3DBlob **ppErrorBlob)
{
   if (!d3d12_dll)
      d3d12_dll = dylib_load(d3d12_dll_name);

   if (d3d12_dll)
   {
      static PFN_D3D12_SERIALIZE_ROOT_SIGNATURE fp;

      if (!fp)
         fp = (PFN_D3D12_SERIALIZE_ROOT_SIGNATURE)dylib_proc(d3d12_dll, "D3D12SerializeRootSignature");

      if (fp)
         return fp(pRootSignature, Version, ppBlob, ppErrorBlob);
   }

   return TYPE_E_CANTLOADLIBRARY;
}

HRESULT WINAPI
D3D12SerializeVersionedRootSignature(const D3D12_VERSIONED_ROOT_SIGNATURE_DESC *pRootSignature,
                                     ID3DBlob **ppBlob, ID3DBlob **ppErrorBlob)
{
   if (!d3d12_dll)
      d3d12_dll = dylib_load(d3d12_dll_name);

   if (d3d12_dll)
   {
      static PFN_D3D12_SERIALIZE_VERSIONED_ROOT_SIGNATURE fp;

      if (!fp)
         fp = (PFN_D3D12_SERIALIZE_VERSIONED_ROOT_SIGNATURE)dylib_proc(d3d12_dll,
               "D3D12SerializeRootSignature");

      if (fp)
         return fp(pRootSignature, ppBlob, ppErrorBlob);
   }

   return TYPE_E_CANTLOADLIBRARY;
}


#include <wiiu/wiiu_dbg.h>

bool d3d12_init_base(d3d12_video_t *d3d12)
{

#ifdef DEBUG
   D3D12GetDebugInterface_(&d3d12->debugController);
   D3D12EnableDebugLayer(d3d12->debugController);
#endif

   DXGICreateFactory(&d3d12->factory);

   {
      int i = 0;

      while (true)
      {
         if (FAILED(DXGIEnumAdapters(d3d12->factory, i++, &d3d12->adapter)))
            return false;

         if (SUCCEEDED(D3D12CreateDevice_(d3d12->adapter, D3D_FEATURE_LEVEL_11_0, &d3d12->device)))
            break;

         Release(d3d12->adapter);
      }
   }

   return true;
}

bool d3d12_init_queue(d3d12_video_t *d3d12)
{
   {
      static const D3D12_COMMAND_QUEUE_DESC desc =
      {
         .Type = D3D12_COMMAND_LIST_TYPE_DIRECT,
         .Flags = D3D12_COMMAND_QUEUE_FLAG_NONE,
      };
      D3D12CreateCommandQueue(d3d12->device, &desc, &d3d12->queue.handle);
   }

   D3D12CreateCommandAllocator(d3d12->device, D3D12_COMMAND_LIST_TYPE_DIRECT,
                               &d3d12->queue.allocator);

   D3D12CreateGraphicsCommandList(d3d12->device, 0, D3D12_COMMAND_LIST_TYPE_DIRECT,
                                  d3d12->queue.allocator, d3d12->pipe.handle, &d3d12->queue.cmd);

   D3D12CloseGraphicsCommandList(d3d12->queue.cmd);

   D3D12CreateFence(d3d12->device, 0, D3D12_FENCE_FLAG_NONE, &d3d12->queue.fence);
   d3d12->queue.fenceValue = 1;
   d3d12->queue.fenceEvent = CreateEvent(NULL, FALSE, FALSE, NULL);

   return true;
}

bool d3d12_init_swapchain(d3d12_video_t *d3d12, int width, int height, HWND hwnd)
{
   {
      DXGI_SWAP_CHAIN_DESC desc =
      {
         .BufferCount = countof(d3d12->chain.renderTargets),
         .BufferDesc.Width = width,
         .BufferDesc.Height = height,
         .BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM,
         .SampleDesc.Count = 1,
#if 0
         .BufferDesc.RefreshRate.Numerator = 60,
         .BufferDesc.RefreshRate.Denominator = 1,
         .SampleDesc.Quality = 0,
#endif
         .BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT,
         .OutputWindow = hwnd,
         .Windowed = TRUE,
#if 1
         .SwapEffect = DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL,
#else
         .SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD,
#endif
      };
      DXGICreateSwapChain(d3d12->factory, d3d12->queue.handle, &desc, &d3d12->chain.handle);
   }

   DXGIMakeWindowAssociation(d3d12->factory, hwnd, DXGI_MWA_NO_ALT_ENTER);

   d3d12->chain.frame_index = DXGIGetCurrentBackBufferIndex(d3d12->chain.handle);

   for (int i = 0; i < countof(d3d12->chain.renderTargets); i++)
   {
      d3d12->chain.desc_handles[i].ptr = d3d12->pipe.rtv_heap.cpu.ptr + i * d3d12->pipe.rtv_heap.stride;
      DXGIGetSwapChainBuffer(d3d12->chain.handle, i, &d3d12->chain.renderTargets[i]);
      D3D12CreateRenderTargetView(d3d12->device, d3d12->chain.renderTargets[i],
                                  NULL, d3d12->chain.desc_handles[i]);
   }

   d3d12->chain.viewport.Width = width;
   d3d12->chain.viewport.Height = height;
   d3d12->chain.scissorRect.right = width;
   d3d12->chain.scissorRect.bottom = height;

   return true;
}

static void d3d12_init_descriptor_heap(D3D12Device device, d3d12_descriptor_heap_t *out)
{
   D3D12CreateDescriptorHeap(device, &out->desc, &out->handle);
   out->cpu = D3D12GetCPUDescriptorHandleForHeapStart(out->handle);
   out->gpu = D3D12GetGPUDescriptorHandleForHeapStart(out->handle);
   out->stride = D3D12GetDescriptorHandleIncrementSize(device, out->desc.Type);
}

static void d3d12_init_sampler(D3D12Device device, d3d12_descriptor_heap_t *heap, descriptor_heap_slot_t heap_index,
                               D3D12_FILTER filter, D3D12_TEXTURE_ADDRESS_MODE address_mode, D3D12_GPU_DESCRIPTOR_HANDLE* dst)
{
   D3D12_SAMPLER_DESC sampler_desc =
   {
      .Filter = filter,
      .AddressU = address_mode,
      .AddressV = address_mode,
      .AddressW = address_mode,
      .MipLODBias = 0,
      .MaxAnisotropy = 0,
      .ComparisonFunc = D3D12_COMPARISON_FUNC_NEVER,
      .BorderColor = {0.0f},
      .MinLOD = 0.0f,
      .MaxLOD = D3D12_FLOAT32_MAX,
   };
   D3D12_CPU_DESCRIPTOR_HANDLE handle = {heap->cpu.ptr + heap_index * heap->stride};
   D3D12CreateSampler(device, &sampler_desc, handle);
   dst->ptr = heap->gpu.ptr + heap_index * heap->stride;
}

bool d3d12_init_descriptors(d3d12_video_t *d3d12)
{
   static const D3D12_DESCRIPTOR_RANGE srv_table[] =
   {
      {
         .RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_SRV,
         .NumDescriptors = 1,
         .BaseShaderRegister = 0,
         .RegisterSpace = 0,
#if 0
            .Flags = D3D12_DESCRIPTOR_RANGE_FLAG_DATA_STATIC, /* version 1_1 only */
#endif
         .OffsetInDescriptorsFromTableStart = D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND,
      },
   };
   static const D3D12_DESCRIPTOR_RANGE sampler_table[] =
   {
      {
         .RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_SAMPLER,
         .NumDescriptors = 1,
         .BaseShaderRegister = 0,
         .RegisterSpace = 0,
         .OffsetInDescriptorsFromTableStart = D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND,
      },
   };

   static const D3D12_ROOT_PARAMETER rootParameters[] =
   {
      {
         .ParameterType = D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE,
         .DescriptorTable = {countof(srv_table), srv_table},
         .ShaderVisibility = D3D12_SHADER_VISIBILITY_PIXEL,
      },
      {
         .ParameterType = D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE,
         .DescriptorTable = {countof(sampler_table), sampler_table},
         .ShaderVisibility = D3D12_SHADER_VISIBILITY_PIXEL,
      },
   };
   static const D3D12_ROOT_SIGNATURE_DESC desc =
   {
      .NumParameters = countof(rootParameters), rootParameters,
      .Flags = D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT,
   };

   {
      D3DBlob signature;
      D3DBlob error;
      D3D12SerializeRootSignature(&desc, D3D_ROOT_SIGNATURE_VERSION_1, &signature, &error);

      if (error)
      {
         RARCH_ERR("[D3D12]: CreateRootSignature failed :\n%s\n", (const char *)D3DGetBufferPointer(error));
         Release(error);
         return false;
      }

      D3D12CreateRootSignature(d3d12->device, 0, D3DGetBufferPointer(signature),
                               D3DGetBufferSize(signature), &d3d12->pipe.rootSignature);
      Release(signature);
   }

   d3d12->pipe.rtv_heap.desc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
   d3d12->pipe.rtv_heap.desc.NumDescriptors = countof(d3d12->chain.renderTargets);
   d3d12->pipe.rtv_heap.desc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
   d3d12_init_descriptor_heap(d3d12->device, &d3d12->pipe.rtv_heap);

   d3d12->pipe.srv_heap.desc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
   d3d12->pipe.srv_heap.desc.NumDescriptors = SRV_HEAP_SLOT_MAX;
   d3d12->pipe.srv_heap.desc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;
   d3d12_init_descriptor_heap(d3d12->device, &d3d12->pipe.srv_heap);

   d3d12->pipe.sampler_heap.desc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_SAMPLER;
   d3d12->pipe.sampler_heap.desc.NumDescriptors = SAMPLER_HEAP_SLOT_MAX;
   d3d12->pipe.sampler_heap.desc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;
   d3d12_init_descriptor_heap(d3d12->device, &d3d12->pipe.sampler_heap);

   d3d12_init_sampler(d3d12->device, &d3d12->pipe.sampler_heap,
                      SAMPLER_HEAP_SLOT_LINEAR, D3D12_FILTER_MIN_MAG_MIP_LINEAR,
                      D3D12_TEXTURE_ADDRESS_MODE_BORDER, &d3d12->sampler_linear);
   d3d12_init_sampler(d3d12->device, &d3d12->pipe.sampler_heap,
                      SAMPLER_HEAP_SLOT_NEAREST, D3D12_FILTER_MIN_MAG_MIP_POINT,
                      D3D12_TEXTURE_ADDRESS_MODE_BORDER, &d3d12->sampler_nearest);
   return true;
}

bool d3d12_init_pipeline(d3d12_video_t *d3d12)
{
   D3DBlob vs_code;
   D3DBlob ps_code;

   static const char stock [] =
#include "gfx/drivers/d3d_shaders/opaque_sm5.hlsl.h"
      ;

   static const D3D12_INPUT_ELEMENT_DESC inputElementDesc[] =
   {
      {"POSITION", 0, DXGI_FORMAT_R32G32_FLOAT,       0, offsetof(d3d12_vertex_t, position), D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0},
      {"TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT,       0, offsetof(d3d12_vertex_t, texcoord), D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0},
      {"COLOR",    0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, offsetof(d3d12_vertex_t, color),    D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0},
   };


   static const D3D12_RASTERIZER_DESC rasterizerDesc =
   {
      .FillMode = D3D12_FILL_MODE_SOLID,
      .CullMode = D3D12_CULL_MODE_BACK,
      .FrontCounterClockwise = FALSE,
      .DepthBias = D3D12_DEFAULT_DEPTH_BIAS,
      .DepthBiasClamp = D3D12_DEFAULT_DEPTH_BIAS_CLAMP,
      .SlopeScaledDepthBias = D3D12_DEFAULT_SLOPE_SCALED_DEPTH_BIAS,
      .DepthClipEnable = TRUE,
      .MultisampleEnable = FALSE,
      .AntialiasedLineEnable = FALSE,
      .ForcedSampleCount = 0,
      .ConservativeRaster = D3D12_CONSERVATIVE_RASTERIZATION_MODE_OFF,
   };

   static const D3D12_BLEND_DESC blendDesc =
   {
      .AlphaToCoverageEnable = FALSE,
      .IndependentBlendEnable = FALSE,
      .RenderTarget[0] =
      {
         .BlendEnable = TRUE, .LogicOpEnable = FALSE,
         D3D12_BLEND_SRC_ALPHA, D3D12_BLEND_INV_SRC_ALPHA, D3D12_BLEND_OP_ADD,
         D3D12_BLEND_SRC_ALPHA, D3D12_BLEND_INV_SRC_ALPHA, D3D12_BLEND_OP_ADD,
         D3D12_LOGIC_OP_NOOP, D3D12_COLOR_WRITE_ENABLE_ALL,
      },
   };

   if (!d3d_compile(stock, sizeof(stock), "VSMain", "vs_5_0", &vs_code))
      return false;

   if (!d3d_compile(stock, sizeof(stock), "PSMain", "ps_5_0", &ps_code))
      return false;

   {
      D3D12_GRAPHICS_PIPELINE_STATE_DESC psodesc =
      {
         .pRootSignature = d3d12->pipe.rootSignature,
         .VS.pShaderBytecode = D3DGetBufferPointer(vs_code), D3DGetBufferSize(vs_code),
         .PS.pShaderBytecode = D3DGetBufferPointer(ps_code), D3DGetBufferSize(ps_code),
         .BlendState = blendDesc,
         .SampleMask = UINT_MAX,
         .RasterizerState = rasterizerDesc,
         .DepthStencilState.DepthEnable = FALSE,
         .DepthStencilState.StencilEnable = FALSE,
         .InputLayout.pInputElementDescs = inputElementDesc, countof(inputElementDesc),
         .PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE,
         .NumRenderTargets = 1,
         .RTVFormats[0] = DXGI_FORMAT_R8G8B8A8_UNORM,
         .SampleDesc.Count = 1,
      };

      D3D12CreateGraphicsPipelineState(d3d12->device, &psodesc, &d3d12->pipe.handle);
   }

   Release(vs_code);
   Release(ps_code);

   return true;
}

void d3d12_create_vertex_buffer(D3D12Device device, D3D12_VERTEX_BUFFER_VIEW *view,
                                D3D12Resource *vbo)
{
   static const D3D12_HEAP_PROPERTIES heap_props =
   {
      .Type = D3D12_HEAP_TYPE_UPLOAD,
      .CreationNodeMask = 1,
      .VisibleNodeMask = 1,
   };

   D3D12_RESOURCE_DESC resource_desc =
   {
      .Dimension = D3D12_RESOURCE_DIMENSION_BUFFER,
      .Width = view->SizeInBytes,
      .Height = 1,
      .DepthOrArraySize = 1,
      .MipLevels = 1,
      .SampleDesc.Count = 1,
      .Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR,
   };

   D3D12CreateCommittedResource(device, &heap_props, D3D12_HEAP_FLAG_NONE, &resource_desc,
                                D3D12_RESOURCE_STATE_GENERIC_READ, NULL, vbo);
   view->BufferLocation = D3D12GetGPUVirtualAddress(*vbo);
}

void d3d12_create_texture(D3D12Device device, d3d12_descriptor_heap_t *heap, descriptor_heap_slot_t heap_index,
                          d3d12_texture_t *tex)
{
   {
      tex->desc.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D;
      tex->desc.DepthOrArraySize = 1;
      tex->desc.MipLevels = 1;
      tex->desc.SampleDesc.Count = 1;

      D3D12_HEAP_PROPERTIES heap_props = {D3D12_HEAP_TYPE_DEFAULT, 0, 0, 1, 1};
      D3D12CreateCommittedResource(device, &heap_props, D3D12_HEAP_FLAG_NONE, &tex->desc,
                                   D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE, NULL, &tex->handle);
   }

   D3D12GetCopyableFootprints(device, &tex->desc, 0, 1, 0, &tex->layout, &tex->num_rows,
                              &tex->row_size_in_bytes, &tex->total_bytes);

   {
      D3D12_RESOURCE_DESC buffer_desc =
      {
         .Dimension = D3D12_RESOURCE_DIMENSION_BUFFER,
         .Width = tex->total_bytes,
         .Height = 1,
         .DepthOrArraySize = 1,
         .MipLevels = 1,
         .SampleDesc.Count = 1,
         .Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR,
      };
      D3D12_HEAP_PROPERTIES heap_props = {D3D12_HEAP_TYPE_UPLOAD, 0, 0, 1, 1};

      D3D12CreateCommittedResource(device, &heap_props, D3D12_HEAP_FLAG_NONE, &buffer_desc,
                                   D3D12_RESOURCE_STATE_GENERIC_READ, NULL, &tex->upload_buffer);
   }

   {
      D3D12_SHADER_RESOURCE_VIEW_DESC view_desc =
      {
         .Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING,
         .Format = tex->desc.Format,
         .ViewDimension = D3D12_SRV_DIMENSION_TEXTURE2D,
         .Texture2D.MipLevels = tex->desc.MipLevels,
      };
      D3D12_CPU_DESCRIPTOR_HANDLE handle = {heap->cpu.ptr + heap_index * heap->stride};
      D3D12CreateShaderResourceView(device, tex->handle, &view_desc, handle);
      tex->gpu_descriptor.ptr = heap->gpu.ptr + heap_index * heap->stride;
   }

}

void d3d12_upload_texture(D3D12GraphicsCommandList cmd, d3d12_texture_t *texture)
{
   D3D12_TEXTURE_COPY_LOCATION src =
   {
      .pResource = texture->upload_buffer,
      .Type = D3D12_TEXTURE_COPY_TYPE_PLACED_FOOTPRINT,
      .PlacedFootprint = texture->layout,
   };

   D3D12_TEXTURE_COPY_LOCATION dst =
   {
      .pResource = texture->handle,
      .Type = D3D12_TEXTURE_COPY_TYPE_SUBRESOURCE_INDEX,
      .SubresourceIndex = 0,
   };

   d3d12_resource_transition(cmd, texture->handle,
                    D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE, D3D12_RESOURCE_STATE_COPY_DEST);

   D3D12CopyTextureRegion(cmd, &dst, 0, 0, 0, &src, NULL);

   d3d12_resource_transition(cmd, texture->handle,
                    D3D12_RESOURCE_STATE_COPY_DEST, D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE);

   texture->dirty = false;
}

void d3d12_create_fullscreen_quad_vbo(D3D12Device device, D3D12_VERTEX_BUFFER_VIEW *view, D3D12Resource *vbo)
{
   static const d3d12_vertex_t vertices[] =
   {
      {{ -1.0f, -1.0f}, {0.0f, 1.0f}, {1.0f, 1.0f, 1.0f, 1.0f}},
      {{ -1.0f,  1.0f}, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f}},
      {{ 1.0f, -1.0f}, {1.0f, 1.0f}, {1.0f, 1.0f, 1.0f, 1.0f}},
      {{ 1.0f,  1.0f}, {1.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f}},
   };

   view->SizeInBytes = sizeof(vertices);
   view->StrideInBytes = sizeof(*vertices);
   d3d12_create_vertex_buffer(device, view, vbo);

   {
      void *vertex_data_begin;
      D3D12_RANGE read_range = {0, 0};

      D3D12Map(*vbo, 0, &read_range, &vertex_data_begin);
      memcpy(vertex_data_begin, vertices, sizeof(vertices));
      D3D12Unmap(*vbo, 0, NULL);
   }
}
