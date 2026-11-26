#ifndef PSO_AUDIO_ADXUIBRIDGE_H
#define PSO_AUDIO_ADXUIBRIDGE_H

#include "types.h"
#include "pso/audio/AdxRnaStreamId.h"

struct GcrnaStream;

struct AdxUiBridgeTarget {
    u8 pad_00[0x0C];
    GcrnaStream *stream;
};

extern "C" {
void VIWaitForRetrace(void);
// Runs the SVM group 4 server callbacks.
void flush_input(void);
void gcrna_bridge_init_buffers(void);
void adx_bridge_set_loop_flag(AdxUiBridgeTarget *bridge, s32 enabled);
s32 adx_ui_bridge_get_stream_id(AdxUiBridgeTarget *bridge, s32 channel);
}

#endif
