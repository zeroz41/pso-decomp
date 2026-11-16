#include "pso/ui/window/TObjBagWarnWin.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TObjBagWarnWin_8006EF24.h"
#include "pso/unk/text_8006EF80.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/map/FloorArea.h"
#include "types.h"
#include "pso/unk/TLobby.h"

#pragma readonly_strings on

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
s32 has_window_task_root();
void *get_player_by_client_id(s32 i);
s32 TLobby__sub_80211C3C();
extern s32 local_client_id;
u32 create__14TWindowMessageFPvll(s32, void *, s32);
s32 get_window_layout_position(s32);
s32 strncpy(void *, s32, s32);
extern u8 TObjBagWarnWin__message_window_size[];

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
void TObjBagWarnWin::open_message_window() {
    message_window = (TWindowMessage *)create__14TWindowMessageFPvll(get_window_layout_position(0x38), TObjBagWarnWin__message_window_size, 1);
    if (message_window != NULL) {
        message_window->set_depth(70200.0f);
        if (TCameraCtrl::get_camera_id() == 4) {
            message_window->set_position_xy(0.8f, 0.8f);
        }
        strncpy(message_text, get_message_text(0x59), 0x7F);
        message_text[0x7F] = 0;
        message_window->append_line((int)message_text, (int)0);
    }
}
TObjBagWarnWin::~TObjBagWarnWin() {}

const char *TObjBagWarnWin__name = "TObjBagWarnWin";

}
TObjBagWarnWin::TObjBagWarnWin(TObject *parent) : TObject(parent) {
    this->m_name = TObjBagWarnWin__name;
    message_window = NULL;
    open_delay = 0;
}
