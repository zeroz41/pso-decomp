#pragma defer_codegen on

#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/item/TItemData.h"
#include "pso/ui/window/TWindowQuantity.h"
#include "pso/ui/city/TShopEquipmentSellWindow.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowBase.h"
#include "types.h"
#include "pso/ui/window/TWindowCost.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_80222C28.h"
#include "pso/ui/city/TShopArmorListWindow.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/city/TShopSequence.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/item/TItem.h"
#include "pso/ui/city/TCheckRoomSequence.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowInputNumber.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/ui/window/TWindowShop.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/task/TObject.h"
#include <string.h>
#include "pso/player/TPlyItem.h"
#include "pso/item/TItemList.h"
#include "pso/object/base/TObjBase.h"

#pragma readonly_strings on

#pragma inline_depth(1)

#pragma auto_inline off

#pragma dont_inline off

extern "C" {
const char *TShopEquipmentSellWindow__class_name = "TShopEquipmentSellWindow";
}

TShopEquipmentSellWindow::TShopEquipmentSellWindow(TObject *parent, TShopWindowBase *sequence, TObjPlayer *player, s32 title_text) : TShopWindowBase(parent) {
    this->m_name = TShopEquipmentSellWindow__class_name;
    this->pad_370 = 0;
    this->entry_count = 0;
    this->title_text = title_text;
    this->state = 0;
    this->sell_count = 1;
    this->cursor = 0;
    this->last_cursor = 0;
    this->sequence = sequence;
    this->item_list = NULL;
    this->confirm_menu = NULL;
    this->number_input = NULL;
    this->help_window = NULL;
    this->owned_window = NULL;
    this->cost_window = NULL;
    this->player = player;
    this->on_close = NULL;
    this->on_empty = NULL;
    memset(this->entries, 0, sizeof(this->entries));
}

