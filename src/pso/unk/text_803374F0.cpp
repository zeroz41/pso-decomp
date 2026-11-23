#include "types.h"
#include "pso/player/TObjPlayer_80337348.h"

void Obj_803374C4::fn_803374F0(s32 index, u8 value) {
    counts[index] = value;
}

u8 Obj_803374C4::fn_803374F8(s32 index) {
    return counts[index];
}
