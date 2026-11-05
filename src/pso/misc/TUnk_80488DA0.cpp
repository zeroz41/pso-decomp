#include "types.h"
#include "pso/misc/TUnk_80488DA0.h"
#include "pso/misc/TCameraCtrl_80067FC0.h"
#include "pso/misc/TCameraCtrl_8006C8E4.h"
#include "pso/system/vector.h"
#include "pso/misc/TUnk_80488DA0.h"
#include "pso/misc/TUnk_80488D70.h"
#include "pso/misc/TCameraCtrl.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct Vec_8006C964 { f32 x, y, z; };
struct V_8006CC7C { f32 x, y, z; };
extern "C" const V_8006CC7C lbl_804384E8;

struct Pad_8006C964 { u8 pad0[0x14]; s16 sx; s16 sy; };

struct Ctl_8006C964 { u8 pad0[0xC0]; Pad_8006C964 pad; };

struct Cam_8006C964 {
    u8 pad0[0x2C];
    s32 pitch;
    s32 yaw;
    u8 pad34[8];
    Vec_8006C964 eye;
    Vec_8006C964 center;
    s32 x54;
    u8 pad58[0x6C - 0x58];
    f32 dist;
};

extern "C" {
void *__nw__7TObjectFUl(int);
V_8006CC7C get_target_position__11TCameraCtrlFv(void);
s32 TWindowShortListCtrl__check_controller_button(void *, s32);
s32 is_on_current_screen__11TCameraCtrlFv(void *, s32);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
void debug_printf_at(s32, const char *, ...);
extern Ctl_8006C964 controller_input_state;
int __ct__13TUnk_80488A28Fv(void);
void __dl__7TObjectFPv(void *);

extern unsigned char __vt__13TUnk_80488DA0[];

void * TCameraCtrl__vt6(void) {
    void *o;
    o = __nw__7TObjectFUl(0x70);
    if (o != NULL) {
        o = TCameraCtrl__sub_8006CC30(o);
    }
    return o;
}

extern Vec_8006C964 lbl_804384F4;
extern char lbl_80438500[];
extern const f64 lbl_80438510;
extern const f64 lbl_80438518;
#pragma push
#pragma fp_contract on
void TUnk_80488DA0::run_task() {
    Vec_8006C964 target = lbl_804384F4;
    Vec_8006C964 v;
    Pad_8006C964 *pad = &controller_input_state.pad;
    s16 sx = controller_input_state.pad.sx;
    s16 sy = controller_input_state.pad.sy;
    f32 r;
    if (is_on_current_screen__11TCameraCtrlFv(pad, 0x100) != 0) {
        debug_printf_at(0xC0014, lbl_80438500, (s32)(lbl_80438518 * (f64)((Cam_8006C964 *)this)->x54 + lbl_80438510));
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
    if (is_on_current_screen__11TCameraCtrlFv(pad, 0x200) != 0) {
        if (is_on_current_screen__11TCameraCtrlFv(pad, 0x10) != 0) {
            ((Cam_8006C964 *)this)->dist -= (2.0f);
        }
        if (is_on_current_screen__11TCameraCtrlFv(pad, 0x20) != 0) {
            ((Cam_8006C964 *)this)->dist += (2.0f);
        }
        if (((Cam_8006C964 *)this)->dist < 20.0f) {
            ((Cam_8006C964 *)this)->dist = 20.0f;
        }
        if (((Cam_8006C964 *)this)->dist > 400.0f) {
            ((Cam_8006C964 *)this)->dist = 400.0f;
        }
    }
    if (is_on_current_screen__11TCameraCtrlFv(pad, 0x400) != 0) {
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
extern "C" {

void* TCameraCtrl__sub_8006CC30(void* a0) { __ct__13TUnk_80488A28Fv(); *(int*)((char*)a0 + 0x18) = (int)__vt__13TUnk_80488DA0; *(float*)((char*)a0 + 0x6c) = (2e+01f); ((TUnk_80488DA0 *)a0)->m_38 = 0; return a0; }

struct O_8006CC7C { u8 pad[0x1c]; V_8006CC7C pos; };
extern O_8006CC7C *demo_camera_controller_table[];
extern s16 demo_camera_controller_index;

V_8006CC7C get_target_position__11TCameraCtrlFv(void) {
    V_8006CC7C def = lbl_804384E8;
    O_8006CC7C *o = demo_camera_controller_table[demo_camera_controller_index];
    if (o != 0) {
        return o->pos;
    }
    return def;
}

}
