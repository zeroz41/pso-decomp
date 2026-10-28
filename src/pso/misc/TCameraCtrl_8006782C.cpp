#include "types.h"
#include "pso/misc/TUnk_80488A28.h"
#include "pso/misc/TCameraCtrl_8006782C.h"
#include "pso/system/vector.h"
#include "pso/misc/TUnk_804887F8.h"
#include "pso/misc/TUnk_80488E00.h"

#include <stddef.h>
#include "pso/misc/TCameraCtrl.h"
#include "pso/boss/TBoss3Volopt.h"
struct Stack_80067AB0 {
    f32 sp8;
    f32 spC;
    f32 sp10;
};

struct RecoveredGlobal_80067AB0_lbl_80438150 { s32 value; u8 remaining[0x14]; };
typedef char RecoveredGlobal_80067AB0_lbl_80438150_size[sizeof(RecoveredGlobal_80067AB0_lbl_80438150) == 0x18 ? 1 : -1];

struct Stack_8006786C {
    f32 sp8;
    f32 spC;
    f32 sp10;
};

extern "C" {
f32 vector_length(void *);
extern RecoveredGlobal_80067AB0_lbl_80438150 camera_ctrl_default_offset_vecs;
extern u8 *camera_ctrl_instance;
extern const f32 lbl_805D8F38;
extern const f32 lbl_805D8F4C;
extern const f32 lbl_805D8F50;
extern const f32 lbl_805D8F54;
extern const f32 lbl_805D8F58;
extern const f32 lbl_805D8F5C;
void normalize_vector(void *);
extern const f32 lbl_805D8F3C;
extern const f32 lbl_805D8F40;
extern const f32 lbl_805D8F44;
extern const f32 lbl_805D8F48;
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);
s32 is_on_current_screen__11TCameraCtrlFv(void *, s32);
s16 get_entity_id(u32);

void TUnk_80488A28::set_target(u32 arg1) {
    *(u32 *)((s8 *)this + 0x1C) = arg1;
    if (arg1 != 0U) {
        this->m_20 = get_entity_id(arg1);
    }
}

#pragma push
#pragma fp_contract on
void TCameraCtrl::update_target_follow() {
#define arg0 ((u8 *)this)
    typedef char sp8_offset[(offsetof(Stack_8006786C, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_8006786C, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_8006786C, sp10) == 0x8) ? 1 : -1];
    Stack_8006786C stack;
    f32 temp_f1;
    f32 temp_f1_2;
    u8 *temp_r3;
    u8 *temp_r4;
    temp_r3 = (u8 *)TBoss3Volopt::get_camera_focus();
    if (temp_r3 != NULL) {
        temp_r4 = *(u8 **)((s8 *)arg0 + 0x1C);
        stack.sp8 = *(f32 *)((s8 *)temp_r4 + 0x38) - *(f32 *)((s8 *)temp_r3 + 0);
        temp_f1 = (*(f32 *)((s8 *)temp_r4 + 0x40)) - *(f32 *)((s8 *)temp_r3 + 8);
        stack.spC = lbl_805D8F38;
        stack.sp10 = temp_f1;
        temp_f1_2 = vector_length(&stack.sp8);
        if (lbl_805D8F38 != temp_f1_2) {
            normalize_vector(&stack.sp8);
        } else {
            return;
        }
        switch (*(s32 *)((s8 *)arg0 + 0x114)) {
        case 0:
            *(f32 *)((s8 *)arg0 + 0x48) = (f32) *(f32 *)((s8 *)temp_r3 + 0);
            *(f32 *)((s8 *)arg0 + 0x50) = (f32) *(f32 *)((s8 *)temp_r3 + 8);
            *(f32 *)((s8 *)arg0 + 0x4C) = (f32) *(f32 *)((s8 *)temp_r3 + 4);
            if (*(f32 *)((s8 *)arg0 + 0x4C) >= lbl_805D8F3C) {
                *(f32 *)((s8 *)arg0 + 0x4C) = (f32) lbl_805D8F40;
            }
            *(f32 *)((s8 *)arg0 + 0x3C) = (f32) ((lbl_805D8F44 * stack.sp8) + *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x1C)) + 0x38));
            *(f32 *)((s8 *)arg0 + 0x44) = (f32) ((lbl_805D8F44 * stack.sp10) + *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x1C)) + 0x40));
            *(f32 *)((s8 *)arg0 + 0x40) = (f32) (lbl_805D8F48 + *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x1C)) + 0x3C));
            if (temp_f1_2 < lbl_805D8F4C) {
                *(s32 *)((s8 *)arg0 + 0x114) = 1;
                *(f32 *)((s8 *)arg0 + 0x118) = (f32) (*(f32 *)((s8 *)arg0 + 0x48) - *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x1C)) + 0x38));
                *(f32 *)((s8 *)arg0 + 0x11C) = (f32) (*(f32 *)((s8 *)arg0 + 0x4C) - *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x1C)) + 0x3C));
                *(f32 *)((s8 *)arg0 + 0x120) = (f32) (*(f32 *)((s8 *)arg0 + 0x50) - *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x1C)) + 0x40));
                *(f32 *)((s8 *)arg0 + 0x124) = (f32) (*(f32 *)((s8 *)arg0 + 0x3C) - *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x1C)) + 0x38));
                *(f32 *)((s8 *)arg0 + 0x128) = (f32) (*(f32 *)((s8 *)arg0 + 0x40) - *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x1C)) + 0x3C));
                *(f32 *)((s8 *)arg0 + 0x12C) = (f32) (*(f32 *)((s8 *)arg0 + 0x44) - *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x1C)) + 0x40));
                return;
            }
            break;
        case 1:
            if (temp_f1_2 > lbl_805D8F4C) {
                *(s32 *)((s8 *)arg0 + 0x114) = 0;
            }
            *(f32 *)((s8 *)arg0 + 0x48) = (f32) (*(f32 *)((s8 *)arg0 + 0x118) + *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x1C)) + 0x38));
            *(f32 *)((s8 *)arg0 + 0x4C) = (f32) (*(f32 *)((s8 *)arg0 + 0x11C) + *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x1C)) + 0x3C));
            *(f32 *)((s8 *)arg0 + 0x50) = (f32) (*(f32 *)((s8 *)arg0 + 0x120) + *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x1C)) + 0x40));
            *(f32 *)((s8 *)arg0 + 0x3C) = (f32) (*(f32 *)((s8 *)arg0 + 0x124) + *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x1C)) + 0x38));
            *(f32 *)((s8 *)arg0 + 0x40) = (f32) (*(f32 *)((s8 *)arg0 + 0x128) + *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x1C)) + 0x3C));
            *(f32 *)((s8 *)arg0 + 0x44) = (f32) (*(f32 *)((s8 *)arg0 + 0x12C) + *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x1C)) + 0x40));
            break;
        }
    }
}
#undef arg0
#pragma pop

