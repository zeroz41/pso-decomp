#pragma defer_codegen on
#define TOBJECT_OUT_OF_LINE_HELPERS
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/city/TShopDeleteItemWindow.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/city/TCheckRoomSequence.h"
#include "pso/network/TLobby.h"
#include "pso/ui/city/TShopEquipmentSellWindow.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/ui/window/TWindowInputNumber.h"
#include "pso/ui/city/TShopArmorListWindow.h"
#include "pso/ui/city/TShopGetItemWindow.h"
#include "pso/ui/window/TWindowShop.h"
#include "pso/ui/window/TWindowSetLevelUp.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/CounterTextLookup.h"
#include "pso/object/base/TObjBase.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/system/GameModeQueries.h"

const char *shop_delete_item_window_name = "TShopDeleteItemWindow";
TShopDeleteItemWindow::TShopDeleteItemWindow(TObject *parent, TShopWindowBase *owner, TObjPlayer *player) : TShopWindowBase(parent) {
    m_name = shop_delete_item_window_name;
    state = 0;
    this->player = player;
    delete_count = 1;
    unused_54 = 0;
    last_cursor = 0;
    on_close = 0;
    on_empty = 0;
    item_list = 0;
    confirm_menu = 0;
    number_input = 0;
    help_window = 0;
    sequence = owner;
    ((TItemData *)(&displayed_item_colored))->init();
}

TShopDeleteItemWindow::~TShopDeleteItemWindow() {
    if (item_list != NULL) { item_list->close(); item_list = 0; }
    if (confirm_menu != NULL) { confirm_menu->close(); confirm_menu = 0; }
    if (number_input != NULL) { number_input->close(); number_input = 0; }
    if (help_window != NULL) { help_window->close(); help_window = 0; }
}

void TShopDeleteItemWindow::update_state() {
    void (*callback)(TShopWindowBase *);
    void (*empty_callback)(TShopWindowBase *);
    switch (state) {
    case 0:
        open_item_list();
        return;
    case 1:
        update_item_select();
        return;
    case 2:
        handle_number_input();
        return;
    case 3:
        handle_confirm_dialog();
        return;
    case 4:
        destroy();
        return;
    case 6:
        empty_callback = on_empty;
        if (empty_callback != NULL) {
            empty_callback(sequence);
        }
        queue_destruction();
        return;
    case 7:
        callback = on_close;
        if (callback != NULL) {
            callback(sequence);
        }
        queue_destruction();
    default:
        return;
    }
}

#pragma push
#pragma opt_loop_invariants off

void TShopDeleteItemWindow::open_item_list() {
    s32 base;
    s32 cursor;
    s32 i;
    delete_count = 1;
    base = get_split_screen_slot();
    room_table_entry = TCheckRoomSequence::get_room_table_entry(base);
    if (room_table_entry == 0) {
        display_shop_message(0x3E, 1);
        set_state(6);
        if (item_list != NULL) {
            item_list->reset_list();
        }
        return;
    }
    display_shop_message(0x4C, 1);
    if (item_list == NULL) {
        TItemData item;
        s32 count;
        item_list = create_item_list_window(get_shop_text(0x30), 200, player->get_entity_id());
        item_list->set_capacity(200);
        for (i = 0; i < 200; i++) {
            if (copy_bank_item_with_stack_limit(i, &item, &count, base) != 0) {
                if (count > 1) {
                    item_list->add_item_info_entry(&item, i, count);
                } else {
                    item_list->add_item_info_entry(&item, i, 0);
                }
            }
        }
        item_list->calc_content_extent();
        cursor = item_list->get_cursor_index();
    } else {
        TItemData item;
        s32 count;
        s32 j;
        item_list->save_cursor_selection();
        item_list->reset_list();
        for (j = 0; j < 200; j++) {
            if (copy_bank_item_with_stack_limit(j, &item, &count, base) != 0) {
                if (count > 1) {
                    item_list->add_item_info_entry(&item, j, count);
                } else {
                    item_list->add_item_info_entry(&item, j, 0);
                }
            }
        }
        item_list->clamp_selection_to_valid_entry();
        item_list->calc_content_extent();
        item_list->clear_decided();
        cursor = item_list->get_cursor_index();
    }
    if (help_window == NULL) {
        if (TCheckRoomSequence::copy_item_record(cursor, &displayed_item_colored, base) != 0) {
            help_window = new TWindowHelpItem(get_window_layout_position(0x27), player->get_entity_id());
            if (help_window != NULL && is_camera_ctrl_active() > 2) {
                help_window->set_scale(0.75f, 0.75f);
            }
            help_window->set_displayed_item_colored(&displayed_item_colored);
            last_cursor = cursor;
        }
    } else if (TCheckRoomSequence::copy_item_record(cursor, &displayed_item_colored, base) != 0) {
        help_window->set_displayed_item_colored(&displayed_item_colored);
        last_cursor = cursor;
    }
    set_state(1);
}

