#include "pso/system/TLanguage.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/object/base/TObjBase.h"
#pragma defer_codegen on

#pragma readonly_strings on

#include "pso/system/CharacterSaveRecordLookup.h"
#include "pso/ui/window/TObjBagWarnWin4P.h"
#include <string.h>

#include "pso/ui/window/TWindowMessage.h"

#include "pso/ui/window/TWindowBase.h"

#include "types.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

#include "pso/ui/hud/TRaderMapCore.h"

#include "pso/ui/window/TWindowCtrl.h"
#include "pso/system/GameModeQueries.h"

#include "pso/player/PlayerSlots.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TPlyItem.h"


#include "pso/ui/window/TObjBagWarnWin.h"

const char *TObjBagWarnWin::class_name = "TObjBagWarnWin";

const char *TObjBagWarnWin4P::class_name = "TObjBagWarnWin4P";

#include "pso/ui/window/TObjBagWarnWin_8006EF24.h"

#include "pso/quest/challenge/ChallengeMode.h"

#include "pso/camera/TCameraCtrl.h"

#include "pso/ui/window/TWindowAddition.h"

#include "pso/map/FloorArea.h"

#include "pso/network/TLobby.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/city/THunterGuildWarning.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/network/client_id.h"
#include "pso/ui/window/WindowLayout.h"
















const char *get_message_text(s32 text) {
    return text_language_group_table[11][text];
}

void *TObjBagWarnWin::create(TObject *bag_warn_win) {
    void *o = (void *)new TObjBagWarnWin(bag_warn_win);
    return o;
}

TObjBagWarnWin::TObjBagWarnWin(TObject *parent) : TObject(parent) {
    this->m_name = class_name;
    message_window = NULL;
    open_delay = 0;
}
TObjBagWarnWin::~TObjBagWarnWin() {}

void TObjBagWarnWin::open_message_window() {
    message_window = TWindowMessage::create(get_window_layout_position(0x38), (const f32 *)message_window_size, 1);
    if (message_window != NULL) {
        message_window->set_depth(70200.0f);
        if (TCameraCtrl::get_camera_id() == 4) {
            message_window->set_position_xy(0.8f, 0.8f);
        }
        strncpy(message_text, get_message_text(0x59), 0x7F);
        message_text[0x7F] = 0;
        message_window->append_line(message_text, (int)0);
    }
}

void TObjBagWarnWin::run_task() {
    s32 remaining;
    if (message_window == NULL) {
        if (has_window_task_root() != 0) {
            if (should_show_warning() != 0) {
                remaining = open_delay - 1;
                open_delay = remaining;
                if (remaining < 0) {
                    open_delay = 0;
                }
            } else {
                open_delay = 0x1E;
            }
            if (open_delay == 0) {
                open_message_window();
            }
        }
    } else if (should_show_warning() == 0) {
        message_window->close();
        message_window = NULL;
        open_delay = 0x1E;
    }
}

s32 TObjBagWarnWin::should_show_warning() {
    TObjPlayer *ctrl;
    if (get_guild_quest_list_stage() != 3) {
        return 0;
    }
    if (get_challenge_record_window_mode() != 0) {
        return 0;
    }
    ctrl = get_player_by_client_id(local_client_id);
    if (ctrl == NULL) {
        return 0;
    }
    switch (get_current_floor_area()) {
    case AREA_PIONEER2_EP1:
        if (ctrl->position.x <= -100.0f || ctrl->position.x >= 330.0f) {
            return 0;
        }
        break;
    case AREA_PIONEER2_EP2:
        if (ctrl->position.x <= -40.0f || ctrl->position.z <= -175.0f) {
            return 0;
        }
        break;
    }
    ctrl = get_player_by_client_id(local_client_id);
    if (ctrl == NULL || ctrl->inventory_objects->item_count < 30) {
        return 0;
    }
    return 1;
}

TObjBagWarnWin4P *create_bag_warn_window_4p(TObject *parent) {
    if (is_map_visible() == 0) {
        return new TObjBagWarnWin4P(parent);
    }
    return NULL;
}

TObjBagWarnWin4P::TObjBagWarnWin4P(TObject *parent) : TObject(parent) {
    m_name = class_name;
    message_window = NULL;
    open_delay = 0;
}

TObjBagWarnWin4P::~TObjBagWarnWin4P() {}

void TObjBagWarnWin4P::create_window() {
    const NJS_POINT2 *position = get_window_layout_position(0x5B);
    message_window = TWindowMessage::create(position, message_window_size, 1, 4);
    if (message_window != NULL) {
        strncpy(message_text, get_message_text(0x69), 0x7F);
        message_text[0x7F] = 0;
        message_window->append_line(message_text, (int)0);
    }
}

void TObjBagWarnWin4P::run_task() {
    s32 remaining;
    if (message_window == NULL) {
        if (has_window_task_root() != 0) {
            if (check_can_open() != 0) {
                remaining = open_delay - 1;
                open_delay = remaining;
                if (remaining < 0) {
                    open_delay = 0;
                }
            } else {
                open_delay = 0x1E;
            }
            if (open_delay == 0) {
                create_window();
            }
        }
    } else if (check_can_open() == 0) {
        message_window->close();
        message_window = NULL;
        open_delay = 0x1E;
    }
}

s32 TObjBagWarnWin4P::check_can_open() {
    s32 i;
    s32 j;

    for (i = 0; i < 4; i++) {
        TObjPlayer *player = get_player_by_client_id(i);
        if (player != NULL && TWindowCtrl::has_player_active_menu(player->get_entity_id()) != 0) {
            return 0;
        }
    }
    for (i = 0; i < 4; i++) {
        TObjPlayer *player = get_player_by_client_id(i);
        if (player != NULL && TWindowCtrl::is_slot_visible(player->get_entity_id()) != 0) {
            return 0;
        }
    }
    if (THunterGuildWarning::is_active() != 0) {
        return 0;
    }
    CharacterSaveRecord *record;
    i = 0;
    j = 0;
    do {
        if ((get_player_by_client_id(j) != NULL) && ((record = get_character_save_record(j)) != 0U) && (record->is_bank_full() != 0)) {
            i = 1;
        }
        j += 1;
    } while (j < 4);
    return i;
}

// The map is hidden only in single-screen solo play while the lobby state
// reports it closed.
s32 is_map_visible() {
    if (TRaderMapCore::is_not_split_screen() != 1) {
        return 1;
    }
    if (get_game_play_mode() != 1) {
        return 1;
    }
    return is_challenge_quest_active() != 0 ? 1 : 0;
}

__declspec(section ".data") f32 TObjBagWarnWin::message_window_size[2] = {350.0f, 120.0f};
__declspec(section ".data") f32 TObjBagWarnWin4P::message_window_size[2] = {350.0f, 120.0f};
