#ifndef PSO_AUDIO_GCRNA_BRIDGE_H
#define PSO_AUDIO_GCRNA_BRIDGE_H

#include "types.h"
#include "pso/audio/GcrnaError.h"

struct GcrnaStream;
struct SjRingBuffer;

extern "C" {
void TLobby__sub_803CBF50(GcrnaStream *stream, s32 ch, s32 pan);
void trigger_sub_task(GcrnaStream *stream, s32 volume);
void TLobby__sub_803CBF90(GcrnaStream *stream, s32 rate);
void TLobby__sub_803CBFB0(GcrnaStream *stream, s32 stream_count);
s32 TLobby__sub_803CBFF0(GcrnaStream *stream);
s32 query_available_size(GcrnaStream *stream);
void TLobby__sub_803CC030(GcrnaStream *stream, s32 enabled);
void gcrna_bridge_update_streams(void);
void gcrna_bridge_set_trans_sw(GcrnaStream *stream, s32 enabled);
GcrnaStream *gcrna_bridge_create(SjRingBuffer **inputs, s32 channels);
void gcrna_bridge_set_error_callback(GcrnaErrorCallback callback, void *context);
void gcrna_bridge_shutdown(void);
void TLobby__sub_803CC114(void);
}

#endif
