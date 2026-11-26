#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/SoundEffect.h"
#include "pso/ui/window/TWindowSubEquipKind.h"
#include "types.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/ui/window/TWindowSubTradeMain_802D2808.h"
#include "pso/network/TradeSession.h"
#include "pso/unk/text_80076BC4.h"
#include "pso/network/TLobby.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/frontend/TAdChrSelASlotGC.h"
#include "pso/ui/window/TWindowInputNumber.h"
#include "pso/ui/window/TWindowLockOn.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowMessageYesNo.h"
#include "pso/ui/window/TWindowMenuIconLine.h"


#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/window/TWindowSubLog.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/system/ControllerInput.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/WindowLayout.h"

const char *TWindowSubTradeMain::class_name = "TWindowSubTradeMain";

// inferred: screen positions of the trade windows, named after the function that opens each one
// (create_equip_kind_window takes the position, like short_list_window_pos in TWindowShortListCtrl).
static const NJS_POINT2 trade_window_pos = {326.0f, 84.0f};
static const NJS_POINT2 trade_equip_window_pos = {326.0f, 84.0f};
static const NJS_POINT2 trade_list_window_pos = {326.0f, 104.0f};

#include "pso/ui/city/TShopEquipmentSellWindow.h"
#include "pso/ui/chat/TWindowChat.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/player/PlayerSlots.h"





// Built with deferred code generation (the vtable precedes run_task's jump
// table in .data), so the functions are written from the last one back.
#pragma fp_contract on

// Child-window flag helpers; their only callers are TWindowSubTradeMain's
// set_child_windows_enabled and run_task, and they follow its dtor/ctor here.
void TWindowMenuIconLine::clear_flag4() { state_flags &= ~4; }
void TWindowInputNumber::clear_flag_40() { inputFlags &= ~0x40; }
void TWindowInputNumber::set_flag_40() { inputFlags |= 0x40; }

TWindowSubTradeMain::TWindowSubTradeMain(TWindowMainMenu *parent, s32 client) : TObject(parent) {
    TObjPlayer *player;
    this->m_name = TWindowSubTradeMain::class_name;
    this->state = 0;
    this->flags = 0;
    this->timer = 0;
    client_id = client;
    parent_menu = parent;
    this->menu = NULL;
    this->confirm = NULL;
    dialog = 0;
    this->offer = NULL;
    this->request = NULL;
    this->list = NULL;
    this->input_number = NULL;
    this->help_item = NULL;
    this->displayed_item = -1;
    TWindowCtrl::lock_client_main_menu(client_id);
    TWindowCtrl::hide_client_status_window(client_id);
    claim_trade_main_window(this);
    snapshot_trade_inventories();
    parent_menu->hide_for_subwindow();
    chat = new TWindowChat(this, &submission);
    chat->set_flag1e_bit200();
    player = get_player_by_client_id(client_id);
    if (player != NULL) {
        player->start_freeze();
    }
}

TWindowSubTradeMain::~TWindowSubTradeMain() {
    TObjPlayer *player;

    release_trade_main_window(this);
    TLobby::check_flags_and_proceed();
    if ((player = get_player_by_client_id(this->client_id)) != NULL) {
        player->end_camera_pan();
    }
    if (chat != NULL) {
        chat->queue_destruction();
        chat = NULL;
    }
    if (this->help_item != NULL) {
        this->help_item->close();
        this->help_item = NULL;
    }
    if (this->input_number != NULL) {
        this->input_number->close();
        this->input_number = NULL;
    }
    if (this->list != NULL) {
        this->list->close();
        this->list = NULL;
    }
    if (this->request != NULL) {
        this->request->close();
        this->request = NULL;
    }
    if (this->offer != NULL) {
        this->offer->close();
        this->offer = NULL;
    }
    if (dialog != NULL) {
        reinterpret_cast<TWindowMessageYesNo *>(dialog)->close();
        dialog = 0U;
    }
    if (this->confirm != NULL) {
        this->confirm->close();
        this->confirm = NULL;
    }
    if (this->menu != NULL) {
        this->menu->close();
        this->menu = NULL;
    }
    if (parent_menu != NULL) {
        parent_menu->restore_after_subwindow();
    }
    TWindowCtrl::show_client_status_window(this->client_id);
    TWindowCtrl::unlock_client_main_menu(this->client_id);
}

