#include "types.h"
#include "pso/player/TPlyGuildCardTag_801E09C4.h"

u8 __eq__16TPlyGuildCardTagFR16TPlyGuildCardTag(void *arg0, void *arg1) {
    int equal;

    equal = 0;
    if (((u8) *(u8 *)((s8 *)arg0 + 1) == (u8) *(u8 *)((s8 *)arg1 + 1)) && ((u16) *(u16 *)((s8 *)arg0 + 2) == (u16) *(u16 *)((s8 *)arg1 + 2)) && ((u32) *(u32 *)((s8 *)arg0 + 4) == (u32) *(u32 *)((s8 *)arg1 + 4))) {
        equal = 1;
    }
    return (u8)equal;
}
