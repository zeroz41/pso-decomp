#include "pso/ui/chat/SymbolChatPreset.h"
#include "types.h"
#include "pso/unk/TLobby_8036B204.h"
#include "pso/unk/text_80076E84.h"
#include "pso/ui/chat/TWindowSubSymbolChat.h"
#include "pso/unk/TLobby.h"
#include "pso/object/base/TObjBase.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/player/PlayerSlots.h"

struct Pkt_80076E98 { u8 pad[4]; s32 f4; u32 f8; };

extern "C" {
extern u8 *text_language_group_table;
SymbolChatPreset symbol_chat_receive_buffer;
extern s32 local_client_id;
void handle_6x07_symbol_chat(Pkt_80076E98 *command);
s32 get_technique_name(s32 id) {
    return *(s32 *)((s8 *)(*(saddr *)((s8 *)text_language_group_table + 0x10)) + (id * 4));
}
void handle_6x07_symbol_chat(Pkt_80076E98 *command) {
    u32 *p;
    s32 ply;
    ((TWindowSubSymbolChat *)command)->bswap_symbol_chat_packet();
    p = &command->f8;
    ply = (saddr)get_player_by_client_id(command->f4);
    if (ply != 0) {
        TLobby::dispatch_by_index(command->f4, (saddr)p);
        TWindowCtrl::open_balloon(((TObjBase *)(saddr)(ply))->get_entity_id(), (u8 *)p, 2, local_client_id);
        if (*p & 0x200) {
            for (; static_cast<s8>(pending_symbol_chat_count) >= 1; pending_symbol_chat_count--) {
            }
            pending_symbol_chat_count++;
            TLobby::copy_symbol_chat_entry(symbol_chat_receive_buffer.get_data_ptr(), p);
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
