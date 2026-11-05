#include "types.h"
#include "pso/enemy/TObjEneBalClawClaw_8008DC18.h"
#include "pso/enemy/TObjEneBalClawBody.h"

#include <stddef.h>
#include "pso/enemy/TObjEneBalClawClaw.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/misc/TLobby.h"
struct Stack_8008DC18 {
    s32 sp8;
    s32 spC;
    s32 sp10;
    s32 sp14;
};

struct RecoveredGlobal_8008DC18_lbl_80439B5C {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_8008DC18_lbl_8048EEE0 {
    s32 value;
    u8 remaining[0x28];
};

extern RecoveredGlobal_8008DC18_lbl_80439B5C lbl_80439B5C;
extern RecoveredGlobal_8008DC18_lbl_8048EEE0 lbl_8048EEE0;
extern u8 *lbl_805D4F20;
extern const f32 lbl_805D9618;

extern "C" {

f32 xz_distance_squared(s32, s32);

typedef char RecoveredGlobal_8008DC18_lbl_80439B5C_size[sizeof(RecoveredGlobal_8008DC18_lbl_80439B5C) == 0x14 ? 1 : -1];
typedef char RecoveredGlobal_8008DC18_lbl_8048EEE0_size[sizeof(RecoveredGlobal_8008DC18_lbl_8048EEE0) == 0x2C ? 1 : -1];
void TObjEneBalClawClaw::spawn_child_enemy() {
    typedef char sp8_offset[(offsetof(Stack_8008DC18, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_8008DC18, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_8008DC18, sp10) == 0x8) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_8008DC18, sp14) == 0xC) ? 1 : -1];
    Stack_8008DC18 stack;
    u8 *temp_r5;
    stack.sp8 = *(s32 *)((s8 *)&lbl_80439B5C.value + 0);
    stack.spC = *(s32 *)((s8 *)&lbl_80439B5C.value + 4);
    stack.sp10 = *(s32 *)((s8 *)&lbl_80439B5C.value + 8);
    stack.sp14 = *(s32 *)((s8 *)&lbl_80439B5C.value + 0xC);
    stack.sp8 = *(s32 *)((s8 *)lbl_805D4F20 + 0x430);
    temp_r5 = (u8 *)(*(u8 **)((s8 *)lbl_805D4F20 + 0x42C));
    TLobby::spawn_npc_enemy((s16)(0x13), (s32)((int) (*(s32 *)((s8 *)temp_r5 + 0x18))), (NJS_TEXLIST *)((int) (*(s32 *)((s8 *)temp_r5 + 0x1C))), &stack.sp8, (f32)((f32) (*(f32 *)((s8 *)&lbl_8048EEE0.value + 0xC))), (f32)lbl_805D9618);
}

void TObjEneBalClawClaw__sub_8008DC90(void) {  }

extern f32 lbl_805D961C;

void TObjEneBalClawBody::vfunc_58() {
    s32 arg0 = (s32)this;
    if (xz_distance_squared(arg0 + 0x38, arg0 + 0x50) > lbl_805D961C) {
        ((TObjEnemyCustom *)arg0)->update_if_active(8);
        return;
    }
    ((TObjEnemyCustom *)arg0)->update_if_active(0);
}

}
