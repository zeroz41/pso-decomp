#include "pso/unk/TWindowLayoutEntry.h"
#include "pso/ui/window/TWindowSubStatusDisp_80287570.h"
#pragma defer_codegen on

#include "types.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowCtrl_8024A054.h"
#include "pso/ui/window/TWindowSubStatusDisp_802671F0.h"
#include "pso/map/FloorArea.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/system/SoundEffect.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/ui/window/TWindowSubItemList.h"
#include "pso/item/TItem.h"
#include "pso/network/TLobby.h"
#include "pso/object/switch/TOSwitchItem.h"
#include "pso/ui/city/TShopEquipmentSellWindow.h"
#include "pso/ui/city/TShopGetItemWindow.h"
#include "pso/ui/city/TShopJudgmentItemWindow.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/ui/window/TWindowShortListCtrl.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/window/TWindowInputNumber.h"
#include "pso/ui/city/TShopArmorListWindow.h"
#include "pso/system/ControllerInput.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/player/TPlyItem.h"
#include "pso/ui/ItemListRow.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/player/PlayerSlots.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/system/SoundEffect.h"

#pragma readonly_strings on

#pragma inline_depth(1)

#pragma auto_inline off

#pragma dont_inline off

struct ItemData_80279754 {
    u8 b[0x14];
};

void add_item_purpose_actions(TWindowSubItem *window_sub_item, TWindowMenu *list, saddr item_id);

extern "C" {
s32 try_send_6x27_use_item(TObjPlayer *player, s32 key);
}

s32 has_armor_with_unit_slot(TWindowSubItem *window_sub_item, TItem *item);

#define BACK_PRESSED(idx) (test_pressed_buttons_packed(&controller_input_state.controllers[idx], 2) != 0 || test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)
const char *TWindowSubItem::class_name = "TWindowSubItem";

// Item list window position (x, y).
extern const NJS_POINT2 sub_item_list_window_position = {308.0f, 184.0f};

void TWindowSubItemList::build_item_list() {
    s32 ids[30];
    TObjPlayer *pl;
    player_stats *stats;
    u32 i;
    TItem *it;

    pl = get_player_by_client_id(client_index);
    if (pl != NULL) {
        item_count = pl->inventory_objects->run_and_get_result(ids);
        for (i = 0; i < item_count; i++) {
            it = find_item_by_id(ids[i]);
            if (it != NULL) {
                add_list_entry(it, ids[i]);
            }
        }
        for (i = 0; i < 5; i++) {
            add_battle_stat_entry(i, get_battle_item_id(i), 0);
        }
        stats = pl->get_stats();
        if (stats != NULL && stats->meseta > 0) {
            push_status_disp_entry(stats->meseta, -0xFF);
        }
        if (entry_count <= 0) {
            add_list_entry(-1);
        }
        calc_content_extent();
    }
}

void TWindowSubItemList::refresh() {
    save_cursor_selection();
    reset_list();
    build_item_list();
    clamp_selection_to_valid_entry();
    clamp_scroll_offset();
    reset_selected();
}

// Grey out the battle item rows.
void TWindowSubItemList::gray_out_battle_item_entries() {
    s32 i;
    ItemListRow *e;

    for (i = 0; i < entry_capacity; i++) {
        e = (ItemListRow *)get_array_entry(i);
        if (e->is_flag_4_set() != 0 && (e->get_item() & -0x10) == -0x10) {
            e->category_style = 0xFFAAAAAA;
            e->style = 0xFF909090;
            e->suffix_style = 0xFF909090;
            e->flags |= 0x80;
        }
    }
}

// Grey out the meseta row.
void TWindowSubItemList::gray_out_unusable_entries() {
    s32 i;
    ItemListRow *e;

    for (i = 0; i < entry_capacity; i++) {
        e = (ItemListRow *)get_array_entry(i);
        if (e->is_flag_4_set() != 0 && e->get_item() == -0xFF) {
            e->category_style = 0xFFAAAAAA;
            e->suffix_style = 0xFF909090;
            e->flags |= 0x80;
        }
    }
}

s32 get_battle_item_id(s32 stat) {
    return stat - 0x10;
}

s32 TWindowSubItemList::get_selected_entry() {
    return ((ItemListRow *)get_array_entry(selected_index))->get_item();
}

void TWindowSubItemList::set_cursor(s16 index) { cursor = index; }

void TWindowSubItemList::reset_selected() { selected_index = -1; }

void TWindowSubItemList::select_cursor_entry() {
    selected_index = cursor;
}

