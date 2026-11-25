#ifndef PSO_SYSTEM_SUBTRACTIVERNG_H
#define PSO_SYSTEM_SUBTRACTIVERNG_H

#include "types.h"

// A subtractive random number generator: 55 words of lagged state and the
// seed. The default constructor seeds it with 0.
struct SubtractiveRng {
    SubtractiveRng();
    SubtractiveRng(u32 seed);
    s32 pos;          // the table index of the last sample (1-55); 55 refills the table
    s32 table[56];    // the lagged words in [1]-[55]; [0] is unused
    s32 seed;
    // The next sample as a ratio in [0, 1).
    f32 next_ratio();
    // Subtracts the next samples from `len` bytes of words.
    void apply_rng_cipher(u32 *data, s32 len);
    // Moves each 256-byte block's bytes to the positions of subtractive_rng_make_shuffle's permutation.
    void permute_save_blocks(const u8 *source, u8 *destination, u32 size);
    // XORs the next samples into `len` bytes of big-endian words.
    void crypt_data_be(u32 *data, s32 len);
};
LAYOUT_ASSERT(SubtractiveRng_size, sizeof(SubtractiveRng) == 0xE8);

extern "C" {
void subtractive_rng_seed(SubtractiveRng *rng, s32 seed);
void subtractive_rng_refill(SubtractiveRng *rng);
u32 subtractive_rng_next(SubtractiveRng *rng);
u16 subtractive_rng_range(SubtractiveRng *rng, u16 x);
void subtractive_rng_make_shuffle(SubtractiveRng *rng);
void subtractive_rng_unshuffle(SubtractiveRng *rng, const u8 *source, u8 *destination, u32 size);
void subtractive_rng_xor_buffer(SubtractiveRng *rng, u32 *data, s32 len);
}

#endif
