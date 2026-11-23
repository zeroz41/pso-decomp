#include "types.h"
#include "pso/unk/TLobby_80134DA0.h"
#include "pso/unk/TLobby.h"
#include "pso/network/TProtocol.h"

extern "C" {

s32 set_clock_offset_from_server_time();
int fn_800779A0(void*);
int TAdSinglePlyChrSelectGC__sub_80077AE8(void*);
int init_once__6TLobbyFl(void*);

void set_lobby_event_theme(int theme) { TLobby::event_theme_id = theme; }

int init_once__6TLobbyFPv(void* p) { return init_once__6TLobbyFl(p); }
int TLobby__sub_80134DC8(void* p) { return fn_800779A0(p); }
int TLobby__sub_80134DE8(void* p) { return TAdSinglePlyChrSelectGC__sub_80077AE8(p); }


void TLobby::reset_lobby_state() {
    set_clock_offset_from_server_time();
    protocol_instance->send_server_time_accepted();
}

}