void TWindowSubItem::clear_flag_and_release() {
    *(u16 *)((s8 *)this + 0x60) = (u16) (*(u16 *)((s8 *)this + 0x60) & 0xFFFFFFFD);
    if ((u32) *(u32 *)((s8 *)this + 0x70) != 0U) {
        ((WindowHeading *)(*(saddr *)((s8 *)this + 0x70)))->set_state(1);
    }
}

void TWindowSubItem::set_flag60_bit10() { *(u16*)((char*)this + 0x60) |= 0x10; }

TWindowSubItem::TWindowSubItem(TWindowMainMenu *parent, s32 client) : TObject(parent) {
    m_name = class_name;
    parent_menu = parent;
    client_id = client;
    item_list = create_sub_item_list_window(get_window_layout_position(3), &sub_item_list_window_position, client_id);
    item_list->set_depth(get_main_menu_layer_depth((u8 *)parent_menu, 0));
    item_list->set_flag70_bit10();
    help_window = 0;
    purpose_menu = 0;
    confirm_menu = 0;
    count_input = 0;
    displayed_item = -1;
    amount = 0;
    state = 0;
}

TWindowSubItem::~TWindowSubItem() {
    if (count_input != 0) { ((TWindowBase *)count_input)->close(); count_input = 0; }
    if (confirm_menu != 0) { confirm_menu->close(); confirm_menu = 0; }
    if (purpose_menu != 0) { purpose_menu->close(); purpose_menu = 0; }
    if (help_window != 0) { help_window->close(); help_window = 0; }
    if (item_list != 0) { item_list->close(); item_list = 0; }
}

