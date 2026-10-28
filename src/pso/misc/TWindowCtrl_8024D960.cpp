#include "types.h"
#include "pso/misc/TWindowMainMenu.h"
#include "pso/misc/TUnk_804CE018.h"
#include "pso/misc/TWindowLockOn.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/TObject.h"
#include "pso/misc/TKeyBoardControl.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TQuestVmDownLoadServer.h"
#include "pso/misc/TWindowCtrlMain.h"
#include "pso/misc/TWindowCtrlPlayer.h"
#include "pso/misc/TWindowSubEquip.h"
#include "pso/misc/TWindowSubTradeMain.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/FloorArea.h"

struct Pad_8024DCE8 { u8 pad[0x20]; u8 btn[0x30]; };

struct WBase_8024DCE8 { u8 pad[0x18]; };

struct W_8024DCE8 : WBase_8024DCE8 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
};

extern "C" {
u32 get_player_by_client_id(int);
}
void window_request_show(void *arg0);
extern "C" {
s32 is_split_screen();
s32 TWindowCtrl__sub_8024C7F8(void *);
s32 TWindow__close(void *);
s32 TWindowCtrl__sub_8024A314();
s32 TWindowCtrl__sub_8024C7C4(void *);
s32 TWindowCtrl__sub_8024C7E0(void *);
s32 bind_target__13TWindowLockOnFv(void *, s32);
u32 create_for_target__13TWindowLockOnFlUs(int, s32);
s32 TKeyBoardControl__sub_801A58B0();
s32 TKeyBoardControl__sub_801A58D8();
s32 get_function_key_menu__16TKeyBoardControlFPv(void *arg0);
void queue_destruction__7TObjectFv(void *);
s32 fn_8002AE08(void *p);
s32 TWindowShortListCtrl__check_controller_button(void *, int);
s32 is_on_current_screen__11TCameraCtrlFv(void *, int);
u16 get_current_target_id__10TObjPlayerFv();
void *__nw__7TObjectFUl(int);
s32 is_player_input_active(s32);
int TWindowCtrl__sub_8024C7D4(void *p);
void *TWindowShortListCtrl__ct(void *, void *, int);
extern Pad_8024DCE8 controller_input_state[];
u32 is_action_active__10TObjPlayerFv(void *);
int TWindowMainMenu__sub_8024E3F4(void *p);
void TWindowCtrl__sub_8024DAAC(void *arg0);
s32 TWindowMainMenu__sub_8024E3E0(void *);
s32 get_window_layout_position(s32);

s32 TWindowCtrl::get_active_menu() {
    void *p = *(void **)((s8 *)this + 0x28);
    if (p == 0) {
        return 0;
    }
    return TWindowMainMenu__sub_8024E3E0(p);
}

s32 get_function_key_menu__16TKeyBoardControlFPv(void *arg0) {
    if (is_split_screen() != 0) {
        return 0x1F;
    }
    if (TKeyBoardControl__sub_801A58B0() != 0) {
        return 0x1F;
    }
    if (TKeyBoardControl__sub_801A58D8() == 0) {
        return 0x1F;
    }
    if (TKeyBoardControl::is_key_down(0x44) != 0) {
        return 0x13;
    }
    if (TKeyBoardControl::is_key_down(0x45) != 0) {
        return 0x15;
    }
    if (TKeyBoardControl::is_key_down(0x46) != 0) {
        return 0xE;
    }
    if (TKeyBoardControl::is_key_down(0x47) != 0) {
        return 0x1A;
    }
    if (TKeyBoardControl::is_key_down(0x48) != 0) {
        return 0x17;
    }
    if (TKeyBoardControl::is_key_down(0x49) != 0) {
        return 0xC;
    }
    if (TKeyBoardControl::is_key_down(0x4A) != 0) {
        return 0xB;
    }
    return (TKeyBoardControl::is_key_down(0x4B) != 0) ? 0 : 0x1F;
}

void TWindowCtrl__sub_8024DAAC(void *arg0) {
    s32 temp_r4;

    temp_r4 = *(s16 *)((s8 *)arg0 + 0x20);
    if (temp_r4 > 0) {
        *(s16 *)((s8 *)arg0 + 0x20) = (temp_r4 - 1);
    }
}

void TWindowCtrl::update_short_list_request() {
    s32 idx;
    u16 id;
    u8 *btn;
    void *o;
    if (*(void **)((s8 *)this + 0x3C) != NULL && ((TObject *)(*(void **)((s8 *)this + 0x3C)))->all_parents_unqueued_for_destruction() == 0) {
        *(void **)((s8 *)this + 0x3C) = NULL;
    }
    if (*(void **)((s8 *)this + 0x34) != NULL && ((TWindowCtrl *)(*(void **)((s8 *)this + 0x34)))->is_flag_2_set() == 0) {
        if (get_player_by_client_id(*(s32 *)&this->m_24) == 0) {
            if (*(void **)((s8 *)this + 0x3C) != NULL) {
                queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x3C));
                *(void **)((s8 *)this + 0x3C) = NULL;
            }
        } else {
            idx = is_player_input_active(*(s32 *)&this->m_24);
            id = get_current_target_id__10TObjPlayerFv();
            if (get_active_menu() != 0 || is_visible() != 0 ||
                (id != 0xFFFF && id != *(s32 *)&this->m_24) || TWindowCtrl__sub_8024C7D4(this) != 0 ||
                TWindowCtrl::get_display_flag() != 0) {
                if (*(void **)((s8 *)this + 0x3C) != NULL) {
                    queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x3C));
                    *(void **)((s8 *)this + 0x3C) = NULL;
                }
            } else if (*(void **)((s8 *)this + 0x3C) == NULL && is_enabled() == 0) {
                if (is_on_current_screen__11TCameraCtrlFv(btn = controller_input_state[idx].btn, fn_8002AE08((void *)(*(s32 *)&this->m_24))) != 0 &&
                    TWindowShortListCtrl__check_controller_button(btn, 0x200) != 0) {
                    o = __nw__7TObjectFUl(0x3C);
                    if (o != NULL) {
                        o = TWindowShortListCtrl__ct(o, this, *(s32 *)&this->m_24);
                    }
                    *(void **)((s8 *)this + 0x3C) = o;
                }
            }
        }
    }
}

