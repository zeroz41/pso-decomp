#include "types.h"
#include "pso/unk/TLobby.h"
struct TAdScrollWinGC;
#include "pso/player/TObjPlayer.h"

#include "pso/ui/frontend/TAdEnterSerialAccessGC.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

void clear_state(void);
extern "C" {
int get_instance__15TAdPlayerLoadGCFv(void*);
s32 get_option_field_C__17TWindowOptionCtrlFv();

void *__nw__7TObjectFUl(int);
void *TAdScrollWinGC__ct(TAdScrollWinGC *arg0, void *arg1, s32 arg2, s32 arg3);
s32 strncpy(void *, s32, s32);
extern u8 lobby_scroll_text_buffer[];
extern s32 TLobby__data_805D5594;
extern void *lobby_scroll_text_window;
extern s32 tl_window;
void on_game_player_add__6TLobbyFiii();
void handle_game_join__6TLobbyFPv();

extern s32 TLobby__protocol_instance;

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
        TAdEnterSerialAccessGC::store_serial_access_key(TLobby__protocol_instance + 0x3F8A, TLobby__protocol_instance + 0x3F9B, TLobby__protocol_instance + 0x3F3A);
        return;
    case 2:
        TAdEnterSerialAccessGC::clear_serial_buffer();
        return;
    }
}

void TLobby::open_scroll_text_window(s32 arg0) {
    void *obj;
    if (lobby_scroll_text_window == 0) {
        strncpy(lobby_scroll_text_buffer, arg0, 0x1000);
        lobby_scroll_text_buffer[0xFFF] = 0;
        obj = __nw__7TObjectFUl(0x54);
        if (obj != 0) {
            obj = TAdScrollWinGC__ct((TAdScrollWinGC *)obj, (void *)tl_window, 2, (s32)lobby_scroll_text_buffer);
        }
        lobby_scroll_text_window = obj;
    }
    TLobby__data_805D5594 = 0x1A;
}

void TLobby::render() { { (void)(get_instance__15TAdPlayerLoadGCFv(this)); return; } }

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
void TLobby::copy_player_record(u8 *arg1) {
    *(s32 *)&this->m_name = (s32) *(s32 *)((s8 *)arg1 + 0);
    *(ByteBlock_100 *)((s32) ((u8 *)this) + 4) = *(const ByteBlock_100 *)((s32) arg1 + 4);
    *(u16 *)((s8 *)((u8 *)this) + 0x104) = (u16) *(u16 *)((s8 *)arg1 + 0x104);
    *(u16 *)((s8 *)((u8 *)this) + 0x106) = (u16) *(u16 *)((s8 *)arg1 + 0x106);
    *(u16 *)((s8 *)((u8 *)this) + 0x108) = (u16) *(u16 *)((s8 *)arg1 + 0x108);
    *(u16 *)((s8 *)((u8 *)this) + 0x10A) = (u16) *(u16 *)((s8 *)arg1 + 0x10A);
    *(u16 *)((s8 *)((u8 *)this) + 0x10C) = (u16) *(u16 *)((s8 *)arg1 + 0x10C);
    *(u16 *)((s8 *)((u8 *)this) + 0x10E) = (u16) *(u16 *)((s8 *)arg1 + 0x10E);
    *(u16 *)((s8 *)((u8 *)this) + 0x110) = (u16) *(u16 *)((s8 *)arg1 + 0x110);
    *(u16 *)((s8 *)((u8 *)this) + 0x112) = (u16) *(u16 *)((s8 *)arg1 + 0x112);
    *(s32 *)((s8 *)((u8 *)this) + 0x114) = (s32) *(s32 *)((s8 *)arg1 + 0x114);
    *(s32 *)((s8 *)((u8 *)this) + 0x118) = (s32) *(s32 *)((s8 *)arg1 + 0x118);
}

struct Ent_80134C44 { u8 pad[4]; u32 key; u32 val; };
struct Obj_80134C44 { u8 pad0; u8 count; u8 pad2[2]; Ent_80134C44 e[1]; };
void* get_player_by_client_id(s32);
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

extern s32 TLobby__net_session_mode;

s32 TLobby::get_option_state() {

    switch (get_option_field_C__17TWindowOptionCtrlFv()) {
    case 0:
        return TLobby__net_session_mode;
    case 1:
        return 0;
    case 2:
        return 1;
    default:
        return 0;
    }
}

void TLobby::install_game_join_handlers() {
    *(void (**)())(TLobby__protocol_instance + 0xBC04) = handle_game_join__6TLobbyFPv;
    *(void (**)())(TLobby__protocol_instance + 0xBC18) = on_game_player_add__6TLobbyFiii;
}
}
