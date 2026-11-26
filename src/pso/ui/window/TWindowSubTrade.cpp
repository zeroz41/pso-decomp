#include "pso/system/SoundEffect.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228CC0.h"
// ---- pso/ui/window/TWindowSubTrade_802B1AB4
#include "types.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/ControllerInput.h"
#include "pso/unk/TLobby_8001D6A0.h"
class TChCrTagPlBack;
#include "pso/ui/window/TWindowSubTrade.h"
#include "pso/network/TLobby.h"
#include "pso/ui/chat/TWindowSubShortMail.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"

#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/network/TradeSession.h"


#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowMessageYesNo.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/player/PlayerSlots.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/network/client_id.h"

#pragma readonly_strings on

const char *TWindowSubTrade::class_name = "TWindowSubTrade"; // TWindowSubTrade::class_name
// Player message window position (x, y).
extern const f32 trade_message_window_size[2] = {384.0f, 120.0f};
TWindowSubComCardList *create_trade_partner_menu(TWindowSubTrade *);

// Built with deferred code generation (the vtable precedes run_task's jump
// table in .data), so the functions are written from the last one back.
TWindowSubTrade::TWindowSubTrade(TWindowMainMenu *parent, s32 client) : TObject(parent) {
    this->m_name = TWindowSubTrade::class_name;
    parent_menu = parent;
    client_id = client;
    this->selected_player = 4;
    this->m_player_list = NULL;
    this->m_message_window = NULL;
    this->m_confirm_prompt = NULL;
    claim_trade_sub_window(this);
    this->state = 0;
}

TWindowSubTrade::~TWindowSubTrade() {
    release_trade_sub_window(this);
    TLobby::check_flags_and_proceed();
    if (this->m_confirm_prompt != NULL) {
        this->m_confirm_prompt->close();
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
    s32 controller_index;
    controller_index = is_player_input_active((this->client_id));
    switch (this->state) {
    case 0:
    case 1:
        if (this->m_confirm_prompt != NULL) {
            this->m_confirm_prompt->close();
            this->m_confirm_prompt = NULL;
        }
        if (this->m_message_window != NULL) {
            m_message_window->close();
            this->m_message_window = NULL;
        }
        if (this->m_player_list == NULL) {
            m_player_list = create_trade_partner_menu(this);
        }
        m_player_list->clear_flag_and_release();
        this->state = 2U;
    case 2:
        if (this->m_player_list->is_cancelled() != 0) {
            parent_menu->on_submenu_closed();
            this->state = 7U;
        } else if (m_player_list->is_decided() != 0) {
            this->state = 3U;
        }
        break;
    case 3:
        if (this->m_player_list != NULL) {
            this->selected_player = m_player_list->get_selected_value();
        }
        if (this->m_confirm_prompt == NULL) {
            this->m_confirm_prompt = this->open_trade_confirm_prompt(this->selected_player);
        }
        this->state = 4U;
    case 4:
        if (this->m_confirm_prompt->is_cancelled() != 0) {
            this->state = 1U;
        } else if (m_confirm_prompt->is_child_visible() != 0) {
            if (this->m_confirm_prompt->get_selected_value() == 0) {
                this->state = 5U;
            } else {
                this->state = 1U;
            }
        }
        break;
    case 5:
        if (this->m_confirm_prompt != NULL) {
            this->m_confirm_prompt->close();
            this->m_confirm_prompt = NULL;
        }
        if (this->m_message_window == NULL) {
            this->m_message_window = this->open_player_message_window(this->selected_player, (const char *)TWindowSubStatusDisp::get_message_10(0xD7));
        }
        send_6xA6_modify_trade_proposal((this->selected_player));
        this->state = 6U;
    case 6:
        if ((test_pressed_buttons_packed(&controller_input_state.controllers[controller_index], 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
            play_sound_effect(0x52F16, 0, 0, 0);
            TLobby::cancel_trade();
            this->state = 1U;
        }
        break;
    case 7:
        break;
    }
}

void TWindowSubTrade::render() {  }

// The caller passes its TWindowSubTrade in r3; the body never reads it.
TWindowSubComCardList *create_trade_partner_menu(TWindowSubTrade *) {
    s32 i;
    TObjPlayer *player;
    TWindowSubComCardList *list;

    list = (TWindowSubComCardList *)(saddr)create_titled_window_menu_default(get_window_layout_position(0x5A), 4, (saddr)(TWindowSubStatusDisp::get_message_10(0x1F)));
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
    if (list->get_entry_count() <= 0) {
        add_gray_text_entry((TWindowMenu *)list, (const char *)(TWindowSubStatusDisp::get_message_10(0xD2)), 7, 0);
    }
    list->set_flag70_bit10();
    list->set_scroll_target(224.0f, 88.0f);
    return list;
}

TWindowMessage *TWindowSubTrade::open_player_message_window(s32 player, const char *message) {
    TWindowMessage *window;
    TObjPlayer *p = get_player_by_client_id(player);
    text_builder_reset();
    if (p != NULL) {
        text_builder_append(p->get_name());
    }
    text_builder_append(message);
    window = TWindowMessage::create(get_window_layout_position(0x5B), trade_message_window_size, 1, this->client_id);
    window->append_line((saddr)get_shared_text_buffer(), 0x82);
    return window;
}

TWindowMessageYesNo *TWindowSubTrade::open_trade_confirm_prompt(s32 client) {
    TWindowMessageYesNo *prompt;
    TObjPlayer *player = get_player_by_client_id(client);
    text_builder_reset();
    if (player != NULL) {
        text_builder_append(player->get_name());
    }
    text_builder_append((const char *)TWindowSubStatusDisp::get_message_10(0xD6));
    prompt = (TWindowMessageYesNo *)TWindowMessageYesNo::create(this, client_id, NULL, NULL);
    open_yes_no_prompt(prompt, (uaddr)(TWindowSubStatusDisp::get_message_10(0x20)), (saddr)(get_shared_text_buffer()), get_window_layout_position(0x5B), 384.0f);
    prompt->set_menu_selected_index(1);
    prompt->set_choice_menu_flag70_bit10();
    return prompt;
}
