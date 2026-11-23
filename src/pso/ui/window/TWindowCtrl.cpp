#include "pso/ui/window/TWindowFukidasi.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/TWindowCtrl_8024B048.h"
#include "pso/object/base/TObjChara.h"
#include "pso/ui/window/TWindowCtrl_8024B7D4.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowTradeRequest.h"
#include "pso/ui/window/TWindowGetComCard.h"
#include "pso/ui/window/TWindowSimpleStatus.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowCtrl_8024B9C0.h"
#include "pso/ui/window/TWindowSubComCard_80244774.h"
#include "pso/ui/window/TWindowLockOn.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/ui/chat/TWindowSubShortMail_80246CB8.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/chat/TWindowChat.h"
#include "pso/npc/TNpcPlayer.h"
#include "pso/map/FloorArea.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/system/ControllerInput.h"
#include "pso/unk/TLobby.h"
#include "pso/math/AngleLookup.h"
#include "pso/enemy/shinowa/TObjEneMe3ShinowaReal_8002ADD8.h"

const char *TWindowCtrl__name = "TWindowCtrl";
/* frame of the open sequence at which each window appears: split screen / single player */
static const s16 split_open_times[6] = {0, 4, 8, 12, 0, 0};
static const s16 open_times[4] = {24, 30, 36, 0};


typedef struct Ctrl_8024B8A0 {
    u8 pad0[0x1E];
    s16 timer;
    u8 pad20[4];
    u32 color;
} Ctrl_8024B8A0;


extern "C" {
void *get_player_by_client_id(s32 i);

saddr TWindowCtrl__sub_8024B7D4(s32 n) {
    s32 i;
    TWindowSimpleStatus *status;
    TObjPlayer *player;

    if (TWindowCtrl::instance == NULL) {
        return 0;
    }
    if (get_current_floor_area() == AREA_LOBBY) {
        return 0;
    }
    for (i = 0; i < 3; i++) {
        status = TWindowCtrl::instance->simple_status[i];
        if (status != NULL && status->sub_80244994() != 0 && n-- == 0) {
            player = (TObjPlayer *)get_player_by_client_id(((TWindowSimpleStatus *)status)->get_width());
            if (player == NULL) {
                return 0;
            }
            return (saddr)player->get_name();
        }
    }
    return 0;
}

#pragma push
#pragma fp_contract on
void TWindowCtrl::update_pulse_color() {
    Ctrl_8024B8A0 *o = (Ctrl_8024B8A0 *)this;
    f32 t;
    f32 a;
    t = (u32)o->timer % 100;
    if (t > 50.0f) {
        t = 100.0f - t;
    }
    t = t / 100.0f;
    a = 0.85f * (1.0f + cos_table_lookup((s32)(65536.0f * t)));
    if (a > 1.0f) {
        a = 1.0f;
    }
    o->color = (u8)(s32)(53.0f * a + 19.0f * (1.0f - a)) |
               ((((u8)(s32)(255.0f * a + 187.0f * (1.0f - a)) << 16) | 0xFF000000) |
                ((u8)(s32)(174.0f * a + 83.0f * (1.0f - a)) << 8));
}
#pragma pop

s32 TWindowCtrl__sub_8024B000(void *, saddr);
s32 is_split_screen();

extern s32 local_client_id;

void TWindowCtrl__sub_8024B9C0(void *arg0) {
    if ((u32) *(u32 *)((s8 *)arg0 + 0x30) != 0U) {
        if (TWindowCtrl::is_slot_visible(local_client_id) != 0) {
            ((TWindowLockOn *)(*(uaddr *)((s8 *)arg0 + 0x30)))->request_close();
            return;
        }
        window_request_show((void *)(*(uaddr *)((s8 *)arg0 + 0x30)));
    }
}

void TWindowCtrl::update_trade_window() {
    if (this->m_34 != NULL) {
        if ((TWindowCtrl::is_slot_visible(local_client_id) != 0) || (TWindowCtrl__sub_8024B000(this, local_client_id) != 0) || ((is_split_screen() != 0) && (TRaderMapCore::is_active() == 0))) {
            ((TWindowLockOn *)(this->m_34))->request_close();
            return;
        }
        window_request_show((void *)this->m_34);
    }
}


void TWindowCtrl::handle_controller() {
    saddr arg0 = (saddr)this;
    if ((get_current_floor_area() == AREA_LOBBY) && (TWindowCtrl::is_slot_visible(local_client_id) == 0) && (TWindowCtrl__sub_8024B000((void *)arg0, (s32)local_client_id) == 0) && (TWindowCtrl::has_player_active_menu(local_client_id) == 0) && (test_pressed_buttons_packed(&controller_input_state.controllers[0], fn_8002AE08(local_client_id)) != 0)) {
        TWindowCtrlMain::advance_card_status(local_client_id);
    }
}

}

