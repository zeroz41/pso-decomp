#include "types.h"
#include "pso/unk/text_802FF760.h"
#include "pso/system/vector.h"
struct Vec_802FF760 { f32 x, y, z; };

struct Cam_802FF760 { u8 pad[0x14]; s32 v; u8 pad2[4]; Vec_802FF760 c; Vec_802FF760 d; u8 pad3[0x10]; };

struct Vec_802FF7EC { f32 x, y, z; };

struct Cam_802FF7EC { u8 pad[0x14]; s32 v; u8 pad2[4]; Vec_802FF7EC c; Vec_802FF7EC d; u8 pad3[0x10]; };

// TAdMultiConfirmGC's code follows these two functions in the same translation unit; its name
// string comes first in the unit's .rodata.
const char *TAdMultiConfirmGC__name = "TAdMultiConfirmGC";

// defer_codegen emits these in reverse source order: fn_802FF760 comes first in .text, while
// the camera pose initializers keep source order in .rodata (fn_802FF7EC's come first).
#pragma defer_codegen on

extern "C" {
void set_active_camera_pose_from_params(u8 *arg0);
s32 activate_camera_mode(s32 arg0);
void fn_802FF7EC(void) {
    Cam_802FF7EC cam;
    Vec_802FF7EC b = {0.0f, 0.0f, 0.0f};
    Vec_802FF7EC a = {0.0f, 0.0f, -100.0f};
    VecCopy((Vec *)((Vec_802FF760 *)(&cam.c)), (const Vec *)((Vec_802FF760 *)(&b)));
    VecCopy((Vec *)((Vec_802FF760 *)(&cam.d)), (const Vec *)((Vec_802FF760 *)(&a)));
    cam.v = 0x1999;
    activate_camera_mode(9);
    set_active_camera_pose_from_params((u8 *)&cam);
}
void fn_802FF760(void) {
    Cam_802FF760 cam;
    Vec_802FF760 b = {0.0f, 0.0f, 0.0f};
    Vec_802FF760 a = {0.0f, 0.0f, -100.0f};
    VecCopy((Vec *)&cam.c, (const Vec *)&b);
    VecCopy((Vec *)&cam.d, (const Vec *)&a);
    cam.v = 0x36C1;
    activate_camera_mode(9);
    set_active_camera_pose_from_params((u8 *)&cam);
}

}

#pragma defer_codegen off
