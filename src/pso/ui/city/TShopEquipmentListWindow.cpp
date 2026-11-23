#pragma defer_codegen on

#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/item/TItemData.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowBase.h"
#include "types.h"
#include "pso/ui/window/TWindowCost.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/item/TItem.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/city/TShopEquipmentListWindow.h"
#include "pso/ui/city/TCheckRoomSequence.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/city/TShopArmorListWindow.h"
#include "pso/ui/city/TShopEquipmentSellWindow.h"
#include "pso/ui/city/TShopGetItemWindow.h"
#include "pso/ui/city/TShopGetItemWindow_8021EEE4.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/object/base/TObjBase.h"
#include "pso/item/shop/ShopWeaponStock.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/unk/text_80104FCC.h"
#include "pso/unk/text_8011A780.h"
#include "pso/unk/text_80222C28.h"
#include "pso/unk/text_80222DE8.h"
#include "pso/ui/window/TWindowShop.h"
#include "pso/system/SoundEffect.h"

#pragma readonly_strings on

#pragma inline_depth(1)

#pragma auto_inline off

#pragma dont_inline off

const char *TShopEquipmentListWindow__class_name = "TShopEquipmentListWindow";

extern "C" {
void get_shop_weapon_stock_item(TItemData *dst, s32 index, s32 table);
void try_buy_item(void *player, TItemData *item);
extern int shop_weapon_stock_counts[];
extern const s32 local_client_id;

int TShopEquipmentListWindow__sub_8021C85C(int a0) {  return shop_weapon_stock_counts[a0]; }
}

TShopEquipmentListWindow::TShopEquipmentListWindow(TObject *parent, TShopWindowBase *sequence, TObjPlayer *player) : TShopWindowBase(parent) {
    s32 count;
    this->m_name = TShopEquipmentListWindow__class_name;
    this->player = player;
    this->sequence = sequence;
    this->confirm_menu = NULL;
    this->item_list = NULL;
    this->help_window = NULL;
    this->pad_38 = NULL;
    this->cost_window = NULL;
    this->pad_40 = 0;
    this->last_cursor = 0;
    this->can_equip = 0;
    this->state = 0;
    this->on_close = NULL;
    calc_item_count(this->player, &count);
    TLobby__sub_80225238((get_split_screen_slot()), (count));
}

TShopEquipmentListWindow::~TShopEquipmentListWindow() {
    if (item_list != NULL) { item_list->close(); item_list = NULL; }
    if (confirm_menu != NULL) { confirm_menu->close(); confirm_menu = NULL; }
    if (help_window != NULL) { help_window->close(); help_window = NULL; }
    if (pad_38 != NULL) { pad_38->close(); pad_38 = NULL; }
    if (cost_window != NULL) { cost_window->close(); cost_window = NULL; }
}

void TShopEquipmentListWindow::update_state() {
    void (*callback)(TShopWindowBase *);
    switch (this->state) {
    case 0:
        create_buy_list_windows();
        set_state(1);
        return;
    case 1:
        handle_selection();
        return;
    case 2:
        handle_equip_offer();
        return;
    case 5:
        handle_select();
        return;
    case 6:
        handle_confirm();
        return;
    case 7:
        get_list_item8();
        return;
    case 8:
        open_menu_window();
        return;
    case 9:
        handle_buy_confirm();
        return;
    case 3:
    case 10:
        callback = this->on_close;
        if (callback != NULL) {
            callback(this->sequence);
        }
        queue_destruction();
    default:
        return;
    }
}

#pragma push
#pragma opt_common_subs off

