#include "pso/item/TItemData.h"
#include "pso/misc/TWindowMenuIconLine.h"
#include "pso/misc/TWindowBase.h"
#include "types.h"
#include "pso/protocol/protocol_types.h"
#include "pso/item/TItem.h"
#include "pso/misc/TWindowAddition.h"
#include "pso/misc/TWindowMenu.h"
#include "pso/misc/TShopEquipmentListWindow.h"
#include "pso/misc/TCheckRoomSequence.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TShopArmorListWindow.h"
#include "pso/misc/TShopEquipmentSellWindow.h"
#include "pso/misc/TShopGetItemWindow.h"
#include "pso/misc/TWindowHelpItem.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowSubItem.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/player/TObjPlayer.h"

struct Base_8021B974 { char pad[0x18]; };
struct VObj_8021B974 : Base_8021B974 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
};
struct Base_8021B9AC_8021B974 { char pad[0x18]; };
struct VObj_8021B9AC_8021B974 : Base_8021B9AC_8021B974 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
};
struct Base_8021C040_8021B974 { char pad[0x18]; };
struct VObj_8021C040_8021B974 : Base_8021C040_8021B974 {
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
struct Base_8021C0D0_8021B974 { char pad[0x18]; };
struct VObj_8021C0D0_8021B974 : Base_8021C0D0_8021B974 {
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

struct RecoveredGlobal_8021C7C0___vt__24TShopEquipmentListWindow {
    s32 value;
    u8 remaining[0x2C];
};

struct Rec_8021C33C { u8 kind; u8 sub; u8 pad[0xe]; s32 price; };

struct Win_8021C33C {
    u8 pad[0x24];
    void *player;
    u8 pad28[8];
    void *list;
    u8 pad34[0x4c - 0x34];
    s32 flag;
    Rec_8021C33C recs[16];
};

struct VBase_18_a93f07 { char pad[0x18]; };

struct VObj_18_a93f07 : VBase_18_a93f07 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual s32 m4(s32, s32);
};

struct Rec_8021C408 { s32 w[4]; s32 price; };

struct Win_8021C408 {
    VObj_18_a93f07 base;
    u8 pad1c[0x24 - 0x1C];
    s32 player;
    u8 pad28[8];
    void *list;
    void *help;
    u8 pad38[0x3C - 0x38];
    void *cost;
    u8 pad40[0x44 - 0x40];
    s32 count;
    u8 pad48[0x50 - 0x48];
    Rec_8021C408 recs[16];
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

struct Rec_8021BC18 { s32 w[3]; s32 id; s32 price; };

struct Win_8021BC18 {
    u8 pad0[0x24];
    void *player;
    u8 pad28[0x2C - 0x28];
    void *card;
    void *list;
    u8 pad34[0x50 - 0x34];
    Rec_8021BC18 recs[16];
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct Rec_8021BA1C { s32 w[5]; };

struct Win_8021BA1C {
    VObj_18_a93f07 base;
    u8 pad1c[0x24 - 0x1C];
    s32 player;
    u8 pad28[4];
    void *win;
    void *list;
    u8 pad34[0x4c - 0x34];
    s32 flag;
    Rec_8021BA1C recs[16];
};

struct VBase_8021C160 { char pad[0x18]; };

struct VObj_8021C160 : VBase_8021C160 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual s32 m4(s32, s32);
};

struct Rec_8021C160 { s32 w[5]; };

struct Win_8021C160 : VObj_8021C160 {
    u8 pad1c[0x30 - 0x1C];
    void *list;
    void *help;
    u8 pad38[0x48 - 0x38];
    s32 sel;
    u8 pad4c[4];
    Rec_8021C160 recs[1];
};

extern "C" {
s32 sub_8022397C__15TShopWindowBaseFv(void *);
void *__ct__15TShopWindowBaseFv(void *arg0);
void TLobby__sub_80225238(int a0, int a1);
extern s32 __vt__24TShopEquipmentListWindow[];
extern s32 TShopEquipmentListWindow__class_name;
u8 *TShopEquipmentListWindow__ct(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
void queue_destruction__7TObjectFv(void *arg0);
int set_field_20__15TShopWindowBaseFl(void*, int);
int obj_getPtr2B0_20(u8 *p);
s32 check_equip_requirements(void *, Rec_8021C33C *, u32 *);
s32 get_cursor_value__19TWindowMenuIconLineFv(void *);
s32 get_entity_id(s32);
s32 get_shop_weapon_stock_item(void *, int, s32);
int TShopEquipmentListWindow__sub_8021C85C(int a0);
s32 get_shop_text(s32);
void *__nw__7TObjectFUl(u32);
void *__ct__15TWindowHelpItemFPvUs(void *, s32, u16);
s32 get_window_layout_position(s32);
void *create_item_list_window(s32, s32, u16);
s32 get_item_count__24TShopEquipmentSellWindowFv(void *a, s32 b);
void *create_cost_window(u16);
extern const f32 lbl_805DC6D0;
s32 advance_item_id_counter(u16);
void try_buy_item(void *, void *);
void send_6x26_unequip_item__10TObjPlayerFPvPv(void *, s32);
void send_6x25_equip_item(void *, s32, s32);
}
s32 is_single_purchase_shop_item(u8 *p);
extern "C" {
extern const s32 local_client_id;
f32 get_scale__15TShopWindowBaseFv(void *);
u32 create_yes_no_window(int, u16, int, int);
s32 sub_802239EC__13TShopSequenceFv(void *);
s32 sub_80223A48__15TShopWindowBaseFv(void *);
void play_sound_effect(int, int, int, int);
void *__dt__24TShopEquipmentListWindowFv(TShopEquipmentListWindow *arg0, s16 arg1);
s32 create_window_menu(s32 arg0, s32 arg1, s32 arg2);
s32 align_menu_entry_positions(u32);
void __dl__7TObjectFPv(void *);
void *__dt__15TShopWindowBaseFv(void *self, s16 m);
int forward_trade_action_default__16TObjCityMainWarpFPviii(void *p, int a1, int a2, int a3);

void TShopEquipmentListWindow::display_message(const char *text, s32 flags) {
    struct VObj_8021B974 *o = (struct VObj_8021B974 *)*(void **)((s8 *)this + 0x28);
    if (o != NULL) {
        o->m5();
    }
}

void TShopEquipmentListWindow::vfunc_6() {
    struct VObj_8021B9AC_8021B974 *o = (struct VObj_8021B9AC_8021B974 *)*(void **)((s8 *)this + 0x28);
    if (o != NULL) {
        o->m4();
    }
}

void TShopEquipmentListWindow::update_list(void *arg1) {
    void *v = *(void **)((s8 *)this + 0x3C);
    if (v != 0) {
        s32 n = *(s32 *)((s8 *)arg1 + 0x10);
        if (n > 0) {
            get_item_count__24TShopEquipmentSellWindowFv(v, n);
        }
    }
}

void TShopEquipmentListWindow::handle_equip_offer() {
    Win_8021BA1C *w = (Win_8021BA1C *)this;
    s32 r;
    s32 i;
    f32 sc;
    if (w->win != NULL && ((TWindowMenu *)(w->win))->is_decided() != 0) {
        r = ((TWindowMenu *)w->win)->get_selected_value();
        if (r == 0 && w->list != NULL) {
            if (w->flag != 0) {
                w->base.m4(0x18, 1);
                ((TWindowBase *)w->win)->close();
                w->win = (void *)create_yes_no_window(get_window_layout_position(0x2B), get_entity_id(w->player), 0, 0);
                sc = get_scale__15TShopWindowBaseFv(w);
                ((TWindowAddition *)((u32)w->win))->set_position_xy(get_scale__15TShopWindowBaseFv(w), sc);
                set_field_20__15TShopWindowBaseFl(w, 9);
            } else {
                Rec_8021BA1C c;
                i = get_cursor_value__19TWindowMenuIconLineFv(w->list);
                c = w->recs[i];
                c.w[3] = advance_item_id_counter(local_client_id);
                ((TItemData *)(&c))->set_stack_count(1);
                try_buy_item((void *)w->player, &c);
                ((TShopEquipmentListWindow *)w)->update_list(&w->recs[i]);
                if (is_single_purchase_shop_item((u8 *)&w->recs[i]) != 0) {
                    TLobby::clear_slot_field_f10(i, (s32)((void *)sub_8022397C__15TShopWindowBaseFv(w)));
                }
                ((TWindowBase *)w->win)->close();
                w->win = NULL;
                set_field_20__15TShopWindowBaseFl(w, 0);
            }
        }
        if (r == 1) {
            ((TWindowBase *)w->win)->close();
            w->win = NULL;
            set_field_20__15TShopWindowBaseFl(w, 0);
        }
    }
    if (w->win != NULL && ((TWindowMenu *)(w->win))->is_cancelled() != 0) {
        ((TWindowBase *)w->win)->close();
        w->win = NULL;
        set_field_20__15TShopWindowBaseFl(w, 0);
    }
}

void TShopEquipmentListWindow::handle_buy_confirm() {
    Win_8021BC18 *w = (Win_8021BC18 *)this;
    s32 r;
    if (w->card != NULL && ((TWindowMenu *)(w->card))->is_decided() != 0) {
        r = ((TWindowMenu *)w->card)->get_selected_value();
        if (r == 0) {
            if (w->list != NULL) {
                s32 i = get_cursor_value__19TWindowMenuIconLineFv(w->list);
                Rec_8021BC18 it = w->recs[i];
                VObj_18_b34251 *item;
                u32 e;
                it.id = advance_item_id_counter(local_client_id);
                ((TItemData *)(&it))->set_stack_count(1);
                try_buy_item(w->player, &it);
                item = (VObj_18_b34251 *)find_item_by_id(it.id);
                if (item != NULL && (e = (u32)((TObjPlayer *)w->player)->get_equipped_item(item->m31())) != 0) {
                    send_6x26_unequip_item__10TObjPlayerFPvPv(w->player, ((TItem *)e)->get_item_id());
                }
                send_6x25_equip_item(w->player, it.id, 0);
                update_list(&w->recs[i]);
                if (is_single_purchase_shop_item((u8 *)&w->recs[i]) != 0) {
                    TLobby::clear_slot_field_f10(i, sub_8022397C__15TShopWindowBaseFv(w));
                }
                ((TShopArmorListWindow *)(w->list))->save_cursor_selection();
            }
            ((TWindowBase *)w->card)->close();
            w->card = NULL;
            set_field_20__15TShopWindowBaseFl(w, 0);
        }
        if (r == 1) {
            if (w->list != NULL) {
                s32 i = get_cursor_value__19TWindowMenuIconLineFv(w->list);
                Rec_8021BC18 it = w->recs[i];
                it.id = advance_item_id_counter(local_client_id);
                ((TItemData *)(&it))->set_stack_count(1);
                try_buy_item(w->player, &it);
                update_list(&w->recs[i]);
                if (is_single_purchase_shop_item((u8 *)&w->recs[i]) != 0) {
                    TLobby::clear_slot_field_f10(i, sub_8022397C__15TShopWindowBaseFv(w));
                }
                ((TShopArmorListWindow *)(w->list))->save_cursor_selection();
            }
            ((TWindowBase *)w->card)->close();
            w->card = NULL;
            set_field_20__15TShopWindowBaseFl(w, 0);
        }
    }
    if (w->card != NULL && ((TWindowMenu *)(w->card))->is_cancelled() != 0) {
        if (w->list != NULL) {
            s32 i = get_cursor_value__19TWindowMenuIconLineFv(w->list);
            Rec_8021BC18 it = w->recs[i];
            it.id = advance_item_id_counter(local_client_id);
            ((TItemData *)(&it))->set_stack_count(1);
            try_buy_item(w->player, &it);
            update_list(&w->recs[i]);
            if (is_single_purchase_shop_item((u8 *)&w->recs[i]) != 0) {
                TLobby::clear_slot_field_f10(i, sub_8022397C__15TShopWindowBaseFv(w));
            }
            ((TShopArmorListWindow *)(w->list))->save_cursor_selection();
        }
        ((TWindowBase *)w->card)->close();
        w->card = NULL;
        set_field_20__15TShopWindowBaseFl(w, 0);
    }
}

s32 TShopEquipmentListWindow::open_menu_window() {
    f32 temp_f31;
    u16 temp_r31;

    if ((u32) this->m_2c == 0U) {
        temp_r31 = get_entity_id(this->m_24);
        this->m_2c = create_window_menu(get_window_layout_position(0x2B), 2, temp_r31);
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)this->m_2c, (int)(get_shop_text(4)), 6, 0);
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)this->m_2c, (int)(get_shop_text(5)), 6, 1);
        ((TWindowSubComCard *)(this->m_2c))->calc_window_size();
        align_menu_entry_positions(this->m_2c);
        ((TCheckRoomSequence *)(this->m_2c))->set_ready_flag();
        temp_f31 = get_scale__15TShopWindowBaseFv(this);
        ((TWindowAddition *)(this->m_2c))->set_position_xy(get_scale__15TShopWindowBaseFv(this), temp_f31);
    }
    set_field_20__15TShopWindowBaseFl(this, 2);
}
int TShopEquipmentListWindow::get_list_item8() { return set_field_20__15TShopWindowBaseFl(this, 8); }

