#ifndef PSO_CAMERA_CAMERAPLAYBACK_H
#define PSO_CAMERA_CAMERAPLAYBACK_H

#include "types.h"
#include <stddef.h>

struct CameraPlayback {
    void cache_target_and_forward(s32 angle) const;

    u8 bank;
    u8 index;
    u16 flags;
    f32 frame;
    f32 frame_step;
};

typedef char CameraPlaybackSize[(sizeof(CameraPlayback) == 0xC) ? 1 : -1];
typedef char CameraPlaybackFlagsOffset[(offsetof(CameraPlayback, flags) == 2) ? 1 : -1];
typedef char CameraPlaybackFrameOffset[(offsetof(CameraPlayback, frame) == 4) ? 1 : -1];
typedef char CameraPlaybackStepOffset[(offsetof(CameraPlayback, frame_step) == 8) ? 1 : -1];

#endif
