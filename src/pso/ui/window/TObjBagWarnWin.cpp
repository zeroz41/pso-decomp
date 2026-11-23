#include "pso/player/TObjPlayer_80011014.h"
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
#include "pso/unk/TLobby_8030A6A8.h"

#include "pso/player/PlayerSlots.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_80211C3C.h"

const char *TObjBagWarnWin__name = "TObjBagWarnWin";

const char *TObjBagWarnWin4P__name = "TObjBagWarnWin4P";

#include "pso/unk/text_8006EBC4.h"

#include "pso/ui/window/TObjBagWarnWin.h"

#include "pso/ui/window/TObjBagWarnWin_8006EF24.h"

#include "pso/unk/text_8006EF80.h"

#include "pso/camera/TCameraCtrl.h"

#include "pso/ui/window/TWindowAddition.h"

#include "pso/map/FloorArea.h"

#include "pso/unk/TLobby.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/city/THunterGuildWarning.h"
#include "pso/ui/window/TWindowCtrlMain_8024CB7C.h"

extern "C" {



saddr get_message_text(s32);


saddr get_window_layout_position(s32);






extern f32 TObjBagWarnWin4P__message_window_size[2];

}

struct Sub_8006EC20 {
    u8 pad[0x1C];
    s16 v1C;
};

struct Ctrl_8006EC20 {
    u8 pad0[0x38];
    f32 f38;
    u8 pad3C[4];
    f32 f40;
    u8 pad44[0xD00 - 0x44];
    Sub_8006EC20 *pD00;
};
extern "C" {


extern s32 local_client_id;


saddr get_window_layout_position(s32);


extern f32 TObjBagWarnWin__message_window_size[2];

extern u8 *text_language_group_table;

saddr get_message_text(s32 text) {
    return *(s32 *)((s8 *)(*(saddr *)((s8 *)text_language_group_table + 0x2C)) + (text * 4));
}

void *TObjBagWarnWin::create(void *bag_warn_win) {
    void *o = (void *)new TObjBagWarnWin((TObject *)bag_warn_win);
    return o;
}
}

TObjBagWarnWin::TObjBagWarnWin(TObject *parent) : TObject(parent) {
    this->m_name = TObjBagWarnWin__name;
    message_window = NULL;
    open_delay = 0;
}
extern "C" {
TObjBagWarnWin::~TObjBagWarnWin() {}

void TObjBagWarnWin::open_message_window() {
    message_window = (TWindowMessage *)TWindowMessage::create((const NJS_POINT2 *)(get_window_layout_position(0x38)), (const f32 *)TObjBagWarnWin__message_window_size, 1);
    if (message_window != NULL) {
        message_window->set_depth(70200.0f);
        if (TCameraCtrl::get_camera_id() == 4) {
            message_window->set_position_xy(0.8f, 0.8f);
        }
        strncpy(message_text, (const char *)get_message_text(0x59), 0x7F);
        message_text[0x7F] = 0;
        message_window->append_line((saddr)message_text, (int)0);
    }
}

void TObjBagWarnWin::run_task() {
    s32 temp_r0;
    if (message_window == NULL) {
        if (has_window_task_root() != 0) {
            if (TObjBagWarnWin::should_show_warning(this) != 0) {
                temp_r0 = open_delay - 1;
                open_delay = temp_r0;
                if (temp_r0 < 0) {
                    open_delay = 0;
                }
            } else {
                open_delay = 0x1E;
            }
            if (open_delay == 0) {
                open_message_window();
            }
        }
    } else if (TObjBagWarnWin::should_show_warning(this) == 0) {
        message_window->close();
        message_window = NULL;
        open_delay = 0x1E;
    }
}

s32 TObjBagWarnWin::should_show_warning(void *arg0) {
    Ctrl_8006EC20 *ctrl;
    if (TLobby__sub_80211C3C() != 3) {
        return 0;
    }
    if (fn_8006EF80() != 0) {
        return 0;
    }
    ctrl = (Ctrl_8006EC20 *)get_player_by_client_id(local_client_id);
    if (ctrl == NULL) {
        return 0;
    }
    switch (get_current_floor_area()) {
    case AREA_PIONEER2_EP1:
        if (ctrl->f38 <= -100.0f || ctrl->f38 >= 330.0f) {
            return 0;
        }
        break;
    case AREA_PIONEER2_EP2:
        if (ctrl->f38 <= -40.0f || ctrl->f40 <= -175.0f) {
            return 0;
        }
        break;
    }
    ctrl = (Ctrl_8006EC20 *)get_player_by_client_id(local_client_id);
    if (ctrl == NULL || ctrl->pD00->v1C < 30) {
        return 0;
    }
    return 1;
}

TObjBagWarnWin4P *fn_8006EBC4(saddr parent) {
    if (TWindowCtrl::is_map_visible() == 0) {
        return new TObjBagWarnWin4P((TObject *)parent);
    }
    return NULL;
}

TObjBagWarnWin4P::TObjBagWarnWin4P(TObject *parent) : TObject(parent) {
    m_name = TObjBagWarnWin4P__name;
    message_window = NULL;
    open_delay = 0;
}

TObjBagWarnWin4P::~TObjBagWarnWin4P() {}

void TObjBagWarnWin4P::create_window() {
    s32 position = get_window_layout_position(0x5B);
    message_window = (TWindowMessage *)TWindowMessage::create(position, TObjBagWarnWin4P__message_window_size, 1, 4);
    if (message_window != NULL) {
        strncpy(message_text, (const char *)get_message_text(0x69), 0x7F);
        message_text[0x7F] = 0;
        message_window->append_line((saddr)message_text, (int)0);
    }
}

void TObjBagWarnWin4P::run_task() {
    s32 temp_r0;
    if (message_window == NULL) {
        if (has_window_task_root() != 0) {
            if (TObjBagWarnWin4P::check_can_open(this) != 0) {
                temp_r0 = open_delay - 1;
                open_delay = temp_r0;
                if (temp_r0 < 0) {
                    open_delay = 0;
                }
            } else {
                open_delay = 0x1E;
            }
            if (open_delay == 0) {
                create_window();
            }
        }
    } else if (TObjBagWarnWin4P::check_can_open(this) == 0) {
        message_window->close();
        message_window = NULL;
        open_delay = 0x1E;
    }
}

s32 TObjBagWarnWin4P::check_can_open(void * _w0) {
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
        if ((get_player_by_client_id(j) != NULL) && ((record = (CharacterSaveRecord *)get_character_save_record(j)) != 0U) && (record->is_bank_full() != 0)) {
            i = 1;
        }
        j += 1;
    } while (j < 4);
    return i;
}
}

// The map is hidden only in single-screen solo play while the lobby state
// reports it closed.
s32 TWindowCtrl::is_map_visible() {
    if (TRaderMapCore::is_not_split_screen() != 1) {
        return 1;
    }
    if (get_game_play_mode() != 1) {
        return 1;
    }
    return TLobby__sub_8030A770() != 0 ? 1 : 0;
}

__declspec(section ".data") f32 TObjBagWarnWin__message_window_size[2] = {350.0f, 120.0f};
__declspec(section ".data") f32 TObjBagWarnWin4P__message_window_size[2] = {350.0f, 120.0f};
