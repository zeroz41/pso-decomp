#include "pso/unk/TWindowLayoutEntry.h"
#pragma defer_codegen on

#include "types.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/ui/window/TWindowCtrl_8024A054.h"
#include "pso/ui/window/TWindowSubStatusDisp_802671F0.h"
#include "pso/map/FloorArea.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowSubShortCutList.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/item/TItem.h"
#include "pso/unk/TLobby.h"
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
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TPlyItem.h"
#include "pso/ui/ItemListRow.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/ui/window/TWindowSubEquip_80263AB0.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/player/PlayerSlots.h"

#pragma readonly_strings on

#pragma inline_depth(1)

#pragma auto_inline off

#pragma dont_inline off

struct ItemData_80279754 {
    u8 b[0x14];
};

extern "C" {
void TWindowSubItem__sub_8027AA30(u8 *arg0);
s32 TWindowSubItem__sub_8027AA78(s32 arg0);
saddr get_window_layout_position(s32);
s32 TObjPlayer__sub_801B7B58(int, int, int);
}

saddr create_titled_window_menu(saddr position, s32 count, saddr title, s32 client_id);
void add_item_purpose_actions(TWindowSubItem *arg0, saddr arg1, saddr arg2);

extern "C" {
struct Wn_8027AA80 { u8 pad0[0x76]; s16 f76; };
struct Wn_8027AB10 { u8 pad0[0x76]; s16 f76; };
struct Quest_8027ABFC { u8 pad[0x20]; s32 count; };
struct Win_8027ABFC { u8 pad0[0x20]; s16 id; u8 pad1[0x72 - 0x22]; s16 sel; u8 pad2[0x8C - 0x74]; u32 n; };
void TWindowSubItem__sub_8027AB10(Wn_8027AB10 *arg0);
void populate_sub_item_list(Win_8027ABFC *arg0);
void decrement_clamped(void *, s32);
void play_sound_effect(s32, s32, s32, s32);
s32 TWindowCtrl__sub_8024A228(saddr);
s32 send_6x25_equip_item(s32, s32, s32);
s32 close_sub_window__10TObjPlayerFv();
s32 try_send_6x27_use_item(s32, s32);
s32 create_sub_item_list_window(saddr, const f32 *, s32);
}

s32 has_armor_with_unit_slot(TWindowSubItem *window_sub_item, TItem *item);

#define BACK_PRESSED(idx) (test_pressed_buttons_packed(&controller_input_state.controllers[idx], 2) != 0 || test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)
const char *TWindowSubItem::class_name = "TWindowSubItem";

// Item list window position (x, y).
extern const f32 lbl_8044F998[2] = {308.0f, 184.0f};

void populate_sub_item_list(Win_8027ABFC *arg0) {
    s32 ids[30];
    TObjPlayer *pl;
    Quest_8027ABFC *q;
    u32 i;
    TItem *it;

    pl = get_player_by_client_id(arg0->id);
    if (pl != NULL) {
        arg0->n = pl->inventory_objects->run_and_get_result((saddr)ids);
        for (i = 0; i < arg0->n; i++) {
            it = find_item_by_id(ids[i]);
            if (it != NULL) {
                ((TWindowMenuIconLine *)arg0)->add_list_entry(it, ids[i]);
            }
        }
        for (i = 0; i < 5; i++) {
            add_battle_stat_entry(arg0, i, TWindowSubItem__sub_8027AA78(i), 0);
        }
        q = (Quest_8027ABFC *)pl->get_stats();
        if (q != NULL && q->count > 0) {
            push_status_disp_entry(arg0, q->count, -0xFF);
        }
        if (arg0->sel <= 0) {
            ((TWindowSubStatusDisp *)arg0)->add_list_entry(-1);
        }
        ((TWindowMenuIconLine *)arg0)->calc_content_extent();
    }
}

void TWindowSubItem::refresh() { ((TShopArmorListWindow *)this)->save_cursor_selection(); ((TWindowMenuIconLine *)this)->reset_list(); populate_sub_item_list((Win_8027ABFC*)(this)); ((TShopArmorListWindow *)this)->clamp_selection_to_valid_entry(); ((TWindowSubStatusDisp *)this)->clamp_scroll_offset(); reset_selected(); }

