#ifndef PSO_CAMERA_TCAMERACTRL_803D676C_H
#define PSO_CAMERA_TCAMERACTRL_803D676C_H

#include "types.h"

extern const f32 fov_angle_scale;
extern const f64 angle_to_degrees;
extern const f64 radians_to_angle;
extern const f32 screen_half_scale;
extern const f32 projection_unit;
extern const f32 screen_aspect_ratio;

// --- C functions defined in TCameraCtrl_803D676C.cpp ---
void set_perspective_projection_from_fov(s32 arg0, f32 farg0, f32 farg1, f32 farg2);
// --- end of C functions

#endif
