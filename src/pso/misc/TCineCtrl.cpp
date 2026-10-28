#include "types.h"
#include "pso/misc/TCineCtrl.h"
#include "pso/system/ModelDrawContext.h"

#include "pso/TObjCMHairMenu.h"
#include "pso/misc/TCameraCtrl.h"

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
extern void * TCineCtrl__instance;
extern const f32 lbl_805D91E0;
extern const f32 lbl_805D91E4;
extern const f32 lbl_805D91E8;
extern const f32 lbl_805D91EC;
extern const f32 TCineCtrl__data_805D91D0;
void TCameraCtrl__sub_80068EF0(void);
extern const f32 lbl_805D91D4;
extern const f32 lbl_805D91D8;
extern const f32 lbl_805D91DC;

extern void *TCineCtrl__instance;

void TCineCtrl::render() {
    u8 *arg0 = (u8 *)this;
    VtxList_80077BC0 vl;
    u32 col[4];
    f32 pos[8];
    if (!(*(f32 *)((s8 *)arg0 + 0x1C) <= TCineCtrl__data_805D91D0)) {
        TCameraCtrl::restore_full_screen_view();
        set_color_blending_mode(0, 8);
        set_color_blending_mode(1, 6);
        vl.pos = pos;
        vl.col = col;
        vl.n = 0;
        vl.cap = 4;
        this->m_27 = (s8) *(f32 *)((s8 *)arg0 + 0x1C);
        vl.pos[0] = TCineCtrl__data_805D91D0;
        vl.pos[1] = TCineCtrl__data_805D91D0;
        vl.col[0] = *(u32 *)((s8 *)arg0 + 0x24);
        vl.pos[2] = lbl_805D91D4;
        vl.pos[3] = TCineCtrl__data_805D91D0;
        vl.col[1] = *(u32 *)((s8 *)arg0 + 0x24);
        vl.pos[4] = lbl_805D91D4;
        vl.pos[5] = this->m_20;
        vl.col[2] = *(u32 *)((s8 *)arg0 + 0x24);
        vl.pos[6] = TCineCtrl__data_805D91D0;
        vl.pos[7] = this->m_20;
        vl.col[3] = *(u32 *)((s8 *)arg0 + 0x24);
        ((TObjCMHairMenu *)(&vl))->draw_tri_fan_2d(4U, 0x16, lbl_805D91D8);
        vl.pos[0] = TCineCtrl__data_805D91D0;
        vl.pos[1] = lbl_805D91DC - this->m_20;
        vl.col[0] = *(u32 *)((s8 *)arg0 + 0x24);
        vl.pos[2] = lbl_805D91D4;
        vl.pos[3] = lbl_805D91DC - this->m_20;
        vl.col[1] = *(u32 *)((s8 *)arg0 + 0x24);
        vl.pos[4] = lbl_805D91D4;
        vl.pos[5] = lbl_805D91DC;
        vl.col[2] = *(u32 *)((s8 *)arg0 + 0x24);
        vl.pos[6] = TCineCtrl__data_805D91D0;
        vl.pos[7] = lbl_805D91DC;
        vl.col[3] = *(u32 *)((s8 *)arg0 + 0x24);
        ((TObjCMHairMenu *)(&vl))->draw_tri_fan_2d(4U, 0x16, lbl_805D91D8);
        TCameraCtrl__sub_80068EF0();
    }
}

#pragma push
#pragma opt_common_subs off
void TCineCtrl::update_letterbox_hide() {
    s32 (*temp_r12)(void *);
    *(f32 *)((s8 *)((u8 *)this) + 0x1C) = (f32) (*(f32 *)((s8 *)((u8 *)this) + 0x1C) - lbl_805D91E0);
    this->m_20 = (f32) (this->m_20 - lbl_805D91E4);
    if (*(f32 *)((s8 *)((u8 *)this) + 0x1C) <= TCineCtrl__data_805D91D0) {
        *(f32 *)((s8 *)((u8 *)this) + 0x1C) = (f32) TCineCtrl__data_805D91D0;
    }
    if (this->m_20 <= TCineCtrl__data_805D91D0) {
        this->m_20 = (f32) TCineCtrl__data_805D91D0;
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
        *(f32 *)((s8 *)TCineCtrl__instance + 0x1C) = (f32) lbl_805D91E8;
        *(f32 *)((s8 *)TCineCtrl__instance + 0x20) = (f32) lbl_805D91EC;
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
    *(f32 *)((s8 *)((u8 *)this) + 0x1C) = (f32) (*(f32 *)((s8 *)((u8 *)this) + 0x1C) + lbl_805D91E0);
    this->m_20 = (f32) (this->m_20 + lbl_805D91E4);
    if (*(f32 *)((s8 *)((u8 *)this) + 0x1C) >= lbl_805D91E8) {
        *(f32 *)((s8 *)((u8 *)this) + 0x1C) = (f32) lbl_805D91E8;
    }
    if (this->m_20 >= lbl_805D91EC) {
        this->m_20 = (f32) lbl_805D91EC;
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
        *(f32 *)((s8 *)TCineCtrl__instance + 0x1C) = (f32) TCineCtrl__data_805D91D0;
        *(f32 *)((s8 *)TCineCtrl__instance + 0x20) = (f32) TCineCtrl__data_805D91D0;
        *(s8 *)((s8 *)TCineCtrl__instance + 0x26) = 0;
        *(s8 *)((s8 *)TCineCtrl__instance + 0x25) = 0;
        *(s8 *)((s8 *)TCineCtrl__instance + 0x24) = 0;
        *(s32 *)((s8 *)TCineCtrl__instance + 0x28) = 1;
    }
}

extern void *tl_fade;
extern void *TCineCtrl__class_name;

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
    *(void * *)&this->m_name = TCineCtrl__class_name;
    *(f32 *)((s8 *)this + 0x1C) = TCineCtrl__data_805D91D0;
    this->m_20 = TCineCtrl__data_805D91D0;
    *(u32 *)((s8 *)this + 0x24) = 0;
    *(u32 *)((s8 *)this + 0x28) = 0;
    TCineCtrl__instance = this;
}
