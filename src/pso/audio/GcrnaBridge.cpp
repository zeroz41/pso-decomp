#include "types.h"
#include "pso/audio/GcrnaBridgeSampleBits.h"
#include "pso/audio/GcrnaStatusBridge.h"
#include "pso/audio/GcrnaBridge.h"
#include "pso/network/TLobby.h"
#include "pso/audio/GcrnaStream.h"
#include "pso/audio/GcrnaBufferQuery.h"
#include "pso/audio/GcrnaChannelBridge.h"
#include "pso/audio/GcrnaBridgeTeardown.h"

void TLobby__sub_803CBF30(GcrnaStream *stream, s32 sample_bits) {
    gcrna_set_sample_bits(stream, sample_bits);
}

extern "C" {

void TLobby__sub_803CBF50(GcrnaStream *stream, s32 ch, s32 pan) {
    set_stream_channel_pan(stream, ch, pan);
}

void trigger_sub_task(GcrnaStream *stream, s32 volume) {
    set_sound_stream_volume(stream, volume);
}

void TLobby__sub_803CBF90(GcrnaStream *stream, s32 rate) {
    set_stream_frequency(stream, rate);
}

void TLobby__sub_803CBFB0(GcrnaStream *stream, s32 stream_count) {
    TLobby__sub_803D4704(stream, stream_count);
}

void gcrna_bridge_update_streams(void) {
    update_active_streams();
}

s32 TLobby__sub_803CBFF0(GcrnaStream *stream) {
    return get_packet_size(stream);
}

s32 query_available_size(GcrnaStream *stream) {
    return get_available_size(stream);
}

void gcrna_bridge_set_play_sw(GcrnaStream *stream, s32 enabled) {
    GCRNA_SetPlaySw(stream, enabled);
}

void gcrna_bridge_set_trans_sw(GcrnaStream *stream, s32 enabled) {
    GCRNA_SetTransSw(stream, enabled);
}

}

void unregister_si_polling(GcrnaStream *stream) {
    GCRNA_SetPlaySw(stream, 0);
    GCRNA_SetTransSw(stream, 0);
    gcrna_destroy_stream(stream);
}

GcrnaStream *gcrna_bridge_create(SjRingBuffer **inputs, s32 channels) {
    return GCRNA_Create(inputs, channels);
}

void gcrna_bridge_set_error_callback(GcrnaErrorCallback callback, void *context) {
    gcrna_set_error_callback(callback, context);
}

void gcrna_bridge_shutdown(void) {
    gcrna_shutdown();
}

void TLobby__sub_803CC114(void) {
    gcrna_initialize();
}