void TWindowSubTradeMain::run_task() {
    s32 player;
    saddr entry;
    saddr n;
    player = is_player_input_active(this->client_id);
    if (this->chat->is_mode_bit4() != 0 && chat_accept_submission((saddr)&this->submission) != 0) {
        consume_active_flag(this->chat);
    }
    if (this->chat->is_visible() != 0) {
        consume_input_active_flag(this->chat);
    }
    if (this->chat->is_busy() != 0) {
        this->set_labels(0xA);
        this->set_child_windows_enabled(0);
        this->flags |= 1;
    } else {
        this->set_labels(0);
        this->set_child_windows_enabled(1);
        this->flags &= ~1;
    }
    switch (this->state) {
    case 0:
    case 1:
        if (this->offer == NULL) {
            this->offer = this->create_trade_window();
        }
        if (this->request == NULL) {
            this->request = this->open_trade_equip_window();
        }
        if (this->menu == NULL) {
            this->menu = build_trade_menu();
        }
        window_request_show(this->menu);
        this->menu->clear_flag_and_release();
        this->menu->clear_flag70_bit4();
        this->state = 2;
    case 2:
        if (this->menu->is_cancelled() != 0) {
            this->state = 0x17;
        } else if (this->menu->is_decided() != 0) {
            this->state = this->menu->get_selected_value();
        }
        break;
    case 3:
        if (this->menu != NULL) {
            this->menu->request_close();
        }
        if (this->offer != NULL) {
            this->offer->slide_to((f32 *)get_window_layout_position(0x62));
        }
        if (this->request != NULL) {
            this->request->slide_to((f32 *)get_window_layout_position(0x63));
        }
        if (this->list == NULL) {
            this->list = this->create_list();
        }
        if (this->help_item == NULL) {
            this->help_item = this->create_help_item();
        }
        this->list->clear_decided();
        this->state = 4;
    case 4:
        this->set_displayed_item((s32)(this->list->get_cursor_value()));
        if (this->list->is_cancelled() != 0) {
            this->state = 5;
        } else if (this->list->is_decided() != 0) {
            this->state = 6;
        }
        break;
    case 5:
        if (this->help_item != NULL) {
            this->help_item->close();
            this->help_item = NULL;
        }
        if (this->list != NULL) {
            this->list->close();
            this->list = NULL;
        }
        if (this->offer != NULL) {
            this->offer->slide_to((f32 *)get_window_layout_position(0x60));
        }
        if (this->request != NULL) {
            this->request->slide_to((f32 *)get_window_layout_position(0x61));
        }
        this->state = 1;
        break;
    case 6:
        if (this->help_item != NULL) {
            this->help_item->close();
            this->help_item = NULL;
        }
        entry = this->list->get_cursor_value();
        n = get_trade_list_items()->get_item_count(entry);
        if (n <= 1) {
            TWindowSubTradeMain::draw_request(entry, 1);
            this->state = 9;
            break;
        }
        if (this->input_number == NULL) {
            this->input_number = this->create_input_number(n);
        }
        this->state = 7;
    case 7:
        if (this->input_number->is_cancelled() != 0) {
            this->state = 8;
        }
        if (this->input_number->is_confirmed() != 0) {
            n = this->input_number->get_value();
            TWindowSubTradeMain::draw_request(this->list->get_cursor_value(), n);
            this->state = 9;
        }
        break;
    case 8:
        if (this->input_number != NULL) {
            this->input_number->close();
            this->input_number = NULL;
        }
        this->state = 3;
        break;
    case 9:
        if (this->input_number != NULL) {
            this->input_number->close();
            this->input_number = NULL;
        }
        this->state = 5;
        break;
    case 10:
        if (this->menu != NULL) {
            this->menu->request_close();
        }
        if (this->request != NULL) {
            this->request->activate();
        }
        if (this->help_item == NULL) {
            this->help_item = this->create_help_item();
        }
        this->request->clear_decided();
        this->state = 0xB;
    case 11:
        this->set_displayed_item((s32)(this->request->get_cursor_value()));
        if (this->request->is_cancelled() != 0) {
            this->state = 0xC;
        } else if (this->request->is_decided() != 0) {
            this->state = 0xD;
        }
        break;
    case 12:
        if (this->help_item != NULL) {
            this->help_item->close();
            this->help_item = NULL;
        }
        if (this->request != NULL) {
            this->request->clear_decided();
            this->request->clear_flag4();
            this->request->deactivate();
        }
        this->state = 1;
        break;
    case 13:
        if (this->help_item != NULL) {
            this->help_item->close();
            this->help_item = NULL;
        }
        entry = this->request->get_cursor_value();
        n = get_trade_window_state()->get_item_count(entry);
        if (n <= 1) {
            TWindowSubTradeMain::draw_offer(entry, 1);
            this->state = 0x10;
            break;
        }
        if (this->input_number == NULL) {
            this->input_number = this->create_input_number(n);
        }
        this->state = 0xE;
    case 14:
        if (this->input_number->is_cancelled() != 0) {
            this->state = 0xF;
        }
        if (this->input_number->is_confirmed() != 0) {
            n = this->input_number->get_value();
            TWindowSubTradeMain::draw_offer(this->request->get_cursor_value(), n);
            this->state = 0x10;
        }
        break;
    case 15:
        if (this->input_number != NULL) {
            this->input_number->close();
            this->input_number = NULL;
        }
        this->state = 0xA;
        break;
    case 16:
        if (this->input_number != NULL) {
            this->input_number->close();
            this->input_number = NULL;
        }
        this->state = 0xC;
        break;
    case 17:
        if (this->menu != NULL) {
            this->menu->request_close();
        }
        if (this->offer != NULL) {
            this->offer->activate();
        }
        if (this->help_item == NULL) {
            this->help_item = this->create_help_item();
        }
        this->state = 0x12;
    case 18:
        this->set_displayed_item((s32)(this->offer->get_cursor_value()));
        if (this->offer->is_cancelled() != 0) {
            this->state = 0x13;
        } else if (this->offer->is_decided() != 0) {
            this->state = 0x13;
        }
        break;
    case 19:
        if (this->help_item != NULL) {
            this->help_item->close();
            this->help_item = NULL;
        }
        if (this->offer != NULL) {
            this->offer->clear_decided();
            this->offer->clear_flag4();
            this->offer->deactivate();
        }
        if (is_local_trade_offer_confirmation_requested() != 0) {
            this->state = 0x14;
        } else {
            this->state = 1;
        }
        break;
    case 20:
        if (this->menu != NULL) {
            this->menu->open();
        }
        window_request_show(this->menu);
        if (this->confirm == NULL) {
            this->confirm = create_trade_menu();
        }
        window_request_show(this->confirm);
        this->confirm->clear_flag_and_release();
        set_local_trade_offer_confirmation();
        this->state = 0x15;
    case 21:
        if (are_both_trade_offers_confirmed() != 0) {
            this->confirm->enable_row(2, 0xFFEE946E);
        } else {
            this->confirm->disable_row(2);
        }
        if (this->confirm->is_cancelled() != 0) {
            this->state = 0x16;
        } else if (this->confirm->is_decided() != 0) {
            this->state = this->confirm->get_selected_value();
            if (this->confirm != NULL) {
                this->confirm->request_close();
            }
            if (this->menu != NULL) {
                this->menu->clear_transition_flag();
            }
        }
        break;
    case 22:
        if (this->confirm != NULL) {
            this->confirm->close();
            this->confirm = NULL;
        }
        if (this->menu != NULL) {
            this->menu->clear_transition_flag();
        }
        clear_local_trade_offer_confirmation();
        this->state = 1;
        break;
    case 23:
        if (this->menu != NULL) {
            this->menu->request_close();
        }
        if (this->dialog == NULL) {
            this->dialog = this->open_confirm_prompt();
        }
        this->state = 0x18;
    case 24:
        if (this->dialog->is_cancelled() != 0) {
            this->state = 0x19;
        } else if (this->dialog->is_child_visible() != 0) {
            if (this->dialog->get_selected_value() == 0) {
                this->parent_menu->on_submenu_closed();
                this->state = 0x22;
            } else {
                this->state = 0x19;
            }
        }
        break;
    case 25:
        if (this->dialog != NULL) {
            this->dialog->close();
            this->dialog = NULL;
        }
        if (is_local_trade_offer_confirmation_requested() != 0) {
            this->state = 0x14;
        } else {
            this->state = 1;
        }
        break;
    case 26:
        if (this->menu != NULL) {
            this->menu->request_close();
        }
        if ((n = TLobby::check_trade_items_and_show_error()) != 0) {
            if (this->dialog == NULL) {
                this->dialog = open_option_dialog_thunk(n);
            }
            this->state = 0x1C;
        } else {
            if (this->dialog == NULL) {
                this->dialog = open_confirm_yes_no();
            }
            this->state = 0x1B;
        }
    case 27:
        if (are_both_trade_offers_confirmed() == 0) {
            this->state = 0x1D;
        }
        if (this->dialog->is_cancelled() != 0) {
            this->state = 0x1D;
        } else if (this->dialog->is_child_visible() != 0) {
            if (this->dialog->get_selected_value() == 0) {
                this->dialog->close();
                this->dialog = update_from_lobby();
                set_local_trade_final_confirmation();
                this->state = 0x1C;
            } else {
                this->state = 0x1D;
            }
        }
        break;
    case 28:
        if (are_both_trade_offers_confirmed() == 0 ||
            (!(this->flags & 1) &&
             (test_pressed_buttons_packed(&controller_input_state.controllers[player], 2) != 0 ||
              test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0))) {
            play_sound_effect(0x52F16, 0, 0, 0);
            clear_local_trade_final_confirmation();
            this->state = 0x1D;
        }
        break;
    case 29:
        if (this->dialog != NULL) {
            this->dialog->close();
            this->dialog = NULL;
        }
        this->state = 0x14;
        break;
    case 30:
        if (this->dialog != NULL) {
            this->dialog->close();
            this->dialog = NULL;
        }
        this->dialog = open_status_window();
        this->timer = 900;
        this->state = 0x1F;
    case 31:
        if (this->timer > 0) {
            this->timer--;
        } else if (!(this->flags & 1) &&
                   (test_pressed_buttons_packed(&controller_input_state.controllers[player], 2) != 0 ||
                    test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
            play_sound_effect(0x52F16, 0, 0, 0);
            TLobby::clear_flag400();
            this->timer = 900;
            this->state = 0x20;
        }
        break;
    case 32:
        if (this->timer > 0) {
            this->timer--;
        } else {
            reset_trade_session();
            this->state = 0x22;
        }
        break;
    case 33:
    case 34:
        break;
    }
}

void TWindowSubTradeMain::render() {  }

TWindowMenu *TWindowSubTradeMain::build_trade_menu() {
  TWindowMenu *titled_window_menu;
  titled_window_menu = create_titled_window_menu(get_window_layout_position(0x5C), 5, (0, (saddr)TWindowSubStatusDisp::get_message_10(0x26)), client_id);
  titled_window_menu->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xDA)), 6, 3);
  titled_window_menu->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xDB)), 6, 0xA);
  titled_window_menu->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xDC)), 6, 0x11);
  titled_window_menu->add_text_entry((saddr) TWindowSubStatusDisp::get_message_10(0xDD), 6, 0x14, (int) 0xFFEE946E);
  titled_window_menu->add_text_entry((saddr) TWindowSubStatusDisp::get_message_10(0xDF), 6, 0x17, (int) 0xFFEE6ED8);
  titled_window_menu->update_layout_height(282.0f);
  align_menu_entry_positions(titled_window_menu);
  return titled_window_menu;
}

