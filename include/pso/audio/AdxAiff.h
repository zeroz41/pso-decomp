#ifndef PSO_AUDIO_ADXAIFF_H
#define PSO_AUDIO_ADXAIFF_H

#include "types.h"

// --- C functions defined in AdxAiff.cpp ---
extern "C" {
u8 *adx_aiff_parse_header(u8 *hdr, s32 *rate, s32 *channels, s32 *bits, s32 *frames);
}
// --- end of C functions

#endif
