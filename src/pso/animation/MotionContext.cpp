#include "pso/animation/MotionContext.h"
#include "types.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/system/ModelDrawCallback.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_803E4954.h"

extern "C" void blend_quaternions_nlerp(const f32 *a, const f32 *b, f32 rate, f32 *out);

// How far bind_motion_blend_channels' second motion weighs in.
f32 motion_blend_factor;
// The motion select_motion_sampler samples when given none: no frames, no keys.
const NJS_MOTION empty_motion = { 0 };
MotionContext motion_contexts[2];
// The context model_draw_context points to.
ModelDrawContext default_model_draw_context;
// Const for its users, but placed in .sdata (not .sdata2) in the DOL.
__declspec(section ".sdata") ModelDrawContext *const model_draw_context = &default_model_draw_context;

#pragma push
#pragma scheduling off
// Binds motion->motion[0] to context 0 and motion->motion[1] to context 1, to
// be blended by blend_factor.
void bind_motion_blend_channels(NJS_MOTION_LINK *motion, f32 blend_factor) {
    select_motion_context(1);
    bind_motion_channel_samplers(motion->motion[1], motion->frame[1]);
    select_motion_context(0);
    bind_motion_channel_samplers(motion->motion[0], motion->frame[0]);
    motion_blend_factor = blend_factor;
}
#pragma pop

#pragma push
#pragma use_lmw_stmw off
// Samples node in both contexts and blends the two poses; the rotation always
// comes out as a quaternion.
s32 blend_motion_poses(NJS_OBJECT *node, f32 *pos, s32 *ang, f32 *scl, f32 *quat) {
    f32 pos_b[3];
    f32 scl_b[3];
    s32 ang_b[3];
    f32 quat_b[4];
    f32 pos_a[3];
    f32 scl_a[3];
    s32 ang_a[3];
    f32 quat_a[4];
    f32 u;
    f32 t;
    s32 kind_a;
    s32 kind_b;

    t = motion_blend_factor;
    u = 1.0f - t;
    select_motion_context(1);
    kind_a = sample_motion_node_transform(node, pos_a, ang_a, scl_a, quat_a);
    select_motion_context(0);
    kind_b = sample_motion_node_transform(node, pos_b, ang_b, scl_b, quat_b);
    if (kind_b != 2) {
        if (kind_b == 0) {
            euler_zyx_to_quaternion((u8 *)ang_b, (u8 *)quat_b);
        } else {
            euler_yxz_to_quaternion((u8 *)ang_b, (u8 *)quat_b);
        }
    }
    if (kind_a != 2) {
        if (kind_a == 0) {
            euler_zyx_to_quaternion((u8 *)ang_a, (u8 *)quat_a);
        } else {
            euler_yxz_to_quaternion((u8 *)ang_a, (u8 *)quat_a);
        }
    }
    pos[0] = pos_b[0] * u + pos_a[0] * t;
    pos[1] = pos_b[1] * u + pos_a[1] * t;
    pos[2] = pos_b[2] * u + pos_a[2] * t;
    scl[0] = scl_b[0] * u + scl_a[0] * t;
    scl[1] = scl_b[1] * u + scl_a[1] * t;
    scl[2] = scl_b[2] * u + scl_a[2] * t;
    blend_quaternions_nlerp(quat_b, quat_a, t, quat);
    return 2;
}
#pragma pop

#pragma push
#pragma opt_common_subs off
#pragma scheduling off
#pragma peephole off
// Applies node's blended pose (bind_motion_blend_channels) to the current
// matrix.
void apply_motion_node_transform(NJS_OBJECT *node) {
    f32 pos[3];
    f32 scl[3];
    s32 ang[3];
    f32 quat[4];
    s32 kind;
    kind = blend_motion_poses(node, pos, ang, scl, quat);
    post_translate_matrix(pos);
    switch (kind) {
    case 0:
        rotate_matrix_by_node_angles(ang, 0);
        break;
    case 1:
        rotate_matrix_by_node_angles(ang, 1);
        break;
    default:
        ((TObjPlayer *)quat)->concat_quaternion_rotation();
        break;
    }
    scale_current_matrix(scl);
}

// Starts the first row of the current motion; each row holds `channels` key
// pointers and then `channels` key counts.
void set_motion_row_stride(s32 channels) {
    s32 size = channels * 4;
    u8 *row;
    current_motion_context->key_list_size = size;
    current_motion_context->row_size = size + size;
    row = current_motion_context->row;
    current_motion_context->keys = (void **)row;
    current_motion_context->key_counts = (u32 *)(row + current_motion_context->key_list_size);
    current_motion_context->channel = 0;
}

// Moves to the next node's row.
void advance_motion_row() {
    u8 *row = current_motion_context->row;
    row += current_motion_context->row_size;
    current_motion_context->row = row;
    current_motion_context->keys = (void **)row;
    current_motion_context->key_counts = (u32 *)(row + current_motion_context->key_list_size);
    current_motion_context->channel = 0;
}

