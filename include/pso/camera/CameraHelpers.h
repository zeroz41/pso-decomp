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
// Moves current toward target by 0.16 * rate of the distance between them, or
// by 12 units once that step reaches 5. Within a step it copies current into
// target and returns TRUE.
BOOL approach_camera_vector(Vec *current, Vec *target, f32 rate);
// Places the scripted camera: motions of banks without flag 4 play relative to
// position and angles->yaw. target is kept in target_origin, which nothing reads.
void set_scripted_camera_origin(const Vec *position, const Vec *target, const CameraAngles *angles);
// Copies playback into the scripted camera and picks its motion from the
// current floor area's banks; fov is not used.
void configure_scripted_camera_playback(CameraPlayback *playback, s32 fov);
// The scripted camera's playback, or NULL; marked done while another camera
// mode is active.
CameraPlayback *get_scripted_camera_playback();

#endif
