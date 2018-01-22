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


#pragma once

#ifdef __MINGW32__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#define _In_
#define _In_opt_
#define _Null_

#define _Out_writes_bytes_opt_(s)
#define _Inout_opt_bytecount_(s)
#endif

#define CINTERFACE
#define COBJMACROS
#if 0
#ifdef __GNUC__
#define WIDL_C_INLINE_WRAPPERS
#include <_mingw.h>
#undef __forceinline
#define __forceinline inline __attribute__((__always_inline__))
#endif
#endif

#include <d3d11.h>
#include "dxgi_common.h"

#ifndef countof
#define countof(a) (sizeof(a)/ sizeof(*a))
#endif

#ifndef __uuidof
#define __uuidof(type) &IID_##type
#endif

#ifndef COM_RELEASE_DECLARED
#define COM_RELEASE_DECLARED
#if defined(__cplusplus) && !defined(CINTERFACE)
static inline ULONG Release(IUnknown* object)
{
   return object->Release();
}
#else
static inline ULONG Release(void* object)
{
   return ((IUnknown*)object)->lpVtbl->Release(object);
}
#endif
#endif

typedef ID3D11InputLayout*              D3D11InputLayout;
typedef ID3D11RasterizerState*          D3D11RasterizerState;
typedef ID3D11DepthStencilState*        D3D11DepthStencilState;
typedef ID3D11BlendState*               D3D11BlendState;
typedef ID3D11PixelShader*              D3D11PixelShader;
typedef ID3D11SamplerState*             D3D11SamplerState;
typedef ID3D11VertexShader*             D3D11VertexShader;
typedef ID3D11DomainShader*             D3D11DomainShader;
typedef ID3D11HullShader*               D3D11HullShader;
typedef ID3D11ComputeShader*            D3D11ComputeShader;
typedef ID3D11GeometryShader*           D3D11GeometryShader;

/* auto-generated */

typedef ID3D11Resource*                 D3D11Resource;
typedef ID3D11Buffer*                   D3D11Buffer;
typedef ID3D11Texture1D*                D3D11Texture1D;
typedef ID3D11Texture2D*                D3D11Texture2D;
typedef ID3D11Texture3D*                D3D11Texture3D;
typedef ID3D11View*                     D3D11View;
typedef ID3D11ShaderResourceView*       D3D11ShaderResourceView;
typedef ID3D11RenderTargetView*         D3D11RenderTargetView;
typedef ID3D11DepthStencilView*         D3D11DepthStencilView;
typedef ID3D11UnorderedAccessView*      D3D11UnorderedAccessView;
typedef ID3D11Asynchronous*             D3D11Asynchronous;
typedef ID3D11Query*                    D3D11Query;
typedef ID3D11Predicate*                D3D11Predicate;
typedef ID3D11Counter*                  D3D11Counter;
typedef ID3D11ClassInstance*            D3D11ClassInstance;
typedef ID3D11ClassLinkage*             D3D11ClassLinkage;
typedef ID3D11CommandList*              D3D11CommandList;
typedef ID3D11DeviceContext*            D3D11DeviceContext;
typedef ID3D11VideoDecoder*             D3D11VideoDecoder;
typedef ID3D11VideoProcessorEnumerator* D3D11VideoProcessorEnumerator;
typedef ID3D11VideoProcessor*           D3D11VideoProcessor;
typedef ID3D11AuthenticatedChannel*     D3D11AuthenticatedChannel;
typedef ID3D11CryptoSession*            D3D11CryptoSession;
typedef ID3D11VideoDecoderOutputView*   D3D11VideoDecoderOutputView;
typedef ID3D11VideoProcessorInputView*  D3D11VideoProcessorInputView;
typedef ID3D11VideoProcessorOutputView* D3D11VideoProcessorOutputView;
typedef ID3D11VideoContext*             D3D11VideoContext;
typedef ID3D11VideoDevice*              D3D11VideoDevice;
typedef ID3D11Device*                   D3D11Device;
typedef ID3D11Debug*                    D3D11Debug;
typedef ID3D11SwitchToRef*              D3D11SwitchToRef;
typedef ID3D11TracingDevice*            D3D11TracingDevice;
typedef ID3D11InfoQueue*                D3D11InfoQueue;