s32 TShopEquipmentListWindow::handle_confirm() {
    VObj_8021C040_8021B974 *o = (VObj_8021C040_8021B974 *)this;
    if (o->m8() != 0 && (sub_80223A48__15TShopWindowBaseFv(this) != 0 || sub_802239EC__13TShopSequenceFv(this) != 0)) {
        o->m4(0xB, 1);
        ((TWindowMenuIconLine *)(this->m_30))->clear_decided();
        set_field_20__15TShopWindowBaseFl(this, 1);
    }
}

s32 TShopEquipmentListWindow::handle_select() {
    VObj_8021C0D0_8021B974 *o = (VObj_8021C0D0_8021B974 *)this;
    if (o->m8() != 0 && (sub_80223A48__15TShopWindowBaseFv(this) != 0 || sub_802239EC__13TShopSequenceFv(this) != 0)) {
        o->m4(0xB, 1);
        ((TWindowMenuIconLine *)(this->m_30))->clear_decided();
        set_field_20__15TShopWindowBaseFl(this, 1);
    }
}

struct Win_8021C33C;
void TShopEquipmentListWindow::handle_selection() {
    Win_8021C160 *w = (Win_8021C160 *)this;
    s32 i;
    if (w->list != NULL) {
        i = get_cursor_value__19TWindowMenuIconLineFv(w->list);
        if (w->help != NULL && i != w->sel) {
            ((TWindowHelpItem *)(w->help))->set_displayed_item_colored((u32)&w->recs[i]);
        }
        if (i != w->sel) {
            update_list(&w->recs[i]);
        }
        w->sel = i;
    }
    if (sub_802239EC__13TShopSequenceFv(w) != 0) {
        set_field_20__15TShopWindowBaseFl(w, 3);
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

s32 TShopEquipmentListWindow::check_purchase_eligibility() {
    Win_8021C33C *w = (Win_8021C33C *)this;
    u32 res;
    s32 i;
    Rec_8021C33C *r;
    w->flag = 0;
    if (w->list == 0) {
        return 0;
    }
    i = get_cursor_value__19TWindowMenuIconLineFv(w->list);
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
    w->flag = 1;
    return 4;
}

#pragma push
#pragma opt_common_subs off
#define W ((Win_8021C408 *)p)
void TShopEquipmentListWindow::create_buy_list_windows(void *p) {
    Rec_8021C408 tmp;
    u16 id;
    void *o;
    s32 i;
    Rec_8021C408 *r;
    s32 j;
    s32 k;
    u8 *e;
    void *c;
    W->count = TShopEquipmentListWindow__sub_8021C85C(sub_8022397C__15TShopWindowBaseFv(W));
    for (i = 0; i < W->count; i++) {
        get_shop_weapon_stock_item(&tmp, i, sub_8022397C__15TShopWindowBaseFv(W));
        ((TItemData *)(&W->recs[i]))->copy_from((TItemData *)(&tmp));
    }
    r = W->recs;
    for (j = 0; j < W->count; j++, r++) {
        if (r->price != -1) {
            r->price = TItemData::calc_price_of((TItemData *)r);
        }
    }
    if (W->list == NULL) {
        W->list = create_item_list_window(get_shop_text(0x26), W->count, get_entity_id(W->player));
    } else {
        ((TShopArmorListWindow *)(W->list))->save_cursor_selection();
        ((TWindowMenuIconLine *)(W->list))->reset_list();
    }
    if (W->list != NULL) {
        for (k = 0; k < W->count; k++) {
            e = (u8 *)W + k * 0x14;
            if (*(s32 *)(e + 0x60) != -1) {
                ((TWindowSubStatusDisp *)(W->list))->add_ground_item((s32)(e + 0x50), (s32)k);
            }
        }
        ((TWindowMenuIconLine *)W->list)->calc_content_extent();
        ((TWindowMenuIconLine *)((s32)W->list))->clear_decided();
        ((TShopArmorListWindow *)(W->list))->clamp_selection_to_valid_entry();
    }
    if (W->help == NULL) {
        o = __nw__7TObjectFUl(0xBC);
        if (o != NULL) {
            id = get_entity_id(W->player);
            o = __ct__15TWindowHelpItemFPvUs(o, get_window_layout_position(0x27), id);
        }
        W->help = o;
        if (W->help != NULL && TLobby::is_camera_ctrl_active() > 2) {
            ((TLobby *)(W->help))->set_position(lbl_805DC6D0, lbl_805DC6D0);
        }
        ((TWindowHelpItem *)(W->help))->set_displayed_item_colored((u32)W->recs);
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

void TShopEquipmentListWindow::vfunc_11() {
    u8 *arg0 = (u8 *)this;
    s32 (*temp_r12)(s32);
    switch (*(u32 *)((s8 *)arg0 + 0x20)) {
    case 0:
        TShopEquipmentListWindow::create_buy_list_windows(arg0);
        set_field_20__15TShopWindowBaseFl(arg0, 1);
        return;
    case 1:
        ((TShopEquipmentListWindow *)arg0)->handle_selection();
        return;
    case 2:
        ((TShopEquipmentListWindow *)arg0)->handle_equip_offer();
        return;
    case 5:
        ((TShopEquipmentListWindow *)arg0)->handle_select();
        return;
    case 6:
        ((TShopEquipmentListWindow *)arg0)->handle_confirm();
        return;
    case 7:
        ((s32)((TShopEquipmentListWindow *)arg0)->get_list_item8());
        return;
    case 8:
        ((TShopEquipmentListWindow *)arg0)->open_menu_window();
        return;
    case 9:
        ((TShopEquipmentListWindow *)arg0)->handle_buy_confirm();
        return;
    case 3:
    case 10:
        temp_r12 = *(s32 (**)(s32))((s8 *)arg0 + 0x190);
        if (temp_r12 != NULL) {
            temp_r12(*(s32 *)((s8 *)arg0 + 0x28));
        }
        queue_destruction__7TObjectFv((arg0));
    default:
        return;
    }
}

void *__dt__24TShopEquipmentListWindowFv(TShopEquipmentListWindow *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__24TShopEquipmentListWindow;
        if (*(void **)((s8 *)arg0 + 0x30) != NULL) { ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x30)))->close(); arg0->m_30 = 0; }
        if (*(void **)((s8 *)arg0 + 0x2C) != NULL) { ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x2C)))->close(); arg0->m_2c = 0; }
        if (*(void **)((s8 *)arg0 + 0x34) != NULL) { ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x34)))->close(); arg0->m_34 = 0; }
        if (*(void **)((s8 *)arg0 + 0x38) != NULL) { ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x38)))->close(); arg0->m_38 = 0; }
        if (*(void **)((s8 *)arg0 + 0x3C) != NULL) { ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x3C)))->close(); arg0->m_3c = 0; }
        __dt__15TShopWindowBaseFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

    extern int shop_weapon_stock_counts[];

