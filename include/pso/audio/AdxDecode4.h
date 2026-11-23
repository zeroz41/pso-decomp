#ifndef PSO_AUDIO_ADXDECODE4_H
#define PSO_AUDIO_ADXDECODE4_H

#include "types.h"

struct AdxFrame {
    s16 scale;
    s8 nibbles[16];
};

// --- C functions defined in AdxDecode4.cpp ---
extern "C" {
s32 decode_adx_mono_blocks(s8 *src, s32 nblk, s16 *out, s16 *dly, s16 k0, s16 k1);
}
// --- end of C functions

#endif
