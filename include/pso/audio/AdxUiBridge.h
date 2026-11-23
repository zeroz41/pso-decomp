#ifndef PSO_AUDIO_ADXUIBRIDGE_H
#define PSO_AUDIO_ADXUIBRIDGE_H

#include "types.h"
#include "pso/audio/AdxRnaStreamId.h"

struct TLobby;

struct AdxUiBridgeTarget {
    u8 pad_00[0x0C];
    TLobby *target;
};

extern "C" {
void VIWaitForRetrace(void);
void TLobby__sub_803CBE20(void);
void adx_bridge_apply_field(AdxUiBridgeTarget *bridge);
void TLobby__sub_803CBE64(AdxUiBridgeTarget *bridge);
}

#endif