void TWindowSubItem__sub_8027AB10(Wn_8027AB10 *arg0) {
    s32 i;
    ItemListRow *e;

    for (i = 0; i < arg0->f76; i++) {
        e = (ItemListRow *)((TWindowBase *)arg0)->get_array_entry(i);
        if (((TWindowLayoutEntry *)e)->is_flag_4_set() != 0 && (((ItemListRow *)e)->get_item() & -0x10) == -0x10) {
            e->category_style = 0xFFAAAAAA;
            e->style = 0xFF909090;
            e->suffix_style = 0xFF909090;
            e->flags |= 0x80;
        }
    }
}

void TWindowSubItem::gray_out_unusable_entries() {
    s32 i;
    ItemListRow *e;

    for (i = 0; i < ((Wn_8027AA80 *)this)->f76; i++) {
        e = (ItemListRow *)((TWindowBase *)this)->get_array_entry(i);
        if (((TWindowLayoutEntry *)e)->is_flag_4_set() != 0 && ((ItemListRow *)e)->get_item() == -0xFF) {
            e->category_style = 0xFFAAAAAA;
            e->suffix_style = 0xFF909090;
            e->flags |= 0x80;
        }
    }
}

s32 TWindowSubItem__sub_8027AA78(s32 arg0) {
    return arg0 - 0x10;
}

s32 TWindowSubItem::get_selected_entry() {
    return ((ItemListRow *)((TWindowBase *)this)->get_array_entry(*(s16 *)((s8 *)this + 0x88)))->get_item();
}

void TWindowSubItem::set_field_74(s16 v) { *(s16*)((char*)this + 0x74) = v; }

void TWindowSubItem::reset_selected() { *(s16*)((char*)this + 0x88) = -1; }

void TWindowSubItem__sub_8027AA30(u8 *arg0) {
    *(s16 *)((s8 *)arg0 + 0x88) = (s16) *(s16 *)((s8 *)arg0 + 0x74);
}

void TWindowSubItem::clear_flag_and_release() {
    *(u16 *)((s8 *)this + 0x60) = (u16) (*(u16 *)((s8 *)this + 0x60) & 0xFFFFFFFD);
    if ((u32) *(u32 *)((s8 *)this + 0x70) != 0U) {
        ((TWindowSubStatusDisp *)(*(saddr *)((s8 *)this + 0x70)))->set_entry_state(1);
    }
}

void TWindowSubItem::set_flag60_bit10() { *(u16*)((char*)this + 0x60) |= 0x10; }

TWindowSubItem::TWindowSubItem(TWindowMainMenu *parent, s32 client) : TObject(parent) {
    m_name = class_name;
    parent_menu = parent;
    client_id = client;
    item_list = create_sub_item_list_window(get_window_layout_position(3), lbl_8044F998, client_id);
    ((TWindowBase *)item_list)->set_depth(TWindowSubEquip__sub_80263AF8((u8 *)parent_menu, 0));
    ((TWindowSubShortCutList *)item_list)->set_flag70_bit10();
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
    if (confirm_menu != 0) { ((TWindowBase *)confirm_menu)->close(); confirm_menu = 0; }
    if (purpose_menu != 0) { ((TWindowBase *)purpose_menu)->close(); purpose_menu = 0; }
    if (help_window != 0) { ((TWindowBase *)help_window)->close(); help_window = 0; }
    if (item_list != 0) { ((TWindowBase *)item_list)->close(); item_list = 0; }
}

