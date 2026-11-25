#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/SoundEffect.h"
#include "pso/ui/window/TWindowSubEquipKind.h"
#include "types.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/ui/window/TWindowCtrl_8024A054.h"
#include "pso/ui/window/TWindowSubComCard_802A5748.h"
#include "pso/ui/window/TWindowSubEquip_80263AB0.h"
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

extern "C" {
}

#include "pso/ui/city/TShopEquipmentSellWindow.h"
#include "pso/ui/chat/TWindowChat.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/player/PlayerSlots.h"



// Built with deferred code generation (the vtable precedes run_task's jump
// table in .data), so the functions are written from the last one back.
#pragma fp_contract on

extern "C" {
// Child-window flag setters; their only callers are TWindowSubTradeMain's
// set_child_windows_enabled and run_task, and they follow its dtor/ctor here.
void TWindowSubTradeMain__sub_803323C8(void* p) { *(u16*)((char*)p + 0x70) &= 0xfffffffb; }
void TWindowSubTradeMain__sub_803323B8(void* p) { *(u16*)((char*)p + 0x60) &= 0xffffffbf; }
void TWindowSubTradeMain__sub_803323A8(void* p) { *(u16*)((char*)p + 0x60) |= 0x40; }
}

TWindowSubTradeMain::TWindowSubTradeMain(TWindowMainMenu *parent, s32 client) : TObject(parent) {
    void *x;
    this->m_name = TWindowSubTradeMain::class_name;
    this->state = 0;
    this->flags = 0;
    this->timer = 0;
    client_id = client;
    parent_menu = parent;
    this->menu = 0;
    this->confirm = 0;
    dialog = 0;
    this->offer = 0;
    this->request = 0;
    this->list = 0;
    this->input_number = 0;
    this->help_item = 0;
    this->displayed_item = -1;
    TWindowCtrl::lock_client_main_menu(client_id);
    TWindowCtrl::hide_client_status_window(client_id);
    claim_trade_main_window(this);
    snapshot_trade_inventories();
    parent_menu->hide_for_subwindow();
    chat = new TWindowChat(this, &submission);
    fn_8027B2A8(chat);
    x = get_player_by_client_id(client_id);
    if (x != NULL) {
        ((TObjPlayer *)x)->start_freeze();
    }
}

