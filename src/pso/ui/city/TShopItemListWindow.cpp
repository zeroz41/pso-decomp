#define TOBJECT_OUT_OF_LINE_HELPERS
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

#include "types.h"
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


#pragma readonly_strings on

struct Base_8021F134 { char pad[0x18]; };
struct VObj_8021F134 : Base_8021F134 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
};
struct Base_8021F16C_8021F134 { char pad[0x18]; };
struct VObj_8021F16C_8021F134 : Base_8021F16C_8021F134 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
};
struct Base_8021F678_8021F134 { char pad[0x18]; };
struct VObj_8021F678_8021F134 : Base_8021F678_8021F134 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(int, int);
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual int  m8();
};
struct Base_8021F708_8021F134 { char pad[0x18]; };
struct VObj_8021F708_8021F134 : Base_8021F708_8021F134 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(int, int);
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual int  m8();
};

struct VBase_18_a93f07 { char pad[0x18]; };

struct VObj_18_a93f07 : VBase_18_a93f07 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual s32 m4(s32, s32);
};

struct Rec_8021F798 { s32 w[4]; s32 qty; };

struct Win_8021F798 {
    VObj_18_a93f07 base;
    u8 pad1c[0x24 - 0x1C];
    u8 *player;
    void *list;
    u8 pad2c[0x38 - 0x2C];
    void *help;
    void *status;
    void *sell;
    u8 pad44[0x54 - 0x44];
    s32 cur;
    Rec_8021F798 recs[16];
};

struct Rec_8021F964 { s32 w[4]; s32 qty; };

struct Win_8021F964 {
    u8 pad0[0x24];
    saddr player;
    void *list;
    u8 pad2c[0x58 - 0x2C];
    Rec_8021F964 recs[16];
};

struct Win_8021F1A4 {
    u8 pad0[0x58];
    TItemData recs[16];
};

struct Rec_8021F9EC { s32 w[4]; s32 price; };

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
    u8 pad4c[0x58 - 0x4C];
    Rec_8021F9EC recs[16];
};

// Favoured grind type per section ID (-1: none), indexed by the player's section ID in
// roll_shop_weapon_grind and TLobby::is_slot_match.
s32 section_id_favored_grind_table[10] = {9, 7, 2, 4, 8, 10, -1, 3, -1, 5};

extern "C" {
s32 sub_8022397C__15TShopWindowBaseFv(void *);
const char *TShopItemListWindow__class_name = "TShopItemListWindow";
s32 sub_802239EC__13TShopSequenceFv(void *);
s32 play_sound_effect(int, int, int, int);
s32 get_item_count__24TShopEquipmentSellWindowFv(void *a, s32 b);
int obj_getPtr2B0_20(u8 *p);
s32 get_entity_id(void *);
s32 TShopItemTecSequence__sub_8021FE6C();
s32 get_shop_text(int);
void *__ct__15TWindowHelpItemFPvUs(void *, s32, u16);
s32 get_window_layout_position(int);
void *create_window_quantity(u16);
void *create_item_list_window(s32, s32, u16);
void *create_cost_window(u16);
s32 align_menu_entry_positions(u32);
s32 try_buy_item(s32 arg0, void *item);

}