void TWindowSubItem::run_task() {
    saddr p;
    s32 idx;
    p = (saddr)get_player_by_client_id(this->client_id);
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
                ((TWindowBase *)(this->confirm_menu))->close();
                this->confirm_menu = 0;
            }
            if (this->purpose_menu != 0) {
                ((TWindowBase *)(this->purpose_menu))->close();
                this->purpose_menu = 0;
            }
            if (this->help_window == 0) {
                this->help_window = new TWindowHelpItem((void *)get_window_layout_position(2), this->client_id);
                ((TWindowBase *)this->help_window)->set_depth(TWindowSubEquip__sub_80263AF8((u8 *)this->parent_menu, 4));
                this->displayed_item = -1;
            }
            ((TWindowSubItem *)item_list)->refresh();
            ((TWindowMenuIconLine *)item_list)->clear_decided();
            this->state = 2;
        case 2:
            set_displayed_item(((TWindowMenuIconLine *)item_list)->get_cursor_value());
            if (((TWindowMenuIconLine *)item_list)->is_cancelled() != 0) {
                parent_menu->on_submenu_closed();
                this->state = 0x17;
                return;
            }
            if (((TWindowMenuIconLine *)item_list)->is_decided() != 0) {
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
                ((TWindowBase *)(this->confirm_menu))->close();
                this->confirm_menu = 0;
            }
            if (this->help_window != 0) {
                ((TWindowBase *)(this->help_window))->close();
                this->help_window = 0;
            }
            if (this->purpose_menu == 0) {
                this->purpose_menu = open_purpose_window(((TWindowMenuIconLine *)item_list)->get_cursor_value());
            }
            ((TWindowMenu *)(this->purpose_menu))->clear_flag_and_release();
            ((TWindowMenu *)(this->purpose_menu))->clear_transition_flag();
            this->state = 4;
        case 4:
            if (((TWindowMenu *)(this->purpose_menu))->get_selected_value() == 0) {
                TWindowShortListCtrl::assign_item_to_palette(((TWindowMenuIconLine *)item_list)->get_cursor_value(), this->client_id);
            }
            if (((TWindowMenu *)(this->purpose_menu))->is_cancelled() != 0) {
                this->state = 1;
            }
            if (((TWindowMenu *)(this->purpose_menu))->is_decided() != 0) {
                set_cursor_row_for_mode((s32)(((TWindowMenu *)(this->purpose_menu))->get_selected_value()));
                return;
            }
            break;
        case 5:
            if (BACK_PRESSED(idx)) {
                play_sound_effect(0x52F16, 0, 0, 0);
                this->state = 3;
            }
            if (TWindowSubItem::is_usable(p) != 0) {
                exec_item_command(((TWindowMenuIconLine *)item_list)->get_cursor_value(), ((TWindowMenu *)(this->purpose_menu))->get_selected_value());
                return;
            }
            break;
        case 6:
            ((TWindowMenu *)(this->purpose_menu))->open();
            this->confirm_menu = create_menu_window();
            this->state = 7;
        case 7:
            if (((TWindowMenu *)(this->confirm_menu))->is_cancelled() != 0) {
                this->state = 3;
            }
            if (((TWindowMenu *)(this->confirm_menu))->is_decided() != 0) {
                close_windows(((TWindowMenu *)(this->confirm_menu))->get_selected_value());
                return;
            }
            break;
        case 8: {
            s16 cur = ((TShopGetItemWindow *)item_list)->get_cursor_index();
            ((TWindowSubItem *)item_list)->refresh();
            TWindowSubItem__sub_8027AB10((Wn_8027AB10 *) item_list);
            ((TWindowSubItem *)item_list)->gray_out_unusable_entries();
            ((TWindowSubItem *)item_list)->set_field_74(cur);
            ((TWindowMenuIconLine *)item_list)->clear_decided();
            ((TWindowSubItem *)item_list)->reset_selected();
            this->state = 9;
        }
        case 9:
            if (((TWindowMenuIconLine *)item_list)->is_cancelled() != 0) {
                parent_menu->on_submenu_closed();
                this->state = 0x17;
                return;
            }
            if (((TWindowMenuIconLine *)item_list)->is_decided() != 0) {
                ((TWindowMenuIconLine *)item_list)->clear_decided();
                this->state = 0xA;
                return;
            }
            break;
        case 10:
            TWindowSubItem__sub_8027AB10((Wn_8027AB10 *) item_list);
            ((TWindowSubItem *)item_list)->gray_out_unusable_entries();
            TWindowSubItem__sub_8027AA30((u8 *) item_list);
            ((TWindowMenuIconLine *)item_list)->clear_decided();
            this->state = 0xB;
        case 11:
            if (((TWindowMenuIconLine *)item_list)->is_cancelled() != 0) {
                this->state = 8;
                return;
            }
            if (((TWindowMenuIconLine *)item_list)->is_decided() != 0) {
                use_selected_item();
                ((TWindowMenuIconLine *)item_list)->clear_decided();
                this->state = 8;
                return;
            }
            break;
        case 12: {
            s32 n = find_item_by_id(((TWindowMenuIconLine *)item_list)->get_cursor_value())->get_amount();
            if (n <= 1) {
                this->amount = 1;
                this->state = 0xE;
                return;
            }
            ((TWindowMenu *)(this->purpose_menu))->open();
            if (this->count_input == 0) {
                this->count_input = create_count_input(n);
            }
            reinterpret_cast<TWindowSubItem *>(this->count_input)->clear_flag_and_release();
            this->state = 0xD;
        }
        case 13:
            if (((TShopEquipmentSellWindow *)(this->count_input))->is_confirmed() != 0) {
                this->state = 3;
            }
            if (((TWindowInputNumber *)(this->count_input))->is_confirmed() != 0) {
                this->amount = ((TShopEquipmentSellWindow *)(this->count_input))->get_result();
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
                ((TObjPlayer *)p)->request_item_drop(((TWindowMenuIconLine *)item_list)->get_cursor_value(), this->amount);
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
            p = (saddr)get_player_by_client_id(this->client_id);
            if (p != 0 && TWindowSubItem::is_usable(p) != 0 && TWindowCtrl__sub_8024A228(this->client_id) != 0) {
                ((TObjPlayer *)p)->send_trap_packet(((TWindowMenuIconLine *)item_list)->get_cursor_value() & 0xF);
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
            p = (saddr)get_player_by_client_id(this->client_id);
            if (p != 0 && TWindowSubItem::is_usable(p) != 0 && TAdSinglePlyChrSelectGC::create_if_key_pressed() != 0) {
                decrement_clamped((void *)(p + 0x7C8), 1);
                this->state = 1;
                return;
            }
            break;
        case 19: {
            Quest_8027ABFC *q = (Quest_8027ABFC *)((TObjPlayer *)p)->get_stats();
            s32 n;
            if (q == NULL) {
                this->state = 0x16;
                return;
            }
            n = q->count;
            if (n <= 1) {
                if (n == 1) {
                    this->amount = 1;
                    this->state = 0x15;
                    return;
                }
                this->state = 0x16;
                return;
            }
            ((TWindowMenu *)(this->purpose_menu))->open();
            if (this->count_input == 0) {
                this->count_input = create_count_input(n);
            }
            reinterpret_cast<TWindowSubItem *>(this->count_input)->clear_flag_and_release();
            this->state = 0x14;
        }
        case 20:
            if (((TShopEquipmentSellWindow *)(this->count_input))->is_confirmed() != 0) {
                this->state = 3;
            }
            if (((TWindowInputNumber *)(this->count_input))->is_confirmed() != 0) {
                this->amount = ((TShopEquipmentSellWindow *)(this->count_input))->get_result();
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
                ((TObjPlayer *)p)->request_meseta_drop(this->amount);
                this->state = 0x16;
                return;
            }
            break;
        case 22:
            if ((u32)((TObjPlayer *)p)->is_action_active() == 0) {
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

s32 TWindowSubItem::open_purpose_window(s32 arg1) {
    saddr titled_window_menu;
    titled_window_menu = create_titled_window_menu(((int)get_window_layout_position(4)), 3, (saddr)TWindowSubStatusDisp::get_message_10(0x26), this->client_id);
    if (arg1 == -0xFF) {
        TWindowSubItem::add_meseta_purpose_actions((saddr)this, titled_window_menu);
    } else if ((s32) (arg1 & 0xFFFFFFF0) == -0x10) {
        TWindowSubItem::draw_slot((saddr)this, titled_window_menu, arg1);
    } else {
        add_item_purpose_actions((TWindowSubItem *)this, titled_window_menu, arg1);
    }
    ((TWindowBase *)titled_window_menu)->set_depth(TWindowSubEquip__sub_80263AF8((u8 *)this->parent_menu, 1));
    ((TWindowMenu *)titled_window_menu)->set_flag70_bit10();
    ((TWindowMenu *)titled_window_menu)->update_layout_height(224.0f);
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(titled_window_menu));
    return titled_window_menu;
}

s32 TWindowSubItem::create_menu_window() {
    saddr titled_window_menu;
    titled_window_menu = create_titled_window_menu(((int)get_window_layout_position(6)), 2, (saddr)TWindowSubStatusDisp::get_message_10(0x27), this->client_id);
    ((TWindowMenu *)titled_window_menu)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x5D)), 6, 0);
    ((TWindowMenu *)titled_window_menu)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x5E)), 6, 1);
    ((TWindowBase *)titled_window_menu)->set_depth(TWindowSubEquip__sub_80263AF8((u8 *)this->parent_menu, 2));
    ((TWindowMenu *)titled_window_menu)->set_flag70_bit10();
    ((TWindowMenu *)titled_window_menu)->update_layout_height(224.0f);
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(titled_window_menu));
    return titled_window_menu;
}

