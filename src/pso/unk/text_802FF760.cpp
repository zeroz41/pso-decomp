#include "types.h"
#include "pso/unk/text_802FF760.h"
#include "pso/system/vector.h"
#include "pso/camera/TCameraCtrl.h"

// TAdMultiConfirmGC's code follows these two functions in the same translation unit; its name
// string comes first in the unit's .rodata.
const char *TAdMultiConfirmGC__name = "TAdMultiConfirmGC";

// defer_codegen emits these in reverse source order: fn_802FF760 comes first in .text, while
// the camera pose initializers keep source order in .rodata (fn_802FF7EC's come first).
#pragma defer_codegen on

extern "C" {
void fn_802FF7EC(void) {
    CameraParams cam;
    Vec b = {0.0f, 0.0f, 0.0f};
    Vec a = {0.0f, 0.0f, -100.0f};
    VecCopy(&cam.position, &b);
    VecCopy(&cam.target, &a);
    cam.fov = 0x1999;
    activate_camera_mode(9);
    set_active_camera_pose_from_params(&cam);
}
void fn_802FF760(void) {
    CameraParams cam;
    Vec b = {0.0f, 0.0f, 0.0f};
    Vec a = {0.0f, 0.0f, -100.0f};
    VecCopy(&cam.position, &b);
    VecCopy(&cam.target, &a);
    cam.fov = 0x36C1;
    activate_camera_mode(9);
    set_active_camera_pose_from_params(&cam);
}

}

#pragma defer_codegen off
