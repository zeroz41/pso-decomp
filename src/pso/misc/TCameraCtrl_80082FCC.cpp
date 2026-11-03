#include "types.h"
#include "pso/misc/TCameraCtrl_80082FCC.h"
#include "pso/TMainTask.h"
#include "pso/misc/TUnk_8048E5DC.h"

#include <stddef.h>
#include "pso/misc/TCameraCtrl.h"
#include "pso/object/TObjFish.h"
struct Stack_800830B0 {
    s32 sp8;
    s32 spC;
    s32 sp10;
    f32 sp14;
    f32 sp18;
    f32 sp1C;
    s32 sp20;
    s32 sp24;
    s32 sp28;
};

struct RecoveredGlobal_800830B0_lbl_80439348 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_800830B0_main_task {
    s32 value;
    u8 remaining[0x30];
};

struct G_80082FCC { s32 value; s32 v4; f32 f8; f32 fC; };

extern "C" {
s32 is_split_screen();
s32 TCameraCtrl__sub_80068EF0();
s32 direction_to_pitch_yaw(void *, void *, void *);
s32 TObjPlayer__sub_80084744();
s32 TObjPlayer__sub_80084754();
s32 GXPixModeSync();
s32 GXSetTexCopySrc(int, int, int, int);
s32 GXSetTexCopyDst(int, int, int, int);
s32 GXSetCopyClear(void *, int);
s32 GXCopyTex(void *, int);
s32 GXSetZMode(int, int, int);
s32 GXSetViewport(f32, f32, f32, f32, f32, f32);
s32 GXSetScissor(int, int, int, int);
s32 set_perspective_projection_from_fov(int, f32, f32, f32);
void VecCopy__FP3VecPC3Vec(void *);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
}
void set_camera_look_at(u8 *eye, u8 *target, u8 *up);
extern RecoveredGlobal_800830B0_lbl_80439348 camera_ctrl_up_vector;
extern u8 *camera_ctrl_instance;
extern u32 camera_render_target_singleton;
extern const f32 lbl_805D93D0;
extern const f32 lbl_805D93D8;
extern const f32 lbl_805D9404;
extern const f32 lbl_805D9408;
extern const f32 lbl_805D940C;
extern const f32 lbl_805D9410;
extern s32 lbl_805E1210;
extern G_80082FCC TCameraCtrl__data_804FF634;
extern const f32 lbl_805D93EC;
extern const f32 lbl_805D93F0;
extern const f32 lbl_805D93F4;
extern const f32 lbl_805D93F8;
extern const f32 lbl_805D93FC;
extern const f32 lbl_805D9400;
void load_list_texture(s32 idx, s32 wrapS, s32 wrapT, s32 map);
void calc_projection_screen_offset(f32 *arg0, f32 *arg1) {
    f32 dx = TCameraCtrl__data_804FF634.f8;
    f32 y = TCameraCtrl__data_804FF634.fC;
    f32 dy;
    dx -= lbl_805D93EC;
    dy = y - lbl_805D93F0;
    *arg0 = (lbl_805D93F4 * dx) / lbl_805D93F8;
    *arg1 = (lbl_805D93FC * dy) / lbl_805D9400;
}

void TCameraCtrl::copy_position_vectors(void *arg1, void *arg2) {
    VecCopy__FP3VecPC3Vec((void *)((char *)this + 32));
    ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)((void *)((char *)this + 44), arg2);
}

void TCameraCtrl::update_single_screen() {
    if ((is_split_screen() == 0) && ((u32) camera_render_target_singleton != 0U)) {
        TObjFish::set_global_param(camera_render_target_singleton + 0x1C);
        load_list_texture(0, 0, 0, 0);
    }
}

void TUnk_8048E5DC::render() {  }
void TUnk_8048E5DC::run_task() {  }

extern s32 __vt__13TUnk_8048E5DC[];

