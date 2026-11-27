#include "pso/system/CharacterSaveRecordLookup.h"
#include "types.h"
#include "pso/ui/chat/ChatShortcuts.h"
#include "pso/network/TLobby.h"
#include "pso/network/TProtocol.h"
#include "pso/player/TPlyGuildCardTag.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/WordSelectMessage.h"
#include "pso/ui/chat/TWindowSubSymbolChat.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"
#include "pso/network/client_id.h"
#include "pso/ui/chat/ChatShortcuts.h"


char *get_chat_shortcut_text(s32 *text) { return (char *)text; }
void submit_chat_text(char *text) {
    TObjBase *player;
    player = (TObjBase *)get_player_by_client_id(local_client_id);
    if (player != NULL && *text != 0) {
        ((TLobby *)text)->capture_chat_sensor();
        if (get_main_phase() == 0xF) {
            const TPlyGuildCardTag &made = TPlyGuildCardTag(0, 0);
            SubmitChatTextTag tmp = *(SubmitChatTextTag *)&made;
            TLobby::protocol_instance->send_chat(*(TPlyGuildCardTag *)&tmp, text);
        } else {
            TWindowCtrl::open(player->get_entity_id(), text, 0xCB);
        }
    }
}

void chat_dispatch_accepted_result(ChatShortcut *submission) {

    switch (submission->kind.value) {
    case 1:
        submit_chat_text(submission->body.text);
        return;
    case 2:
        G_WordSelect_6x74::send_message(&submission->body.message);
        return;
    case 3:
        send_selected_symbol_chat(&submission->body.symbol_chat_preset);
    case 0:
        return;
    }
}
s32 chat_accept_submission(ChatShortcut *submission) {
    if (TWindowCtrl::is_submit_cooldown_clear() == 0) {
        return 0;
    }
    TWindowCtrl::start_submit_cooldown();
    chat_dispatch_accepted_result(submission);
    return 1;
}

void send_chat_shortcut(s32 index) { chat_accept_submission(get_chat_shortcut(index)); }

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

s32 is_chat_shortcut_set(s32 index) {
    if (get_chat_shortcut(index)->kind.value != 0) {
        return 1;
    }
    return 0;
}
ChatShortcut *get_chat_shortcut(s32 index) {
    u8 *p = (u8 *)((ChatShortcut *)get_character_save_record(0xFFFF) + index);
    return (ChatShortcut *)(p + offsetof(CharacterSaveRecord, chat_shortcuts));
}
