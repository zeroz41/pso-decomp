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

LAYOUT_ASSERT(CameraPlaybackSize, sizeof(CameraPlayback) == 0xC);
LAYOUT_ASSERT(CameraPlaybackFlagsOffset, offsetof(CameraPlayback, flags) == 2);
LAYOUT_ASSERT(CameraPlaybackFrameOffset, offsetof(CameraPlayback, frame) == 4);
LAYOUT_ASSERT(CameraPlaybackStepOffset, offsetof(CameraPlayback, frame_step) == 8);

#endif
