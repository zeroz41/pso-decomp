#ifndef PSO_MISC_TCAMERACTRL_803D6538_H
#define PSO_MISC_TCAMERACTRL_803D6538_H

#include "types.h"
#include "pso/animation/MotionContext.h"
struct NJS_ARGB;
struct _GXColor;

extern "C" {
void TCameraCtrl__sub_803D65F8(u8 *_w0);
s32 TObjPlayer__sub_803D6C1C(s32 arg0);
s32 TObjPlayer__sub_803D7FD0(void);
s32 TObjPlayer__sub_803D7FD8(void);
// Float colour (alpha first, 0..255 scale) to a GX byte colour and back,
// through the paired-single quantizers (hand-written assembly).
void convert_color_f32_to_u8(const NJS_ARGB *src, struct _GXColor *dst);
void convert_color_u8_to_f32(const struct _GXColor *src, NJS_ARGB *dst);
}
void advance_motion_row(void);
void bind_motion_channel_samplers(int arg0, f32 farg0);
s32 blend_motion_poses(void *node, void *arg1, void *unused, void *arg3, void *rot);
extern "C" {
void compose_motion_node_matrix(void *arg0);
}
void find_motion_key_interval(void *keys, s32 stride, s32 count, f32 t, void *k0, void *k1, void *frac);
void find_motion_key_interval_u16(u8 *keys, u32 stride, u32 count, f32 t, u16 * *k0, u16 * *k1, f32 *frac);
u32 find_motion_key_partition_u16(u8 *base, u32 stride, u32 hi, u32 key);
u32 find_motion_key_partition_u32(u8 *base, u32 stride, u32 hi, u32 key);
void interpolate_motion_quaternion_keys(u32 keys, u32 count, s32 output, f32 frame);
void interpolate_motion_vector_keys(u8 *keys, s32 count, u8 *arg2, f32 farg0);
void interpolate_motion_vector_keys_xy(u8 *keys, s32 count, u8 *arg2, f32 farg0);
void sample_camera_motion(u8 *arg0, s32 arg1, u8 *arg2, f32 farg0);
void sample_motion_angle_keys(u8 *keys, s32 count, u8 *arg2, f32 farg0);
void sample_motion_angle_keys_s16(u8 *keys, s32 count, u8 *arg2, f32 farg0);
s32 sample_motion_node_transform(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4);
s32 sample_motion_vector_channel(s32 arg0);
void select_motion_context(s32 arg0);
void select_motion_sampler(s32 *arg0, f32 farg0);
void set_camera_look_at(u8 *eye, u8 *target, u8 *up);
void set_motion_row_stride(s32 n);
extern "C" {
void set_perspective_projection_from_fov(s32 arg0, f32 farg0, f32 farg1, f32 farg2);
}
void set_screen_size(f32 farg0, f32 farg1);

#endif
