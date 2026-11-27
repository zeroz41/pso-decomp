#include "pso/system/TLanguage.h"
#include "pso/ui/chat/SymbolChatPreset.h"
#include "types.h"
#include "pso/ui/chat/TSymbolChatCapture.h"
#include "pso/ui/chat/SymbolChatCommand.h"
#include "pso/ui/chat/TWindowSubSymbolChat.h"
#include "pso/network/TLobby.h"
#include "pso/object/base/TObjBase.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/TObjPlayer.h"
#include "pso/network/client_id.h"
#include "pso/network/protocol/subcmd_6x.h"


SymbolChatPreset symbol_chat_receive_buffer;

extern "C" {
const char *get_technique_name(s32 id) {
    return text_language_group_table[4][id];
}
}
void handle_6x07_symbol_chat(G_SymbolChat_6x07 *command) {
    SymbolChatPayload *p;
    TObjPlayer *player;
    command->bswap();
    p = &command->data;
    player = get_player_by_client_id(command->client_id);
    if (player != NULL) {
        capture_slot_symbol_chat(command->client_id, p);
        TWindowCtrl::open_balloon(player->get_entity_id(), (u8 *)p, 2, local_client_id);
        if (p->appearance & 0x200) {
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
SymbolChatPayload *TLobby::copy_symbol_chat_entry(SymbolChatPayload *dst, SymbolChatPayload *src) {
    *dst = *src;
    return dst;
}
