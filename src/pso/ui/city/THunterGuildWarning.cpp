#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
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

#pragma readonly_strings on

const char *THunterGuildWarning__name = "THunterGuildWarning";
THunterGuildWarning *THunterGuildWarning__instance;

void THunterGuildWarning::queue_destruction() {
    if ((TRaderMapCore::is_not_split_screen() == 1) && (THunterGuildWarning__instance != NULL) && (THunterGuildWarning__instance->all_parents_unqueued_for_destruction() != 0)) {
        THunterGuildWarning__instance->TObject::queue_destruction();
    }
}

void THunterGuildWarning::create_instance(s32 arg0) {
    if ((TRaderMapCore::is_not_split_screen() == 1) && (THunterGuildWarning__instance == NULL)) {
        new THunterGuildWarning(tl_05, (void *)arg0);
    }
}

u8 THunterGuildWarning::is_active() {
    return (u8) (THunterGuildWarning__instance != 0);
}

void THunterGuildWarning__sub_80211700(void) { THunterGuildWarning__instance = 0; }

void THunterGuildWarning__sub_8021170C(void) { THunterGuildWarning__instance = 0; }

extern "C" {
s32 get_window_layout_position(s32 index);
}

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
void THunterGuildWarning::sub_80211774(void *) {
    f32 size[2] = {322.0f, 120.0f};
    f32 scale[2] = {1.0f, 1.0f};
    int text;
    s32 i;
    u16 id;

    if (TCameraCtrl::get_instance() > 2) {
        scale[0] = 0.9f;
        scale[1] = 0.9f;
    }
    switch (mode) {
    case 0:
        id = TCameraCtrl::get_nth_view_player_id(0);
        if (get_player_by_client_id(id) != NULL) {
            windows[id] = (TWindowMessage *)TWindowMessage::create(get_window_layout_position(0x31), size, 1, id);
        }
        if (windows[id] != NULL) {
            windows[id]->append_line(TQuestVmDownLoadServer__sub_8006EF6C(99), 0x81);
            windows[id]->set_position_xy(scale[0], scale[1]);
        }
        break;
    case 1:
        id = TCameraCtrl::get_nth_view_player_id(0);
        if (get_player_by_client_id(id) != NULL) {
            windows[id] = (TWindowMessage *)TWindowMessage::create(get_window_layout_position(0x31), size, 1, id);
        }
        if (windows[id] != NULL) {
            windows[id]->append_line(TQuestVmDownLoadServer__sub_8006EF6C(104), 0x81);
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
                    windows[i] = (TWindowMessage *)TWindowMessage::create(get_window_layout_position(0x31), size, 1, i);
                }
                if (windows[i] != NULL) {
                    windows[i]->append_line(TQuestVmDownLoadServer__sub_8006EF6C(text), 0x81);
                    windows[i]->set_position_xy(scale[0], scale[1]);
                }
            }
        }
        break;
    }
}

extern "C" void THunterGuildWarning__sub_802119CC(THunterGuildWarning *self) {
    s32 i;
    for (i = 0; i < 4; i++) self->windows[i] = NULL;
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
    THunterGuildWarning__instance = NULL;
}

THunterGuildWarning::THunterGuildWarning(TObject *object, void *arg2) : TObject(object) {
    m_name = THunterGuildWarning__name;
    mode = (s32)arg2;
    timer = 90;
    THunterGuildWarning__sub_802119CC(this);
    sub_80211774((void *)mode);
    THunterGuildWarning__instance = this;
}

#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TPlayerBattleCtrl4P.h"

