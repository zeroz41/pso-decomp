#include "pso/system/SoundEffect.h"
#include "pso/ui/window/TWindowMainMenu.h"
// ---- pso/ui/window/TWindowSubTrade_802B1AB4
#include "types.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/ControllerInput.h"
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
#include "pso/network/TradeSession.h"
#include "pso/unk/text_802D298C.h"


#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowMessageYesNo.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/player/PlayerSlots.h"

#pragma readonly_strings on

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
}

// Built with deferred code generation (the vtable precedes run_task's jump
// table in .data), so the functions are written from the last one back.
TWindowSubTrade::TWindowSubTrade(TWindowMainMenu *parent, s32 client) : TObject(parent) {
    this->m_name = TWindowSubTrade__name;
    parent_menu = parent;
    m_20 = client;
    this->m_24 = 4;
    this->m_player_list = NULL;
    this->m_message_window = NULL;
    this->m_confirm_prompt = NULL;
    TLobby__sub_802D2A50((uaddr)this);
    this->m_1c = 0;
}

TWindowSubTrade::~TWindowSubTrade() {
    TLobby__sub_802D2A2C((uaddr)this);
    TLobby::check_flags_and_proceed();
    if (this->m_confirm_prompt != NULL) {
        ((TWindowMessageYesNo *)(this->m_confirm_prompt))->close();
        this->m_confirm_prompt = NULL;
    }
    if (this->m_message_window != NULL) {
        m_message_window->close();
        this->m_message_window = NULL;
    }
    if (this->m_player_list != NULL) {
        m_player_list->close();
        this->m_player_list = NULL;
    }
}

void TWindowSubTrade::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r30;
    temp_r30 = is_player_input_active((this->m_20));
    switch (this->m_1c) {
    case 0:
    case 1:
        if (this->m_confirm_prompt != NULL) {
            ((TWindowMessageYesNo *)(this->m_confirm_prompt))->close();
            this->m_confirm_prompt = NULL;
        }
        if (this->m_message_window != NULL) {
            m_message_window->close();
            this->m_message_window = NULL;
        }
        if (this->m_player_list == NULL) {
            m_player_list = TWindowSubComCard__sub_802B1C1C(this);
        }
        m_player_list->clear_flag_and_release();
        this->m_1c = 2U;
    case 2:
        if (((TWindowMenu *)(this->m_player_list))->is_cancelled() != 0) {
            parent_menu->on_submenu_closed();
            this->m_1c = 7U;
        } else if (m_player_list->is_decided() != 0) {
            this->m_1c = 3U;
        }
        break;
    case 3:
        if (this->m_player_list != NULL) {
            this->m_24 = m_player_list->get_selected_value();
        }
        if (this->m_confirm_prompt == NULL) {
            this->m_confirm_prompt = ((TWindowSubTrade *)arg0)->open_trade_confirm_prompt(this->m_24);
        }
        this->m_1c = 4U;
    case 4:
        if (((TWindowMessageYesNo *)(this->m_confirm_prompt))->is_cancelled() != 0) {
            this->m_1c = 1U;
        } else if (m_confirm_prompt->is_child_visible() != 0) {
            if (((TWindowMessageYesNo *)(this->m_confirm_prompt))->get_selected_value() == 0) {
                this->m_1c = 5U;
            } else {
                this->m_1c = 1U;
            }
        }
        break;
    case 5:
        if (this->m_confirm_prompt != NULL) {
            ((TWindowMessageYesNo *)(this->m_confirm_prompt))->close();
            this->m_confirm_prompt = NULL;
        }
        if (this->m_message_window == NULL) {
            this->m_message_window = ((TWindowSubTrade *)arg0)->open_player_message_window(this->m_24, (saddr) (TWindowSubStatusDisp::get_message_10(0xD7)));
        }
        send_6xA6_modify_trade_proposal((this->m_24));
        this->m_1c = 6U;
    case 6:
        if ((test_pressed_buttons_packed(&controller_input_state.controllers[temp_r30], 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
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
            list->add_text_entry((saddr)player->get_name(), 7, i);
        } else {
            add_gray_text_entry((TWindowMenu *)list, (const char *)(player->get_name()), 7, i);
        }
    }
    if (list->get_field_72() <= 0) {
        add_gray_text_entry((TWindowMenu *)list, (const char *)(TWindowSubStatusDisp::get_message_10(0xD2)), 7, 0);
    }
    list->set_flag70_bit10();
    list->set_scroll_target(224.0f, 88.0f);
    return list;
}
}

TWindowMessage *TWindowSubTrade::open_player_message_window(s32 player, s32 arg2) {
    TWindowMessage *window;
    TObjPlayer *p = get_player_by_client_id(player);
    text_builder_reset();
    if (p != NULL) {
        ((s32 (*)(s32))text_builder_append)((saddr)p->get_name());
    }
    ((s32 (*)(s32))text_builder_append)(arg2);
    window = (TWindowMessage *)TWindowMessage::create(get_window_layout_position(0x5B), lbl_80470AA8, 1, this->m_20);
    window->append_line((saddr)get_shared_text_buffer(), 0x82);
    return window;
}

TWindowMessageYesNo *TWindowSubTrade::open_trade_confirm_prompt(s32 client) {
    TWindowMessageYesNo *prompt;
    TObjPlayer *player = get_player_by_client_id(client);
    text_builder_reset();
    if (player != NULL) {
        player->get_name();
        text_builder_append();
    }
    TWindowSubStatusDisp::get_message_10(0xD6);
    text_builder_append();
    prompt = (TWindowMessageYesNo *)TWindowMessageYesNo::create(this, m_20, NULL, NULL);
    open_yes_no_prompt(prompt, (uaddr)(TWindowSubStatusDisp::get_message_10(0x20)), (saddr)(get_shared_text_buffer()), (s32)(get_window_layout_position(0x5B)), 384.0f);
    prompt->set_menu_selected_index(1);
    prompt->set_choice_menu_flag70_bit10();
    return prompt;
}
