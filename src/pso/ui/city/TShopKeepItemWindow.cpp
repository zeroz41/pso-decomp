#define TOBJECT_OUT_OF_LINE_HELPERS
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

#include "pso/player/TPlyItem.h"
#include "pso/ui/window/TWindowShop.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "types.h"
#include <string.h>
#include "pso/ui/city/TShopKeepItemWindow.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_80222C28.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemData.h"
#include "pso/ui/city/TShopSequence.h"
#include "pso/ui/city/TShopArmorListWindow.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TWindowMenu.h"

#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/city/TCheckRoomSequence.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/city/TShopEquipmentSellWindow.h"
#include "pso/ui/city/TShopGetItemWindow.h"
#include "pso/ui/city/TShopJudgmentItemWindow.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TMessageWindowController.h"
#include "pso/ui/window/TWindowInputNumber.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/system/SoundEffect.h"
#include "pso/ui/window/WindowLayout.h"

extern "C" {
}

const char *TShopKeepItemWindow__class_name = "TShopKeepItemWindow";

TShopKeepItemWindow::TShopKeepItemWindow(TObject *parent, TShopWindowBase *sequence, TObjPlayer *player) : TShopWindowBase(parent) {
    m_name = TShopKeepItemWindow__class_name;
    this->pad_370 = 0;
    this->entry_count = 0;
    this->deposit_count = 1;
    this->help_item_index = 0;
    this->state = 0;
    this->sequence = sequence;
    this->item_list_window = 0;
    this->confirm_window = 0;
    this->help_window = 0;
    this->number_window = 0;
    this->player = player;
    this->ok_callback = NULL;
    this->cancel_callback = NULL;
    memset(this->entries, 0, sizeof(this->entries));
}

TShopKeepItemWindow::~TShopKeepItemWindow() {
    if (this->item_list_window != 0) { ((TWindowBase *)this->item_list_window)->close(); this->item_list_window = 0; }
    if (this->confirm_window != 0) { ((TWindowBase *)this->confirm_window)->close(); this->confirm_window = 0; }
    if (this->number_window != 0) { ((TWindowBase *)this->number_window)->close(); this->number_window = 0; }
    if (this->help_window != 0) { ((TWindowBase *)this->help_window)->close(); this->help_window = 0; }
}

void TShopKeepItemWindow::update_state() {
    switch (this->state) {
    case 0:
        rebuild_item_list();
        return;
    case 1:
        handle_deposit_list_select();
        return;
    case 2:
        handle_deposit_confirm();
        return;
    case 3:
        close();
        return;
    case 4:
        update_number_input();
        return;
    case 5:
        close_with_ok_callback();
        return;
    case 7:
        close_with_cancel_callback();
    default:
        return;
    }
}

void TShopKeepItemWindow::rebuild_item_list() {
    TItem *buf[30];
    s32 count;
    s32 i;
    s32 cur;
    this->deposit_count = 1;
    count = player->inventory_objects->count_matching_items(buf);
    this->entry_count = 0;
    for (i = 0; i < count; i++) {
        if (buf[i] != NULL && buf[i]->copy_to_item_data(&this->entries[this->entry_count].data) != 0) {
            this->entries[this->entry_count].item = buf[i];
            this->entries[this->entry_count].inventory_index = i;
            this->entry_count++;
        }
    }
    if (this->entry_count != 0) {
        set_state(1);
    } else {
        display_shop_message(0x49, 1);
        set_state(7);
        return;
    }
    if (this->item_list_window == NULL) {
        this->item_list_window = create_item_list_window(get_shop_text(0x30), 0x40, this->player->get_entity_id());
        for (s32 j = 0; j < this->entry_count; j++) {
            this->item_list_window->add_list_entry(this->entries[j].item, j);
        }
        this->item_list_window->calc_content_extent();
        cur = this->item_list_window->get_cursor_index();
    } else {
        ((TWindowMenuIconLine *)(this->item_list_window))->save_cursor_selection();
        this->item_list_window->reset_list();
        for (s32 j = 0; j < this->entry_count; j++) {
            this->item_list_window->add_list_entry(this->entries[j].item, j);
        }
        ((TWindowMenuIconLine *)(this->item_list_window))->clamp_selection_to_valid_entry();
        this->item_list_window->calc_content_extent();
        this->item_list_window->clear_decided();
        cur = this->item_list_window->get_cursor_index();
    }
    if (this->help_window == NULL) {
        this->help_window = new TWindowHelpItem((void *)get_window_layout_position(0x27), this->player->get_entity_id());
        if (this->help_window != NULL && TLobby::is_camera_ctrl_active() > 2) {
            this->help_window->set_scale(0.75f, 0.75f);
        }
        this->help_window->set_displayed_item_by_id(this->entries[cur].item->get_item_id());
        this->help_item_index = cur;
    } else {
        this->help_window->set_displayed_item_by_id(this->entries[cur].item->get_item_id());
        this->help_item_index = cur;
    }
}