TShopItemListWindow::TShopItemListWindow(s32 parent, s32 arg2, s32 arg3) : TShopWindowBase((TObject *)parent) {
    s32 sp8;
    this->m_name = TShopItemListWindow__class_name;
    this->m_24 = arg3;
    this->m_2c = arg2;
    this->item_list = 0;
    this->confirm_menu = 0;
    this->quantity_input = 0;
    this->help_window = 0;
    this->status_window = 0;
    this->cost_window = 0;
    this->m_44 = 0;
    this->m_50 = 0;
    this->m_20 = 0;
    this->m_1c0 = 0;
    this->m_4c = 0;
    this->m_54 = 0;
    ((TShopGetItemWindow *)(this->m_24))->calc_item_count(&sp8);
    TLobby::set_6264_and_call_2244B0((saddr)((void *) (sub_8022397C__15TShopWindowBaseFv(((u8 *)this)))), sp8);
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
        ((TShopWindowBase *)arg0)->set_field_20(1);
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
    Rec_8021F9EC tmp;
    s32 i;
    Rec_8021F9EC *r;
    s32 j;
    void *o;
    u8 *e;
    s32 n;
    void *c;
    ((TShopWindowBase *)W)->sub_8022397C();
    W->count = TShopItemTecSequence__sub_8021FE6C();
    for (i = 0; i < W->count; i++) {
        ((TLobby *)(&tmp))->copy_shop_item_entry(i, sub_8022397C__15TShopWindowBaseFv(W));
        ((TItemData *)(&W->recs[i]))->copy_from((TItemData *)(&tmp));
    }
    r = W->recs;
    for (j = 0; j < W->count; j++, r++) {
        if (r->price != -1) {
            r->price = TItemData::calc_price_of((TItemData *)r);
        }
    }
    if (W->list == NULL) {
        W->list = create_item_list_window(get_shop_text(0x2D), W->count, get_entity_id(W->player));
    } else {
        ((TWindowMenuIconLine *)(W->list))->reset_list();
    }
    if (W->list != NULL) {
        for (i = 0; i < W->count; i++) {
            e = (u8 *)W + i * 0x14;
            if (*(s32 *)(e + 0x68) != -1) {
                ((TWindowSubStatusDisp *)(W->list))->add_ground_item((saddr)(e + 0x58), (s32)i);
            }
        }
        ((TWindowMenuIconLine *)W->list)->calc_content_extent();
        ((TWindowMenuIconLine *)((saddr)W->list))->clear_decided();
        ((TShopArmorListWindow *)(W->list))->clamp_selection_to_valid_entry();
    }
    if (W->help == NULL) {
        o = TObject::operator new(0xBC);
        if (o != NULL) {
            o = __ct__15TWindowHelpItemFPvUs(o, get_window_layout_position(0x27), get_entity_id(W->player));
        }
        W->help = o;
        if (W->help != NULL && TLobby::is_camera_ctrl_active() > 2) {
            ((TLobby *)(W->help))->set_position(0.75f, 0.75f);
        }
        ((TWindowHelpItem *)(W->help))->set_displayed_item_colored((uaddr)W->recs);
    }
    if (W->status == NULL) {
        W->status = create_window_quantity(((TShopSequence *)W)->get_child_field1c());
        n = ((TObjPlayer *)(*(saddr *)(W->player + 0xD00)))->count_items_by_id((saddr)W->recs);
        ((TWindowSubStatusDisp *)(W->status))->set_entry1_field20(n);
    }
    if (W->cost == NULL) {
        W->cost = create_cost_window(get_entity_id(W->player));
        if ((c = W->cost) != NULL && W->recs[0].price > 0) {
            get_item_count__24TShopEquipmentSellWindowFv(c, W->recs[0].price);
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
    if (self->recs[sel].qty > meseta) {
        return 0;
    }
    if (((TObjPlayer *)(self->player))->can_inventory_accept_item((u8 *)&self->recs[sel]) == 0) {
        return 1;
    }
    return 3;
}

#define W ((Win_8021F798 *)p)
s32 TShopItemListWindow::handle_tool_list_select(void *p) {
    s32 i;
    s32 n;
    u8 *e;
    if (W->list != NULL) {
        i = ((TWindowMenuIconLine *)(W->list))->get_cursor_value();
        if (W->help != NULL && i != W->cur) {
            ((TWindowHelpItem *)(W->help))->set_displayed_item_colored((uaddr)&W->recs[i]);
        }
        if (W->status != NULL && i != W->cur) {
            n = ((TObjPlayer *)(*(saddr *)(W->player + 0xD00)))->count_items_by_id((saddr)&W->recs[i]);
            ((TWindowSubStatusDisp *)(W->status))->set_entry1_field20(n);
        }
        if (W->sell != NULL && i != W->cur && (e = (u8 *)W + i * 0x14, *(s32 *)(e + 0x68) > 0)) {
            get_item_count__24TShopEquipmentSellWindowFv(W->sell, *(s32 *)(e + 0x68));
        }
        W->cur = i;
    }
    if (sub_802239EC__13TShopSequenceFv(W) != 0) {
        *(s32 *)((u8 *)W + 0x20) = 3;
        play_sound_effect(0x52D01, 0, 0, 0);
        return;
    }
    if (((TShopWindowBase *)W)->sub_80223A48() != 0) {
        play_sound_effect(0x52D01, 0, 0, 0);
        switch (((TShopItemListWindow *)W)->check_purchase_eligibility()) {
        case 0:
            W->base.m4(0xF, 1);
            ((TShopWindowBase *)W)->set_field_20(5);
            break;
        case 1:
            W->base.m4(0x19, 1);
            ((TShopWindowBase *)W)->set_field_20(6);
            break;
        case 2:
            break;
        case 3:
            ((TShopWindowBase *)W)->set_field_20(7);
            break;
        }
    }
}
#undef W

s32 TShopItemListWindow::update() {
    VObj_8021F708_8021F134 *o = (VObj_8021F708_8021F134 *)this;
    if (o->m8() != 0 && (sub_80223A48() != 0 || sub_802239EC__13TShopSequenceFv(this) != 0)) {
        o->m4(0xB, 1);
        ((TWindowMenuIconLine *)(this->item_list))->clear_decided();
        set_field_20(1);
    }
}

s32 TShopItemListWindow::handle_confirm() {
    VObj_8021F678_8021F134 *o = (VObj_8021F678_8021F134 *)this;
    if (o->m8() != 0 && (sub_80223A48() != 0 || sub_802239EC__13TShopSequenceFv(this) != 0)) {
        o->m4(0xB, 1);
        ((TWindowMenuIconLine *)(this->item_list))->clear_decided();
        set_field_20(1);
    }
}

void TShopItemListWindow::prepare_tool_purchase() {
    Win_8021F9EC *self = (Win_8021F9EC *)this;
    s32 sel;
    s32 room;
    s32 count;

    if (self->list != NULL) {
        sel = ((TWindowMenuIconLine *)self->list)->get_cursor_value();
        room = ((TObjPlayer *)self->player)->can_inventory_accept_item((u8 *)&self->recs[sel]);
        count = obj_getPtr2B0_20(self->player) / self->recs[sel].price;
        if (count > room) {
            count = room;
        }
        if (count > 1) {
            quantity_input = (uaddr)new TWindowInputNumber((void *)get_window_layout_position(0x2B), 1, count, 1, ((TShopSequence *)this)->get_child_field1c());
            if (quantity_input != 0U && TLobby::is_camera_ctrl_active() > 2) {
                ((TCheckRoomSequence *)quantity_input)->set_position(0.75f, 0.75f);
            }
            m_4c = 0;
            set_field_20(2);
            return;
        }
        confirm_menu = create_window_menu(get_window_layout_position(0x2B), 2, (u16)get_entity_id((void *)m_24));
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)confirm_menu, get_shop_text(4), 6, 0);
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)confirm_menu, get_shop_text(5), 6, 1);
        ((TWindowSubComCard *)confirm_menu)->calc_window_size();
        align_menu_entry_positions(confirm_menu);
        ((TCheckRoomSequence *)confirm_menu)->set_ready_flag();
        f32 scale = get_scale();
        ((TWindowAddition *)confirm_menu)->set_position_xy(get_scale(), scale);
        m_50 = 1;
        m_4c = 1;
        set_field_20(2);
    }
}

