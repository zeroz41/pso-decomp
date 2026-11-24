#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/unk/TScreenFadeOut.h"
#include "types.h"
#include "pso/npc/TNpcPlayer.h"
#include "pso/unk/TLobby_800FD78C.h"
#include "pso/unk/text_8024AC64.h"
#include "pso/unk/text_8024ACA8.h"
#include "pso/ui/window/TWindowReturnCity.h"
#include "pso/ui/window/TWindowMessageYesNo.h"

#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/warp/TObjAreaWarpQuest.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowSubComCard_802A5748.h"
#include "pso/unk/TLobby_80207644.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"

#include "pso/player/PlayerSlots.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TMainTask.h"
#include "pso/npc/NpcPartnerControl.h"

extern "C" {
s32 prepare_hospital_return__10TObjPlayerFv();
saddr get_window_layout_position(int);
void TWindowCtrl__sub_8026D4E8(void);
}

#pragma push
#pragma readonly_strings on
const char *TWindowReturnCity::class_name = "TWindowReturnCity";
#pragma pop

extern s32 lbl_805D55C0;
int TWindowReturnCity__client_scan_index;
void return_to_city_after_defeat(TObject *) {
    if (((s32) lbl_805D55C0 != 1) && ((s32) (*(s32 *)&TWindowReturnCity__client_scan_index) < 4)) {
        if (((saddr)get_player_by_client_id((s32)((u32) (*(s32 *)&TWindowReturnCity__client_scan_index)))) != 0U) {
            prepare_hospital_return__10TObjPlayerFv();
        }
        floor_transition_state.set_next_floor(0, (int) (get_floor_map_terrain(0)));
        mark_area_change_pending();
        send_inter_level_warp_all(floor_transition_state.get_next_floor());
        (*(s32 *)&TWindowReturnCity__client_scan_index) = 4;
    }
}

s32 TWindowReturnCity::query_battle_state() {
    TObjPlayer *player = get_player_by_client_id(client);
    if (player == NULL) {
        return 0;
    }
    return player->has_flag_0x800();
}

void TWindowReturnCity::render() {  }

void TWindowReturnCity::run_task() {
    s32 selected_value;
    if ((s32) lbl_805D55C0 != 1) {
        switch (state) {
        case 2:
            break;
        case 0:
            state = 1;
        case 1:
            if ((query_battle_state() == 0) || ((s32) TWindowReturnCity__client_scan_index != 4)) {
                TWindowReturnCity::clear_flag_bit5();
                TWindowReturnCity__sub_8024ACA8(client);
                TWindowCtrl::clear_flag_2();
                queue_destruction();
                state = 2;
                return;
            }
            if (((TWindowMessageYesNo *)yes_no_window)->is_cancelled() != 0) {
                TWindowReturnCity::clear_flag_bit5();
                TWindowReturnCity__sub_8024ACA8(client);
                TWindowCtrl::clear_flag_2();
                queue_destruction();
                state = 2;
                return;
            }
            if (yes_no_window->is_child_visible() != 0) {
                selected_value = ((TWindowMessageYesNo *)yes_no_window)->get_selected_value();
                if (selected_value == 0) {
                    TWindowReturnCity__client_scan_index = client;
                    new TScreenFadeOut(tl_00, return_to_city_after_defeat);
                    state = 2;
                }
                if (selected_value == 1) {
                    TWindowReturnCity::clear_flag_bit5();
                    TWindowReturnCity__sub_8024ACA8(client);
                    TWindowCtrl::clear_flag_2();
                    queue_destruction();
                    state = 2;
                }
            }
            break;
        }
    }
}

TWindowReturnCity::~TWindowReturnCity() {
    if (yes_no_window != NULL) {
        ((TWindowMessageYesNo *)yes_no_window)->close();
        yes_no_window = NULL;
    }
}

TWindowReturnCity::TWindowReturnCity(TObject *parent, s32 client) : TObject(parent) {
    m_name = class_name;
    this->client = client;
    yes_no_window = TWindowMessageYesNo::create(this, this->client, 0, 0);
    yes_no_window->open_yes_no_prompt_with_text((saddr)TWindowSubStatusDisp::get_message_10(0x43), get_window_layout_position(0x23), 206.0f);
    yes_no_window->set_menu_selected_index(1);
    fn_8024AC64(this->client);
    TWindowCtrl::set_close_flag();
    TWindowCtrl__sub_8026D4E8();
    state = 0;
}

void TWindowReturnCity__sub_8026D4BC(void) {  }

void TWindowReturnCity__sub_8026D4C0(void) { TWindowReturnCity__client_scan_index = 4; }


void TWindowReturnCity::clear_flag_bit5() {
    if (TWindowCtrl::instance != NULL) {
        TWindowCtrl::instance->flags &= ~0x20;
    }
}

void TWindowCtrl__sub_8026D4E8(void) {
    if (TWindowCtrl::instance != NULL) {
        TWindowCtrl::instance->flags |= 0x20;
    }
}