void TShopKeepItemWindow::handle_deposit_list_select() {
    s32 bank = get_split_screen_slot();
    s32 cur;
    s32 count;
    s32 stack;
    TItemData *data;
    if (this->item_list_window != NULL) {
        cur = this->item_list_window->get_cursor_value();
        if (this->help_window != NULL && cur != this->help_item_index) {
            this->help_window->set_displayed_item_by_id(this->entries[cur].item->get_item_id());
            this->help_item_index = cur;
        }
    }
    if (is_cancel_pressed() != 0) {
        set_state(5);
        play_sound_effect(0x52D01, 0, 0, 0);
        return;
    }
    if (is_decide_pressed() == 0) {
        return;
    }
    cur = this->item_list_window->get_cursor_value();
    switch (this->entries[cur].data.data1.data_u8[0]) {
    case 3:
        data = &this->entries[cur].data;
        if (TItemData::lookup_item_def(data) != 0) {
            count = get_bank_deposit_capacity_for_item(data, bank);
            stack = data->get_stack_count();
            count = count < stack ? count : stack;
        } else if (bank_has_free_row(bank) != 0) {
            count = 1;
        } else {
            count = 0;
        }
        if (count == 0) {
            display_shop_message(0x3C, 1);
            set_state(7);
            return;
        }
        break;
    case 0:
    case 1:
    case 2:
    default:
        if (bank_has_free_row(bank) == 0) {
            display_shop_message(0x3C, 1);
            set_state(7);
            return;
        }
        count = 1;
        break;
    }
    if (count > 1 && this->number_window == NULL) {
        this->number_window = new TWindowInputNumber((void *)get_window_layout_position(0x2B), 1, count, 1, get_player_entity_id());
        if (this->number_window != NULL && TLobby::is_camera_ctrl_active() > 2) {
            this->number_window->set_scale(0.75f, 0.75f);
        }
        set_state(4);
        return;
    }
    if (this->confirm_window == NULL) {
        this->confirm_window = create_yes_no_window((const NJS_POINT2 *)get_window_layout_position(0x2B), (this->player->get_entity_id()), NULL, NULL);
        ((TWindowMenu *)this->confirm_window)->set_ready_flag();
        f32 scale = get_scale();
        ((TWindowAddition *)this->confirm_window)->set_position_xy(get_scale(), scale);
        set_state(2);
    }
}

void TShopKeepItemWindow::update_number_input() {
    f32 scale;
    s32 entity_id;
    TWindowInputNumber *w;
    w = this->number_window;
    if ((w != NULL) && (w->is_confirmed() != 0)) {
        if (this->confirm_window == NULL) {
            entity_id = this->player->get_entity_id();
            this->confirm_window = create_yes_no_window((const NJS_POINT2 *)get_window_layout_position(0x2B), entity_id, NULL, NULL);
            ((TWindowMenu *)(this->confirm_window))->set_ready_flag();
            scale = get_scale();
            ((TWindowAddition *)(this->confirm_window))->set_position_xy(get_scale(), scale);
        }
        this->deposit_count = ((TWindowInputNumber *)(this->number_window))->get_value();
        ((TWindowBase *)this->number_window)->close();
        this->number_window = NULL;
        set_state(2);
        return;
    }
    w = this->number_window;
    if ((w != NULL) && (((TWindowInputNumber *)w)->is_cancelled() != 0)) {
        ((TWindowBase *)this->number_window)->close();
        this->number_window = NULL;
        set_state(3);
    }
}

void TShopKeepItemWindow::handle_deposit_confirm() {
    s32 base;
    s32 r;
    s32 i;
    TWindowMenu *win;
    win = this->confirm_window;
    if (win != NULL && win->is_decided() != 0) {
        base = get_split_screen_slot();
        r = this->confirm_window->get_selected_value();
        if (r == 0) {
            i = this->item_list_window->get_cursor_value();
            if (store_item_in_bank(&this->entries[i].data, this->deposit_count, base) != 0) {
                delete_item(this->player, this->entries[i].item->get_item_id(), this->deposit_count);
                copy_bank_to_card_window(base);
                play_sound_effect(0x52D01, 0, 0, 0);
                ((TWindowBase *)this->confirm_window)->close();
                this->confirm_window = 0;
                set_state(0);
                return;
            }
            display_shop_message(0x3C, 1);
            play_sound_effect(0x53F06, 0, 0, 0);
            ((TWindowBase *)this->confirm_window)->close();
            this->confirm_window = 0;
            set_state(7);
            return;
        }
        if (r == 1) {
            ((TWindowBase *)this->confirm_window)->close();
            this->confirm_window = 0;
            set_state(3);
            return;
        }
    }
    win = this->confirm_window;
    if (win != NULL && win->is_cancelled() != 0) {
        ((TWindowBase *)this->confirm_window)->close();
        this->confirm_window = 0;
        set_state(3);
    }
}

void TShopKeepItemWindow::close() {
    if (this->item_list_window != NULL) {
        this->item_list_window->clear_decided();
    }
    set_state(1);
}

void TShopKeepItemWindow::close_with_ok_callback() {
    void (*callback)(TShopWindowBase *);

    callback = this->ok_callback;
    if (callback != NULL) {
        callback(this->sequence);
    }
    sort_bank_items(get_split_screen_slot());
    queue_destruction();
}

void TShopKeepItemWindow::close_with_cancel_callback() {
    void (*callback)(TShopWindowBase *);

    callback = this->cancel_callback;
    if (callback != NULL) {
        callback(this->sequence);
    }
    sort_bank_items(get_split_screen_slot());
    queue_destruction();
}

void TShopKeepItemWindow::display_shop_message(s32 id, s32 flags) {
    TShopWindowBase *owner = this->sequence;
    if (owner != NULL) {
        owner->display_shop_message(id, flags);
    }
}

void TShopKeepItemWindow::display_message(const char *text, s32 flags) {
    TShopWindowBase *owner = this->sequence;
    if (owner != NULL) {
        owner->display_message(text, flags);
    }
}