void TWindowCtrl::show_active_window() {
    if ((u32) this->m_2c != 0U) {
        if (is_visible() != 0) {
            ((TWindowLockOn *)(this->m_2c))->request_close();
            return;
        }
        window_request_show((void *)this->m_2c);
        if (get_active_menu() != 0) {
            ((TWindowCtrl *)(this->m_2c))->set_position((void *)(get_window_layout_position(0x21)));
            return;
        }
        ((TWindowCtrl *)(this->m_2c))->set_position((void *)(get_window_layout_position(0x20)));
    }
}

void TWindowCtrl::update_main_menu_request() {
    u32 p;
    s16 key;
    if (*(void **)((s8 *)this + 0x28) == NULL) {
        return;
    }
    p = get_player_by_client_id(this->m_24);
    if (p == 0) {
        return;
    }
    if (((TObjPlayer *)p)->is_inactive() == 0) {
        return;
    }
    if (is_visible() != 0 || TWindowCtrl__sub_8024C7D4(this) != 0) {
        (*(W_8024DCE8 **)((s8 *)this + 0x28))->m6();
        return;
    }
    {
        s32 idx = is_player_input_active(this->m_24);
        key = ((s16 (*)(void *))get_function_key_menu__16TKeyBoardControlFPv)(this);
        if (TWindowShortListCtrl__check_controller_button(controller_input_state[idx].btn, 0x108) == 0 && key == 0x1F) {
            return;
        }
    }
    if (get_active_menu() != 0) {
        if (TWindowMainMenu__sub_8024E3F4(this) == 0) {
            (*(W_8024DCE8 **)((s8 *)this + 0x28))->m6();
        }
        return;
    }
    if (*(void **)((s8 *)this + 0x3C) != NULL) {
        queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x3C));
        *(void **)((s8 *)this + 0x3C) = NULL;
        return;
    }
    if (TWindowCtrl::get_active_sub() != 0) {
        TWindowCtrl::update_focused();
        return;
    }
    if (is_action_active__10TObjPlayerFv((void *) p) != 0) {
        return;
    }
    if (key == 0x1F) {
        (*(W_8024DCE8 **)((s8 *)this + 0x28))->m4();
        return;
    }
    ((TWindowMainMenu *)(*(void **)((s8 *)this + 0x28)))->try_open_battle_menu(key);
}

