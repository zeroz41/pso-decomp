#include "types.h"
#include "pso/unk/TLobby_803CBF50.h"
#include "pso/unk/TLobby.h"

extern "C" {

s32 set_sound_stream_volume();
s32 TLobby__sub_803D4704();
s32 GCRNA_SetPlaySw();
s32 GCRNA_SetTransSw();

void TLobby__sub_803CBF50(TLobby *stream, s32 ch, s32 pan) {
    stream->set_stream_channel_pan(ch, pan);
}

void TLobby::trigger_sub_task() {
    set_sound_stream_volume();
}

void TLobby__sub_803CBF90(TLobby *stream, s32 rate) {
    stream->set_stream_frequency(rate);
}

void TLobby__sub_803CBFB0(void) {
    TLobby__sub_803D4704();
}

void TLobby::run_sequence() {
    TLobby::update_active_streams();
}

s32 TLobby__sub_803CBFF0(TLobby *stream) {
    return stream->get_packet_size();
}

s32 TLobby::query_available_size() {
    return get_available_size();
}

void TLobby__sub_803CC030(void) {
    GCRNA_SetPlaySw();
}

void TLobby::dispatch_packet() {
    GCRNA_SetTransSw();
}

}
