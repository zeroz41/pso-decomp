#include "pso/ui/chat/SymbolChatPreset.h"
#include "types.h"
#include "pso/unk/TLobby_8036B204.h"
#include "pso/unk/text_80076E84.h"
#include "pso/ui/chat/TWindowSubSymbolChat.h"
#include "pso/network/TLobby.h"
#include "pso/object/base/TObjBase.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/player/PlayerSlots.h"
#include "pso/network/client_id.h"

struct Handle6x07SymbolChatPacket { u8 pad[4]; s32 f4; u32 f8; };

SymbolChatPreset symbol_chat_receive_buffer;

extern "C" {
extern u8 *text_language_group_table;
void handle_6x07_symbol_chat(Handle6x07SymbolChatPacket *command);
s32 get_technique_name(s32 id) {
    return *(s32 *)((s8 *)(*(saddr *)((s8 *)text_language_group_table + 0x10)) + (id * 4));
}
void handle_6x07_symbol_chat(Handle6x07SymbolChatPacket *command) {
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
struct Handle6x07SymbolChatSymBody { u32 w[12]; };
struct Handle6x07SymbolChatSymPair { u32 b; u32 c; };
struct CopySymbolChatEntrySym { u32 a; Handle6x07SymbolChatSymPair mid; Handle6x07SymbolChatSymBody body; };
void *TLobby::copy_symbol_chat_entry(void *dst, void *src) {
    *(CopySymbolChatEntrySym *)dst = *(CopySymbolChatEntrySym *)src;
    return dst;
}

}
