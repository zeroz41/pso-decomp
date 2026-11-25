#include "types.h"
#include "pso/unk/text_80228C54.h"

s32 to_upper_latin1(s32 c) {
    if (((s8)c >= 0x61 && (s8)c <= 0x7a) || ((s8)c >= 0xc0 && (s8)c <= 0xff)) {
        return c - 0x20;
    }
    return c;
}
