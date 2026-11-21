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
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"

#pragma readonly_strings on

struct Base_8021A394 { char pad[0x18]; };
struct VObj_8021A394 : Base_8021A394 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
};
struct Base_8021A3CC_8021A394 { char pad[0x18]; };
struct VObj_8021A3CC_8021A394 : Base_8021A3CC_8021A394 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
};
struct Base_8021AA2C_8021A394 { char pad[0x18]; };
struct VObj_8021AA2C_8021A394 : Base_8021AA2C_8021A394 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(s32, s32);
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8();
};
struct Base_8021AABC_8021A394 { char pad[0x18]; };
struct VObj_8021AABC_8021A394 : Base_8021AABC_8021A394 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(s32, s32);
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8();
};

struct Rec_8021AD24 { u8 kind; u8 sub; u8 pad[0xe]; s32 price; };

struct Win_8021AD24 {
    u8 pad[0x24];
    void *player;
    u8 pad28[4];
    void *list;
    u8 pad30[0x4c - 0x30];
    Rec_8021AD24 recs[(0x1f0 - 0x4c) / 0x14];
    s32 flag;
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct VBase_18_a93f07 { char pad[0x18]; };

struct VObj_18_a93f07 : VBase_18_a93f07 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual s32 m4(s32, s32);
};

struct Rec_8021A43C { s32 w[5]; };

struct Win_8021A43C {
    VObj_18_a93f07 base;
    u8 pad1c[0x24 - 0x1C];
    s32 player;
    u8 pad28[4];
    void *list;
    void *win;
    u8 pad34[0x4c - 0x34];
    Rec_8021A43C recs[(0x1f0 - 0x4c) / 0x14];
    s32 flag;
};

struct VBase_18 { char pad[0x18]; };

struct VObj_18 : VBase_18 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual s32 m4(s32, s32);
};

struct Rec_8021AB4C { s32 w[5]; };

struct Win_8021AB4C : VObj_18 {
    u8 pad1c[0x20 - 0x1C];
    s32 f20;
    u8 pad24[0x2c - 0x24];
    void *list;
    u8 pad30[4];
    void *help;
    u8 pad38[0x48 - 0x38];
    s32 sel;
    Rec_8021AB4C recs[1];
};

struct VBase_18_b34251 { char pad[0x18]; };

struct VObj_18_b34251 : VBase_18_b34251 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual s8 m31();
};

struct Rec_8021A634 { s32 w[3]; s32 id; s32 price; };

struct Win_8021A634 {
    u8 pad0[0x24];
    saddr player;
    u8 pad28[0x2C - 0x28];
    void *list;
    void *card;
    u8 pad34[0x4C - 0x34];
    Rec_8021A634 recs[16];
};

struct Rec_8021AE18 { s32 w[4]; s32 price; };

struct Win_8021AE18 {
    VObj_18_a93f07 base;
    u8 pad1c[0x24 - 0x1C];
    s32 player;
    u8 pad28[4];
    void *list;
    u8 pad30[0x34 - 0x30];
    void *help;
    u8 pad38[0x3C - 0x38];
    void *cost;
    u8 pad40[0x44 - 0x40];
    s32 count;
    u8 pad48[0x4C - 0x48];
    Rec_8021AE18 recs[16];
};

