#define TOBJECT_OUT_OF_LINE_HELPERS
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

#include "pso/system/SoundEffect.h"
#include "pso/ui/window/TWindowQuantity.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "types.h"
#include "pso/ui/window/TWindowCost.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/city/TShopSequence.h"
#include "pso/ui/city/TShopItemListWindow.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/city/TShopArmorListWindow.h"
#include "pso/ui/city/TShopEquipmentSellWindow.h"
#include "pso/ui/city/TShopGetItemWindow.h"
#include "pso/ui/city/TShopGetItemWindow_8021EEE4.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowInputNumber.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/ui/city/TCheckRoomSequence.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/item/TItemData.h"
#include "pso/network/client_id.h"
#include "pso/unk/text_8011A780.h"
#include "pso/unk/text_80222DE8.h"
#include "pso/unk/text_80223B98.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TPlyItem.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/ui/city/TShopItemTecSequence.h"
#include "pso/ui/window/TWindowShop.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/unk/text_80222C28.h"


#pragma readonly_strings on

// These offsets retain the original addressing for the two indexed price loads.
static const size_t shop_items_offset = offsetof(TShopItemListWindow, shop_items);
static const size_t shop_price_offset = shop_items_offset + offsetof(TItemData, data2);

// Favoured grind type per section ID (-1: none), indexed by the player's section ID in
// roll_shop_weapon_grind and TLobby::is_slot_match.
s32 section_id_favored_grind_table[10] = {9, 7, 2, 4, 8, 10, -1, 3, -1, 5};

extern "C" {
const char *TShopItemListWindow__class_name = "TShopItemListWindow";
s32 try_buy_item(TObjPlayer *player, void *item);
}

TShopItemListWindow::TShopItemListWindow(TObject *parent, TShopWindowBase *sequence, TObjPlayer *player) : TShopWindowBase(parent) {
    s32 count;
    this->m_name = TShopItemListWindow__class_name;
    this->player = player;
    this->sequence = sequence;
    this->item_list = 0;
    this->confirm_menu = 0;
    this->quantity_input = 0;
    this->help_window = 0;
    this->status_window = 0;
    this->cost_window = 0;
    this->pad_44 = 0;
    this->purchase_count = 0;
    this->state = 0;
    this->on_close = 0;
    this->purchase_step = 0;
    this->last_cursor = 0;
    calc_item_count((TObjPlayer *)this->player, &count);
    TLobby::set_6264_and_call_2244B0(get_split_screen_slot(), count);
}

TShopItemListWindow::~TShopItemListWindow() {
    if (item_list != NULL) { item_list->close(); item_list = NULL; }
    if (confirm_menu != NULL) { confirm_menu->close(); confirm_menu = NULL; }
    if (quantity_input != NULL) { quantity_input->close(); quantity_input = NULL; }
    if (help_window != NULL) { help_window->close(); help_window = NULL; }
    if (status_window != NULL) { status_window->close(); status_window = NULL; }
    if (cost_window != NULL) { cost_window->close(); cost_window = NULL; }
}

void TShopItemListWindow::update_state() {
    switch (state) {
    case 0:
        build_item_list();
        set_state(1);
        return;
    case 1:
        handle_tool_list_select();
        return;
    case 2:
        handle_amount_confirm();
        return;
    case 3:
    case 8:
        if (on_close != NULL) {
            on_close(sequence);
        }
        queue_destruction();
        return;
    case 5:
        update();
        return;
    case 6:
        handle_confirm();
        return;
    case 7:
        prepare_tool_purchase();
    default:
        return;
    }
}

