#include "pso/system/CharacterSaveRecordLookup.h"
#include "types.h"
#include "pso/unk/text_80076BC4.h"
#include "pso/network/TLobby.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/WordSelectMessage.h"
#include "pso/ui/chat/TWindowSubSymbolChat.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"
#include "pso/network/client_id.h"
#include "pso/unk/text_80076BC4.h"

struct TPlyGuildCardTag { u32 a; u32 b; TPlyGuildCardTag(u16, u32); };


extern "C" {
void send_chat__9TProtocolFR16TPlyGuildCardTagPc(void *, TPlyGuildCardTag *, u8 *);
}

char *get_chat_shortcut_text(s32 *text) { return (char *)text; }
void submit_chat_text(u8 *lobby) {
    void *player;
    player = get_player_by_client_id(local_client_id);
    if (player != NULL && (s8) *lobby != 0) {
        ((TLobby *)lobby)->capture_chat_sensor();
        if (get_main_phase() == 0xF) {
            const TPlyGuildCardTag &made = TPlyGuildCardTag(0, 0);
            SubmitChatTextTag tmp = *(SubmitChatTextTag *)&made;
            send_chat__9TProtocolFR16TPlyGuildCardTagPc(TLobby::protocol_instance, (TPlyGuildCardTag *)&tmp, lobby);
        } else {
            TWindowCtrl::open(((TObjBase *)(player))->get_entity_id(), (const char *)lobby, 0xCB);
        }
    }
}

void chat_dispatch_accepted_result(s32 *submission) {

    switch (*submission) {
    case 1:
        ((s32 (*)(void *)) submit_chat_text)((s8 *)submission + 4);
        return;
    case 2:
        G_WordSelect_6x74::send_message((WordSelectMessage *)((s8 *)submission + 4));
        return;
    case 3:
        send_selected_symbol_chat((s32 *)((s8 *)submission + 4));
    case 0:
        return;
    }
}
s32 chat_accept_submission(saddr submission) {
    if (TWindowCtrl::is_submit_cooldown_clear() == 0) {
        return 0;
    }
    TWindowCtrl::start_submit_cooldown();
    chat_dispatch_accepted_result((s32 *)submission);
    return 1;
}

void send_chat_shortcut(s32 index) { chat_accept_submission((saddr)get_chat_shortcut(index)); }

#pragma inline_depth(1)
#pragma auto_inline on
#pragma dont_inline off

void clear_chat_shortcut(s32 i) {
    void **p = ((void **)get_chat_shortcut(i));
    *p = 0;
}
ChatShortcut *store_chat_shortcut(s32 index, const ChatShortcut *src) { return &(*get_chat_shortcut(index) = *src); }

ChatShortcut &ChatShortcut::operator=(const ChatShortcut &src) {
    kind = src.kind;
    body = src.body;
    return *this;
}

ChatShortcutKind &ChatShortcutKind::operator=(const ChatShortcutKind &src) {
    value = src.value;
    return *this;
}

bool is_chat_shortcut_set(s32 index) {
    return get_chat_shortcut(index)->kind.value != 0;
}
ChatShortcut *get_chat_shortcut(s32 index) {
    u8 *p = (u8 *)((ChatShortcut *)get_character_save_record(0xFFFF) + index);
    return (ChatShortcut *)(p + offsetof(CharacterSaveRecord, chat_shortcuts));
}
