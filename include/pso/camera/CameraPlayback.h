#ifndef PSO_CAMERA_CAMERAPLAYBACK_H
#define PSO_CAMERA_CAMERAPLAYBACK_H

#include "types.h"
#include <stddef.h>

// A motion of a loaded camera bank for the scripted camera to play.
struct CameraPlayback {
    enum Flag {
        // The motion has played to its end (or another camera mode took over).
        FLAG_DONE = 1
    };

    // Starts the scripted camera on this motion at fov, keeping the
    // camera's current fov in scripted_camera_saved_fov.
    void play(s32 fov) const;

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
