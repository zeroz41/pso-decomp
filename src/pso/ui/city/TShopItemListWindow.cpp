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


#pragma readonly_strings on

struct Win_8021F798 {
    u8 pad00[0x24];
    u8 *player;
    void *list;
    u8 pad2c[0x38 - 0x2C];
    void *help;
    void *status;
    void *sell;
    u8 pad44[0x54 - 0x44];
    s32 cur;
};

struct Win_8021F964 {
    u8 pad0[0x24];
    saddr player;
    void *list;
};

struct Win_8021F9EC {
    u8 pad0[0x24];
    u8 *player;
    void *list;
    u8 pad2c[0x38 - 0x2C];
    void *help;
    void *status;
    void *cost;
    u8 pad44[0x48 - 0x44];
    s32 count;
};

// These offsets retain the original addressing for the two indexed price loads.
static const size_t shop_items_offset = offsetof(TShopItemListWindow, shop_items);
static const size_t shop_price_offset = shop_items_offset + offsetof(TItemData, data2);

// Favoured grind type per section ID (-1: none), indexed by the player's section ID in
// roll_shop_weapon_grind and TLobby::is_slot_match.
s32 section_id_favored_grind_table[10] = {9, 7, 2, 4, 8, 10, -1, 3, -1, 5};

extern "C" {
s32 sub_8022397C__15TShopWindowBaseFv(void *);
const char *TShopItemListWindow__class_name = "TShopItemListWindow";
int obj_getPtr2B0_20(u8 *p);
s32 TShopItemTecSequence__sub_8021FE6C();
s32 get_shop_text(int);
void *__ct__15TWindowHelpItemFPvl(void *, s32, s32);
saddr get_window_layout_position(int);
void *create_item_list_window(s32, s32, s32);

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
    this->m_44 = 0;
    this->m_50 = 0;
    this->state = 0;
    this->m_1c0 = 0;
    this->m_4c = 0;
    this->m_54 = 0;
    calc_item_count((TObjPlayer *)this->player, &count);
    TLobby::set_6264_and_call_2244B0(sub_8022397C(), count);
}

TShopItemListWindow::~TShopItemListWindow() {
    if (item_list != 0) { ((TWindowBase *)item_list)->close(); item_list = 0; }
    if (confirm_menu != 0) { ((TWindowBase *)confirm_menu)->close(); confirm_menu = 0; }
    if (quantity_input != 0) { ((TWindowBase *)quantity_input)->close(); quantity_input = 0; }
    if (help_window != 0) { ((TWindowBase *)help_window)->close(); help_window = 0; }
    if (status_window != 0) { ((TWindowBase *)status_window)->close(); status_window = 0; }
    if (cost_window != 0) { ((TWindowBase *)cost_window)->close(); cost_window = 0; }
}

void TShopItemListWindow::vfunc_11() {
    u8 *arg0 = (u8 *)this;
    s32 (*temp_r12)(s32);
    switch (*(u32 *)((s8 *)arg0 + 0x20)) {
    case 0:
        TShopItemListWindow::build_item_list(arg0);
        ((TShopWindowBase *)arg0)->set_state(1);
        return;
    case 1:
        TShopItemListWindow::handle_tool_list_select(arg0);
        return;
    case 2:
        ((TShopItemListWindow *)arg0)->handle_amount_confirm();
        return;
    case 3:
    case 8:
        temp_r12 = *(s32 (**)(s32))((s8 *)arg0 + 0x1C0);
        if (temp_r12 != NULL) {
            temp_r12(*(s32 *)((s8 *)arg0 + 0x2C));
        }
        ((TObject *)arg0)->queue_destruction();
        return;
    case 5:
        ((TShopItemListWindow *)arg0)->update();
        return;
    case 6:
        ((TShopItemListWindow *)arg0)->handle_confirm();
        return;
    case 7:
        ((TShopItemListWindow *)arg0)->prepare_tool_purchase();
    default:
        return;
    }
}

