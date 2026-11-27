#include "types.h"
#include <string.h>
#include "pso/system/CharacterSaveRecordLookup.h"
#include "pso/network/TProtocol.h"
#include "pso/network/TLobby.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/enemy/BattleParamTables.h"
#include "pso/unk/TLobbyAutoReply.h"

s32 auto_reply_flags;

void sync_auto_reply_state() {
    if ((auto_reply_flags & 4) || (auto_reply_flags & 1) != ((auto_reply_flags >> 1) & 1)) {
        if (get_flag_bit0() != 0) {
            TLobby::protocol_instance->send_text_packet_c7((char *)(get_card_window_area()));
        } else {
            TLobby::protocol_instance->send_disable_auto_reply();
        }
        auto_reply_flags &= ~4;
        auto_reply_flags = get_flag_bit0() != 0 ? (auto_reply_flags | 2) : (auto_reply_flags & ~2);
    }
}

const char *get_card_window_area() {
    return (const char *)(get_character_save_record(0xFFFF) + 0x2050);
}
void set_short_mail_text(char *text) {
    u8 *mail_text;
    mail_text = (u8 *)(get_character_save_record((0xFFFFU)) + 0x2050);
    mask_profanity_words(text, get_shared_text_buffer());
    strncpy((char *)mail_text, get_shared_text_buffer(), 0xAB);
    *(s8 *)((s8 *)mail_text + 0xAB) = 0;
    auto_reply_flags |= 4;
    if (is_active() != 0) {
        set_flag_bit0(1);
        return;
    }
    set_flag_bit0(0);
}

int get_flag_bit0() { return (auto_reply_flags & 0x1); }

s32 set_flag_bit0(s32 enabled) {
    s32 flags;
    s32 ret;

    ret = get_flag_bit0();
    if (ret == enabled) {
        return 0;
    }
    flags = auto_reply_flags & 0xFFFFFFFE;
    if (enabled != 0) {
        flags = auto_reply_flags | 1;
    }
    auto_reply_flags = flags;
    return 1;
}

s32 is_active() {
    return *(s8 *)get_card_window_area() == 0 ? 0 : 1;
}

void reset_auto_reply_flags(void *p) {
    auto_reply_flags = 0;
}

void clear_auto_reply_flags(void* p) { reset_auto_reply_flags(p); }
void reset_auto_reply_flags_callback(void* p) { reset_auto_reply_flags(p); }