TWindowSubTradeMain::~TWindowSubTradeMain() {
    release_trade_main_window(this);
    TLobby::check_flags_and_proceed();
    void *tmp_player;
    if ((tmp_player = (void *)get_player_by_client_id(this->client_id)) != 0U) {
        ((TObjPlayer *)tmp_player)->end_camera_pan();
    }
    if (chat != NULL) {
        chat->queue_destruction();
        chat = NULL;
    }
    if (this->help_item != NULL) {
        ((TWindowBase *)this->help_item)->close();
        this->help_item = NULL;
    }
    if ((u32) this->input_number != 0U) {
        ((TWindowBase *)this->input_number)->close();
        this->input_number = 0U;
    }
    if ((u32) this->list != 0U) {
        ((TWindowBase *)this->list)->close();
        this->list = 0U;
    }
    if ((u32) this->request != 0U) {
        ((TWindowBase *)this->request)->close();
        this->request = 0U;
    }
    if ((u32) this->offer != 0U) {
        ((TWindowBase *)this->offer)->close();
        this->offer = 0U;
    }
    if (dialog != NULL) {
        reinterpret_cast<TWindowMessageYesNo *>(dialog)->close();
        dialog = 0U;
    }
    if ((u32) this->confirm != 0U) {
        ((TWindowBase *)this->confirm)->close();
        this->confirm = 0U;
    }
    if ((u32) this->menu != 0U) {
        ((TWindowBase *)this->menu)->close();
        this->menu = 0U;
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
    if (((TWindowChat *)(this->chat))->is_mode_bit4() != 0 && chat_accept_submission((saddr)&this->submission) != 0) {
        TWindowChat__sub_80247E50(reinterpret_cast<TWindowChat *>(this->chat));
    }
    if (((TWindowChat *)(this->chat))->is_visible() != 0) {
        TWindowChat__sub_80247DFC(reinterpret_cast<TWindowChat *>(this->chat));
    }
    if (TWindowCtrl__sub_8024701C(reinterpret_cast<TWindowChat *>(this->chat)) != 0) {
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
        if (this->offer == 0) {
            this->offer = (TWindowMenuIconLine *)this->create_trade_window();
        }
        if (this->request == 0) {
            this->request = (TWindowMenuIconLine *)this->open_trade_equip_window();
        }
        if (this->menu == 0) {
            this->menu = (TWindowMenu *)build_trade_menu();
        }
        window_request_show(this->menu);
        ((TWindowMenu *)(this->menu))->clear_flag_and_release();
        ((TWindowOptionCtrl *)(this->menu))->clear_flag70_bit4();
        this->state = 2;
    case 2:
        if (((TWindowMenu *)(this->menu))->is_cancelled() != 0) {
            this->state = 0x17;
        } else if (((TWindowMenu *)(this->menu))->is_decided() != 0) {
            this->state = ((TWindowMenu *)this->menu)->get_selected_value();
        }
        break;
    case 3:
        if (this->menu != 0) {
            ((TWindowBase *)this->menu)->request_close();
        }
        if (this->offer != 0) {
            ((TWindowBase *)this->offer)->slide_to((f32 *)get_window_layout_position(0x62));
        }
        if (this->request != 0) {
            ((TWindowBase *)this->request)->slide_to((f32 *)get_window_layout_position(0x63));
        }
        if (this->list == 0) {
            this->list = (TWindowMenuIconLine *)this->create_list();
        }
        if (this->help_item == 0) {
            this->help_item = this->create_help_item();
        }
        ((TWindowMenuIconLine *)(this->list))->clear_decided();
        this->state = 4;
    case 4:
        this->set_displayed_item((s32)(((TWindowMenuIconLine *)this->list)->get_cursor_value()));
        if (((TWindowMenuIconLine *)(this->list))->is_cancelled() != 0) {
            this->state = 5;
        } else if (((TWindowMenuIconLine *)(this->list))->is_decided() != 0) {
            this->state = 6;
        }
        break;
    case 5:
        if (this->help_item != 0) {
            ((TWindowBase *)this->help_item)->close();
            this->help_item = 0;
        }
        if (this->list != 0) {
            ((TWindowBase *)this->list)->close();
            this->list = 0;
        }
        if (this->offer != 0) {
            ((TWindowBase *)this->offer)->slide_to((f32 *)get_window_layout_position(0x60));
        }
        if (this->request != 0) {
            ((TWindowBase *)this->request)->slide_to((f32 *)get_window_layout_position(0x61));
        }
        this->state = 1;
        break;
    case 6:
        if (this->help_item != 0) {
            ((TWindowBase *)this->help_item)->close();
            this->help_item = 0;
        }
        entry = ((TWindowMenuIconLine *)this->list)->get_cursor_value();
        n = get_trade_list_items()->get_item_count(entry);
        if (n <= 1) {
            TWindowSubTradeMain::draw_request(entry, 1);
            this->state = 9;
            break;
        }
        if (this->input_number == 0) {
            this->input_number = this->create_input_number(n);
        }
        this->state = 7;
    case 7:
        if (((TWindowInputNumber *)(this->input_number))->is_cancelled() != 0) {
            this->state = 8;
        }
        if (((TWindowInputNumber *)(this->input_number))->is_confirmed() != 0) {
            n = ((TWindowInputNumber *)(this->input_number))->get_value();
            TWindowSubTradeMain::draw_request(((TWindowMenuIconLine *)this->list)->get_cursor_value(), n);
            this->state = 9;
        }
        break;
    case 8:
        if (this->input_number != 0) {
            ((TWindowBase *)this->input_number)->close();
            this->input_number = 0;
        }
        this->state = 3;
        break;
    case 9:
        if (this->input_number != 0) {
            ((TWindowBase *)this->input_number)->close();
            this->input_number = 0;
        }
        this->state = 5;
        break;
    case 10:
        if (this->menu != 0) {
            ((TWindowBase *)this->menu)->request_close();
        }
        if (this->request != 0) {
            ((TWindowSubTradeMain *)(this->request))->update_trade_state();
        }
        if (this->help_item == 0) {
            this->help_item = this->create_help_item();
        }
        ((TWindowMenuIconLine *)(this->request))->clear_decided();
        this->state = 0xB;
    case 11:
        this->set_displayed_item((s32)(((TWindowMenuIconLine *)this->request)->get_cursor_value()));
        if (((TWindowMenuIconLine *)(this->request))->is_cancelled() != 0) {
            this->state = 0xC;
        } else if (((TWindowMenuIconLine *)(this->request))->is_decided() != 0) {
            this->state = 0xD;
        }
        break;
    case 12:
        if (this->help_item != 0) {
            ((TWindowBase *)this->help_item)->close();
            this->help_item = 0;
        }
        if (this->request != 0) {
            ((TWindowMenuIconLine *)(this->request))->clear_decided();
            TWindowSubTradeMain__sub_803323C8(this->request);
            ((TWindowSubTradeMain *)(this->request))->close();
        }
        this->state = 1;
        break;
    case 13:
        if (this->help_item != 0) {
            ((TWindowBase *)this->help_item)->close();
            this->help_item = 0;
        }
        entry = ((TWindowMenuIconLine *)this->request)->get_cursor_value();
        n = get_trade_window_state()->get_item_count(entry);
        if (n <= 1) {
            TWindowSubTradeMain::draw_offer(entry, 1);
            this->state = 0x10;
            break;
        }
        if (this->input_number == 0) {
            this->input_number = this->create_input_number(n);
        }
        this->state = 0xE;
    case 14:
        if (((TWindowInputNumber *)(this->input_number))->is_cancelled() != 0) {
            this->state = 0xF;
        }
        if (((TWindowInputNumber *)(this->input_number))->is_confirmed() != 0) {
            n = ((TWindowInputNumber *)(this->input_number))->get_value();
            TWindowSubTradeMain::draw_offer(((TWindowMenuIconLine *)this->request)->get_cursor_value(), n);
            this->state = 0x10;
        }
        break;
    case 15:
        if (this->input_number != 0) {
            ((TWindowBase *)this->input_number)->close();
            this->input_number = 0;
        }
        this->state = 0xA;
        break;
    case 16:
        if (this->input_number != 0) {
            ((TWindowBase *)this->input_number)->close();
            this->input_number = 0;
        }
        this->state = 0xC;
        break;
    case 17:
        if (this->menu != 0) {
            ((TWindowBase *)this->menu)->request_close();
        }
        if (this->offer != 0) {
            ((TWindowSubTradeMain *)(this->offer))->update_trade_state();
        }
        if (this->help_item == 0) {
            this->help_item = this->create_help_item();
        }
        this->state = 0x12;
    case 18:
        this->set_displayed_item((s32)(((TWindowMenuIconLine *)this->offer)->get_cursor_value()));
        if (((TWindowMenuIconLine *)(this->offer))->is_cancelled() != 0) {
            this->state = 0x13;
        } else if (((TWindowMenuIconLine *)(this->offer))->is_decided() != 0) {
            this->state = 0x13;
        }
        break;
    case 19:
        if (this->help_item != 0) {
            ((TWindowBase *)this->help_item)->close();
            this->help_item = 0;
        }
        if (this->offer != 0) {
            ((TWindowMenuIconLine *)(this->offer))->clear_decided();
            TWindowSubTradeMain__sub_803323C8(this->offer);
            ((TWindowSubTradeMain *)(this->offer))->close();
        }
        if (is_local_trade_offer_confirmation_requested() != 0) {
            this->state = 0x14;
        } else {
            this->state = 1;
        }
        break;
    case 20:
        if (this->menu != 0) {
            ((TWindowMenu *)(this->menu))->open();
        }
        window_request_show(this->menu);
        if (this->confirm == 0) {
            this->confirm = (TWindowBase *)create_trade_menu();
        }
        window_request_show(this->confirm);
        ((TWindowMenu *)(this->confirm))->clear_flag_and_release();
        set_local_trade_offer_confirmation();
        this->state = 0x15;
    case 21:
        if (are_both_trade_offers_confirmed() != 0) {
            ((TWindowSubComCard *)(this->confirm))->set_entry_value_clear_flag(2, 0xFFEE946E);
        } else {
            TWindowSubComCard__sub_80265680((TWindowMenu *)this->confirm, 2);
        }
        if (((TWindowMenu *)(this->confirm))->is_cancelled() != 0) {
            this->state = 0x16;
        } else if (((TWindowMenu *)(this->confirm))->is_decided() != 0) {
            this->state = ((TWindowMenu *)this->confirm)->get_selected_value();
            if (this->confirm != 0) {
                ((TWindowBase *)this->confirm)->request_close();
            }
            if (this->menu != 0) {
                ((TWindowMenu *)(this->menu))->clear_transition_flag();
            }
        }
        break;
    case 22:
        if (this->confirm != 0) {
            ((TWindowBase *)this->confirm)->close();
            this->confirm = 0;
        }
        if (this->menu != 0) {
            ((TWindowMenu *)(this->menu))->clear_transition_flag();
        }
        clear_local_trade_offer_confirmation();
        this->state = 1;
        break;
    case 23:
        if (this->menu != 0) {
            ((TWindowBase *)this->menu)->request_close();
        }
        if (this->dialog == 0) {
            this->dialog = this->open_confirm_prompt();
        }
        this->state = 0x18;
    case 24:
        if (((TWindowMessageYesNo *)(this->dialog))->is_cancelled() != 0) {
            this->state = 0x19;
        } else if (this->dialog->is_child_visible() != 0) {
            if (((TWindowMessageYesNo *)(this->dialog))->get_selected_value() == 0) {
                this->parent_menu->on_submenu_closed();
                this->state = 0x22;
            } else {
                this->state = 0x19;
            }
        }
        break;
    case 25:
        if (this->dialog != 0) {
            ((TWindowMessageYesNo *)(this->dialog))->close();
            this->dialog = 0;
        }
        if (is_local_trade_offer_confirmation_requested() != 0) {
            this->state = 0x14;
        } else {
            this->state = 1;
        }
        break;
    case 26:
        if (this->menu != 0) {
            ((TWindowBase *)this->menu)->request_close();
        }
        if ((n = TLobby::check_trade_items_and_show_error()) != 0) {
            if (this->dialog == 0) {
                this->dialog = open_option_dialog_thunk(n);
            }
            this->state = 0x1C;
        } else {
            if (this->dialog == 0) {
                this->dialog = open_confirm_yes_no();
            }
            this->state = 0x1B;
        }
    case 27:
        if (are_both_trade_offers_confirmed() == 0) {
            this->state = 0x1D;
        }
        if (((TWindowMessageYesNo *)(this->dialog))->is_cancelled() != 0) {
            this->state = 0x1D;
        } else if (this->dialog->is_child_visible() != 0) {
            if (((TWindowMessageYesNo *)(this->dialog))->get_selected_value() == 0) {
                ((TWindowMessageYesNo *)(this->dialog))->close();
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
        if (this->dialog != 0) {
            ((TWindowMessageYesNo *)(this->dialog))->close();
            this->dialog = 0;
        }
        this->state = 0x14;
        break;
    case 30:
        if (this->dialog != 0) {
            ((TWindowMessageYesNo *)(this->dialog))->close();
            this->dialog = 0;
        }
        this->dialog = open_status_window();
        this->timer = 900;
        this->state = 0x1F;
    case 31:
        if ((s32)this->timer > 0) {
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
        if ((s32)this->timer > 0) {
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

saddr TWindowSubTradeMain::build_trade_menu() {
  TWindowMenu *titled_window_menu;
  titled_window_menu = create_titled_window_menu(get_window_layout_position(0x5C), 5, (0, (saddr)TWindowSubStatusDisp::get_message_10(0x26)), (int) this->client_id);
  titled_window_menu->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xDA)), 6, 3);
  titled_window_menu->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xDB)), 6, 0xA);
  titled_window_menu->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xDC)), 6, 0x11);
  titled_window_menu->add_text_entry((saddr) TWindowSubStatusDisp::get_message_10(0xDD), 6, 0x14, (int) 0xFFEE946E);
  titled_window_menu->add_text_entry((saddr) TWindowSubStatusDisp::get_message_10(0xDF), 6, 0x17, (int) 0xFFEE6ED8);
  titled_window_menu->update_layout_height(282.0f);
  align_menu_entry_positions(titled_window_menu);
  return (saddr)titled_window_menu;
}

