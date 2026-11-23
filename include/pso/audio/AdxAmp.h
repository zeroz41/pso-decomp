#ifndef PSO_AUDIO_ADX_AMP_H
#define PSO_AUDIO_ADX_AMP_H

#include "types.h"

struct AdxAmp {
    u8 pad_00[0x20];
    s32 sfreq;
    u8 pad_24[0xC];
};
LAYOUT_ASSERT(AdxAmp_size, sizeof(AdxAmp) == 0x30);

#endif
