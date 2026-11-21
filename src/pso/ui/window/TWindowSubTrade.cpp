#include "pso/ui/window/TWindowMainMenu.h"
// ---- pso/ui/window/TWindowSubTrade_802B1AB4
#include "types.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801A6D60.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/ui/window/TWindowSubComCard_802A5748.h"
class TChCrTagPlBack;
#include "pso/ui/window/TWindowSubTrade.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/chat/TWindowSubShortMail.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"

#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowCtrl_8024A054.h"
#include "pso/ui/window/TWindowSubComCard_80244774.h"
#include "pso/network/TradeSession.h"
#include "pso/unk/text_802D298C.h"


#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowMessageYesNo.h"
#include "pso/object/warp/TObjCityMainWarp.h"

#pragma readonly_strings on

struct VBase_18_f23ffb { char pad[0x18]; };

struct VObj_18_f23ffb : VBase_18_f23ffb {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual s32 m10();
};

struct VBase_802B1B80 { char pad[0x18]; };

struct VObj_802B1B80 : VBase_802B1B80 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual s32 m10();
};

extern "C" {
s32 text_builder_append();
}
void text_builder_reset(void);
extern "C" {
saddr get_window_layout_position(int);
const char *TWindowSubTrade__name = "TWindowSubTrade"; // TWindowSubTrade__name
// Player message window position (x, y).
extern const f32 lbl_80470AA8[2] = {384.0f, 120.0f};
extern s32 local_client_id;
s32 is_trade_range_bit_set(s32 client);
TWindowSubComCardList *TWindowSubComCard__sub_802B1C1C(TWindowSubTrade *);
s32 play_sound_effect(int, int, int, int);
extern s32 controller_input_state[];
}

// Built with deferred code generation (the vtable precedes run_task's jump
// table in .data), so the functions are written from the last one back.
TWindowSubTrade::TWindowSubTrade(TWindowMainMenu *parent, s32 client) : TObject(parent) {
    this->m_name = TWindowSubTrade__name;
    parent_menu = parent;
    m_20 = client;
    this->m_24 = 4;
    this->m_player_list = 0;
    this->m_message_window = 0;
    this->m_confirm_prompt = 0;
    TLobby__sub_802D2A50((uaddr)this);
    this->m_1c = 0;
}

TWindowSubTrade::~TWindowSubTrade() {
    TLobby__sub_802D2A2C((uaddr)this);
    TLobby::check_flags_and_proceed();
    if (this->m_confirm_prompt != 0U) {
        ((TWindowSubComCard *)(this->m_confirm_prompt))->close();
        this->m_confirm_prompt = 0U;
    }
    if (this->m_message_window != 0U) {
        ((TWindowBase *)this->m_message_window)->close();
        this->m_message_window = 0U;
    }
    if (this->m_player_list != 0U) {
        ((TWindowBase *)this->m_player_list)->close();
        this->m_player_list = 0U;
    }
}

void TWindowSubTrade::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r30;
    s32 temp_r5;
    temp_r30 = is_player_input_active((this->m_20));
    switch (this->m_1c) {
    case 0:
    case 1:
        if ((u32) this->m_confirm_prompt != 0U) {
            ((TWindowSubComCard *)(this->m_confirm_prompt))->close();
            this->m_confirm_prompt = 0U;
        }
        if ((u32) this->m_message_window != 0U) {
            ((TWindowBase *)this->m_message_window)->close();
            this->m_message_window = 0U;
        }
        if ((u32) this->m_player_list == 0U) {
            this->m_player_list = (uaddr)TWindowSubComCard__sub_802B1C1C(this);
        }
        ((TWindowSubComCard *)(this->m_player_list))->clear_flag_and_release();
        this->m_1c = 2U;
    case 2:
        if (((TWindowMenu *)(this->m_player_list))->is_cancelled() != 0) {
            parent_menu->vfunc_9();
            this->m_1c = 7U;
        } else if (((TWindowMenu *)(this->m_player_list))->is_decided() != 0) {
            this->m_1c = 3U;
        }
        break;
    case 3:
        if (this->m_player_list != 0) {
            this->m_24 = ((TWindowMenu *)this->m_player_list)->get_selected_value();
        }
        if ((u32) this->m_confirm_prompt == 0U) {
            this->m_confirm_prompt = ((TWindowSubTrade *)arg0)->open_trade_confirm_prompt(this->m_24);
        }
        this->m_1c = 4U;
    case 4:
        if (((TWindowSubComCard *)(this->m_confirm_prompt))->get_card_data() != 0) {
            this->m_1c = 1U;
        } else if (((TWindowMessageYesNo *)(this->m_confirm_prompt))->is_child_visible() != 0) {
            if (((TWindowSubComCard *)(this->m_confirm_prompt))->get_slot_or_neg1() == 0) {
                this->m_1c = 5U;
            } else {
                this->m_1c = 1U;
            }
        }
        break;
    case 5:
        if ((u32) this->m_confirm_prompt != 0U) {
            ((TWindowSubComCard *)(this->m_confirm_prompt))->close();
            this->m_confirm_prompt = 0U;
        }
        if ((u32) this->m_message_window == 0U) {
            this->m_message_window = ((TWindowSubTrade *)arg0)->open_player_message_window(this->m_24, (saddr) (TWindowSubStatusDisp::get_message_10(0xD7)));
        }
        send_6xA6_modify_trade_proposal((this->m_24));
        this->m_1c = 6U;
    case 6:
        temp_r5 = temp_r30 * 0x50;
        if ((TWindowShortListCtrl__check_controller_button((void *) ((u8 *)(((u8 *)controller_input_state + temp_r5)) + 0x20), 2) != 0) || (test_controller_flag_4c_color((void *) ((u8 *)controller_input_state + 0x160), 2) != 0)) {
            play_sound_effect(0x52F16, 0, 0, 0);
            TLobby::cancel_trade();
            this->m_1c = 1U;
        }
        break;
    case 7:
        break;
    }
}

