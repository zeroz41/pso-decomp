#include "types.h"
#include "pso/unk/TUnk_80488DA0.h"
#include "pso/camera/TCameraCtrl_80067FC0.h"
#include "pso/camera/TCameraCtrl_8006C8E4.h"
#include "pso/system/vector.h"

#include "pso/unk/TUnk_80488D70.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801A6D60.h"
#include "pso/math/AngleLookup.h"
#include "pso/camera/TCameraCtrl_801A6E60.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
static const Vec default_target_position = {0.0f, 0.0f, 0.0f};

struct Pad_8006C964 { u8 pad0[0x14]; s16 sx; s16 sy; };

struct Ctl_8006C964 { u8 pad0[0xC0]; Pad_8006C964 pad; };

struct Cam_8006C964 {
    u8 pad0[0x2C];
    s32 pitch;
    s32 yaw;
    u8 pad34[8];
    Vec eye;
    Vec center;
    s32 x54;
    u8 pad58[0x6C - 0x58];
    f32 dist;
};

extern "C" {
Vec get_target_position__11TCameraCtrlFv(void);
void debug_printf_at(s32, const char *, ...);
extern Ctl_8006C964 controller_input_state;


void * TCameraCtrl__vt6(void) {
    void *o;
    o = (void *)new TUnk_80488DA0();
    return o;
}

#pragma push
#pragma fp_contract on
void TUnk_80488DA0::run_task() {
    Vec target = {0.0f, 0.0f, 0.0f};
    Vec v;
    Pad_8006C964 *pad = &controller_input_state.pad;
    s16 sx = controller_input_state.pad.sx;
    s16 sy = controller_input_state.pad.sy;
    f32 r;
    if (test_previous_buttons_packed(pad, 0x100) != 0) {
        debug_printf_at(0xC0014, "PERS = %d", (s32)(0.0054931640625 * ((Cam_8006C964 *)this)->x54 + 1.0));
        if (TWindowShortListCtrl__check_controller_button(pad, 0x20000) != 0) {
            ((Cam_8006C964 *)this)->x54 += 0xB6;
        }
        if (TWindowShortListCtrl__check_controller_button(pad, 0x10000) != 0) {
            ((Cam_8006C964 *)this)->x54 -= 0xB6;
        }
    }
    ((void (*)(void *))get_target_position__11TCameraCtrlFv)(&v);
    VecCopy((Vec *)&target, (const Vec *)&v);
    this->set_target_pos(&target);
    if (test_previous_buttons_packed(pad, 0x200) != 0) {
        if (test_previous_buttons_packed(pad, 0x10) != 0) {
            ((Cam_8006C964 *)this)->dist -= (2.0f);
        }
        if (test_previous_buttons_packed(pad, 0x20) != 0) {
            ((Cam_8006C964 *)this)->dist += (2.0f);
        }
        if (((Cam_8006C964 *)this)->dist < 20.0f) {
            ((Cam_8006C964 *)this)->dist = 20.0f;
        }
        if (((Cam_8006C964 *)this)->dist > 400.0f) {
            ((Cam_8006C964 *)this)->dist = 400.0f;
        }
    }
    if (test_previous_buttons_packed(pad, 0x400) != 0) {
        ((Cam_8006C964 *)this)->yaw += sx * 3;
        ((Cam_8006C964 *)this)->pitch += sy * 3;
    }
    if (((Cam_8006C964 *)this)->pitch > 0x3800) {
        ((Cam_8006C964 *)this)->pitch = 0x3800;
    }
    if (((Cam_8006C964 *)this)->pitch < -0x3800) {
        ((Cam_8006C964 *)this)->pitch = -0x3800;
    }
    r = ((Cam_8006C964 *)this)->dist * cos_table_lookup(((Cam_8006C964 *)this)->pitch);
    ((Cam_8006C964 *)this)->eye.x = r * sin_table_lookup(((Cam_8006C964 *)this)->yaw) + ((Cam_8006C964 *)this)->center.x;
    ((Cam_8006C964 *)this)->eye.y = -(((Cam_8006C964 *)this)->dist * sin_table_lookup(((Cam_8006C964 *)this)->pitch) - ((Cam_8006C964 *)this)->center.y);
    ((Cam_8006C964 *)this)->eye.z = r * cos_table_lookup(((Cam_8006C964 *)this)->yaw) + ((Cam_8006C964 *)this)->center.z;
}
#pragma pop

}
TUnk_80488DA0::~TUnk_80488DA0() {

}


TUnk_80488DA0::TUnk_80488DA0() : TUnk_80488A28() {
    *(float*)((char*)this + 0x6c) = (2e+01f);
    this->m_38 = 0;
}

struct O_8006CC7C { u8 pad[0x1c]; Vec pos; };
extern O_8006CC7C *demo_camera_controller_table[];
extern s16 demo_camera_controller_index;

Vec get_target_position__11TCameraCtrlFv(void) {
    Vec def = default_target_position;
    O_8006CC7C *o = demo_camera_controller_table[demo_camera_controller_index];
    if (o != 0) {
        return o->pos;
    }
    return def;
}

