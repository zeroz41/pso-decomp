#ifndef PSO_SYSTEM_FLAGWORD_H
#define PSO_SYSTEM_FLAGWORD_H

#include "types.h"

// A word of flag bits set and cleared by mask.
struct FlagWord {
    s32 bits;

    FlagWord();
    void reset();
    void set(u32 mask);
    void clear(u32 mask);
};

extern "C" {
// FlagWord::FlagWord(), for code that builds the word in place.
FlagWord *__ct__8FlagWordFv(void *flags);
}

#endif
