#ifndef PSO_RENDER_GINJAVIEW_H
#define PSO_RENDER_GINJAVIEW_H

#include "types.h"
#include "pso/animation/MotionContext.h"

// The screen the view projects onto: per-axis scale (distance times the
// screen size, y flipped), the centre and the reciprocals of the scales.
struct ScreenProjection {
    f32 scale_x;
    f32 scale_y;
    f32 center_x;
    f32 center_y;
    f32 inv_scale_x;
    f32 inv_scale_y;
    f32 distance;
    f32 width;
    f32 height;
    f32 aspect;  // height / width
};

LAYOUT_ASSERT(ScreenProjection_size, sizeof(ScreenProjection) == 0x28);

extern ScreenProjection screen_projection;

// [0] far and [1] near clip distance, [2..5] the screen bounds of [6..9]
// relative to the screen centre.
extern f32 camera_clip_parameters[10];

// The perspective GX projects with, and what it was built from.
struct SceneProjectionState {
    f32 matrix[4][4];
    s32 type;  // 0: perspective
    f32 near_z;
    f32 far_z;
    f32 aspect;
    f32 screen_scale;  // half the EFB height times matrix[1][1]
    f32 inv_screen_scale;
};

LAYOUT_ASSERT(SceneProjectionState_size, sizeof(SceneProjectionState) == 0x58);

extern SceneProjectionState scene_projection_state;

// GinjaPerspective.cpp: constants of set_perspective_projection_from_fov.
extern const f32 fov_angle_scale;
extern const f64 angle_to_degrees;
extern const f64 radians_to_angle;
extern const f32 screen_half_scale;
extern const f32 projection_unit;
extern const f32 screen_aspect_ratio;

extern f32 camera_look_at_up_vector[3];

extern "C" {
void TCameraCtrl__sub_803D65F8(u8 *eye);
}
void set_camera_look_at(u8 *eye, u8 *target, u8 *up);
void set_screen_size(f32 width, f32 height);
// fov is a horizontal angle (0x10000 a turn) at aspect; GX gets the vertical one.
void set_perspective_projection_from_fov(s32 fov, f32 aspect, f32 near_z, f32 far_z);

#endif