saddr TWindowSubTradeMain::create_trade_menu() {
  TWindowMenu *titled_window_menu;
  titled_window_menu = create_titled_window_menu(get_window_layout_position(0x5E), 4, (0, (saddr)TWindowSubStatusDisp::get_message_10(0xDD)), (int) this->client_id);
  titled_window_menu->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xDC)), 6, 0x11);
  titled_window_menu->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xE3)), 6, 0x16);
  titled_window_menu->add_text_entry((saddr) TWindowSubStatusDisp::get_message_10(0xDE), 6, 0x1A, (int) 0xFFEE946E);
  titled_window_menu->add_text_entry((saddr) TWindowSubStatusDisp::get_message_10(0xDF), 6, 0x17, (int) 0xFFEE6ED8);
  titled_window_menu->update_layout_height(282.0f);
  align_menu_entry_positions(titled_window_menu);
  return (saddr)titled_window_menu;
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

saddr TWindowSubTradeMain::create_trade_window() {
    TObjPlayer *p;
    saddr w;
    p = get_player_by_client_id((s8)TLobby::get_trade_mode());
    if (p == NULL) {
        return 0;
    }
    w = reinterpret_cast<saddr>(create_equip_kind_window(get_window_layout_position(0x60), &trade_window_pos, this->client_id));
    ((TWindowMenuIconLine *)w)->ensure_status_display((s32)p->get_name());
    ((TWindowSubTradeMain *)w)->set_trade_state(0);
    ((TWindowMenuIconLine *)w)->refresh_trade_item_list(get_trade_offer_items()->entries);
    ((TWindowSubTradeMain *)w)->close();
    ((TWindowBase *)w)->set_depth(get_main_menu_layer_depth((u8 *)this->parent_menu, 0));
    return w;
}