extern "C" void TWindowCtrl__sub_8024BB30(TWindowCtrl *ctrl);

void TWindowCtrl__sub_8024BB30(TWindowCtrl *ctrl) {
    u32 i;
    for (i = 0; i < 4; i++) {
        TWindowFukidasi *child = ctrl->balloons[i];
        if (child != 0 && child->all_parents_unqueued_for_destruction() == 0) {
            if (ctrl->window_id == child->get_speaker_id()) {
                ctrl->window_id = 0xFFFF;
            }
            ctrl->balloons[i] = 0;
        }
    }
}

extern "C" {




void TWindowCtrl::update_trade_request_window() {
    if ((is_trade_active() == 0) || (TWindowCtrl::has_player_active_menu(local_client_id) != 0) || (TWindowCtrl::is_slot_visible(local_client_id) != 0) || (this->m_3c != 0U) || (((uaddr) *(void * *)&this->m_38 != 0U) && (TWindowCtrl__sub_8024701C(reinterpret_cast<TWindowChat *>(*(void * *)&this->m_38)) != 0))) {
        if (trade_request != NULL) {
            trade_request->queue_destruction();
            trade_request = NULL;
        }
    } else if (trade_request == NULL) {
        trade_request = new TWindowTradeRequest(this);
    }
}

void TWindowCtrl::update_com_card_window() {
    TWindowGetComCard *temp_r3;
    uaddr temp_r3_2;
    TWindowGetComCard *temp_r3_3;
    temp_r3 = this->m_3c;
    if ((temp_r3 != NULL) && (temp_r3->all_parents_unqueued_for_destruction() == 0)) {
        this->m_3c = NULL;
    }
    if ((is_guild_card_receive_active() == 0) || (TWindowCtrl::has_player_active_menu(local_client_id) != 0) || (TWindowCtrl::is_slot_visible(local_client_id) != 0) || (TWindowCtrl::get_flag_bit5() != 0) || (trade_request != NULL) || ((temp_r3_2 = this->m_38, ((temp_r3_2 == 0U) == 0)) && (TWindowCtrl__sub_8024701C(reinterpret_cast<TWindowChat *>((void *)temp_r3_2)) != 0))) {
        temp_r3_3 = this->m_3c;
        if (temp_r3_3 != NULL) {
            temp_r3_3->queue_destruction();
            this->m_3c = NULL;
        }
    } else if (this->m_3c == NULL) {
        this->m_3c = new TWindowGetComCard(this);
    }
}

s32 apply_default_vec__11TWindowCtrlFll(void *, s32);
}
s32 chat_accept_submission(saddr arg0);
extern "C" {


void TWindowCtrl::update_window_visibility() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r3;
    s32 current_target_id;

    if ((u32) this->m_38 != 0U) {
        temp_r3 = this->submit_cooldown;
        if (temp_r3 > 0) {
            this->submit_cooldown = (temp_r3 - 1);
        }
        if (get_player_by_client_id(local_client_id) == 0U) {
            ((TWindowChat *)(this->m_38))->update();
            return;
        }
        current_target_id = TObjPlayer::get_current_target_id();
        if ((TWindowCtrl::get_display_flag() != 0) || (TWindowCtrl::has_player_active_menu(local_client_id) != 0) || (TWindowCtrl::is_slot_visible(local_client_id) != 0) || (apply_default_vec__11TWindowCtrlFll(arg0, local_client_id) != 0) || (((u16)current_target_id != 0xffffU) && ((s32)(u16)current_target_id != (s32) local_client_id))) {
            ((TWindowChat *)(this->m_38))->update();
            return;
        }
        ((TWindowChat *)(this->m_38))->open_input();
        if ((((TWindowChat *)(this->m_38))->is_mode_bit4() != 0) && (chat_accept_submission((saddr)&this->m_94) != 0)) {
            TWindowChat__sub_80247E50(reinterpret_cast<TWindowChat *>(m_38));
        }
        if (((TWindowChat *)(this->m_38))->is_visible() != 0) {
            TWindowChat__sub_80247DFC(reinterpret_cast<TWindowChat *>(m_38));
        }
    }
}
}

