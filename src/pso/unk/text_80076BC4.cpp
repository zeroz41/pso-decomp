#include "pso/system/CharacterSaveRecordLookup.h"
#include "types.h"
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

struct SubmitChatTextTag { u32 a; u32 b; };

extern "C" {
void send_chat__9TProtocolFR16TPlyGuildCardTagPc(void *, TPlyGuildCardTag *, u8 *);

char *fn_80076BC4(s32 *text) { return (char *)text; }
}
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

extern "C" {
void TAdSinglePlyChrSelectGC__sub_80076DF4(void* p, void* q);
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
        TWindowSubSymbolChat::send_selected_symbol_chat((s32 *)((s8 *)submission + 4));
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

void send_chat_shortcut(void) { ((int (*)()) get_chat_shortcut)(); ((int (*)()) chat_accept_submission)(); }

#pragma inline_depth(1)
#pragma auto_inline on
#pragma dont_inline off

extern "C" {

void clear_chat_shortcut(s32 i) {
    void **p = ((void **)get_chat_shortcut(i));
    *p = 0;
}
}
s32 store_chat_shortcut(s32 index, s32 src) { return TAdSinglePlyChrSelectGC__sub_80076D9C(((s32)get_chat_shortcut(index)), src); }

saddr TAdSinglePlyChrSelectGC__sub_80076D9C(saddr dst, saddr src) {
    TAdSinglePlyChrSelectGC__sub_80076DF4((void*)dst, (void*)src);
    ((ChatShortcutRecordCopy *)dst)->body = ((const ChatShortcutRecordCopy *)src)->body;
    return dst;
}

void TAdSinglePlyChrSelectGC__sub_80076DF4(void* p, void* q) { *(u32*)((char*)p + 0x0) = *(u32*)((char*)q + 0x0); }

bool is_chat_shortcut_set(s32 index) {
    return *((s32 *)get_chat_shortcut(index)) != 0;
}
typedef struct { u8 b[0x54]; } Rec_80076E2C;
saddr get_chat_shortcut(s32 index) {
    u8 *p = (u8 *)((Rec_80076E2C *)get_character_save_record(0xFFFF) + index);
    return (saddr)(p + 0x19C0);
}