saddr TWindowSubTradeMain::open_trade_equip_window() {
    TObjPlayer *p;
    saddr w;
    p = get_player_by_client_id(this->client_id);
    if (p == NULL) {
        return 0;
    }
    w = reinterpret_cast<saddr>(create_equip_kind_window(get_window_layout_position(0x61), &trade_equip_window_pos, this->client_id));
    ((TWindowMenuIconLine *)w)->ensure_status_display((s32)p->get_name());
    ((TWindowSubTradeMain *)w)->set_trade_state(0);
    ((TWindowMenuIconLine *)w)->refresh_trade_item_list(get_trade_window_state()->entries);
    ((TWindowSubTradeMain *)w)->close();
    ((TWindowBase *)w)->set_depth(get_main_menu_layer_depth((u8 *)this->parent_menu, 1));
    return w;
}

saddr TWindowSubTradeMain::create_list() {
    saddr equip_kind_window;

    equip_kind_window = reinterpret_cast<saddr>(create_equip_kind_window(get_window_layout_position(0x64), &trade_list_window_pos, this->client_id));
    ((TWindowMenuIconLine *)equip_kind_window)->ensure_status_display((saddr)TWindowSubStatusDisp::get_message_10(0x24));
    ((TWindowMenuIconLine *)equip_kind_window)->refresh_trade_item_list(get_trade_list_items()->entries);
    ((TWindowBase *)equip_kind_window)->set_depth(get_main_menu_layer_depth(reinterpret_cast<u8 *>(parent_menu), 2));
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
    if ((u32) this->menu != 0U) {
        TWindowSubTradeMain::update_position_if_changed((saddr)this, (u8 *)this->menu, (u8 *)(get_window_layout_position(labels + 0x5C)));
    }
    if ((u32) this->confirm != 0U) {
        TWindowSubTradeMain::update_position_if_changed((saddr)this, (u8 *)this->confirm, (u8 *)(get_window_layout_position(labels + 0x5E)));
    }
    if (dialog != NULL) {
        dialog->move_to(reinterpret_cast<const NJS_POINT2 *>(get_window_layout_position(labels + 0x5F)));
    }
    if ((u32) this->offer != 0U) {
        if ((u32) this->list != 0U) {
            TWindowSubTradeMain::update_position_if_changed((saddr)this, (u8 *)this->offer, (u8 *)(get_window_layout_position(labels + 0x62)));
        } else {
            TWindowSubTradeMain::update_position_if_changed((saddr)this, (u8 *)this->offer, (u8 *)(get_window_layout_position(labels + 0x60)));
        }
    }
    if ((u32) this->request != 0U) {
        if ((u32) this->list != 0U) {
            TWindowSubTradeMain::update_position_if_changed((saddr)this, (u8 *)this->request, (u8 *)(get_window_layout_position(labels + 0x63)));
        } else {
            TWindowSubTradeMain::update_position_if_changed((saddr)this, (u8 *)this->request, (u8 *)(get_window_layout_position(labels + 0x61)));
        }
    }
    if ((u32) this->list != 0U) {
        TWindowSubTradeMain::update_position_if_changed((saddr)this, (u8 *)this->list, (u8 *)(get_window_layout_position(labels + 0x64)));
    }
    if ((u32) this->input_number != 0U) {
        TWindowSubTradeMain::update_position_if_changed((saddr)this, (u8 *)this->input_number, (u8 *)(get_window_layout_position(labels + 0x5D)));
    }
    if (this->help_item != NULL) {
        TWindowSubTradeMain::update_position_if_changed((saddr)this, (u8 *)this->help_item, (u8 *)(get_window_layout_position(labels + 0x65)));
    }
}

