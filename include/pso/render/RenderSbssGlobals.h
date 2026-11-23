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
// The number of texture slots in use.
extern u32 player_ref_entry_active_count;

#endif
