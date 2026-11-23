#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/item/TItemData.h"
#include "pso/ui/window/TWindowShop.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/city/TShopGetItemWindow.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowBase.h"
#include "types.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_80222C28.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/city/TShopSequence.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/ui/city/TCheckRoomSequence.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/city/TShopArmorListWindow.h"
#include "pso/ui/city/TShopEquipmentSellWindow.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowInputNumber.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjBase.h"

extern "C" {

saddr get_window_layout_position(s32);
TWindowInputNumber *__ct__18TWindowInputNumberFPvllls(void *, s32, s32, s32, s32, s16);
}

extern const char *TShopGetItemWindow__class_name;

const char *TShopGetItemWindow__class_name = "TShopGetItemWindow";
TShopGetItemWindow::TShopGetItemWindow(TObject *parent, TShopWindowBase *owner, TObjPlayer *player) : TShopWindowBase(parent) {
    m_name = TShopGetItemWindow__class_name;
    state = 0;
    this->player = player;
    withdraw_count = 1;
    pad_4C = 0;
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

TShopGetItemWindow::~TShopGetItemWindow() {
    if (item_list != NULL) { item_list->close(); item_list = 0; }
    if (confirm_menu != NULL) { confirm_menu->close(); confirm_menu = 0; }
    if (number_input != NULL) { number_input->close(); number_input = 0; }
    if (help_window != NULL) { help_window->close(); help_window = 0; }
}

void TShopGetItemWindow::update_state() {
    void (*empty_callback)(TShopWindowBase *);
    void (*callback)(TShopWindowBase *);
    switch (state) {
    case 0:
        rebuild_item_list();
        return;
    case 1:
        handle_withdraw_list_input();
        return;
    case 2:
        update_input_number();
        return;
    case 3:
        handle_withdraw_confirm();
        return;
    case 4:
        close();
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

void TShopGetItemWindow::rebuild_item_list() {
    s32 x;
    s32 sel;
    s32 i;
    withdraw_count = 1;
    room_table_entry = TCheckRoomSequence::get_room_table_entry(x = get_split_screen_slot());
    if (room_table_entry == 0) {
        display_shop_message(0x3E, 1);
        set_state(6);
        if (item_list != NULL) {
            item_list->reset_list();
        }
    } else {
    if (item_list == NULL) {
        TItemData item;
        s32 count;
        item_list = create_item_list_window(get_shop_text(0x30), 0xC8, player->get_entity_id());
        item_list->set_capacity(0xC8);
        for (i = 0; i < 0xC8; i++) {
            if (copy_bank_item_with_stack_limit(i, &item, &count, x) != 0) {
                if (count > 1) {
                    item_list->add_item_info_entry(&item, i, count);
                } else {
                    item_list->add_item_info_entry(&item, i, 0);
                }
            }
        }
        item_list->calc_content_extent();
        sel = item_list->get_cursor_index();
    } else {
        TItemData item;
        s32 count;
        s32 j;
        item_list->save_cursor_selection();
        item_list->reset_list();
        for (j = 0; j < 0xC8; j++) {
            if (copy_bank_item_with_stack_limit(j, &item, &count, x) != 0) {
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
        sel = item_list->get_cursor_index();
    }
    if (help_window == NULL) {
        if (TCheckRoomSequence::copy_item_record(sel, &displayed_item_colored, x) != 0) {
            help_window = new TWindowHelpItem((void *)get_window_layout_position(0x27), player->get_entity_id());
            if (help_window != NULL && TLobby::is_camera_ctrl_active() > 2) {
                help_window->set_scale(0.75f, 0.75f);
            }
            help_window->set_displayed_item_colored((uaddr)&displayed_item_colored);
            last_cursor = sel;
        }
    } else if (TCheckRoomSequence::copy_item_record(sel, &displayed_item_colored, x) != 0) {
        help_window->set_displayed_item_colored((uaddr)&displayed_item_colored);
        last_cursor = sel;
    }
    set_state(1);
    }
}

void TShopGetItemWindow::handle_withdraw_list_input() {
    s32 sel;
    s32 x;
    s32 count;
    TItemData item;
    f32 scale;
    x = get_split_screen_slot();
    if (item_list != NULL) {
        sel = item_list->get_cursor_value();
        if (help_window != NULL && sel != last_cursor) {
            if (TCheckRoomSequence::copy_item_record(sel, &displayed_item_colored, x) != 0) {
                help_window->set_displayed_item_colored((uaddr)&displayed_item_colored);
            }
            last_cursor = sel;
        }
    }
    if (is_cancel_pressed() != 0) {
        set_state(7);
        return;
    }
    if (is_decide_pressed() != 0) {
        if (copy_bank_item_with_stack_limit(item_list->get_cursor_value(), &item, &count, x) != 0) {
            if (item.data1.data_u8[0] == 3 && count > 1) {
                TWindowInputNumber *obj = (TWindowInputNumber *)TObject::operator new(0x7C);
                if (obj != NULL) {
                    sel = (s16)get_player_entity_id();
                    obj = __ct__18TWindowInputNumberFPvllls(obj, get_window_layout_position(0x2B), 1, count, 1, sel);
                }
                number_input = obj;
                if (number_input != NULL && TLobby::is_camera_ctrl_active() > 2) {
                    number_input->set_scale(0.75f, 0.75f);
                }
                set_state(2);
                return;
            }
            sel = player->get_entity_id();
            confirm_menu = create_yes_no_window((const NJS_POINT2 *)get_window_layout_position(0x2B), sel, NULL, NULL);
            confirm_menu->set_ready_flag();
            scale = get_scale();
            ((TWindowAddition *)confirm_menu)->set_position_xy(get_scale(), scale);
            set_state(3);
        }
    }
}

void TShopGetItemWindow::update_input_number() {
    TWindowInputNumber *w;
    w = number_input;
    if (w != NULL && w->is_confirmed() != 0) {
        if (confirm_menu == NULL) {
            confirm_menu = create_yes_no_window((const NJS_POINT2 *)get_window_layout_position(0x2B), player->get_entity_id(), NULL, NULL);
            confirm_menu->set_ready_flag();
            ((TWindowAddition *)confirm_menu)->set_position_xy(get_scale(), get_scale());
        }
        withdraw_count = number_input->get_value();
        number_input->close();
        number_input = NULL;
        set_state(3);
        return;
    }
    w = number_input;
    if (w != NULL && ((TWindowInputNumber *)w)->is_cancelled() != 0) {
        number_input->close();
        number_input = NULL;
        set_state(4);
    }
}

void TShopGetItemWindow::handle_withdraw_confirm() {
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
            if (TCheckRoomSequence::copy_item_record(idx, &record, (int)(slot & 0xFFFFFFFFFFFFFFFFu)) != 0) {
                record.id = -1;
                if (TCheckRoomSequence::get_item_def((uaddr)&record) != 0) {
                    record.set_stack_count(withdraw_count);
                }
                if (player->can_inventory_accept_item((u8 *)&record) == 0) {
                    display_shop_message(0x4B, 1);
                    set_state(6);
                } else {
                    player->request_inventory_item(&record);
                    TCheckRoomSequence::remove_bank_item_amount(idx, withdraw_count, slot);
                    TCheckRoomSequence::compact_items(slot);
                    copy_bank_to_card_window(slot);
                    set_state(0);
                }
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

void TShopGetItemWindow::close() {
    if (item_list != NULL) {
        item_list->clear_decided();
    }
    set_state(1);
}

void TShopGetItemWindow::display_shop_message(s32 id, s32 flags) {
    if (this->sequence != NULL) {
        this->sequence->display_shop_message(id, flags);
    }
}

void TShopGetItemWindow::display_message(const char *text, s32 flags) {
    if (this->sequence != NULL) {
        this->sequence->display_message(text, flags);
    }
}
