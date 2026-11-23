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

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

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
    data_805D5594 = 0x1A;
}

void TLobby::render() { { (void)(TAdPlayerLoadGC::get_instance()); return; } }

struct E_80134B58 { u8 d[0x11C]; };
struct In_80134B58 { u32 type; u8 rest[0x118]; };
extern E_80134B58 lobby_player_status_records[];
void TLobby::copy_player_records(s32 arg1) {
    In_80134B58 *arg0 = (In_80134B58 *)this;
    s32 i;
    for (i = 0; i < arg1; i++) {
        if (arg0[i].type > 0xC) {
            return;
        }
        ((TLobby *)((u8 *)&lobby_player_status_records[arg0[i].type]))->copy_player_record((u8 *)&arg0[i]);
    }
}

struct ByteBlock_100 { u8 bytes[0x100]; };
void TLobby::copy_player_record(u8 *challenge) {
    *(s32 *)&this->m_name = (s32) *(s32 *)((s8 *)challenge + 0);
    *(ByteBlock_100 *)((saddr) ((u8 *)this) + 4) = *(const ByteBlock_100 *)((saddr) challenge + 4);
    *(u16 *)((s8 *)((u8 *)this) + 0x104) = (u16) *(u16 *)((s8 *)challenge + 0x104);
    *(u16 *)((s8 *)((u8 *)this) + 0x106) = (u16) *(u16 *)((s8 *)challenge + 0x106);
    *(u16 *)((s8 *)((u8 *)this) + 0x108) = (u16) *(u16 *)((s8 *)challenge + 0x108);
    *(u16 *)((s8 *)((u8 *)this) + 0x10A) = (u16) *(u16 *)((s8 *)challenge + 0x10A);
    *(u16 *)((s8 *)((u8 *)this) + 0x10C) = (u16) *(u16 *)((s8 *)challenge + 0x10C);
    *(u16 *)((s8 *)((u8 *)this) + 0x10E) = (u16) *(u16 *)((s8 *)challenge + 0x10E);
    *(u16 *)((s8 *)((u8 *)this) + 0x110) = (u16) *(u16 *)((s8 *)challenge + 0x110);
    *(u16 *)((s8 *)((u8 *)this) + 0x112) = (u16) *(u16 *)((s8 *)challenge + 0x112);
    *(s32 *)((s8 *)((u8 *)this) + 0x114) = (s32) *(s32 *)((s8 *)challenge + 0x114);
    *(s32 *)((s8 *)((u8 *)this) + 0x118) = (s32) *(s32 *)((s8 *)challenge + 0x118);
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