extern "C" {
const char *TShopArmorListWindow__class_name = "TShopArmorListWindow";
int obj_getPtr2B0_20(u8 *p);
s32 check_equip_requirements(void *self, TItemData *p, s32 *out);
s32 get_entity_id(s32);
s32 advance_item_id_counter(u16);
s32 try_buy_item(int, void *);
}
s32 is_single_purchase_shop_item(u8 *p);
extern "C" {
uaddr create_yes_no_window(int, u16, int, int);
saddr get_window_layout_position(s32);
extern const s32 local_client_id;
s32 play_sound_effect(int, int, int, int);
void send_6x25_equip_item(void *arg0, s32 arg1, s32 arg2);
void handle_buy_confirm__20TShopArmorListWindowFv(Win_8021A634 *w);
s32 TLobby__sub_8021B274();
s32 get_shop_text(s32);
void *__ct__15TWindowHelpItemFPvUs(void *, s32, u16);
u8 *create_item_list_window(s32 arg0, s32 arg1, s32 arg2);
s32 sub_802239EC__13TShopSequenceFv(void *);

int forward_trade_action_default__16TObjCityMainWarpFPviii(void *p, int a1, int a2, int a3);

// Written last-to-first: the unit is built with deferred code generation (see configure.py).

TShopArmorListWindow::TShopArmorListWindow(saddr parent, s32 arg2, s32 arg3) : TShopWindowBase((TObject *)parent) {
    s32 sp8;
    this->m_name = TShopArmorListWindow__class_name;
    this->m_24 = arg3;
    this->m_28 = arg2;
    this->item_list = NULL;
    this->choice_menu = 0;
    this->help_window = NULL;
    this->m_38 = 0;
    this->cost_window = NULL;
    this->m_40 = 0;
    this->m_20 = 0;
    this->m_48 = 0;
    this->m_1f4 = 0;
    this->m_1f0 = 0;
    ((TShopGetItemWindow *)(this->m_24))->calc_item_count(&sp8);
    TLobby::set_shop_armor_list_flag(sub_8022397C(), sp8);
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
    if (m_38 != 0) {
        ((TWindowBase *)m_38)->close();
        m_38 = 0;
    }
    if (cost_window != NULL) {
        cost_window->close();
        cost_window = NULL;
    }
}

void TShopArmorListWindow::vfunc_11() {
    u8 *arg0 = (u8 *)this;
    s32 (*temp_r12)(s32);
    switch (*(u32 *)((s8 *)arg0 + 0x20)) {
    case 0:
        TShopArmorListWindow::refresh_item_list(arg0);
        ((TShopWindowBase *)arg0)->set_field_20(1);
        return;
    case 1:
        ((TShopArmorListWindow *)arg0)->handle_selection();
        return;
    case 2:
        ((TShopArmorListWindow *)arg0)->handle_equip_offer();
        return;
    case 3:
    case 10:
        temp_r12 = *(s32 (**)(s32))((s8 *)arg0 + 0x1F4);
        if (temp_r12 != NULL) {
            temp_r12(*(s32 *)((s8 *)arg0 + 0x28));
        }
        ((TObject *)arg0)->queue_destruction();
        return;
    case 5:
        ((TShopArmorListWindow *)arg0)->handle_select();
        return;
    case 6:
        ((TShopArmorListWindow *)arg0)->update();
        return;
    case 7:
        ((TShopArmorListWindow *)arg0)->advance_to_preparation_phase();
        return;
    case 8:
        ((TShopArmorListWindow *)arg0)->open_menu_window();
        return;
    case 9:
        handle_buy_confirm__20TShopArmorListWindowFv((Win_8021A634 *)(arg0));
    default:
        return;
    }
}

#pragma push
#pragma opt_common_subs off
#define W ((Win_8021AE18 *)p)
void TShopArmorListWindow::refresh_item_list(void *p) {
    Rec_8021AE18 tmp;
    void *o;
    u16 id;
    s32 base;
    s32 i;
    Rec_8021AE18 *r;
    s32 j;
    s32 k;
    u8 *e;
    void *c;
    base = ((TShopWindowBase *)W)->sub_8022397C();
    W->count = TLobby__sub_8021B274();
    for (i = 0; i < W->count; i++) {
        ((TLobby *)(&tmp))->copy_armor_shop_entry(i, base);
        ((TItemData *)(&W->recs[i]))->copy_from((TItemData *)(&tmp));
    }
    r = W->recs;
    for (j = 0; j < W->count; j++, r++) {
        if (r->price != -1) {
            r->price = TItemData::calc_price_of((TItemData *)r);
        }
    }
    if (W->list == NULL) {
        W->list = create_item_list_window(get_shop_text(0x2A), W->count, (u16)get_entity_id(W->player));
    } else {
        ((TShopArmorListWindow *)(W->list))->save_cursor_selection();
        ((TWindowMenuIconLine *)(W->list))->reset_list();
    }
    if (W->list != NULL) {
        for (k = 0; k < W->count; k++) {
            e = (u8 *)W + k * 0x14;
            if (*(s32 *)(e + 0x5C) != -1) {
                ((TWindowSubStatusDisp *)(W->list))->add_ground_item((saddr)(e + 0x4C), (s32)k);
            }
        }
        ((TWindowMenuIconLine *)W->list)->calc_content_extent();
        ((TWindowMenuIconLine *)((saddr)W->list))->clear_decided();
        ((TShopArmorListWindow *)(W->list))->clamp_selection_to_valid_entry();
    }
    if (W->help == NULL) {
        o = TObject::operator new(0xBC);
        if (o != NULL) {
            o = __ct__15TWindowHelpItemFPvUs(o, get_window_layout_position(0x27), (u16)get_entity_id(W->player));
        }
        W->help = o;
        if (W->help != NULL && TLobby::is_camera_ctrl_active() > 2) {
            ((TLobby *)(W->help))->set_position(0.75f, 0.75f);
        }
        ((TWindowHelpItem *)((saddr)W->help))->set_displayed_item_colored((uaddr)W->recs);
    }
    if (W->cost == NULL) {
        W->cost = create_cost_window((u16)get_entity_id(W->player));
        if ((c = W->cost) != NULL && W->recs[0].price > 0) {
            ((TWindowCost *)c)->set_cost(W->recs[0].price);
        }
    }
    W->base.m4(0xB, 1);
}
#undef W
#pragma pop

s32 TShopArmorListWindow::check_purchase_eligibility() {
    Win_8021AD24 *w = (Win_8021AD24 *)this;
    u32 res;
    s32 i;
    Rec_8021AD24 *r;
    w->flag = 0;
    if (w->list == 0) {
        return 0;
    }
    i = ((TWindowMenuIconLine *)(w->list))->get_cursor_value();
    if (w->recs[i].price > obj_getPtr2B0_20((u8 *)w->player)) {
        return 0;
    }
    r = &w->recs[i];
    if (((TObjPlayer *)(w->player))->can_inventory_accept_item((u8 *)r) == 0) {
        return 1;
    }
    if (check_equip_requirements((void *)w->player, (TItemData *)r, (s32 *)&res) == 0) {
        return (res & 1) ? 2 : 3;
    }
    if (w->recs[i].kind == 1 && w->recs[i].sub == 3) {
        w->flag = 0;
    } else {
        w->flag = 1;
    }
    return 4;
}

struct Win_8021AD24;
void TShopArmorListWindow::handle_selection() {
    Win_8021AB4C *w = (Win_8021AB4C *)this;
    s32 i;
    if (w->list != NULL) {
        i = ((TWindowMenuIconLine *)(w->list))->get_cursor_value();
        if (w->help != NULL && i != w->sel) {
            ((TWindowHelpItem *)((saddr)w->help))->set_displayed_item_colored((uaddr)&w->recs[i]);
        }
        if (i != w->sel) {
            update_selection(&w->recs[i]);
        }
        w->sel = i;
    }
    if (sub_802239EC__13TShopSequenceFv(w) != 0) {
        w->f20 = 3;
        play_sound_effect(0x52D01, 0, 0, 0);
        return;
    }
    if (((TShopWindowBase *)w)->sub_80223A48() != 0) {
        play_sound_effect(0x52D01, 0, 0, 0);
        switch (check_purchase_eligibility()) {
        case 0:
            w->m4(0xF, 1);
            ((TShopWindowBase *)w)->set_field_20(5);
            break;
        case 1:
            w->m4(0x19, 1);
            ((TShopWindowBase *)w)->set_field_20(6);
            break;
        case 2:
            w->m4(0x12, 1);
            ((TShopWindowBase *)w)->set_field_20(7);
            break;
        case 3:
            w->m4(0x11, 1);
            ((TShopWindowBase *)w)->set_field_20(7);
            break;
        case 4:
            ((TShopWindowBase *)w)->set_field_20(8);
            break;
        }
    }
}

void TShopArmorListWindow::handle_select() {
    if ((this->vfunc_10() != 0) && ((sub_80223A48() != 0) || (sub_802239EC__13TShopSequenceFv(this) != 0))) {
        ((VObj_8021AABC_8021A394 *)this)->m4(0xB, 1);
        ((TWindowMenuIconLine *)(this->item_list))->clear_decided();
        set_field_20(1);
    }
}

void TShopArmorListWindow::update() {
    if ((this->vfunc_10() != 0) && ((sub_80223A48() != 0) || (sub_802239EC__13TShopSequenceFv(this) != 0))) {
        ((VObj_8021AA2C_8021A394 *)this)->m4(0xB, 1);
        ((TWindowMenuIconLine *)(this->item_list))->clear_decided();
        set_field_20(1);
    }
}

void TShopArmorListWindow::advance_to_preparation_phase() { set_field_20(8); }

void TShopArmorListWindow::open_menu_window() {
    f32 scale;
    u16 temp_r31;

    if (this->choice_menu == NULL) {
        temp_r31 = get_entity_id(this->m_24);
        this->choice_menu = create_window_menu((saddr)get_window_layout_position(0x2B), 2, temp_r31);
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)this->choice_menu, (int)(get_shop_text(4)), 6, 0);
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)this->choice_menu, (int)(get_shop_text(5)), 6, 1);
        choice_menu->calc_window_size();
        align_menu_entry_positions(this->choice_menu);
        choice_menu->set_ready_flag();
        scale = get_scale();
        choice_menu->set_position_xy(get_scale(), scale);
    }
    set_field_20(2);
}

