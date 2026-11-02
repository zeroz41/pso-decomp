#include "types.h"
#include "pso/misc/TUnk_804887C8.h"
#include "pso/misc/TUnk_80488A28.h"
#include "pso/misc/TCameraCtrl_80067654.h"
#include "pso/misc/TCameraCtrl_80067FC0.h"
#include "pso/system/vector.h"
#include "pso/misc/TUnk_804887C8.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/boss/TBoss3Volopt.h"

struct Stack_800676A0 {
    f32 sp8;
    f32 spC;
    f32 sp10;
};

struct RecoveredGlobal_800677D4_lbl_804887C8 {
    s32 value;
    u8 remaining[0x2C];
};

extern "C" {
void *__nw__7TObjectFUl(int);
f32 vector_length(void *, int, f32, f32);
s32 normalize_vector(void *);
u8 * __ct__13TUnk_80488A28Fv(void *);
void *get_player_by_client_id(s32 i);
extern s32 __vt__13TUnk_804887C8[];
void __dl__7TObjectFPv(void *);

void TUnk_80488A28::vfunc_6() {  }
void TUnk_80488A28::vfunc_7() {  }
void TUnk_80488A28::vfunc_9(u8 *, u8 *) {  }
void TUnk_80488A28::vfunc_8(void *) {  }
void TUnk_80488A28::vfunc_10() {  }

void * TCameraCtrl__vt11(void) {
    void *o;
    o = __nw__7TObjectFUl(0x6C);
    if (o != NULL) {
        o = TCameraCtrl__sub_800677D4((u8 *)o);
    }
    return o;
}

#pragma push
#pragma fp_contract on
void TUnk_804887C8::run_task() {
    u8 *arg0 = (u8 *)this;
    Stack_800676A0 stack;
    f32 temp_f1;
    f32 temp_f2;
    u8 *temp_r3;
    u8 *temp_r4;
    this->m_58 = 1.0f;
    if ((void *) *(u8 **)((s8 *)arg0 + 0x1C) != NULL) {
        temp_r3 = (u8 *)TBoss3Volopt::get_camera_focus();
        if (temp_r3 != NULL) {
            VecCopy((Vec *)(arg0 + 0x48), (const Vec *)(temp_r3));
            temp_r4 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x1C));
            stack.sp8 = *(f32 *)((s8 *)temp_r4 + 0x38) - *(f32 *)((s8 *)temp_r3 + 0);
            temp_f2 = *(f32 *)((s8 *)temp_r4 + 0x40);
            temp_f1 = temp_f2 - *(f32 *)((s8 *)temp_r3 + 8);
            stack.spC = 0.0f;
            stack.sp10 = temp_f1;
            if (0.0f != vector_length(&stack.sp8, (int)temp_r4, (f32)temp_f1, (f32)temp_f2)) {
                normalize_vector(&stack.sp8);
                this->position.x = (f32) ((30.0f * stack.sp8) + *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x1C)) + 0x38));
                this->position.y = (f32) (10.0f + *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x1C)) + 0x3C));
                this->position.z = (f32) ((30.0f * stack.sp10) + *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x1C)) + 0x40));
            }
        }
    }
}
#pragma pop

}
TUnk_804887C8::~TUnk_804887C8() {

}
extern "C" {
typedef char RecoveredGlobal_800677D4_lbl_804887C8_size[sizeof(RecoveredGlobal_800677D4_lbl_804887C8) == 0x30 ? 1 : -1];
u8 *TCameraCtrl__sub_800677D4(u8 *arg0) {
    __ct__13TUnk_80488A28Fv(arg0);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_800677D4_lbl_804887C8 *)&__vt__13TUnk_804887C8).value;
    ((TUnk_804887C8 *)arg0)->m_38 = 5;
    ((TUnk_80488A28 *)arg0)->set_target((u32)get_player_by_client_id(0U));
    return arg0;
}

}
