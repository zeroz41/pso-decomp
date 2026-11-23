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

// Takes view's distance and centre into screen_projection, rebuilding its
// scales, and makes the clip bounds relative to the new centre.
void update_projection_params(const ScreenProjection *view);

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

extern Vec camera_look_at_up_vector;

// Would fill the eye look_at_position views from; empty, so the eye is left
// as it is.
void get_look_at_eye(Vec *eye);
void set_camera_look_at(const Vec *eye, const Vec *target, const Vec *up);
// Moves the view to x, y, z (translate_view_negated).
void update_camera_state(f32 x, f32 y, f32 z);
// Points the view from the current eye at x, y, z.
void look_at_position(f32 x, f32 y, f32 z);
// Translates the current matrix by -x, -y, -z.
void translate_view_negated(f32 x, f32 y, f32 z);
// Sets the near and far clip planes (negative view-space z), each clamped to
// [-65535, -1].
void set_clip_planes(f32 near_z, f32 far_z);
// Resets camera to the origin, looking down -z with a 60-degree view angle
// and clip planes at -1 and -60000 (the Ninja SDK's njInitCamera).
void init_ninja_camera(struct NJS_CAMERA *camera);
void set_screen_size(f32 width, f32 height);
// fov is a horizontal angle (0x10000 a turn) at aspect; GX gets the vertical one.
void set_perspective_projection_from_fov(s32 fov, f32 aspect, f32 near_z, f32 far_z);

#endif
