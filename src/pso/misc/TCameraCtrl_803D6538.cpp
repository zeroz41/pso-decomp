#include "pso/animation/MotionContext.h"
#include "types.h"
#include "pso/system/NinjaTypes.h"
#include "pso/misc/TCameraCtrl_803D6538.h"

#include <stddef.h>
#include "pso/misc/TCameraCtrl.h"
#include "pso/player/TObjPlayer.h"
struct Stack_803D6DDC {
    u8 * sp8;
    u8 * spC;
    f32 sp10;
};

struct Stack_803D6E8C {
    u8 * sp8;
    u8 * spC;
    f32 sp10;
};

struct RecoveredGlobal_803D662C_lbl_8058D4D0 {
    s32 value;
    u8 remaining[0x24];
};

struct RecoveredGlobal_803D77C0_lbl_8047E3C8 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_803D77C0_lbl_804FA500 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_803D77C0_lbl_804FA50C {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_803D77C0_lbl_804FA51C {
    s32 value;
    u8 remaining[0x20];
};

struct RecoveredGlobal_803D78A8_lbl_8058CAB8 {
    s32 value;
    u8 remaining[0x7C];
};

struct St_803D7784 { s32 a0, a4, a8, ac, b0, b4, b8, x1c; };

struct Vec_803D7504 { f32 x, y, z; };
struct Quat_803D7504 { f32 x, y, z, w; };

struct Vec_803D7CA4 { f32 x, y, z; };

struct Angles_803D7CA4 { s32 x, y, z; };

struct Quat_803D7CA4 { f32 x, y, z, w; };

struct V_803D6558 { f32 x, y, z; };

struct G_803D6688 { f32 f0, f4, pad8[2], f10, f14, f18, f1c, f20, f24; };

struct St_803D6BA4 { u8 pad0[0xC]; u32 *keys; u32 *vals; f32 t; u8 pad18[4]; s32 idx; u8 pad20[4]; void (*fn24)(u32, u32, s32, f32); void (*fn28)(u32, u32, s32, f32); void (*fn2c)(u32, u32, s32, f32); };

struct St_803D6C1C { u8 pad0[0xC]; u32 *keys; u32 *vals; f32 t; u8 pad18[4]; s32 idx; u8 pad20[4]; void (*fn24)(u32, u32, s32, f32); void (*fn28)(u32, u32, s32, f32); void (*fn2c)(u32, u32, s32, f32); };

struct St_803D6C94 { u8 pad0[0xC]; u32 *keys; u32 *vals; f32 t; u8 pad18[4]; s32 idx; u8 pad20[4]; void (*fn24)(u32, u32, s32, f32); void (*fn28)(u32, u32, s32, f32); void (*fn2c)(u32, u32, s32, f32); };

struct St_803D6D0C { u8 pad0[0xC]; u32 *keys; u32 *vals; f32 t; u8 pad18[4]; s32 idx; };

struct Vec_803D7D30 { f32 x, y, z; };

struct Vec4_803D7D30 { f32 w, x, y, z; };

struct Key_803D7D30 {
    u32 flags;
    u8 pad4[4];
    Vec_803D7D30 pos;
    Vec_803D7D30 rot;
    Vec_803D7D30 scl;
    u8 pad2c[8];
    f32 w;
};

struct Smp_803D7D30 {
    u8 pad[0x30];
    s32 (*f30)(void *);
    s32 (*f34)(void *);
    s32 (*f38)(void *);
    s32 (*f3C)(void *);
};

struct Stack_803D6F20 {
    u8 * sp8;
    u8 * spC;
    f32 sp10;
};

struct Stack_803D6FC8 {
    u8 * sp8;
    u8 * spC;
    f32 sp10;
};

struct Stack_803D7128 {
    u8 * sp8;
    u8 * spC;
    f32 sp10;
};

struct Proj_803D676C { f32 m[4][4]; s32 f40; f32 f44, f48, f4C, f50, f54; };

struct Disp_803D676C { u8 pad[6]; u16 h; };

struct MotionQuaternionKey {
  u32 frame;
  f32 rotation[4];
};

struct SplineKey_803D7288 { u32 frame; f32 value[3]; };

struct Cam_803D66DC { f32 f0, f4, f8, fC, f10, f14, f18, f1C, f20, f24; };

extern u8 *current_motion_context;
extern "C" {
s32 C_MTXPerspective(void *, f32, f32, f32, f32);
s32 GXSetProjection(void *, int);
f64 atan(f32);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
Proj_803D676C scene_projection_state;
extern RecoveredGlobal_803D662C_lbl_8058D4D0 camera_clip_parameters;
extern G_803D6688 lbl_8058D4F8;
extern Disp_803D676C *active_gx_render_mode;
extern const f32 lbl_805E0E18;
extern const f64 lbl_805E0E20;
extern const f64 lbl_805E0E28;
extern const f32 lbl_805E0E30;
extern const f32 lbl_805E0E34;
extern const f32 lbl_805E0E38;
void blend_quaternions_nlerp(void *a, void *b, void *out, f32 t);
void interpolate_spline_cyclic_cubic(struct SplineKey_803D7288 *keys, u32 count, f32 frame, f32 *output);
extern const f32 lbl_805E0E10;
extern const f32 lbl_805E0E50;
void C_MTXLookAt(void *, void *, void *, void *);
extern u8 *current_matrix;
extern f32 motion_blend_factor;
extern const f32 lbl_805E0E00;
extern const f32 lbl_805E0E04;
extern RecoveredGlobal_803D77C0_lbl_8047E3C8 lbl_8047E3C8;
extern RecoveredGlobal_803D77C0_lbl_804FA500 motion_sampler_function_table;
extern RecoveredGlobal_803D77C0_lbl_804FA50C motion_angle_sampler_table;
extern RecoveredGlobal_803D77C0_lbl_804FA51C motion_key_sampler_table;
extern s32 motion_packed_rotation_mode;
RecoveredGlobal_803D78A8_lbl_8058CAB8 camera_motion_context_table;
u8 lbl_8058CB38[0x10];
s32 translate_matrix(s32, f32, f32, f32);
void rotate_matrix_by_node_angles(void *, int);
void scale_current_matrix(void *);
void post_translate_matrix(void *);
void set_matrix_identity(u8 *arg0);
}
extern u8 camera_look_at_up_vector[];
extern const f32 lbl_805E0E08;
void euler_zyx_to_quaternion(u8 *arg0, u8 *arg1);
void euler_yxz_to_quaternion(u8 *arg0, u8 *arg1);
extern const f32 lbl_805E0E88;

void TCameraCtrl::update_camera_state(f32 _w0, f32 _w1, f32 _w2) {
    TCameraCtrl::translate_view_negated(_w0, _w1, _w2);
}

void TCameraCtrl::look_at_position(f32 farg0, f32 farg1, f32 farg2) {
    u8 eye[0x14];
    V_803D6558 v;
    TCameraCtrl__sub_803D65F8(eye);
    v.x = farg0;
    v.y = farg1;
    v.z = farg2;
    set_matrix_identity(0);
    set_camera_look_at(eye, (u8*)((u8 *)&v), camera_look_at_up_vector);
}

#pragma push
#pragma scheduling off
s32 TCameraCtrl::translate_view_negated(f32 x, f32 y, f32 z) {
    return translate_matrix(0, -x, -y, -z);
}
#pragma pop

void TCameraCtrl__sub_803D65F8(u8 * _w0) {

}

#pragma push
#pragma scheduling off
void set_camera_look_at(u8* eye, u8* target, u8* up) {
    C_MTXLookAt(current_matrix, eye, up, target);
}
#pragma pop

#pragma push
#pragma opt_common_subs off
#pragma scheduling off
typedef char RecoveredGlobal_803D662C_lbl_8058D4D0_size[sizeof(RecoveredGlobal_803D662C_lbl_8058D4D0) == 0x28 ? 1 : -1];

void TCameraCtrl::set_clamped_offsets(f32 farg0, f32 farg1) {
    f32 var_f1;
    f32 var_f2;
    var_f1 = farg0;
    var_f2 = farg1;
    if (var_f1 > lbl_805E0E00) {
        var_f1 = lbl_805E0E00;
    }
    if (var_f1 < lbl_805E0E04) {
        var_f1 = lbl_805E0E04;
    }
    if (var_f2 > lbl_805E0E00) {
        var_f2 = lbl_805E0E00;
    }
    if (var_f2 < lbl_805E0E04) {
        var_f2 = lbl_805E0E04;
    }
    *(f32 *)((s8 *)&camera_clip_parameters.value + 4) = (f32) -var_f1;
    *(f32 *)((s8 *)&camera_clip_parameters.value + 0) = (f32) -var_f2;
}
#pragma pop

void set_screen_size(f32 farg0, f32 farg1) {
    f32 a, b;
    lbl_8058D4F8.f1c = farg0;
    lbl_8058D4F8.f20 = farg1;
    lbl_8058D4F8.f24 = farg1 / farg0;
    a = (f32)(f64)farg0 * lbl_8058D4F8.f18;
    lbl_8058D4F8.f0 = a;
    b = -((f32)(f64)farg1 * lbl_8058D4F8.f18);
    lbl_8058D4F8.f4 = b;
    lbl_8058D4F8.f10 = lbl_805E0E08 / a;
    lbl_8058D4F8.f14 = lbl_805E0E08 / (f32)(f64)b;
}

#define G_803D6BA4 ((St_803D6BA4 *)current_motion_context)

#pragma push
#pragma use_lmw_stmw off

#pragma push
#pragma opt_common_subs off

void TCameraCtrl::update_projection_params() {
    Cam_803D66DC *arg0 = (Cam_803D66DC *)this;
    f32 c, b, a;
    (*(Cam_803D66DC *)&lbl_8058D4F8).f18 = a = arg0->f18;
    (*(Cam_803D66DC *)&lbl_8058D4F8).f8 = b = arg0->f8;
    (*(Cam_803D66DC *)&lbl_8058D4F8).fC = c = arg0->fC;
    (*(Cam_803D66DC *)&lbl_8058D4F8).f0 = (*(Cam_803D66DC *)&lbl_8058D4F8).f1C * a;
    (*(Cam_803D66DC *)&lbl_8058D4F8).f4 = -((*(Cam_803D66DC *)&lbl_8058D4F8).f20 * a);
    (*(Cam_803D66DC *)&lbl_8058D4F8).f10 = lbl_805E0E10 / (*(Cam_803D66DC *)&lbl_8058D4F8).f0;
    (*(Cam_803D66DC *)&lbl_8058D4F8).f14 = lbl_805E0E10 / (*(Cam_803D66DC *)&lbl_8058D4F8).f4;
    (*(Cam_803D66DC *)&camera_clip_parameters).f8 = (*(Cam_803D66DC *)&camera_clip_parameters).f20 - b;
    (*(Cam_803D66DC *)&camera_clip_parameters).fC = (*(Cam_803D66DC *)&camera_clip_parameters).f18 - b;
    (*(Cam_803D66DC *)&camera_clip_parameters).f10 = (*(Cam_803D66DC *)&camera_clip_parameters).f24 - c;
    (*(Cam_803D66DC *)&camera_clip_parameters).f14 = (*(Cam_803D66DC *)&camera_clip_parameters).f1C - c;
}
#pragma pop

void set_perspective_projection_from_fov(s32 arg0, f32 farg0, f32 farg1, f32 farg2) {
    s32 h;
    f32 c;
    f32 r;
    f32 x;
    f32 sc;
    f32 b;
    f32 a;
    f32 one;
    h = (s32)((f32)arg0 * lbl_805E0E18) / 2;
    c = cos_table_lookup(h);
    r = atan((sin_table_lookup(h) / c) / farg0);
    C_MTXPerspective(&scene_projection_state, lbl_805E0E20 * ((s32)(lbl_805E0E28 * r) * 2), farg0, farg1, farg2);
    GXSetProjection(&scene_projection_state, 0);
    scene_projection_state.f40 = 0;
    scene_projection_state.f44 = farg1;
    scene_projection_state.f48 = farg2;
    scene_projection_state.f4C = farg0;
    sc = lbl_805E0E30 * ((f32)active_gx_render_mode->h * scene_projection_state.m[1][1]);
    scene_projection_state.f50 = sc;
    one = lbl_805E0E34;
    scene_projection_state.f54 = one / sc;
    lbl_8058D4F8.f18 = sc;
    x = farg0 / lbl_805E0E38;
    lbl_8058D4F8.f1c = x;
    lbl_8058D4F8.f20 = one;
    lbl_8058D4F8.f24 = one / farg0;
    a = x * (f32)(f64)lbl_8058D4F8.f18;
    lbl_8058D4F8.f0 = a;
    b = -(one * (f32)(f64)lbl_8058D4F8.f18);
    lbl_8058D4F8.f4 = b;
    lbl_8058D4F8.f10 = one / a;
    lbl_8058D4F8.f14 = one / (f32)(f64)b;
    *(f32 *)((s8 *)&camera_clip_parameters.value + 0) = farg2;
    *(f32 *)((s8 *)&camera_clip_parameters.value + 4) = farg1;
}

void sample_camera_motion(u8 *arg0, s32 arg1, u8 *arg2, f32 farg0) {
    s32 temp_r31;
    s32 *temp_r30;
    s32 *temp_r29;
    u8 *temp_r27;
    u8 *temp_r26;
    temp_r27 = (u8 *)(*(u8 **)((s8 *)arg2 + 0));
    temp_r26 = (u8 *)(*(u8 **)((s8 *)arg2 + 4));
    temp_r30 = (s32 *)(*(s32 **)((s8 *)arg2 + 8));
    temp_r29 = (s32 *)(*(s32 **)((s8 *)arg2 + 0xC));
    select_motion_context(0);
    select_motion_sampler((s32 *)arg1, (f32)farg0);
    temp_r31 = *(s32 *)((s8 *)current_motion_context + 0x20);
    if ((u32) (temp_r31 & 1) != 0) {
        if (sample_motion_vector_channel((int)temp_r27) == 0) {
            *(f32 *)((s8 *)temp_r27 + 0) = (f32) *(f32 *)((s8 *)arg0 + 0);
            *(f32 *)((s8 *)temp_r27 + 4) = (f32) *(f32 *)((s8 *)arg0 + 4);
            *(f32 *)((s8 *)temp_r27 + 8) = (f32) *(f32 *)((s8 *)arg0 + 8);
        }
    } else {
        *(f32 *)((s8 *)temp_r27 + 0) = (f32) *(f32 *)((s8 *)arg0 + 0);
        *(f32 *)((s8 *)temp_r27 + 4) = (f32) *(f32 *)((s8 *)arg0 + 4);
        *(f32 *)((s8 *)temp_r27 + 8) = (f32) *(f32 *)((s8 *)arg0 + 8);
    }
    if ((u32) (temp_r31 & 2) != 0) {
        *(s32 *)((s8 *)current_motion_context + 0x1C) = (s32) (*(s32 *)((s8 *)current_motion_context + 0x1C) + 1);
    }
    if ((u32) (temp_r31 & 4) != 0) {
        *(s32 *)((s8 *)current_motion_context + 0x1C) = (s32) (*(s32 *)((s8 *)current_motion_context + 0x1C) + 1);
    }
    if ((u32) (temp_r31 & 0x40) != 0) {
        if (sample_motion_vector_channel((int)temp_r26) != 0) {
            *(f32 *)((s8 *)temp_r26 + 0) = (f32) (*(f32 *)((s8 *)temp_r26 + 0) - *(f32 *)((s8 *)temp_r27 + 0));
            *(f32 *)((s8 *)temp_r26 + 4) = (f32) (*(f32 *)((s8 *)temp_r26 + 4) - *(f32 *)((s8 *)temp_r27 + 4));
            *(f32 *)((s8 *)temp_r26 + 8) = (f32) (*(f32 *)((s8 *)temp_r26 + 8) - *(f32 *)((s8 *)temp_r27 + 8));
        } else {
            *(f32 *)((s8 *)temp_r26 + 0) = (f32) *(f32 *)((s8 *)arg0 + 0xC);
            *(f32 *)((s8 *)temp_r26 + 4) = (f32) *(f32 *)((s8 *)arg0 + 0x10);
            *(f32 *)((s8 *)temp_r26 + 8) = (f32) *(f32 *)((s8 *)arg0 + 0x14);
        }
    } else if ((u32) (temp_r31 & 8) != 0) {
        if (sample_motion_vector_channel((int)temp_r26) == 0) {
            *(f32 *)((s8 *)temp_r26 + 0) = (f32) *(f32 *)((s8 *)arg0 + 0xC);
            *(f32 *)((s8 *)temp_r26 + 4) = (f32) *(f32 *)((s8 *)arg0 + 0x10);
            *(f32 *)((s8 *)temp_r26 + 8) = (f32) *(f32 *)((s8 *)arg0 + 0x14);
        }
    } else {
        *(f32 *)((s8 *)temp_r26 + 0) = (f32) *(f32 *)((s8 *)arg0 + 0xC);
        *(f32 *)((s8 *)temp_r26 + 4) = (f32) *(f32 *)((s8 *)arg0 + 0x10);
        *(f32 *)((s8 *)temp_r26 + 8) = (f32) *(f32 *)((s8 *)arg0 + 0x14);
    }
    if ((u32) (temp_r31 & 0x10) != 0) {
        *(s32 *)((s8 *)current_motion_context + 0x1C) = (s32) (*(s32 *)((s8 *)current_motion_context + 0x1C) + 1);
    }
    if ((u32) (temp_r31 & 0x20) != 0) {
        *(s32 *)((s8 *)current_motion_context + 0x1C) = (s32) (*(s32 *)((s8 *)current_motion_context + 0x1C) + 1);
    }
    if (((u32) (temp_r31 & 0x80) != 0) && (TObjPlayer__sub_803D6C1C((int)temp_r30) == 0)) {
        *(s32 *)((s8 *)temp_r30 + 0) = *(s32 *)((s8 *)arg0 + 0x18);
    }
    if ((u32) (temp_r31 & 0x100) != 0) {
        if (TObjPlayer__sub_803D6C1C((int)temp_r29) == 0) {
            *(s32 *)((s8 *)temp_r29 + 0) = *(s32 *)((s8 *)arg0 + 0x1C);
        }
    } else {
        *(s32 *)((s8 *)temp_r29 + 0) = *(s32 *)((s8 *)arg0 + 0x1C);
    }
}
#pragma pop

s32 sample_motion_vector_channel(s32 arg0) {
    if (G_803D6BA4->keys[G_803D6BA4->idx] != 0) {
        G_803D6BA4->fn24(G_803D6BA4->keys[G_803D6BA4->idx], G_803D6BA4->vals[G_803D6BA4->idx], arg0, G_803D6BA4->t);
        G_803D6BA4->idx = G_803D6BA4->idx + 1;
        return 1;
    }
    G_803D6BA4->idx = G_803D6BA4->idx + 1;
    return 0;
}

#define G_803D6C1C ((St_803D6C1C *)current_motion_context)

s32 TObjPlayer__sub_803D6C1C(s32 arg0) {
    if (G_803D6C1C->keys[G_803D6C1C->idx] != 0) {
        G_803D6C1C->fn2c(G_803D6C1C->keys[G_803D6C1C->idx], G_803D6C1C->vals[G_803D6C1C->idx], arg0, G_803D6C1C->t);
        G_803D6C1C->idx = G_803D6C1C->idx + 1;
        return 1;
    }
    G_803D6C1C->idx = G_803D6C1C->idx + 1;
    return 0;
}

#define G_803D6C94 ((St_803D6C94 *)current_motion_context)
s32 TObjPlayer::run_next_key_callback(s32 arg0) {
    if (G_803D6C94->keys[G_803D6C94->idx] != 0) {
        G_803D6C94->fn28(G_803D6C94->keys[G_803D6C94->idx], G_803D6C94->vals[G_803D6C94->idx], arg0, G_803D6C94->t);
        G_803D6C94->idx = G_803D6C94->idx + 1;
        return 1;
    }
    G_803D6C94->idx = G_803D6C94->idx + 1;
    return 0;
}

#define G_803D6D0C ((St_803D6D0C *)current_motion_context)
s32 TObjPlayer::sample_next_quaternion_key(s32 output) {
    if (G_803D6D0C->keys[G_803D6D0C->idx] != 0) {
      interpolate_motion_quaternion_keys(
          G_803D6D0C->keys[G_803D6D0C->idx],
          G_803D6D0C->vals[G_803D6D0C->idx], output, G_803D6D0C->t);
      G_803D6D0C->idx = G_803D6D0C->idx + 1;
      return 1;
    }
    G_803D6D0C->idx = G_803D6D0C->idx + 1;
    return 0;
}

void interpolate_motion_quaternion_keys(u32 keys, u32 count, s32 output,
                                        f32 frame) {
  f32 fraction;
  MotionQuaternionKey *first;
  MotionQuaternionKey *second;
  find_motion_key_interval(
      (void *)((void *)keys), (s32)(sizeof(MotionQuaternionKey)), count,
      frame, &first, &second, &fraction);
  ((void (*)(void *, void *, f32, void *))blend_quaternions_nlerp)(
      first->rotation, second->rotation, fraction, (void *)output);
}

#pragma push
#pragma scheduling off
void interpolate_motion_vector_keys(u8 *keys, s32 count, u8 *arg2, f32 farg0) {
    typedef char sp8_offset[(offsetof(Stack_803D6DDC, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_803D6DDC, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_803D6DDC, sp10) == 0x8) ? 1 : -1];
    Stack_803D6DDC stack;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    find_motion_key_interval(keys, 0x10, count, farg0, &stack.spC, &stack.sp8, &stack.sp10);
    temp_f2 = *(f32 *)((s8 *)stack.spC + 4);
    *(f32 *)((s8 *)arg2 + 0) = (f32) (temp_f2 + (stack.sp10 * (*(f32 *)((s8 *)stack.sp8 + 4) - temp_f2)));
    temp_f2_2 = *(f32 *)((s8 *)stack.spC + 8);
    *(f32 *)((s8 *)arg2 + 4) = (f32) (temp_f2_2 + (stack.sp10 * (*(f32 *)((s8 *)stack.sp8 + 8) - temp_f2_2)));
    temp_f2_3 = *(f32 *)((s8 *)stack.spC + 0xC);
    *(f32 *)((s8 *)arg2 + 8) = (f32) (temp_f2_3 + (stack.sp10 * (*(f32 *)((s8 *)stack.sp8 + 0xC) - temp_f2_3)));
}
#pragma pop

#pragma push
#pragma scheduling off
void interpolate_motion_vector_keys_xy(u8 *keys, s32 count, u8 *arg2, f32 farg0) {
    typedef char sp8_offset[(offsetof(Stack_803D6E8C, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_803D6E8C, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_803D6E8C, sp10) == 0x8) ? 1 : -1];
    Stack_803D6E8C stack;
    f32 temp_f2;
    f32 temp_f2_2;
    find_motion_key_interval(keys, 0x10, count, farg0, &stack.spC, &stack.sp8, &stack.sp10);
    temp_f2 = *(f32 *)((s8 *)stack.spC + 4);
    *(f32 *)((s8 *)arg2 + 0) = (f32) (temp_f2 + (stack.sp10 * (*(f32 *)((s8 *)stack.sp8 + 4) - temp_f2)));
    temp_f2_2 = *(f32 *)((s8 *)stack.spC + 8);
    *(f32 *)((s8 *)arg2 + 4) = (f32) (temp_f2_2 + (stack.sp10 * (*(f32 *)((s8 *)stack.sp8 + 8) - temp_f2_2)));
    *(f32 *)((s8 *)arg2 + 8) = (f32) lbl_805E0E50;
}
#pragma pop

#pragma push
#pragma scheduling off

void TObjPlayer::interpolate_motion_key(s32 count, s32 *arg2, f32 farg0) {
    u8 *arg0 = (u8 *)this;
    typedef char sp8_offset[(offsetof(Stack_803D6F20, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_803D6F20, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_803D6F20, sp10) == 0x8) ? 1 : -1];
    Stack_803D6F20 stack;

    s32 temp_r5;

    find_motion_key_interval(arg0, 8, count, farg0, &stack.spC, &stack.sp8, &stack.sp10);
    temp_r5 = *(s32 *)((s8 *)stack.spC + 4);
    *arg2 = (s32) ((f32) temp_r5 + (stack.sp10 * (f32) (s16) (*(s32 *)((s8 *)stack.sp8 + 4) - temp_r5)));
}
#pragma pop

#pragma push
#pragma scheduling off
void sample_motion_angle_keys(u8 *keys, s32 count, u8 *arg2, f32 farg0) {
    typedef char sp8_offset[(offsetof(Stack_803D6FC8, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_803D6FC8, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_803D6FC8, sp10) == 0x8) ? 1 : -1];
    Stack_803D6FC8 stack;

    s32 temp_r5;
    s32 temp_r5_2;
    s32 temp_r5_3;

    find_motion_key_interval(keys, 0x10, count, farg0, &stack.spC, &stack.sp8, &stack.sp10);
    temp_r5 = *(s32 *)((s8 *)stack.spC + 4);
    *(s32 *)((s8 *)arg2 + 0) = (s32) ((f32) temp_r5 + (stack.sp10 * (f32) (s16) (*(s32 *)((s8 *)stack.sp8 + 4) - temp_r5)));
    temp_r5_2 = *(s32 *)((s8 *)stack.spC + 8);
    *(s32 *)((s8 *)arg2 + 4) = (s32) ((f32) temp_r5_2 + (stack.sp10 * (f32) (s16) (*(s32 *)((s8 *)stack.sp8 + 8) - temp_r5_2)));
    temp_r5_3 = *(s32 *)((s8 *)stack.spC + 0xC);
    *(s32 *)((s8 *)arg2 + 8) = (s32) ((f32) temp_r5_3 + (stack.sp10 * (f32) (s16) (*(s32 *)((s8 *)stack.sp8 + 0xC) - temp_r5_3)));
}
#pragma pop

#pragma push
#pragma scheduling off
void sample_motion_angle_keys_s16(u8 *keys, s32 count, u8 *arg2, f32 farg0) {
    typedef char sp8_offset[(offsetof(Stack_803D7128, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_803D7128, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_803D7128, sp10) == 0x8) ? 1 : -1];
    Stack_803D7128 stack;

    s16 temp_r5;
    s16 temp_r5_2;
    s16 temp_r5_3;

    find_motion_key_interval_u16(keys, 8, count, farg0, (u16 **)&stack.spC, (u16 **)&stack.sp8, &stack.sp10);
    temp_r5 = *(s16 *)((s8 *)stack.spC + 2);
    *(s32 *)((s8 *)arg2 + 0) = (s32) ((f32) temp_r5 + (stack.sp10 * (f32) (s16) (*(s16 *)((s8 *)stack.sp8 + 2) - temp_r5)));
    temp_r5_2 = *(s16 *)((s8 *)stack.spC + 4);
    *(s32 *)((s8 *)arg2 + 4) = (s32) ((f32) temp_r5_2 + (stack.sp10 * (f32) (s16) (*(s16 *)((s8 *)stack.sp8 + 4) - temp_r5_2)));
    temp_r5_3 = *(s16 *)((s8 *)stack.spC + 6);
    *(s32 *)((s8 *)arg2 + 8) = (s32) ((f32) temp_r5_3 + (stack.sp10 * (f32) (s16) (*(s16 *)((s8 *)stack.sp8 + 6) - temp_r5_3)));
}
#pragma pop

void interpolate_spline_cyclic_cubic(struct SplineKey_803D7288 *keys, u32 count, f32 frame, f32 *output) {
    f32 tbl[2] = { 1.0f, 1.0f };
    u32 delta;
    u32 cf;
    u32 index;
    struct SplineKey_803D7288 *previous;
    struct SplineKey_803D7288 *current;
    struct SplineKey_803D7288 *next;
    struct SplineKey_803D7288 *after;
    f32 t, square, cube, twiceSquare, a, b, c, d;
    index = find_motion_key_partition_u32((u8 *)keys, 16, count, (u32)frame);
    previous = keys + (index + count - 1) % count;
    current = keys + index;
    next = keys + (index + 1) % count;
    after = keys + (index + 2) % count;
    cf = current->frame;
    delta = next->frame - cf;
    tbl[1] = (f32)delta;
    t = (frame - (f32)cf) / tbl[(s32)delta > 0];
    square = t * t;
    cube = square * t;
    a = 0.5f * ((-cube + 2.0f * square) - t);
    b = 1.0f + (1.5f * cube - 2.5f * square);
    c = 0.5f * t + (-1.5f * cube + 2.0f * square);
    d = 0.5f * (cube - square);
    output[0] = d * after->value[0] + (c * next->value[0] + (a * previous->value[0] + b * current->value[0]));
    output[1] = d * after->value[1] + (c * next->value[1] + (a * previous->value[1] + b * current->value[1]));
    output[2] = d * after->value[2] + (c * next->value[2] + (a * previous->value[2] + b * current->value[2]));
}

#pragma push
#pragma scheduling off
void bind_motion_blend_channels(NJS_MOTION_LINK *motion, f32 blend_factor) {
    select_motion_context(1);
    bind_motion_channel_samplers((s32)motion->motion[1], motion->frame[1]);
    select_motion_context(0);
    bind_motion_channel_samplers((s32)motion->motion[0], motion->frame[0]);
    motion_blend_factor = blend_factor;
}
#pragma pop

#pragma push
#pragma use_lmw_stmw off
#define pos ((Vec_803D7504 *)arg1)
#define scl ((Vec_803D7504 *)arg3)
s32 blend_motion_poses(void *node, void *arg1, void *unused, void *arg3, void *rot) {
    Vec_803D7504 pb;
    Vec_803D7504 sb;
    Vec_803D7504 rb;
    Quat_803D7504 qb;
    Vec_803D7504 pa;
    Vec_803D7504 sa;
    Vec_803D7504 ra;
    Quat_803D7504 qa;
    f32 u;
    f32 t;
    s32 res_a;
    s32 res_b;

    t = motion_blend_factor;
    u = lbl_805E0E88 - t;
    select_motion_context(1);
    res_a = sample_motion_node_transform(node, &pa, &ra, &sa, &qa);
    select_motion_context(0);
    res_b = sample_motion_node_transform(node, &pb, &rb, &sb, &qb);
    if (res_b != 2) {
        if (res_b == 0) {
            euler_zyx_to_quaternion((u8 *)&rb, (u8 *)&qb);
        } else {
            euler_yxz_to_quaternion((u8 *)&rb, (u8 *)&qb);
        }
    }
    if (res_a != 2) {
        if (res_a == 0) {
            euler_zyx_to_quaternion((u8 *)&ra, (u8 *)&qa);
        } else {
            euler_yxz_to_quaternion((u8 *)&ra, (u8 *)&qa);
        }
    }
    pos->x = pb.x * u + pa.x * t;
    pos->y = pb.y * u + pa.y * t;
    pos->z = pb.z * u + pa.z * t;
    scl->x = sb.x * u + sa.x * t;
    scl->y = sb.y * u + sa.y * t;
    scl->z = sb.z * u + sa.z * t;
    ((void (*)(void *, void *, f32, void *))blend_quaternions_nlerp)(&qb, &qa, t, rot);
    return 2;
}
#pragma pop
#undef pos
#undef scl

#pragma push
#pragma opt_common_subs off
#pragma scheduling off
#pragma peephole off
typedef char RecoveredGlobal_803D77C0_lbl_8047E3C8_size[sizeof(RecoveredGlobal_803D77C0_lbl_8047E3C8) == 0x10 ? 1 : -1];
typedef char RecoveredGlobal_803D77C0_lbl_804FA500_size[sizeof(RecoveredGlobal_803D77C0_lbl_804FA500) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_803D77C0_lbl_804FA50C_size[sizeof(RecoveredGlobal_803D77C0_lbl_804FA50C) == 0x10 ? 1 : -1];
typedef char RecoveredGlobal_803D77C0_lbl_804FA51C_size[sizeof(RecoveredGlobal_803D77C0_lbl_804FA51C) == 0x24 ? 1 : -1];

#pragma push
#pragma scheduling off
#pragma opt_common_subs off
#pragma peephole off

void TObjPlayer::apply_motion_node_transform() {
    struct Vec_803D7CA4 trans;
    struct Vec_803D7CA4 scale;
    struct Angles_803D7CA4 rot;
    struct Quat_803D7CA4 quat;
    s32 kind;
    kind = blend_motion_poses(this, &trans, &rot, &scale, &quat);
    post_translate_matrix(&trans);
    switch (kind) {
    case 0:
        rotate_matrix_by_node_angles(&rot, 0);
        break;
    case 1:
        rotate_matrix_by_node_angles(&rot, 1);
        break;
    default:
        ((TObjPlayer *)(&quat))->concat_quaternion_rotation();
        break;
    }
    scale_current_matrix(&scale);
}
#pragma pop

void set_motion_row_stride(s32 n) {
    s32 w = n * 4;
    s32 a;
    *(s32 *)(current_motion_context + 0x4) = w;
    *(s32 *)(current_motion_context + 0x8) = w + w;
    a = *(s32 *)(current_motion_context + 0x0);
    *(s32 *)(current_motion_context + 0xc) = a;
    *(s32 *)(current_motion_context + 0x10) = a + *(s32 *)(current_motion_context + 0x4);
    *(s32 *)(current_motion_context + 0x1c) = 0;
}

#pragma push
#pragma scheduling off
void advance_motion_row(void) {
    s32 v = ((St_803D7784 *)current_motion_context)->a0;
    v += ((St_803D7784 *)current_motion_context)->a8;
    ((St_803D7784 *)current_motion_context)->a0 = v;
    ((St_803D7784 *)current_motion_context)->ac = v;
    ((St_803D7784 *)current_motion_context)->b0 = v + ((St_803D7784 *)current_motion_context)->a4;
    ((St_803D7784 *)current_motion_context)->x1c = 0;
}
#pragma pop

void select_motion_sampler(s32 *arg0, f32 farg0) {
    s32 *var_r3;
    s32 temp_r31;
    s32 temp_r4;
    var_r3 = arg0;
    if (var_r3 == NULL) {
        var_r3 = (s32 *)&lbl_8047E3C8.value;
    }
    temp_r31 = (s32) (*(u16 *)((s8 *)var_r3 + 0xA) & 0xC0) >> 6;
    *(s32 *)((s8 *)current_motion_context + 0) = (s32) *(s32 *)((s8 *)var_r3 + 0);
    *(s32 *)((s8 *)current_motion_context + 0x18) = (s32) *(s32 *)((s8 *)var_r3 + 4);
    *(s32 *)((s8 *)current_motion_context + 0x20) = (s32) *(u16 *)((s8 *)var_r3 + 8);
    *(f32 *)((s8 *)current_motion_context + 0x14) = farg0;
    *(s32 *)((s8 *)current_motion_context + 0x1C) = 0;
    set_motion_row_stride((s32)((int) (*(u16 *)((s8 *)var_r3 + 0xA) & 0xFFFFFF3F)));
    temp_r4 = temp_r31 * 4;
    *(s32 *)((s8 *)current_motion_context + 0x24) = (s32) *(s32 *)((s8 *)&motion_sampler_function_table.value + temp_r4);
    if ((s32) motion_packed_rotation_mode != 0) {
        *(s32 *)((s8 *)current_motion_context + 0x28) = (s32) *(s32 *)((s8 *)&motion_angle_sampler_table.value + 0xC);
    } else {
        *(s32 *)((s8 *)current_motion_context + 0x28) = (s32) *(s32 *)((s8 *)&motion_angle_sampler_table.value + temp_r4);
    }
    *(s32 *)((s8 *)current_motion_context + 0x2C) = (s32) motion_key_sampler_table.value;
}
#pragma pop

#pragma push
#pragma scheduling off
typedef char RecoveredGlobal_803D78A8_lbl_8058CAB8_size[sizeof(RecoveredGlobal_803D78A8_lbl_8058CAB8) == 0x80 ? 1 : -1];
void select_motion_context(s32 arg0) {
    current_motion_context = (u8 *)&camera_motion_context_table.value + (arg0 << 6);
}
#pragma pop

u32 find_motion_key_partition_u32(u8 *base, u32 stride, u32 hi, u32 key) {
    u32 lo = 0;
    while (hi - lo > 1) {
        u32 mid = (lo + hi) >> 1;
        if (key >= *(u32 *)(base + mid * stride)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    return lo;
}

u32 find_motion_key_partition_u16(u8 *base, u32 stride, u32 hi, u32 key) {
    u32 lo = 0;
    while (hi - lo > 1) {
        u32 mid = (lo + hi) >> 1;
        if (key >= *(u16 *)(base + mid * stride)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    return lo;
}

#pragma push
#pragma optimize_for_size on
#pragma use_lmw_stmw off
void find_motion_key_interval_u16(u8 *keys, u32 stride, u32 count, f32 t, u16 **k0, u16 **k1, f32 *frac) {
    u32 i;
    u16 *a;
    u16 *b;
    s32 d;
    i = find_motion_key_partition_u16(keys, stride, count, (u32) t);
    a = (u16 *) (keys + i * stride);
    if (i < count - 1) {
        b = (u16 *) (keys + (i + 1) * stride);
    } else {
        b = (u16 *) keys;
    }
    *k0 = a;
    *k1 = b;
    d = *b - *a;
    if (d > 0) {
        *frac = (t - *a) / d;
    } else {
        *frac = t - *a;
    }
}
#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma use_lmw_stmw off
void find_motion_key_interval(void *keys, s32 stride, s32 count, f32 t, void *k0, void *k1, void *frac) {
    u32 i;
    u32 *a;
    u32 *b;
    s32 d;

    i = find_motion_key_partition_u32((u8 *) keys, stride, count, (u32) t);
    a = (u32 *) ((u8 *) keys + i * stride);
    if (i < (count - 1)) {
        b = (u32 *) ((u8 *) keys + (i + 1) * stride);
    } else {
        b = (u32 *) keys;
    }
    *(u32 **) k0 = a;
    *(u32 **) k1 = b;
    d = *b - *a;
    if (d > 0) {
        *(f32 *) frac = (t - *a) / d;
    } else {
        *(f32 *) frac = t - *a;
    }
}
#pragma pop

#pragma push
#pragma scheduling off

void bind_motion_context(NJS_MOTION *motion, f32 farg0) {
    select_motion_context(0);
    bind_motion_channel_samplers((s32)motion, farg0);
}
#pragma pop

void bind_motion_channel_samplers(int arg0, f32 farg0) {
    s32 temp_r5;
    select_motion_sampler((s32 *)arg0, farg0);
    temp_r5 = *(s32 *)((s8 *)current_motion_context + 0x20);
    if ((u32) (temp_r5 & 1) != 0) {
        *(void **)((s8 *)current_motion_context + 0x30) = (void *)sample_motion_vector_channel;
    } else {
        *(void **)((s8 *)current_motion_context + 0x30) = (void *)TObjPlayer__sub_803D7FD0;
    }
    if ((u32) (temp_r5 & 2) != 0) {
        *(void **)((s8 *)current_motion_context + 0x34) = (void *)TObjPlayer::run_next_key_callback;
        *(void **)((s8 *)current_motion_context + 0x3C) = NULL;
    } else if ((u32) (temp_r5 & 0x2000) != 0) {
        *(void **)((s8 *)current_motion_context + 0x34) = NULL;
        *(void **)((s8 *)current_motion_context + 0x3C) = (void *)TObjPlayer::sample_next_quaternion_key;
    } else {
        *(void **)((s8 *)current_motion_context + 0x34) = (void *)TObjPlayer__sub_803D7FD8;
        *(void **)((s8 *)current_motion_context + 0x3C) = NULL;
    }
    if ((u32) (temp_r5 & 4) != 0) {
        *(void **)((s8 *)current_motion_context + 0x38) = (void *)sample_motion_vector_channel;
        return;
    }
    *(void **)((s8 *)current_motion_context + 0x38) = (void *)TObjPlayer__sub_803D7FD0;
}

void compose_motion_node_matrix(void *arg0) {
    struct Vec_803D7CA4 trans;
    struct Vec_803D7CA4 scale;
    struct Angles_803D7CA4 rot;
    struct Quat_803D7CA4 quat;
    s32 kind;
    kind = sample_motion_node_transform(arg0, &trans, &rot, &scale, &quat);
    post_translate_matrix(&trans);
    switch (kind) {
    case 0:
        rotate_matrix_by_node_angles(&rot, 0);
        break;
    case 1:
        rotate_matrix_by_node_angles(&rot, 1);
        break;
    default:
        ((TObjPlayer *)(&quat))->concat_quaternion_rotation();
        break;
    }
    scale_current_matrix(&scale);
}

#define G_803D7D30 ((Smp_803D7D30 *)current_motion_context)
#pragma push
#pragma optimize_for_size off
#pragma optimization_level 3
#pragma peephole off
#pragma scheduling off
#pragma use_lmw_stmw off
s32 sample_motion_node_transform(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4) {
#define kK ((Key_803D7D30 *)arg0)
#define pP ((Vec_803D7D30 *)arg1)
#define rR ((Vec_803D7D30 *)arg2)
#define sS ((Vec_803D7D30 *)arg3)
#define qQ ((Vec4_803D7D30 *)arg4)
    s32 r;
    if (!(kK->flags & 0x40)) {
        if (G_803D7D30->f30(pP) == 0) {
            pP->x = kK->pos.x;
            pP->y = kK->pos.y;
            pP->z = kK->pos.z;
        }
        if (G_803D7D30->f34 != NULL) {
            if (G_803D7D30->f34(rR) != 0) {
                r = (kK->flags & 0x20) ? 1 : 0;
            } else if (kK->flags & 0x400) {
                qQ->w = kK->w;
                qQ->x = kK->rot.x;
                qQ->y = kK->rot.y;
                qQ->z = kK->rot.z;
                r = 2;
            } else {
                ((u32 *)rR)[0] = ((u32 *)&kK->rot)[0];
            ((u32 *)rR)[1] = ((u32 *)&kK->rot)[1];
            ((u32 *)rR)[2] = ((u32 *)&kK->rot)[2];
                r = (kK->flags & 0x20) ? 1 : 0;
            }
        } else if (G_803D7D30->f3C(qQ) != 0) {
            r = 2;
        } else if (kK->flags & 0x400) {
            qQ->w = kK->w;
            qQ->x = kK->rot.x;
            qQ->y = kK->rot.y;
            qQ->z = kK->rot.z;
            r = 2;
        } else {
            ((u32 *)rR)[0] = ((u32 *)&kK->rot)[0];
            ((u32 *)rR)[1] = ((u32 *)&kK->rot)[1];
            ((u32 *)rR)[2] = ((u32 *)&kK->rot)[2];
            r = (kK->flags & 0x20) ? 1 : 0;
        }
        if (G_803D7D30->f38(sS) == 0) {
            sS->x = kK->scl.x;
            sS->y = kK->scl.y;
            sS->z = kK->scl.z;
        }
        advance_motion_row();
    } else {
        pP->x = kK->pos.x;
        pP->y = kK->pos.y;
        pP->z = kK->pos.z;
        sS->x = kK->scl.x;
        sS->y = kK->scl.y;
        sS->z = kK->scl.z;
        if (kK->flags & 0x400) {
            qQ->w = kK->w;
            qQ->x = kK->rot.x;
            qQ->y = kK->rot.y;
            qQ->z = kK->rot.z;
            r = 2;
        } else {
            ((u32 *)rR)[0] = ((u32 *)&kK->rot)[0];
            ((u32 *)rR)[1] = ((u32 *)&kK->rot)[1];
            ((u32 *)rR)[2] = ((u32 *)&kK->rot)[2];
            r = (kK->flags & 0x20) ? 1 : 0;
        }
    }
    return r;
#undef kK
#undef pP
#undef rR
#undef sS
#undef qQ
}
#pragma pop

s32 TObjPlayer__sub_803D7FD0(void) {
    return 0;
}

s32 TObjPlayer__sub_803D7FD8(void) {
    return 0;
}