static inline void D3D11SetResourceEvictionPriority(D3D11Resource resource, UINT eviction_priority)
{
   resource->lpVtbl->SetEvictionPriority(resource, eviction_priority);
}
static inline UINT D3D11GetResourceEvictionPriority(D3D11Resource resource)
{
   return resource->lpVtbl->GetEvictionPriority(resource);
}
static inline void D3D11SetBufferEvictionPriority(D3D11Buffer buffer, UINT eviction_priority)
{
   buffer->lpVtbl->SetEvictionPriority(buffer, eviction_priority);
}
static inline UINT D3D11GetBufferEvictionPriority(D3D11Buffer buffer)
{
   return buffer->lpVtbl->GetEvictionPriority(buffer);
}
static inline void D3D11SetTexture1DEvictionPriority(D3D11Texture1D texture1d, UINT eviction_priority)
{
   texture1d->lpVtbl->SetEvictionPriority(texture1d, eviction_priority);
}
static inline UINT D3D11GetTexture1DEvictionPriority(D3D11Texture1D texture1d)
{
   return texture1d->lpVtbl->GetEvictionPriority(texture1d);
}
static inline void D3D11SetTexture2DEvictionPriority(D3D11Texture2D texture2d, UINT eviction_priority)
{
   texture2d->lpVtbl->SetEvictionPriority(texture2d, eviction_priority);
}
static inline UINT D3D11GetTexture2DEvictionPriority(D3D11Texture2D texture2d)
{
   return texture2d->lpVtbl->GetEvictionPriority(texture2d);
}
static inline void D3D11SetTexture3DEvictionPriority(D3D11Texture3D texture3d, UINT eviction_priority)
{
   texture3d->lpVtbl->SetEvictionPriority(texture3d, eviction_priority);
}
static inline UINT D3D11GetTexture3DEvictionPriority(D3D11Texture3D texture3d)
{
   return texture3d->lpVtbl->GetEvictionPriority(texture3d);
}
static inline void D3D11GetViewResource(D3D11View view, D3D11Resource* resource)
{
   view->lpVtbl->GetResource(view, resource);
}
static inline void D3D11GetShaderResourceViewResource(D3D11ShaderResourceView shader_resource_view, D3D11Resource* resource)
{
   shader_resource_view->lpVtbl->GetResource(shader_resource_view, resource);
}
static inline void D3D11GetRenderTargetViewResource(D3D11RenderTargetView render_target_view, D3D11Resource* resource)
{
   render_target_view->lpVtbl->GetResource(render_target_view, resource);
}
static inline void D3D11GetDepthStencilViewResource(D3D11DepthStencilView depth_stencil_view, D3D11Resource* resource)
{
   depth_stencil_view->lpVtbl->GetResource(depth_stencil_view, resource);
}
static inline void D3D11GetUnorderedAccessViewResource(D3D11UnorderedAccessView unordered_access_view, D3D11Resource* resource)
{
   unordered_access_view->lpVtbl->GetResource(unordered_access_view, resource);
}
static inline UINT D3D11GetAsynchronousDataSize(D3D11Asynchronous asynchronous)
{
   return asynchronous->lpVtbl->GetDataSize(asynchronous);
}
static inline UINT D3D11GetQueryDataSize(D3D11Query query)
{
   return query->lpVtbl->GetDataSize(query);
}
static inline UINT D3D11GetPredicateDataSize(D3D11Predicate predicate)
{
   return predicate->lpVtbl->GetDataSize(predicate);
}
static inline UINT D3D11GetCounterDataSize(D3D11Counter counter)
{
   return counter->lpVtbl->GetDataSize(counter);
}
static inline void D3D11GetClassLinkage(D3D11ClassInstance class_instance, D3D11ClassLinkage* linkage)
{
   class_instance->lpVtbl->GetClassLinkage(class_instance, linkage);
}
static inline void D3D11GetInstanceName(D3D11ClassInstance class_instance, LPSTR instance_name, SIZE_T* buffer_length)
{
   class_instance->lpVtbl->GetInstanceName(class_instance, instance_name, buffer_length);
}
static inline void D3D11GetTypeName(D3D11ClassInstance class_instance, LPSTR type_name, SIZE_T* buffer_length)
{
   class_instance->lpVtbl->GetTypeName(class_instance, type_name, buffer_length);
}
static inline HRESULT D3D11GetClassInstance(D3D11ClassLinkage class_linkage, LPCSTR class_instance_name, UINT instance_index, D3D11ClassInstance* instance)
{
   return class_linkage->lpVtbl->GetClassInstance(class_linkage, class_instance_name, instance_index, instance);
}
static inline HRESULT D3D11CreateClassInstance(D3D11ClassLinkage class_linkage, LPCSTR class_type_name, UINT constant_buffer_offset, UINT constant_vector_offset, UINT texture_offset, UINT sampler_offset, D3D11ClassInstance* instance)
{
   return class_linkage->lpVtbl->CreateClassInstance(class_linkage, class_type_name, constant_buffer_offset, constant_vector_offset, texture_offset, sampler_offset, instance);
}
static inline UINT D3D11GetCommandListContextFlags(D3D11CommandList command_list)
{
   return command_list->lpVtbl->GetContextFlags(command_list);
}
static inline void D3D11SetVShaderConstantBuffers(D3D11DeviceContext device_context, UINT start_slot, UINT num_buffers, D3D11Buffer*const  constant_buffers)
{
   device_context->lpVtbl->VSSetConstantBuffers(device_context, start_slot, num_buffers, constant_buffers);
}
static inline void D3D11SetPShaderResources(D3D11DeviceContext device_context, UINT start_slot, UINT num_views, D3D11ShaderResourceView*const  shader_resource_views)
{
   device_context->lpVtbl->PSSetShaderResources(device_context, start_slot, num_views, shader_resource_views);
}
static inline void D3D11SetPShader(D3D11DeviceContext device_context, D3D11PixelShader pixel_shader, D3D11ClassInstance*const  class_instances, UINT num_class_instances)
{
   device_context->lpVtbl->PSSetShader(device_context, pixel_shader, class_instances, num_class_instances);
}
static inline void D3D11SetPShaderSamplers(D3D11DeviceContext device_context, UINT start_slot, UINT num_samplers, D3D11SamplerState*const  samplers)
{
   device_context->lpVtbl->PSSetSamplers(device_context, start_slot, num_samplers, samplers);
}
static inline void D3D11SetVShader(D3D11DeviceContext device_context, D3D11VertexShader vertex_shader, D3D11ClassInstance*const  class_instances, UINT num_class_instances)
{
   device_context->lpVtbl->VSSetShader(device_context, vertex_shader, class_instances, num_class_instances);
}
static inline void D3D11DrawIndexed(D3D11DeviceContext device_context, UINT index_count, UINT start_index_location, INT base_vertex_location)
{
   device_context->lpVtbl->DrawIndexed(device_context, index_count, start_index_location, base_vertex_location);
}
static inline void D3D11Draw(D3D11DeviceContext device_context, UINT vertex_count, UINT start_vertex_location)
{
   device_context->lpVtbl->Draw(device_context, vertex_count, start_vertex_location);
}
static inline HRESULT D3D11Map(D3D11DeviceContext device_context, D3D11Resource resource, UINT subresource, D3D11_MAP map_type, UINT map_flags, D3D11_MAPPED_SUBRESOURCE* mapped_resource)
{
   return device_context->lpVtbl->Map(device_context, resource, subresource, map_type, map_flags, mapped_resource);
}
static inline void D3D11Unmap(D3D11DeviceContext device_context, D3D11Resource resource, UINT subresource)
{
   device_context->lpVtbl->Unmap(device_context, resource, subresource);
}
static inline void D3D11SetPShaderConstantBuffers(D3D11DeviceContext device_context, UINT start_slot, UINT num_buffers, D3D11Buffer*const  constant_buffers)
{
   device_context->lpVtbl->PSSetConstantBuffers(device_context, start_slot, num_buffers, constant_buffers);
}
static inline void D3D11SetInputLayout(D3D11DeviceContext device_context, D3D11InputLayout input_layout)
{
   device_context->lpVtbl->IASetInputLayout(device_context, input_layout);
}
static inline void D3D11SetVertexBuffers(D3D11DeviceContext device_context, UINT start_slot, UINT num_buffers, D3D11Buffer*const  vertex_buffers, UINT* strides, UINT* offsets)
{
   device_context->lpVtbl->IASetVertexBuffers(device_context, start_slot, num_buffers, vertex_buffers, strides, offsets);
}
static inline void D3D11SetIndexBuffer(D3D11DeviceContext device_context, D3D11Buffer index_buffer, DXGI_FORMAT format, UINT offset)
{
   device_context->lpVtbl->IASetIndexBuffer(device_context, index_buffer, format, offset);
}
static inline void D3D11DrawIndexedInstanced(D3D11DeviceContext device_context, UINT index_count_per_instance, UINT instance_count, UINT start_index_location, INT base_vertex_location, UINT start_instance_location)
{
   device_context->lpVtbl->DrawIndexedInstanced(device_context, index_count_per_instance, instance_count, start_index_location, base_vertex_location, start_instance_location);
}
static inline void D3D11DrawInstanced(D3D11DeviceContext device_context, UINT vertex_count_per_instance, UINT instance_count, UINT start_vertex_location, UINT start_instance_location)
{
   device_context->lpVtbl->DrawInstanced(device_context, vertex_count_per_instance, instance_count, start_vertex_location, start_instance_location);
}
static inline void D3D11SetGShaderConstantBuffers(D3D11DeviceContext device_context, UINT start_slot, UINT num_buffers, D3D11Buffer*const  constant_buffers)
{
   device_context->lpVtbl->GSSetConstantBuffers(device_context, start_slot, num_buffers, constant_buffers);
}
static inline void D3D11SetGShader(D3D11DeviceContext device_context, D3D11GeometryShader shader, D3D11ClassInstance*const  class_instances, UINT num_class_instances)
{
   device_context->lpVtbl->GSSetShader(device_context, shader, class_instances, num_class_instances);
}
static inline void D3D11SetPrimitiveTopology(D3D11DeviceContext device_context, D3D11_PRIMITIVE_TOPOLOGY topology)
{
   device_context->lpVtbl->IASetPrimitiveTopology(device_context, topology);
}
static inline void D3D11SetVShaderResources(D3D11DeviceContext device_context, UINT start_slot, UINT num_views, D3D11ShaderResourceView*const  shader_resource_views)
{
   device_context->lpVtbl->VSSetShaderResources(device_context, start_slot, num_views, shader_resource_views);
}
static inline void D3D11SetVShaderSamplers(D3D11DeviceContext device_context, UINT start_slot, UINT num_samplers, D3D11SamplerState*const  samplers)
{
   device_context->lpVtbl->VSSetSamplers(device_context, start_slot, num_samplers, samplers);
}
static inline void D3D11Begin(D3D11DeviceContext device_context, D3D11Asynchronous async)
{
   device_context->lpVtbl->Begin(device_context, async);
}
static inline void D3D11End(D3D11DeviceContext device_context, D3D11Asynchronous async)
{
   device_context->lpVtbl->End(device_context, async);
}
static inline HRESULT D3D11GetData(D3D11DeviceContext device_context, D3D11Asynchronous async, void* data, UINT data_size, UINT get_data_flags)
{
   return device_context->lpVtbl->GetData(device_context, async, data, data_size, get_data_flags);
}
static inline void D3D11SetPredication(D3D11DeviceContext device_context, D3D11Predicate predicate, BOOL predicate_value)
{
   device_context->lpVtbl->SetPredication(device_context, predicate, predicate_value);
}
static inline void D3D11SetGShaderResources(D3D11DeviceContext device_context, UINT start_slot, UINT num_views, D3D11ShaderResourceView*const  shader_resource_views)
{
   device_context->lpVtbl->GSSetShaderResources(device_context, start_slot, num_views, shader_resource_views);
}
static inline void D3D11SetGShaderSamplers(D3D11DeviceContext device_context, UINT start_slot, UINT num_samplers, D3D11SamplerState*const  samplers)
{
   device_context->lpVtbl->GSSetSamplers(device_context, start_slot, num_samplers, samplers);
}
static inline void D3D11SetRenderTargets(D3D11DeviceContext device_context, UINT num_views, D3D11RenderTargetView*const  render_target_views, D3D11DepthStencilView depth_stencil_view)
{
   device_context->lpVtbl->OMSetRenderTargets(device_context, num_views, render_target_views, depth_stencil_view);
}
static inline void D3D11SetRenderTargetsAndUnorderedAccessViews(D3D11DeviceContext device_context, UINT num_rtvs, D3D11RenderTargetView*const  render_target_views, D3D11DepthStencilView depth_stencil_view, UINT uavstart_slot, UINT num_uavs, D3D11UnorderedAccessView*const  unordered_access_views, UINT* uavinitial_counts)
{
   device_context->lpVtbl->OMSetRenderTargetsAndUnorderedAccessViews(device_context, num_rtvs, render_target_views, depth_stencil_view, uavstart_slot, num_uavs, unordered_access_views, uavinitial_counts);
}
static inline void D3D11SetBlendState(D3D11DeviceContext device_context, D3D11BlendState blend_state, FLOAT blend_factor[4], UINT sample_mask)
{
   device_context->lpVtbl->OMSetBlendState(device_context, blend_state, blend_factor, sample_mask);
}
static inline void D3D11SetDepthStencilState(D3D11DeviceContext device_context, D3D11DepthStencilState depth_stencil_state, UINT stencil_ref)
{
   device_context->lpVtbl->OMSetDepthStencilState(device_context, depth_stencil_state, stencil_ref);
}
static inline void D3D11SOSetTargets(D3D11DeviceContext device_context, UINT num_buffers, D3D11Buffer*const  sotargets, UINT* offsets)
{
   device_context->lpVtbl->SOSetTargets(device_context, num_buffers, sotargets, offsets);
}
static inline void D3D11DrawAuto(D3D11DeviceContext device_context)
{
   device_context->lpVtbl->DrawAuto(device_context);
}
static inline void D3D11DrawIndexedInstancedIndirect(D3D11DeviceContext device_context, D3D11Buffer buffer_for_args, UINT aligned_byte_offset_for_args)
{
   device_context->lpVtbl->DrawIndexedInstancedIndirect(device_context, buffer_for_args, aligned_byte_offset_for_args);
}
static inline void D3D11DrawInstancedIndirect(D3D11DeviceContext device_context, D3D11Buffer buffer_for_args, UINT aligned_byte_offset_for_args)
{
   device_context->lpVtbl->DrawInstancedIndirect(device_context, buffer_for_args, aligned_byte_offset_for_args);
}
static inline void D3D11Dispatch(D3D11DeviceContext device_context, UINT thread_group_count_x, UINT thread_group_count_y, UINT thread_group_count_z)
{
   device_context->lpVtbl->Dispatch(device_context, thread_group_count_x, thread_group_count_y, thread_group_count_z);
}
static inline void D3D11DispatchIndirect(D3D11DeviceContext device_context, D3D11Buffer buffer_for_args, UINT aligned_byte_offset_for_args)
{
   device_context->lpVtbl->DispatchIndirect(device_context, buffer_for_args, aligned_byte_offset_for_args);
}
static inline void D3D11SetState(D3D11DeviceContext device_context, D3D11RasterizerState rasterizer_state)
{
   device_context->lpVtbl->RSSetState(device_context, rasterizer_state);
}
static inline void D3D11SetViewports(D3D11DeviceContext device_context, UINT num_viewports, D3D11_VIEWPORT* viewports)
{
   device_context->lpVtbl->RSSetViewports(device_context, num_viewports, viewports);
}
static inline void D3D11SetScissorRects(D3D11DeviceContext device_context, UINT num_rects, D3D11_RECT* rects)
{
   device_context->lpVtbl->RSSetScissorRects(device_context, num_rects, rects);
}
static inline void D3D11CopySubresourceRegion(D3D11DeviceContext device_context, D3D11Resource dst_resource, UINT dst_subresource, UINT dst_x, UINT dst_y, UINT dst_z, D3D11Resource src_resource, UINT src_subresource, D3D11_BOX* src_box)
{
   device_context->lpVtbl->CopySubresourceRegion(device_context, dst_resource, dst_subresource, dst_x, dst_y, dst_z, src_resource, src_subresource, src_box);
}
static inline void D3D11CopyResource(D3D11DeviceContext device_context, D3D11Resource dst_resource, D3D11Resource src_resource)
{
   device_context->lpVtbl->CopyResource(device_context, dst_resource, src_resource);
}
static inline void D3D11UpdateSubresource(D3D11DeviceContext device_context, D3D11Resource dst_resource, UINT dst_subresource, D3D11_BOX* dst_box, void* src_data, UINT src_row_pitch, UINT src_depth_pitch)
{
   device_context->lpVtbl->UpdateSubresource(device_context, dst_resource, dst_subresource, dst_box, src_data, src_row_pitch, src_depth_pitch);
}
static inline void D3D11CopyStructureCount(D3D11DeviceContext device_context, D3D11Buffer dst_buffer, UINT dst_aligned_byte_offset, D3D11UnorderedAccessView src_view)
{
   device_context->lpVtbl->CopyStructureCount(device_context, dst_buffer, dst_aligned_byte_offset, src_view);
}
static inline void D3D11ClearRenderTargetView(D3D11DeviceContext device_context, D3D11RenderTargetView render_target_view, FLOAT color_rgba[4])
{
   device_context->lpVtbl->ClearRenderTargetView(device_context, render_target_view, color_rgba);
}
static inline void D3D11ClearUnorderedAccessViewUint(D3D11DeviceContext device_context, D3D11UnorderedAccessView unordered_access_view, UINT values[4])
{
   device_context->lpVtbl->ClearUnorderedAccessViewUint(device_context, unordered_access_view, values);
}
static inline void D3D11ClearUnorderedAccessViewFloat(D3D11DeviceContext device_context, D3D11UnorderedAccessView unordered_access_view, FLOAT values[4])
{
   device_context->lpVtbl->ClearUnorderedAccessViewFloat(device_context, unordered_access_view, values);
}
static inline void D3D11ClearDepthStencilView(D3D11DeviceContext device_context, D3D11DepthStencilView depth_stencil_view, UINT clear_flags, FLOAT depth, UINT8 stencil)
{
   device_context->lpVtbl->ClearDepthStencilView(device_context, depth_stencil_view, clear_flags, depth, stencil);
}
static inline void D3D11GenerateMips(D3D11DeviceContext device_context, D3D11ShaderResourceView shader_resource_view)
{
   device_context->lpVtbl->GenerateMips(device_context, shader_resource_view);
}
static inline void D3D11SetResourceMinLOD(D3D11DeviceContext device_context, D3D11Resource resource, FLOAT min_lod)
{
   device_context->lpVtbl->SetResourceMinLOD(device_context, resource, min_lod);
}
static inline FLOAT D3D11GetResourceMinLOD(D3D11DeviceContext device_context, D3D11Resource resource)
{
   return device_context->lpVtbl->GetResourceMinLOD(device_context, resource);
}
static inline void D3D11ResolveSubresource(D3D11DeviceContext device_context, D3D11Resource dst_resource, UINT dst_subresource, D3D11Resource src_resource, UINT src_subresource, DXGI_FORMAT format)
{
   device_context->lpVtbl->ResolveSubresource(device_context, dst_resource, dst_subresource, src_resource, src_subresource, format);
}
static inline void D3D11ExecuteCommandList(D3D11DeviceContext device_context, D3D11CommandList command_list, BOOL restore_context_state)
{
   device_context->lpVtbl->ExecuteCommandList(device_context, command_list, restore_context_state);
}
static inline void D3D11HSSetShaderResources(D3D11DeviceContext device_context, UINT start_slot, UINT num_views, D3D11ShaderResourceView*const  shader_resource_views)
{
   device_context->lpVtbl->HSSetShaderResources(device_context, start_slot, num_views, shader_resource_views);
}
static inline void D3D11HSSetShader(D3D11DeviceContext device_context, D3D11HullShader hull_shader, D3D11ClassInstance*const  class_instances, UINT num_class_instances)
{
   device_context->lpVtbl->HSSetShader(device_context, hull_shader, class_instances, num_class_instances);
}
static inline void D3D11HSSetSamplers(D3D11DeviceContext device_context, UINT start_slot, UINT num_samplers, D3D11SamplerState*const  samplers)
{
   device_context->lpVtbl->HSSetSamplers(device_context, start_slot, num_samplers, samplers);
}
static inline void D3D11HSSetConstantBuffers(D3D11DeviceContext device_context, UINT start_slot, UINT num_buffers, D3D11Buffer*const  constant_buffers)
{
   device_context->lpVtbl->HSSetConstantBuffers(device_context, start_slot, num_buffers, constant_buffers);
}
static inline void D3D11SetDShaderResources(D3D11DeviceContext device_context, UINT start_slot, UINT num_views, D3D11ShaderResourceView*const  shader_resource_views)
{
   device_context->lpVtbl->DSSetShaderResources(device_context, start_slot, num_views, shader_resource_views);
}
static inline void D3D11SetDShader(D3D11DeviceContext device_context, D3D11DomainShader domain_shader, D3D11ClassInstance*const  class_instances, UINT num_class_instances)
{
   device_context->lpVtbl->DSSetShader(device_context, domain_shader, class_instances, num_class_instances);
}
static inline void D3D11SetDShaderSamplers(D3D11DeviceContext device_context, UINT start_slot, UINT num_samplers, D3D11SamplerState*const  samplers)
{
   device_context->lpVtbl->DSSetSamplers(device_context, start_slot, num_samplers, samplers);
}
static inline void D3D11SetDShaderConstantBuffers(D3D11DeviceContext device_context, UINT start_slot, UINT num_buffers, D3D11Buffer*const  constant_buffers)
{
   device_context->lpVtbl->DSSetConstantBuffers(device_context, start_slot, num_buffers, constant_buffers);
}
static inline void D3D11SetCShaderResources(D3D11DeviceContext device_context, UINT start_slot, UINT num_views, D3D11ShaderResourceView*const  shader_resource_views)
{
   device_context->lpVtbl->CSSetShaderResources(device_context, start_slot, num_views, shader_resource_views);
}
static inline void D3D11SetCShaderUnorderedAccessViews(D3D11DeviceContext device_context, UINT start_slot, UINT num_uavs, D3D11UnorderedAccessView*const  unordered_access_views, UINT* uavinitial_counts)
{
   device_context->lpVtbl->CSSetUnorderedAccessViews(device_context, start_slot, num_uavs, unordered_access_views, uavinitial_counts);
}
static inline void D3D11SetCShader(D3D11DeviceContext device_context, D3D11ComputeShader compute_shader, D3D11ClassInstance*const  class_instances, UINT num_class_instances)
{
   device_context->lpVtbl->CSSetShader(device_context, compute_shader, class_instances, num_class_instances);
}
static inline void D3D11SetCShaderSamplers(D3D11DeviceContext device_context, UINT start_slot, UINT num_samplers, D3D11SamplerState*const  samplers)
{
   device_context->lpVtbl->CSSetSamplers(device_context, start_slot, num_samplers, samplers);
}
static inline void D3D11SetCShaderConstantBuffers(D3D11DeviceContext device_context, UINT start_slot, UINT num_buffers, D3D11Buffer*const  constant_buffers)
{
   device_context->lpVtbl->CSSetConstantBuffers(device_context, start_slot, num_buffers, constant_buffers);
}
static inline void D3D11GetVShaderConstantBuffers(D3D11DeviceContext device_context, UINT start_slot, UINT num_buffers, D3D11Buffer* constant_buffers)
{
   device_context->lpVtbl->VSGetConstantBuffers(device_context, start_slot, num_buffers, constant_buffers);
}
static inline void D3D11GetPShaderResources(D3D11DeviceContext device_context, UINT start_slot, UINT num_views, D3D11ShaderResourceView* shader_resource_views)
{
   device_context->lpVtbl->PSGetShaderResources(device_context, start_slot, num_views, shader_resource_views);
}
static inline void D3D11GetPShader(D3D11DeviceContext device_context, D3D11PixelShader* pixel_shader, D3D11ClassInstance* class_instances, UINT* num_class_instances)
{
   device_context->lpVtbl->PSGetShader(device_context, pixel_shader, class_instances, num_class_instances);
}
static inline void D3D11GetPShaderSamplers(D3D11DeviceContext device_context, UINT start_slot, UINT num_samplers, D3D11SamplerState* samplers)
{
   device_context->lpVtbl->PSGetSamplers(device_context, start_slot, num_samplers, samplers);
}
static inline void D3D11GetVShader(D3D11DeviceContext device_context, D3D11VertexShader* vertex_shader, D3D11ClassInstance* class_instances, UINT* num_class_instances)
{
   device_context->lpVtbl->VSGetShader(device_context, vertex_shader, class_instances, num_class_instances);
}
static inline void D3D11GetPShaderConstantBuffers(D3D11DeviceContext device_context, UINT start_slot, UINT num_buffers, D3D11Buffer* constant_buffers)
{
   device_context->lpVtbl->PSGetConstantBuffers(device_context, start_slot, num_buffers, constant_buffers);
}
static inline void D3D11GetInputLayout(D3D11DeviceContext device_context, D3D11InputLayout* input_layout)
{
   device_context->lpVtbl->IAGetInputLayout(device_context, input_layout);
}
static inline void D3D11GetVertexBuffers(D3D11DeviceContext device_context, UINT start_slot, UINT num_buffers, D3D11Buffer* vertex_buffers, UINT* strides, UINT* offsets)
{
   device_context->lpVtbl->IAGetVertexBuffers(device_context, start_slot, num_buffers, vertex_buffers, strides, offsets);
}
static inline void D3D11GetIndexBuffer(D3D11DeviceContext device_context, D3D11Buffer* index_buffer, DXGI_FORMAT* format, UINT* offset)
{
   device_context->lpVtbl->IAGetIndexBuffer(device_context, index_buffer, format, offset);
}
static inline void D3D11GetGShaderConstantBuffers(D3D11DeviceContext device_context, UINT start_slot, UINT num_buffers, D3D11Buffer* constant_buffers)
{
   device_context->lpVtbl->GSGetConstantBuffers(device_context, start_slot, num_buffers, constant_buffers);
}
static inline void D3D11GetGShader(D3D11DeviceContext device_context, D3D11GeometryShader* geometry_shader, D3D11ClassInstance* class_instances, UINT* num_class_instances)
{
   device_context->lpVtbl->GSGetShader(device_context, geometry_shader, class_instances, num_class_instances);
}
static inline void D3D11GetPrimitiveTopology(D3D11DeviceContext device_context, D3D11_PRIMITIVE_TOPOLOGY* topology)
{
   device_context->lpVtbl->IAGetPrimitiveTopology(device_context, topology);
}
static inline void D3D11GetVShaderResources(D3D11DeviceContext device_context, UINT start_slot, UINT num_views, D3D11ShaderResourceView* shader_resource_views)
{
   device_context->lpVtbl->VSGetShaderResources(device_context, start_slot, num_views, shader_resource_views);
}
static inline void D3D11GetVShaderSamplers(D3D11DeviceContext device_context, UINT start_slot, UINT num_samplers, D3D11SamplerState* samplers)
{
   device_context->lpVtbl->VSGetSamplers(device_context, start_slot, num_samplers, samplers);
}
static inline void D3D11GetPredication(D3D11DeviceContext device_context, D3D11Predicate* predicate, BOOL* predicate_value)
{
   device_context->lpVtbl->GetPredication(device_context, predicate, predicate_value);
}
static inline void D3D11GetGShaderResources(D3D11DeviceContext device_context, UINT start_slot, UINT num_views, D3D11ShaderResourceView* shader_resource_views)
{
   device_context->lpVtbl->GSGetShaderResources(device_context, start_slot, num_views, shader_resource_views);
}
static inline void D3D11GetGShaderSamplers(D3D11DeviceContext device_context, UINT start_slot, UINT num_samplers, D3D11SamplerState* samplers)
{
   device_context->lpVtbl->GSGetSamplers(device_context, start_slot, num_samplers, samplers);
}
static inline void D3D11GetRenderTargets(D3D11DeviceContext device_context, UINT num_views, D3D11RenderTargetView* render_target_views, D3D11DepthStencilView* depth_stencil_view)
{
   device_context->lpVtbl->OMGetRenderTargets(device_context, num_views, render_target_views, depth_stencil_view);
}
static inline void D3D11GetRenderTargetsAndUnorderedAccessViews(D3D11DeviceContext device_context, UINT num_rtvs, D3D11RenderTargetView* render_target_views, D3D11DepthStencilView* depth_stencil_view, UINT uavstart_slot, UINT num_uavs, D3D11UnorderedAccessView* unordered_access_views)
{
   device_context->lpVtbl->OMGetRenderTargetsAndUnorderedAccessViews(device_context, num_rtvs, render_target_views, depth_stencil_view, uavstart_slot, num_uavs, unordered_access_views);
}
static inline void D3D11GetBlendState(D3D11DeviceContext device_context, D3D11BlendState* blend_state, FLOAT blend_factor[4], UINT* sample_mask)
{
   device_context->lpVtbl->OMGetBlendState(device_context, blend_state, blend_factor, sample_mask);
}
static inline void D3D11GetDepthStencilState(D3D11DeviceContext device_context, D3D11DepthStencilState* depth_stencil_state, UINT* stencil_ref)
{
   device_context->lpVtbl->OMGetDepthStencilState(device_context, depth_stencil_state, stencil_ref);
}
static inline void D3D11SOGetTargets(D3D11DeviceContext device_context, UINT num_buffers, D3D11Buffer* sotargets)
{
   device_context->lpVtbl->SOGetTargets(device_context, num_buffers, sotargets);
}
static inline void D3D11GetState(D3D11DeviceContext device_context, D3D11RasterizerState* rasterizer_state)
{
   device_context->lpVtbl->RSGetState(device_context, rasterizer_state);
}
static inline void D3D11GetViewports(D3D11DeviceContext device_context, UINT* num_viewports, D3D11_VIEWPORT* viewports)
{
   device_context->lpVtbl->RSGetViewports(device_context, num_viewports, viewports);
}
static inline void D3D11GetScissorRects(D3D11DeviceContext device_context, UINT* num_rects, D3D11_RECT* rects)
{
   device_context->lpVtbl->RSGetScissorRects(device_context, num_rects, rects);
}
static inline void D3D11HSGetShaderResources(D3D11DeviceContext device_context, UINT start_slot, UINT num_views, D3D11ShaderResourceView* shader_resource_views)
{
   device_context->lpVtbl->HSGetShaderResources(device_context, start_slot, num_views, shader_resource_views);
}
static inline void D3D11HSGetShader(D3D11DeviceContext device_context, D3D11HullShader* hull_shader, D3D11ClassInstance* class_instances, UINT* num_class_instances)
{
   device_context->lpVtbl->HSGetShader(device_context, hull_shader, class_instances, num_class_instances);
}
static inline void D3D11HSGetSamplers(D3D11DeviceContext device_context, UINT start_slot, UINT num_samplers, D3D11SamplerState* samplers)
{
   device_context->lpVtbl->HSGetSamplers(device_context, start_slot, num_samplers, samplers);
}
static inline void D3D11HSGetConstantBuffers(D3D11DeviceContext device_context, UINT start_slot, UINT num_buffers, D3D11Buffer* constant_buffers)
{
   device_context->lpVtbl->HSGetConstantBuffers(device_context, start_slot, num_buffers, constant_buffers);
}
static inline void D3D11GetDShaderResources(D3D11DeviceContext device_context, UINT start_slot, UINT num_views, D3D11ShaderResourceView* shader_resource_views)
{
   device_context->lpVtbl->DSGetShaderResources(device_context, start_slot, num_views, shader_resource_views);
}
static inline void D3D11GetDShader(D3D11DeviceContext device_context, D3D11DomainShader* domain_shader, D3D11ClassInstance* class_instances, UINT* num_class_instances)
{
   device_context->lpVtbl->DSGetShader(device_context, domain_shader, class_instances, num_class_instances);
}
static inline void D3D11GetDShaderSamplers(D3D11DeviceContext device_context, UINT start_slot, UINT num_samplers, D3D11SamplerState* samplers)
{
   device_context->lpVtbl->DSGetSamplers(device_context, start_slot, num_samplers, samplers);
}
static inline void D3D11GetDShaderConstantBuffers(D3D11DeviceContext device_context, UINT start_slot, UINT num_buffers, D3D11Buffer* constant_buffers)
{
   device_context->lpVtbl->DSGetConstantBuffers(device_context, start_slot, num_buffers, constant_buffers);
}
static inline void D3D11GetCShaderResources(D3D11DeviceContext device_context, UINT start_slot, UINT num_views, D3D11ShaderResourceView* shader_resource_views)
{
   device_context->lpVtbl->CSGetShaderResources(device_context, start_slot, num_views, shader_resource_views);
}
static inline void D3D11GetCShaderUnorderedAccessViews(D3D11DeviceContext device_context, UINT start_slot, UINT num_uavs, D3D11UnorderedAccessView* unordered_access_views)
{
   device_context->lpVtbl->CSGetUnorderedAccessViews(device_context, start_slot, num_uavs, unordered_access_views);
}
static inline void D3D11GetCShader(D3D11DeviceContext device_context, D3D11ComputeShader* compute_shader, D3D11ClassInstance* class_instances, UINT* num_class_instances)
{
   device_context->lpVtbl->CSGetShader(device_context, compute_shader, class_instances, num_class_instances);
}
static inline void D3D11GetCShaderSamplers(D3D11DeviceContext device_context, UINT start_slot, UINT num_samplers, D3D11SamplerState* samplers)
{
   device_context->lpVtbl->CSGetSamplers(device_context, start_slot, num_samplers, samplers);
}
static inline void D3D11GetCShaderConstantBuffers(D3D11DeviceContext device_context, UINT start_slot, UINT num_buffers, D3D11Buffer* constant_buffers)
{
   device_context->lpVtbl->CSGetConstantBuffers(device_context, start_slot, num_buffers, constant_buffers);
}
static inline void D3D11ClearState(D3D11DeviceContext device_context)
{
   device_context->lpVtbl->ClearState(device_context);
}
static inline void D3D11Flush(D3D11DeviceContext device_context)
{
   device_context->lpVtbl->Flush(device_context);
}
static inline UINT D3D11GetDeviceContextContextFlags(D3D11DeviceContext device_context)
{
   return device_context->lpVtbl->GetContextFlags(device_context);
}
static inline HRESULT D3D11FinishCommandList(D3D11DeviceContext device_context, BOOL restore_deferred_context_state, D3D11CommandList* command_list)
{
   return device_context->lpVtbl->FinishCommandList(device_context, restore_deferred_context_state, command_list);
}
static inline HRESULT D3D11GetCreationParameters(D3D11VideoDecoder video_decoder, D3D11_VIDEO_DECODER_DESC* video_desc, D3D11_VIDEO_DECODER_CONFIG* config)
{
   return video_decoder->lpVtbl->GetCreationParameters(video_decoder, video_desc, config);
}
static inline HRESULT D3D11GetDriverHandle(D3D11VideoDecoder video_decoder, HANDLE* driver_handle)
{
   return video_decoder->lpVtbl->GetDriverHandle(video_decoder, driver_handle);
}
static inline HRESULT D3D11GetVideoProcessorContentDesc(D3D11VideoProcessorEnumerator video_processor_enumerator, D3D11_VIDEO_PROCESSOR_CONTENT_DESC* content_desc)
{
   return video_processor_enumerator->lpVtbl->GetVideoProcessorContentDesc(video_processor_enumerator, content_desc);
}
static inline HRESULT D3D11CheckVideoProcessorFormat(D3D11VideoProcessorEnumerator video_processor_enumerator, DXGI_FORMAT format, UINT* flags)
{
   return video_processor_enumerator->lpVtbl->CheckVideoProcessorFormat(video_processor_enumerator, format, flags);
}
static inline HRESULT D3D11GetVideoProcessorCaps(D3D11VideoProcessorEnumerator video_processor_enumerator, D3D11_VIDEO_PROCESSOR_CAPS* caps)
{
   return video_processor_enumerator->lpVtbl->GetVideoProcessorCaps(video_processor_enumerator, caps);
}
static inline HRESULT D3D11GetVideoProcessorRateConversionCaps(D3D11VideoProcessorEnumerator video_processor_enumerator, UINT type_index, D3D11_VIDEO_PROCESSOR_RATE_CONVERSION_CAPS* caps)
{
   return video_processor_enumerator->lpVtbl->GetVideoProcessorRateConversionCaps(video_processor_enumerator, type_index, caps);
}
static inline HRESULT D3D11GetVideoProcessorCustomRate(D3D11VideoProcessorEnumerator video_processor_enumerator, UINT type_index, UINT custom_rate_index, D3D11_VIDEO_PROCESSOR_CUSTOM_RATE* rate)
{
   return video_processor_enumerator->lpVtbl->GetVideoProcessorCustomRate(video_processor_enumerator, type_index, custom_rate_index, rate);
}
static inline HRESULT D3D11GetVideoProcessorFilterRange(D3D11VideoProcessorEnumerator video_processor_enumerator, D3D11_VIDEO_PROCESSOR_FILTER filter, D3D11_VIDEO_PROCESSOR_FILTER_RANGE* range)
{
   return video_processor_enumerator->lpVtbl->GetVideoProcessorFilterRange(video_processor_enumerator, filter, range);
}
static inline void D3D11GetContentDesc(D3D11VideoProcessor video_processor, D3D11_VIDEO_PROCESSOR_CONTENT_DESC* desc)
{
   video_processor->lpVtbl->GetContentDesc(video_processor, desc);
}
static inline void D3D11GetRateConversionCaps(D3D11VideoProcessor video_processor, D3D11_VIDEO_PROCESSOR_RATE_CONVERSION_CAPS* caps)
{
   video_processor->lpVtbl->GetRateConversionCaps(video_processor, caps);
}
static inline HRESULT D3D11GetAuthenticatedChannelCertificateSize(D3D11AuthenticatedChannel authenticated_channel, UINT* certificate_size)
{
   return authenticated_channel->lpVtbl->GetCertificateSize(authenticated_channel, certificate_size);
}
static inline HRESULT D3D11GetAuthenticatedChannelCertificate(D3D11AuthenticatedChannel authenticated_channel, UINT certificate_size, BYTE* certificate)
{
   return authenticated_channel->lpVtbl->GetCertificate(authenticated_channel, certificate_size, certificate);
}
static inline void D3D11GetChannelHandle(D3D11AuthenticatedChannel authenticated_channel, HANDLE* channel_handle)
{
   authenticated_channel->lpVtbl->GetChannelHandle(authenticated_channel, channel_handle);
}
static inline void D3D11GetCryptoType(D3D11CryptoSession crypto_session, GUID* crypto_type)
{
   crypto_session->lpVtbl->GetCryptoType(crypto_session, crypto_type);
}
static inline void D3D11GetDecoderProfile(D3D11CryptoSession crypto_session, GUID* decoder_profile)
{
   crypto_session->lpVtbl->GetDecoderProfile(crypto_session, decoder_profile);
}
static inline HRESULT D3D11GetCryptoSessionCertificateSize(D3D11CryptoSession crypto_session, UINT* certificate_size)
{
   return crypto_session->lpVtbl->GetCertificateSize(crypto_session, certificate_size);
}
static inline HRESULT D3D11GetCryptoSessionCertificate(D3D11CryptoSession crypto_session, UINT certificate_size, BYTE* certificate)
{
   return crypto_session->lpVtbl->GetCertificate(crypto_session, certificate_size, certificate);
}
static inline void D3D11GetCryptoSessionHandle(D3D11CryptoSession crypto_session, HANDLE* crypto_session_handle)
{
   crypto_session->lpVtbl->GetCryptoSessionHandle(crypto_session, crypto_session_handle);
}
static inline void D3D11GetVideoDecoderOutputViewResource(D3D11VideoDecoderOutputView video_decoder_output_view, D3D11Resource* resource)
{
   video_decoder_output_view->lpVtbl->GetResource(video_decoder_output_view, resource);
}
static inline void D3D11GetVideoProcessorInputViewResource(D3D11VideoProcessorInputView video_processor_input_view, D3D11Resource* resource)
{
   video_processor_input_view->lpVtbl->GetResource(video_processor_input_view, resource);
}
static inline void D3D11GetVideoProcessorOutputViewResource(D3D11VideoProcessorOutputView video_processor_output_view, D3D11Resource* resource)
{
   video_processor_output_view->lpVtbl->GetResource(video_processor_output_view, resource);
}
static inline HRESULT D3D11GetDecoderBuffer(D3D11VideoContext video_context, D3D11VideoDecoder decoder, D3D11_VIDEO_DECODER_BUFFER_TYPE type, UINT* buffer_size, void** buffer)
{
   return video_context->lpVtbl->GetDecoderBuffer(video_context, decoder, type, buffer_size, buffer);
}
static inline HRESULT D3D11ReleaseDecoderBuffer(D3D11VideoContext video_context, D3D11VideoDecoder decoder, D3D11_VIDEO_DECODER_BUFFER_TYPE type)
{
   return video_context->lpVtbl->ReleaseDecoderBuffer(video_context, decoder, type);
}
static inline HRESULT D3D11DecoderBeginFrame(D3D11VideoContext video_context, D3D11VideoDecoder decoder, D3D11VideoDecoderOutputView view, UINT content_key_size, void* content_key)
{
   return video_context->lpVtbl->DecoderBeginFrame(video_context, decoder, view, content_key_size, content_key);
}
static inline HRESULT D3D11DecoderEndFrame(D3D11VideoContext video_context, D3D11VideoDecoder decoder)
{
   return video_context->lpVtbl->DecoderEndFrame(video_context, decoder);
}
static inline HRESULT D3D11SubmitDecoderBuffers(D3D11VideoContext video_context, D3D11VideoDecoder decoder, UINT num_buffers, D3D11_VIDEO_DECODER_BUFFER_DESC* buffer_desc)
{
   return video_context->lpVtbl->SubmitDecoderBuffers(video_context, decoder, num_buffers, buffer_desc);
}
static inline APP_DEPRECATED_HRESULT D3D11DecoderExtension(D3D11VideoContext video_context, D3D11VideoDecoder decoder, D3D11_VIDEO_DECODER_EXTENSION* extension_data)
{
   return video_context->lpVtbl->DecoderExtension(video_context, decoder, extension_data);
}
static inline void D3D11VideoProcessorSetOutputTargetRect(D3D11VideoContext video_context, D3D11VideoProcessor video_processor, BOOL enable, RECT* rect)
{
   video_context->lpVtbl->VideoProcessorSetOutputTargetRect(video_context, video_processor, enable, rect);
}
static inline void D3D11VideoProcessorSetOutputBackgroundColor(D3D11VideoContext video_context, D3D11VideoProcessor video_processor, BOOL ycb_cr, D3D11_VIDEO_COLOR* color)
{
   video_context->lpVtbl->VideoProcessorSetOutputBackgroundColor(video_context, video_processor, ycb_cr, color);
}
static inline void D3D11VideoProcessorSetOutputColorSpace(D3D11VideoContext video_context, D3D11VideoProcessor video_processor, D3D11_VIDEO_PROCESSOR_COLOR_SPACE* color_space)
{
   video_context->lpVtbl->VideoProcessorSetOutputColorSpace(video_context, video_processor, color_space);
}
static inline void D3D11VideoProcessorSetOutputAlphaFillMode(D3D11VideoContext video_context, D3D11VideoProcessor video_processor, D3D11_VIDEO_PROCESSOR_ALPHA_FILL_MODE alpha_fill_mode, UINT stream_index)
{
   video_context->lpVtbl->VideoProcessorSetOutputAlphaFillMode(video_context, video_processor, alpha_fill_mode, stream_index);
}
static inline void D3D11VideoProcessorSetOutputConstriction(D3D11VideoContext video_context, D3D11VideoProcessor video_processor, BOOL enable, SIZE size)
{
   video_context->lpVtbl->VideoProcessorSetOutputConstriction(video_context, video_processor, enable, size);
}
static inline void D3D11VideoProcessorSetOutputStereoMode(D3D11VideoContext video_context, D3D11VideoProcessor video_processor, BOOL enable)
{
   video_context->lpVtbl->VideoProcessorSetOutputStereoMode(video_context, video_processor, enable);
}
static inline APP_DEPRECATED_HRESULT D3D11VideoProcessorSetOutputExtension(D3D11VideoContext video_context, D3D11VideoProcessor video_processor, GUID* extension_guid, UINT data_size, void* data)
{
   return video_context->lpVtbl->VideoProcessorSetOutputExtension(video_context, video_processor, extension_guid, data_size, data);
}
static inline void D3D11VideoProcessorGetOutputTargetRect(D3D11VideoContext video_context, D3D11VideoProcessor video_processor, BOOL* enabled, RECT* rect)
{
   video_context->lpVtbl->VideoProcessorGetOutputTargetRect(video_context, video_processor, enabled, rect);
}
static inline void D3D11VideoProcessorGetOutputBackgroundColor(D3D11VideoContext video_context, D3D11VideoProcessor video_processor, BOOL* ycb_cr, D3D11_VIDEO_COLOR* color)
{
   video_context->lpVtbl->VideoProcessorGetOutputBackgroundColor(video_context, video_processor, ycb_cr, color);
}
static inline void D3D11VideoProcessorGetOutputColorSpace(D3D11VideoContext video_context, D3D11VideoProcessor video_processor, D3D11_VIDEO_PROCESSOR_COLOR_SPACE* color_space)
{
   video_context->lpVtbl->VideoProcessorGetOutputColorSpace(video_context, video_processor, color_space);
}
static inline void D3D11VideoProcessorGetOutputAlphaFillMode(D3D11VideoContext video_context, D3D11VideoProcessor video_processor, D3D11_VIDEO_PROCESSOR_ALPHA_FILL_MODE* alpha_fill_mode, UINT* stream_index)
{
   video_context->lpVtbl->VideoProcessorGetOutputAlphaFillMode(video_context, video_processor, alpha_fill_mode, stream_index);
}
static inline void D3D11VideoProcessorGetOutputConstriction(D3D11VideoContext video_context, D3D11VideoProcessor video_processor, BOOL* enabled, SIZE* size)
{
   video_context->lpVtbl->VideoProcessorGetOutputConstriction(video_context, video_processor, enabled, size);
}
static inline void D3D11VideoProcessorGetOutputStereoMode(D3D11VideoContext video_context, D3D11VideoProcessor video_processor, BOOL* enabled)
{
   video_context->lpVtbl->VideoProcessorGetOutputStereoMode(video_context, video_processor, enabled);
}
static inline APP_DEPRECATED_HRESULT D3D11VideoProcessorGetOutputExtension(D3D11VideoContext video_context, D3D11VideoProcessor video_processor, GUID* extension_guid, UINT data_size, void* data)
{
   return video_context->lpVtbl->VideoProcessorGetOutputExtension(video_context, video_processor, extension_guid, data_size, data);
}
static inline void D3D11VideoProcessorSetStreamFrameFormat(D3D11VideoContext video_context, D3D11VideoProcessor video_processor, UINT stream_index, D3D11_VIDEO_FRAME_FORMAT frame_format)
{
   video_context->lpVtbl->VideoProcessorSetStreamFrameFormat(video_context, video_processor, stream_index, frame_format);
}
static inline void D3D11VideoProcessorSetStreamColorSpace(D3D11VideoContext video_context, D3D11VideoProcessor video_processor, UINT stream_index, D3D11_VIDEO_PROCESSOR_COLOR_SPACE* color_space)
{
   video_context->lpVtbl->VideoProcessorSetStreamColorSpace(video_context, video_processor, stream_index, color_space);
}
static inline void D3D11VideoProcessorSetStreamOutputRate(D3D11VideoContext video_context, D3D11VideoProcessor video_processor, UINT stream_index, D3D11_VIDEO_PROCESSOR_OUTPUT_RATE output_rate, BOOL repeat_frame, DXGI_RATIONAL* custom_rate)
{
   video_context->lpVtbl->VideoProcessorSetStreamOutputRate(video_context, video_processor, stream_index, output_rate, repeat_frame, custom_rate);
}
static inline void D3D11VideoProcessorSetStreamSourceRect(D3D11VideoContext video_context, D3D11VideoProcessor video_processor, UINT stream_index, BOOL enable, RECT* rect)
{
   video_context->lpVtbl->VideoProcessorSetStreamSourceRect(video_context, video_processor, stream_index, enable, rect);
}
static inline void D3D11VideoProcessorSetStreamDestRect(D3D11VideoContext video_context, D3D11VideoProcessor video_processor, UINT stream_index, BOOL enable, RECT* rect)
{
   video_context->lpVtbl->VideoProcessorSetStreamDestRect(video_context, video_processor, stream_index, enable, rect);
}
static inline void D3D11VideoProcessorSetStreamAlpha(D3D11VideoContext video_context, D3D11VideoProcessor video_processor, UINT stream_index, BOOL enable, FLOAT alpha)
{
   video_context->lpVtbl->VideoProcessorSetStreamAlpha(video_context, video_processor, stream_index, enable, alpha);
}
static inline void D3D11VideoProcessorSetStreamPalette(D3D11VideoContext video_context, D3D11VideoProcessor video_processor, UINT stream_index, UINT count, UINT* entries)
{
   video_context->lpVtbl->VideoProcessorSetStreamPalette(video_context, video_processor, stream_index, count, entries);
}
static inline void D3D11VideoProcessorSetStreamPixelAspectRatio(D3D11VideoContext video_context, D3D11VideoProcessor video_processor, UINT stream_index, BOOL enable, DXGI_RATIONAL* source_aspect_ratio, DXGI_RATIONAL* destination_aspect_ratio)
{
   video_context->lpVtbl->VideoProcessorSetStreamPixelAspectRatio(video_context, video_processor, stream_index, enable, source_aspect_ratio, destination_aspect_ratio);
}
static inline void D3D11VideoProcessorSetStreamLumaKey(D3D11VideoContext video_context, D3D11VideoProcessor video_processor, UINT stream_index, BOOL enable, FLOAT lower, FLOAT upper)
{
   video_context->lpVtbl->VideoProcessorSetStreamLumaKey(video_context, video_processor, stream_index, enable, lower, upper);
}
static inline void D3D11VideoProcessorSetStreamStereoFormat(D3D11VideoContext video_context, D3D11VideoProcessor video_processor, UINT stream_index, BOOL enable, D3D11_VIDEO_PROCESSOR_STEREO_FORMAT format, BOOL left_view_frame0, BOOL base_view_frame0, D3D11_VIDEO_PROCESSOR_STEREO_FLIP_MODE flip_mode, int mono_offset)
{
   video_context->lpVtbl->VideoProcessorSetStreamStereoFormat(video_context, video_processor, stream_index, enable, format, left_view_frame0, base_view_frame0, flip_mode, mono_offset);
}
static inline void D3D11VideoProcessorSetStreamAutoProcessingMode(D3D11VideoContext video_context, D3D11VideoProcessor video_processor, UINT stream_index, BOOL enable)
{
   video_context->lpVtbl->VideoProcessorSetStreamAutoProcessingMode(video_context, video_processor, stream_index, enable);
}
static inline void D3D11VideoProcessorSetStreamFilter(D3D11VideoContext video_context, D3D11VideoProcessor video_processor, UINT stream_index, D3D11_VIDEO_PROCESSOR_FILTER filter, BOOL enable, int level)
{
   video_context->lpVtbl->VideoProcessorSetStreamFilter(video_context, video_processor, stream_index, filter, enable, level);
}
static inline APP_DEPRECATED_HRESULT D3D11VideoProcessorSetStreamExtension(D3D11VideoContext video_context, D3D11VideoProcessor video_processor, UINT stream_index, GUID* extension_guid, UINT data_size, void* data)
{
   return video_context->lpVtbl->VideoProcessorSetStreamExtension(video_context, video_processor, stream_index, extension_guid, data_size, data);
}
static inline void D3D11VideoProcessorGetStreamFrameFormat(D3D11VideoContext video_context, D3D11VideoProcessor video_processor, UINT stream_index, D3D11_VIDEO_FRAME_FORMAT* frame_format)
{
   video_context->lpVtbl->VideoProcessorGetStreamFrameFormat(video_context, video_processor, stream_index, frame_format);
}
static inline void D3D11VideoProcessorGetStreamColorSpace(D3D11VideoContext video_context, D3D11VideoProcessor video_processor, UINT stream_index, D3D11_VIDEO_PROCESSOR_COLOR_SPACE* color_space)
{
   video_context->lpVtbl->VideoProcessorGetStreamColorSpace(video_context, video_processor, stream_index, color_space);
}
static inline void D3D11VideoProcessorGetStreamOutputRate(D3D11VideoContext video_context, D3D11VideoProcessor video_processor, UINT stream_index, D3D11_VIDEO_PROCESSOR_OUTPUT_RATE* output_rate, BOOL* repeat_frame, DXGI_RATIONAL* custom_rate)
{
   video_context->lpVtbl->VideoProcessorGetStreamOutputRate(video_context, video_processor, stream_index, output_rate, repeat_frame, custom_rate);
}
static inline void D3D11VideoProcessorGetStreamSourceRect(D3D11VideoContext video_context, D3D11VideoProcessor video_processor, UINT stream_index, BOOL* enabled, RECT* rect)
{
   video_context->lpVtbl->VideoProcessorGetStreamSourceRect(video_context, video_processor, stream_index, enabled, rect);
}
static inline void D3D11VideoProcessorGetStreamDestRect(D3D11VideoContext video_context, D3D11VideoProcessor video_processor, UINT stream_index, BOOL* enabled, RECT* rect)
{
   video_context->lpVtbl->VideoProcessorGetStreamDestRect(video_context, video_processor, stream_index, enabled, rect);
}
static inline void D3D11VideoProcessorGetStreamAlpha(D3D11VideoContext video_context, D3D11VideoProcessor video_processor, UINT stream_index, BOOL* enabled, FLOAT* alpha)
{
   video_context->lpVtbl->VideoProcessorGetStreamAlpha(video_context, video_processor, stream_index, enabled, alpha);
}
static inline void D3D11VideoProcessorGetStreamPalette(D3D11VideoContext video_context, D3D11VideoProcessor video_processor, UINT stream_index, UINT count, UINT* entries)
{
   video_context->lpVtbl->VideoProcessorGetStreamPalette(video_context, video_processor, stream_index, count, entries);
}
static inline void D3D11VideoProcessorGetStreamPixelAspectRatio(D3D11VideoContext video_context, D3D11VideoProcessor video_processor, UINT stream_index, BOOL* enabled, DXGI_RATIONAL* source_aspect_ratio, DXGI_RATIONAL* destination_aspect_ratio)
{
   video_context->lpVtbl->VideoProcessorGetStreamPixelAspectRatio(video_context, video_processor, stream_index, enabled, source_aspect_ratio, destination_aspect_ratio);
}
static inline void D3D11VideoProcessorGetStreamLumaKey(D3D11VideoContext video_context, D3D11VideoProcessor video_processor, UINT stream_index, BOOL* enabled, FLOAT* lower, FLOAT* upper)
{
   video_context->lpVtbl->VideoProcessorGetStreamLumaKey(video_context, video_processor, stream_index, enabled, lower, upper);
}
static inline void D3D11VideoProcessorGetStreamStereoFormat(D3D11VideoContext video_context, D3D11VideoProcessor video_processor, UINT stream_index, BOOL* enable, D3D11_VIDEO_PROCESSOR_STEREO_FORMAT* format, BOOL* left_view_frame0, BOOL* base_view_frame0, D3D11_VIDEO_PROCESSOR_STEREO_FLIP_MODE* flip_mode, int* mono_offset)
{
   video_context->lpVtbl->VideoProcessorGetStreamStereoFormat(video_context, video_processor, stream_index, enable, format, left_view_frame0, base_view_frame0, flip_mode, mono_offset);
}
static inline void D3D11VideoProcessorGetStreamAutoProcessingMode(D3D11VideoContext video_context, D3D11VideoProcessor video_processor, UINT stream_index, BOOL* enabled)
{
   video_context->lpVtbl->VideoProcessorGetStreamAutoProcessingMode(video_context, video_processor, stream_index, enabled);
}
static inline void D3D11VideoProcessorGetStreamFilter(D3D11VideoContext video_context, D3D11VideoProcessor video_processor, UINT stream_index, D3D11_VIDEO_PROCESSOR_FILTER filter, BOOL* enabled, int* level)
{
   video_context->lpVtbl->VideoProcessorGetStreamFilter(video_context, video_processor, stream_index, filter, enabled, level);
}
static inline APP_DEPRECATED_HRESULT D3D11VideoProcessorGetStreamExtension(D3D11VideoContext video_context, D3D11VideoProcessor video_processor, UINT stream_index, GUID* extension_guid, UINT data_size, void* data)
{
   return video_context->lpVtbl->VideoProcessorGetStreamExtension(video_context, video_processor, stream_index, extension_guid, data_size, data);
}
static inline HRESULT D3D11VideoProcessorBlt(D3D11VideoContext video_context, D3D11VideoProcessor video_processor, D3D11VideoProcessorOutputView view, UINT output_frame, UINT stream_count, D3D11_VIDEO_PROCESSOR_STREAM* streams)
{
   return video_context->lpVtbl->VideoProcessorBlt(video_context, video_processor, view, output_frame, stream_count, streams);
}
static inline HRESULT D3D11NegotiateCryptoSessionKeyExchange(D3D11VideoContext video_context, D3D11CryptoSession crypto_session, UINT data_size, void* data)
{
   return video_context->lpVtbl->NegotiateCryptoSessionKeyExchange(video_context, crypto_session, data_size, data);
}
static inline void D3D11EncryptionBlt(D3D11VideoContext video_context, D3D11CryptoSession crypto_session, D3D11Texture2D src_surface, D3D11Texture2D dst_surface, UINT ivsize, void* iv)
{
   video_context->lpVtbl->EncryptionBlt(video_context, crypto_session, src_surface, dst_surface, ivsize, iv);
}
static inline void D3D11DecryptionBlt(D3D11VideoContext video_context, D3D11CryptoSession crypto_session, D3D11Texture2D src_surface, D3D11Texture2D dst_surface, D3D11_ENCRYPTED_BLOCK_INFO* encrypted_block_info, UINT content_key_size, void* content_key, UINT ivsize, void* iv)
{
   video_context->lpVtbl->DecryptionBlt(video_context, crypto_session, src_surface, dst_surface, encrypted_block_info, content_key_size, content_key, ivsize, iv);
}
static inline void D3D11StartSessionKeyRefresh(D3D11VideoContext video_context, D3D11CryptoSession crypto_session, UINT random_number_size, void* random_number)
{
   video_context->lpVtbl->StartSessionKeyRefresh(video_context, crypto_session, random_number_size, random_number);
}
static inline void D3D11FinishSessionKeyRefresh(D3D11VideoContext video_context, D3D11CryptoSession crypto_session)
{
   video_context->lpVtbl->FinishSessionKeyRefresh(video_context, crypto_session);
}
static inline HRESULT D3D11GetEncryptionBltKey(D3D11VideoContext video_context, D3D11CryptoSession crypto_session, UINT key_size, void* readback_key)
{
   return video_context->lpVtbl->GetEncryptionBltKey(video_context, crypto_session, key_size, readback_key);
}
static inline HRESULT D3D11NegotiateAuthenticatedChannelKeyExchange(D3D11VideoContext video_context, D3D11AuthenticatedChannel channel, UINT data_size, void* data)
{
   return video_context->lpVtbl->NegotiateAuthenticatedChannelKeyExchange(video_context, channel, data_size, data);
}
static inline HRESULT D3D11QueryAuthenticatedChannel(D3D11VideoContext video_context, D3D11AuthenticatedChannel channel, UINT input_size, void* input, UINT output_size, void* output)
{
   return video_context->lpVtbl->QueryAuthenticatedChannel(video_context, channel, input_size, input, output_size, output);
}
static inline HRESULT D3D11ConfigureAuthenticatedChannel(D3D11VideoContext video_context, D3D11AuthenticatedChannel channel, UINT input_size, void* input, D3D11_AUTHENTICATED_CONFIGURE_OUTPUT* output)
{
   return video_context->lpVtbl->ConfigureAuthenticatedChannel(video_context, channel, input_size, input, output);
}
static inline void D3D11VideoProcessorSetStreamRotation(D3D11VideoContext video_context, D3D11VideoProcessor video_processor, UINT stream_index, BOOL enable, D3D11_VIDEO_PROCESSOR_ROTATION rotation)
{
   video_context->lpVtbl->VideoProcessorSetStreamRotation(video_context, video_processor, stream_index, enable, rotation);
}
static inline void D3D11VideoProcessorGetStreamRotation(D3D11VideoContext video_context, D3D11VideoProcessor video_processor, UINT stream_index, BOOL* enable, D3D11_VIDEO_PROCESSOR_ROTATION* rotation)
{
   video_context->lpVtbl->VideoProcessorGetStreamRotation(video_context, video_processor, stream_index, enable, rotation);
}
static inline HRESULT D3D11CreateVideoDecoder(D3D11VideoDevice video_device, D3D11_VIDEO_DECODER_DESC* video_desc, D3D11_VIDEO_DECODER_CONFIG* config, D3D11VideoDecoder* decoder)
{
   return video_device->lpVtbl->CreateVideoDecoder(video_device, video_desc, config, decoder);
}
static inline HRESULT D3D11CreateVideoProcessor(D3D11VideoDevice video_device, D3D11VideoProcessorEnumerator enumerator, UINT rate_conversion_index, D3D11VideoProcessor* video_processor)
{
   return video_device->lpVtbl->CreateVideoProcessor(video_device, enumerator, rate_conversion_index, video_processor);
}
static inline HRESULT D3D11CreateAuthenticatedChannel(D3D11VideoDevice video_device, D3D11_AUTHENTICATED_CHANNEL_TYPE channel_type, D3D11AuthenticatedChannel* authenticated_channel)
{
   return video_device->lpVtbl->CreateAuthenticatedChannel(video_device, channel_type, authenticated_channel);
}
static inline HRESULT D3D11CreateCryptoSession(D3D11VideoDevice video_device, GUID* crypto_type, GUID* decoder_profile, GUID* key_exchange_type, D3D11CryptoSession* crypto_session)
{
   return video_device->lpVtbl->CreateCryptoSession(video_device, crypto_type, decoder_profile, key_exchange_type, crypto_session);
}
static inline HRESULT D3D11CreateVideoDecoderOutputView(D3D11VideoDevice video_device, D3D11Resource resource, D3D11_VIDEO_DECODER_OUTPUT_VIEW_DESC* desc, D3D11VideoDecoderOutputView* vdovview)
{
   return video_device->lpVtbl->CreateVideoDecoderOutputView(video_device, resource, desc, vdovview);
}
static inline HRESULT D3D11CreateVideoProcessorInputView(D3D11VideoDevice video_device, D3D11Resource resource, D3D11VideoProcessorEnumerator enumerator, D3D11_VIDEO_PROCESSOR_INPUT_VIEW_DESC* desc, D3D11VideoProcessorInputView* vpiview)
{
   return video_device->lpVtbl->CreateVideoProcessorInputView(video_device, resource, enumerator, desc, vpiview);
}
static inline HRESULT D3D11CreateVideoProcessorOutputView(D3D11VideoDevice video_device, D3D11Resource resource, D3D11VideoProcessorEnumerator enumerator, D3D11_VIDEO_PROCESSOR_OUTPUT_VIEW_DESC* desc, D3D11VideoProcessorOutputView* vpoview)
{
   return video_device->lpVtbl->CreateVideoProcessorOutputView(video_device, resource, enumerator, desc, vpoview);
}
static inline HRESULT D3D11CreateVideoProcessorEnumerator(D3D11VideoDevice video_device, D3D11_VIDEO_PROCESSOR_CONTENT_DESC* desc, D3D11VideoProcessorEnumerator* enumerator)
{
   return video_device->lpVtbl->CreateVideoProcessorEnumerator(video_device, desc, enumerator);
}
static inline UINT D3D11GetVideoDecoderProfileCount(D3D11VideoDevice video_device)
{
   return video_device->lpVtbl->GetVideoDecoderProfileCount(video_device);
}
static inline HRESULT D3D11GetVideoDecoderProfile(D3D11VideoDevice video_device, UINT index, GUID* decoder_profile)
{
   return video_device->lpVtbl->GetVideoDecoderProfile(video_device, index, decoder_profile);
}
static inline HRESULT D3D11CheckVideoDecoderFormat(D3D11VideoDevice video_device, GUID* decoder_profile, DXGI_FORMAT format, BOOL* supported)
{
   return video_device->lpVtbl->CheckVideoDecoderFormat(video_device, decoder_profile, format, supported);
}
static inline HRESULT D3D11GetVideoDecoderConfigCount(D3D11VideoDevice video_device, D3D11_VIDEO_DECODER_DESC* desc, UINT* count)
{
   return video_device->lpVtbl->GetVideoDecoderConfigCount(video_device, desc, count);
}
static inline HRESULT D3D11GetVideoDecoderConfig(D3D11VideoDevice video_device, D3D11_VIDEO_DECODER_DESC* desc, UINT index, D3D11_VIDEO_DECODER_CONFIG* config)
{
   return video_device->lpVtbl->GetVideoDecoderConfig(video_device, desc, index, config);
}
static inline HRESULT D3D11GetContentProtectionCaps(D3D11VideoDevice video_device, GUID* crypto_type, GUID* decoder_profile, D3D11_VIDEO_CONTENT_PROTECTION_CAPS* caps)
{
   return video_device->lpVtbl->GetContentProtectionCaps(video_device, crypto_type, decoder_profile, caps);
}
static inline HRESULT D3D11CheckCryptoKeyExchange(D3D11VideoDevice video_device, GUID* crypto_type, GUID* decoder_profile, UINT index, GUID* key_exchange_type)
{
   return video_device->lpVtbl->CheckCryptoKeyExchange(video_device, crypto_type, decoder_profile, index, key_exchange_type);
}
static inline HRESULT D3D11CreateBuffer(D3D11Device device, D3D11_BUFFER_DESC* desc, D3D11_SUBRESOURCE_DATA* initial_data, D3D11Buffer* buffer)
{
   return device->lpVtbl->CreateBuffer(device, desc, initial_data, buffer);
}
static inline HRESULT D3D11CreateTexture1D(D3D11Device device, D3D11_TEXTURE1D_DESC* desc, D3D11_SUBRESOURCE_DATA* initial_data, D3D11Texture1D* texture1d)
{
   return device->lpVtbl->CreateTexture1D(device, desc, initial_data, texture1d);
}
static inline HRESULT D3D11CreateTexture2D(D3D11Device device, D3D11_TEXTURE2D_DESC* desc, D3D11_SUBRESOURCE_DATA* initial_data, D3D11Texture2D* texture2d)
{
   return device->lpVtbl->CreateTexture2D(device, desc, initial_data, texture2d);
}
static inline HRESULT D3D11CreateTexture3D(D3D11Device device, D3D11_TEXTURE3D_DESC* desc, D3D11_SUBRESOURCE_DATA* initial_data, D3D11Texture3D* texture3d)
{
   return device->lpVtbl->CreateTexture3D(device, desc, initial_data, texture3d);
}
static inline HRESULT D3D11CreateShaderResourceView(D3D11Device device, D3D11Resource resource, D3D11_SHADER_RESOURCE_VIEW_DESC* desc, D3D11ShaderResourceView* srview)
{
   return device->lpVtbl->CreateShaderResourceView(device, resource, desc, srview);
}
static inline HRESULT D3D11CreateUnorderedAccessView(D3D11Device device, D3D11Resource resource, D3D11_UNORDERED_ACCESS_VIEW_DESC* desc, D3D11UnorderedAccessView* uaview)
{
   return device->lpVtbl->CreateUnorderedAccessView(device, resource, desc, uaview);
}
static inline HRESULT D3D11CreateRenderTargetView(D3D11Device device, D3D11Resource resource, D3D11_RENDER_TARGET_VIEW_DESC* desc, D3D11RenderTargetView* rtview)
{
   return device->lpVtbl->CreateRenderTargetView(device, resource, desc, rtview);
}
static inline HRESULT D3D11CreateDepthStencilView(D3D11Device device, D3D11Resource resource, D3D11_DEPTH_STENCIL_VIEW_DESC* desc, D3D11DepthStencilView* depth_stencil_view)
{
   return device->lpVtbl->CreateDepthStencilView(device, resource, desc, depth_stencil_view);
}
static inline HRESULT D3D11CreateInputLayout(D3D11Device device, D3D11_INPUT_ELEMENT_DESC* input_element_descs, UINT num_elements, void* shader_bytecode_with_input_signature, SIZE_T bytecode_length, D3D11InputLayout* input_layout)
{
   return device->lpVtbl->CreateInputLayout(device, input_element_descs, num_elements, shader_bytecode_with_input_signature, bytecode_length, input_layout);
}
static inline HRESULT D3D11CreateVertexShader(D3D11Device device, void* shader_bytecode, SIZE_T bytecode_length, D3D11ClassLinkage class_linkage, D3D11VertexShader* vertex_shader)
{
   return device->lpVtbl->CreateVertexShader(device, shader_bytecode, bytecode_length, class_linkage, vertex_shader);
}
static inline HRESULT D3D11CreateGeometryShader(D3D11Device device, void* shader_bytecode, SIZE_T bytecode_length, D3D11ClassLinkage class_linkage, D3D11GeometryShader* geometry_shader)
{
   return device->lpVtbl->CreateGeometryShader(device, shader_bytecode, bytecode_length, class_linkage, geometry_shader);
}
static inline HRESULT D3D11CreateGeometryShaderWithStreamOutput(D3D11Device device, void* shader_bytecode, SIZE_T bytecode_length, D3D11_SO_DECLARATION_ENTRY* sodeclaration, UINT num_entries, UINT* buffer_strides, UINT num_strides, UINT rasterized_stream, D3D11ClassLinkage class_linkage, D3D11GeometryShader* geometry_shader)
{
   return device->lpVtbl->CreateGeometryShaderWithStreamOutput(device, shader_bytecode, bytecode_length, sodeclaration, num_entries, buffer_strides, num_strides, rasterized_stream, class_linkage, geometry_shader);
}
static inline HRESULT D3D11CreatePixelShader(D3D11Device device, void* shader_bytecode, SIZE_T bytecode_length, D3D11ClassLinkage class_linkage, D3D11PixelShader* pixel_shader)
{
   return device->lpVtbl->CreatePixelShader(device, shader_bytecode, bytecode_length, class_linkage, pixel_shader);
}
static inline HRESULT D3D11CreateHullShader(D3D11Device device, void* shader_bytecode, SIZE_T bytecode_length, D3D11ClassLinkage class_linkage, D3D11HullShader* hull_shader)
{
   return device->lpVtbl->CreateHullShader(device, shader_bytecode, bytecode_length, class_linkage, hull_shader);
}
static inline HRESULT D3D11CreateDomainShader(D3D11Device device, void* shader_bytecode, SIZE_T bytecode_length, D3D11ClassLinkage class_linkage, D3D11DomainShader* domain_shader)
{
   return device->lpVtbl->CreateDomainShader(device, shader_bytecode, bytecode_length, class_linkage, domain_shader);
}
static inline HRESULT D3D11CreateComputeShader(D3D11Device device, void* shader_bytecode, SIZE_T bytecode_length, D3D11ClassLinkage class_linkage, D3D11ComputeShader* compute_shader)
{
   return device->lpVtbl->CreateComputeShader(device, shader_bytecode, bytecode_length, class_linkage, compute_shader);
}
static inline HRESULT D3D11CreateClassLinkage(D3D11Device device, D3D11ClassLinkage* linkage)
{
   return device->lpVtbl->CreateClassLinkage(device, linkage);
}
static inline HRESULT D3D11CreateBlendState(D3D11Device device, D3D11_BLEND_DESC* blend_state_desc, D3D11BlendState* blend_state)
{
   return device->lpVtbl->CreateBlendState(device, blend_state_desc, blend_state);
}
static inline HRESULT D3D11CreateDepthStencilState(D3D11Device device, D3D11_DEPTH_STENCIL_DESC* depth_stencil_desc, D3D11DepthStencilState* depth_stencil_state)
{
   return device->lpVtbl->CreateDepthStencilState(device, depth_stencil_desc, depth_stencil_state);
}
static inline HRESULT D3D11CreateRasterizerState(D3D11Device device, D3D11_RASTERIZER_DESC* rasterizer_desc, D3D11RasterizerState* rasterizer_state)
{
   return device->lpVtbl->CreateRasterizerState(device, rasterizer_desc, rasterizer_state);
}
static inline HRESULT D3D11CreateSamplerState(D3D11Device device, D3D11_SAMPLER_DESC* sampler_desc, D3D11SamplerState* sampler_state)
{
   return device->lpVtbl->CreateSamplerState(device, sampler_desc, sampler_state);
}
static inline HRESULT D3D11CreateQuery(D3D11Device device, D3D11_QUERY_DESC* query_desc, D3D11Query* query)
{
   return device->lpVtbl->CreateQuery(device, query_desc, query);
}
static inline HRESULT D3D11CreatePredicate(D3D11Device device, D3D11_QUERY_DESC* predicate_desc, D3D11Predicate* predicate)
{
   return device->lpVtbl->CreatePredicate(device, predicate_desc, predicate);
}
static inline HRESULT D3D11CreateCounter(D3D11Device device, D3D11_COUNTER_DESC* counter_desc, D3D11Counter* counter)
{
   return device->lpVtbl->CreateCounter(device, counter_desc, counter);
}
static inline HRESULT D3D11CreateDeferredContext(D3D11Device device, UINT context_flags, D3D11DeviceContext* deferred_context)
{
   return device->lpVtbl->CreateDeferredContext(device, context_flags, deferred_context);
}
static inline HRESULT D3D11OpenSharedResource(D3D11Device device, HANDLE h_resource, ID3D11Resource** out)
{
   return device->lpVtbl->OpenSharedResource(device, h_resource, __uuidof(ID3D11Resource), (void**)out);
}
static inline HRESULT D3D11CheckFormatSupport(D3D11Device device, DXGI_FORMAT format, UINT* format_support)
{
   return device->lpVtbl->CheckFormatSupport(device, format, format_support);
}
static inline HRESULT D3D11CheckMultisampleQualityLevels(D3D11Device device, DXGI_FORMAT format, UINT sample_count, UINT* num_quality_levels)
{
   return device->lpVtbl->CheckMultisampleQualityLevels(device, format, sample_count, num_quality_levels);
}
static inline void D3D11CheckCounterInfo(D3D11Device device, D3D11_COUNTER_INFO* counter_info)
{
   device->lpVtbl->CheckCounterInfo(device, counter_info);
}
static inline HRESULT D3D11CheckCounter(D3D11Device device, D3D11_COUNTER_DESC* desc, D3D11_COUNTER_TYPE* type, UINT* active_counters, LPSTR sz_name, UINT* name_length, LPSTR sz_units, UINT* units_length, LPSTR sz_description, UINT* description_length)
{
   return device->lpVtbl->CheckCounter(device, desc, type, active_counters, sz_name, name_length, sz_units, units_length, sz_description, description_length);
}
static inline HRESULT D3D11CheckFeatureSupport(D3D11Device device, D3D11_FEATURE feature, void* feature_support_data, UINT feature_support_data_size)
{
   return device->lpVtbl->CheckFeatureSupport(device, feature, feature_support_data, feature_support_data_size);
}
static inline D3D_FEATURE_LEVEL D3D11GetFeatureLevel(D3D11Device device)
{
   return device->lpVtbl->GetFeatureLevel(device);
}
static inline UINT D3D11GetCreationFlags(D3D11Device device)
{
   return device->lpVtbl->GetCreationFlags(device);
}
static inline HRESULT D3D11GetDeviceRemovedReason(D3D11Device device)
{
   return device->lpVtbl->GetDeviceRemovedReason(device);
}
static inline void D3D11GetImmediateContext(D3D11Device device, D3D11DeviceContext* immediate_context)
{
   device->lpVtbl->GetImmediateContext(device, immediate_context);
}
static inline HRESULT D3D11SetExceptionMode(D3D11Device device, UINT raise_flags)
{
   return device->lpVtbl->SetExceptionMode(device, raise_flags);
}
static inline UINT D3D11GetExceptionMode(D3D11Device device)
{
   return device->lpVtbl->GetExceptionMode(device);
}
static inline HRESULT D3D11SetDebugFeatureMask(D3D11Debug debug, UINT mask)
{
   return debug->lpVtbl->SetFeatureMask(debug, mask);
}
static inline UINT D3D11GetDebugFeatureMask(D3D11Debug debug)
{
   return debug->lpVtbl->GetFeatureMask(debug);
}
static inline HRESULT D3D11SetPresentPerRenderOpDelay(D3D11Debug debug, UINT milliseconds)
{
   return debug->lpVtbl->SetPresentPerRenderOpDelay(debug, milliseconds);
}
static inline UINT D3D11GetPresentPerRenderOpDelay(D3D11Debug debug)
{
   return debug->lpVtbl->GetPresentPerRenderOpDelay(debug);
}
static inline HRESULT D3D11SetSwapChain(D3D11Debug debug, IDXGISwapChain* swap_chain)
{
   return debug->lpVtbl->SetSwapChain(debug, (IDXGISwapChain*)swap_chain);
}
static inline HRESULT D3D11GetSwapChain(D3D11Debug debug, IDXGISwapChain** swap_chain)
{
   return debug->lpVtbl->GetSwapChain(debug, (IDXGISwapChain**)swap_chain);
}
static inline HRESULT D3D11ValidateContext(D3D11Debug debug, D3D11DeviceContext context)
{
   return debug->lpVtbl->ValidateContext(debug, context);
}
static inline HRESULT D3D11ReportLiveDeviceObjects(D3D11Debug debug, D3D11_RLDO_FLAGS flags)
{
   return debug->lpVtbl->ReportLiveDeviceObjects(debug, flags);
}
static inline HRESULT D3D11ValidateContextForDispatch(D3D11Debug debug, D3D11DeviceContext context)
{
   return debug->lpVtbl->ValidateContextForDispatch(debug, context);
}
static inline BOOL D3D11SetUseRef(D3D11SwitchToRef switch_to_ref, BOOL use_ref)
{
   return switch_to_ref->lpVtbl->SetUseRef(switch_to_ref, use_ref);
}
static inline BOOL D3D11GetUseRef(D3D11SwitchToRef switch_to_ref)
{
   return switch_to_ref->lpVtbl->GetUseRef(switch_to_ref);
}
static inline HRESULT D3D11SetShaderTrackingOptionsByType(D3D11TracingDevice tracing_device, UINT resource_type_flags, UINT options)
{
   return tracing_device->lpVtbl->SetShaderTrackingOptionsByType(tracing_device, resource_type_flags, options);
}
static inline HRESULT D3D11SetShaderTrackingOptions(D3D11TracingDevice tracing_device, void* shader, UINT options)
{
   return tracing_device->lpVtbl->SetShaderTrackingOptions(tracing_device, (IUnknown*)shader, options);
}
static inline HRESULT D3D11SetMessageCountLimit(D3D11InfoQueue info_queue, UINT64 message_count_limit)
{
   return info_queue->lpVtbl->SetMessageCountLimit(info_queue, message_count_limit);
}
static inline void D3D11ClearStoredMessages(D3D11InfoQueue info_queue)
{
   info_queue->lpVtbl->ClearStoredMessages(info_queue);
}
static inline HRESULT D3D11GetMessageA(D3D11InfoQueue info_queue, UINT64 message_index, D3D11_MESSAGE* message, SIZE_T* message_byte_length)
{
   return info_queue->lpVtbl->GetMessageA(info_queue, message_index, message, message_byte_length);
}
static inline UINT64 D3D11GetNumMessagesAllowedByStorageFilter(D3D11InfoQueue info_queue)
{
   return info_queue->lpVtbl->GetNumMessagesAllowedByStorageFilter(info_queue);
}
static inline UINT64 D3D11GetNumMessagesDeniedByStorageFilter(D3D11InfoQueue info_queue)
{
   return info_queue->lpVtbl->GetNumMessagesDeniedByStorageFilter(info_queue);
}
static inline UINT64 D3D11GetNumStoredMessages(D3D11InfoQueue info_queue)
{
   return info_queue->lpVtbl->GetNumStoredMessages(info_queue);
}
static inline UINT64 D3D11GetNumStoredMessagesAllowedByRetrievalFilter(D3D11InfoQueue info_queue)
{
   return info_queue->lpVtbl->GetNumStoredMessagesAllowedByRetrievalFilter(info_queue);
}
static inline UINT64 D3D11GetNumMessagesDiscardedByMessageCountLimit(D3D11InfoQueue info_queue)
{
   return info_queue->lpVtbl->GetNumMessagesDiscardedByMessageCountLimit(info_queue);
}
static inline UINT64 D3D11GetMessageCountLimit(D3D11InfoQueue info_queue)
{
   return info_queue->lpVtbl->GetMessageCountLimit(info_queue);
}
static inline HRESULT D3D11AddStorageFilterEntries(D3D11InfoQueue info_queue, D3D11_INFO_QUEUE_FILTER* filter)
{
   return info_queue->lpVtbl->AddStorageFilterEntries(info_queue, filter);
}
static inline HRESULT D3D11GetStorageFilter(D3D11InfoQueue info_queue, D3D11_INFO_QUEUE_FILTER* filter, SIZE_T* filter_byte_length)
{
   return info_queue->lpVtbl->GetStorageFilter(info_queue, filter, filter_byte_length);
}
static inline void D3D11ClearStorageFilter(D3D11InfoQueue info_queue)
{
   info_queue->lpVtbl->ClearStorageFilter(info_queue);
}
static inline HRESULT D3D11PushEmptyStorageFilter(D3D11InfoQueue info_queue)
{
   return info_queue->lpVtbl->PushEmptyStorageFilter(info_queue);
}
static inline HRESULT D3D11PushCopyOfStorageFilter(D3D11InfoQueue info_queue)
{
   return info_queue->lpVtbl->PushCopyOfStorageFilter(info_queue);
}
static inline HRESULT D3D11PushStorageFilter(D3D11InfoQueue info_queue, D3D11_INFO_QUEUE_FILTER* filter)
{
   return info_queue->lpVtbl->PushStorageFilter(info_queue, filter);
}
static inline void D3D11PopStorageFilter(D3D11InfoQueue info_queue)
{
   info_queue->lpVtbl->PopStorageFilter(info_queue);
}
static inline UINT D3D11GetStorageFilterStackSize(D3D11InfoQueue info_queue)
{
   return info_queue->lpVtbl->GetStorageFilterStackSize(info_queue);
}
static inline HRESULT D3D11AddRetrievalFilterEntries(D3D11InfoQueue info_queue, D3D11_INFO_QUEUE_FILTER* filter)
{
   return info_queue->lpVtbl->AddRetrievalFilterEntries(info_queue, filter);
}
static inline HRESULT D3D11GetRetrievalFilter(D3D11InfoQueue info_queue, D3D11_INFO_QUEUE_FILTER* filter, SIZE_T* filter_byte_length)
{
   return info_queue->lpVtbl->GetRetrievalFilter(info_queue, filter, filter_byte_length);
}
static inline void D3D11ClearRetrievalFilter(D3D11InfoQueue info_queue)
{
   info_queue->lpVtbl->ClearRetrievalFilter(info_queue);
}
static inline HRESULT D3D11PushEmptyRetrievalFilter(D3D11InfoQueue info_queue)
{
   return info_queue->lpVtbl->PushEmptyRetrievalFilter(info_queue);
}
static inline HRESULT D3D11PushCopyOfRetrievalFilter(D3D11InfoQueue info_queue)
{
   return info_queue->lpVtbl->PushCopyOfRetrievalFilter(info_queue);
}
static inline HRESULT D3D11PushRetrievalFilter(D3D11InfoQueue info_queue, D3D11_INFO_QUEUE_FILTER* filter)
{
   return info_queue->lpVtbl->PushRetrievalFilter(info_queue, filter);
}
static inline void D3D11PopRetrievalFilter(D3D11InfoQueue info_queue)
{
   info_queue->lpVtbl->PopRetrievalFilter(info_queue);
}
static inline UINT D3D11GetRetrievalFilterStackSize(D3D11InfoQueue info_queue)
{
   return info_queue->lpVtbl->GetRetrievalFilterStackSize(info_queue);
}
static inline HRESULT D3D11AddMessage(D3D11InfoQueue info_queue, D3D11_MESSAGE_CATEGORY category, D3D11_MESSAGE_SEVERITY severity, D3D11_MESSAGE_ID id, LPCSTR description)
{
   return info_queue->lpVtbl->AddMessage(info_queue, category, severity, id, description);
}
static inline HRESULT D3D11AddApplicationMessage(D3D11InfoQueue info_queue, D3D11_MESSAGE_SEVERITY severity, LPCSTR description)
{
   return info_queue->lpVtbl->AddApplicationMessage(info_queue, severity, description);
}
static inline HRESULT D3D11SetBreakOnCategory(D3D11InfoQueue info_queue, D3D11_MESSAGE_CATEGORY category, BOOL enable)
{
   return info_queue->lpVtbl->SetBreakOnCategory(info_queue, category, enable);
}
static inline HRESULT D3D11SetBreakOnSeverity(D3D11InfoQueue info_queue, D3D11_MESSAGE_SEVERITY severity, BOOL enable)
{
   return info_queue->lpVtbl->SetBreakOnSeverity(info_queue, severity, enable);
}
static inline HRESULT D3D11SetBreakOnID(D3D11InfoQueue info_queue, D3D11_MESSAGE_ID id, BOOL enable)
{
   return info_queue->lpVtbl->SetBreakOnID(info_queue, id, enable);
}
static inline BOOL D3D11GetBreakOnCategory(D3D11InfoQueue info_queue, D3D11_MESSAGE_CATEGORY category)
{
   return info_queue->lpVtbl->GetBreakOnCategory(info_queue, category);
}
static inline BOOL D3D11GetBreakOnSeverity(D3D11InfoQueue info_queue, D3D11_MESSAGE_SEVERITY severity)
{
   return info_queue->lpVtbl->GetBreakOnSeverity(info_queue, severity);
}
static inline BOOL D3D11GetBreakOnID(D3D11InfoQueue info_queue, D3D11_MESSAGE_ID id)
{
   return info_queue->lpVtbl->GetBreakOnID(info_queue, id);
}
static inline void D3D11SetMuteDebugOutput(D3D11InfoQueue info_queue, BOOL mute)
{
   info_queue->lpVtbl->SetMuteDebugOutput(info_queue, mute);
}
static inline BOOL D3D11GetMuteDebugOutput(D3D11InfoQueue info_queue)
{
   return info_queue->lpVtbl->GetMuteDebugOutput(info_queue);
}
/* end of auto-generated */

