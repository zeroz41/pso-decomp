#include "types.h"
#include "pso/camera/TCameraController.h"
#include "pso/system/vector.h"
#include "pso/unk/TUnk_804887F8.h"
#include "pso/unk/TUnk_80488E00.h"
#include <stddef.h>
#include "pso/camera/TCameraCtrl.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/system/task/TObject.h"
#include "pso/camera/TCameraCtrl_801A6E60.h"
#include "pso/unk/text_803D96A8.h"

const Vec camera_ctrl_default_offset_vecs[2] = {
    {0.0f, 25.43f, 45.42f},
    {0.0f, 30.0f, 40.0f},
};

extern "C" {
f32 vector_length(void *);
extern u8 *camera_ctrl_instance;
s16 get_entity_id(u32);

void TCameraController::set_target(uaddr arg1) {
    *(u32 *)((s8 *)this + 0x1C) = arg1;
    if (arg1 != 0U) {
        this->m_20 = get_entity_id(arg1);
    }
}

#pragma push
#pragma fp_contract on
void TUnk_804887F8::update_target_follow() {
#define arg0 ((u8 *)this)
    Vec stack;
    f32 temp_f1;
    f32 temp_f1_2;
    u8 *camera_focus;
    u8 *temp_r4;
    camera_focus = (u8 *)TBoss3Volopt::get_camera_focus();
    if (camera_focus != NULL) {
        temp_r4 = *(u8 **)((s8 *)arg0 + 0x1C);
        stack.x = *(f32 *)((s8 *)temp_r4 + 0x38) - *(f32 *)((s8 *)camera_focus + 0);
        temp_f1 = (*(f32 *)((s8 *)temp_r4 + 0x40)) - *(f32 *)((s8 *)camera_focus + 8);
        stack.y = 0.0f;
        stack.z = temp_f1;
        temp_f1_2 = vector_length(&stack.x);
        if (0.0f != temp_f1_2) {
            normalize_vector(&stack);
        } else {
            return;
        }
        switch (*(s32 *)((s8 *)arg0 + 0x114)) {
        case 0:
            *(f32 *)((s8 *)arg0 + 0x48) = (f32) *(f32 *)((s8 *)camera_focus + 0);
            *(f32 *)((s8 *)arg0 + 0x50) = (f32) *(f32 *)((s8 *)camera_focus + 8);
            *(f32 *)((s8 *)arg0 + 0x4C) = (f32) *(f32 *)((s8 *)camera_focus + 4);
            if (*(f32 *)((s8 *)arg0 + 0x4C) >= 50.0f) {
                *(f32 *)((s8 *)arg0 + 0x4C) = 60.0f;
            }
            *(f32 *)((s8 *)arg0 + 0x3C) = (f32) ((45.42f * stack.x) + *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x1C)) + 0x38));
            *(f32 *)((s8 *)arg0 + 0x44) = (f32) ((45.42f * stack.z) + *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x1C)) + 0x40));
            *(f32 *)((s8 *)arg0 + 0x40) = (f32) (15.0f + *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x1C)) + 0x3C));
            if (temp_f1_2 < 100.0f) {
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
            if (temp_f1_2 > 100.0f) {
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
    Vec stack;
    this->m_38 = 0x15;
    this->m_58 = 1.65f;
    stack.x = *(f32 *)((s8 *)camera_ctrl_instance + 0x184) - this->target.x;
    stack.y = *(f32 *)((s8 *)camera_ctrl_instance + 0x188) - this->target.y;
    stack.z = *(f32 *)((s8 *)camera_ctrl_instance + 0x18C) - *(f32 *)((s8 *)arg0 + 0x50);
    *(f32 *)((s8 *)arg0 + 0x5C) = (f32) ((0.7f * vector_length(&stack.x)) / 100.0f);
    if (((TUnk_80488E00 *)arg0)->predict_obstruction() != 0) {
        this->m_fc = (s32) (this->m_fc | 1);
    } else {
        this->m_fc = (s32) (this->m_fc & 0xFFFFFFFE);
    }
    this->m_e8 = 0.0f;
    *(f32 *)((s8 *)arg0 + 0xEC) = 19.8f;
    this->m_f0 = -5.0f;
    VecCopy((Vec *)(arg0 + 0xDC), &camera_ctrl_default_offset_vecs[0]);
}

void *TCameraCtrl__vt12(void) {
    void *o;
    o = new TUnk_804887F8();
    return o;
}

extern u8 controller_input_state[];

void TUnk_804887F8::run_task() {
    m_38 = 0x15;
    if (test_previous_buttons_packed(controller_input_state + 0x20, 0x10000) != 0) {
        TUnk_80488E00::run_task();
    } else {
        update_target_follow();
    }
    m_38 = (s32) (m_38 | 0x10);
}

TUnk_804887F8::~TUnk_804887F8() {}

TUnk_804887F8::TUnk_804887F8() {
    m_38 = 21;
    m_58 = 0.65f;
    m_114 = 0;
    m_110 = 0;
}

void TUnk_80488E00::vfunc_14(s32 v) { this->m_10c = v; }

}
