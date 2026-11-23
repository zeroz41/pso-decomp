#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/TWindowCost.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/item/TItem.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/city/TShopArmorListWindow.h"
#include "pso/ui/city/TCheckRoomSequence.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/city/TShopEquipmentSellWindow.h"
#include "pso/ui/city/TShopGetItemWindow.h"
#include "pso/ui/city/TShopGetItemWindow_8021EEE4.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/system/SoundEffect.h"
#include "pso/ui/window/TWindowShop.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/unk/TLobby_8021B268.h"
#include "pso/unk/text_80104FCC.h"
#include "pso/unk/text_8011A780.h"
#include "pso/unk/text_80222C28.h"
#include "pso/unk/text_80222DE8.h"

#pragma readonly_strings on

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
extern "C" {
const char *TShopArmorListWindow__class_name = "TShopArmorListWindow";
s32 try_buy_item(TObjPlayer *player, TItemData *item);
// This unit sees the local client id as const: its load is scheduled across the item copies.
extern const s32 local_client_id;
}

// Written last-to-first: the unit is built with deferred code generation (see configure.py).

TShopArmorListWindow::TShopArmorListWindow(TObject *parent, TShopWindowBase *sequence, TObjPlayer *player) : TShopWindowBase(parent) {
    s32 count;
    this->m_name = TShopArmorListWindow__class_name;
    this->player = player;
    this->sequence = sequence;
    this->item_list = NULL;
    this->choice_menu = 0;
    this->help_window = NULL;
    this->extra_window = NULL;
    this->cost_window = NULL;
    this->pad_40 = 0;
    this->state = 0;
    this->last_cursor = 0;
    this->on_close = 0;
    this->can_equip = 0;
    calc_item_count((TObjPlayer *)this->player, &count);
    TLobby::set_shop_armor_list_flag(get_split_screen_slot(), count);
}

TShopArmorListWindow::~TShopArmorListWindow() {
    if (item_list != NULL) {
        item_list->close();
        item_list = NULL;
    }
    if (choice_menu != 0) {
        choice_menu->close();
        choice_menu = 0;
    }
    if (help_window != NULL) {
        help_window->close();
        help_window = NULL;
    }
    if (extra_window != NULL) {
        extra_window->close();
        extra_window = NULL;
    }
    if (cost_window != NULL) {
        cost_window->close();
        cost_window = NULL;
    }
}

void TShopArmorListWindow::update_state() {
    void (*callback)(TShopWindowBase *);
    switch (state) {
    case 0:
        refresh_item_list();
        set_state(1);
        return;
    case 1:
        handle_selection();
        return;
    case 2:
        handle_equip_offer();
        return;
    case 3:
    case 10:
        callback = on_close;
        if (callback != NULL) {
            callback(sequence);
        }
        queue_destruction();
        return;
    case 5:
        handle_select();
        return;
    case 6:
        update();
        return;
    case 7:
        advance_to_preparation_phase();
        return;
    case 8:
        open_menu_window();
        return;
    case 9:
        handle_buy_confirm();
    default:
        return;
    }
}

