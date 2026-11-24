#ifndef PSO_RENDER_SCENEFOG_H
#define PSO_RENDER_SCENEFOG_H

#include "types.h"

extern "C" {
// Sets the current matrix to the identity (hand-written paired-single assembly).
void identity_current_matrix_ps(void);
// Entry inside identity_current_matrix_ps after it loads the matrix pointer; push_identity_matrix_ps branches here.
void identity_matrix_ps_entry(void);
void push_identity_matrix_ps(void);
}

// The fog apply_scene_fog hands GX: on/off, colour (0xRRGGBBxx), start and end distance and GX fog type.
void enable_scene_fog();
void disable_scene_fog();
void set_scene_fog_color(u32 color);
void set_scene_fog_distances(f32 start, f32 end);
void set_scene_fog_type(s32 type);
void apply_scene_fog();
// White perspective fog from 0 to 1000000, enabled and applied.
void reset_scene_fog();

#endif
