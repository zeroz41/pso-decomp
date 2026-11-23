#ifndef PSO_OBJECT_AMBIENT_TOBJLIGHT_803DF220_H
#define PSO_OBJECT_AMBIENT_TOBJLIGHT_803DF220_H

#include "types.h"

extern "C" {
// Loads the camera view matrix, then sets up untextured colour drawing, blended when `blended`.
void setup_world_color_draw(s32 blended);
}
void init_distant_light(s32 idx, f32 x, f32 y, f32 z);
void load_gx_light_slot(s32 arg0);
void reset_player_transform(void);
void set_gx_light_color(s32 idx, f32 r, f32 g, f32 b);
void set_light_ambient_color(f32 r, f32 g, f32 b);
void submit_light0(s32 arg0, s32 arg1);

#endif