#pragma push
#pragma opt_common_subs off
void TShopArmorListWindow::refresh_item_list() {
    TItemData tmp;
    u16 id;
    s32 base;
    s32 i;
    TItemData *r;
    s32 j;
    s32 k;
    u8 *e;
    TWindowCost *c;
    base = get_split_screen_slot();
    item_count = TLobby__sub_8021B274(base);
    for (i = 0; i < item_count; i++) {
        ((TLobby *)(&tmp))->copy_armor_shop_entry(i, base);
        stock[i].copy_from(&tmp);
    }
    r = stock;
    for (j = 0; j < item_count; j++, r++) {
        if (r->data2.price != -1) {
            r->data2.price = TItemData::calc_price_of(r);
        }
    }
    if (item_list == NULL) {
        item_list = create_item_list_window(get_shop_text(0x2A), item_count, player->get_entity_id());
    } else {
        item_list->save_cursor_selection();
        item_list->reset_list();
    }
    if (item_list != NULL) {
        for (k = 0; k < item_count; k++) {
            e = (u8 *)this + k * sizeof(TItemData);
            if (*(s32 *)(e + offsetof(TShopArmorListWindow, stock[0].data2)) != -1) {
                item_list->add_ground_item((TItemData *)(e + offsetof(TShopArmorListWindow, stock)), k);
            }
        }
        item_list->calc_content_extent();
        item_list->clear_decided();
        item_list->clamp_selection_to_valid_entry();
    }
    if (help_window == NULL) {
        help_window = new TWindowHelpItem((void *)get_window_layout_position(0x27), player->get_entity_id());
        if (help_window != NULL && TLobby::is_camera_ctrl_active() > 2) {
            help_window->set_scale(0.75f, 0.75f);
        }
        help_window->set_displayed_item_colored((uaddr)stock);
    }
    if (cost_window == NULL) {
        cost_window = create_cost_window(player->get_entity_id());
        if ((c = cost_window) != NULL && stock[0].data2.price > 0) {
            c->set_cost(stock[0].data2.price);
        }
    }
    display_shop_message(0xB, 1);
}
#pragma pop

s32 TShopArmorListWindow::check_purchase_eligibility() {
    s32 res;
    s32 i;
    TItemData *r;
    can_equip = 0;
    if (item_list == NULL) {
        return 0;
    }
    i = item_list->get_cursor_value();
    if (stock[i].data2.price > obj_getPtr2B0_20((u8 *)player)) {
        return 0;
    }
    r = &stock[i];
    if (player->can_inventory_accept_item((u8 *)r) == 0) {
        return 1;
    }
    if (check_equip_requirements(player, r, &res) == 0) {
        return (res & 1) ? 2 : 3;
    }
    if (stock[i].data1.data_u8[0] == 1 && stock[i].data1.data_u8[1] == 3) {
        can_equip = 0;
    } else {
        can_equip = 1;
    }
    return 4;
}