#pragma push
#pragma opt_common_subs off
typedef char RecoveredGlobal_800830B0_lbl_80439348_size[sizeof(RecoveredGlobal_800830B0_lbl_80439348) == 0x10 ? 1 : -1];
typedef char RecoveredGlobal_800830B0_main_task_size[sizeof(RecoveredGlobal_800830B0_main_task) == 0x34 ? 1 : -1];
void TUnk_8048E5DC::render_shadows() {
    u8 *arg0 = (u8 *)this;
    typedef char sp8_offset[(offsetof(Stack_800830B0, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_800830B0, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_800830B0, sp10) == 0x8) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_800830B0, sp14) == 0xC) ? 1 : -1];
    typedef char sp18_offset[(offsetof(Stack_800830B0, sp18) == 0x10) ? 1 : -1];
    typedef char sp1C_offset[(offsetof(Stack_800830B0, sp1C) == 0x14) ? 1 : -1];
    typedef char sp20_offset[(offsetof(Stack_800830B0, sp20) == 0x18) ? 1 : -1];
    typedef char sp24_offset[(offsetof(Stack_800830B0, sp24) == 0x1C) ? 1 : -1];
    typedef char sp28_offset[(offsetof(Stack_800830B0, sp28) == 0x20) ? 1 : -1];
    Stack_800830B0 stack;
    if (is_split_screen() == 0) {
        TCameraCtrl::restore_full_screen_view();
        GXSetViewport(lbl_805D93D0, lbl_805D93D0, lbl_805D9404, lbl_805D9408, lbl_805D93D0, lbl_805D93D8);
        GXSetScissor(0, 0, 0x280, 0x1E0);
        stack.sp20 = *(s32 *)((s8 *)&camera_ctrl_up_vector.value + 0);
        stack.sp24 = *(s32 *)((s8 *)&camera_ctrl_up_vector.value + 4);
        stack.sp28 = *(s32 *)((s8 *)&camera_ctrl_up_vector.value + 8);
        set_perspective_projection_from_fov((int) (((TCameraCtrl *)camera_ctrl_instance)->fov), lbl_805D940C, lbl_805D93D8, lbl_805D9410);
        set_camera_look_at((u8 *)&this->m_20, (u8 *)&this->unk_2C, (u8 *)&stack.sp20);
        if ((void *) camera_ctrl_instance != NULL) {
            stack.sp14 = *(f32 *)&this->unk_2C - this->m_20;
            stack.sp18 = this->m_30 - *(f32 *)&this->unk_24;
            stack.sp1C = *(f32 *)((s8 *)arg0 + 0x34) - this->m_28;
            direction_to_pitch_yaw((void *)&stack.sp14, (void *)&stack.sp10, (void *)&stack.spC);
            TCameraCtrl::calc_axes_from_angles((s32)camera_ctrl_instance, (s32)stack.sp10, (s32)stack.spC);
        }
        TObjPlayer__sub_80084754();
        ((TMainTask *)(&(*(RecoveredGlobal_800830B0_main_task *)&main_task).value))->render_scene_passes();
        TObjPlayer__sub_80084744();
        if ((void *) (*(u8 * *)&camera_render_target_singleton) != NULL) {
            stack.sp8 = lbl_805E1210;
            GXSetCopyClear((void *)&stack.sp8, 0xFFFFFF);
            GXSetZMode((int) (1U), 7, 1);
            GXSetTexCopySrc((int) (0U), 0, (int) (0x280U), (int) (0x1E0U));
            GXSetTexCopyDst(0x280, 0x1E0, 4, 0);
            GXCopyTex((void *) (*(s32 *)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&camera_render_target_singleton) + 0x1C)) + 8)) + 0xC)) + 0x20)), (int) (1U));
            GXPixModeSync();
        }
        GXSetViewport(lbl_805D93D0, lbl_805D93D0, lbl_805D9404, lbl_805D9408, lbl_805D93D0, lbl_805D93D8);
        GXSetScissor(0, 0, 0x280, 0x1E0);
        TCameraCtrl__sub_80068EF0();
        ((TCameraCtrl *)camera_ctrl_instance)->calc_rotated_axes();
        ((TCameraCtrl *)camera_ctrl_instance)->setup_default_view(0);
    }
}
#pragma pop

void *TUnk_8048E5DC::dt(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = __vt__13TUnk_8048E5DC;
        __dt__7TObjectFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}
