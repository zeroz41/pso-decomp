#include "types.h"
#include "pso/system/data/FlagWord.h"

void FlagWord::set(u32 mask) { bits |= mask; }

void FlagWord::clear(u32 mask) { bits &= ~mask; }

s32 FlagWord::test_flags_any(u32 mask) {
    return (bits & mask) != 0;
}

FlagWord::FlagWord() { reset(); }

void FlagWord::reset() { bits = 0; }
