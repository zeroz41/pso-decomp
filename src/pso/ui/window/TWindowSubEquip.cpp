#include "pso/ui/window/TWindowSubEquipKind.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "types.h"
#include "pso/ui/window/TWindowSubEquip.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/ui/window/TWindowShortListCtrl.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubShortCutList.h"
#include "pso/network/TLobby.h"
#include "pso/ui/city/TShopArmorListWindow.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/ui/window/TWindowSubMag.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/system/ControllerInput.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/player/PlayerSlots.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/system/SoundEffect.h"
#include "pso/ui/window/TWindowSubEquipList.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"

#pragma readonly_strings on

const char *TWindowSubEquip::class_name = "TWindowSubEquip";

// Sizes of the equipment list (ctor) and equipment kind (open_equip_kind_list) windows, passed next to
// their layout positions. Names from the create_*_window argument they fill.
static const NJS_POINT2 equip_list_window_size = {308.0f, 184.0f};
static const NJS_POINT2 equip_kind_window_size = {308.0f, 124.0f};



// Built with deferred code generation (the vtable precedes the switch table
// in .data), so the functions are written from the last one back.
TWindowSubEquip::TWindowSubEquip(TWindowMainMenu *parent, s32 client) : TObject(parent) {
    m_name = TWindowSubEquip::class_name;
    this->parent = parent;
    this->client_id = client;
    this->equip_list = (TWindowMenuIconLine *)create_equip_list_window((saddr)get_window_layout_position(0), &equip_list_window_size, this->client_id);
    this->equip_list->set_depth(get_main_menu_layer_depth((u8 *)this->parent, 0));
    this->equip_list->set_flag70_bit10();
    this->window_help_item = new TWindowHelpItem(get_window_layout_position(2), this->client_id);
    this->window_help_item->set_depth(get_main_menu_layer_depth((u8 *)this->parent, 2));
    this->equip_kind_list = 0;
    this->shown_item_id = -1;
    this->shown_kind_item_id = -1;
    this->state = 0;
}

TWindowSubEquip::~TWindowSubEquip() {
    if (equip_kind_list != NULL) { equip_kind_list->close(); this->equip_kind_list = 0; }
    if (equip_list != NULL) { equip_list->close(); this->equip_list = 0; }
    if (this->window_help_item != NULL) { this->window_help_item->close(); this->window_help_item = NULL; }
}