extern "C" {
TObjPlayer *get_player_by_client_id(s32 id);
s32 check_flag_100__10TObjPlayerFPv(TObjPlayer *player);
f32 xz_distance_squared(const f32 *a, const f32 *b);

#pragma push
#pragma optimization_level 3
s32 TPlayerBattleCtrl4P::fn_80211B10(s32 id) {
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
            if (other != NULL && check_flag_100__10TObjPlayerFPv(other) != 0) {
                result = 3;
            }
        }
    }
    for (j = 0; j < 4; j++) {
        if (client_id != j) {
            TObjPlayer *other = get_player_by_client_id(j);
            if (other != NULL && xz_distance_squared(&self->position.x, &other->position.x) > 22500.0f) {
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
}

// ---- pso/unk/TLobby_80211C1C
#include "types.h"
#include "pso/unk/TLobby.h"

extern "C" {

int get_selected_quest_id__16TQuestListOnlineFv(void*);

int TLobby::get_selected_quest_id() { return get_selected_quest_id__16TQuestListOnlineFv(this); }

}

// ---- pso/unk/text_80211C3C
#include "types.h"
#include "pso/unk/text_80211C3C.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/quest/TQuestListOnline.h"

extern "C" {
extern s32 TLobby__designated_client_id;
extern s32 local_client_id;
s32 THunterGuildSeqOffline__sub_80213458(void);
}

s32 TLobby__sub_80211C3C(void) {
    if (get_main_phase() != 0xF) {
        return 3;
    }
    if (TLobby__designated_client_id == local_client_id) {
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
    switch (THunterGuildSeqOffline__sub_80213458()) {
    case -1:
        return 3;
    default:
        return 0;
    }
}

// ---- pso/unk/TLobby_80211CE0
#include "types.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_80211F0C.h"

extern "C" {

s32 create__22THunterGuildSeqOfflineFPv(s32);

s32 TLobby::handle_main_phase(s32 arg0) {
    if (get_main_phase() == 0xE) {
        return create__22THunterGuildSeqOfflineFPv(arg0);
    }
    if (get_main_phase() == 0xF) {
        if ((s32) local_client_id == (s32) TLobby__designated_client_id) {
            return (s32)TLobby::create_tl05_object((void *)arg0);
        }
        return (s32)create_lobby_object_05((void *)arg0);
    }
    return 0;
}

}

// ---- pso/unk/text_80211D58
#include "types.h"
#include "pso/player/TPlayerBattleCtrl4P.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/unk/TLobby_8030A6A8.h"
#include "pso/unk/text_80211D58.h"
#include "pso/ui/city/THunterGuildWarning.h"
#include "pso/ui/hud/TRaderMapCore.h"
extern "C" {
s32 get_nth_view_player_id__11TCameraCtrlFl(s32);
s32 TWindowShortListCtrl__check_controller_button(void *, s32);
s32 get_map_id__13TRaderMapCoreFv();
s32 is_active__19THunterGuildWarningFv();
s32 THunterGuildSeqOffline__sub_80211FEC(s32);
s32 THunterGuildSeqOffline__sub_80212000(s32);
s32 THunterGuildSeqOffline__sub_80212060(s32);
extern u8 controller_input_state[][0x50];
extern s32 lbl_805D55C0;
s32 TLobby__sub_80211D58(s32 arg0) {
    s32 kind;
    s32 player;
    if (get_main_phase() == 14) {
        if (TRaderMapCore::is_not_split_screen() == 1) {
            if (get_game_play_mode() == 0) {
                return 1;
            }
            player = get_nth_view_player_id__11TCameraCtrlFl(0);
            if ((u16)player != arg0) {
                return 1;
            }
            if (is_active__19THunterGuildWarningFv() != 0) {
                return 1;
            }
            kind = TPlayerBattleCtrl4P::fn_80211B10(player);
            if (kind != 0) {
                if (get_player_by_client_id((u16)player) != NULL) {
                    if (TWindowShortListCtrl__check_controller_button(&controller_input_state[get_map_id__13TRaderMapCoreFv()][0x20], 4) != 0 &&
                        is_active__19THunterGuildWarningFv() == 0) {
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
        return THunterGuildSeqOffline__sub_80212060(arg0);
    }
    if (get_main_phase() == 15) {
        if (lbl_805D55C0 != 0) {
            return 1;
        }
        if (THunterGuildSeqOffline__sub_80212000(arg0) != 0) {
            return 1;
        }
        return THunterGuildSeqOffline__sub_80211FEC(arg0) != 0 ? 1 : 0;
    }
    return 0;
}

}

// ---- pso/unk/TLobby_80211F0C
#include "types.h"
#include "pso/ui/city/THunterGuildSeqOffline_80213788.h"
#include "pso/ui/city/THunterGuildWarning.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/unk/TLobby_80211F0C.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/quest/TQuestListOnline.h"

void update_hunter_guild_phase(void) {
    if (get_main_phase() == 0xE) {
        THunterGuildWarning__sub_80211700();
        THunterGuildSeqOffline::clear_instance_table();
    }
    if (get_main_phase() == 0xF) {
        clear_slots__22THunterGuildSeqOfflineFv();
        clear_slot_flags__22THunterGuildSeqOfflineFv();
        TQuestListOnline::release_resources();
    }
}
extern "C" {

void THunterGuildSeqOffline__sub_8021339C(void);

void TLobby::update_guild_or_quest_phase() {
    if (get_main_phase() == 0xE) {
        THunterGuildSeqOffline__sub_8021339C();
        THunterGuildWarning__sub_8021170C();
    }
    if (get_main_phase() == 0xF) {
        TQuestListOnline::init_download_buffers();
        zero_four_slots__22THunterGuildSeqOfflineFv();
        THunterGuildSeqOffline__sub_80213CA4();
    }
}

void *__nw__7TObjectFUl(int);
void *THunterGuildSeqOnline_Client__ct(void *, void *, void *);

void *create_lobby_object_05(void *arg0) {
    void *o = __nw__7TObjectFUl(0x40);
    if (o != NULL) {
        o = THunterGuildSeqOnline_Client__ct(o, tl_05, arg0);
    }
    return o;
}

void *THunterGuildSeqOffline__sub_80214B3C(void *, void *, void *);

void *TLobby::create_tl05_object(void *arg0) {
    void *o = __nw__7TObjectFUl(0x44);
    if (o != NULL) {
        o = THunterGuildSeqOffline__sub_80214B3C(o, tl_05, arg0);
    }
    return o;
}
}
