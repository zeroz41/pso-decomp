#include "pso/animation/MotionContext.h"
#include "types.h"
#include "pso/system/NinjaTypes.h"
#include "pso/camera/TCameraCtrl_803D6538.h"

#include <stddef.h>
#include "pso/camera/TCameraCtrl.h"
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

struct St_803D6BA4 { u8 pad0[0xC]; u32 *keys; u32 *vals; f32 t; u8 pad18[4]; s32 idx; u8 pad20[4]; void (*fn24)(u32, u32, s32, f32); void (*fn28)(u32, u32, s32, f32); void (*fn2c)(u32, u32, s32, f32); };

struct St_803D6C1C { u8 pad0[0xC]; u32 *keys; u32 *vals; f32 t; u8 pad18[4]; s32 idx; u8 pad20[4]; void (*fn24)(u32, u32, s32, f32); void (*fn28)(u32, u32, s32, f32); void (*fn2c)(u32, u32, s32, f32); };

struct St_803D6C94 { u8 pad0[0xC]; u32 *keys; u32 *vals; f32 t; u8 pad18[4]; s32 idx; u8 pad20[4]; void (*fn24)(u32, u32, s32, f32); void (*fn28)(u32, u32, s32, f32); void (*fn2c)(u32, u32, s32, f32); };

struct St_803D6D0C { u8 pad0[0xC]; u32 *keys; u32 *vals; f32 t; u8 pad18[4]; s32 idx; };

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

struct MotionQuaternionKey {
  u32 frame;
  f32 rotation[4];
};

struct SplineKey_803D7288 { u32 frame; f32 value[3]; };

extern u8 *current_motion_context;
extern "C" {
void blend_quaternions_nlerp(void *a, void *b, void *out, f32 t);
void interpolate_spline_cyclic_cubic(struct SplineKey_803D7288 *keys, u32 count, f32 frame, f32 *output);
}

#define G_803D6BA4 ((St_803D6BA4 *)current_motion_context)

#pragma push
#pragma use_lmw_stmw off

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
    *(f32 *)((s8 *)arg2 + 8) = 0.0f;
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