#pragma push
#pragma fp_contract on
void TWindowCtrl::update_target_info_window() {
    u8 *arg0 = (u8 *)this;
    if ((*(void **)((s8 *)arg0 + 0x38) != NULL) && ((((TObject *)(*(void **)((s8 *)arg0 + 0x38)))->all_parents_unqueued_for_destruction() == 0) || (((TUnk_804CE018 *)(*(u32 *)((s8 *)arg0 + 0x38)))->sub_80244994() == 0))) {
        *(u32 *)((s8 *)arg0 + 0x38) = 0U;
    }
    if ((TWindowCtrl__sub_8024C7E0(arg0) != 0) || (get_active_menu() != 0) || (((TWindowCtrl *)arg0)->is_visible() != 0) || (TWindowCtrl__sub_8024C7C4(arg0) != 0) || (TWindowCtrl__sub_8024A314() != 0)) {
        if ((u32) *(u32 *)((s8 *)arg0 + 0x38) != 0U) {
            TWindow__close(*(void **)((s8 *)arg0 + 0x38));
            *(u32 *)((s8 *)arg0 + 0x38) = 0U;
        }
    } else {
        s32 id = TObjPlayer::get_battle_ctrl_id((int) ((u16) *(s32 *)((s8 *)arg0 + 0x24)));
        if ((u16) id != 0xFFFF) {
            void *w = *(void **)((s8 *)arg0 + 0x38);
            if (w == NULL) {
                *(u32 *)((s8 *)arg0 + 0x38) = create_for_target__13TWindowLockOnFlUs((int) (*(s32 *)((s8 *)arg0 + 0x24)), id);
            } else {
                bind_target__13TWindowLockOnFv(w, id);
            }
        }
    }
}
#pragma pop

void TWindowCtrl::update_child_window_visibility() {
    u8 *arg0 = (u8 *)this;
    u32 temp_r31;
    if (((u32) this->m_34 != 0U) && (((TWindowCtrl *)((void *) this->m_34))->is_flag_2_set() == 0)) {
        temp_r31 = get_player_by_client_id(this->m_24);
        if ((get_active_menu() != 0) || (((TWindowCtrl *)arg0)->is_visible() != 0) || (((TWindowCtrl *)arg0)->is_enabled() != 0) || (temp_r31 == 0U)) {
            ((TWindowLockOn *)(this->m_34))->request_close();
            return;
        }
        window_request_show((void *)this->m_34);
    }
}

void TWindowCtrl::update_trade_window_visibility() {
    u8 *arg0 = (u8 *)this;
    if (((u32) this->m_30 != 0U) && (((TWindowCtrl *)((void *) this->m_30))->is_flag_2_set() == 0)) {
        if ((get_player_by_client_id(this->m_24) == 0U) || (((TWindowCtrl *)arg0)->is_visible() != 0) || (TWindowCtrl__sub_8024C7F8(arg0) != 0) || ((is_split_screen() != 0) && (get_active_menu() != 0))) {
            ((TWindowLockOn *)(this->m_30))->request_close();
            return;
        }
        window_request_show((void *)this->m_30);
    }
}

void TWindowCtrl::run_all_updates() { update_trade_window_visibility(); update_child_window_visibility(); update_target_info_window(); update_main_menu_request(); show_active_window(); update_short_list_request(); TWindowCtrl__sub_8024DAAC(this); }
#pragma push
#pragma scheduling off
void TWindowCtrlPlayer::sub_8024E0F0() {
    s16 temp_r3_3;
    u32 temp_r3;
    u32 temp_r3_2;
    switch (*(s16 *)&this->m_1e) {
    case 18:
        temp_r3 = this->m_30;
        if (temp_r3 != 0U) {
            ((TQuestVmDownLoadServer *)temp_r3)->clear_flag4_bit4();
        }
        break;
    case 38:
        if (is_current_area_item_enabled() != 0) {
            temp_r3_2 = this->m_34;
            if (temp_r3_2 != 0U) {
                ((TQuestVmDownLoadServer *)temp_r3_2)->clear_flag4_bit4();
            }
        }
        break;
    }
    temp_r3_3 = *(s16 *)&this->m_1e;
    if (temp_r3_3 > 0x7530) {
        *(s16 *)&this->m_1e = (temp_r3_3 - 0x2710);
    }
    *(s16 *)&this->m_1e = (s16) (*(s16 *)&this->m_1e + 1);
}
}
#pragma pop
