#ifndef PSO_PLAYER_TOBJPLAYER_80141D1C_H
#define PSO_PLAYER_TOBJPLAYER_80141D1C_H

#include "types.h"
#include <dolphin/mtx.h>

extern "C" {
f32 approach_vector_fixed_distance(const Vec *from, const Vec *to, Vec *out, f32 step);
s32 TAdSinglePlyChrSelectGC__sub_80141E8C(f32 v);
f32 TAdSinglePlyChrSelectGC__sub_80141EA0(s32 v);
s16 angle_diff_s16(s32 a, s32 b);
s32 angle_difference_abs(s32 a, s32 b);
u16 approach_angle_adaptive(s32 a0, s32 b0);
s32 approach_angle_limited(s32 angle, s32 target, s32 max_step);
}
void direction_to_rotation_xy(u8 *arg0, s32 *arg1, s32 *arg2);
void direction_to_rotation_xz(u8 *arg0, s32 *arg1, s32 *arg2);
void direction_to_rotation_yx(u8 *arg0, s32 *arg1, s32 *arg2);
extern "C" {
void fn_80141EB4(void);
}
void set_additive_blend();
void set_default_alpha_blend();
void setSpriteInverseColorBlend(void);
f32 vec_distance_squared(u8 *arg0, u8 *arg1);
void vsub(void *arg0, void *arg1, void *arg2);

#endif