#pragma push
#pragma opt_common_subs off
void TShopItemListWindow::build_item_list() {
    TItemData tmp;
    s32 i;
    TItemData *r;
    s32 j;
    u8 *entry;
    s32 n;
    TWindowCost *c;
    item_count = TShopItemTecSequence__sub_8021FE6C(get_split_screen_slot());
    for (i = 0; i < item_count; i++) {
        reinterpret_cast<TLobby *>(&tmp)->copy_shop_item_entry(i, get_split_screen_slot());
        shop_items[i].copy_from(&tmp);
    }
    r = shop_items;
    for (j = 0; j < item_count; j++, r++) {
        if ((s32)r->data2.data_u32 != -1) {
            r->data2.data_u32 = TItemData::calc_price_of(r);
        }
    }
    if (item_list == NULL) {
        item_list = create_item_list_window(get_shop_text(0x2D), item_count, player->get_entity_id());
    } else {
        item_list->reset_list();
    }
    if (item_list != NULL) {
        for (i = 0; i < item_count; i++) {
            entry = (u8 *)this + i * sizeof(TItemData);
            if (*(s32 *)(entry + shop_price_offset) != -1) {
                item_list->add_ground_item((TItemData *)(entry + shop_items_offset), i);
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
        help_window->set_displayed_item_colored((uaddr)shop_items);
    }
    if (status_window == NULL) {
        status_window = create_window_quantity((u16)get_player_entity_id());
        n = player->inventory_objects->count_items_by_id(&shop_items[0]);
        status_window->set_quantity(n);
    }
    if (cost_window == NULL) {
        cost_window = create_cost_window(player->get_entity_id());
        if ((c = cost_window) != NULL && (s32)shop_items[0].data2.data_u32 > 0) {
            c->set_cost((s32)shop_items[0].data2.data_u32);
        }
    }
}
#pragma pop

s32 TShopItemListWindow::check_purchase_eligibility() {
    s32 sel;
    s32 meseta;
    if (item_list == NULL) {
        return 0;
    }
    sel = item_list->get_cursor_value();
    meseta = obj_getPtr2B0_20((u8 *)player);
    if ((s32)shop_items[sel].data2.data_u32 > meseta) {
        return 0;
    }
    if (player->can_inventory_accept_item(reinterpret_cast<u8 *>(&shop_items[sel])) == 0) {
        return 1;
    }
    return 3;
}

void TShopItemListWindow::handle_tool_list_select() {
    s32 i;
    s32 n;
    u8 *entry;
    if (item_list != NULL) {
        i = item_list->get_cursor_value();
        if (help_window != NULL && i != last_cursor) {
            help_window->set_displayed_item_colored((uaddr)&shop_items[i]);
        }
        if (status_window != NULL && i != last_cursor) {
            n = player->inventory_objects->count_items_by_id(&shop_items[i]);
            status_window->set_quantity(n);
        }
        if (cost_window != NULL && i != last_cursor && (entry = (u8 *)this + i * sizeof(TItemData), *(s32 *)(entry + shop_price_offset) > 0)) {
            cost_window->set_cost(*(s32 *)(entry + shop_price_offset));
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
            break;
        case 3:
            set_state(7);
            break;
        }
    }
}

void TShopItemListWindow::update() {
    if (is_message_ready() != 0 && (is_decide_pressed() != 0 || is_cancel_pressed() != 0)) {
        display_shop_message(0xB, 1);
        this->item_list->clear_decided();
        set_state(1);
    }
}

void TShopItemListWindow::handle_confirm() {
    if (is_message_ready() != 0 && (is_decide_pressed() != 0 || is_cancel_pressed() != 0)) {
        display_shop_message(0xB, 1);
        this->item_list->clear_decided();
        set_state(1);
    }
}

void TShopItemListWindow::prepare_tool_purchase() {
    s32 sel;
    s32 room;
    s32 count;

    if (item_list != NULL) {
        sel = item_list->get_cursor_value();
        room = player->can_inventory_accept_item(reinterpret_cast<u8 *>(&shop_items[sel]));
        count = obj_getPtr2B0_20((u8 *)player) / (s32)shop_items[sel].data2.data_u32;
        if (count > room) {
            count = room;
        }
        if (count > 1) {
            quantity_input = new TWindowInputNumber((void *)get_window_layout_position(0x2B), 1, count, 1, get_player_entity_id());
            if (quantity_input != NULL && TLobby::is_camera_ctrl_active() > 2) {
                quantity_input->set_scale(0.75f, 0.75f);
            }
            purchase_step = 0;
            set_state(2);
            return;
        }
        confirm_menu = create_window_menu((saddr)get_window_layout_position(0x2B), 2, player->get_entity_id());
        confirm_menu->add_text_entry(get_shop_text(4), 6, 0);
        confirm_menu->add_text_entry(get_shop_text(5), 6, 1);
        confirm_menu->calc_window_size();
        align_menu_entry_positions(confirm_menu);
        confirm_menu->set_ready_flag();
        f32 scale = get_scale();
        confirm_menu->set_position_xy(get_scale(), scale);
        purchase_count = 1;
        purchase_step = 1;
        set_state(2);
    }
}

void TShopItemListWindow::handle_amount_confirm() {
    s32 r;
    s32 sel;
    s32 n;

    switch (purchase_step) {
    case 0:
        if (quantity_input != NULL && quantity_input->is_confirmed() != 0) {
            if (confirm_menu == NULL) {
                confirm_menu = create_window_menu((saddr)get_window_layout_position(0x2B), 2, player->get_entity_id());
                confirm_menu->add_text_entry(get_shop_text(4), 6, 0);
                confirm_menu->add_text_entry(get_shop_text(5), 6, 1);
                confirm_menu->calc_window_size();
                align_menu_entry_positions(confirm_menu);
                confirm_menu->set_ready_flag();
                f32 scale = get_scale();
                confirm_menu->set_position_xy(get_scale(), scale);
            }
            purchase_count = quantity_input->get_value();
            quantity_input->close();
            quantity_input = NULL;
            purchase_step = 1;
        }
        if (quantity_input != NULL && quantity_input->is_cancelled() != 0) {
            quantity_input->close();
            quantity_input = NULL;
            if (item_list != NULL) {
                item_list->clear_decided();
            }
            set_state(1);
        }
        break;
    case 1:
        if (confirm_menu != NULL && confirm_menu->is_decided() != 0) {
            r = confirm_menu->get_selected_value();
            if (r == 0) {
                if (item_list != NULL) {
                    sel = item_list->get_cursor_value();
                    TItemData item = shop_items[sel];
                    item.id = advance_item_id_counter(local_client_id);
                    if (TCheckRoomSequence::get_item_def((uaddr)&item) != 0) {
                        item.set_stack_count(purchase_count);
                    }
                    try_buy_item(player, &item);
                    if (status_window != NULL) {
                        n = player->inventory_objects->count_items_by_id(&shop_items[sel]);
                        status_window->set_quantity(n);
                    }
                    if (is_single_purchase_shop_item((u8 *)&shop_items[sel]) != 0) {
                        mark_shop_tool_sold_out(sel, get_split_screen_slot());
                    }
                    item_list->save_cursor_selection();
                }
                confirm_menu->close();
                confirm_menu = NULL;
                set_state(0);
            }
            if (r == 1) {
                confirm_menu->close();
                confirm_menu = NULL;
                if (item_list != NULL) {
                    item_list->clear_decided();
                }
                set_state(1);
            }
        }
        if (confirm_menu != NULL && confirm_menu->is_cancelled() != 0) {
            confirm_menu->close();
            confirm_menu = NULL;
            if (item_list != NULL) {
                item_list->clear_decided();
            }
            set_state(1);
        }
        break;
    }
}

void TShopItemListWindow::display_shop_message(s32 id, s32 flags) {
    TShopWindowBase *sequence = this->sequence;
    if (sequence != NULL) {
        sequence->display_shop_message(id, flags);
    }
}

void TShopItemListWindow::display_message(const char *text, s32 flags) {
    TShopWindowBase *sequence = this->sequence;
    if (sequence != NULL) {
        sequence->display_message(text, flags);
    }
}
