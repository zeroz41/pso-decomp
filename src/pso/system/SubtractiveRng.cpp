#include "pso/system/SubtractiveRng.h"
#include "types.h"
#include <string.h>
#include "pso/system/byteswap.h"

extern "C" {
u8 save_block_shuffle_permutation[256];
u8 save_block_unshuffle_permutation[256];
}

void SubtractiveRng::apply_rng_cipher(u32 *data, s32 len) {
    s32 i;
    s32 n = (len + 3) / 4;
    for (i = 0; i < n; i++) {
        data[i] = subtractive_rng_next(this) - data[i];
    }
}

extern "C" void subtractive_rng_unshuffle(SubtractiveRng *rng, const u8 *source, u8 *destination, u32 size) {
    u32 block, i;
    memcpy(destination, source, size);
    for (block = 0; block < (size >> 8); block++) {
        for (i = 0; i < 256; i++) destination[(block << 8) + save_block_unshuffle_permutation[i]] = source[(block << 8) + i];
    }
}

void SubtractiveRng::permute_save_blocks(const u8 *source, u8 *destination, u32 size) {
    u32 block, i;
    memcpy(destination, source, size);
    for (block = 0; block < (size >> 8); block++) {
        for (i = 0; i < 256; i++) destination[(block << 8) + save_block_shuffle_permutation[i]] = source[(block << 8) + i];
    }
}

extern "C" void subtractive_rng_make_shuffle(SubtractiveRng *rng) {
    s32 i;
    u16 index;
    u8 value;
    for (i = 0; i < 256; i++) save_block_shuffle_permutation[i] = (u8)i;
    for (i = 255; i >= 0; i--) {
        index = subtractive_rng_range(rng, i + 1);
        value = save_block_shuffle_permutation[index];
        save_block_shuffle_permutation[index] = save_block_shuffle_permutation[i];
        save_block_unshuffle_permutation[value] = (u8)i;
        save_block_shuffle_permutation[i] = value;
    }
}

void SubtractiveRng::crypt_data_be(u32 *data, s32 len) {
    u32 *p;
    s32 i;
    s32 n = (len + 3) / 4;
    for (i = 0; i < n; i++) {
        p = &data[i];
        bswap_32(p);
        *p ^= subtractive_rng_next(this);
        bswap_32(p);
    }
}

extern "C" void subtractive_rng_xor_buffer(SubtractiveRng *rng, u32 *data, s32 len) {
    s32 i;
    s32 n = (len + 3) / 4;
    for (i = 0; i < n; i++) {
        data[i] ^= subtractive_rng_next(rng);
    }
}

extern "C" u32 subtractive_rng_next(SubtractiveRng *rng) {
    s32 pos;
    pos = rng->pos;
    rng->pos = pos + 1;
    if (pos + 1 > 55) {
        subtractive_rng_refill(rng);
        rng->pos = 1;
    }
    return rng->table[rng->pos];
}

extern "C" void subtractive_rng_refill(SubtractiveRng *rng) {
    s32 i;
    for (i = 1; i < 25; i++) {
        rng->table[i] -= rng->table[i + 31];
    }
    for (i = 25; i < 56; i++) {
        rng->table[i] -= rng->table[i - 24];
    }
}

extern "C" void subtractive_rng_seed(SubtractiveRng *rng, s32 seed) {
    s32 idx;
    s32 prev;
    s32 i;
    rng->seed = seed;
    rng->table[55] = seed;
    prev = 1;
    for (i = 1; i < 55; i++) {
        idx = (21 * i) % 55;
        rng->table[idx] = prev;
        prev = seed - prev;
        seed = rng->table[idx];
    }
    subtractive_rng_refill(rng);
    subtractive_rng_refill(rng);
    subtractive_rng_refill(rng);
    subtractive_rng_refill(rng);
    rng->pos = 55;
}

SubtractiveRng::SubtractiveRng(u32 seed) {
    subtractive_rng_seed(this, seed);
}

SubtractiveRng::SubtractiveRng() {
    subtractive_rng_seed(this, 0);
}

extern "C" u16 subtractive_rng_range(SubtractiveRng *rng, u16 x) {
    return (x * (subtractive_rng_next(rng) >> 16)) >> 16;
}