void TWindowSubItem::run_task() {
    TObjPlayer *p;
    s32 idx;
    p = get_player_by_client_id(this->client_id);
    if (p != 0) {
        idx = is_player_input_active(this->client_id);
        switch (this->state) {
        case 0:
        case 1:
            if (this->count_input != 0) {
                ((TWindowBase *)(this->count_input))->close();
                this->count_input = 0;
            }
            if (this->confirm_menu != 0) {
                this->confirm_menu->close();
                this->confirm_menu = 0;
            }
            if (this->purpose_menu != 0) {
                this->purpose_menu->close();
                this->purpose_menu = 0;
            }
            if (this->help_window == 0) {
                this->help_window = new TWindowHelpItem(get_window_layout_position(2), this->client_id);
                this->help_window->set_depth(get_main_menu_layer_depth((u8 *)this->parent_menu, 4));
                this->displayed_item = -1;
            }
            item_list->refresh();
            item_list->clear_decided();
            this->state = 2;
        case 2:
            set_displayed_item(item_list->get_cursor_value());
            if (item_list->is_cancelled() != 0) {
                parent_menu->on_submenu_closed();
                this->state = 0x17;
                return;
            }
            if (item_list->is_decided() != 0) {
                this->state = 3;
                return;
            }
            break;
        case 3:
            if (this->count_input != 0) {
                ((TWindowBase *)(this->count_input))->close();
                this->count_input = 0;
            }
            if (this->confirm_menu != 0) {
                this->confirm_menu->close();
                this->confirm_menu = 0;
            }
            if (this->help_window != 0) {
                this->help_window->close();
                this->help_window = 0;
            }
            if (this->purpose_menu == 0) {
                this->purpose_menu = open_purpose_window(item_list->get_cursor_value());
            }
            this->purpose_menu->clear_flag_and_release();
            this->purpose_menu->clear_transition_flag();
            this->state = 4;
        case 4:
            if (this->purpose_menu->get_selected_value() == 0) {
                TWindowShortListCtrl::assign_item_to_palette(item_list->get_cursor_value(), this->client_id);
            }
            if (this->purpose_menu->is_cancelled() != 0) {
                this->state = 1;
            }
            if (this->purpose_menu->is_decided() != 0) {
                set_cursor_row_for_mode((s32)(this->purpose_menu->get_selected_value()));
                return;
            }
            break;
        case 5:
            if (BACK_PRESSED(idx)) {
                play_sound_effect(0x52F16, 0, 0, 0);
                this->state = 3;
            }
            if (TWindowSubItem::is_usable(p) != 0) {
                exec_item_command(item_list->get_cursor_value(), this->purpose_menu->get_selected_value());
                return;
            }
            break;
        case 6:
            this->purpose_menu->open();
            this->confirm_menu = create_menu_window();
            this->state = 7;
        case 7:
            if (this->confirm_menu->is_cancelled() != 0) {
                this->state = 3;
            }
            if (this->confirm_menu->is_decided() != 0) {
                close_windows(this->confirm_menu->get_selected_value());
                return;
            }
            break;
        case 8: {
            s16 cur = item_list->get_cursor_index();
            item_list->refresh();
            item_list->gray_out_battle_item_entries();
            item_list->gray_out_unusable_entries();
            item_list->set_cursor(cur);
            item_list->clear_decided();
            item_list->reset_selected();
            this->state = 9;
        }
        case 9:
            if (item_list->is_cancelled() != 0) {
                parent_menu->on_submenu_closed();
                this->state = 0x17;
                return;
            }
            if (item_list->is_decided() != 0) {
                item_list->clear_decided();
                this->state = 0xA;
                return;
            }
            break;
        case 10:
            item_list->gray_out_battle_item_entries();
            item_list->gray_out_unusable_entries();
            item_list->select_cursor_entry();
            item_list->clear_decided();
            this->state = 0xB;
        case 11:
            if (item_list->is_cancelled() != 0) {
                this->state = 8;
                return;
            }
            if (item_list->is_decided() != 0) {
                use_selected_item();
                item_list->clear_decided();
                this->state = 8;
                return;
            }
            break;
        case 12: {
            s32 n = find_item_by_id(item_list->get_cursor_value())->get_amount();
            if (n <= 1) {
                this->amount = 1;
                this->state = 0xE;
                return;
            }
            this->purpose_menu->open();
            if (this->count_input == 0) {
                this->count_input = create_count_input(n);
            }
            reinterpret_cast<TWindowSubItem *>(this->count_input)->clear_flag_and_release();
            this->state = 0xD;
        }
        case 13:
            if (((TWindowInputNumber *)(this->count_input))->is_cancelled() != 0) {
                this->state = 3;
            }
            if (((TWindowInputNumber *)(this->count_input))->is_confirmed() != 0) {
                this->amount = ((TWindowInputNumber *)(this->count_input))->get_value();
                this->state = 0xE;
                return;
            }
            break;
        case 14:
            if (BACK_PRESSED(idx)) {
                play_sound_effect(0x52F16, 0, 0, 0);
                this->state = 3;
            }
            if (TWindowSubItem::is_usable(p) != 0) {
                p->request_item_drop(item_list->get_cursor_value(), this->amount);
                this->state = 0x16;
                return;
            }
            break;
        case 15:
            this->state = 0x10;
        case 16:
            if (BACK_PRESSED(idx)) {
                play_sound_effect(0x52F16, 0, 0, 0);
                this->state = 1;
            }
            p = get_player_by_client_id(this->client_id);
            if (p != 0 && TWindowSubItem::is_usable(p) != 0 && TWindowCtrl::is_client_countdown_done(this->client_id) != 0) {
                p->send_trap_packet(item_list->get_cursor_value() & 0xF);
                this->state = 1;
                return;
            }
            break;
        case 17:
            this->state = 0x12;
        case 18:
            if (BACK_PRESSED(idx)) {
                play_sound_effect(0x52F16, 0, 0, 0);
                this->state = 1;
            }
            p = get_player_by_client_id(this->client_id);
            if (p != 0 && TWindowSubItem::is_usable(p) != 0 && TAdSinglePlyChrSelectGC::create_if_key_pressed() != 0) {
                p->sonar_stock.consume(1);
                this->state = 1;
                return;
            }
            break;
        case 19: {
            player_stats *stats = p->get_stats();
            s32 n;
            if (stats == NULL) {
                this->state = 0x16;
                return;
            }
            n = stats->meseta;
            if (n <= 1) {
                if (n == 1) {
                    this->amount = 1;
                    this->state = 0x15;
                    return;
                }
                this->state = 0x16;
                return;
            }
            this->purpose_menu->open();
            if (this->count_input == 0) {
                this->count_input = create_count_input(n);
            }
            reinterpret_cast<TWindowSubItem *>(this->count_input)->clear_flag_and_release();
            this->state = 0x14;
        }
        case 20:
            if (((TWindowInputNumber *)(this->count_input))->is_cancelled() != 0) {
                this->state = 3;
            }
            if (((TWindowInputNumber *)(this->count_input))->is_confirmed() != 0) {
                this->amount = ((TWindowInputNumber *)(this->count_input))->get_value();
                this->state = 0x15;
                return;
            }
            break;
        case 21:
            if (BACK_PRESSED(idx)) {
                play_sound_effect(0x52F16, 0, 0, 0);
                this->state = 3;
            }
            if (TWindowSubItem::is_usable(p) != 0) {
                p->request_meseta_drop(this->amount);
                this->state = 0x16;
                return;
            }
            break;
        case 22:
            if ((u32)p->is_action_active() == 0) {
                this->state = 1;
            }
            break;
        case 23:
            break;
        }
    }
}

