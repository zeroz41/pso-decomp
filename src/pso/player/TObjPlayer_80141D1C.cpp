#include "types.h"
#include "pso/system/date.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/system/ModelDrawContext.h"

#define RAD_TO_ANGLE (32768.0 / 3.141592f)

struct DS_80142108 { u16 y; u8 b2; u8 b3; u8 b4; u8 b5; u8 b6; u8 b7; };

extern "C" {
f32 atan2_float(f32 y, f32 x);
f32 newton_sqrtf(f32);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
u16 approach_angle_adaptive(s32 a0, s32 b0);
f32 TAdSinglePlyChrSelectGC__sub_80141EA0(s32 v);
s32 TAdSinglePlyChrSelectGC__sub_80141E8C(f32 v);
u16 angle_difference_abs(s32 a, s32 b);
s16 angle_diff_s16(s32 a, s32 b);
u16 approach_angle_limited(s32 arg0, s32 arg1, s32 arg2);
void fn_80141EB4(void);
f32 vec_squared_length(u8 *arg0);
void normalize_vector(void *);

extern f32 lbl_805DB158;

s32 TObjPlayer::check_camera_distance() {
    s32 arg0 = (s32)this;
    if (vec_squared_length((u8 *)arg0) < lbl_805DB158) {
        return 0;
    }
    normalize_vector((void *)arg0);
    return 1;
}

extern const f32 lbl_805DB150;

void TObjPlayer::calc_direction_vector(s32 arg0, void *arg1, f32 farg0) {

    *(f32 *)((s8 *)arg1 + 0) = (farg0 * sin_table_lookup(arg0));
    *(f32 *)((s8 *)arg1 + 4) = (f32) lbl_805DB150;
    *(f32 *)((s8 *)arg1 + 8) = (f32) (farg0 * cos_table_lookup(arg0));
}

#pragma push
#pragma fp_contract on
void TObjPlayer::calc_circle_offset_pos(s32 arg0, void *arg1, void *arg2, f32 farg0) {
    *(f32 *)((s8 *)arg2 + 0) = (f32) ((farg0 * sin_table_lookup(arg0)) + *(f32 *)((s8 *)arg1 + 0));
    *(f32 *)((s8 *)arg2 + 4) = (f32) *(f32 *)((s8 *)arg1 + 4);
    *(f32 *)((s8 *)arg2 + 8) = (f32) ((farg0 * cos_table_lookup(arg0)) + *(f32 *)((s8 *)arg1 + 8));
}
#pragma pop

s32 TObjPlayer::calc_angle_to(void *arg1) {

    return (s32) (RAD_TO_ANGLE * atan2_float((*(f32 *)((s8 *)arg1 + 0)) - *(f32 *)((s8 *)this + 0), *(f32 *)((s8 *)arg1 + 8) - *(f32 *)((s8 *)this + 8)));
}

s32 TAdSinglePlyChrSelectGC__sub_80141E8C(f32 v) {
    return *(s32 *)&v;
}

f32 TAdSinglePlyChrSelectGC__sub_80141EA0(s32 v) {
    return *(f32 *)&v;
}

void fn_80141EB4(void) { set_color_blending_mode(0, 5); set_color_blending_mode(1, 6); }
}
void direction_to_rotation_yx(u8 *arg0, s32 *arg1, s32 *arg2);
void direction_to_rotation_xz(u8 *arg0, s32 *arg1, s32 *arg2);
void direction_to_rotation_xy(u8 *arg0, s32 *arg1, s32 *arg2);
f32 vec_distance_squared(u8 *arg0, u8 *arg1);
void setSpriteInverseColorBlend(void);
void vsub(void *arg0, void *arg1, void *arg2);
void setSpriteInverseColorBlend(void) { set_color_blending_mode(0, 5); set_color_blending_mode(1, 7); }

// Ninja's default blending: source alpha over inverse source alpha.
void set_default_alpha_blend() { set_color_blending_mode(0, 8); set_color_blending_mode(1, 6); }

// Source alpha added onto the destination.
void set_additive_blend() { set_color_blending_mode(0, 8); set_color_blending_mode(1, 10); }

extern "C" {

u16 angle_difference_abs(s32 a, s32 b) {
    s16 d = (u16)b - (u16)a;
    if (d < 0) {
        d = -d;
    }
    return d;
}

s16 angle_diff_s16(s32 a, s32 b) {
    return (u16)b - (u16)a;
}

struct V3_80141FBC { f32 x, y, z; };
f32 vector_length(V3_80141FBC *);

f32 approach_vector_fixed_distance(const V3_80141FBC *from, const V3_80141FBC *to, V3_80141FBC *out, f32 step) {
    V3_80141FBC d;
    d.x = to->x - from->x;
    d.y = to->y - from->y;
    d.z = to->z - from->z;
    f32 len = vector_length(&d);
    if (len <= step || lbl_805DB150 == len) {
        out->x = to->x;
        out->y = to->y;
        out->z = to->z;
        return lbl_805DB150;
    }
    normalize_vector(&d);
    d.x *= step;
    d.y *= step;
    d.z *= step;
    d.x += from->x;
    d.y += from->y;
    d.z += from->z;
    out->x = d.x;
    out->y = d.y;
    out->z = d.z;
    return len;
}

s32 TObjPlayer::clamp_s32(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_r3;

    var_r3 = arg0;
    if (var_r3 < arg1) {
        var_r3 = arg1;
    }
    if (var_r3 > arg2) {
        return arg2;
    }
    return var_r3;
}

void TAdSinglePlyChrSelectGC::get_current_date_stamp() {
    DS_80142108 *arg0 = (DS_80142108 *)this;
    DS_80142108 d;
    getDateStamp((DateStamp *)&d);
    arg0->y = d.y;
    arg0->b2 = d.b2;
    arg0->b3 = d.b3;
    arg0->b4 = d.b4;
    arg0->b5 = d.b5;
    arg0->b6 = d.b6;
    arg0->b7 = d.b7;
}
}