#pragma push
#pragma opt_common_subs off
#define W ((Win_8021F9EC *)p)
void TShopItemListWindow::build_item_list(void *p) {
    TShopItemListWindow *window = (TShopItemListWindow *)p;
    TItemData tmp;
    s32 i;
    TItemData *r;
    s32 j;
    void *o;
    u8 *entry;
    s32 n;
    void *c;
    ((TShopWindowBase *)W)->sub_8022397C();
    W->count = TShopItemTecSequence__sub_8021FE6C();
    for (i = 0; i < W->count; i++) {
        reinterpret_cast<TLobby *>(&tmp)->copy_shop_item_entry(i, reinterpret_cast<TShopWindowBase *>(W)->sub_8022397C());
        window->shop_items[i].copy_from(&tmp);
    }
    r = window->shop_items;
    for (j = 0; j < W->count; j++, r++) {
        if ((s32)r->data2.data_u32 != -1) {
            r->data2.data_u32 = TItemData::calc_price_of(r);
        }
    }
    if (W->list == NULL) {
        W->list = create_item_list_window(get_shop_text(0x2D), W->count, ((TObjBase *)(W->player))->get_entity_id());
    } else {
        ((TWindowMenuIconLine *)(W->list))->reset_list();
    }
    if (W->list != NULL) {
        for (i = 0; i < W->count; i++) {
            entry = (u8 *)W + i * sizeof(TItemData);
            if (*(s32 *)(entry + shop_price_offset) != -1) {
                ((TWindowSubStatusDisp *)(W->list))->add_ground_item((saddr)(entry + shop_items_offset), i);
            }
        }
        ((TWindowMenuIconLine *)W->list)->calc_content_extent();
        ((TWindowMenuIconLine *)((saddr)W->list))->clear_decided();
        ((TWindowMenuIconLine *)(W->list))->clamp_selection_to_valid_entry();
    }
    if (W->help == NULL) {
        o = TObject::operator new(0xBC);
        if (o != NULL) {
            o = __ct__15TWindowHelpItemFPvl(o, get_window_layout_position(0x27), ((TObjBase *)(W->player))->get_entity_id());
        }
        W->help = o;
        if (W->help != NULL && TLobby::is_camera_ctrl_active() > 2) {
            ((TWindowHelpItem *)(W->help))->set_scale(0.75f, 0.75f);
        }
        ((TWindowHelpItem *)(W->help))->set_displayed_item_colored((uaddr)window->shop_items);
    }
    if (W->status == NULL) {
        W->status = create_window_quantity((u16)((TShopSequence *)W)->get_child_field1c());
        n = static_cast<TPlyItem *>(reinterpret_cast<TObjPlayer *>(W->player)->inventory_objects)->count_items_by_id(reinterpret_cast<saddr>(&window->shop_items[0]));
        ((TWindowSubStatusDisp *)(W->status))->set_entry1_field20(n);
    }
    if (W->cost == NULL) {
        W->cost = create_cost_window(((TObjBase *)(W->player))->get_entity_id());
        if ((c = W->cost) != NULL && (s32)window->shop_items[0].data2.data_u32 > 0) {
            static_cast<TWindowCost *>(c)->set_cost((s32)window->shop_items[0].data2.data_u32);
        }
    }
}
#undef W
#pragma pop

s32 TShopItemListWindow::check_purchase_eligibility() {
    Win_8021F964 *self = (Win_8021F964 *)this;
    s32 sel;
    s32 meseta;
    if (self->list == NULL) {
        return 0;
    }
    sel = ((TWindowMenuIconLine *)self->list)->get_cursor_value();
    meseta = obj_getPtr2B0_20((u8 *)self->player);
    if ((s32)shop_items[sel].data2.data_u32 > meseta) {
        return 0;
    }
    if (reinterpret_cast<TObjPlayer *>(self->player)->can_inventory_accept_item(reinterpret_cast<u8 *>(&shop_items[sel])) == 0) {
        return 1;
    }
    return 3;
}

