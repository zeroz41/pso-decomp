#ifndef PSO_CAMERA_CAMERA_VIEW_PARAMS_H
#define PSO_CAMERA_CAMERA_VIEW_PARAMS_H

#include "types.h"
#include <stddef.h>

// A projection and viewport a screen can put over the camera's own: apply()
// copies it into the current view parameters, and while an override is begun
// the scene re-applies its own parameters through apply_if_overridden().
struct CameraViewParams {
    f32 pad_0[2];
    f32 center_x;
    f32 center_y;
    f32 pad_10[6];
    f32 width;
    f32 height;
    f32 pad_30[6];

    s32 begin_override();
    void apply_if_overridden();
    void apply();
    // Dead-stripped in the DOL (only its literals remain); see TCameraCtrl.cpp.
    void set_fullscreen_defaults();
};
typedef char CameraViewParams_size[sizeof(CameraViewParams) == 0x48 ? 1 : -1];
typedef char CameraViewParams_center[offsetof(CameraViewParams, center_x) == 0x8 ? 1 : -1];
typedef char CameraViewParams_viewport[offsetof(CameraViewParams, width) == 0x28 ? 1 : -1];

// Drops a begun override and puts back the full-screen default parameters.
void end_view_override();

#endif
