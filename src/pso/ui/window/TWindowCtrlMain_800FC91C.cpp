#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228CC0.h"
#include "pso/ui/font/TFontPlayerStatusHelp.h"
#include "pso/ui/window/TWindowCtrlMain_800FC91C.h"
#include "pso/ui/font/TFontSmallTask.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubStatusDisp_80071774.h"
#include "pso/network/protocol/packet_classes.h"
#include "pso/ui/font/TFontSmallHelp.h"
#include "pso/ui/font/TFontSmallLobby.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/system/task/TObject.h"

#include "pso/ui/window/TWindowShortListCtrl.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
s32 get_shared_text_buffer(void);
void text_builder_append_int(s32);
void text_builder_append(const char *);
}
void text_builder_reset(void);
const char *TFontSmallLobby_class_name = "TFontSmallLobby";

// One letter per language (J/E/G/F/S), appended after the player name.
char *status_text_label_table[5] = { "J", "E", "G", "F", "S" };
extern TPlyChallenge lobby_player_status_records[];

saddr TWindowCtrlMain::get_instance() {  return (saddr)instance; }

void TWindowCtrlMain::advance_card_status(s32 local_client_id) {
    s32 card_status_bits;

    card_status_bits = TWindowShortListCtrl::get_card_status_bits(local_client_id) + 1;
    if (card_status_bits >= 5) {
        card_status_bits = 0;
    }
    update_card_window_flags(local_client_id, card_status_bits);
}
s32 TWindowSubStatusDisp::build_status_text(s32 client_id) {
    s32 mode;
    char *name;
    u8 *info;
    s32 idx;
    s32 lvl;
    TObjPlayer *p;
    mode = TWindowShortListCtrl::get_card_status_bits(client_id);
    p = get_player_by_client_id(client_id);
    if (p == NULL) {
        return 0;
    }
    info = (u8 *)p->name;
    if (info == NULL) {
        return 0;
    }
    name = (char *)p->get_name();
    idx = p->get_language();
    lvl = p->get_actor_level_index();
    text_builder_reset();
    switch (mode) {
    case 0:
        text_builder_append(name);
        break;
    case 1:
        text_builder_append(name);
        append_text_space();
        text_builder_append(status_text_label_table[idx]);
        append_padded_number(lvl + 1, 3);
        break;
    case 2:
        if ((s8)info[0x33] < 2) {
            return 0;
        }
        text_builder_append("W:");
        text_builder_append_int(lobby_player_status_records[client_id].battle_place_count_1);
        text_builder_append(" D:");
        text_builder_append_int(lobby_player_status_records[client_id].battle_disconnect_count);
        break;
    case 3:
        if ((s8)info[0x33] < 2) {
            return 0;
        }
        text_builder_append(decode_challenge_rank_title(&lobby_player_status_records[client_id].challenge));
        break;
    case 4:
        return 0;
    }
    return get_shared_text_buffer();
}

void *TFontSmallLobby::create(s32 id) {
    void *o = TObject::operator new(0x64);
    if (o != NULL) {
        o = fn_800FCC78((u8 *)o, id);
    }
    return o;
}

void TFontPlayerStatusHelp::run_task() {
    s32 status_bits;
    s32 client;
    uaddr text_source;
    TObjPlayer *player;

    player = get_player_by_client_id((s32)this->player_id);
    if (player == NULL) {
        queue_destruction();
        return;
    }
    status_bits = TWindowShortListCtrl::get_card_status_bits((s32)this->player_id);
    if (this->card_status_bits != status_bits) {
        this->card_status_bits = status_bits;
        text_source = (u32)TWindowSubStatusDisp::build_status_text((s32)this->player_id);
        set_help_text((const char *)text_source);
        if (text_source != 0U) {
            if (this->card_status_bits == 3) {
                client = (s32)this->player_id;
                set_color(challenge_title_color(&lobby_player_status_records[client].challenge));
            } else {
                set_color(get_player_status_color(player));
            }
        }
    }
    TFontSmallHelp::run_task();
}


TFontPlayerStatusHelp::~TFontPlayerStatusHelp() {

}

struct RecoveredGlobal_800FCC78_lbl_8049CA54 {
    s32 value;
    u8 remaining[0x18];
};

LAYOUT_ASSERT(RecoveredGlobal_800FCC78_lbl_8049CA54_size, sizeof(RecoveredGlobal_800FCC78_lbl_8049CA54) == 0x1C);

extern "C" {
u8 * __ct__14TFontSmallHelpFUlUllUl(void *, s32, s32, s32, s32);
extern RecoveredGlobal_800FCC78_lbl_8049CA54 __vt__21TFontPlayerStatusHelp;
u8 *fn_800FCC78(u8 *font, s32 id) {
    __ct__14TFontSmallHelpFUlUllUl(font, id, -1, -1, 0);
    *(s32 **)((s8 *)font + 0x18) = &__vt__21TFontPlayerStatusHelp.value;
    *(s32 *)((s8 *)font + 0x60) = 5;
    return font;
}

}