#undef BACK_PRESSED
void TWindowSubItem::render() {  }

TWindowMenu *TWindowSubItem::open_purpose_window(s32 item_id) {
    TWindowMenu *titled_window_menu;
    titled_window_menu = create_titled_window_menu(get_window_layout_position(4), 3, (saddr)TWindowSubStatusDisp::get_message_10(0x26), this->client_id);
    if (item_id == -0xFF) {
        TWindowSubItem::add_meseta_purpose_actions((saddr)this, titled_window_menu);
    } else if ((s32) (item_id & 0xFFFFFFF0) == -0x10) {
        TWindowSubItem::draw_slot((saddr)this, titled_window_menu, item_id);
    } else {
        add_item_purpose_actions(this, titled_window_menu, item_id);
    }
    titled_window_menu->set_depth(get_main_menu_layer_depth((u8 *)this->parent_menu, 1));
    titled_window_menu->set_flag70_bit10();
    titled_window_menu->update_layout_height(224.0f);
    align_menu_entry_positions(titled_window_menu);
    return titled_window_menu;
}

TWindowMenu *TWindowSubItem::create_menu_window() {
    TWindowMenu *titled_window_menu;
    titled_window_menu = create_titled_window_menu(get_window_layout_position(6), 2, (saddr)TWindowSubStatusDisp::get_message_10(0x27), this->client_id);
    titled_window_menu->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x5D)), 6, 0);
    titled_window_menu->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x5E)), 6, 1);
    titled_window_menu->set_depth(get_main_menu_layer_depth((u8 *)this->parent_menu, 2));
    titled_window_menu->set_flag70_bit10();
    titled_window_menu->update_layout_height(224.0f);
    align_menu_entry_positions(titled_window_menu);
    return titled_window_menu;
}

s32 TWindowSubItem::create_count_input(s32 maximum) {
    saddr storage;

    storage = (saddr)new TWindowInputNumber(get_window_layout_position(5), 1, maximum, 1, (s16) this->client_id);
    ((TWindowInputNumber *)storage)->create((saddr)TWindowSubStatusDisp::get_message_10(0x28));
    ((TWindowBase *)storage)->set_depth(get_main_menu_layer_depth((u8 *)this->parent_menu, 3));
    ((TWindowInputNumber *)storage)->set_value(224.0f);
    ((TWindowSubItem *)storage)->set_flag60_bit10();
    return storage;
}

void TWindowSubItem::add_meseta_purpose_actions(saddr owner, TWindowMenu *titled_window_menu) {
    if (get_current_floor_area() == AREA_LOBBY) {
        add_gray_text_entry(titled_window_menu, (const char *)(TWindowSubStatusDisp::get_message_10(0x5F)), 6, 6);
        return;
    }
    titled_window_menu->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x5F)), 6, 6);
}

void TWindowSubItem::draw_slot(saddr owner, TWindowMenu *titled_window_menu, s32 item_id) {
    s32 id;

    id = ((u32)__cntlzw(4 - (item_id & 0xF)) >> 5) + 4;
    if ((is_current_area_item_enabled() == 0) || (is_boss_area() != 0)) {
        add_gray_text_entry(titled_window_menu, (const char *)(get_localized_text_entry(0x10, 0xF)), 6, id);
        return;
    }
    titled_window_menu->add_text_entry(get_localized_text_entry(0x10, 0xF), 0x26, id);
}