void TWindowSubTrade::render() {  }

extern "C" {
// The caller passes its TWindowSubTrade in r3; the body never reads it.
TWindowSubComCardList *TWindowSubComCard__sub_802B1C1C(TWindowSubTrade *) {
    s32 i;
    TObjPlayer *player;
    TWindowSubComCardList *list;

    list = (TWindowSubComCardList *)(saddr)create_titled_window_menu_default((s32)(get_window_layout_position(0x5A)), 4, (saddr)(TWindowSubStatusDisp::get_message_10(0x1F)));
    for (i = 0; i < 4; i++) {
        if (i == local_client_id) {
            continue;
        }
        player = get_player_by_client_id(i);
        if (player == NULL) {
            continue;
        }
        if (player->is_script_controlled() != 0) {
            continue;
        }
        if (player->obj_isState3_324() != 0) {
            continue;
        }
        if (is_trade_range_bit_set(i)) {
            TObjCityMainWarp::forward_trade_action_default(list, (saddr)player->get_name(), 7, i);
        } else {
            add_gray_text_entry((TWindowSubTradeMain *)list, (const char *)(player->get_name()), 7, i);
        }
    }
    if (list->get_field_72() <= 0) {
        add_gray_text_entry((TWindowSubTradeMain *)list, (const char *)(TWindowSubStatusDisp::get_message_10(0xD2)), 7, 0);
    }
    list->set_flag70_bit10();
    list->set_scroll_target(224.0f, 88.0f);
    return list;
}
}

s32 TWindowSubTrade::open_player_message_window(s32 arg1, s32 arg2) {
    saddr r;
    VObj_802B1B80 *p;
    p = (VObj_802B1B80 *)get_player_by_client_id(arg1);
    text_builder_reset();
    if (p != NULL) {
        ((s32 (*)(s32))text_builder_append)(p->m10());
    }
    ((s32 (*)(s32))text_builder_append)(arg2);
    r = (saddr)TWindowMessage::create(get_window_layout_position(0x5B), lbl_80470AA8, 1, this->m_20);
    ((TWindowMessage *)r)->append_line((saddr)get_shared_text_buffer(), 0x82);
    return r;
}

s32 TWindowSubTrade::open_trade_confirm_prompt(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    saddr temp_r29;
    u8 *player;
    player = (u8 *)(get_player_by_client_id(arg1));
    text_builder_reset();
    if (player != NULL) {
        ((VObj_18_f23ffb *)(player))->m10();
        text_builder_append();
    }
    TWindowSubStatusDisp::get_message_10(0xD6);
    text_builder_append();
    temp_r29 = (saddr)TWindowMessageYesNo::create((void *)(arg0), (void *)(this->m_20), 0, 0);
    open_yes_no_prompt((TChCrTagPlBack *)((u8 *)temp_r29), (uaddr)(TWindowSubStatusDisp::get_message_10(0x20)), (saddr)(get_shared_text_buffer()), (s32)(get_window_layout_position(0x5B)), 384.0f);
    set_menu_selected_index((TWindowSubComCard *)temp_r29, 1);
    ((TWindowMessageYesNo *)temp_r29)->set_choice_menu_flag70_bit10();
    return temp_r29;
}
