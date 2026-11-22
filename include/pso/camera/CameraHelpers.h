#ifndef PSO_CAMERA_CAMERAHELPERS_H
#define PSO_CAMERA_CAMERAHELPERS_H

#include "types.h"
#include <dolphin/mtx.h>
#include "pso/camera/CameraAngles.h"
#include "pso/camera/CameraPlayback.h"

s32 approach_camera_scalar(f32 *current, f32 *target, f32 rate);
void step_camera_scalar(const f32* current, const f32* target, f32* output, f32 step);
void direction_to_pitch_yaw(Vec *direction, s32 *pitch, s32 *yaw);
// Turns angle toward target by at most rate * 0x7F.
s32 approach_camera_angle(s32 angle, s32 target, s32 rate);
extern "C" {
BOOL approach_camera_vector(Vec* current, Vec* target, f32 rate);
void set_scripted_camera_pose(const Vec* position, const Vec* target, const CameraAngles* angles);
}
void configure_scripted_camera_playback(CameraPlayback *playback, s32 angle);
extern "C" {
CameraPlayback* get_scripted_camera_playback();
}

#endif
