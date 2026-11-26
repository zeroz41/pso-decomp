#include "types.h"
#include "pso/audio/GcrnaBridgeSampleBits.h"
#include "pso/audio/GcrnaStatusBridge.h"
#include "pso/audio/GcrnaBridge.h"
#include "pso/network/TLobby.h"
#include "pso/audio/GcrnaStream.h"
#include "pso/audio/GcrnaBufferQuery.h"
#include "pso/audio/GcrnaChannelBridge.h"
#include "pso/audio/GcrnaBridgeTeardown.h"

void gcrna_bridge_set_sample_bits(GcrnaStream *stream, s32 sample_bits) {
    gcrna_set_sample_bits(stream, sample_bits);
}

extern "C" {

void gcrna_bridge_set_channel_pan(GcrnaStream *stream, s32 ch, s32 pan) {
    set_stream_channel_pan(stream, ch, pan);
}

void gcrna_bridge_set_volume(GcrnaStream *stream, s32 volume) {
    set_sound_stream_volume(stream, volume);
}

void gcrna_bridge_set_frequency(GcrnaStream *stream, s32 rate) {
    set_stream_frequency(stream, rate);
}

void gcrna_bridge_set_stream_count(GcrnaStream *stream, s32 stream_count) {
    gcrna_set_stream_count(stream, stream_count);
}

void gcrna_bridge_update_streams(void) {
    update_active_streams();
}

s32 gcrna_bridge_get_packet_size(GcrnaStream *stream) {
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

void gcrna_bridge_destroy(GcrnaStream *stream) {
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

void gcrna_bridge_initialize(void) {
    gcrna_initialize();
}