s32 TWindowSubItem::create_count_input(s32 maximum) {
    saddr storage;

    storage = (saddr)new TWindowInputNumber((void *)get_window_layout_position(5), 1, maximum, 1, (s16) this->client_id);
    ((TWindowInputNumber *)storage)->create((saddr)TWindowSubStatusDisp::get_message_10(0x28));
    ((TWindowBase *)storage)->set_depth(TWindowSubEquip__sub_80263AF8((u8 *)this->parent_menu, 3));
    ((TWindowInputNumber *)storage)->set_value(224.0f);
    ((TWindowSubItem *)storage)->set_flag60_bit10();
    return storage;
}

void TWindowSubItem::add_meseta_purpose_actions(saddr arg0, saddr titled_window_menu) {
    if (get_current_floor_area() == AREA_LOBBY) {
        add_gray_text_entry((TWindowMenu *)titled_window_menu, (const char *)(TWindowSubStatusDisp::get_message_10(0x5F)), 6, 6);
        return;
    }
    ((TWindowMenu *)titled_window_menu)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x5F)), 6, 6);
}

void TWindowSubItem::draw_slot(saddr arg1, saddr titled_window_menu, s32 arg3) {
    s32 id;

    id = ((u32)__cntlzw(4 - (arg3 & 0xF)) >> 5) + 4;
    if ((is_current_area_item_enabled() == 0) || (is_boss_area() != 0)) {
        add_gray_text_entry((TWindowMenu *)titled_window_menu, (const char *)(get_localized_text_entry(0x10, 0xF)), 6, id);
        return;
    }
    ((TWindowMenu *)titled_window_menu)->add_text_entry(get_localized_text_entry(0x10, 0xF), 0x26, id);
}

