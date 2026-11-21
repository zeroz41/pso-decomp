#include "types.h"
#include "pso/unk/text_803374F0.h"

void fn_803374F0(u8 *arg0, s32 arg1, s8 arg2) {
    *(s8 *)((s8 *)(arg0 + arg1) + 0) = arg2;
}

u8 fn_803374F8(u8 *arg0, s32 arg1) {
    return *(u8 *)((s8 *)(arg0 + arg1) + 0);
}