typedef char RecoveredGlobal_8021C7C0___vt__24TShopEquipmentListWindow_size[sizeof(RecoveredGlobal_8021C7C0___vt__24TShopEquipmentListWindow) == 0x30 ? 1 : -1];
u8 *TShopEquipmentListWindow__ct(u8 *shop_equipment_list_window, s32 arg1, s32 arg2, s32 arg3) {
    s32 sp8;
    __ct__15TShopWindowBaseFv((shop_equipment_list_window));
    *(s32 **)((s8 *)shop_equipment_list_window + 0x18) = &(*(RecoveredGlobal_8021C7C0___vt__24TShopEquipmentListWindow *)&__vt__24TShopEquipmentListWindow).value;
    *(s32 *)((s8 *)shop_equipment_list_window + 0) = (s32) TShopEquipmentListWindow__class_name;
    ((TShopEquipmentListWindow *)shop_equipment_list_window)->m_24 = arg3;
    ((TShopEquipmentListWindow *)shop_equipment_list_window)->m_28 = arg2;
    ((TShopEquipmentListWindow *)shop_equipment_list_window)->m_2c = 0;
    ((TShopEquipmentListWindow *)shop_equipment_list_window)->m_30 = 0;
    ((TShopEquipmentListWindow *)shop_equipment_list_window)->m_34 = 0;
    ((TShopEquipmentListWindow *)shop_equipment_list_window)->m_38 = 0;
    ((TShopEquipmentListWindow *)shop_equipment_list_window)->m_3c = 0;
    ((TShopEquipmentListWindow *)shop_equipment_list_window)->m_40 = 0;
    ((TShopEquipmentListWindow *)shop_equipment_list_window)->m_48 = 0;
    ((TShopEquipmentListWindow *)shop_equipment_list_window)->m_4c = 0;
    ((TShopEquipmentListWindow *)shop_equipment_list_window)->m_20 = 0;
    ((TShopEquipmentListWindow *)shop_equipment_list_window)->m_190 = 0;
    ((TShopGetItemWindow *)(((TShopEquipmentListWindow *)shop_equipment_list_window)->m_24))->calc_item_count(&sp8);
    TLobby__sub_80225238((sub_8022397C__15TShopWindowBaseFv(shop_equipment_list_window)), (sp8));
    return shop_equipment_list_window;
}

int TShopEquipmentListWindow__sub_8021C85C(int a0) {  return shop_weapon_stock_counts[a0]; }
}