TWindowMenu *TWindowSubTradeMain::create_trade_menu() {
  TWindowMenu *titled_window_menu;
  titled_window_menu = create_titled_window_menu(get_window_layout_position(0x5E), 4, (0, (saddr)TWindowSubStatusDisp::get_message_10(0xDD)), client_id);
  titled_window_menu->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xDC)), 6, 0x11);
  titled_window_menu->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xE3)), 6, 0x16);
  titled_window_menu->add_text_entry((saddr) TWindowSubStatusDisp::get_message_10(0xDE), 6, 0x1A, (int) 0xFFEE946E);
  titled_window_menu->add_text_entry((saddr) TWindowSubStatusDisp::get_message_10(0xDF), 6, 0x17, (int) 0xFFEE6ED8);
  titled_window_menu->update_layout_height(282.0f);
  align_menu_entry_positions(titled_window_menu);
  return titled_window_menu;
}

TWindowMessageYesNo *TWindowSubTradeMain::open_confirm_yes_no() {
    TWindowMessageYesNo *window = TWindowMessageYesNo::create(this, client_id, NULL, NULL);
    open_yes_no_prompt(window,
        reinterpret_cast<uaddr>(TWindowSubStatusDisp::get_message_10(0x20)),
        reinterpret_cast<saddr>(TWindowSubStatusDisp::get_message_10(0xE6)),get_window_layout_position(0x5F), 282.0f);
    window->set_menu_selected_index(1);
    return window;
}

