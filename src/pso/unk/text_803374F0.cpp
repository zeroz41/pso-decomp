#include "types.h"
#include "pso/player/TObjPlayer_80337348.h"

void MaterialUsage::set_count(s32 index, u8 count) {
    counts[index] = count;
}

u8 MaterialUsage::get_count(s32 index) {
    return counts[index];
}