void TUnk_804887F8::update_follow_flags() {
    u8 *arg0 = (u8 *)this;
    typedef char sp8_offset[(offsetof(Stack_80067AB0, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_80067AB0, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_80067AB0, sp10) == 0x8) ? 1 : -1];
    Stack_80067AB0 stack;
    this->m_38 = 0x15;
    this->m_58 = (f32) lbl_805D8F50;
    stack.sp8 = *(f32 *)((s8 *)camera_ctrl_instance + 0x184) - this->target.x;
    stack.spC = *(f32 *)((s8 *)camera_ctrl_instance + 0x188) - this->target.y;
    stack.sp10 = *(f32 *)((s8 *)camera_ctrl_instance + 0x18C) - *(f32 *)((s8 *)arg0 + 0x50);
    *(f32 *)((s8 *)arg0 + 0x5C) = (f32) ((lbl_805D8F54 * vector_length(&stack.sp8)) / lbl_805D8F4C);
    if (((TUnk_80488E00 *)arg0)->predict_obstruction() != 0) {
        this->m_fc = (s32) (this->m_fc | 1);
    } else {
        this->m_fc = (s32) (this->m_fc & 0xFFFFFFFE);
    }
    this->m_e8 = (f32) lbl_805D8F38;
    *(f32 *)((s8 *)arg0 + 0xEC) = (f32) lbl_805D8F58;
    this->m_f0 = (f32) lbl_805D8F5C;
    VecCopy((Vec *)(arg0 + 0xDC), (const Vec *)(&camera_ctrl_default_offset_vecs.value));
}

void *TCameraCtrl__vt12(void) {
    void *o = __nw__7TObjectFUl(0x130);
    if (o != NULL) {
        o = ((TUnk_804887F8 *)o)->init();
    }
    return o;
}

extern u8 controller_input_state[];

void TCameraCtrl::init_state() {
    *(s32 *)&this->unk_38 = 0x15;
    if (is_on_current_screen__11TCameraCtrlFv(controller_input_state + 0x20, 0x10000) != 0) {
        update_follow_camera();
    } else {
        update_target_follow();
    }
    *(s32 *)&this->unk_38 = (s32) (*(s32 *)&this->unk_38 | 0x10);
}

extern s32 lbl_804887F8[];

void *__dt__13TUnk_804887F8Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804887F8;
        ((TCameraCtrl *)arg0)->deleting_dtor(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

}
