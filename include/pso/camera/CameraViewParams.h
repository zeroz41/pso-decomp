#ifndef PSO_CAMERA_CAMERA_VIEW_PARAMS_H
#define PSO_CAMERA_CAMERA_VIEW_PARAMS_H

#include "types.h"
#include "pso/render/Draw2D.h"
#include "pso/render/GinjaView.h"
#include <stddef.h>

// The screen a view projects onto and the size of its viewport in pixels.
struct ViewScreen {
    ScreenProjection projection;
    f32 viewport_width;
    f32 viewport_height;
};

// A projection and viewport a screen can put over the camera's own: apply()
// copies it into the current view parameters, and while an override is begun
// the scene re-applies its own parameters through apply_if_overridden().
struct CameraViewParams {
    ViewScreen screen;
    TileRect scissor;  // the view's scissor box
    f32 pad_40[2];

    s32 begin_override();
    void apply_if_overridden();
    void apply();
    void copy_view_state(const CameraViewParams *src);
    // Never called; the game keeps only its constants.
    void set_fullscreen_defaults();
};
LAYOUT_ASSERT(CameraViewParams_size, sizeof(CameraViewParams) == 0x48);
LAYOUT_ASSERT(CameraViewParams_scissor, offsetof(CameraViewParams, scissor) == 0x30);

// Drops a begun override and puts back the full-screen default parameters.
void end_view_override();

#endif
