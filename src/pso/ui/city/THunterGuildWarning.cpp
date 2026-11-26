#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/ui/city/THunterGuildSeqOnline.h"
#include "pso/network/client_id.h"
#include "pso/ui/city/THunterGuildWarning.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TObjBagWarnWin_8006EF24.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/unk/TLobby_8030A6A8.h"
#include "pso/system/ControllerInput.h"
#include "pso/ui/window/WindowLayout.h"
#define PSO_SDK_COMPACT_MATH
#include "pso/render/NinjaUtil.h"
#undef PSO_SDK_COMPACT_MATH

#pragma readonly_strings on

const char *hunter_guild_warning_name = "THunterGuildWarning";
THunterGuildWarning *THunterGuildWarning::instance;

void THunterGuildWarning::queue_destruction() {
    if ((TRaderMapCore::is_not_split_screen() == 1) && (THunterGuildWarning::instance != NULL) && (THunterGuildWarning::instance->all_parents_unqueued_for_destruction() != 0)) {
        THunterGuildWarning::instance->TObject::queue_destruction();
    }
}

void THunterGuildWarning::create_instance(s32 mode) {
    if ((TRaderMapCore::is_not_split_screen() == 1) && (THunterGuildWarning::instance == NULL)) {
        new THunterGuildWarning(tl_05, mode);
    }
}

s32 THunterGuildWarning::is_active() {
    return (u8)((u8) (THunterGuildWarning::instance != 0));
}

void clear_guild_warning_on_guild_exit(void) { THunterGuildWarning::instance = 0; }

void clear_guild_warning_on_quest_exit(void) { THunterGuildWarning::instance = 0; }

void THunterGuildWarning::close_windows() {
    s32 i = 0;
    do {
        if (windows[i] != NULL) {
            windows[i]->close();
            windows[i] = NULL;
        }
        i++;
    } while (i < 4);
}

// Opens the warning message windows for the local or remote players.
void THunterGuildWarning::open_warning_windows(void *) {
    f32 size[2] = {322.0f, 120.0f};
    f32 scale[2] = {1.0f, 1.0f};
    int text;
    s32 i;
    u16 id;

    if (TCameraCtrl::get_view_count() > 2) {
        scale[0] = 0.9f;
        scale[1] = 0.9f;
    }
    switch (mode) {
    case 0:
        id = TCameraCtrl::get_nth_view_player_id(0);
        if (get_player_by_client_id(id) != NULL) {
            windows[id] = TWindowMessage::create(get_window_layout_position(0x31), size, 1, id);
        }
        if (windows[id] != NULL) {
            windows[id]->append_line(get_message_text(99), 0x81);
            windows[id]->set_position_xy(scale[0], scale[1]);
        }
        break;
    case 1:
        id = TCameraCtrl::get_nth_view_player_id(0);
        if (get_player_by_client_id(id) != NULL) {
            windows[id] = TWindowMessage::create(get_window_layout_position(0x31), size, 1, id);
        }
        if (windows[id] != NULL) {
            windows[id]->append_line(get_message_text(104), 0x81);
            windows[id]->set_position_xy(scale[0], scale[1]);
        }
        break;
    case 2:
        text = 100;
        if (get_game_play_mode() == 2) {
            text = 106;
        }
        id = TCameraCtrl::get_nth_view_player_id(0);
        for (i = 0; i < 4; i++) {
            if (id != i) {
                if (get_player_by_client_id(i) != NULL) {
                    windows[i] = TWindowMessage::create(get_window_layout_position(0x31), size, 1, i);
                }
                if (windows[i] != NULL) {
                    windows[i]->append_line(get_message_text(text), 0x81);
                    windows[i]->set_position_xy(scale[0], scale[1]);
                }
            }
        }
        break;
    }
}

void clear_windows(THunterGuildWarning *warning) {
    s32 i;
    for (i = 0; i < 4; i++) warning->windows[i] = NULL;
}

void THunterGuildWarning::run_task() {
    switch (mode) {
    case 0:
    case 1:
        if (--timer < 0) {
            TObject::queue_destruction();
        }
        break;
    case 2:
        break;
    }
}

THunterGuildWarning::~THunterGuildWarning() {
    close_windows();
    THunterGuildWarning::instance = NULL;
}

THunterGuildWarning::THunterGuildWarning(TObject *object, s32 initial_mode) : TObject(object) {
    m_name = hunter_guild_warning_name;
    mode = initial_mode;
    timer = 90;
    clear_windows(this);
    open_warning_windows((void *)mode);
    THunterGuildWarning::instance = this;
}


#include "pso/player/TObjPlayer.h"
#include "pso/player/TPlayerBattleCtrl4P.h"