#pragma pop
#pragma push
#pragma opt_common_subs off
void TShopDeleteItemWindow::update_item_select() {
    TItemData item;
    s32 count;
    s32 base;
    s32 cursor;
    base = get_split_screen_slot();
    if (item_list != NULL) {
        cursor = item_list->get_cursor_value();
        if (help_window != NULL && cursor != last_cursor) {
            if (TCheckRoomSequence::copy_item_record(cursor, &displayed_item_colored, base) != 0) {
                help_window->set_displayed_item_colored(&displayed_item_colored);
            }
            last_cursor = cursor;
        }
    }
    if (is_cancel_pressed() != 0) {
        set_state(7);
    } else if (is_decide_pressed() != 0) {
        if (copy_bank_item_with_stack_limit(item_list->get_cursor_value(), &item, &count, base) != 0) {
            if (item.data1.data_u8[0] == 3 && count > 1) {
                number_input = new TWindowInputNumber(get_window_layout_position(0x2B), 1, count, 1, get_player_entity_id());
                if (number_input != NULL && is_camera_ctrl_active() > 2) {
                    number_input->set_scale(0.75f, 0.75f);
                }
                set_state(2);
            } else {
                confirm_menu = create_yes_no_window(get_window_layout_position(0x2B), player->get_entity_id(), NULL, NULL);
                confirm_menu->set_ready_flag();
                confirm_menu->set_selected_index(1);
                confirm_menu->set_position_xy(get_scale(), get_scale());
                set_state(3);
                display_shop_message(0x4D, 1);
            }
        }
    }
}

#pragma pop

void TShopDeleteItemWindow::handle_number_input() {
    if (number_input != NULL && number_input->is_confirmed() != 0) {
        if (confirm_menu == NULL) {
            u32 id = player->get_entity_id();
            confirm_menu = create_yes_no_window(get_window_layout_position(0x2B), id, NULL, NULL);
            confirm_menu->set_ready_flag();
            confirm_menu->set_selected_index(1);
            confirm_menu->set_position_xy(get_scale(), get_scale());
        }
        delete_count = number_input->get_value();
        number_input->close();
        number_input = NULL;
        set_state(3);
        display_shop_message(0x4D, 1);
        return;
    }
    if (number_input != NULL && number_input->is_cancelled() != 0) {
        number_input->close();
        number_input = NULL;
        set_state(4);
    }
}

void TShopDeleteItemWindow::handle_confirm_dialog() {
    TItemData record;
    s32 slot;
    s32 sel;
    s32 idx;
    TWindowMenu *menu;
    TWindowMenu *menu2;
    menu = confirm_menu;
    if (menu != NULL && menu->is_decided() != 0) {
        slot = get_split_screen_slot();
        sel = confirm_menu->get_selected_value();
        if (sel == 0) {
            idx = item_list->get_cursor_value();
            if (TCheckRoomSequence::copy_item_record(idx, &record, slot) != 0) {
                TCheckRoomSequence::remove_bank_item_amount(idx, delete_count, slot);
                TCheckRoomSequence::compact_items(slot);
                copy_bank_to_card_window(slot);
                set_state(0);
            }
            confirm_menu->close();
            confirm_menu = NULL;
            return;
        }
        if (sel == 1) {
            confirm_menu->close();
            confirm_menu = NULL;
            set_state(4);
            return;
        }
    }
    menu2 = confirm_menu;
    if (menu2 != NULL && menu2->is_cancelled() != 0) {
        confirm_menu->close();
        confirm_menu = NULL;
        set_state(4);
    }
}

void TShopDeleteItemWindow::destroy() {
    if (item_list != NULL) {
        item_list->clear_decided();
    }
    set_state(1);
    display_shop_message(0x4C, 1);
}

void TShopDeleteItemWindow::display_shop_message(s32 id, s32 flags) {
    TShopWindowBase *owner = sequence;
    if (owner != NULL) {
        owner->display_shop_message(id, flags);
    }
}

void TShopDeleteItemWindow::display_message(const char *text, s32 flags) {
    TShopWindowBase *owner = sequence;
    if (owner != NULL) {
        owner->display_message(text, flags);
    }
}
