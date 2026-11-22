#include "pso/animation/MotionContext.h"
#include "types.h"
#include "pso/system/NinjaTypes.h"

extern "C" void blend_quaternions_nlerp(const f32 *a, const f32 *b, f32 rate, f32 *out);

#pragma push
#pragma use_lmw_stmw off
// Samples a camera motion at frame: position, target vector (stored relative
// to the position), roll and angle, each from base when the motion has no keys
// for it.
void sample_camera_motion(const CameraMotionPose *base, NJS_MOTION *motion, const CameraMotionTargets *out, f32 frame) {
    u32 type;
    s32 *roll;
    s32 *angle;
    Vec *pos;
    Vec *vector;
    pos = out->pos;
    vector = out->vector;
    roll = out->roll;
    angle = out->angle;
    select_motion_context(0);
    select_motion_sampler(motion, frame);
    type = current_motion_context->type;
    if (type & NJD_MTYPE_POS_0) {
        if (sample_motion_vector_channel(pos) == 0) {
            pos->x = base->pos.x;
            pos->y = base->pos.y;
            pos->z = base->pos.z;
        }
    } else {
        pos->x = base->pos.x;
        pos->y = base->pos.y;
        pos->z = base->pos.z;
    }
    if (type & NJD_MTYPE_ANG_1) {
        current_motion_context->channel++;
    }
    if (type & NJD_MTYPE_SCL_2) {
        current_motion_context->channel++;
    }
    if (type & NJD_MTYPE_TARGET_3) {
        if (sample_motion_vector_channel(vector) != 0) {
            vector->x = vector->x - pos->x;
            vector->y = vector->y - pos->y;
            vector->z = vector->z - pos->z;
        } else {
            vector->x = base->vector.x;
            vector->y = base->vector.y;
            vector->z = base->vector.z;
        }
    } else if (type & NJD_MTYPE_VEC_3) {
        if (sample_motion_vector_channel(vector) == 0) {
            vector->x = base->vector.x;
            vector->y = base->vector.y;
            vector->z = base->vector.z;
        }
    } else {
        vector->x = base->vector.x;
        vector->y = base->vector.y;
        vector->z = base->vector.z;
    }
    if (type & NJD_MTYPE_VERT_4) {
        current_motion_context->channel++;
    }
    if (type & NJD_MTYPE_NORM_5) {
        current_motion_context->channel++;
    }
    if ((type & NJD_MTYPE_ROLL_6) && sample_motion_value_channel(roll) == 0) {
        *roll = base->roll;
    }
    if (type & NJD_MTYPE_ANGLE_7) {
        if (sample_motion_value_channel(angle) == 0) {
            *angle = base->angle;
        }
    } else {
        *angle = base->angle;
    }
}
#pragma pop

s32 sample_motion_vector_channel(void *out) {
    if (current_motion_context->keys[current_motion_context->channel] != NULL) {
        current_motion_context->sample_vector_keys(current_motion_context->keys[current_motion_context->channel],
                                                   current_motion_context->key_counts[current_motion_context->channel],
                                                   current_motion_context->frame, out);
        current_motion_context->channel = current_motion_context->channel + 1;
        return 1;
    }
    current_motion_context->channel = current_motion_context->channel + 1;
    return 0;
}

s32 sample_motion_value_channel(void *out) {
    if (current_motion_context->keys[current_motion_context->channel] != NULL) {
        current_motion_context->sample_value_keys(current_motion_context->keys[current_motion_context->channel],
                                                  current_motion_context->key_counts[current_motion_context->channel],
                                                  current_motion_context->frame, out);
        current_motion_context->channel = current_motion_context->channel + 1;
        return 1;
    }
    current_motion_context->channel = current_motion_context->channel + 1;
    return 0;
}

s32 sample_motion_angle_channel(void *out) {
    if (current_motion_context->keys[current_motion_context->channel] != NULL) {
        current_motion_context->sample_angle_keys(current_motion_context->keys[current_motion_context->channel],
                                                  current_motion_context->key_counts[current_motion_context->channel],
                                                  current_motion_context->frame, out);
        current_motion_context->channel = current_motion_context->channel + 1;
        return 1;
    }
    current_motion_context->channel = current_motion_context->channel + 1;
    return 0;
}

s32 sample_motion_quaternion_channel(void *out) {
    if (current_motion_context->keys[current_motion_context->channel] != NULL) {
        interpolate_motion_quaternion_keys(current_motion_context->keys[current_motion_context->channel],
                                           current_motion_context->key_counts[current_motion_context->channel],
                                           current_motion_context->frame, out);
        current_motion_context->channel = current_motion_context->channel + 1;
        return 1;
    }
    current_motion_context->channel = current_motion_context->channel + 1;
    return 0;
}

void interpolate_motion_quaternion_keys(const void *keys, u32 count, f32 frame, void *out) {
    f32 rate;
    const NJS_MKEY_QUAT *key0;
    const NJS_MKEY_QUAT *key1;
    find_motion_key_interval(keys, sizeof(NJS_MKEY_QUAT), count, frame, &key0, &key1, &rate);
    blend_quaternions_nlerp(key0->key, key1->key, rate, (f32 *)out);
}