void TShopEquipmentListWindow::create_buy_list_windows() {
    TItemData tmp;
    s32 i;
    TItemData *r;
    s32 j;
    s32 k;
    u8 *e;
    TWindowCost *c;
    this->item_count = TShopEquipmentListWindow__sub_8021C85C(get_split_screen_slot());
    for (i = 0; i < this->item_count; i++) {
        get_shop_weapon_stock_item(&tmp, i, get_split_screen_slot());
        this->stock[i].copy_from(&tmp);
    }
    r = this->stock;
    for (j = 0; j < this->item_count; j++, r++) {
        if (r->data2.price != -1) {
            r->data2.price = TItemData::calc_price_of(r);
        }
    }
    if (this->item_list == NULL) {
        this->item_list = create_item_list_window(get_shop_text(0x26), this->item_count, this->player->get_entity_id());
    } else {
        this->item_list->save_cursor_selection();
        this->item_list->reset_list();
    }
    if (this->item_list != NULL) {
        for (k = 0; k < this->item_count; k++) {
            e = (u8 *)this + k * sizeof(TItemData);
            if (*(s32 *)(e + offsetof(TShopEquipmentListWindow, stock[0].data2)) != -1) {
                this->item_list->add_ground_item((TItemData *)(e + offsetof(TShopEquipmentListWindow, stock)), k);
            }
        }
        this->item_list->calc_content_extent();
        this->item_list->clear_decided();
        this->item_list->clamp_selection_to_valid_entry();
    }
    if (this->help_window == NULL) {
        this->help_window = new TWindowHelpItem((void *)get_window_layout_position(0x27), this->player->get_entity_id());
        if (this->help_window != NULL && TLobby::is_camera_ctrl_active() > 2) {
            this->help_window->set_scale(0.75f, 0.75f);
        }
        this->help_window->set_displayed_item_colored((uaddr)this->stock);
    }
    if (this->cost_window == NULL) {
        this->cost_window = create_cost_window(this->player->get_entity_id());
        if ((c = this->cost_window) != NULL && this->stock[0].data2.price > 0) {
            c->set_cost(this->stock[0].data2.price);
        }
    }
    display_shop_message(0xB, 1);
}

#pragma pop

s32 TShopEquipmentListWindow::check_purchase_eligibility() {
    u32 res;
    s32 i;
    TItemData *r;
    this->can_equip = 0;
    if (this->item_list == NULL) {
        return 0;
    }
    i = this->item_list->get_cursor_value();
    if (this->stock[i].data2.price > obj_getPtr2B0_20((u8 *)this->player)) {
        return 0;
    }
    r = &this->stock[i];
    if (this->player->can_inventory_accept_item((u8 *)r) == 0) {
        return 1;
    }
    if (check_equip_requirements(this->player, r, (s32 *)&res) == 0) {
        return (res & 1) ? 2 : 3;
    }
    this->can_equip = 1;
    return 4;
}

void TShopEquipmentListWindow::handle_selection() {
    s32 i;
    if (this->item_list != NULL) {
        i = this->item_list->get_cursor_value();
        if (this->help_window != NULL && i != this->last_cursor) {
            this->help_window->set_displayed_item_colored((uaddr)&this->stock[i]);
        }
        if (i != this->last_cursor) {
            update_list(&this->stock[i]);
        }
        this->last_cursor = i;
    }
    if (is_cancel_pressed() != 0) {
        set_state(3);
        play_sound_effect(0x52D01, 0, 0, 0);
        return;
    }
    if (is_decide_pressed() != 0) {
        play_sound_effect(0x52D01, 0, 0, 0);
        switch (check_purchase_eligibility()) {
        case 0:
            display_shop_message(0xF, 1);
            set_state(5);
            break;
        case 1:
            display_shop_message(0x19, 1);
            set_state(6);
            break;
        case 2:
            display_shop_message(0x12, 1);
            set_state(7);
            break;
        case 3:
            display_shop_message(0x11, 1);
            set_state(7);
            break;
        case 4:
            set_state(8);
            break;
        }
    }
}

void TShopEquipmentListWindow::handle_select() {
    if (is_message_ready() != 0 && (is_decide_pressed() != 0 || is_cancel_pressed() != 0)) {
        display_shop_message(0xB, 1);
        this->item_list->clear_decided();
        this->TShopWindowBase::set_state(1);
    }
}

void TShopEquipmentListWindow::handle_confirm() {
    if (is_message_ready() != 0 && (is_decide_pressed() != 0 || is_cancel_pressed() != 0)) {
        display_shop_message(0xB, 1);
        this->item_list->clear_decided();
        this->TShopWindowBase::set_state(1);
    }
}

void TShopEquipmentListWindow::get_list_item8() { set_state(8); }

void TShopEquipmentListWindow::open_menu_window() {
    f32 scale;
    s32 entity_id;

    if (this->confirm_menu == NULL) {
        entity_id = this->player->get_entity_id();
        this->confirm_menu = create_window_menu((saddr)get_window_layout_position(0x2B), 2, entity_id);
        this->confirm_menu->add_text_entry(get_shop_text(4), 6, 0);
        this->confirm_menu->add_text_entry(get_shop_text(5), 6, 1);
        confirm_menu->calc_window_size();
        align_menu_entry_positions(this->confirm_menu);
        confirm_menu->set_ready_flag();
        scale = get_scale();
        confirm_menu->set_position_xy(get_scale(), scale);
    }
    set_state(2);
}