#define W ((Win_8021F798 *)p)
void TShopItemListWindow::handle_tool_list_select(void *p) {
    s32 i;
    s32 n;
    TShopItemListWindow *window = (TShopItemListWindow *)p;
    u8 *entry;
    if (W->list != NULL) {
        i = ((TWindowMenuIconLine *)(W->list))->get_cursor_value();
        if (W->help != NULL && i != W->cur) {
            ((TWindowHelpItem *)(W->help))->set_displayed_item_colored((uaddr)&window->shop_items[i]);
        }
        if (W->status != NULL && i != W->cur) {
            n = static_cast<TPlyItem *>(reinterpret_cast<TObjPlayer *>(W->player)->inventory_objects)->count_items_by_id(reinterpret_cast<saddr>(&window->shop_items[i]));
            ((TWindowSubStatusDisp *)(W->status))->set_entry1_field20(n);
        }
        if (W->sell != NULL && i != W->cur && (entry = (u8 *)W + i * sizeof(TItemData), *(s32 *)(entry + shop_price_offset) > 0)) {
            static_cast<TWindowCost *>(W->sell)->set_cost(*(s32 *)(entry + shop_price_offset));
        }
        W->cur = i;
    }
    if (((TShopWindowBase *)W)->sub_802239EC() != 0) {
        *(s32 *)((u8 *)W + 0x20) = 3;
        play_sound_effect(0x52D01, 0, 0, 0);
        return;
    }
    if (((TShopWindowBase *)W)->sub_80223A48() != 0) {
        play_sound_effect(0x52D01, 0, 0, 0);
        switch (((TShopItemListWindow *)W)->check_purchase_eligibility()) {
        case 0:
            ((TShopItemListWindow *)p)->display_shop_message(0xF, 1);
            ((TShopWindowBase *)W)->set_state(5);
            break;
        case 1:
            ((TShopItemListWindow *)p)->display_shop_message(0x19, 1);
            ((TShopWindowBase *)W)->set_state(6);
            break;
        case 2:
            break;
        case 3:
            ((TShopWindowBase *)W)->set_state(7);
            break;
        }
    }
}
#undef W

void TShopItemListWindow::update() {
    if (vfunc_10() != 0 && (sub_80223A48() != 0 || sub_802239EC() != 0)) {
        display_shop_message(0xB, 1);
        ((TWindowMenuIconLine *)(this->item_list))->clear_decided();
        set_state(1);
    }
}

void TShopItemListWindow::handle_confirm() {
    if (vfunc_10() != 0 && (sub_80223A48() != 0 || sub_802239EC() != 0)) {
        display_shop_message(0xB, 1);
        ((TWindowMenuIconLine *)(this->item_list))->clear_decided();
        set_state(1);
    }
}

void TShopItemListWindow::prepare_tool_purchase() {
    Win_8021F9EC *self = (Win_8021F9EC *)this;
    s32 sel;
    s32 room;
    s32 count;

    if (self->list != NULL) {
        sel = ((TWindowMenuIconLine *)self->list)->get_cursor_value();
        room = reinterpret_cast<TObjPlayer *>(self->player)->can_inventory_accept_item(reinterpret_cast<u8 *>(&shop_items[sel]));
        count = obj_getPtr2B0_20((u8 *)self->player) / (s32)shop_items[sel].data2.data_u32;
        if (count > room) {
            count = room;
        }
        if (count > 1) {
            quantity_input = (uaddr)new TWindowInputNumber((void *)get_window_layout_position(0x2B), 1, count, 1, ((TShopSequence *)this)->get_child_field1c());
            if (quantity_input != 0U && TLobby::is_camera_ctrl_active() > 2) {
                ((TWindowInputNumber *)(quantity_input))->set_scale(0.75f, 0.75f);
            }
            m_4c = 0;
            set_state(2);
            return;
        }
        confirm_menu = create_window_menu((saddr)get_window_layout_position(0x2B), 2, ((TObjBase *)player)->get_entity_id());
        confirm_menu->add_text_entry(get_shop_text(4), 6, 0);
        confirm_menu->add_text_entry(get_shop_text(5), 6, 1);
        confirm_menu->calc_window_size();
        align_menu_entry_positions(confirm_menu);
        confirm_menu->set_ready_flag();
        f32 scale = get_scale();
        ((TWindowAddition *)confirm_menu)->set_position_xy(get_scale(), scale);
        m_50 = 1;
        m_4c = 1;
        set_state(2);
    }
}