#pragma fp_contract off

TWindowMessageYesNo *TWindowSubTradeMain::update_from_lobby() {
    return open_option_dialog(build_trade_partner_status_text());
}

TWindowMessageYesNo *TWindowSubTradeMain::open_status_window() {
    return open_option_dialog(reinterpret_cast<saddr>(TWindowSubStatusDisp::get_message_10(0xF7)));
}

TWindowMessageYesNo *TWindowSubTradeMain::open_option_dialog_thunk(saddr message) {
    return open_option_dialog(message);
}

TWindowMessageYesNo *TWindowSubTradeMain::open_option_dialog(saddr message) {
    TWindowMessageYesNo *dialog = TWindowMessageYesNo::create(this, client_id, NULL, NULL);
    initialize_option_dialog(dialog, message, get_window_layout_position(0x5F), 282.0f);
    return dialog;
}

TWindowMessageYesNo *TWindowSubTradeMain::open_confirm_prompt() {
    TWindowMessageYesNo *window = TWindowMessageYesNo::create(this, client_id, NULL, NULL);
    open_yes_no_prompt(window,
        reinterpret_cast<uaddr>(TWindowSubStatusDisp::get_message_10(0x20)),
        reinterpret_cast<saddr>(TWindowSubStatusDisp::get_message_10(0xE4)),get_window_layout_position(0x5F), 282.0f);
    window->set_menu_selected_index(1);
    return window;
}

