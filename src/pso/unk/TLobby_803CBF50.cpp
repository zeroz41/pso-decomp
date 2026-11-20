#include "types.h"
#include "pso/unk/TLobby_803CBF50.h"
#include "pso/unk/TLobby.h"
#include "pso/audio/GcrnaStream.h"

extern "C" {

s32 set_stream_channel_pan__6TLobbyFll();
s32 set_sound_stream_volume();
s32 set_stream_frequency__6TLobbyFl();
s32 TLobby__sub_803D4704();
s32 get_packet_size__6TLobbyFv();

void TLobby__sub_803CBF50(void) {
    set_stream_channel_pan__6TLobbyFll();
}

void TLobby::trigger_sub_task() {
    set_sound_stream_volume();
}

void TLobby__sub_803CBF90(void) {
    set_stream_frequency__6TLobbyFl();
}

void TLobby__sub_803CBFB0(void) {
    TLobby__sub_803D4704();
}

void TLobby::run_sequence() {
    TLobby::update_active_streams();
}

void TLobby__sub_803CBFF0(void) {
    get_packet_size__6TLobbyFv();
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