// Points the current context at motion's first row at frame and picks the key
// samplers for its interpolation.
void select_motion_sampler(const NJS_MOTION *motion, f32 frame) {
    s32 interpolation;
    if (motion == NULL) {
        motion = &empty_motion;
    }
    interpolation = (motion->inp_fn & 0xC0) >> 6;
    current_motion_context->row = (u8 *)motion->mdata;
    current_motion_context->frame_count = motion->nbFrame;
    current_motion_context->type = motion->type;
    current_motion_context->frame = frame;
    current_motion_context->channel = 0;
    set_motion_row_stride(motion->inp_fn & ~0xC0);
    current_motion_context->sample_vector_keys = motion_sampler_function_table[interpolation];
    if (motion_packed_rotation_mode != 0) {
        current_motion_context->sample_angle_keys = motion_angle_sampler_table[3];
    } else {
        current_motion_context->sample_angle_keys = motion_angle_sampler_table[interpolation];
    }
    current_motion_context->sample_value_keys = motion_key_sampler_table[0];
}
#pragma pop

#pragma push
#pragma scheduling off
void select_motion_context(s32 index) {
    current_motion_context = &motion_contexts[index];
}
#pragma pop

u32 find_motion_key_partition_u32(const void *keys, u32 stride, u32 count, u32 frame) {
    u32 lo = 0;
    while (count - lo > 1) {
        u32 mid = (lo + count) >> 1;
        if (frame >= *(const u32 *)((const u8 *)keys + mid * stride)) {
            lo = mid;
        } else {
            count = mid;
        }
    }
    return lo;
}

u32 find_motion_key_partition_u16(const void *keys, u32 stride, u32 count, u32 frame) {
    u32 lo = 0;
    while (count - lo > 1) {
        u32 mid = (lo + count) >> 1;
        if (frame >= *(const u16 *)((const u8 *)keys + mid * stride)) {
            lo = mid;
        } else {
            count = mid;
        }
    }
    return lo;
}

#pragma push
#pragma optimize_for_size on
#pragma use_lmw_stmw off
void find_motion_key_interval_u16(const void *keys, u32 stride, u32 count, f32 frame, void *key0, void *key1, f32 *rate) {
    u32 i;
    const u16 *a;
    const u16 *b;
    s32 d;
    i = find_motion_key_partition_u16(keys, stride, count, (u32)frame);
    a = (const u16 *)((const u8 *)keys + i * stride);
    if (i < count - 1) {
        b = (const u16 *)((const u8 *)keys + (i + 1) * stride);
    } else {
        b = (const u16 *)keys;
    }
    *(const u16 **)key0 = a;
    *(const u16 **)key1 = b;
    d = *b - *a;
    if (d > 0) {
        *rate = (frame - *a) / d;
    } else {
        *rate = frame - *a;
    }
}

void find_motion_key_interval(const void *keys, u32 stride, u32 count, f32 frame, void *key0, void *key1, f32 *rate) {
    u32 i;
    const u32 *a;
    const u32 *b;
    s32 d;

    i = find_motion_key_partition_u32(keys, stride, count, (u32)frame);
    a = (const u32 *)((const u8 *)keys + i * stride);
    if (i < count - 1) {
        b = (const u32 *)((const u8 *)keys + (i + 1) * stride);
    } else {
        b = (const u32 *)keys;
    }
    *(const u32 **)key0 = a;
    *(const u32 **)key1 = b;
    d = *b - *a;
    if (d > 0) {
        *rate = (frame - *a) / d;
    } else {
        *rate = frame - *a;
    }
}
#pragma pop

#pragma push
#pragma scheduling off
void bind_motion_context(NJS_MOTION *motion, f32 frame) {
    select_motion_context(0);
    bind_motion_channel_samplers(motion, frame);
}
#pragma pop

// Selects the motion and the channel samplers its type has keys for.
void bind_motion_channel_samplers(const NJS_MOTION *motion, f32 frame) {
    u32 type;
    select_motion_sampler(motion, frame);
    type = current_motion_context->type;
    if (type & NJD_MTYPE_POS_0) {
        current_motion_context->sample_position = sample_motion_vector_channel;
    } else {
        current_motion_context->sample_position = sample_absent_vector_channel;
    }
    if (type & NJD_MTYPE_ANG_1) {
        current_motion_context->sample_rotation = sample_motion_angle_channel;
        current_motion_context->sample_quaternion = NULL;
    } else if (type & NJD_MTYPE_QUAT_1) {
        current_motion_context->sample_rotation = NULL;
        current_motion_context->sample_quaternion = sample_motion_quaternion_channel;
    } else {
        current_motion_context->sample_rotation = sample_absent_angle_channel;
        current_motion_context->sample_quaternion = NULL;
    }
    if (type & NJD_MTYPE_SCL_2) {
        current_motion_context->sample_scale = sample_motion_vector_channel;
    } else {
        current_motion_context->sample_scale = sample_absent_vector_channel;
    }
}

