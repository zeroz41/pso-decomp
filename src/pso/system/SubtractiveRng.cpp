#include "pso/system/SubtractiveRng.h"
#include "types.h"
#include <string.h>
#include "pso/system/byteswap.h"

extern "C" {
u8 save_block_shuffle_permutation[256];
u8 save_block_unshuffle_permutation[256];
}

void SubtractiveRng::apply_rng_cipher(void *buffer, s32 len) {
    u32 *data = (u32 *)buffer;
    s32 i;
    s32 n = (len + 3) / 4;
    for (i = 0; i < n; i++) {
        data[i] = next() - data[i];
    }
}

void SubtractiveRng::unshuffle(const u8 *source, u8 *destination, u32 size) {
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

void SubtractiveRng::make_shuffle() {
    s32 i;
    u16 index;
    u8 value;
    for (i = 0; i < 256; i++) save_block_shuffle_permutation[i] = (u8)i;
    for (i = 255; i >= 0; i--) {
        index = range(i + 1);
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
        *p ^= next();
        bswap_32(p);
    }
}

void SubtractiveRng::xor_buffer(void *buffer, s32 len) {
    u32 *data = (u32 *)buffer;
    s32 i;
    s32 n = (len + 3) / 4;
    for (i = 0; i < n; i++) {
        data[i] ^= next();
    }
}

u32 SubtractiveRng::next() {
    s32 last = pos;
    pos = last + 1;
    if (last + 1 > 55) {
        refill();
        pos = 1;
    }
    return table[pos];
}

void SubtractiveRng::refill() {
    s32 i;
    for (i = 1; i < 25; i++) {
        table[i] -= table[i + 31];
    }
    for (i = 25; i < 56; i++) {
        table[i] -= table[i - 24];
    }
}

void SubtractiveRng::set_seed(s32 seed) {
    s32 idx;
    s32 prev;
    s32 i;
    this->seed = seed;
    table[55] = seed;
    prev = 1;
    for (i = 1; i < 55; i++) {
        idx = (21 * i) % 55;
        table[idx] = prev;
        prev = seed - prev;
        seed = table[idx];
    }
    refill();
    refill();
    refill();
    refill();
    pos = 55;
}

SubtractiveRng::SubtractiveRng(u32 seed) {
    set_seed(seed);
}

SubtractiveRng::SubtractiveRng() {
    set_seed(0);
}

u16 SubtractiveRng::range(u16 x) {
    return (x * (next() >> 16)) >> 16;
}
