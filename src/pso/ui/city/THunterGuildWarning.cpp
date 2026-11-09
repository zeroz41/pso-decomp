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
