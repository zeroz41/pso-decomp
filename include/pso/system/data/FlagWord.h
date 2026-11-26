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
    s32 get_bits();
    void set_bits(s32 value);
    void bswap();
    FlagWord &operator=(FlagWord &src);
};

extern "C" {
// FlagWord::FlagWord(), for code that builds the word in place.
FlagWord *__ct__8FlagWordFv(void *flags);
}

extern "C" {
// Whether any bit of `mask` is set in the flag word.
s32 test_flags_any(s32 *flags, s32 mask);
}
#endif
