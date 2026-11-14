#include "types.h"
#include "pso/camera/TCineCtrl.h"
#include "pso/render/ModelDrawContext.h"

#include "pso/ui/charcreate/TObjCMHairMenu.h"
#include "pso/camera/TCameraCtrl.h"

#pragma readonly_strings on

struct RecoveredGlobal_80077FA0___vt__9TCineCtrl {
    s32 value;
    u8 remaining[0x14];
};

struct Obj_80077F58 { u8 pad[0x28]; s32 state; };

struct VtxList_80077BC0 {
    f32 *pos;
    u32 *col;
    s32 n;
    s32 cap;
};

extern "C" {
u8 * __dt__7TObjectFv(void *, s16);
void __dl__7TObjectFPv(s32);
extern s32 __vt__9TCineCtrl[];
void * TCineCtrl__instance;
void TCameraCtrl__sub_80068EF0(void);

extern void *TCineCtrl__instance;

void TCineCtrl::render() {
    u8 *arg0 = (u8 *)this;
    VtxList_80077BC0 vl;
    u32 col[4];
    f32 pos[8];
    if (!(*(f32 *)((s8 *)arg0 + 0x1C) <= 0.0f)) {
        TCameraCtrl::restore_full_screen_view();
        set_color_blending_mode(0, 8);
        set_color_blending_mode(1, 6);
        vl.pos = pos;
        vl.col = col;
        vl.n = 0;
        vl.cap = 4;
        this->m_27 = (s8) *(f32 *)((s8 *)arg0 + 0x1C);
        vl.pos[0] = 0.0f;
        vl.pos[1] = 0.0f;
        vl.col[0] = *(u32 *)((s8 *)arg0 + 0x24);
        vl.pos[2] = 640.0f;
        vl.pos[3] = 0.0f;
        vl.col[1] = *(u32 *)((s8 *)arg0 + 0x24);
        vl.pos[4] = 640.0f;
        vl.pos[5] = this->m_20;
        vl.col[2] = *(u32 *)((s8 *)arg0 + 0x24);
        vl.pos[6] = 0.0f;
        vl.pos[7] = this->m_20;
        vl.col[3] = *(u32 *)((s8 *)arg0 + 0x24);
        ((TObjCMHairMenu *)(&vl))->draw_tri_fan_2d(4U, 0x16, -10.0f);
        vl.pos[0] = 0.0f;
        vl.pos[1] = 480.0f - this->m_20;
        vl.col[0] = *(u32 *)((s8 *)arg0 + 0x24);
        vl.pos[2] = 640.0f;
        vl.pos[3] = 480.0f - this->m_20;
        vl.col[1] = *(u32 *)((s8 *)arg0 + 0x24);
        vl.pos[4] = 640.0f;
        vl.pos[5] = 480.0f;
        vl.col[2] = *(u32 *)((s8 *)arg0 + 0x24);
        vl.pos[6] = 0.0f;
        vl.pos[7] = 480.0f;
        vl.col[3] = *(u32 *)((s8 *)arg0 + 0x24);
        ((TObjCMHairMenu *)(&vl))->draw_tri_fan_2d(4U, 0x16, -10.0f);
        TCameraCtrl__sub_80068EF0();
    }
}

#pragma push
#pragma opt_common_subs off
void TCineCtrl::update_letterbox_hide() {
    s32 (*temp_r12)(void *);
    *(f32 *)((s8 *)((u8 *)this) + 0x1C) = (f32) (*(f32 *)((s8 *)((u8 *)this) + 0x1C) - 8.0f);
    this->m_20 = (f32) (this->m_20 - 2.0f);
    if (*(f32 *)((s8 *)((u8 *)this) + 0x1C) <= 0.0f) {
        *(f32 *)((s8 *)((u8 *)this) + 0x1C) = 0.0f;
    }
    if (this->m_20 <= 0.0f) {
        this->m_20 = 0.0f;
        temp_r12 = *(s32 (**)(void *))((s8 *)((u8 *)this) + 0x2C);
        if (temp_r12 != NULL) {
            temp_r12(this);
        }
        *(s32 *)((s8 *)((u8 *)this) + 0x28) = 0;
    }
}
#pragma pop

void TCineCtrl::reset_state(s32 arg0) {
    if ((void *) TCineCtrl__instance != NULL) {
        *(s32 *)((s8 *)TCineCtrl__instance + 0x2C) = arg0;
        *(f32 *)((s8 *)TCineCtrl__instance + 0x1C) = 255.0f;
        *(f32 *)((s8 *)TCineCtrl__instance + 0x20) = 70.0f;
        *(s8 *)((s8 *)TCineCtrl__instance + 0x26) = 0;
        *(s8 *)((s8 *)TCineCtrl__instance + 0x25) = 0;
        *(s8 *)((s8 *)TCineCtrl__instance + 0x24) = 0;
        *(s32 *)((s8 *)TCineCtrl__instance + 0x28) = 2;
    }
}

#pragma push
#pragma opt_common_subs off
void TCineCtrl::update_letterbox_show() {
    s32 (*temp_r12)(void *);
    *(f32 *)((s8 *)((u8 *)this) + 0x1C) += 8.0f;
    this->m_20 += 2.0f;
    if (*(f32 *)((s8 *)((u8 *)this) + 0x1C) >= 255.0f) {
        *(f32 *)((s8 *)((u8 *)this) + 0x1C) = 255.0f;
    }
    if (this->m_20 >= 70.0f) {
        this->m_20 = 70.0f;
        temp_r12 = *(s32 (**)(void *))((s8 *)((u8 *)this) + 0x2C);
        if (temp_r12 != NULL) {
            temp_r12(this);
        }
        *(s32 *)((s8 *)((u8 *)this) + 0x28) = 0;
    }
}
#pragma pop

void TCineCtrl::reset(s32 arg0) {
    if ((void *) TCineCtrl__instance != NULL) {
        *(s32 *)((s8 *)TCineCtrl__instance + 0x2C) = arg0;
        *(f32 *)((s8 *)TCineCtrl__instance + 0x1C) = 0.0f;
        *(f32 *)((s8 *)TCineCtrl__instance + 0x20) = 0.0f;
        *(s8 *)((s8 *)TCineCtrl__instance + 0x26) = 0;
        *(s8 *)((s8 *)TCineCtrl__instance + 0x25) = 0;
        *(s8 *)((s8 *)TCineCtrl__instance + 0x24) = 0;
        *(s32 *)((s8 *)TCineCtrl__instance + 0x28) = 1;
    }
}

extern void *tl_fade;
const char *TCineCtrl__class_name = "TCineCtrl";

typedef char RecoveredGlobal_80077FA0___vt__9TCineCtrl_size[sizeof(RecoveredGlobal_80077FA0___vt__9TCineCtrl) == 0x18 ? 1 : -1];

void TCineCtrl::run_task() {
    Obj_80077F58 *self = (Obj_80077F58 *)this;
    switch (self->state) {
    case 0:
        break;
    case 1:
        ((TCineCtrl *)self)->update_letterbox_show();
        break;
    case 2:
        ((TCineCtrl *)self)->update_letterbox_hide();
        break;
    }
}

u8 *__dt__9TCineCtrlFv(u8 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_80077FA0___vt__9TCineCtrl *)&__vt__9TCineCtrl).value;
        (*(s32 *)&TCineCtrl__instance) = 0;
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv((s32) arg0);
        }
    }
    return arg0;
}

}
TCineCtrl::TCineCtrl() : TObject((TObject *)tl_fade) {
    this->m_name = TCineCtrl__class_name;
    *(f32 *)((s8 *)this + 0x1C) = 0.0f;
    this->m_20 = 0.0f;
    *(u32 *)((s8 *)this + 0x24) = 0;
    *(u32 *)((s8 *)this + 0x28) = 0;
    TCineCtrl__instance = this;
}