void add_item_purpose_actions(TWindowSubItem *window_sub_item, TWindowMenu *list, saddr item_id) {
  s32 sp8;
  TItem *item;
  TObjPlayer *player;
  item = find_item_by_id((saddr)((void *) item_id));
  if (item != 0)
  {
    if (item->get_usable_action_flags(2, 0) != 0U)
    {
      if ((item->get_usable_action_flags(1, 0) != 0U) || (get_current_floor_area() == AREA_LOBBY))
      {
        add_gray_text_entry(list, (const char *)(TWindowSubStatusDisp::get_message_10(0x60)), 6, 0);
      }
      else
      {
        list->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x60)), 6, 0);
      }
    }
    item->get_item_type();
    if (item->get_usable_action_flags(8, 0) != 0U)
    {
      if (item->test_item_flags(8) != 0U)
      {
        if (get_current_floor_area() == AREA_LOBBY)
        {
          add_gray_text_entry(list, (const char *)(TWindowSubStatusDisp::get_message_10(0x61)), 6, 2);
        }
        else
        {
          list->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x61)), 6, 2);
        }
      }
      else
      {
        player = get_player_by_client_id(window_sub_item->client_id);
        if (player != NULL)
        {
          if (((item->check_equip_requirements(player, (s16 *)&sp8) != 0) && (has_armor_with_unit_slot(window_sub_item, item) != 0)) && (get_current_floor_area() != AREA_LOBBY))
          {
            list->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x62)), 6, 1);
          }
          else
          {
            add_gray_text_entry(list, (const char *)(TWindowSubStatusDisp::get_message_10(0x62)), 6, 1);
          }
        }
      }
    }
    if ((get_current_floor_area() == AREA_LOBBY) || (item->get_usable_action_flags(0x10, 0) != 0U))
    {
      add_gray_text_entry(list, (const char *)(TWindowSubStatusDisp::get_message_10(0x5F)), 6, 3);
    }
    else
    {
      list->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x5F)), 6, 3);
    }
    if (get_current_floor_area() == AREA_LOBBY)
    {
      add_gray_text_entry(list, (const char *)(TWindowSubStatusDisp::get_message_10(0x63)), 6, 7);
      return;
    }
    list->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x63)), 6, 7);
  }
}

void TWindowSubItem::set_cursor_row_for_mode(s32 mode) {
    switch (mode) {
    case 3:
        this->state = 0xC;
        return;
    case 4:
        this->state = 0xF;
        return;
    case 5:
        this->state = 0x11;
        return;
    case 6:
        this->state = 0x13;
        return;
    case 7:
        this->state = 6;
        return;
    case 0:
    case 1:
    case 2:
        this->state = 5;
        return;
    }
}

void TWindowSubItem::exec_item_command(saddr item_id, s32 command) {
    TObjPlayer *player;
    TItem *item;
    saddr t;

    player = get_player_by_client_id(this->client_id);
    if ((player != NULL) && (item = find_item_by_id(item_id), ((item == NULL) == 0))) {
        switch (command) {
        case 3:
            break;
        case 0:
            try_send_6x27_use_item(player, item_id);
            this->state = 0x16;
            break;
        case 1: {
            TItem *held = (TItem *)TObjPlayer::get_slot_value(player->equipped_items.items, item->get_attach_slot());
            if (held != NULL) {
                t = held->get_item_id();
                TObjPlayer::send_6x26_unequip_item(player, t);
            }
            send_6x25_equip_item(player, item_id, 0);
            this->state = 0x16;
            break;
        }
        case 2:
            TObjPlayer::send_6x26_unequip_item(player, item_id);
            this->state = 0x16;
            break;
        }
    }
}

void TWindowSubItem::close_windows(s32 mode) {
    TObjPlayer *player = get_player_by_client_id(this->client_id);
    if (player != NULL) {
        switch (mode) {
        case 0:
            player->close_sub_window();
            this->state = 0x16;
            return;
        case 1:
            if (this->confirm_menu != NULL) {
                this->confirm_menu->close();
                this->confirm_menu = 0U;
            }
            if (this->purpose_menu != NULL) {
                this->purpose_menu->close();
                this->purpose_menu = 0U;
            }
            this->state = 0xA;
            break;
        }
    }
}

#pragma push
#pragma scheduling off
void TWindowSubItem::use_selected_item() {
    TObjPlayer *player;
    player = get_player_by_client_id(this->client_id);
    if (player != NULL) {
        player->swap_inventory_items((int) (this->item_list->get_cursor_value()), this->item_list->get_selected_entry());
    }
}

#pragma pop
s32 has_armor_with_unit_slot(TWindowSubItem *window_sub_item, TItem *item) {
    ItemData_80279754 d;
    TObjPlayer *pl;
    uaddr armor;
    pl = get_player_by_client_id(window_sub_item->client_id);
    if (pl == NULL) {
        return 0;
    }
    if (item->get_item_type() != 1) {
        return 1;
    }
    if (item->get_item_group() != 3) {
        return 1;
    }
    armor = TObjPlayer::get_slot_value(pl->equipped_items.items, 2);
    if (armor == 0) {
        return 0;
    }
    ((TItem *)armor)->copy_to_item_data((TItemData *)&d);
    return d.b[5] != 0 ? 1 : 0;
}

void TWindowSubItem::set_displayed_item(s32 id) {
    if ((this->help_window != NULL) && (id != (s32) this->displayed_item)) {
        this->displayed_item = id;
        this->help_window->set_displayed_item_by_id(id);
    }
}
