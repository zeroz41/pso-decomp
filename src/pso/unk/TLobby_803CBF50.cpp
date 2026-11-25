#include "types.h"
#include "pso/unk/TLobby_803CBF50.h"
#include "pso/network/TLobby.h"
#include "pso/audio/GcrnaStream.h"
#include "pso/audio/GcrnaBufferQuery.h"
#include "pso/audio/GcrnaChannelBridge.h"

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

void TLobby::run_sequence() {
    update_active_streams();
}

s32 TLobby__sub_803CBFF0(GcrnaStream *stream) {
    return get_packet_size(stream);
}

s32 query_available_size(GcrnaStream *stream) {
    return get_available_size(stream);
}

void TLobby__sub_803CC030(GcrnaStream *stream, s32 enabled) {
    GCRNA_SetPlaySw(stream, enabled);
}

void TLobby::dispatch_packet(GcrnaStream *stream, s32 enabled) {
    GCRNA_SetTransSw(stream, enabled);
}

}
