#include "pso/animation/MotionContext.h"
#include "types.h"
#include "pso/system/NinjaTypes.h"
#include "pso/camera/TCameraCtrl_803D6538.h"

#include <stddef.h>
#include "pso/camera/TCameraCtrl.h"
#include "pso/player/TObjPlayer.h"
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

extern u8 *current_motion_context;
extern "C" {
void blend_quaternions_nlerp(void *a, void *b, void *out, f32 t);
f32 motion_blend_factor;
extern RecoveredGlobal_803D77C0_lbl_8047E3C8 lbl_8047E3C8;
extern RecoveredGlobal_803D77C0_lbl_804FA500 motion_sampler_function_table;
extern RecoveredGlobal_803D77C0_lbl_804FA50C motion_angle_sampler_table;
extern RecoveredGlobal_803D77C0_lbl_804FA51C motion_key_sampler_table;
extern s32 motion_packed_rotation_mode;
RecoveredGlobal_803D78A8_lbl_8058CAB8 camera_motion_context_table;
// Only pointed to by model_draw_context (.sdata 0x805D4698).
u8 lbl_8058CB38[0x10];
void rotate_matrix_by_node_angles(void *, int);
void scale_current_matrix(void *);
void post_translate_matrix(void *);
}
void euler_zyx_to_quaternion(u8 *arg0, u8 *arg1);
void euler_yxz_to_quaternion(u8 *arg0, u8 *arg1);

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
    u = 1.0f - t;
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

asm void convert_color_f32_to_u8(const NJS_ARGB *src, struct _GXColor *dst) {
#include "orig_asm/pso/camera/TCameraCtrl_803D749C/convert_color_f32_to_u8.inc"
}

asm void convert_color_u8_to_f32(const struct _GXColor *src, NJS_ARGB *dst) {
#include "orig_asm/pso/camera/TCameraCtrl_803D749C/convert_color_u8_to_f32.inc"
}
