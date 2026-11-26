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
    // Moves each 256-byte block's bytes to the positions of make_shuffle's permutation.
    void permute_save_blocks(const u8 *source, u8 *destination, u32 size);
    // XORs the next samples into `len` bytes of big-endian words.
    void crypt_data_be(u32 *data, s32 len);
    // Seeds the table from `seed` and stirs it four times.
    void set_seed(s32 seed);
    // Stirs the lagged table: each word subtracts the word 24 places behind it.
    void refill();
    // The next sample; refills the table every 55 samples.
    u32 next();
    // A sample scaled to [0, x).
    u16 range(u16 x);
    // Builds the save-block byte permutation and its inverse from the next samples.
    void make_shuffle();
    // Moves each 256-byte block's bytes back through make_shuffle's inverse permutation.
    void unshuffle(const u8 *source, u8 *destination, u32 size);
    // XORs the next samples into `len` bytes of words.
    void xor_buffer(u32 *data, s32 len);
};
LAYOUT_ASSERT(SubtractiveRng_size, sizeof(SubtractiveRng) == 0xE8);

#endif