void TShopArmorListWindow::handle_selection() {
    s32 i;
    if (item_list != NULL) {
        i = item_list->get_cursor_value();
        if (help_window != NULL && i != last_cursor) {
            help_window->set_displayed_item_colored((uaddr)&stock[i]);
        }
        if (i != last_cursor) {
            update_selection(&stock[i]);
        }
        last_cursor = i;
    }
    if (is_cancel_pressed() != 0) {
        state = 3;
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

void TShopArmorListWindow::handle_select() {
    if ((this->is_message_ready() != 0) && ((is_decide_pressed() != 0) || (is_cancel_pressed() != 0))) {
        display_shop_message(0xB, 1);
        item_list->clear_decided();
        set_state(1);
    }
}

void TShopArmorListWindow::update() {
    if ((this->is_message_ready() != 0) && ((is_decide_pressed() != 0) || (is_cancel_pressed() != 0))) {
        display_shop_message(0xB, 1);
        item_list->clear_decided();
        set_state(1);
    }
}

void TShopArmorListWindow::advance_to_preparation_phase() { set_state(8); }

void TShopArmorListWindow::open_menu_window() {
    f32 scale;
    s32 entity_id;

    if (this->choice_menu == NULL) {
        entity_id = this->player->get_entity_id();
        this->choice_menu = create_window_menu((saddr)get_window_layout_position(0x2B), 2, entity_id);
        this->choice_menu->add_text_entry(get_shop_text(4), 6, 0);
        this->choice_menu->add_text_entry(get_shop_text(5), 6, 1);
        choice_menu->calc_window_size();
        align_menu_entry_positions(this->choice_menu);
        choice_menu->set_ready_flag();
        scale = get_scale();
        choice_menu->set_position_xy(get_scale(), scale);
    }
    set_state(2);
}

void TShopArmorListWindow::handle_buy_confirm() {
    saddr base = get_split_screen_slot();
    s32 r;
    if (choice_menu != NULL && choice_menu->is_decided() != 0) {
        r = choice_menu->get_selected_value();
        if (r == 0) {
            if (item_list != NULL) {
                s32 i = item_list->get_cursor_value();
                TItemData it = stock[i];
                TItem *item;
                TItem *e;
                it.id = advance_item_id_counter(local_client_id);
                try_buy_item(player, &it);
                item = find_item_by_id(it.id);
                if (item != NULL && (e = player->get_equipped_item(item->get_attach_slot())) != NULL) {
                    TObjPlayer::send_6x26_unequip_item(player, e->get_item_id());
                }
                send_6x25_equip_item(player, it.id, 0);
                update_selection(&stock[i]);
                if (is_single_purchase_shop_item((u8 *)&stock[i]) != 0) {
                    TLobby::clear_shop_entry_value(i, base);
                }
                item_list->save_cursor_selection();
            }
            choice_menu->close();
            choice_menu = NULL;
            set_state(0);
        }
        if (r == 1) {
            if (item_list != NULL) {
                s32 i = item_list->get_cursor_value();
                TItemData it = stock[i];
                it.id = advance_item_id_counter(local_client_id);
                try_buy_item(player, &it);
                update_selection(&stock[i]);
                if (is_single_purchase_shop_item((u8 *)&stock[i]) != 0) {
                    TLobby::clear_shop_entry_value(i, base);
                }
                item_list->save_cursor_selection();
            }
            choice_menu->close();
            choice_menu = NULL;
            set_state(0);
        }
    }
    if (choice_menu != NULL && choice_menu->is_cancelled() != 0) {
        if (item_list != NULL) {
            s32 i = item_list->get_cursor_value();
            TItemData it = stock[i];
            it.id = advance_item_id_counter(local_client_id);
            try_buy_item(player, &it);
            update_selection(&stock[i]);
            if (is_single_purchase_shop_item((u8 *)&stock[i]) != 0) {
                TLobby::clear_shop_entry_value(i, base);
            }
            item_list->save_cursor_selection();
        }
        choice_menu->close();
        choice_menu = NULL;
        set_state(0);
    }
}

void TShopArmorListWindow::handle_equip_offer() {
    s32 i;
    s32 r;
    f32 sc;
    if (choice_menu != NULL && choice_menu->is_decided() != 0) {
        r = choice_menu->get_selected_value();
        if (r == 0 && item_list != NULL) {
            if (can_equip != 0) {
                display_shop_message(0x18, 1);
                choice_menu->close();
                choice_menu = create_yes_no_window(get_window_layout_position(0x2B), player->get_entity_id(), NULL, NULL);
                sc = get_scale();
                choice_menu->set_position_xy(get_scale(), sc);
                set_state(9);
            } else {
                i = item_list->get_cursor_value();
                TItemData c = stock[i];
                c.id = advance_item_id_counter(local_client_id);
                try_buy_item(player, &c);
                update_selection(&stock[i]);
                if (is_single_purchase_shop_item((u8 *)&stock[i]) != 0) {
                    TLobby::clear_shop_entry_value((s32)i, get_split_screen_slot());
                }
                item_list->save_cursor_selection();
                choice_menu->close();
                choice_menu = NULL;
                set_state(0);
            }
        }
        if (r == 1) {
            choice_menu->close();
            choice_menu = NULL;
            set_state(0);
        }
    }
    if (choice_menu != NULL && choice_menu->is_cancelled() != 0) {
        choice_menu->close();
        choice_menu = NULL;
        set_state(0);
    }
}

void TShopArmorListWindow::update_selection(TItemData *item) {
    TWindowCost *cost = this->cost_window;
    if (cost != NULL) {
        s32 price = item->data2.price;
        if (price > 0) {
            cost->set_cost(price);
        }
    }
}

void TShopArmorListWindow::display_shop_message(s32 id, s32 flags) {
    TShopWindowBase *sequence = this->sequence;
    if (sequence != NULL) {
        sequence->display_shop_message(id, flags);
    }
}

void TShopArmorListWindow::display_message(const char *text, s32 flags) {
    TShopWindowBase *sequence = this->sequence;
    if (sequence != NULL) {
        sequence->display_message(text, flags);
    }
}
