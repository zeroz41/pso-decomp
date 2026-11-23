#ifndef PSO_AUDIO_GCRNASTATUSBRIDGE_H
#define PSO_AUDIO_GCRNASTATUSBRIDGE_H

#include "types.h"

struct GcrnaSampleBitsTarget {
    u8 pad_00[0x18];
    s32 sample_bits;
};

extern "C" {
s32 gcrna_bridge_is_ready(void);
s32 gcrna_bridge_get_status(void);
void gcrna_set_sample_bits(GcrnaSampleBitsTarget *target, s32 sample_bits);
}

#endif