void TWindowSubTradeMain::set_child_windows_enabled(s32 on) {
    switch (this->state) {
    case 2:
        if (this->menu != 0) {
            if (on != 0) {
                ((TWindowSubTradeMain *)(this->menu))->clear_trade_flag();
            } else {
                ((TWindowMenu *)(this->menu))->set_flag_40();
            }
        }
        break;
    case 4:
        if (this->help_item != 0) {
            if (on != 0) {
                ((TWindowHelpItem *)(this->help_item))->sub_80255E24();
            } else {
                ((TWindowHelpItem *)(this->help_item))->set_flag60_bit4();
            }
        }
        if (this->list != 0) {
            if (on != 0) {
                ((TWindowSubTradeMain *)(this->list))->clear_flag();
            } else {
                ((TWindowSubTradeMain *)(this->list))->set_visible();
            }
        }
        break;
    case 7:
    case 14:
        if (this->input_number != 0) {
            if (on != 0) {
                TWindowSubTradeMain__sub_803323B8(this->input_number);
            } else {
                TWindowSubTradeMain__sub_803323A8(this->input_number);
            }
        }
        break;
    case 11:
        if (this->help_item != 0) {
            if (on != 0) {
                ((TWindowHelpItem *)(this->help_item))->sub_80255E24();
            } else {
                ((TWindowHelpItem *)(this->help_item))->set_flag60_bit4();
            }
        }
        if (this->request != 0) {
            if (on != 0) {
                ((TWindowSubTradeMain *)(this->request))->clear_flag();
            } else {
                ((TWindowSubTradeMain *)(this->request))->set_visible();
            }
        }
        break;
    case 18:
        if (this->help_item != 0) {
            if (on != 0) {
                ((TWindowHelpItem *)(this->help_item))->sub_80255E24();
            } else {
                ((TWindowHelpItem *)(this->help_item))->set_flag60_bit4();
            }
        }
        if (this->offer != 0) {
            if (on != 0) {
                ((TWindowSubTradeMain *)(this->offer))->clear_flag();
            } else {
                ((TWindowSubTradeMain *)(this->offer))->set_visible();
            }
        }
        break;
    case 21:
        if (this->confirm != 0) {
            if (on != 0) {
                ((TWindowSubTradeMain *)(this->confirm))->clear_trade_flag();
            } else {
                ((TWindowMenu *)(this->confirm))->set_flag_40();
            }
        }
        break;
    case 24:
    case 27:
        if (this->dialog != 0) {
            if (on != 0) {
                ((TWindowSubComCard *)(this->dialog))->notify_trade_main();
            } else {
                ((TWindowSubComCard *)(this->dialog))->update_card_slot();
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
    if ((u32) this->offer != 0U) {
        ((TWindowMenuIconLine *)(this->offer))->refresh_trade_item_list(get_trade_offer_items()->entries);
        ((TWindowSubTradeMain *)(this->offer))->set_trade_state(3);
    }
}

void TWindowSubTradeMain::draw_item_slot() {
    if ((u32) this->request != 0U) {
        ((TWindowMenuIconLine *)(this->request))->refresh_trade_item_list(get_trade_window_state()->entries);
    }
}

void TWindowSubTradeMain::notify_child_if_present(s32 trade_state) {
    uaddr window = (uaddr)this->offer;
    if (window != 0U) {
        ((TWindowSubTradeMain *)window)->set_trade_state((s16) trade_state);
    }
}

void TWindowSubTradeMain::forward_to_child(s32 trade_state) {
    uaddr window = (uaddr)this->request;
    if (window != 0U) {
        ((TWindowSubTradeMain *)window)->set_trade_state((s16) trade_state);
    }
}

void TWindowSubTradeMain::show_trade_status() { state = 30; }

void TWindowSubTradeMain::finish() {
    parent_menu->on_submenu_closed();
    state = 0x22;
}
