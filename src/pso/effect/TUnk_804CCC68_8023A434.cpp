#include "types.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/effect/TUnk_804CCC68_8023A434.h"
#include "pso/system/vector.h"
#include "pso/effect/TUnk_804CCC68.h"

#include <stddef.h>
struct Stack_8023A434 {
    f32 sp8;
    f32 spC;
    f32 sp10;
    f32 sp14;
    f32 sp18;
    f32 sp1C;
};

extern "C" {
u8 *csnVector(f32 *, f32 *, s32);
#pragma push
#pragma opt_common_subs off
void TUnk_804CCC68::check_technique_projectile_wall_hit() {
    typedef char sp8_offset[(offsetof(Stack_8023A434, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_8023A434, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_8023A434, sp10) == 0x8) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_8023A434, sp14) == 0xC) ? 1 : -1];
    typedef char sp18_offset[(offsetof(Stack_8023A434, sp18) == 0x10) ? 1 : -1];
    typedef char sp1C_offset[(offsetof(Stack_8023A434, sp1C) == 0x14) ? 1 : -1];
    Stack_8023A434 stack;
    u8 *temp_r3;
    stack.sp8 = *(f32 *)((s8 *)((u8 *)this) + 0x78);
    stack.spC = *(f32 *)((s8 *)((u8 *)this) + 0x7C);
    stack.sp10 = *(f32 *)((s8 *)((u8 *)this) + 0x80);
    stack.sp14 = *(f32 *)((s8 *)((u8 *)this) + 0x20);
    stack.sp18 = *(f32 *)((s8 *)((u8 *)this) + 0x24);
    stack.sp1C = *(f32 *)((s8 *)((u8 *)this) + 0x28);
    temp_r3 = (u8 *)(csnVector(&stack.sp8, &stack.sp14, 0x100));
    if (temp_r3 != NULL) {
        VecCopy((Vec *)(((u8 *)this) + 0x20), (const Vec *)(*(s32 *)((s8 *)temp_r3 + 4)));
        this->vfunc_6();
        queue_destruction__7TObjectFv((this));
    }
}
#pragma pop

}