void TShopItemListWindow::handle_amount_confirm() {
    s32 r;
    s32 sel;
    s32 n;

    switch (m_4c) {
    case 0:
        if (quantity_input != 0U && ((TWindowInputNumber *)quantity_input)->is_confirmed() != 0) {
            if (confirm_menu == NULL) {
                confirm_menu = create_window_menu((saddr)get_window_layout_position(0x2B), 2, ((TObjBase *)player)->get_entity_id());
                confirm_menu->add_text_entry(get_shop_text(4), 6, 0);
                confirm_menu->add_text_entry(get_shop_text(5), 6, 1);
                confirm_menu->calc_window_size();
                align_menu_entry_positions(confirm_menu);
                confirm_menu->set_ready_flag();
                f32 scale = get_scale();
                ((TWindowAddition *)confirm_menu)->set_position_xy(get_scale(), scale);
            }
            m_50 = ((TWindowInputNumber *)quantity_input)->get_value();
            ((TWindowBase *)quantity_input)->close();
            quantity_input = 0U;
            m_4c = 1;
        }
        if (quantity_input != 0U && ((TWindowInputNumber *)quantity_input)->is_cancelled() != 0) {
            ((TWindowBase *)quantity_input)->close();
            quantity_input = 0U;
            if (item_list != 0U) {
                ((TWindowMenuIconLine *)item_list)->clear_decided();
            }
            set_state(1);
        }
        break;
    case 1:
        if (confirm_menu != NULL && confirm_menu->is_decided() != 0) {
            r = confirm_menu->get_selected_value();
            if (r == 0) {
                if (item_list != 0U) {
                    sel = ((TWindowMenuIconLine *)item_list)->get_cursor_value();
                    TItemData item = shop_items[sel];
                    item.id = advance_item_id_counter(local_client_id);
                    if (TCheckRoomSequence::get_item_def((uaddr)&item) != 0) {
                        item.set_stack_count(m_50);
                    }
                    try_buy_item(player, &item);
                    if (status_window != 0U) {
                        n = static_cast<TPlyItem *>(reinterpret_cast<TObjPlayer *>(player)->inventory_objects)->count_items_by_id(reinterpret_cast<saddr>(&shop_items[sel]));
                        ((TWindowSubStatusDisp *)status_window)->set_entry1_field20(n);
                    }
                    if (is_single_purchase_shop_item((u8 *)&shop_items[sel]) != 0) {
                        mark_shop_tool_sold_out(sel, sub_8022397C__15TShopWindowBaseFv(this));
                    }
                    ((TWindowMenuIconLine *)item_list)->save_cursor_selection();
                }
                ((TWindowBase *)confirm_menu)->close();
                confirm_menu = NULL;
                set_state(0);
            }
            if (r == 1) {
                ((TWindowBase *)confirm_menu)->close();
                confirm_menu = NULL;
                if (item_list != 0U) {
                    ((TWindowMenuIconLine *)item_list)->clear_decided();
                }
                set_state(1);
            }
        }
        if (confirm_menu != NULL && confirm_menu->is_cancelled() != 0) {
            ((TWindowBase *)confirm_menu)->close();
            confirm_menu = NULL;
            if (item_list != 0U) {
                ((TWindowMenuIconLine *)item_list)->clear_decided();
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
