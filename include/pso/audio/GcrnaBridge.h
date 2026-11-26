#ifndef PSO_AUDIO_GCRNA_BRIDGE_H
#define PSO_AUDIO_GCRNA_BRIDGE_H

#include "types.h"
#include "pso/audio/GcrnaError.h"

struct GcrnaStream;
struct SjRingBuffer;

extern "C" {
void gcrna_bridge_set_channel_pan(GcrnaStream *stream, s32 ch, s32 pan);
void gcrna_bridge_set_volume(GcrnaStream *stream, s32 volume);
void gcrna_bridge_set_frequency(GcrnaStream *stream, s32 rate);
void gcrna_bridge_set_stream_count(GcrnaStream *stream, s32 stream_count);
s32 gcrna_bridge_get_packet_size(GcrnaStream *stream);
s32 query_available_size(GcrnaStream *stream);
void gcrna_bridge_set_play_sw(GcrnaStream *stream, s32 enabled);
void gcrna_bridge_update_streams(void);
void gcrna_bridge_set_trans_sw(GcrnaStream *stream, s32 enabled);
GcrnaStream *gcrna_bridge_create(SjRingBuffer **inputs, s32 channels);
void gcrna_bridge_set_error_callback(GcrnaErrorCallback callback, void *context);
void gcrna_bridge_shutdown(void);
void gcrna_bridge_initialize(void);
}

#endif
