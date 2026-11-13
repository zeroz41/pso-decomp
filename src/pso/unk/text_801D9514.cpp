#include "types.h"
#include "pso/player/TObjPlayer_801D9E08.h"
#include "pso/unk/text_801D9514.h"

extern "C" {
s8 TObjPlayer__sub_801AFDBC(s32 cls);
extern u8 *class_technique_cap_table[12];

u8 TObjPlayer__sub_801D9514(s32 cls, s16 tech) {
    return class_technique_cap_table[TObjPlayer__sub_801AFDBC(cls)][tech];
}

void TObjPlayer__sub_801D955C(u8 *techs, s32 cls) {
    s32 i;
    s32 n = TObjPlayer__sub_801D9E08();
    for (i = 0; i < n; ) {
        techs[i + 0x5C] = TObjPlayer__sub_801D9514(cls, i);
        i++;
    }
}
}