#pragma push
#pragma scheduling on
void direction_to_rotation_yx(u8 *arg0, s32 *arg1, s32 *arg2) {
    f32 temp_f0;
    f32 temp_f1;
    *arg1 = -(s32) (RAD_TO_ANGLE * atan2_float((f32) (*(f32 *)((s8 *)arg0 + 8)), (f32) (*(f32 *)((s8 *)arg0 + 0))));
    temp_f1 = *(f32 *)((s8 *)arg0 + 8);
    temp_f0 = *(f32 *)((s8 *)arg0 + 0);
    *arg2 = (s32) (RAD_TO_ANGLE * atan2_float((f32) (*(f32 *)((s8 *)arg0 + 4)), (f32) (newton_sqrtf((f32) ((temp_f1 * temp_f1) + (temp_f0 * temp_f0))))));
}
#pragma pop

#pragma push
#pragma scheduling on
void direction_to_rotation_xz(u8 *arg0, s32 *arg1, s32 *arg2) {
    f32 temp_f0;
    f32 temp_f1;
    *arg2 = -(s32) (RAD_TO_ANGLE * atan2_float((f32) (*(f32 *)((s8 *)arg0 + 0)), (f32) (*(f32 *)((s8 *)arg0 + 4))));
    temp_f1 = *(f32 *)((s8 *)arg0 + 0);
    temp_f0 = *(f32 *)((s8 *)arg0 + 4);
    *arg1 = (s32) (RAD_TO_ANGLE * atan2_float((f32) (*(f32 *)((s8 *)arg0 + 8)), (f32) (newton_sqrtf((f32) ((temp_f1 * temp_f1) + (temp_f0 * temp_f0))))));
}
#pragma pop

#pragma push
#pragma scheduling on
void direction_to_rotation_xy(u8 *arg0, s32 *arg1, s32 *arg2) {
    f32 temp_f0;
    f32 temp_f1;
    *arg1 = -(s32) (RAD_TO_ANGLE * atan2_float((f32) (*(f32 *)((s8 *)arg0 + 4)), (f32) (*(f32 *)((s8 *)arg0 + 8))));
    temp_f1 = *(f32 *)((s8 *)arg0 + 4);
    temp_f0 = *(f32 *)((s8 *)arg0 + 8);
    *arg2 = (s32) (RAD_TO_ANGLE * atan2_float((f32) (*(f32 *)((s8 *)arg0 + 0)), (f32) (newton_sqrtf((f32) ((temp_f1 * temp_f1) + (temp_f0 * temp_f0))))));
}
#pragma pop

u16 approach_angle_adaptive(s32 a0, s32 b0) {
    u16 a = a0;
    u16 b = b0;
    s16 d = b - a;
    s32 r;
    if (d > -0x3000 && d < 0x3000) {
        r = (d >> 1) - (d >> 2);
    } else {
        r = d >> 1;
    }
    return a + r;
}

u16 TObjPlayer::lerp_angle_half(u16 arg0, u16 arg1) {
    return (u16) (arg0 + ((s16) ((u16) arg1 - arg0) >> 1));
}

u16 approach_angle_limited(s32 arg0, s32 arg1, s32 arg2) {
    s16 d = (u16)arg1 - (u16)arg0;
    s16 out;
    if (d > arg2 || d < -arg2) {
        if (d & 0x8000) {
            out = (u16)arg0 - arg2;
        } else {
            out = (u16)arg0 + arg2;
        }
        return out;
    }
    return arg1;
}

void vsub(void *arg0, void *arg1, void *arg2) {
    *(f32 *)((s8 *)arg2 + 0) = (f32) (*(f32 *)((s8 *)arg1 + 0) - *(f32 *)((s8 *)arg0 + 0));
    *(f32 *)((s8 *)arg2 + 4) = (f32) (*(f32 *)((s8 *)arg1 + 4) - *(f32 *)((s8 *)arg0 + 4));
    *(f32 *)((s8 *)arg2 + 8) = (f32) (*(f32 *)((s8 *)arg1 + 8) - *(f32 *)((s8 *)arg0 + 8));
}

extern f32 lbl_805DB15C;
extern f32 lbl_805DB160;

#pragma fp_contract on
f32 vec_distance_squared(u8 *arg0, u8 *arg1) {
  f32 *new_var;
  f32 temp_f3;
  f32 temp_f1;
  f32 temp_f4;
  new_var = (f32 *) (((s8 *) arg0) + 4);
  ;
  temp_f3 = (*((f32 *) (((s8 *) arg1) + 0))) - (*((f32 *) (((s8 *) arg0) + 0)));
  temp_f1 = (*((f32 *) (((s8 *) arg1) + 8))) - (*((f32 *) (((s8 *) arg0) + 8)));
  return (temp_f1 * temp_f1) + ((temp_f3 * temp_f3) + (((*((f32 *) (((s8 *) arg1) + 4))) - (*new_var)) * ((*((f32 *) (((s8 *) arg1) + 4))) - (*new_var))));
}

s32 TObjPlayer::is_in_range(f32 farg0) {
    if ((lbl_805DB160 < farg0) && (farg0 < lbl_805DB15C)) {
        return 1;
    }
    return 0;
}
