#include "types.h"
#include <string.h>
#include "pso/unk/TLobby.h"
#include "pso/network/TProtocol.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/frontend/TAdScrollWinGC.h"
#include "pso/player/TObjPlayer.h"

#include "pso/ui/frontend/TAdEnterSerialAccessGC.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/player/PlayerSlots.h"
#include "pso/unk/TLobby_801461EC.h"

void clear_state(void);
extern "C" {

extern u8 lobby_scroll_text_buffer[];
extern void *lobby_scroll_text_window;


void TLobby::dispatch_by_index(s32 arg0) {
    s32 var_r3;

    var_r3 = arg0;
    if ((var_r3 > 3) || (var_r3 < 0)) {
        var_r3 = 0;
    }
    switch (var_r3) {
    case 0:
        clear_state();
        return;
    case 1:
        TAdEnterSerialAccessGC::store_serial_access_key((saddr)protocol_instance->m_serial_number2, (saddr)protocol_instance->m_access_key2, (saddr)protocol_instance->m_password);
        return;
    case 2:
        TAdEnterSerialAccessGC::clear_serial_buffer();
        return;
    }
}

void TLobby::open_scroll_text_window(saddr src) {
    void *obj;
    if (lobby_scroll_text_window == 0) {
        strncpy((char *)lobby_scroll_text_buffer, (const char *)src, 0x1000);
        lobby_scroll_text_buffer[0xFFF] = 0;
        lobby_scroll_text_window = new TAdScrollWinGC(tl_window, 2, (saddr)lobby_scroll_text_buffer);
    }
    lobby_state = 0x1A;
}

void TLobby::render() { { (void)(TAdPlayerLoadGC::get_instance()); return; } }

extern TPlyChallenge lobby_player_status_records[12];

// C5: the server's player records for the lobby.
void TLobby::copy_player_records(TPlyChallenge *records, s32 count) {
    for (s32 i = 0; i < count; i++) {
        if (records[i].client_id > 12) {
            return;
        }
        lobby_player_status_records[records[i].client_id] = records[i];
    }
}

struct Ent_80134C44 { u8 pad[4]; u32 key; u32 val; };
struct Obj_80134C44 { u8 pad0; u8 count; u8 pad2[2]; Ent_80134C44 e[1]; };
void TLobby::apply_lobby_markers() {
    Obj_80134C44 *o = (Obj_80134C44 *)this;
    Ent_80134C44 *e = o->e;
    s32 i;
    for (i = 0; i < o->count; i++, e++) {
        s32 j;
        for (j = 0; j < 12; j++) {
            u8 *p = (u8*)get_player_by_client_id(j);
            if (p != NULL && *(u32*)(p + 0xDB0) == e->key) {
                ((TObjPlayer *)p)->set_lobby_marker((u8)e->val);
            }
        }
    }
}


s32 TLobby::get_option_state() {

    switch (TWindowOptionCtrl::get_option_field_C()) {
    case 0:
        return net_session_mode;
    case 1:
        return 0;
    case 2:
        return 1;
    default:
        return 0;
    }
}

void TLobby::install_game_join_handlers() {
    protocol_instance->m_recv_handlers.handle_64_recv_start_game3 = (recv_packet_handler_handle_64_recv_start_game3)TLobby::handle_game_join;
    protocol_instance->m_recv_handlers.handle_65_recv_burst_game = TLobby::on_game_player_add;
}
}