void handle_buy_confirm__20TShopArmorListWindowFv(Win_8021A634 *w) {
    saddr base = ((TShopWindowBase *)w)->sub_8022397C();
    s32 r;
    if (w->card != NULL && ((TWindowMenu *)(w->card))->is_decided() != 0) {
        r = ((TWindowMenu *)w->card)->get_selected_value();
        if (r == 0) {
            if (w->list != NULL) {
                s32 i = ((TWindowMenuIconLine *)(w->list))->get_cursor_value();
                Rec_8021A634 it = w->recs[i];
                VObj_18_b34251 *item;
                uaddr e;
                it.id = advance_item_id_counter(local_client_id);
                try_buy_item(w->player, &it);
                item = (VObj_18_b34251 *)find_item_by_id(it.id);
                if (item != NULL && (e = (uaddr)((TObjPlayer *)w->player)->get_equipped_item(item->m31())) != 0) {
                    TObjPlayer::send_6x26_unequip_item((void *)(w->player), ((TItem *)e)->get_item_id());
                }
                send_6x25_equip_item((void *)w->player, it.id, 0);
                ((TShopArmorListWindow *)w)->update_selection(&w->recs[i]);
                if (is_single_purchase_shop_item((u8 *)&w->recs[i]) != 0) {
                    TLobby::clear_shop_entry_value((s32)i, (saddr)((void *)base));
                }
                ((TShopArmorListWindow *)(w->list))->save_cursor_selection();
            }
            ((TWindowBase *)w->card)->close();
            w->card = NULL;
            ((TShopWindowBase *)w)->set_field_20(0);
        }
        if (r == 1) {
            if (w->list != NULL) {
                s32 i = ((TWindowMenuIconLine *)(w->list))->get_cursor_value();
                Rec_8021A634 it = w->recs[i];
                it.id = advance_item_id_counter(local_client_id);
                try_buy_item(w->player, &it);
                ((TShopArmorListWindow *)w)->update_selection(&w->recs[i]);
                if (is_single_purchase_shop_item((u8 *)&w->recs[i]) != 0) {
                    TLobby::clear_shop_entry_value((s32)i, (saddr)((void *)base));
                }
                ((TShopArmorListWindow *)(w->list))->save_cursor_selection();
            }
            ((TWindowBase *)w->card)->close();
            w->card = NULL;
            ((TShopWindowBase *)w)->set_field_20(0);
        }
    }
    if (w->card != NULL && ((TWindowMenu *)(w->card))->is_cancelled() != 0) {
        if (w->list != NULL) {
            s32 i = ((TWindowMenuIconLine *)(w->list))->get_cursor_value();
            Rec_8021A634 it = w->recs[i];
            it.id = advance_item_id_counter(local_client_id);
            try_buy_item(w->player, &it);
            ((TShopArmorListWindow *)w)->update_selection(&w->recs[i]);
            if (is_single_purchase_shop_item((u8 *)&w->recs[i]) != 0) {
                TLobby::clear_shop_entry_value((s32)i, (saddr)((void *)base));
            }
            ((TShopArmorListWindow *)(w->list))->save_cursor_selection();
        }
        ((TWindowBase *)w->card)->close();
        w->card = NULL;
        ((TShopWindowBase *)w)->set_field_20(0);
    }
}