void TShopItemListWindow::handle_amount_confirm() {
    Win_8021F1A4 *self = (Win_8021F1A4 *)this;
    s32 r;
    s32 sel;
    s32 n;

    switch (m_4c) {
    case 0:
        if (quantity_input != 0U && ((TWindowInputNumber *)quantity_input)->is_confirmed() != 0) {
            if (confirm_menu == 0U) {
                confirm_menu = create_window_menu(get_window_layout_position(0x2B), 2, (u16)get_entity_id((void *)m_24));
                forward_trade_action_default__16TObjCityMainWarpFPviii((void *)confirm_menu, get_shop_text(4), 6, 0);
                forward_trade_action_default__16TObjCityMainWarpFPviii((void *)confirm_menu, get_shop_text(5), 6, 1);
                ((TWindowSubComCard *)confirm_menu)->calc_window_size();
                align_menu_entry_positions(confirm_menu);
                ((TCheckRoomSequence *)confirm_menu)->set_ready_flag();
                f32 scale = get_scale();
                ((TWindowAddition *)confirm_menu)->set_position_xy(get_scale(), scale);
            }
            m_50 = ((TShopEquipmentSellWindow *)quantity_input)->get_result();
            ((TWindowBase *)quantity_input)->close();
            quantity_input = 0U;
            m_4c = 1;
        }
        if (quantity_input != 0U && ((TShopEquipmentSellWindow *)quantity_input)->is_confirmed() != 0) {
            ((TWindowBase *)quantity_input)->close();
            quantity_input = 0U;
            if (item_list != 0U) {
                ((TWindowMenuIconLine *)item_list)->clear_decided();
            }
            set_field_20(1);
        }
        break;
    case 1:
        if (confirm_menu != 0U && ((TWindowMenu *)confirm_menu)->is_decided() != 0) {
            r = ((TWindowMenu *)confirm_menu)->get_selected_value();
            if (r == 0) {
                if (item_list != 0U) {
                    sel = ((TWindowMenuIconLine *)item_list)->get_cursor_value();
                    TItemData item = self->recs[sel];
                    item.id = advance_item_id_counter(local_client_id);
                    if (TCheckRoomSequence::get_item_def((uaddr)&item) != 0) {
                        item.set_stack_count(m_50);
                    }
                    try_buy_item(m_24, &item);
                    if (status_window != 0U) {
                        n = ((TObjPlayer *)(*(saddr *)(m_24 + 0xD00)))->count_items_by_id((saddr)&self->recs[sel]);
                        ((TWindowSubStatusDisp *)status_window)->set_entry1_field20(n);
                    }
                    if (is_single_purchase_shop_item((u8 *)&self->recs[sel]) != 0) {
                        mark_shop_tool_sold_out(sel, sub_8022397C__15TShopWindowBaseFv(this));
                    }
                    ((TShopArmorListWindow *)item_list)->save_cursor_selection();
                }
                ((TWindowBase *)confirm_menu)->close();
                confirm_menu = 0U;
                set_field_20(0);
            }
            if (r == 1) {
                ((TWindowBase *)confirm_menu)->close();
                confirm_menu = 0U;
                if (item_list != 0U) {
                    ((TWindowMenuIconLine *)item_list)->clear_decided();
                }
                set_field_20(1);
            }
        }
        if (confirm_menu != 0U && ((TWindowMenu *)confirm_menu)->is_cancelled() != 0) {
            ((TWindowBase *)confirm_menu)->close();
            confirm_menu = 0U;
            if (item_list != 0U) {
                ((TWindowMenuIconLine *)item_list)->clear_decided();
            }
            set_field_20(1);
        }
        break;
    }
}

void TShopItemListWindow::vfunc_6() {
    struct VObj_8021F16C_8021F134 *temp_r3;

    temp_r3 = (struct VObj_8021F16C_8021F134 *)*(void **)((s8 *)this + 0x2C);
    if (temp_r3 != NULL) {
        temp_r3->m4();
    }
}

void TShopItemListWindow::display_message(const char *text, s32 flags) {
    struct VObj_8021F134 *temp_r3;

    temp_r3 = (struct VObj_8021F134 *)*(void **)((s8 *)this + 0x2C);
    if (temp_r3 != NULL) {
        temp_r3->m5();
    }
}
