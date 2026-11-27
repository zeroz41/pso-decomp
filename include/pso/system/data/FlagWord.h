#ifndef PSO_SYSTEM_DATA_FLAGWORD_H
#define PSO_SYSTEM_DATA_FLAGWORD_H

#include "types.h"

// A word of flag bits set and cleared by mask.
struct FlagWord {
    s32 bits;

    FlagWord();
    void reset();
    void set(u32 mask);
    void clear(u32 mask);
    // Whether any bit of `mask` is set.
    s32 test_flags_any(u32 mask);
    s32 get_bits();
    void set_bits(s32 value);
    void bswap();
    FlagWord &operator=(FlagWord &src);
};

#ifdef __MWERKS__
extern "C" {
// FlagWord::FlagWord(), for CodeWarrior's hand-written static initializer in TItem.cpp.
FlagWord *__ct__8FlagWordFv(void *flags);
}
#endif

#endif
