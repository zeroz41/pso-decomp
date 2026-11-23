#include "pso/unk/TScreenFadeOut.h"
#include "types.h"
#include "pso/ui/window/TWindowSubGameEnd.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/unk/text_8024AB54.h"
#include "pso/ui/window/TWindowMessageYesNo.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/system/task/TMainTask.h"

#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/chat/TWindowSubShortMail.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/window/TWindowSubComCard_802A5748.h"
#include "pso/network/TPlyJoinLobbyEntry.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"

#pragma readonly_strings on


const char *TWindowSubGameEnd::class_name = "TWindowSubGameEnd";
int window_sub_game_end_active_flag;

extern "C" {
saddr get_window_layout_position(s32);
}

void TKeyBoardControl::init_char_select(TObject *) {
    if (is_split_screen() != 0) {
        TAdSinglePlyChrSelectGC::setup_player_battle_ctrls();
        request_main_phase(7);
        return;
    }
    TAdSinglePlyChrSelectGC::init();
    set_queued_main_phase(9);
    request_main_phase(0x12);
}
void TWindowSubGameEnd::render() {  }

void TWindowSubGameEnd::run_task() {
    s32 slot;
    switch (state) {
    case 0:
    case 1:
        if (((TWindowMessageYesNo *)yes_no_window)->is_cancelled() != 0) {
            parent_menu->on_submenu_closed();
            return;
        }
        if (yes_no_window->is_child_visible() != 0) {
            slot = ((TWindowMessageYesNo *)yes_no_window)->get_selected_value();
            if (slot == 0) {
                if (window_sub_game_end_active_flag != 1) {
                    new TScreenFadeOut(tl_00, TKeyBoardControl::init_char_select);
                    fn_8024AB54(client);
                    TLobby::send_logout();
                    window_sub_game_end_active_flag = 1;
                }
                state = 2;
            }
            if (slot == 1) {
                parent_menu->on_submenu_closed();
            }
        }
        break;
    case 2:
        break;
    }
}

TWindowSubGameEnd::~TWindowSubGameEnd() {
    if (yes_no_window != NULL) {
        ((TWindowMessageYesNo *)yes_no_window)->close();
        yes_no_window = NULL;
    }
}

TWindowSubGameEnd::TWindowSubGameEnd(TWindowMainMenu *parent, s32 client) : TObject(parent) {
    f32 width;
    s32 text;
    m_name = class_name;
    parent_menu = parent;
    this->client = client;
    if (get_main_phase() == 0xF) {
        text = (saddr)TWindowSubStatusDisp::get_message_10(0x3B);
        width = 469.0f;
    } else if (is_split_screen() != 0) {
        text = (saddr)TWindowSubStatusDisp::get_message_10(0x3C);
        width = 312.0f;
    } else {
        text = (saddr)TWindowSubStatusDisp::get_message_10(0x3A);
        width = 469.0f;
    }
    yes_no_window = TWindowMessageYesNo::create(this, this->client, 0, 0);
    yes_no_window->open_yes_no_prompt_with_text(text, get_window_layout_position(0x17), width);
    yes_no_window->set_menu_selected_index(1);
    yes_no_window->set_choice_menu_flag70_bit10();
    state = 0;
}

extern "C" {
void TLobby__sub_802796FC(void) { window_sub_game_end_active_flag = 0; }

void TLobby__sub_80279708(void) { window_sub_game_end_active_flag = 0; }
}
