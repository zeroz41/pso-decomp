#ifndef PSO_UNK_TEXT_8007C0CC_H
#define PSO_UNK_TEXT_8007C0CC_H

#include "types.h"

extern "C" {
void subtractive_rng_make_shuffle(s32 *stream);
s32 subtractive_rng_next(s32 *rng);
void subtractive_rng_unshuffle(void *stream, const u8 *source, u8 *destination, u32 size);
void subtractive_rng_xor_buffer(s32 *self, u32 *data, s32 len);
}

#endif