#pragma push
#pragma scheduling off
void interpolate_motion_vector_keys(const void *keys, u32 count, f32 frame, void *out) {
    f32 rate;
    const NJS_MKEY_F *key0;
    const NJS_MKEY_F *key1;
    f32 *vector = (f32 *)out;
    f32 start;
    find_motion_key_interval(keys, sizeof(NJS_MKEY_F), count, frame, &key0, &key1, &rate);
    start = key0->key[0];
    vector[0] = start + rate * (key1->key[0] - start);
    start = key0->key[1];
    vector[1] = start + rate * (key1->key[1] - start);
    start = key0->key[2];
    vector[2] = start + rate * (key1->key[2] - start);
}

void interpolate_motion_vector_keys_xy(const void *keys, u32 count, f32 frame, void *out) {
    f32 rate;
    const NJS_MKEY_F *key0;
    const NJS_MKEY_F *key1;
    f32 *vector = (f32 *)out;
    f32 start;
    find_motion_key_interval(keys, sizeof(NJS_MKEY_F), count, frame, &key0, &key1, &rate);
    start = key0->key[0];
    vector[0] = start + rate * (key1->key[0] - start);
    start = key0->key[1];
    vector[1] = start + rate * (key1->key[1] - start);
    vector[2] = 0.0f;
}

// Samples single angle keys (roll, angle); the step between two keys is taken
// the short way round, as a signed 16-bit angle.
void interpolate_motion_key(const void *keys, u32 count, f32 frame, void *out) {
    f32 rate;
    const NJS_MKEY_A1 *key0;
    const NJS_MKEY_A1 *key1;
    s32 start;
    find_motion_key_interval(keys, sizeof(NJS_MKEY_A1), count, frame, &key0, &key1, &rate);
    start = key0->key;
    *(s32 *)out = start + rate * (s16)(key1->key - start);
}

void sample_motion_angle_keys(const void *keys, u32 count, f32 frame, void *out) {
    f32 rate;
    const NJS_MKEY_A *key0;
    const NJS_MKEY_A *key1;
    s32 *ang = (s32 *)out;
    s32 start;
    find_motion_key_interval(keys, sizeof(NJS_MKEY_A), count, frame, &key0, &key1, &rate);
    start = key0->key[0];
    ang[0] = start + rate * (s16)(key1->key[0] - start);
    start = key0->key[1];
    ang[1] = start + rate * (s16)(key1->key[1] - start);
    start = key0->key[2];
    ang[2] = start + rate * (s16)(key1->key[2] - start);
}

void sample_motion_angle_keys_s16(const void *keys, u32 count, f32 frame, void *out) {
    f32 rate;
    const NJS_MKEY_SA *key0;
    const NJS_MKEY_SA *key1;
    s32 *ang = (s32 *)out;
    s32 start;
    find_motion_key_interval_u16(keys, sizeof(NJS_MKEY_SA), count, frame, &key0, &key1, &rate);
    start = key0->key[0];
    ang[0] = start + rate * (s16)(key1->key[0] - start);
    start = key0->key[1];
    ang[1] = start + rate * (s16)(key1->key[1] - start);
    start = key0->key[2];
    ang[2] = start + rate * (s16)(key1->key[2] - start);
}
#pragma pop

// Catmull-Rom spline through the keys, closed: the first key follows the last.
void interpolate_spline_cyclic_cubic(const void *keys, u32 count, f32 frame, void *out) {
    f32 tbl[2] = { 1.0f, 1.0f };
    const NJS_MKEY_F *key = (const NJS_MKEY_F *)keys;
    f32 *vector = (f32 *)out;
    u32 delta;
    u32 cf;
    u32 index;
    const NJS_MKEY_F *previous;
    const NJS_MKEY_F *current;
    const NJS_MKEY_F *next;
    const NJS_MKEY_F *after;
    f32 t, square, cube, a, b, c, d;
    index = find_motion_key_partition_u32(keys, sizeof(NJS_MKEY_F), count, (u32)frame);
    previous = key + (index + count - 1) % count;
    current = key + index;
    next = key + (index + 1) % count;
    after = key + (index + 2) % count;
    cf = current->keyframe;
    delta = next->keyframe - cf;
    tbl[1] = (f32)delta;
    t = (frame - (f32)cf) / tbl[(s32)delta > 0];
    square = t * t;
    cube = square * t;
    a = 0.5f * ((-cube + 2.0f * square) - t);
    b = 1.0f + (1.5f * cube - 2.5f * square);
    c = 0.5f * t + (-1.5f * cube + 2.0f * square);
    d = 0.5f * (cube - square);
    vector[0] = d * after->key[0] + (c * next->key[0] + (a * previous->key[0] + b * current->key[0]));
    vector[1] = d * after->key[1] + (c * next->key[1] + (a * previous->key[1] + b * current->key[1]));
    vector[2] = d * after->key[2] + (c * next->key[2] + (a * previous->key[2] + b * current->key[2]));
}
