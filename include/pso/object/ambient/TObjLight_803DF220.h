#ifndef PSO_OBJECT_AMBIENT_TOBJLIGHT_803DF220_H
#define PSO_OBJECT_AMBIENT_TOBJLIGHT_803DF220_H

#include "types.h"

extern "C" {
void TObjPlayer__sub_803DF768(s32 arg0);
}
void draw_untextured_trail_strip(void *arg0, void *arg1);
void init_distant_light(s32 idx, f32 x, f32 y, f32 z);
void load_gx_light_slot(s32 arg0);
void reset_player_transform(void);
void set_gx_light_color(s32 idx, f32 r, f32 g, f32 b);
void set_light_ambient_color(f32 r, f32 g, f32 b);
void submit_light0(s32 arg0, s32 arg1);

#endif
