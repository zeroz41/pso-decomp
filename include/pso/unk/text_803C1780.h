#ifndef PSO_UNK_TEXT_803C1780_H
#define PSO_UNK_TEXT_803C1780_H

#include "types.h"

extern "C" {
s32 adx_parse_wav_header(u8 *buf, s32 len, s16 *data_offset, s8 *marker, s8 *bits, s8 *block_align, s8 *channels, s32 *sample_rate, s32 *sample_count, s32 *samples_per_block, s16 *encoding);
}

#endif
