#include "pso/boss/barbaray/TObjBoss7RaftSplash.h"
#include "pso/boss/goldragon/TBoss8Dragon_8002CC48.h"
#include "pso/system/vector.h"

#include "types.h"
#include "pso/object/ambient/TObjFish.h"
#include <stdlib.h>

struct Stack_802F15D4 {
    s32 sp8;
    f32 spC;
};

struct RecoveredGlobal_802F16CC___vt__19TObjBoss7RaftSplash { s32 value; u8 remaining[0x14]; };

extern "C" {
u16 TCameraCtrl__sub_8006A5DC();
extern const f32 lbl_805DEC68;
void __ct__7TObjectFP7TObject(void *, void *);
extern RecoveredGlobal_802F16CC___vt__19TObjBoss7RaftSplash __vt__19TObjBoss7RaftSplash;
extern s32 lbl_805D3FE8;
s32 spawn_particle__8TObjFishFllf(f32);

extern const f32 lbl_805DEC90;

void TObjBoss7RaftSplash::run_task() {
    u8 *arg0 = (u8 *)this;
    Stack_802F15D4 stack;
    f32 temp_f0;
    f32 temp_f1;
    if (TCameraCtrl__sub_8006A5DC() != 5) {
        *(f32 *)((s8 *)arg0 + 0x1C) = (f32) (*(f32 *)((s8 *)arg0 + 0x1C) + **(f32 **)((s8 *)arg0 + 0x24));
        temp_f0 = *(f32 *)((s8 *)arg0 + 0x1C);
        temp_f1 = *(f32 *)((s8 *)arg0 + 0x20);
        if (temp_f0 >= temp_f1) {
            *(f32 *)((s8 *)arg0 + 0x1C) = (f32) (temp_f0 - temp_f1);
            VecCopy((Vec *)(&stack.sp8), (const Vec *)(arg0 + 0x28));
            stack.spC += **(f32 **)((s8 *)arg0 + 0x24) - lbl_805DEC68;
            TObjFish::create_splash_particle((s32) &stack.sp8, 0x200, (s32)(arg0 + 0x34));
        }
    }
}

TObjBoss7RaftSplash::~TObjBoss7RaftSplash() {}
u8 *TObjBoss7RaftSplash__ct(u8 *object, u8 *arg1, u8 *arg2, u8 *arg3, s32 arg4) {
    __ct__7TObjectFP7TObject(object, arg1);
    *(s32 **)((s8 *)object + 0x18) = &__vt__19TObjBoss7RaftSplash.value;
    *(s32 *)((s8 *)object + 0) = (s32) lbl_805D3FE8;
    *(f32 *)((s8 *)object + 0x20) = (f32) (lbl_805DEC68 * (3.0f + rand_signed_unit()));
    *(f32 *)((s8 *)object + 0x1C) = (f32) (*(f32 *)((s8 *)object + 0x20) * (3.0517578e-05f * (f32) rand()));
    VecCopy((Vec *)(object + 0x28), (const Vec *)arg2);
    VecCopy((Vec *)(object + 0x34), (const Vec *)arg3);
    *(s32 *)((s8 *)object + 0x24) = arg4;
    return object;
}

void TObjFish::spawn_default_particle() {
    spawn_particle__8TObjFishFllf(lbl_805DEC90);
}

}
