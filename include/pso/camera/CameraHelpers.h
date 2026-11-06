#ifndef PSO_CAMERA_CAMERAHELPERS_H
#define PSO_CAMERA_CAMERAHELPERS_H

#include "types.h"
#include <dolphin/mtx.h>

struct CameraAngles {
    s32 pitch, yaw, roll;
};

struct CameraPlayback {
    u8 bank;
    u8 index;
    u16 flags;
    f32 frame;
    f32 frame_step;
};

void step_camera_scalar(const f32* current, const f32* target, f32* output, f32 step);
extern "C" {
BOOL approach_camera_vector(Vec* current, Vec* target, f32 rate);
void set_scripted_camera_pose(const Vec* position, const Vec* target, const CameraAngles* angles);
}
void configure_scripted_camera_playback(u8* playback_data, s32 unused);
extern "C" {
CameraPlayback* get_scripted_camera_playback();
}

#include <stddef.h>
typedef char CameraPlaybackSize[(sizeof(CameraPlayback) == 0xC) ? 1 : -1];
typedef char CameraPlaybackFlagsOffset[(offsetof(CameraPlayback, flags) == 2) ? 1 : -1];
typedef char CameraPlaybackFrameOffset[(offsetof(CameraPlayback, frame) == 4) ? 1 : -1];
typedef char CameraPlaybackStepOffset[(offsetof(CameraPlayback, frame_step) == 8) ? 1 : -1];
#endif