TWindowSubEquipKind *TWindowSubTradeMain::create_trade_window() {
    TObjPlayer *p;
    TWindowSubEquipKind *w;
    p = get_player_by_client_id((s8)TLobby::get_trade_mode());
    if (p == NULL) {
        return 0;
    }
    w = create_equip_kind_window(get_window_layout_position(0x60), &trade_window_pos, client_id);
    w->ensure_status_display((saddr)p->get_name());
    w->set_trade_state(0);
    w->refresh_trade_item_list(get_trade_offer_items()->entries);
    w->deactivate();
    w->set_depth(get_main_menu_layer_depth(reinterpret_cast<u8 *>(parent_menu), 0));
    return w;
}

TWindowSubEquipKind *TWindowSubTradeMain::open_trade_equip_window() {
    TObjPlayer *p;
    TWindowSubEquipKind *w;
    p = get_player_by_client_id(client_id);
    if (p == NULL) {
        return 0;
    }
    w = create_equip_kind_window(get_window_layout_position(0x61), &trade_equip_window_pos, client_id);
    w->ensure_status_display((saddr)p->get_name());
    w->set_trade_state(0);
    w->refresh_trade_item_list(get_trade_window_state()->entries);
    w->deactivate();
    w->set_depth(get_main_menu_layer_depth(reinterpret_cast<u8 *>(parent_menu), 1));
    return w;
}

