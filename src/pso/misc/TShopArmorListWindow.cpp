#include "types.h"
#include "pso/protocol/protocol_types.h"
#include "pso/item/TItem.h"
#include "pso/misc/TUnk_804CDFE8.h"
#include "pso/misc/TWindowMenu.h"
#include "pso/misc/TShopArmorListWindow.h"
#include "pso/misc/TCheckRoomSequence.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TShopEquipmentSellWindow.h"
#include "pso/misc/TShopGetItemWindow.h"
#include "pso/misc/TWindowHelpItem.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowSubItem.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/player/TObjPlayer.h"

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

struct RecoveredGlobal_8021B1CC___vt__20TShopArmorListWindow {
    s32 value;
    u8 remaining[0x2C];
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
    s32 player;
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
s32 sub_8022397C__15TShopWindowBaseFv(void *);
void *__ct__15TShopWindowBaseFv(void *arg0);
extern s32 __vt__20TShopArmorListWindow[];
extern s32 TShopArmorListWindow__class_name;
u8 *TShopArmorListWindow__ct(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
void queue_destruction__7TObjectFv(void *arg0);
int set_field_20__15TShopWindowBaseFl(void*, int);
int obj_getPtr2B0_20(u8 *p);
s32 check_equip_requirements(void *, Rec_8021AD24 *, u32 *);
s32 select_cursor_entry__22TWindowSubShortCutListFv(void *);
s32 get_entity_id(s32);
s32 advance_item_id_counter(u16);
s32 try_buy_item(int, void *);
}
s32 is_single_purchase_shop_item(u8 *p);
extern "C" {
f32 get_scale__15TShopWindowBaseFv(void *);
void TWindow__close(void *);
s32 get_selected_menu_value(void *);
u32 create_yes_no_window(int, u16, int, int);
s32 get_window_layout_position(s32);
extern const s32 local_client_id;
s32 sub_802239EC__13TShopSequenceFv(void *);
s32 sub_80223A48__15TShopWindowBaseFv(void *);
s32 play_sound_effect(int, int, int, int);
u32 get_equip_field_d04__10TObjPlayerFl(s32, s32);
void send_6x26_unequip_item__10TObjPlayerFPvPv(s32, s32);
void send_6x25_equip_item(s32, s32, s32);
void handle_buy_confirm__20TShopArmorListWindowFv(Win_8021A634 *w);
s32 TLobby__sub_8021B274();
s32 get_shop_text(s32);
void *__nw__7TObjectFUl(u32);
void *__ct__15TWindowHelpItemFPvUs(void *, s32, u16);
s32 calc_list_content_extent(void *);
u8 *create_item_list_window(s32 arg0, s32 arg1, s32 arg2);
s32 get_item_count__24TShopEquipmentSellWindowFv(void *a, s32 b);
void *create_cost_window(u16);
extern const f32 lbl_805DC6C0;
void *__dt__20TShopArmorListWindowFv(TShopArmorListWindow *arg0, s16 arg1);
s32 create_window_menu(s32 arg0, s32 arg1, s32 arg2);
s32 align_menu_entry_positions(u32);
void __dl__7TObjectFPv(void *);
void *__dt__15TShopWindowBaseFv(void *self, s16 m);
int forward_trade_action_default__16TObjCityMainWarpFPviii(void *p, int a1, int a2, int a3);

void TShopArmorListWindow::vfunc_7() {
    struct VObj_8021A394 *o = (struct VObj_8021A394 *)*(void **)((s8 *)this + 0x28);
    if (o != NULL) {
        o->m5();
    }
}

void TShopArmorListWindow::vfunc_6() {
    struct VObj_8021A3CC_8021A394 *o = (struct VObj_8021A3CC_8021A394 *)*(void **)((s8 *)this + 0x28);
    if (o != NULL) {
        o->m4();
    }
}

void TShopArmorListWindow::update_selection(void *arg1) {
    void *r3 = *(void **)((s8 *)this + 0x3C);
    if (r3 != 0) {
        s32 r4 = *(s32 *)((s8 *)arg1 + 0x10);
        if (r4 > 0) {
            get_item_count__24TShopEquipmentSellWindowFv(r3, r4);
        }
    }
}

void TShopArmorListWindow::handle_equip_offer() {
    Win_8021A43C *w = (Win_8021A43C *)this;
    s32 i;
    s32 r;
    f32 sc;
    if (w->win != NULL && ((TWindowMenu *)(w->win))->is_visible() != 0) {
        r = get_selected_menu_value(w->win);
        if (r == 0 && w->list != NULL) {
            if (w->flag != 0) {
                w->base.m4(0x18, 1);
                TWindow__close(w->win);
                w->win = (void *)create_yes_no_window(get_window_layout_position(0x2B), get_entity_id(w->player), 0, 0);
                sc = get_scale__15TShopWindowBaseFv(w);
                ((TUnk_804CDFE8 *)((u32)w->win))->set_position_xy(get_scale__15TShopWindowBaseFv(w), sc);
                set_field_20__15TShopWindowBaseFl(w, 9);
            } else {
                Rec_8021A43C c;
                i = select_cursor_entry__22TWindowSubShortCutListFv(w->list);
                c = w->recs[i];
                c.w[3] = advance_item_id_counter(local_client_id);
                try_buy_item(w->player, &c);
                ((TShopArmorListWindow *)w)->update_selection(&w->recs[i]);
                if (is_single_purchase_shop_item((u8 *)&w->recs[i]) != 0) {
                    TLobby::clear_shop_entry_value((s32)i, (s32)((void *)sub_8022397C__15TShopWindowBaseFv(w)));
                }
                ((TShopArmorListWindow *)(w->list))->save_cursor_selection();
                TWindow__close(w->win);
                w->win = NULL;
                set_field_20__15TShopWindowBaseFl(w, 0);
            }
        }
        if (r == 1) {
            TWindow__close(w->win);
            w->win = NULL;
            set_field_20__15TShopWindowBaseFl(w, 0);
        }
    }
    if (w->win != NULL && ((TWindowSubComCard *)(w->win))->get_status_flag() != 0) {
        TWindow__close(w->win);
        w->win = NULL;
        set_field_20__15TShopWindowBaseFl(w, 0);
    }
}

void handle_buy_confirm__20TShopArmorListWindowFv(Win_8021A634 *w) {
    s32 base = sub_8022397C__15TShopWindowBaseFv(w);
    s32 r;
    if (w->card != NULL && ((TWindowMenu *)(w->card))->is_visible() != 0) {
        r = get_selected_menu_value(w->card);
        if (r == 0) {
            if (w->list != NULL) {
                s32 i = select_cursor_entry__22TWindowSubShortCutListFv(w->list);
                Rec_8021A634 it = w->recs[i];
                VObj_18_b34251 *item;
                u32 e;
                it.id = advance_item_id_counter(local_client_id);
                try_buy_item(w->player, &it);
                item = (VObj_18_b34251 *)find_item_by_id(it.id);
                if (item != NULL && (e = get_equip_field_d04__10TObjPlayerFl(w->player, item->m31())) != 0) {
                    send_6x26_unequip_item__10TObjPlayerFPvPv(w->player, ((TItem *)e)->get_item_id());
                }
                send_6x25_equip_item(w->player, it.id, 0);
                ((TShopArmorListWindow *)w)->update_selection(&w->recs[i]);
                if (is_single_purchase_shop_item((u8 *)&w->recs[i]) != 0) {
                    TLobby::clear_shop_entry_value((s32)i, (s32)((void *)base));
                }
                ((TShopArmorListWindow *)(w->list))->save_cursor_selection();
            }
            TWindow__close(w->card);
            w->card = NULL;
            set_field_20__15TShopWindowBaseFl(w, 0);
        }
        if (r == 1) {
            if (w->list != NULL) {
                s32 i = select_cursor_entry__22TWindowSubShortCutListFv(w->list);
                Rec_8021A634 it = w->recs[i];
                it.id = advance_item_id_counter(local_client_id);
                try_buy_item(w->player, &it);
                ((TShopArmorListWindow *)w)->update_selection(&w->recs[i]);
                if (is_single_purchase_shop_item((u8 *)&w->recs[i]) != 0) {
                    TLobby::clear_shop_entry_value((s32)i, (s32)((void *)base));
                }
                ((TShopArmorListWindow *)(w->list))->save_cursor_selection();
            }
            TWindow__close(w->card);
            w->card = NULL;
            set_field_20__15TShopWindowBaseFl(w, 0);
        }
    }
    if (w->card != NULL && ((TWindowSubComCard *)(w->card))->get_status_flag() != 0) {
        if (w->list != NULL) {
            s32 i = select_cursor_entry__22TWindowSubShortCutListFv(w->list);
            Rec_8021A634 it = w->recs[i];
            it.id = advance_item_id_counter(local_client_id);
            try_buy_item(w->player, &it);
            ((TShopArmorListWindow *)w)->update_selection(&w->recs[i]);
            if (is_single_purchase_shop_item((u8 *)&w->recs[i]) != 0) {
                TLobby::clear_shop_entry_value((s32)i, (s32)((void *)base));
            }
            ((TShopArmorListWindow *)(w->list))->save_cursor_selection();
        }
        TWindow__close(w->card);
        w->card = NULL;
        set_field_20__15TShopWindowBaseFl(w, 0);
    }
}

s32 TShopArmorListWindow::open_menu_window() {
    f32 temp_f31;
    u16 temp_r31;

    if ((u32) this->m_30 == 0U) {
        temp_r31 = get_entity_id(this->m_24);
        this->m_30 = create_window_menu(get_window_layout_position(0x2B), 2, temp_r31);
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)this->m_30, (int)(get_shop_text(4)), 6, 0);
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)this->m_30, (int)(get_shop_text(5)), 6, 1);
        ((TWindowSubComCard *)(this->m_30))->calc_window_size();
        align_menu_entry_positions(this->m_30);
        ((TCheckRoomSequence *)(this->m_30))->set_ready_flag();
        temp_f31 = get_scale__15TShopWindowBaseFv(this);
        ((TUnk_804CDFE8 *)(this->m_30))->set_position_xy(get_scale__15TShopWindowBaseFv(this), temp_f31);
    }
    set_field_20__15TShopWindowBaseFl(this, 2);
}
int TShopArmorListWindow::advance_to_preparation_phase() { return set_field_20__15TShopWindowBaseFl(this, 8); }

