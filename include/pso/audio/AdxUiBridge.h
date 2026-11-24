#ifndef PSO_AUDIO_ADXUIBRIDGE_H
#define PSO_AUDIO_ADXUIBRIDGE_H

#include "types.h"
#include "pso/audio/AdxRnaStreamId.h"

struct GcrnaLoopTarget;

struct AdxUiBridgeTarget {
    u8 pad_00[0x0C];
    GcrnaLoopTarget *target;
};

extern "C" {
void VIWaitForRetrace(void);
void TLobby__sub_803CBE20(void);
void adx_bridge_set_loop_flag(AdxUiBridgeTarget *bridge, s32 enabled);
void TLobby__sub_803CBE64(AdxUiBridgeTarget *bridge);
}

#endif
