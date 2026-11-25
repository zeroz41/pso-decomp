#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TObjResultWin.h"
#include "pso/ui/window/TObjBagWarnWin_8006EF24.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/ui/window/TObjNewFloorWin.h"
#include "pso/quest/TQuestListVM.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/frontend/TAdChrSelASlotGC.h"
#include "pso/system/task/TObject.h"
#include "pso/network/TLobby.h"
#include <stdio.h>
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/ui/window/TWindowCtrlMain_8024CB7C.h"
#include "pso/player/PlayerSlots.h"
#include "pso/ui/window/WindowLayout.h"
extern "C" { extern const char TObjNewFloorWin__class_name_string[16] = "TObjNewFloorWin"; }



void TShopWindowBase::set_state(s32 v) { state = v; }

void TObjNewFloorWin::run_task() {
    switch (state) {
    case 0:
        if (window == NULL) {
            if (has_window_task_root() == 0) {
                if (--wait_timer <= 0) {
                    queue_destruction();
                    return;
                }
                return;
            } else {
                open_window();
                state = 1;
            }
        }
        break;
    case 1:
        if (--display_timer == 0x3C) {
            if (window != NULL) {
                window->close();
                window = NULL;
            }
            state = 2;
        }
        break;
    case 2:
        if (--display_timer <= 0) {
            queue_destruction();
        }
        break;
    }
}

void TObjNewFloorWin::open_window() {
    const NJS_POINT2 *pos;
    pos = get_window_layout_position(0x3D);
    if (client_id < 0) {
        window = create_window_menu_default(pos, 1);
    } else {
        window = create_window_menu(pos, 1, client_id);
    }
    if (window != NULL) {
        sprintf(floor_text, "%s %02d", get_message_text(0x67), TObjNewFloorWin__sub_8007410C());
        window->add_text_entry((saddr)floor_text, 0, 0);
        window->calc_window_size();
        window->set_flag_40();
        fn_800740DC();
        TWindowCtrl::close_active_window();
        TWindowCtrl::ensure_initialized();
    }
}


TObjNewFloorWin::~TObjNewFloorWin() {}


extern "C" {
const char *TObjNewFloorWin__class_name = TObjNewFloorWin__class_name_string;
}

TObjNewFloorWin::TObjNewFloorWin(TObject *object, s32 client_id) : TObject(object) {
    this->m_name = TObjNewFloorWin__class_name;
    this->client_id = client_id;
    window = NULL;
    wait_timer = 450;
    display_timer = 150;
    state = 0;
}

u8 *TLobby::create_new_floor_windows() {
    TObjNewFloorWin *window;
    s32 i;
    if (is_split_screen() == 0) {
        return (u8 *)new TObjNewFloorWin(this, -1);
    }
    window = NULL;
    i = 0;
    do {
        if (get_player_by_client_id(i) != NULL) {
            window = new TObjNewFloorWin(this, i);
        }
        i++;
    } while (i < 4);
    return (u8 *)window;
}

void fn_800740DC(void) { TWindowCtrl::close_active_window(); }
