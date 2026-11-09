#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubComCard_80244774.h"
#include "pso/ui/city/THunterGuildWarning.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TObjBagWarnWin_8006EF24.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/unk/TLobby_8030A6A8.h"
struct Obj_802119CC { u8 pad[0x24]; s32 a[4]; };

// A window's width and height.
struct WindowSize {
    f32 width;
    f32 height;
};

struct S_80211718 { u8 pad[0x1C]; s32 mode; u8 pad20[4]; u32 w[4]; };

extern "C" {
s32 get_window_layout_position(s32 index);
void THunterGuildWarning__sub_802119CC(Obj_802119CC *self);

void THunterGuildWarning::close_windows() {
    S_80211718 *self = (S_80211718 *)this;
    s32 i = 0;
    do {
        if (self->w[i] != 0) {
            ((TWindowBase *)(self->w[i]))->close();
            self->w[i] = 0;
        }
        i++;
    } while (i < 4);
}

void THunterGuildWarning__sub_802119CC(Obj_802119CC *self) {
    s32 i;
    for (i = 0; i < 4; i++) self->a[i] = 0;
}

}

// Opens the warning message windows for the local or remote players.
void THunterGuildWarning::sub_80211774(void *) {
    S_80211718 *self = (S_80211718 *)this;
    f32 size[2] = {322.0f, 120.0f};
    f32 scale[2] = {1.0f, 1.0f};
    int text;
    s32 i;
    u16 id;

    if (TCameraCtrl::get_instance() > 2) {
        scale[0] = 0.9f;
        scale[1] = 0.9f;
    }
    switch (self->mode) {
    case 0:
        id = TCameraCtrl::get_nth_view_player_id(0);
        if (get_player_by_client_id(id) != NULL) {
            self->w[id] = (u32)TWindowMessage::create(get_window_layout_position(0x31), size, 1, id);
        }
        if (self->w[id] != 0) {
            ((TWindowMessage *)self->w[id])->append_line(TQuestVmDownLoadServer__sub_8006EF6C(99), 0x81);
            ((TWindowAddition *)self->w[id])->set_position_xy(scale[0], scale[1]);
        }
        break;
    case 1:
        id = TCameraCtrl::get_nth_view_player_id(0);
        if (get_player_by_client_id(id) != NULL) {
            self->w[id] = (u32)TWindowMessage::create(get_window_layout_position(0x31), size, 1, id);
        }
        if (self->w[id] != 0) {
            ((TWindowMessage *)self->w[id])->append_line(TQuestVmDownLoadServer__sub_8006EF6C(104), 0x81);
            ((TWindowAddition *)self->w[id])->set_position_xy(scale[0], scale[1]);
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
                    self->w[i] = (u32)TWindowMessage::create(get_window_layout_position(0x31), size, 1, i);
                }
                if (self->w[i] != 0) {
                    ((TWindowMessage *)self->w[i])->append_line(TQuestVmDownLoadServer__sub_8006EF6C(text), 0x81);
                    ((TWindowAddition *)self->w[i])->set_position_xy(scale[0], scale[1]);
                }
            }
        }
        break;
    }
}
