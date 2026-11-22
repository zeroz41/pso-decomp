#ifndef PSO_CAMERA_CAMERAVIEW_H
#define PSO_CAMERA_CAMERAVIEW_H

#include "types.h"
#include <dolphin/mtx.h>

// TCameraCtrl's view and globals as the camera controllers read them. TCameraCtrl.cpp
// defines camera_ctrl_instance, TCameraCtrl__view_state and lbl_804FF5E8 untyped, so
// it does not include this header.
struct CameraView {
    u8 pad_0[0xD4];
    Vec split_pos[4];
    Vec split_tgt[4];
    u8 pad_134[0x178 - 0x134];
    Vec pos;
    Vec tgt;
    s32 pitch;
    s32 yaw;
    u8 pad_198[0x19C - 0x198];
    s32 fov;
    Vec eye;
    Vec at;
    f32 eye_rate;
    f32 at_rate;
};

struct CameraViewState {
    u8 controller;  // inferred: camera_controller_registry index of the first view
    u8 pad_1[7];
    u32 flags;
};

extern Vec lbl_804FF5E8;
extern CameraViewState TCameraCtrl__view_state;
extern CameraView *camera_ctrl_instance;

#endif
