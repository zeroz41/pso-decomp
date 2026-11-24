#ifndef PSO_RENDER_GJLIGHT_H
#define PSO_RENDER_GJLIGHT_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

// The GX light mask bit of each light slot.
extern u32 light_slot_mask_table[5];

// Panics on a light slot outside 0..5.
void assert_light_id(s32 light);
// Sets the colour channel's ambient colour, each component clamped to 1.0.
void set_light_ambient_color(f32 r, f32 g, f32 b);
// Adds the light slot to the colour channel's light mask, or removes it when `enable` is 0.
void submit_light0(s32 light, s32 enable);
void set_gx_light_color(s32 light, f32 r, f32 g, f32 b);
// Slot 0 is a positional light placed far out against the direction; the other slots are directional lights.
void init_distant_light(s32 light, f32 x, f32 y, f32 z);
void load_gx_light_slot(s32 light);

#ifdef __cplusplus
}
#endif

#endif
