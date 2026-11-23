#ifndef PSO_AUDIO_GCRNACHANNELBRIDGE_H
#define PSO_AUDIO_GCRNACHANNELBRIDGE_H

#include "types.h"

struct GcrnaChannelTarget {
    u8 pad_00[0x10];
    s32 channel_count;
};

extern "C" {
void TLobby__sub_803D4704(GcrnaChannelTarget *target, s32 channel_count);
}

#endif
