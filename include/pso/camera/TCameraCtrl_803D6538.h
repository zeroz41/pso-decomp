#ifndef PSO_CAMERA_TCAMERACTRL_803D6538_H
#define PSO_CAMERA_TCAMERACTRL_803D6538_H

#include "types.h"
#include "pso/animation/MotionContext.h"

extern "C" {
void TCameraCtrl__sub_803D65F8(u8 *_w0);
}
void set_camera_look_at(u8 *eye, u8 *target, u8 *up);
void set_perspective_projection_from_fov(s32 arg0, f32 farg0, f32 farg1, f32 farg2);
void set_screen_size(f32 farg0, f32 farg1);

#endif
