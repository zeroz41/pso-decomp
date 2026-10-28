#include "types.h"
#include "pso/unk/text_80076E84.h"
#include "pso/misc/TWindowSubSymbolChat.h"

struct Pkt_80076E98 { u8 pad[4]; s32 f4; u32 f8; };

extern "C" {
extern u8 *text_language_group_table;
s32 get_entity_id(s32);
void *get_player_by_client_id(s32 i);
void open_balloon__11TWindowCtrlFUsPUcll(s32, void *, s32, s32);
void dispatch_by_index__6TLobbyFUsi(u16 arg0, s32 src);
extern u8 symbol_chat_receive_buffer[];
extern s8 pending_symbol_chat_count;
extern s32 local_client_id;
void handle_6x07_symbol_chat(Pkt_80076E98 *arg0);
s32 get_technique_name(s32 arg0) {
    return *(s32 *)((s8 *)(*(s32 *)((s8 *)text_language_group_table + 0x10)) + (arg0 * 4));
}
void handle_6x07_symbol_chat(Pkt_80076E98 *arg0) {
    u32 *p;
    s32 ply;
    ((TWindowSubSymbolChat *)arg0)->bswap_symbol_chat_packet();
    p = &arg0->f8;
    ply = (s32)get_player_by_client_id(arg0->f4);
    if (ply != 0) {
        dispatch_by_index__6TLobbyFUsi(arg0->f4, (s32)p);
        open_balloon__11TWindowCtrlFUsPUcll(get_entity_id(ply), p, 2, local_client_id);
        if (*p & 0x200) {
            for (; pending_symbol_chat_count >= 1; pending_symbol_chat_count--) {
            }
            pending_symbol_chat_count++;
            copy_symbol_chat_entry__6TLobbyFPvPv(((TWindowSubSymbolChat *)symbol_chat_receive_buffer)->get_data_ptr(), p);
        }
    }
}
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct SymBody_80076F48 { u32 w[12]; };
struct SymPair_80076F48 { u32 b; u32 c; };
struct Sym_80076F48 { u32 a; SymPair_80076F48 mid; SymBody_80076F48 body; };
void *copy_symbol_chat_entry__6TLobbyFPvPv(void *dst, void *src) {
    *(Sym_80076F48 *)dst = *(Sym_80076F48 *)src;
    return dst;
}

}