extern "C" {
TShopEquipmentSellWindow::~TShopEquipmentSellWindow() {
    if (item_list != NULL) { item_list->close(); item_list = NULL; }
    if (confirm_menu != NULL) { confirm_menu->close(); confirm_menu = NULL; }
    if (number_input != NULL) { number_input->close(); number_input = NULL; }
    if (help_window != NULL) { help_window->close(); help_window = NULL; }
    if (owned_window != NULL) { owned_window->close(); owned_window = NULL; }
    if (cost_window != NULL) { cost_window->close(); cost_window = NULL; }
}

void TShopEquipmentSellWindow::update_state() {
    void (*callback)(TShopWindowBase *);
    switch (this->state) {
    case 0:
        build_sell_list();
        return;
    case 1:
        handle_selection();
        return;
    case 2:
        handle_sell_confirm();
        return;
    case 3:
        handle_input_window_result();
        return;
    case 5:
        close();
        return;
    case 4:
        update();
        return;
    case 8:
        callback = this->on_close;
        if (callback != NULL) {
            callback(this->sequence);
        }
        queue_destruction();
        return;
    case 7:
        callback = this->on_empty;
        if (callback != NULL) {
            callback(this->sequence);
        }
        queue_destruction();
    default:
        return;
    }
}

void TShopEquipmentSellWindow::build_sell_list() {
    TItem *items[32];
    s32 n;
    s32 i;
    s32 v;
    void *r;
    n = this->player->inventory_objects->count_matching_items(items);
    this->entry_count = 0;
    for (i = 0; i < n; i++) {
        if (items[i] != NULL) {
            v = TShopEquipmentSellWindow::get_item_data_value(reinterpret_cast<uaddr>(items[i]));
            if (v > 0 && items[i]->copy_to_item_data(&this->entries[this->entry_count].data) != 0) {
                this->entries[this->entry_count].item = (TItem *)reinterpret_cast<uaddr>(items[i]);
                this->entries[this->entry_count].data.data2.price = v / 8;
                this->entries[this->entry_count].index = i;
                this->entry_count++;
            }
        }
    }
    if (this->entry_count == 0) {
        set_state(7);
        if (this->item_list != NULL) {
            this->item_list->reset_list();
        }
        return;
    }
    display_shop_message(0xC, 1);
    set_state(1);
    if (this->item_list == NULL) {
        this->item_list = create_item_list_window(get_shop_text(this->title_text), this->entry_count, this->player->get_entity_id());
        for (i = 0; i < this->entry_count; i++) {
            this->item_list->add_item(this->entries[i].item, this->entries[i].data.data2.price, i);
        }
        this->item_list->calc_content_extent();
    } else {
        this->item_list->reset_list();
        for (i = 0; i < this->entry_count; i++) {
            this->item_list->add_item(this->entries[i].item, this->entries[i].data.data2.price, i);
        }
        if (this->cursor > this->entry_count - 1) {
            this->cursor = this->entry_count - 1;
        }
        this->item_list->calc_content_extent();
        this->item_list->set_cursor_index(this->cursor);
        this->item_list->clear_decided();
    }
    if (this->help_window == NULL) {
        this->help_window = new TWindowHelpItem((void *)get_window_layout_position(0x27), this->player->get_entity_id());
        if (this->help_window != NULL && TLobby::is_camera_ctrl_active() > 2) {
            this->help_window->set_scale(0.75f, 0.75f);
        }
        this->help_window->set_displayed_item_by_id(this->entries[0].data.id);
    } else if (this->item_list != NULL) {
        v = this->item_list->get_cursor_value();
        this->help_window->set_displayed_item_by_id(this->entries[v].data.id);
    }
    if (this->owned_window == NULL) {
        this->owned_window = create_window_quantity((u16)get_player_entity_id());
        r = this->player->inventory_objects->set_mode_and_refresh_object(&this->entries[0].data);
        if (r != NULL) {
            this->owned_window->set_entry_count((TItem *)((TItemList *)r)->get_owner_if_alive());
        } else {
            this->owned_window->set_entry_count(NULL);
        }
    } else if (this->item_list != NULL) {
        v = this->item_list->get_cursor_value();
        r = this->player->inventory_objects->set_mode_and_refresh_object(&this->entries[v].data);
        if (r != NULL) {
            this->owned_window->set_entry_count((TItem *)((TItemList *)r)->get_owner_if_alive());
        } else {
            this->owned_window->set_entry_count(NULL);
        }
    }
    if (this->cost_window == NULL) {
        this->cost_window = create_cost_window(this->player->get_entity_id());
        if (this->cost_window != NULL && this->entries[0].data.data2.price > 0) {
            this->cost_window->set_cost(this->entries[0].data.data2.price);
        }
    } else if (this->entries[this->cursor].data.data2.price > 0) {
        this->cost_window->set_cost(this->entries[this->cursor].data.data2.price);
    }
}

void TShopEquipmentSellWindow::handle_selection() {
    s32 i;
    void *n;
    s32 type;
    if (this->item_list != NULL) {
        i = this->item_list->get_cursor_value();
        if (this->help_window != NULL && i != this->last_cursor) {
            this->help_window->set_displayed_item_by_id(this->entries[i].data.id);
        }
        if (this->owned_window != NULL && i != this->last_cursor) {
            n = this->player->inventory_objects->set_mode_and_refresh_object(&this->entries[i].data);
            if (n != 0) {
                this->owned_window->set_entry_count((TItem *)((TItemList *)n)->get_owner_if_alive());
            } else {
                this->owned_window->set_entry_count(NULL);
            }
        }
        if (this->cost_window != NULL && i != this->last_cursor && this->entries[i].data.data2.price > 0) {
            this->cost_window->set_cost(this->entries[i].data.data2.price);
        }
        this->last_cursor = i;
    }
    if (is_cancel_pressed() != 0) {
        set_state(8);
        play_sound_effect(0x52D01, 0, 0, 0);
        return;
    }
    if (is_decide_pressed() != 0) {
        this->sell_count = 1;
        i = this->item_list->get_cursor_value();
        if (this->entries[i].data.data1.data_u8[0] == 3) {
            type = this->entries[i].data.get_stack_count();
            if (type > 1 && this->number_input == NULL) {
                this->number_input = new TWindowInputNumber((void *)get_window_layout_position(0x2B), 1, type, 1, get_player_entity_id());
                if (this->number_input != NULL && TLobby::is_camera_ctrl_active() > 2) {
                    this->number_input->set_scale(0.75f, 0.75f);
                }
                set_state(3);
                return;
            }
        }
        if (this->confirm_menu == NULL) {
            this->confirm_menu = create_window_menu((saddr)get_window_layout_position(0x2B), 2, this->player->get_entity_id());
            this->confirm_menu->add_text_entry(get_shop_text(6), 6, 0);
            this->confirm_menu->add_text_entry(get_shop_text(7), 6, 1);
            this->confirm_menu->calc_window_size();
            align_menu_entry_positions(this->confirm_menu);
            this->confirm_menu->set_ready_flag();
            this->confirm_menu->set_position_xy(get_scale(), get_scale());
            set_state(2);
        }
    }
}

void TShopEquipmentSellWindow::close() {
    if (this->item_list != NULL) {
        this->item_list->clear_decided();
    }
    set_state(1);
}

void TShopEquipmentSellWindow::handle_input_window_result() {

    if (this->number_input != NULL && this->number_input->is_confirmed() != 0) {
        if (confirm_menu == NULL) {
            this->confirm_menu = create_window_menu((saddr)get_window_layout_position(0x2B), 2, this->player->get_entity_id());
            this->confirm_menu->add_text_entry(get_shop_text(6), 6, 0);
            this->confirm_menu->add_text_entry(get_shop_text(7), 6, 1);
            this->confirm_menu->calc_window_size();
            align_menu_entry_positions(this->confirm_menu);
            this->confirm_menu->set_ready_flag();
            this->confirm_menu->set_position_xy(get_scale(), get_scale());
        }
        this->sell_count = this->number_input->get_value();
        this->number_input->close();
        this->number_input = NULL;
        set_state(2);
        return;
    }
    if (this->number_input != NULL && this->number_input->is_cancelled() != 0) {
        this->number_input->close();
        this->number_input = NULL;
        set_state(5);
    }
}

void TShopEquipmentSellWindow::handle_sell_confirm() {
    s32 r;
    if (this->confirm_menu != NULL && this->confirm_menu->is_decided() != 0) {
        r = this->confirm_menu->get_selected_value();
        if (r == 0) {
            s32 i = this->item_list->get_cursor_value();
            if (this->player->try_add_sale_meseta(this->entries[i].item->get_item_id(), this->entries[i].data.data2.price * this->sell_count, this->sell_count) != 0) {
                this->confirm_menu->close();
                this->confirm_menu = NULL;
                this->cursor = i;
                set_state(0);
                return;
            }
            display_shop_message(0x1C, 1);
            this->confirm_menu->close();
            this->confirm_menu = NULL;
            set_state(4);
            return;
        }
        if (r == 1) {
            this->confirm_menu->close();
            this->confirm_menu = NULL;
            set_state(5);
            return;
        }
    }
    if (this->confirm_menu != NULL && this->confirm_menu->is_cancelled() != 0) {
        this->confirm_menu->close();
        this->confirm_menu = NULL;
        set_state(5);
    }
}

void TShopEquipmentSellWindow::update() {
    if (is_message_ready() != 0 && (is_decide_pressed() != 0 || is_cancel_pressed() != 0)) {
        display_shop_message(0xc, 1);
        set_state(5);
    }
}

void TShopEquipmentSellWindow::display_shop_message(s32 id, s32 flags) {
    TShopWindowBase *sequence = this->sequence;
    if (sequence != NULL) {
        sequence->display_shop_message(id, flags);
    }
}

void TShopEquipmentSellWindow::display_message(const char *text, s32 flags) {
    TShopWindowBase *sequence = this->sequence;
    if (sequence != NULL) {
        sequence->display_message(text, flags);
    }
}
}