void TWindowSubEquip::run_task() {
    s32 controller_index;
    controller_index = is_player_input_active(this->client_id);
    switch ((s32) this->state) {
    case 0:
    case 1:
        if (this->equip_kind_list != NULL) {
            TWindowSubEquip__sub_80263AF4(this->parent, 1);
            this->equip_kind_list->close();
            this->equip_kind_list = 0U;
        }
        this->window_help_item->clear_help_item();
        this->shown_item_id = -1;
        this->shown_kind_item_id = -1;
        equip_list->refresh_equipment_list();
        this->equip_list->clear_decided();
        equip_list->start_scroll(188.0f);
        this->state = 2U;
    case 2:
        update();
        if (this->equip_list->is_cancelled() != 0) {
            this->parent->on_submenu_closed();
            this->state = 6U;
            return;
        }
        if (this->equip_list->is_decided() != 0) {
            this->state = 3U;
        }
        break;
    case 3:
        this->equip_list->shrink_to_selected_entry();
        if (this->equip_kind_list == NULL) {
            this->equip_kind_list = open_equip_kind_list(this->equip_list->get_cursor_value());
        }
        this->equip_kind_list->clear_decided();
        this->state = 4U;
    case 4:
        update_displayed_item();
        if (this->equip_kind_list->is_cancelled() != 0) {
            this->state = 1U;
            return;
        }
        if (this->equip_kind_list->is_decided() != 0) {
            this->state = 5U;
            return;
        }
        break;
    case 5:
        if ((test_pressed_buttons_packed(&controller_input_state.controllers[controller_index], 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
            play_sound_effect(0x52F16, 0, 0, 0);
            this->state = 3U;
            return;
        }
        TObjPlayer *selected_player;
        if (((selected_player = get_player_by_client_id(this->client_id)) != 0U) && (TWindowSubItem::is_usable(selected_player) != 0)) {
            apply_slot_selection();
            this->state = 1U;
        }
        break;
    case 6:
        break;
    }
}

void TWindowSubEquip::render() {  }

TWindowMenuIconLine *TWindowSubEquip::open_equip_kind_list(u32 slot) {
    TWindowSubEquipKind *equip_kind_window;
    equip_kind_window = create_equip_kind_window(
        get_window_layout_position(1), &equip_kind_window_size, this->client_id);
    equip_kind_window->set_depth(get_main_menu_layer_depth((u8 *)this->parent, 1));
    equip_kind_window->ensure_status_display((saddr) (TWindowSubStatusDisp::get_message_10(0x24)));
    ((TWindowSubShortCutList *)equip_kind_window)->set_flag70_bit10();
    switch (slot) {
    case 6:
        equip_kind_window->refresh_mag_item_list(0);
        break;
    case 2:
        equip_kind_window->refresh_armor_equip_list(1, 1);
        break;
    case 9:
    case 10:
    case 11:
    case 12:
        equip_kind_window->refresh_armor_equip_list(1, 3);
        break;
    case 3:
        equip_kind_window->refresh_armor_equip_list(1, 2);
        break;
    case 1:
        equip_kind_window->refresh_mag_item_list(2);
        break;
    }
    mark_unequippable_items(equip_kind_window);
    return equip_kind_window;
}

void TWindowSubEquip::apply_slot_selection() {
    s32 cursor_value;
    cursor_value = this->equip_list->get_cursor_value();
    TWindowShortListCtrl::assign_shortcut(cursor_value, (int) (this->equip_kind_list->get_cursor_value()), this->client_id);
}

void TWindowShortListCtrl::assign_shortcut(s32 slot, saddr item, s32 client_id) {
    uaddr slot_value;
    TObjPlayer *player;
    saddr item_id;
    uaddr temp_r3b;

    player = get_player_by_client_id(client_id);
    if (player != 0) {
        slot_value = TObjPlayer::get_slot_value(player->equipped_items.items, slot);
        temp_r3b = (uaddr)find_item_by_id(item);
        if (slot_value == temp_r3b) {
            TObjPlayer::send_6x26_unequip_item(player, item);
            return;
        }
        if (((TItem *)temp_r3b)->test_item_flags(8) != 0U) {
            TObjPlayer::send_6x26_unequip_item(player, item);
        }
        if (slot_value != 0U) {
            item_id = ((TItem *)slot_value)->get_item_id();
            TObjPlayer::send_6x26_unequip_item(player, item_id);
        }
        send_6x25_equip_item(player, item, slot);
    }
}

void TWindowSubEquip::update() {
    TObjPlayer *player;
    s32 item_id;
    s32 slot;

    player = get_player_by_client_id(this->client_id);
    if (player != 0) {
        slot = this->equip_list->get_cursor_value();
        TItem *item = (TItem *)TObjPlayer::get_slot_value(player->equipped_items.items, slot);
        if (item == NULL) {
            item_id = -1;
        } else {
            item_id = item->get_item_id();
        }
        if (item_id != (s32) this->shown_item_id) {
            this->shown_item_id = item_id;
            this->window_help_item->show_item_by_id(item_id);
        }
    }
}

void TWindowSubEquip::update_displayed_item() {
    s32 cursor_value;

    cursor_value = this->equip_kind_list->get_cursor_value();
    if (cursor_value != (s32) this->shown_kind_item_id) {
        this->shown_kind_item_id = cursor_value;
        this->window_help_item->set_displayed_item_by_id(cursor_value);
    }
}
