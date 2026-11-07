#ifndef PSO_UNK_TEXT_803C1780_H
#define PSO_UNK_TEXT_803C1780_H

#include "types.h"

extern "C" {
void TLobby__sub_803C19D8(void);
void TLobby__sub_803C1A00(u8 *arg0, s32 arg1);
}

// --- C functions defined in text_803C1780.cpp ---
extern "C" {
void TLobby__sub_803C19D8(void);
void TLobby__sub_803C1A00(u8 *arg0, s32 arg1);
// Parses a RIFF/WAVE image of len bytes: finds the "fmt " and "data" chunks and returns the format;
// -1 when the image is not a mono/stereo PCM (16/8-bit) or 4-bit WAVE.
s32 TLobby__sub_803C1780(s32 buf, s32 len, s16 *data_offset, s8 *marker, s8 *bits, s8 *block_align, s8 *channels,
                         s32 *sample_rate, s32 *sample_count, s32 *samples_per_block, s16 *encoding);
}
// --- end of C functions

#endif