typedef struct Win_8024BE80 {
    u8 pad0[0x34];
    f32 y;
    u8 pad38[0x50 - 0x38];
    s32 fade;
} Win_8024BE80;

typedef struct Ctrl_8024BE80 {
    u8 pad0[0x78];
    Win_8024BE80 *slots[3];
} Ctrl_8024BE80;


void *get_player_by_client_id(s32);
void window_request_show(void *);
extern "C" {
void TWindowCtrl::update_party_status_rows() {
    f32 y;
    u32 i;
    void *pl;
    Win_8024BE80 *w;
    y = ((TWindowLockOn *)(0xAB))->get_target_distance();
    for (i = 0; i < 3; i++) {
        w = ((Ctrl_8024BE80 *)this)->slots[i];
        if (w != NULL && ((TWindowCtrl *)w)->is_flag_2_set() == 0) {
            pl = get_player_by_client_id(((TWindowSimpleStatus *)w)->get_width());
            if (pl == NULL || TWindowCtrl::has_player_active_menu(local_client_id) != 0 ||
                TWindowCtrl::is_slot_visible(local_client_id) != 0 || TWindowCtrl__sub_8024B048(this) != 0 ||
                ((TObjPlayer *)pl)->is_script_controlled() != 0 ||
                (((TObjChara *)pl)->obj_isState3_324() != 0 &&
                 (((TObjPlayer *)pl)->get_field_828() != 0 || static_cast<TObjPlayer *>(pl)->get_npc_controller() == 0xFFFF))) {
                ((TWindowLockOn *)w)->request_close();
            } else {
                window_request_show(w);
                if (w->y != y) {
                    w->y = y;
                    w->fade = 0xF;
                }
                y += 55.0f;
            }
        }
    }
}
}

extern "C" {

void TWindowCtrl__sub_8024BB30(TWindowCtrl *ctrl);

void TWindowCtrl::update() { update_party_status_rows(); update_window_visibility(); update_com_card_window(); update_trade_request_window(); TWindowCtrl__sub_8024BB30(this); handle_controller(); update_trade_window(); TWindowCtrl__sub_8024B9C0(this); update_pulse_color(); }

}

typedef struct Win_8024C024 {
    u8 pad0[0x50];
    s32 fade;
} Win_8024C024;

typedef struct Ctrl_8024C024 {
    u8 pad0[0x1E];
    s16 timer;
    s16 step;
    u8 pad22[0x48 - 0x22];
    Win_8024C024 *split[12];
    Win_8024C024 *slots[3];
} Ctrl_8024C024;

extern "C" {
void TWindowCtrl::update_open_sequence() {
    Ctrl_8024C024 *o = (Ctrl_8024C024 *)this;
    if (is_split_screen() != 0) {
        if (o->timer == split_open_times[o->step]) {
            if (o->split[o->step] != NULL) {
                ((TObject *)(o->split[o->step]))->clear_update_suspension();
            }
            o->step++;
        }
    } else {
        if (o->timer == open_times[o->step]) {
            if (o->slots[o->step] != NULL) {
                ((TObject *)(o->slots[o->step]))->clear_update_suspension();
                ((TWindowCtrl *)o)->update_party_status_rows();
                o->slots[o->step]->fade = 0;
            }
            o->step++;
        }
    }
    if (o->timer > 30000) {
        o->timer -= 10000;
    }
    o->timer++;
}

}

void TWindowCtrl::render() {  }
void TWindowCtrl::run_task() { update_open_sequence(); update(); TLobby::update_game_modes(); }
