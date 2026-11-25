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
// Decodes stereo blocks, or mixes them down to mono after adx_set_stereo_downmix(1).
s32 adx_decode_stereo_blocks(s8 *src, s32 nblk, s16 *outl, s16 *dlyl, s16 *outr, s16 *dlyr, s16 k0, s16 k1);
}
// --- end of C functions
s32 decode_adx_stereo(s8 *src, s32 nblk, s16 *outl, s16 *dlyl, s16 *outr, s16 *dlyr, s16 k0, s16 k1);
s32 decode_adx_stereo_downmix(s8 *src, s32 nblk, s16 *outl, s16 *dlyl, s16 *outr, s16 *dlyr, s16 k0, s16 k1);

extern "C" {
void adx_set_stereo_downmix(s32 mode);
}

#endif