void TShopArmorListWindow::handle_equip_offer() {
    Win_8021A43C *w = (Win_8021A43C *)this;
    s32 i;
    s32 r;
    f32 sc;
    if (w->win != NULL && ((TWindowMenu *)(w->win))->is_decided() != 0) {
        r = ((TWindowMenu *)w->win)->get_selected_value();
        if (r == 0 && w->list != NULL) {
            if (w->flag != 0) {
                w->base.m4(0x18, 1);
                ((TWindowBase *)w->win)->close();
                w->win = (void *)create_yes_no_window(get_window_layout_position(0x2B), get_entity_id(w->player), 0, 0);
                sc = ((TShopWindowBase *)w)->get_scale();
                ((TWindowAddition *)((uaddr)w->win))->set_position_xy(((TShopWindowBase *)w)->get_scale(), sc);
                ((TShopWindowBase *)w)->set_field_20(9);
            } else {
                Rec_8021A43C c;
                i = ((TWindowMenuIconLine *)(w->list))->get_cursor_value();
                c = w->recs[i];
                c.w[3] = advance_item_id_counter(local_client_id);
                try_buy_item(w->player, &c);
                ((TShopArmorListWindow *)w)->update_selection(&w->recs[i]);
                if (is_single_purchase_shop_item((u8 *)&w->recs[i]) != 0) {
                    TLobby::clear_shop_entry_value((s32)i, ((TShopWindowBase *)w)->sub_8022397C());
                }
                ((TShopArmorListWindow *)(w->list))->save_cursor_selection();
                ((TWindowBase *)w->win)->close();
                w->win = NULL;
                ((TShopWindowBase *)w)->set_field_20(0);
            }
        }
        if (r == 1) {
            ((TWindowBase *)w->win)->close();
            w->win = NULL;
            ((TShopWindowBase *)w)->set_field_20(0);
        }
    }
    if (w->win != NULL && ((TWindowMenu *)(w->win))->is_cancelled() != 0) {
        ((TWindowBase *)w->win)->close();
        w->win = NULL;
        ((TShopWindowBase *)w)->set_field_20(0);
    }
}

void TShopArmorListWindow::update_selection(void *arg1) {
    void *r3 = *(void **)((s8 *)this + 0x3C);
    if (r3 != 0) {
        s32 r4 = *(s32 *)((s8 *)arg1 + 0x10);
        if (r4 > 0) {
            ((TWindowCost *)r3)->set_cost(r4);
        }
    }
}

void TShopArmorListWindow::vfunc_6(s32 id, s32 flags) {
    struct VObj_8021A3CC_8021A394 *o = (struct VObj_8021A3CC_8021A394 *)*(void **)((s8 *)this + 0x28);
    if (o != NULL) {
        o->m4();
    }
}

void TShopArmorListWindow::display_message(const char *text, s32 flags) {
    struct VObj_8021A394 *o = (struct VObj_8021A394 *)*(void **)((s8 *)this + 0x28);
    if (o != NULL) {
        o->m5();
    }
}

}
