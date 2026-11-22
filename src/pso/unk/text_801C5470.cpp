#include "types.h"
#include "pso/unk/text_801C5470.h"
extern "C" {
s32 calc_class_stat_boost_index__10TObjPlayerFScl(s32, s32, s32);
void TObjPlayer__sub_801C5780(saddr, s32, s32);
s32 are_trap_counts_full(s8 *counts, s32 level, s8 classId) {
    s32 kind;
    s8 max;
    for (kind = 0; kind < 4; kind++) {
        if (kind != 2) {
            max = ((s8 (*)(s32, s8, s32))calc_class_stat_boost_index__10TObjPlayerFScl)(level, classId, kind);
            if (kind < 4 && counts[kind] < max) {
                return 0;
            }
        }
    }
    return 1;
}
}
void refill_trap_counts(s32 trap_counts, s32 arg1, s32 arg2) {
    s32 i;
    for (i = 0; i < 4; i++) {
        s32 idx = calc_class_stat_boost_index__10TObjPlayerFScl(arg1, arg2, i);
        TObjPlayer__sub_801C5780(trap_counts, idx, i);
    }
}