#pragma push
#pragma optimization_level 3
s32 TPlayerBattleCtrl4P::get_party_not_ready_reason(s32 id) {
    TObjPlayer *self;
    u16 client_id;
    s32 result;
    s32 i;
    s32 j;
    s32 k;
    self = get_player_by_client_id((u16)id);
    if (self == NULL) {
        return 1;
    }
    client_id = id;
    result = 0;
    for (i = 0; i < 4; i++) {
        if (client_id != i) {
            TObjPlayer *other = get_player_by_client_id(i);
            if (other != NULL && other->is_controls_locked() != 0) {
                result = 3;
            }
        }
    }
    for (j = 0; j < 4; j++) {
        if (client_id != j) {
            TObjPlayer *other = get_player_by_client_id(j);
            if (other != NULL && xz_distance_squared((const Vec *)&self->position.x, (const Vec *)&other->position.x) > 22500.0f) {
                result = 2;
            }
        }
    }
    for (k = 0; k < 4; k++) {
        TObjPlayer *other = get_player_by_client_id(k);
        if (other != NULL && other->is_inactive() == 0) {
            result = 2;
            break;
        }
    }
    return result;
}
#pragma pop

// ---- pso/unk/TLobby_80211C1C

#include "pso/network/TLobby.h"
#include "pso/quest/TQuestListOnline.h"


int TLobby::get_selected_quest_id() { return TQuestListOnline::get_selected_quest_id(); }


// ---- pso/unk/text_80211C3C

#include "pso/ui/keyboard/SystemBootInit.h"

s32 get_guild_quest_list_stage(void) {
    if (get_main_phase() != 0xF) {
        return 3;
    }
    if (designated_client_id == local_client_id) {
        switch (TQuestListOnline::get_list_state()) {
        case 0:
            return 3;
        case 1:
            return 1;
        case 2:
            return 2;
        default:
            return 0;
        }
    }
    switch (get_online_client_state()) {
    case -1:
        return 3;
    default:
        return 0;
    }
}

// ---- pso/unk/TLobby_80211CE0


#include "pso/unk/TLobby_80211F0C.h"


s32 TLobby::handle_main_phase(saddr player) {
    if (get_main_phase() == 0xE) {
        return (saddr)THunterGuildSeqOffline::create((TObjPlayer *)player);
    }
    if (get_main_phase() == 0xF) {
        if ((s32) local_client_id == (s32) designated_client_id) {
            return (saddr)TLobby::create_tl05_object((void *)player);
        }
        return (saddr)create_lobby_object_05((void *)player);
    }
    return 0;
}


// ---- pso/unk/text_80211D58




extern "C" {
// TCameraCtrl::get_nth_view_player_id, whose u16 return this caller does not see: it extends the id at every use.
s32 get_nth_view_player_id__11TCameraCtrlFl(s32);
}
extern s32 lbl_805D55C0;
s32 is_in_hunter_guild(s32 client_id) {
    s32 kind;
    s32 player;
    if (get_main_phase() == 14) {
        if (TRaderMapCore::is_not_split_screen() == 1) {
            if (get_game_play_mode() == 0) {
                return 1;
            }
            player = get_nth_view_player_id__11TCameraCtrlFl(0);
            if ((u16)player != client_id) {
                return 1;
            }
            if (THunterGuildWarning::is_active() != 0) {
                return 1;
            }
            kind = TPlayerBattleCtrl4P::get_party_not_ready_reason(player);
            if (kind != 0) {
                TObjPlayer *view_player = get_player_by_client_id((u16)player);
                if (view_player != NULL) {
                    if (test_pressed_buttons_packed(&controller_input_state.controllers[view_player->get_controller_port()], 4) != 0 &&
                        THunterGuildWarning::is_active() == 0) {
                        switch (kind) {
                        case 1:
                        case 2:
                            THunterGuildWarning::create_instance(0);
                            break;
                        case 3:
                            THunterGuildWarning::create_instance(1);
                            break;
                        }
                    }
                }
                return 1;
            }
        }
        return get_offline_instance(client_id);
    }
    if (get_main_phase() == 15) {
        if (lbl_805D55C0 != 0) {
            return 1;
        }
        if (get_online_server_instance(client_id) != 0) {
            return 1;
        }
        return get_online_client_instance(client_id) != 0 ? 1 : 0;
    }
    return 0;
}

// ---- pso/unk/TLobby_80211F0C


#include "pso/player/PlayerSlots.h"


void update_hunter_guild_phase(void) {
    if (get_main_phase() == 0xE) {
        clear_guild_warning_on_guild_exit();
        THunterGuildSeqOffline::clear_instance_table();
    }
    if (get_main_phase() == 0xF) {
        THunterGuildSeqOffline::clear_slots();
        THunterGuildSeqOffline::clear_slot_flags();
        TQuestListOnline::release_resources();
    }
}

void TLobby::update_guild_or_quest_phase() {
    if (get_main_phase() == 0xE) {
        clear_offline_instance_table();
        clear_guild_warning_on_quest_exit();
    }
    if (get_main_phase() == 0xF) {
        TQuestListOnline::init_download_buffers();
        THunterGuildSeqOffline::zero_four_slots();
        clear_online_client_instance_table();
    }
}

void *create_lobby_object_05(void *player) {
    return new THunterGuildSeqOnline_Client(tl_05, (TObjPlayer *)player);
}

void *TLobby::create_tl05_object(void *player) {
    return new THunterGuildSeqOnline_Server(tl_05, (TObjPlayer *)player);
}
