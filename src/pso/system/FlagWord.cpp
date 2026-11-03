#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/menu/TAdRicoRing_8001BEE8.h"

void FlagWord::set(u32 mask) { bits |= mask; }

void FlagWord::clear(u32 mask) { bits &= ~mask; }

s32 test_flags_any(s32 *flags, s32 mask) {
    return (*flags & mask) != 0;
}

FlagWord::FlagWord() { reset(); }

void FlagWord::reset() { bits = 0; }