s32 TShopArmorListWindow::update() {
    if ((this->vfunc_10() != 0) && ((sub_80223A48__15TShopWindowBaseFv(this) != 0) || (sub_802239EC__13TShopSequenceFv(this) != 0))) {
        ((VObj_8021AA2C_8021A394 *)this)->m4(0xB, 1);
        ((TWindowSubItem *)(this->m_2c))->clear_selected_and_update_entry();
        set_field_20__15TShopWindowBaseFl(this, 1);
    }
}

s32 TShopArmorListWindow::handle_select() {
    if ((this->vfunc_10() != 0) && ((sub_80223A48__15TShopWindowBaseFv(this) != 0) || (sub_802239EC__13TShopSequenceFv(this) != 0))) {
        ((VObj_8021AABC_8021A394 *)this)->m4(0xB, 1);
        ((TWindowSubItem *)(this->m_2c))->clear_selected_and_update_entry();
        set_field_20__15TShopWindowBaseFl(this, 1);
    }
}

struct Win_8021AD24;
void TShopArmorListWindow::handle_selection() {
    Win_8021AB4C *w = (Win_8021AB4C *)this;
    s32 i;
    if (w->list != NULL) {
        i = select_cursor_entry__22TWindowSubShortCutListFv(w->list);
        if (w->help != NULL && i != w->sel) {
            ((TWindowHelpItem *)((int)w->help))->set_displayed_item_colored((u32)&w->recs[i]);
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
    if (sub_80223A48__15TShopWindowBaseFv(w) != 0) {
        play_sound_effect(0x52D01, 0, 0, 0);
        switch (check_purchase_eligibility()) {
        case 0:
            w->m4(0xF, 1);
            set_field_20__15TShopWindowBaseFl(w, 5);
            break;
        case 1:
            w->m4(0x19, 1);
            set_field_20__15TShopWindowBaseFl(w, 6);
            break;
        case 2:
            w->m4(0x12, 1);
            set_field_20__15TShopWindowBaseFl(w, 7);
            break;
        case 3:
            w->m4(0x11, 1);
            set_field_20__15TShopWindowBaseFl(w, 7);
            break;
        case 4:
            set_field_20__15TShopWindowBaseFl(w, 8);
            break;
        }
    }
}

s32 TShopArmorListWindow::check_purchase_eligibility() {
    Win_8021AD24 *w = (Win_8021AD24 *)this;
    u32 res;
    s32 i;
    Rec_8021AD24 *r;
    w->flag = 0;
    if (w->list == 0) {
        return 0;
    }
    i = select_cursor_entry__22TWindowSubShortCutListFv(w->list);
    if (w->recs[i].price > obj_getPtr2B0_20((u8 *)w->player)) {
        return 0;
    }
    r = &w->recs[i];
    if (((TObjPlayer *)(w->player))->can_inventory_accept_item((u8 *)r) == 0) {
        return 1;
    }
    if (check_equip_requirements(w->player, r, &res) == 0) {
        return (res & 1) ? 2 : 3;
    }
    if (w->recs[i].kind == 1 && w->recs[i].sub == 3) {
        w->flag = 0;
    } else {
        w->flag = 1;
    }
    return 4;
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
    base = sub_8022397C__15TShopWindowBaseFv(W);
    W->count = TLobby__sub_8021B274();
    for (i = 0; i < W->count; i++) {
        ((TLobby *)(&tmp))->copy_armor_shop_entry(i, base);
        ((ItemData *)(&W->recs[i]))->copy_from((ItemData *)(&tmp));
    }
    r = W->recs;
    for (j = 0; j < W->count; j++, r++) {
        if (r->price != -1) {
            r->price = ((TShopEquipmentSellWindow *)r)->get_item_price_if_valid();
        }
    }
    if (W->list == NULL) {
        W->list = create_item_list_window(get_shop_text(0x2A), W->count, (u16)get_entity_id(W->player));
    } else {
        ((TShopArmorListWindow *)(W->list))->save_cursor_selection();
        ((TShopArmorListWindow *)(W->list))->reset_list();
    }
    if (W->list != NULL) {
        for (k = 0; k < W->count; k++) {
            e = (u8 *)W + k * 0x14;
            if (*(s32 *)(e + 0x5C) != -1) {
                ((TWindowSubStatusDisp *)(W->list))->add_ground_item((s32)(e + 0x4C), (s32)k);
            }
        }
        calc_list_content_extent(W->list);
        ((TWindowSubItem *)((s32)W->list))->clear_selected_and_update_entry();
        ((TShopArmorListWindow *)(W->list))->clamp_selection_to_valid_entry();
    }
    if (W->help == NULL) {
        o = __nw__7TObjectFUl(0xBC);
        if (o != NULL) {
            o = __ct__15TWindowHelpItemFPvUs(o, get_window_layout_position(0x27), (u16)get_entity_id(W->player));
        }
        W->help = o;
        if (W->help != NULL && TLobby::is_camera_ctrl_active() > 2) {
            ((TLobby *)(W->help))->set_position(lbl_805DC6C0, lbl_805DC6C0);
        }
        ((TWindowHelpItem *)((int)W->help))->set_displayed_item_colored((u32)W->recs);
    }
    if (W->cost == NULL) {
        W->cost = create_cost_window(get_entity_id(W->player));
        if ((c = W->cost) != NULL && W->recs[0].price > 0) {
            get_item_count__24TShopEquipmentSellWindowFv(c, W->recs[0].price);
        }
    }
    W->base.m4(0xB, 1);
}
#undef W
#pragma pop

void TShopArmorListWindow::vfunc_11() {
    u8 *arg0 = (u8 *)this;
    s32 (*temp_r12)(s32);
    switch (*(u32 *)((s8 *)arg0 + 0x20)) {
    case 0:
        TShopArmorListWindow::refresh_item_list(arg0);
        set_field_20__15TShopWindowBaseFl(arg0, 1);
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
        queue_destruction__7TObjectFv((arg0));
        return;
    case 5:
        ((TShopArmorListWindow *)arg0)->handle_select();
        return;
    case 6:
        ((TShopArmorListWindow *)arg0)->update();
        return;
    case 7:
        ((s32)((TShopArmorListWindow *)arg0)->advance_to_preparation_phase());
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

void *__dt__20TShopArmorListWindowFv(TShopArmorListWindow *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__20TShopArmorListWindow;
        if (*(void **)((s8 *)arg0 + 0x2C) != NULL) { TWindow__close(*(void **)((s8 *)arg0 + 0x2C)); arg0->m_2c = 0; }
        if (*(void **)((s8 *)arg0 + 0x30) != NULL) { TWindow__close(*(void **)((s8 *)arg0 + 0x30)); arg0->m_30 = 0; }
        if (*(void **)((s8 *)arg0 + 0x34) != NULL) { TWindow__close(*(void **)((s8 *)arg0 + 0x34)); arg0->m_34 = 0; }
        if (*(void **)((s8 *)arg0 + 0x38) != NULL) { TWindow__close(*(void **)((s8 *)arg0 + 0x38)); arg0->m_38 = 0; }
        if (*(void **)((s8 *)arg0 + 0x3C) != NULL) { TWindow__close(*(void **)((s8 *)arg0 + 0x3C)); arg0->m_3c = 0; }
        __dt__15TShopWindowBaseFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_8021B1CC___vt__20TShopArmorListWindow_size[sizeof(RecoveredGlobal_8021B1CC___vt__20TShopArmorListWindow) == 0x30 ? 1 : -1];
u8 *TShopArmorListWindow__ct(u8 *shop_armor_list_window, s32 arg1, s32 arg2, s32 arg3) {
    s32 sp8;
    __ct__15TShopWindowBaseFv((shop_armor_list_window));
    *(s32 **)((s8 *)shop_armor_list_window + 0x18) = &(*(RecoveredGlobal_8021B1CC___vt__20TShopArmorListWindow *)&__vt__20TShopArmorListWindow).value;
    *(s32 *)((s8 *)shop_armor_list_window + 0) = (s32) TShopArmorListWindow__class_name;
    ((TShopArmorListWindow *)shop_armor_list_window)->m_24 = arg3;
    ((TShopArmorListWindow *)shop_armor_list_window)->m_28 = arg2;
    ((TShopArmorListWindow *)shop_armor_list_window)->m_2c = 0;
    ((TShopArmorListWindow *)shop_armor_list_window)->m_30 = 0;
    ((TShopArmorListWindow *)shop_armor_list_window)->m_34 = 0;
    ((TShopArmorListWindow *)shop_armor_list_window)->m_38 = 0;
    ((TShopArmorListWindow *)shop_armor_list_window)->m_3c = 0;
    ((TShopArmorListWindow *)shop_armor_list_window)->m_40 = 0;
    ((TShopArmorListWindow *)shop_armor_list_window)->m_20 = 0;
    ((TShopArmorListWindow *)shop_armor_list_window)->m_48 = 0;
    ((TShopArmorListWindow *)shop_armor_list_window)->m_1f4 = 0;
    ((TShopArmorListWindow *)shop_armor_list_window)->m_1f0 = 0;
    ((TShopGetItemWindow *)(((TShopArmorListWindow *)shop_armor_list_window)->m_24))->calc_item_count(&sp8);
    TLobby::set_shop_armor_list_flag((int)((void *) (sub_8022397C__15TShopWindowBaseFv(shop_armor_list_window))), sp8);
    return shop_armor_list_window;
}
}