void add_item_purpose_actions(TWindowSubItem *window_sub_item, saddr list, saddr arg2) {
  s32 sp8;
  saddr item;
  saddr player;
  item = ((saddr)find_item_by_id((saddr)((void *) arg2)));
  if (item != 0)
  {
    if (((TItem *)item)->get_usable_action_flags(2, 0) != 0U)
    {
      if ((((TItem *)item)->get_usable_action_flags(1, 0) != 0U) || (get_current_floor_area() == AREA_LOBBY))
      {
        add_gray_text_entry((TWindowMenu *)list, (const char *)(TWindowSubStatusDisp::get_message_10(0x60)), 6, 0);
      }
      else
      {
        ((TWindowMenu *)list)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x60)), 6, 0);
      }
    }
    ((TItem *)item)->get_item_type();
    if (((TItem *)item)->get_usable_action_flags(8, 0) != 0U)
    {
      if (((TItem *)item)->test_item_flags(8) != 0U)
      {
        if (get_current_floor_area() == AREA_LOBBY)
        {
          add_gray_text_entry((TWindowMenu *)list, (const char *)(TWindowSubStatusDisp::get_message_10(0x61)), 6, 2);
        }
        else
        {
          ((TWindowMenu *)list)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x61)), 6, 2);
        }
      }
      else
      {
        player = (saddr)get_player_by_client_id(window_sub_item->client_id);
        if (player != 0)
        {
          if (((((TItem *)item)->check_equip_requirements((TObjPlayer *)player, (s16 *)(&sp8)) != 0) && (has_armor_with_unit_slot(window_sub_item, (TItem *)item) != 0)) && (get_current_floor_area() != AREA_LOBBY))
          {
            ((TWindowMenu *)list)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x62)), 6, 1);
          }
          else
          {
            add_gray_text_entry((TWindowMenu *)list, (const char *)(TWindowSubStatusDisp::get_message_10(0x62)), 6, 1);
          }
        }
      }
    }
    if ((get_current_floor_area() == AREA_LOBBY) || (((TItem *)item)->get_usable_action_flags(0x10, 0) != 0U))
    {
      add_gray_text_entry((TWindowMenu *)list, (const char *)(TWindowSubStatusDisp::get_message_10(0x5F)), 6, 3);
    }
    else
    {
      ((TWindowMenu *)list)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x5F)), 6, 3);
    }
    if (get_current_floor_area() == AREA_LOBBY)
    {
      add_gray_text_entry((TWindowMenu *)list, (const char *)(TWindowSubStatusDisp::get_message_10(0x63)), 6, 7);
      return;
    }
    ((TWindowMenu *)list)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x63)), 6, 7);
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