TWindowSubEquipKind *TWindowSubTradeMain::create_list() {
    TWindowSubEquipKind *equip_kind_window;

    equip_kind_window = create_equip_kind_window(get_window_layout_position(0x64), &trade_list_window_pos, this->client_id);
    equip_kind_window->ensure_status_display((saddr)TWindowSubStatusDisp::get_message_10(0x24));
    equip_kind_window->refresh_trade_item_list(get_trade_list_items()->entries);
    equip_kind_window->set_depth(get_main_menu_layer_depth(reinterpret_cast<u8 *>(parent_menu), 2));
    return equip_kind_window;
}

TWindowInputNumber *TWindowSubTradeMain::create_input_number(s32 maximum) {
    TWindowInputNumber *window = new TWindowInputNumber(get_window_layout_position(0x5D), 1, maximum, 1, (s16)client_id);
    window->create((saddr)TWindowSubStatusDisp::get_message_10(0x28));
    window->set_value(282.0f);
    return window;
}

TWindowHelpItem *TWindowSubTradeMain::create_help_item() {
    TWindowHelpItem *window = new TWindowHelpItem((void *)get_window_layout_position(2), client_id);
    displayed_item = -1;
    return window;
}

void TWindowSubTradeMain::set_displayed_item(s32 id) {
    if ((this->help_item != NULL) && (id != (s32) this->displayed_item)) {
        this->displayed_item = id;
        this->help_item->set_displayed_item_by_id(id);
    }
}

void TWindowSubTradeMain::set_labels(s32 labels) {
    if (this->menu != NULL) {
        TWindowSubTradeMain::update_position_if_changed((saddr)this, (u8 *)this->menu, (u8 *)(get_window_layout_position(labels + 0x5C)));
    }
    if (this->confirm != NULL) {
        TWindowSubTradeMain::update_position_if_changed((saddr)this, (u8 *)this->confirm, (u8 *)(get_window_layout_position(labels + 0x5E)));
    }
    if (dialog != NULL) {
        dialog->move_to(reinterpret_cast<const NJS_POINT2 *>(get_window_layout_position(labels + 0x5F)));
    }
    if (this->offer != NULL) {
        if (this->list != NULL) {
            TWindowSubTradeMain::update_position_if_changed((saddr)this, (u8 *)this->offer, (u8 *)(get_window_layout_position(labels + 0x62)));
        } else {
            TWindowSubTradeMain::update_position_if_changed((saddr)this, (u8 *)this->offer, (u8 *)(get_window_layout_position(labels + 0x60)));
        }
    }
    if (this->request != NULL) {
        if (this->list != NULL) {
            TWindowSubTradeMain::update_position_if_changed((saddr)this, (u8 *)this->request, (u8 *)(get_window_layout_position(labels + 0x63)));
        } else {
            TWindowSubTradeMain::update_position_if_changed((saddr)this, (u8 *)this->request, (u8 *)(get_window_layout_position(labels + 0x61)));
        }
    }
    if (this->list != NULL) {
        TWindowSubTradeMain::update_position_if_changed((saddr)this, (u8 *)this->list, (u8 *)(get_window_layout_position(labels + 0x64)));
    }
    if (this->input_number != NULL) {
        TWindowSubTradeMain::update_position_if_changed((saddr)this, (u8 *)this->input_number, (u8 *)(get_window_layout_position(labels + 0x5D)));
    }
    if (this->help_item != NULL) {
        TWindowSubTradeMain::update_position_if_changed((saddr)this, (u8 *)this->help_item, (u8 *)(get_window_layout_position(labels + 0x65)));
    }
}

