#pragma defer_codegen on
#define TOBJECT_OUT_OF_LINE_HELPERS
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#include "types.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/city/TShopDeleteItemWindow.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/city/TCheckRoomSequence.h"
#include "pso/unk/TLobby.h"
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
#include "pso/unk/text_80222C28.h"
#include "pso/object/base/TObjBase.h"

extern "C" {

void *get_window_layout_position(int);
s16 get_player_entity_id__15TShopWindowBaseFv(void *);
TWindowInputNumber *__ct__18TWindowInputNumberFPvllls(void *, void *, int, s32, int, int);
}

struct Base_80337910 { char pad[0x18]; };
struct Base_80337948_80337910 { char pad[0x18]; };
struct VBase_80337B00 { char pad[0x18]; };
struct Base_80337980_80337910 { char pad[0x18]; };
const char *TShopDeleteItemWindow__name = "TShopDeleteItemWindow";
TShopDeleteItemWindow::TShopDeleteItemWindow(TObject *parent, TShopWindowBase *owner, TObjPlayer *player) : TShopWindowBase(parent) {
    m_name = TShopDeleteItemWindow__name;
    state = 0;
    this->player = player;
    delete_count = 1;
    pad_54 = 0;
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

extern "C" {
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
        sub_80337E2C();
        return;
    case 1:
        TShopDeleteItemWindow::update_item_select(this);
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
}

#pragma push
#pragma opt_loop_invariants off

extern "C" {
void TShopDeleteItemWindow::sub_80337E2C() {
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
        item_list = create_item_list_window(get_shop_text(0x30), 200, ((TObjBase *)(player))->get_entity_id());
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
            help_window = new TWindowHelpItem(get_window_layout_position(0x27), ((TObjBase *)(player))->get_entity_id());
            if (help_window != NULL && TLobby::is_camera_ctrl_active() > 2) {
                help_window->set_scale(0.75f, 0.75f);
            }
            help_window->set_displayed_item_colored((uaddr)&displayed_item_colored);
            last_cursor = cursor;
        }
    } else if (TCheckRoomSequence::copy_item_record(cursor, &displayed_item_colored, base) != 0) {
        help_window->set_displayed_item_colored((uaddr)&displayed_item_colored);
        last_cursor = cursor;
    }
    set_state(1);
}
}

#pragma pop
#pragma push
#pragma opt_common_subs off
extern "C" {
void TShopDeleteItemWindow::update_item_select(void *arg0) {
    TItemData item;
    s32 count;
    s32 base;
    s32 cursor;
    TWindowInputNumber *p;
    s32 id;
    TShopDeleteItemWindow *self = (TShopDeleteItemWindow *)arg0;
    base = self->get_split_screen_slot();
    if (self->item_list != NULL) {
        cursor = self->item_list->get_cursor_value();
        if (self->help_window != NULL && cursor != self->last_cursor) {
            if (TCheckRoomSequence::copy_item_record(cursor, &self->displayed_item_colored, base) != 0) {
                self->help_window->set_displayed_item_colored((uaddr)&self->displayed_item_colored);
            }
            self->last_cursor = cursor;
        }
    }
    if (self->is_cancel_pressed() != 0) {
        self->set_state(7);
    } else if (self->is_decide_pressed() != 0) {
        if (copy_bank_item_with_stack_limit(self->item_list->get_cursor_value(), &item, &count, base) != 0) {
            if (item.data1.data_u8[0] == 3 && count > 1) {
                p = (TWindowInputNumber *)TObject::operator new(0x7C);
                if (p != NULL) {
                    id = get_player_entity_id__15TShopWindowBaseFv(self);
                    p = __ct__18TWindowInputNumberFPvllls(p, get_window_layout_position(0x2B), 1, count, 1, id);
                }
                self->number_input = p;
                if (self->number_input != NULL && TLobby::is_camera_ctrl_active() > 2) {
                    self->number_input->set_scale(0.75f, 0.75f);
                }
                self->set_state(2);
            } else {
                id = ((TObjBase *)(self->player))->get_entity_id();
                self->confirm_menu = create_yes_no_window((const NJS_POINT2 *)((get_window_layout_position(0x2B))), id, NULL, NULL);
                self->confirm_menu->set_ready_flag();
                ((TWindowSubComCardList *)self->confirm_menu)->set_selected_index(1);
                ((TWindowAddition *)self->confirm_menu)->set_position_xy(self->get_scale(), self->get_scale());
                self->set_state(3);
                self->display_shop_message(0x4D, 1);
            }
        }
    }
}
}

#pragma pop

extern "C" {
void TShopDeleteItemWindow::handle_number_input() {
    if (number_input != NULL && number_input->is_confirmed() != 0) {
        if (confirm_menu == NULL) {
            u32 id = ((TObjBase *)(player))->get_entity_id();
            confirm_menu = create_yes_no_window((const NJS_POINT2 *)((get_window_layout_position(0x2B))), id, NULL, NULL);
            confirm_menu->set_ready_flag();
            ((TWindowSubComCardList *)confirm_menu)->set_selected_index(1);
            ((TWindowAddition *)confirm_menu)->set_position_xy(get_scale(), get_scale());
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
}