static inline HRESULT DXGIGetSwapChainBufferD3D11(DXGISwapChain swap_chain, UINT buffer, D3D11Texture2D* out)
{
   return swap_chain->lpVtbl->GetBuffer(swap_chain, buffer, __uuidof(ID3D11Texture2D), (void**)out);
}

static inline HRESULT D3D11MapTexture2D(D3D11DeviceContext device_context, D3D11Texture2D texture, UINT subresource, D3D11_MAP map_type, UINT map_flags, D3D11_MAPPED_SUBRESOURCE* mapped_resource)
{
   return device_context->lpVtbl->Map(device_context, (D3D11Resource) texture, subresource, map_type, map_flags, mapped_resource);
}
static inline void D3D11UnmapTexture2D(D3D11DeviceContext device_context, D3D11Texture2D texture, UINT subresource)
{
   device_context->lpVtbl->Unmap(device_context, (D3D11Resource)texture, subresource);
}
static inline void D3D11CopyTexture2DSubresourceRegion(D3D11DeviceContext device_context, D3D11Texture2D dst_texture, UINT dst_subresource, UINT dst_x, UINT dst_y, UINT dst_z, D3D11Texture2D src_texture, UINT src_subresource, D3D11_BOX* src_box)
{
   device_context->lpVtbl->CopySubresourceRegion(device_context, (D3D11Resource)dst_texture, dst_subresource, dst_x, dst_y, dst_z, (D3D11Resource)src_texture, src_subresource, src_box);
}
static inline HRESULT D3D11CreateTexture2DRenderTargetView(D3D11Device device, D3D11Texture2D texture, D3D11_RENDER_TARGET_VIEW_DESC* desc, D3D11RenderTargetView* rtview)
{
   return device->lpVtbl->CreateRenderTargetView(device, (D3D11Resource)texture, desc, rtview);
}
static inline HRESULT D3D11CreateTexture2DShaderResourceView(D3D11Device device, D3D11Texture2D texture, D3D11_SHADER_RESOURCE_VIEW_DESC* desc, D3D11ShaderResourceView* srview)
{
   return device->lpVtbl->CreateShaderResourceView(device, (D3D11Resource)texture, desc, srview);
}

static inline HRESULT D3D11MapBuffer(D3D11DeviceContext device_context, D3D11Buffer buffer, UINT subresource, D3D11_MAP map_type, UINT map_flags, D3D11_MAPPED_SUBRESOURCE* mapped_resource)
{
   return device_context->lpVtbl->Map(device_context, (D3D11Resource)buffer, subresource, map_type, map_flags, mapped_resource);
}
static inline void D3D11UnmapBuffer(D3D11DeviceContext device_context, D3D11Buffer buffer, UINT subresource)
{
   device_context->lpVtbl->Unmap(device_context, (D3D11Resource)buffer, subresource);
}
