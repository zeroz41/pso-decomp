#include "pso/ui/window/TWindowSubEquipKind.h"
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
#include "pso/ui/window/TWindowCtrl_8024A054.h"
#include "pso/player/PlayerSlots.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/system/SoundEffect.h"
#include "pso/ui/window/TWindowSubEquipList.h"

#pragma readonly_strings on

const char *TWindowSubEquip__class_name = "TWindowSubEquip";

// Sizes of the equipment list (ctor) and equipment kind (open_equip_kind_list) windows, passed next to
// their layout positions. inferred: names from the create_*_window argument they fill.
static const NJS_POINT2 equip_list_window_size = {308.0f, 184.0f};
static const NJS_POINT2 equip_kind_window_size = {308.0f, 124.0f};


extern "C" {
f32 get_main_menu_layer_depth(u8 *parent, u32 layer);
s32 mark_unequippable_items(int);
void fn_80255A38(TWindowHelpItem *item);
s32 TWindowSubEquip__sub_80263AF4(void *, s32);
}

// Built with deferred code generation (the vtable precedes the switch table
// in .data), so the functions are written from the last one back.
TWindowSubEquip::TWindowSubEquip(TWindowMainMenu *parent, s32 client) : TObject(parent) {
    m_name = TWindowSubEquip__class_name;
    this->parent = parent;
    this->client_id = client;
    this->equip_list = (TWindowMenuIconLine *)create_equip_list_window((saddr)get_window_layout_position(0), (saddr)&equip_list_window_size, this->client_id);
    this->equip_list->set_depth(get_main_menu_layer_depth((u8 *)this->parent, 0));
    ((TWindowSubShortCutList *)(this->equip_list))->set_flag70_bit10();
    this->window_help_item = new TWindowHelpItem((void *)get_window_layout_position(2), this->client_id);
    this->window_help_item->set_depth(get_main_menu_layer_depth((u8 *)this->parent, 2));
    this->equip_kind_list = 0;
    this->m_20 = -1;
    this->m_24 = -1;
    this->m_1c = 0;
}

TWindowSubEquip::~TWindowSubEquip() {
    if (equip_kind_list != NULL) { equip_kind_list->close(); this->equip_kind_list = 0; }
    if (equip_list != NULL) { equip_list->close(); this->equip_list = 0; }
    if (this->window_help_item != NULL) { this->window_help_item->close(); this->window_help_item = NULL; }
}

void TWindowSubEquip::run_task() {
    s32 controller_index;
    controller_index = is_player_input_active(this->client_id);
    switch ((s32) this->m_1c) {
    case 0:
    case 1:
        if ((u32) this->equip_kind_list != 0U) {
            TWindowSubEquip__sub_80263AF4(this->parent, 1);
            this->equip_kind_list->close();
            this->equip_kind_list = 0U;
        }
        fn_80255A38(this->window_help_item);
        this->m_20 = -1;
        this->m_24 = -1;
        equip_list->refresh_equipment_list();
        this->equip_list->clear_decided();
        equip_list->start_scroll(188.0f);
        this->m_1c = 2U;
    case 2:
        update();
        if (this->equip_list->is_cancelled() != 0) {
            this->parent->on_submenu_closed();
            this->m_1c = 6U;
            return;
        }
        if (this->equip_list->is_decided() != 0) {
            this->m_1c = 3U;
        }
        break;
    case 3:
        ((TWindowSubStatusDisp *)(this->equip_list))->init_scroll_pos();
        if ((u32) this->equip_kind_list == 0U) {
            this->equip_kind_list = (TWindowMenuIconLine *)open_equip_kind_list(this->equip_list->get_cursor_value());
        }
        this->equip_kind_list->clear_decided();
        this->m_1c = 4U;
    case 4:
        update_displayed_item();
        if (this->equip_kind_list->is_cancelled() != 0) {
            this->m_1c = 1U;
            return;
        }
        if (this->equip_kind_list->is_decided() != 0) {
            this->m_1c = 5U;
            return;
        }
        break;
    case 5:
        if ((test_pressed_buttons_packed(&controller_input_state.controllers[controller_index], 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
            play_sound_effect(0x52F16, 0, 0, 0);
            this->m_1c = 3U;
            return;
        }
        TObjPlayer *selected_player;
        if (((selected_player = get_player_by_client_id(this->client_id)) != 0U) && (TWindowSubItem::is_usable(selected_player) != 0)) {
            apply_slot_selection();
            this->m_1c = 1U;
        }
        break;
    case 6:
        break;
    }
}

void TWindowSubEquip::render() {  }

s32 TWindowSubEquip::open_equip_kind_list(u32 arg1) {
    saddr equip_kind_window;
    equip_kind_window = reinterpret_cast<saddr>(create_equip_kind_window(
        get_window_layout_position(1), &equip_kind_window_size, this->client_id));
    ((TWindowBase *)equip_kind_window)->set_depth(get_main_menu_layer_depth((u8 *)this->parent, 1));
    ((TWindowMenuIconLine *)equip_kind_window)->ensure_status_display((saddr) (TWindowSubStatusDisp::get_message_10(0x24)));
    ((TWindowSubShortCutList *)equip_kind_window)->set_flag70_bit10();
    switch (arg1) {
    case 6:
        ((TWindowMenuIconLine *)equip_kind_window)->refresh_mag_item_list(0);
        break;
    case 2:
        ((TWindowMenuIconLine *)equip_kind_window)->refresh_armor_equip_list(1, 1);
        break;
    case 9:
    case 10:
    case 11:
    case 12:
        ((TWindowMenuIconLine *)equip_kind_window)->refresh_armor_equip_list(1, 3);
        break;
    case 3:
        ((TWindowMenuIconLine *)equip_kind_window)->refresh_armor_equip_list(1, 2);
        break;
    case 1:
        ((TWindowMenuIconLine *)equip_kind_window)->refresh_mag_item_list(2);
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
