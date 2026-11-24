#ifndef PSO_ANIMATION_MOTIONCONTEXT_H
#define PSO_ANIMATION_MOTIONCONTEXT_H

#include "types.h"
#include <dolphin/mtx/GeoTypes.h>

struct NJS_MOTION;
struct NJS_MOTION_LINK;
struct NJS_OBJECT;
struct NJS_ARGB;
struct _GXColor;

// Interpolates `count` keys of one channel at `frame` into `out`; the key and
// output types are the channel's (vector, angle or single value keys).
typedef void (*MotionKeySampler)(const void *keys, u32 count, f32 frame, void *out);
// Samples the next channel of the current node's row into `out`: nonzero when
// the row has keys for it, 0 when `out` keeps the node's own value.
typedef s32 (*MotionChannelSampler)(void *out);

// The state a motion is sampled with: the current node's row of
// NJS_MOTION::mdata (key pointers followed by key counts, one per channel),
// the frame and the samplers bound for the motion's type and interpolation.
struct MotionContext {
    u8 *row;
    s32 key_list_size;  // bytes of the row's key pointers
    s32 row_size;       // bytes of a whole row
    void **keys;
    u32 *key_counts;
    f32 frame;
    u32 frame_count;  // NJS_MOTION::nbFrame
    s32 channel;      // the row's next channel
    u32 type;         // NJS_MOTION::type (NJD_MTYPE_*)
    MotionKeySampler sample_vector_keys;
    MotionKeySampler sample_angle_keys;
    MotionKeySampler sample_value_keys;
    MotionChannelSampler sample_position;
    MotionChannelSampler sample_rotation;  // NULL when the motion rotates by quaternion
    MotionChannelSampler sample_scale;
    MotionChannelSampler sample_quaternion;
};

LAYOUT_ASSERT(MotionContext_size, sizeof(MotionContext) == 0x40);

extern MotionContext *current_motion_context;

// Key samplers by NJS_MOTION::inp_fn interpolation (linear, spline, linear in x
// and y), angle key samplers (the last for packed 16-bit keys) and single value
// key samplers.
extern MotionKeySampler motion_sampler_function_table[3];
extern MotionKeySampler motion_angle_sampler_table[4];
extern MotionKeySampler motion_key_sampler_table[3];

// The camera sample_camera_motion falls back to for channels its motion has
// no keys for.
struct CameraMotionPose {
    Vec pos;
    Vec vector;
    s32 roll;
    s32 angle;
};

// Where sample_camera_motion writes each camera channel.
struct CameraMotionTargets {
    Vec *pos;
    Vec *vector;
    s32 *roll;
    s32 *angle;
};

// MotionSampling.cpp
void sample_camera_motion(const CameraMotionPose *base, NJS_MOTION *motion, const CameraMotionTargets *out, f32 frame);
s32 sample_motion_vector_channel(void *out);
s32 sample_motion_value_channel(void *out);
s32 sample_motion_angle_channel(void *out);
s32 sample_motion_quaternion_channel(void *out);
void interpolate_motion_quaternion_keys(const void *keys, u32 count, f32 frame, void *out);
void interpolate_motion_vector_keys(const void *keys, u32 count, f32 frame, void *out);
void interpolate_motion_vector_keys_xy(const void *keys, u32 count, f32 frame, void *out);
void interpolate_motion_key(const void *keys, u32 count, f32 frame, void *out);
void sample_motion_angle_keys(const void *keys, u32 count, f32 frame, void *out);
void sample_motion_angle_keys_s16(const void *keys, u32 count, f32 frame, void *out);
void interpolate_spline_cyclic_cubic(const void *keys, u32 count, f32 frame, void *out);

// MotionContext.cpp
void bind_motion_blend_channels(NJS_MOTION_LINK *motion, f32 blend_factor);
s32 blend_motion_poses(NJS_OBJECT *node, f32 *pos, s32 *ang, f32 *scl, f32 *quat);
void apply_motion_node_transform(NJS_OBJECT *node);
void set_motion_row_stride(s32 channels);
void advance_motion_row();
void select_motion_sampler(const NJS_MOTION *motion, f32 frame);
void select_motion_context(s32 index);
// Index of the last of `count` keys `stride` bytes apart whose frame (a u32 or
// u16 first member) is at or before `frame`.
u32 find_motion_key_partition_u32(const void *keys, u32 stride, u32 count, u32 frame);
u32 find_motion_key_partition_u16(const void *keys, u32 stride, u32 count, u32 frame);
// Stores the keys before and after `frame` (the last key wraps to the first)
// in *key0 and *key1, and how far `frame` is between them in *rate.
void find_motion_key_interval_u16(const void *keys, u32 stride, u32 count, f32 frame, void *key0, void *key1, f32 *rate);
void find_motion_key_interval(const void *keys, u32 stride, u32 count, f32 frame, void *key0, void *key1, f32 *rate);
void bind_motion_context(NJS_MOTION *motion, f32 frame);
void bind_motion_channel_samplers(const NJS_MOTION *motion, f32 frame);
void compose_motion_node_matrix(void *node);
s32 sample_motion_node_transform(NJS_OBJECT *node, f32 *pos, s32 *ang, f32 *scl, f32 *quat);
s32 sample_absent_vector_channel(void *out);
s32 sample_absent_angle_channel(void *out);
extern "C" {
// Float colour (alpha first, 0..255 scale) to a GX byte colour and back,
// through the paired-single quantizers (hand-written assembly).
void convert_color_f32_to_u8(const NJS_ARGB *src, struct _GXColor *dst);
void convert_color_u8_to_f32(const struct _GXColor *src, NJS_ARGB *dst);
}

#endif