void TWindowSubTradeMain::set_child_windows_enabled(s32 on) {
    switch (this->state) {
    case 2:
        if (this->menu != NULL) {
            if (on != 0) {
                this->menu->clear_flag_40();
            } else {
                this->menu->set_flag_40();
            }
        }
        break;
    case 4:
        if (this->help_item != NULL) {
            if (on != 0) {
                this->help_item->unlock_page_flip();
            } else {
                this->help_item->lock_page_flip();
            }
        }
        if (this->list != NULL) {
            if (on != 0) {
                this->list->clear_flag_40();
            } else {
                this->list->set_flag_40();
            }
        }
        break;
    case 7:
    case 14:
        if (this->input_number != NULL) {
            if (on != 0) {
                this->input_number->clear_flag_40();
            } else {
                this->input_number->set_flag_40();
            }
        }
        break;
    case 11:
        if (this->help_item != NULL) {
            if (on != 0) {
                this->help_item->unlock_page_flip();
            } else {
                this->help_item->lock_page_flip();
            }
        }
        if (this->request != NULL) {
            if (on != 0) {
                this->request->clear_flag_40();
            } else {
                this->request->set_flag_40();
            }
        }
        break;
    case 18:
        if (this->help_item != NULL) {
            if (on != 0) {
                this->help_item->unlock_page_flip();
            } else {
                this->help_item->lock_page_flip();
            }
        }
        if (this->offer != NULL) {
            if (on != 0) {
                this->offer->clear_flag_40();
            } else {
                this->offer->set_flag_40();
            }
        }
        break;
    case 21:
        if (this->confirm != NULL) {
            if (on != 0) {
                this->confirm->clear_flag_40();
            } else {
                this->confirm->set_flag_40();
            }
        }
        break;
    case 24:
    case 27:
        if (this->dialog != NULL) {
            if (on != 0) {
                this->dialog->clear_choice_menu_flag_40();
            } else {
                this->dialog->set_choice_menu_flag_40();
            }
        }
        break;
    case 34:
        break;
    }
}

void TWindowSubTradeMain::update_position_if_changed(saddr owner, u8 *window, u8 *position) {
    if ((*(f32 *)((s8 *)window + 0x30) != *(f32 *)((s8 *)position + 0)) || (*(f32 *)((s8 *)window + 0x34) != *(f32 *)((s8 *)position + 4))) {
        ((TWindowBase *)window)->slide_to((f32 *)position);
    }
}

void TWindowSubTradeMain::update_trade_window() {
    if (this->offer != NULL) {
        this->offer->refresh_trade_item_list(get_trade_offer_items()->entries);
        this->offer->set_trade_state(3);
    }
}

void TWindowSubTradeMain::draw_item_slot() {
    if (this->request != NULL) {
        this->request->refresh_trade_item_list(get_trade_window_state()->entries);
    }
}

void TWindowSubTradeMain::notify_child_if_present(s32 trade_state) {
    TWindowSubEquipKind *window = this->offer;
    if (window != NULL) {
        window->set_trade_state(trade_state);
    }
}

void TWindowSubTradeMain::forward_to_child(s32 trade_state) {
    TWindowSubEquipKind *window = this->request;
    if (window != NULL) {
        window->set_trade_state(trade_state);
    }
}

void TWindowSubTradeMain::show_trade_status() { state = 30; }

void TWindowSubTradeMain::finish() {
    parent_menu->on_submenu_closed();
    state = 0x22;
}