void TWindowSubItem::exec_item_command(saddr item_id, s32 arg2) {
    saddr player;
    TItem *item;
    saddr t;

    player = (saddr)get_player_by_client_id(this->client_id);
    if ((player != 0) && (item = find_item_by_id(item_id), ((item == NULL) == 0))) {
        switch (arg2) {
        case 3:
            break;
        case 0:
            try_send_6x27_use_item(player, item_id);
            this->state = 0x16;
            break;
        case 1: {
            TItem *held = (TItem *)TObjPlayer::get_slot_value((void *)(player + 0xD04), item->get_attach_slot());
            if (held != NULL) {
                t = held->get_item_id();
                TObjPlayer::send_6x26_unequip_item((void *)player, t);
            }
            send_6x25_equip_item(player, item_id, 0);
            this->state = 0x16;
            break;
        }
        case 2:
            TObjPlayer::send_6x26_unequip_item((void *)player, item_id);
            this->state = 0x16;
            break;
        }
    }
}

void TWindowSubItem::close_windows(s32 arg1) {
    if (get_player_by_client_id(this->client_id) != NULL) {
        switch (arg1) {
        case 0:
            close_sub_window__10TObjPlayerFv();
            this->state = 0x16;
            return;
        case 1:
            if (this->confirm_menu != NULL) {
                ((TWindowBase *)this->confirm_menu)->close();
                this->confirm_menu = 0U;
            }
            if (this->purpose_menu != NULL) {
                ((TWindowBase *)this->purpose_menu)->close();
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
    s32 player;
    player = (saddr)get_player_by_client_id(this->client_id);
    if (player != 0) {
        TObjPlayer__sub_801B7B58(player, (int) (((TWindowMenuIconLine *)this->item_list)->get_cursor_value()), ((TWindowSubItem *)(this->item_list))->get_selected_entry());
    }
}

#pragma pop
s32 has_armor_with_unit_slot(TWindowSubItem *window_sub_item, TItem *item) {
    ItemData_80279754 d;
    saddr pl;
    uaddr armor;
    pl = (saddr)get_player_by_client_id(window_sub_item->client_id);
    if (pl == 0) {
        return 0;
    }
    if (item->get_item_type() != 1) {
        return 1;
    }
    if (item->get_item_group() != 3) {
        return 1;
    }
    armor = TObjPlayer::get_slot_value((void *)(pl + 0xD04), (int)2);
    if (armor == 0) {
        return 0;
    }
    ((TItem *)armor)->copy_to_item_data((TItemData *)&d);
    return d.b[5] != 0 ? 1 : 0;
}

extern "C" {
void TWindowSubItem::set_displayed_item(s32 id) {
    if ((this->help_window != NULL) && (id != (s32) this->displayed_item)) {
        this->displayed_item = id;
        this->help_window->set_displayed_item_by_id(id);
    }
}
}
