#include "types.h"
#include "pso/system/vector.h"

#include <stddef.h>
#include "pso/misc/TNeedleShoot.h"
#include "pso/object/TObjMapWarp_80141C68.h"
#include "pso/system/NinjaTypes.h"
struct Stack_802A4544 {
    f32 sp8;
    f32 spC;
    f32 sp10;
    f32 sp14;
    f32 sp18;
    f32 sp1C;
};

extern "C" {
extern NJS_ARGB needle_shoot_color_white;
extern const f32 lbl_805DDF68;
u8 *csnVector(f32 *, f32 *, s32);
void TNeedleShoot::vfunc_8() {  }

#pragma push
#pragma opt_common_subs off
void TNeedleShoot::check_wall_hit() {
    typedef char sp8_offset[(offsetof(Stack_802A4544, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_802A4544, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_802A4544, sp10) == 0x8) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_802A4544, sp14) == 0xC) ? 1 : -1];
    typedef char sp18_offset[(offsetof(Stack_802A4544, sp18) == 0x10) ? 1 : -1];
    typedef char sp1C_offset[(offsetof(Stack_802A4544, sp1C) == 0x14) ? 1 : -1];
    Stack_802A4544 stack;
    u8 *temp_r3;
    stack.sp8 = *(f32 *)((s8 *)((u8 *)this) + 0x28);
    stack.spC = this->m_2c;
    stack.sp10 = *(f32 *)&this->unk_30;
    stack.sp14 = *(f32 *)&this->m_6c;
    stack.sp18 = *(f32 *)&this->unk_70;
    stack.sp1C = this->m_74;
    temp_r3 = (u8 *)(csnVector(&stack.sp8, &stack.sp14, 0x100));
    if (temp_r3 != NULL) {
        VecCopy((Vec *)(((u8 *)this) + 0x6C), (const Vec *)(*(s32 *)((s8 *)temp_r3 + 4)));
        this->vfunc_6();
    }
}
#pragma pop

void TNeedleShoot::render() {
    NJS_ARGB color = needle_shoot_color_white;
    TObjRoomId__sub_80141CF4((const Vec *)((u8 *)this + 0x6C), &color, lbl_805DDF68);
}

}
