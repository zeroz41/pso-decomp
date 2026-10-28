#include "types.h"
#include "pso/misc/TWindowCtrl_8024B7D4.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/misc/TWindowSimpleStatus.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TWindowCtrl_8024B9C0.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/misc/TWindowLockOn.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/misc/TWindowCtrlMain.h"
#include "pso/misc/TWindowSubTradeMain.h"
#include "pso/misc/TWindowSubShortMail_80246CB8.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/TObject.h"
#include "pso/misc/TWindowChat.h"
#include "pso/misc/TNpcPlayer.h"
#include "pso/map/CurrentArea.h"

typedef struct Ctrl_8024B8A0 {
    u8 pad0[0x1E];
    s16 timer;
    u8 pad20[4];
    u32 color;
} Ctrl_8024B8A0;

typedef struct Ctrl_8024B7D4 {
    u8 pad0[0x78];
    TWindowSimpleStatus *status[3];
} Ctrl_8024B7D4;

extern "C" {
f32 cos_table_lookup(s32);
void *get_player_by_client_id(s32 i);
s32 get_width__19TWindowSimpleStatusFv(void *);
extern TWindowCtrl *TWindowCtrl__active_window;

s32 TWindowCtrl__sub_8024B7D4(s32 n) {
    s32 i;
    TWindowSimpleStatus *status;
    TObjPlayer *player;

    if (TWindowCtrl__active_window == NULL) {
        return 0;
    }
    if (get_current_area() == 0xF) {
        return 0;
    }
    for (i = 0; i < 3; i++) {
        status = ((Ctrl_8024B7D4 *)TWindowCtrl__active_window)->status[i];
        if (status != NULL && status->sub_80244994() != 0 && n-- == 0) {
            player = (TObjPlayer *)get_player_by_client_id(get_width__19TWindowSimpleStatusFv(status));
            if (player == NULL) {
                return 0;
            }
            return (s32)player->get_name();
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

}

extern "C" {

s32 has_player_active_menu__11TWindowCtrlFv(s32);
s32 TWindowCtrl__sub_8024B000(void *, s32);
s32 is_slot_visible__11TWindowCtrlFv(s32);
s32 TWindowShortListCtrl__check_controller_button(void *, s32, s32 *);
s32 is_split_screen();
s32 fn_8002AE08(s32);

extern s32 local_client_id;

void TWindowCtrl__sub_8024B9C0(void *arg0) {
    if ((u32) *(u32 *)((s8 *)arg0 + 0x30) != 0U) {
        if (is_slot_visible__11TWindowCtrlFv(local_client_id) != 0) {
            ((TWindowLockOn *)(*(u32 *)((s8 *)arg0 + 0x30)))->request_close();
            return;
        }
        window_request_show((void *)(*(u32 *)((s8 *)arg0 + 0x30)));
    }
}

void TWindowCtrl::update_trade_window() {
    if ((u32) this->m_34 != 0U) {
        if ((is_slot_visible__11TWindowCtrlFv(local_client_id) != 0) || (TWindowCtrl__sub_8024B000(this, local_client_id) != 0) || ((is_split_screen() != 0) && (TRaderMapCore::is_active() == 0))) {
            ((TWindowLockOn *)(this->m_34))->request_close();
            return;
        }
        window_request_show((void *)this->m_34);
    }
}

extern u8 controller_input_state[];

void TWindowCtrl::handle_controller() {
    s32 arg0 = (s32)this;
    if ((get_current_area() == 0xF) && (is_slot_visible__11TWindowCtrlFv(local_client_id) == 0) && (TWindowCtrl__sub_8024B000((void *)arg0, (s32)local_client_id) == 0) && (has_player_active_menu__11TWindowCtrlFv(local_client_id) == 0) && (TWindowShortListCtrl__check_controller_button(controller_input_state + 0x20, fn_8002AE08(local_client_id), (s32 *)controller_input_state) != 0)) {
        TWindowCtrlMain::advance_card_status(local_client_id);
    }
}

}

struct Obj_8024BB30 { u8 pad[0x84]; TWindowCtrl *children[4]; };

extern "C" void TWindowCtrl__sub_8024BB30(TWindowCtrl *ctrl);

void TWindowCtrl__sub_8024BB30(TWindowCtrl *ctrl) {
    u32 i;
    for (i = 0; i < 4; i++) {
        TWindowCtrl *child = ((Obj_8024BB30 *)ctrl)->children[i];
        if (child != 0 && child->all_parents_unqueued_for_destruction() == 0) {
            if (ctrl->m_28 == child->get_flags()) {
                ctrl->m_28 = 0xFFFF;
            }
            ((Obj_8024BB30 *)ctrl)->children[i] = 0;
        }
    }
}

extern "C" {

s32 has_player_active_menu__11TWindowCtrlFv(s32);
s32 is_slot_visible__11TWindowCtrlFv(s32);
void *TWindowTradeRequest__ct(void *, void *);
void *__nw__7TObjectFUl(s32);
s32 TWindowCtrl__sub_8024701C(void *);

extern s32 local_client_id;

void TWindowCtrl::update_trade_request_window() {
    void *var_r0;

    if ((is_trade_active() == 0) || (has_player_active_menu__11TWindowCtrlFv(local_client_id) != 0) || (is_slot_visible__11TWindowCtrlFv(local_client_id) != 0) || ((u32) this->m_3c != 0U) || (((u32) *(void * *)&this->m_38 != 0U) && (TWindowCtrl__sub_8024701C(*(void * *)&this->m_38) != 0))) {
        if ((u32) this->m_40 != 0U) {
            queue_destruction__7TObjectFv(*(void * *)&this->m_40);
            this->m_40 = 0U;
        }
    } else if ((u32) this->m_40 == 0U) {
        var_r0 = __nw__7TObjectFUl(0x24);
        if (var_r0 != NULL) {
            var_r0 = TWindowTradeRequest__ct(var_r0, this);
        }
        *(void * *)&this->m_40 = var_r0;
    }
}

}

extern "C" {
u32 TWindowGetComCard__ct(int, void *);
extern s32 local_client_id;
void TWindowCtrl::update_com_card_window() {
    u8 *arg0 = (u8 *)this;
    u32 temp_r3;
    u32 temp_r3_2;
    u32 temp_r3_3;
    u32 temp_r3_4;
    u32 var_r0;
    temp_r3 = this->m_3c;
    if ((temp_r3 != 0U) && (((TObject *)temp_r3)->all_parents_unqueued_for_destruction() == 0)) {
        this->m_3c = 0U;
    }
    if ((is_guild_card_receive_active() == 0) || (has_player_active_menu__11TWindowCtrlFv(local_client_id) != 0) || (is_slot_visible__11TWindowCtrlFv(local_client_id) != 0) || (TWindowCtrl::get_flag_bit5() != 0) || ((u32) this->m_40 != 0U) || ((temp_r3_2 = this->m_38, ((temp_r3_2 == 0U) == 0)) && (TWindowCtrl__sub_8024701C((void *)temp_r3_2) != 0))) {
        temp_r3_3 = this->m_3c;
        if (temp_r3_3 != 0U) {
            queue_destruction__7TObjectFv((void *)temp_r3_3);
            this->m_3c = 0U;
        }
    } else if ((u32) this->m_3c == 0U) {
        temp_r3_4 = (u32)__nw__7TObjectFUl(0x2C);
        var_r0 = temp_r3_4;
        if (var_r0 != 0U) {
            var_r0 = TWindowGetComCard__ct(temp_r3_4, arg0);
        }
        this->m_3c = var_r0;
    }
}

}

extern "C" {

void *get_player_by_client_id(s32 i);
s32 has_player_active_menu__11TWindowCtrlFv(s32);
s32 apply_default_vec__11TWindowCtrlFll(void *, s32);
s32 is_slot_visible__11TWindowCtrlFv(s32);
}
s32 chat_accept_submission(s32 arg0);
extern "C" {
void TWindowChat__sub_80247DFC(u8 *arg0);
void TWindowChat__sub_80247E50(u8 *arg0);

extern s32 local_client_id;

void TWindowCtrl::update_window_visibility() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r3;
    s32 current_target_id;

    if ((u32) this->m_38 != 0U) {
        temp_r3 = *(s16 *)&this->m_22;
        if (temp_r3 > 0) {
            *(s16 *)&this->m_22 = (temp_r3 - 1);
        }
        if (get_player_by_client_id(local_client_id) == 0U) {
            ((TWindowChat *)(this->m_38))->update();
            return;
        }
        current_target_id = TObjPlayer::get_current_target_id();
        if ((TWindowCtrl::get_display_flag() != 0) || (has_player_active_menu__11TWindowCtrlFv(local_client_id) != 0) || (is_slot_visible__11TWindowCtrlFv(local_client_id) != 0) || (apply_default_vec__11TWindowCtrlFll(arg0, local_client_id) != 0) || (((u16)current_target_id != 0xffffU) && ((s32)(u16)current_target_id != (s32) local_client_id))) {
            ((TWindowChat *)(this->m_38))->update();
            return;
        }
        ((TWindowChat *)(this->m_38))->open_input();
        if ((((TWindowChat *)(this->m_38))->is_mode_bit4() != 0) && (chat_accept_submission((s32)&this->m_94) != 0)) {
            TWindowChat__sub_80247E50((u8 *)this->m_38);
        }
        if (((TWindowChat *)(this->m_38))->is_visible() != 0) {
            TWindowChat__sub_80247DFC((u8 *)this->m_38);
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

extern "C" {
s32 obj_isState3_324__9TObjCharaFv(void *);
s32 is_script_controlled__10TObjPlayerFv(void *);
void *get_player_by_client_id(s32);
}
void window_request_show(void *);
extern "C" {
s32 has_player_active_menu__11TWindowCtrlFv(s32);
int TWindowCtrl__sub_8024B048(void *p);
s32 is_slot_visible__11TWindowCtrlFv(s32);
f32 get_target_distance__13TWindowLockOnFv(s32);
extern s32 local_client_id;
void TWindowCtrl::update_party_status_rows() {
    f32 y;
    u32 i;
    void *pl;
    Win_8024BE80 *w;
    y = get_target_distance__13TWindowLockOnFv(0xAB);
    for (i = 0; i < 3; i++) {
        w = ((Ctrl_8024BE80 *)this)->slots[i];
        if (w != NULL && ((TWindowCtrl *)w)->is_flag_2_set() == 0) {
            pl = get_player_by_client_id(get_width__19TWindowSimpleStatusFv(w));
            if (pl == NULL || has_player_active_menu__11TWindowCtrlFv(local_client_id) != 0 ||
                is_slot_visible__11TWindowCtrlFv(local_client_id) != 0 || TWindowCtrl__sub_8024B048(this) != 0 ||
                is_script_controlled__10TObjPlayerFv(pl) != 0 ||
                (obj_isState3_324__9TObjCharaFv(pl) != 0 &&
                 (((TObjPlayer *)pl)->get_field_828() != 0 || ((TNpcPlayer *)pl)->get_action_flags() == 0xFFFF))) {
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
