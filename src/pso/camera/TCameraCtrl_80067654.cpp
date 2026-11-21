#include "types.h"
#include "pso/unk/TUnk_804887C8.h"
#include "pso/unk/TUnk_80488A28.h"
#include "pso/camera/TCameraCtrl_80067654.h"
#include "pso/camera/TCameraCtrl_80067FC0.h"
#include "pso/system/vector.h"

#include "pso/camera/TCameraCtrl.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/math/MatrixVector.h"

extern "C" {
void *get_player_by_client_id(s32 i);

void TUnk_80488A28::vfunc_6() {  }
void TUnk_80488A28::reset_state() {  }
void TUnk_80488A28::vfunc_9(u8 *, u8 *) {  }
void TUnk_80488A28::vfunc_8(void *) {  }
void TUnk_80488A28::vfunc_10() {  }

void * TCameraCtrl__vt11(void) {
    void *o;
    o = (void *)new TUnk_804887C8();
    return o;
}

#pragma push
#pragma fp_contract on
void TUnk_804887C8::run_task() {
    u8 *arg0 = (u8 *)this;
    Vec stack;
    f32 temp_f1;
    f32 temp_f2;
    u8 *camera_focus;
    u8 *temp_r4;
    this->m_58 = 1.0f;
    if ((void *) *(u8 **)((s8 *)arg0 + 0x1C) != NULL) {
        camera_focus = (u8 *)TBoss3Volopt::get_camera_focus();
        if (camera_focus != NULL) {
            VecCopy((Vec *)(arg0 + 0x48), (const Vec *)(camera_focus));
            temp_r4 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x1C));
            stack.x = *(f32 *)((s8 *)temp_r4 + 0x38) - *(f32 *)((s8 *)camera_focus + 0);
            temp_f2 = *(f32 *)((s8 *)temp_r4 + 0x40);
            temp_f1 = temp_f2 - *(f32 *)((s8 *)camera_focus + 8);
            stack.y = 0.0f;
            stack.z = temp_f1;
            if (0.0f != vector_length(&stack)) {
                normalize_vector(&stack);
                this->position.x = (f32) ((30.0f * stack.x) + *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x1C)) + 0x38));
                this->position.y = (f32) (10.0f + *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x1C)) + 0x3C));
                this->position.z = (f32) ((30.0f * stack.z) + *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x1C)) + 0x40));
            }
        }
    }
}
#pragma pop

}
TUnk_804887C8::~TUnk_804887C8() {

}

TUnk_804887C8::TUnk_804887C8() : TUnk_80488A28() {
    this->m_38 = 5;
    ((TUnk_80488A28 *)this)->set_target((uaddr)get_player_by_client_id(0U));
}

