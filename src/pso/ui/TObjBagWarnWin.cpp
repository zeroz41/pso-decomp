#include "pso/TObjBagWarnWin.h"
#include "pso/ui/TObjBagWarnWin_8006EF24.h"
#include "pso/unk/text_8006EF80.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TUnk_804CDFE8.h"

#include "types.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/map/CurrentArea.h"

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
s32 TWindow__close(int);
s32 TWindowCtrlMain__sub_8024CE58();
void *get_player_by_client_id(s32 i);
s32 TLobby__sub_80211C3C();
extern s32 local_client_id;
extern const f32 lbl_805D90B8;
extern const f32 lbl_805D90BC;
extern const f32 lbl_805D90C0;
extern const f32 lbl_805D90C4;
s32 send_and_handle__6TLobbyFii(u32, void *, s32);
u32 set_window_mode_4__6TLobbyFPvll(s32, void *, s32);
s32 get_window_layout_position(s32);
s32 strncpy(void *, s32, s32);
extern u8 TObjBagWarnWin__message_window_size[];
extern const f32 lbl_805D90C8;
extern const f32 lbl_805D90CC;

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
    switch (get_current_area()) {
    case 0:
        if (ctrl->f38 <= lbl_805D90B8 || ctrl->f38 >= lbl_805D90BC) {
            return 0;
        }
        break;
    case 18:
        if (ctrl->f38 <= lbl_805D90C0 || ctrl->f40 <= lbl_805D90C4) {
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
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;
    if ((u32) *(u32 *)((s8 *)arg0 + 0x1C) == 0U) {
        if (TWindowCtrlMain__sub_8024CE58() != 0) {
            if (TObjBagWarnWin::should_show_warning(arg0) != 0) {
                temp_r0 = *(s32 *)((s8 *)arg0 + 0xA0) - 1;
                *(s32 *)((s8 *)arg0 + 0xA0) = temp_r0;
                if (temp_r0 < 0) {
                    *(s32 *)((s8 *)arg0 + 0xA0) = 0;
                }
            } else {
                *(s32 *)((s8 *)arg0 + 0xA0) = 0x1E;
            }
            if ((s32) *(s32 *)((s8 *)arg0 + 0xA0) == 0) {
                open_message_window();
            }
        }
    } else if (TObjBagWarnWin::should_show_warning(arg0) == 0) {
        TWindow__close((int) (*(u32 *)((s8 *)arg0 + 0x1C)));
        *(u32 *)((s8 *)arg0 + 0x1C) = 0U;
        *(s32 *)((s8 *)arg0 + 0xA0) = 0x1E;
    }
}
void TObjBagWarnWin::open_message_window() {
    u8 *arg0 = (u8 *)this;
    *(u32 *)((s8 *)arg0 + 0x1C) = set_window_mode_4__6TLobbyFPvll(get_window_layout_position(0x38), TObjBagWarnWin__message_window_size, 1);
    if ((u32) *(u32 *)((s8 *)arg0 + 0x1C) != 0U) {
        ((TLobby *)(*(u32 *)((s8 *)arg0 + 0x1C)))->set_field_1c(lbl_805D90C8);
        if (TCameraCtrl::get_camera_id() == 4) {
            ((TUnk_804CDFE8 *)(*(u32 *)((s8 *)arg0 + 0x1C)))->set_position_xy(lbl_805D90CC, lbl_805D90CC);
        }
        strncpy(arg0 + 0x20, TQuestVmDownLoadServer__sub_8006EF6C(0x59), 0x7F);
        *(s8 *)((s8 *)arg0 + 0x9F) = 0;
        send_and_handle__6TLobbyFii(*(u32 *)((s8 *)arg0 + 0x1C), arg0 + 0x20, 0);
    }
}
TObjBagWarnWin::~TObjBagWarnWin() {}

}
