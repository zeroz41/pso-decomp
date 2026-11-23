#include "types.h"
#include "pso/unk/TLobby_803CBF50.h"
#include "pso/unk/TLobby.h"
#include "pso/audio/GcrnaStream.h"

extern "C" {

s32 set_sound_stream_volume();
s32 TLobby__sub_803D4704();

void TLobby__sub_803CBF50(GcrnaStream *stream, s32 ch, s32 pan) {
    set_stream_channel_pan(stream, ch, pan);
}

void TLobby::trigger_sub_task() {
    set_sound_stream_volume();
}

void TLobby__sub_803CBF90(GcrnaStream *stream, s32 rate) {
    set_stream_frequency(stream, rate);
}

void TLobby__sub_803CBFB0(void) {
    TLobby__sub_803D4704();
}

void TLobby::run_sequence() {
    update_active_streams();
}

s32 TLobby__sub_803CBFF0(TLobby *stream) {
    return stream->get_packet_size();
}

s32 TLobby::query_available_size(TLobby *rna) {
    return rna->get_available_size();
}

void TLobby__sub_803CC030(GcrnaStream *stream, s32 enabled) {
    GCRNA_SetPlaySw(stream, enabled);
}

void TLobby::dispatch_packet(GcrnaStream *stream, s32 enabled) {
    GCRNA_SetTransSw(stream, enabled);
}

}