void TShopEquipmentListWindow::handle_buy_confirm() {
    s32 r;
    if (confirm_menu != NULL && confirm_menu->is_decided() != 0) {
        r = confirm_menu->get_selected_value();
        if (r == 0) {
            if (item_list != NULL) {
                s32 i = item_list->get_cursor_value();
                TItemData it = stock[i];
                TItem *item;
                TItem *equipped;
                it.id = advance_item_id_counter(local_client_id);
                it.set_stack_count(1);
                try_buy_item(player, &it);
                item = find_item_by_id(it.id);
                if (item != NULL && (equipped = player->get_equipped_item(item->get_attach_slot())) != NULL) {
                    TObjPlayer::send_6x26_unequip_item(player, equipped->get_item_id());
                }
                send_6x25_equip_item(reinterpret_cast<TObjPlayer *>(player), it.id, 0);
                update_list(&stock[i]);
                if (is_single_purchase_shop_item((u8 *)&stock[i]) != 0) {
                    TLobby::clear_slot_field_f10(i, get_split_screen_slot());
                }
                item_list->save_cursor_selection();
            }
            confirm_menu->close();
            confirm_menu = NULL;
            set_state(0);
        }
        if (r == 1) {
            if (item_list != NULL) {
                s32 i = item_list->get_cursor_value();
                TItemData it = stock[i];
                it.id = advance_item_id_counter(local_client_id);
                it.set_stack_count(1);
                try_buy_item(player, &it);
                update_list(&stock[i]);
                if (is_single_purchase_shop_item((u8 *)&stock[i]) != 0) {
                    TLobby::clear_slot_field_f10(i, get_split_screen_slot());
                }
                item_list->save_cursor_selection();
            }
            confirm_menu->close();
            confirm_menu = NULL;
            set_state(0);
        }
    }
    if (confirm_menu != NULL && confirm_menu->is_cancelled() != 0) {
        if (item_list != NULL) {
            s32 i = item_list->get_cursor_value();
            TItemData it = stock[i];
            it.id = advance_item_id_counter(local_client_id);
            it.set_stack_count(1);
            try_buy_item(player, &it);
            update_list(&stock[i]);
            if (is_single_purchase_shop_item((u8 *)&stock[i]) != 0) {
                TLobby::clear_slot_field_f10(i, get_split_screen_slot());
            }
            item_list->save_cursor_selection();
        }
        confirm_menu->close();
        confirm_menu = NULL;
        set_state(0);
    }
}

void TShopEquipmentListWindow::handle_equip_offer() {
    s32 r;
    s32 i;
    f32 sc;
    if (confirm_menu != NULL && confirm_menu->is_decided() != 0) {
        r = confirm_menu->get_selected_value();
        if (r == 0 && item_list != NULL) {
            if (can_equip != 0) {
                display_shop_message(0x18, 1);
                confirm_menu->close();
                confirm_menu = create_yes_no_window(get_window_layout_position(0x2B), player->get_entity_id(), NULL, NULL);
                sc = get_scale();
                confirm_menu->set_position_xy(get_scale(), sc);
                set_state(9);
            } else {
                i = item_list->get_cursor_value();
                TItemData c = stock[i];
                c.id = advance_item_id_counter(local_client_id);
                c.set_stack_count(1);
                try_buy_item(player, &c);
                update_list(&stock[i]);
                if (is_single_purchase_shop_item((u8 *)&stock[i]) != 0) {
                    TLobby::clear_slot_field_f10(i, get_split_screen_slot());
                }
                confirm_menu->close();
                confirm_menu = NULL;
                set_state(0);
            }
        }
        if (r == 1) {
            confirm_menu->close();
            confirm_menu = NULL;
            set_state(0);
        }
    }
    if (confirm_menu != NULL && confirm_menu->is_cancelled() != 0) {
        confirm_menu->close();
        confirm_menu = NULL;
        set_state(0);
    }
}

void TShopEquipmentListWindow::update_list(TItemData *item) {
    TWindowCost *cost = this->cost_window;
    if (cost != NULL) {
        s32 price = item->data2.price;
        if (price > 0) {
            cost->set_cost(price);
        }
    }
}

void TShopEquipmentListWindow::display_shop_message(s32 id, s32 flags) {
    TShopWindowBase *sequence = this->sequence;
    if (sequence != NULL) {
        sequence->display_shop_message(id, flags);
    }
}

void TShopEquipmentListWindow::display_message(const char *text, s32 flags) {
    TShopWindowBase *sequence = this->sequence;
    if (sequence != NULL) {
        sequence->display_message(text, flags);
    }
}
