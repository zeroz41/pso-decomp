#ifndef PSO_AUDIO_ADXSTREAMSCROLLOFFSET_H
#define PSO_AUDIO_ADXSTREAMSCROLLOFFSET_H

#include "types.h"

struct AdxStreamScrollState {
    u8 pad_00[0x2B0];
    s32 scroll_offset;
};

#endif
