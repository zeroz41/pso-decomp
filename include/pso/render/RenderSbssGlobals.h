#ifndef PSO_RENDER_RENDERSBSSGLOBALS_H
#define PSO_RENDER_RENDERSBSSGLOBALS_H

#include "types.h"
#include <dolphin/mtx/GeoTypes.h>
#include "pso/render/GinjaMaterialState.h"

// The matrix stack, set up in the locked cache by init_matrix_stack: its first
// slot, the slot on top and the last slot a push may use.
extern GC_Mtx *matrix_stack_base;
extern GC_Mtx *current_matrix;
extern GC_Mtx *matrix_stack_limit;

extern GinjaSceneState *current_render_context;

// The heap in the locked cache that texture pixels are allocated from.
extern u32 locked_cache_heap_handle;
// The locked-cache heap's size in bytes.
extern u32 display_heap_size;
// 1/65535, set by init_projection_state.
extern f32 lbl_805D777C;
// The number of texture surfaces in use.
extern u32 active_texture_surface_count;
// Where shape motions write their interpolated vertex lists (set_shape_vertex_buffer).
extern u32 *shape_vertex_buffer;

#endif
