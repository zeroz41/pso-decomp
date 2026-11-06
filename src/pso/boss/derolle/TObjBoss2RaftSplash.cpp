#include "pso/boss/derolle/TObjBoss2RaftSplash.h"
#include "pso/system/vector.h"
#include "types.h"
#include "pso/boss/goldragon/TBoss8Dragon_8002CC48.h"
#include <stdlib.h>

struct Stack_8003AED4 {
    s32 sp8;
    f32 spC;
};

extern const f32 lbl_805D85B0;
void TObjBoss2RaftSplash::run_task() {
    u8 *arg0 = (u8 *)this;
    Stack_8003AED4 stack;
    f32 temp_f0;
    f32 temp_f1;
    *(f32 *)((s8 *)arg0 + 0x1C) = (f32) (*(f32 *)((s8 *)arg0 + 0x1C) + **(f32 **)((s8 *)arg0 + 0x24));
    temp_f0 = *(f32 *)((s8 *)arg0 + 0x1C);
    temp_f1 = *(f32 *)((s8 *)arg0 + 0x20);
    if (temp_f0 >= temp_f1) {
        *(f32 *)((s8 *)arg0 + 0x1C) = (f32) (temp_f0 - temp_f1);
        VecCopy((Vec *)(&stack.sp8), (const Vec *)(arg0 + 0x28));
        stack.spC += **(f32 **)((s8 *)arg0 + 0x24) - lbl_805D85B0;
        TObjBoss2RaftSplash::spawn_splash((s32) &stack.sp8, 0x170, (s32)(arg0 + 0x34));
    }
}
TObjBoss2RaftSplash::~TObjBoss2RaftSplash() {}

struct RecoveredGlobal_8003AFBC___vt__19TObjBoss2RaftSplash { s32 value; u8 remaining[0x14]; };

extern "C" {
void __ct__7TObjectFP7TObject(void *, void *);
extern RecoveredGlobal_8003AFBC___vt__19TObjBoss2RaftSplash __vt__19TObjBoss2RaftSplash;
extern s32 lbl_805D2700;
u8 *TObjBoss2RaftSplash__ct(u8 *object, u8 *arg1, u8 *arg2, u8 *arg3, s32 arg4) {
    __ct__7TObjectFP7TObject(object, arg1);
    *(s32 **)((s8 *)object + 0x18) = &__vt__19TObjBoss2RaftSplash.value;
    *(s32 *)((s8 *)object + 0) = (s32) lbl_805D2700;
    *(f32 *)((s8 *)object + 0x20) = (f32) (lbl_805D85B0 * (3.0f + rand_signed_unit()));
    *(f32 *)((s8 *)object + 0x1C) = (f32) (*(f32 *)((s8 *)object + 0x20) * (3.0517578e-05f * (f32) rand()));
    VecCopy((Vec *)(object + 0x28), (const Vec *)arg2);
    VecCopy((Vec *)(object + 0x34), (const Vec *)arg3);
    *(s32 *)((s8 *)object + 0x24) = arg4;
    return object;
}

}
