#ifndef PSO_AUDIO_ADXAIFF_H
#define PSO_AUDIO_ADXAIFF_H

#include "types.h"

// --- C functions defined in AdxAiff.cpp ---
extern "C" {
u8 *adx_aiff_parse_header(u8 *hdr, s32 *rate, s32 *channels, s32 *bits, s32 *frames);
}
// --- end of C functions

extern "C" {
s32 parse_wav_header_info(u8 *buf, s32 len, s16 *data_offset, s8 *marker, s8 *bits, s8 *block_align, s8 *channels, s32 *sample_rate, s32 *sample_count, s32 *samples_per_block, s16 *encoding);
}

#endif
