#include "types.h"
#include "pso/render/RenderSbssGlobals.h"
#include "pso/render/GinjaTexture.h"

// Data-only unit split off the shared render/geometry small statics at 0x805D7748.
// Plain uninitialized globals (-sdata 8) land in .sbss in source order; the
// many referencing units keep these extern.

u32 sin_cos_table;
GinjaSceneState *current_render_context;
u32 display_heap_size;
u32 locked_cache_heap_handle;
u32 active_texture_surface_count;
s32 texture_surface_count;
GinjaSurfaceState *texture_surfaces;
s32 texture_state_count;
GinjaTextureState *texture_states;
GC_Mtx *matrix_stack_limit;
GC_Mtx *matrix_stack_base;
GC_Mtx *current_matrix;
u32 *shape_vertex_buffer;
f32 lbl_805D777C;
u32 chunk_polygon_flags_or_mask;
u32 chunk_polygon_flags_and_mask;
u32 ginja_draw_flags;
u32 model_render_flags;
f32 light_position_distance;
u32 gx_chan_ctrl_light_mask;
u32 chunk_polygon_cache_pending[2];
