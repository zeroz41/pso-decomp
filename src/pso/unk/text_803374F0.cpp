#include "types.h"
#include "pso/player/TObjPlayer_80337348.h"

void MaterialUsage::fn_803374F0(s32 index, u8 value) {
    counts[index] = value;
}

u8 MaterialUsage::fn_803374F8(s32 index) {
    return counts[index];
}