// Applies node's pose in the current motion (bind_motion_context) to the
// current matrix.
void compose_motion_node_matrix(void *node) {
    f32 pos[3];
    f32 scl[3];
    s32 ang[3];
    f32 quat[4];
    s32 kind;
    kind = sample_motion_node_transform((NJS_OBJECT *)node, pos, ang, scl, quat);
    post_translate_matrix(pos);
    switch (kind) {
    case 0:
        rotate_matrix_by_node_angles(ang, 0);
        break;
    case 1:
        rotate_matrix_by_node_angles(ang, 1);
        break;
    default:
        ((TObjPlayer *)quat)->concat_quaternion_rotation();
        break;
    }
    scale_current_matrix(scl);
}

#pragma push
#pragma optimize_for_size off
#pragma optimization_level 3
#pragma peephole off
#pragma scheduling off
#pragma use_lmw_stmw off
// Samples node's pose from the current row (or takes the node's own for
// channels without keys, and for NJD_EVAL_SKIP nodes, which take no row) and
// returns how its rotation came out: 0 angles in X, Y, Z order, 1 angles in
// Z, X, Y order, 2 a quaternion (w, x, y, z).
s32 sample_motion_node_transform(NJS_OBJECT *node, f32 *pos, s32 *ang, f32 *scl, f32 *quat) {
    s32 kind;
    if (!(node->evalflags & NJD_EVAL_SKIP)) {
        if (current_motion_context->sample_position(pos) == 0) {
            pos[0] = node->pos[0];
            pos[1] = node->pos[1];
            pos[2] = node->pos[2];
        }
        if (current_motion_context->sample_rotation != NULL) {
            if (current_motion_context->sample_rotation(ang) != 0) {
                kind = (node->evalflags & NJD_EVAL_ZXY_ANG) ? 1 : 0;
            } else if (node->evalflags & NJD_EVAL_QUATERNION) {
                quat[0] = node->quat_w;
                quat[1] = ((f32 *)node->ang)[0];
                quat[2] = ((f32 *)node->ang)[1];
                quat[3] = ((f32 *)node->ang)[2];
                kind = 2;
            } else {
                ang[0] = node->ang[0];
                ang[1] = node->ang[1];
                ang[2] = node->ang[2];
                kind = (node->evalflags & NJD_EVAL_ZXY_ANG) ? 1 : 0;
            }
        } else if (current_motion_context->sample_quaternion(quat) != 0) {
            kind = 2;
        } else if (node->evalflags & NJD_EVAL_QUATERNION) {
            quat[0] = node->quat_w;
            quat[1] = ((f32 *)node->ang)[0];
            quat[2] = ((f32 *)node->ang)[1];
            quat[3] = ((f32 *)node->ang)[2];
            kind = 2;
        } else {
            ang[0] = node->ang[0];
            ang[1] = node->ang[1];
            ang[2] = node->ang[2];
            kind = (node->evalflags & NJD_EVAL_ZXY_ANG) ? 1 : 0;
        }
        if (current_motion_context->sample_scale(scl) == 0) {
            scl[0] = node->scl[0];
            scl[1] = node->scl[1];
            scl[2] = node->scl[2];
        }
        advance_motion_row();
    } else {
        pos[0] = node->pos[0];
        pos[1] = node->pos[1];
        pos[2] = node->pos[2];
        scl[0] = node->scl[0];
        scl[1] = node->scl[1];
        scl[2] = node->scl[2];
        if (node->evalflags & NJD_EVAL_QUATERNION) {
            quat[0] = node->quat_w;
            quat[1] = ((f32 *)node->ang)[0];
            quat[2] = ((f32 *)node->ang)[1];
            quat[3] = ((f32 *)node->ang)[2];
            kind = 2;
        } else {
            ang[0] = node->ang[0];
            ang[1] = node->ang[1];
            ang[2] = node->ang[2];
            kind = (node->evalflags & NJD_EVAL_ZXY_ANG) ? 1 : 0;
        }
    }
    return kind;
}
#pragma pop

// The position and scale sampler of motions without those channels.
s32 sample_absent_vector_channel(void *out) {
    return 0;
}

// The rotation sampler of motions without angle or quaternion keys.
s32 sample_absent_angle_channel(void *out) {
    return 0;
}

asm void convert_color_f32_to_u8(const NJS_ARGB *src, struct _GXColor *dst) {
#include "orig_asm/pso/animation/MotionContext/convert_color_f32_to_u8.inc"
}

asm void convert_color_u8_to_f32(const struct _GXColor *src, NJS_ARGB *dst) {
#include "orig_asm/pso/animation/MotionContext/convert_color_u8_to_f32.inc"
}

MotionKeySampler motion_sampler_function_table[3] = {
    interpolate_motion_vector_keys, interpolate_spline_cyclic_cubic, interpolate_motion_vector_keys_xy
};
MotionKeySampler motion_angle_sampler_table[4] = {
    sample_motion_angle_keys, sample_motion_angle_keys, sample_motion_angle_keys, sample_motion_angle_keys_s16
};
MotionKeySampler motion_key_sampler_table[3] = { interpolate_motion_key, interpolate_motion_key, interpolate_motion_key };

u32 lbl_804FA528[6] = { 0 };
