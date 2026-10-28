#include "types.h"
#include "pso/protocol/protocol_types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TShopSequence.h"
#include "pso/misc/TShopItemListWindow.h"
#include "pso/TShopWindowBase.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TShopArmorListWindow.h"
#include "pso/misc/TShopEquipmentSellWindow.h"
#include "pso/misc/TShopGetItemWindow.h"
#include "pso/misc/TWindowHelpItem.h"
#include "pso/misc/TWindowSubItem.h"
#include "pso/misc/TWindowSubStatusDisp.h"

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

struct RecoveredGlobal_8021FDC8___vt__19TShopItemListWindow {
    s32 value;
    u8 remaining[0x2C];
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
    s32 player;
    void *list;
    u8 pad2c[0x58 - 0x2C];
    Rec_8021F964 recs[16];
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

extern "C" {
s32 sub_8022397C__15TShopWindowBaseFv(void *);
void *__ct__15TShopWindowBaseFv(void *arg0);
extern s32 __vt__19TShopItemListWindow[];
extern s32 TShopItemListWindow__class_name;
u8 *TShopItemListWindow__ct(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
void queue_destruction__7TObjectFv(void *arg0);
s32 sub_802239EC__13TShopSequenceFv(void *);
s32 sub_80223A48__15TShopWindowBaseFv(void *);
s32 play_sound_effect(int, int, int, int);
s32 select_cursor_entry__22TWindowSubShortCutListFv(void *);
s32 get_item_count__24TShopEquipmentSellWindowFv(void *a, s32 b);
int obj_getPtr2B0_20(u8 *p);
s32 get_entity_id(void *);
s32 TShopItemTecSequence__sub_8021FE6C();
s32 get_shop_text(int);
void *__nw__7TObjectFUl(u32);
void *__ct__15TWindowHelpItemFPvUs(void *, s32, u16);
s32 calc_list_content_extent(void *);
s32 get_window_layout_position(int);
void *create_window_quantity(u16);
void *create_item_list_window(s32, s32, u16);
void *create_cost_window(u16);
extern const f32 lbl_805DC6F8;
void *__dt__19TShopItemListWindowFv(TShopItemListWindow *arg0, s16 arg1);
void TWindow__close(u8 *arg0);
void __dl__7TObjectFPv(void *);
void *__dt__15TShopWindowBaseFv(void *self, s16 m);

void TShopItemListWindow::vfunc_7() {
    struct VObj_8021F134 *temp_r3;

    temp_r3 = (struct VObj_8021F134 *)*(void **)((s8 *)this + 0x2C);
    if (temp_r3 != NULL) {
        temp_r3->m5();
    }
}

void TShopItemListWindow::vfunc_6() {
    struct VObj_8021F16C_8021F134 *temp_r3;

    temp_r3 = (struct VObj_8021F16C_8021F134 *)*(void **)((s8 *)this + 0x2C);
    if (temp_r3 != NULL) {
        temp_r3->m4();
    }
}

s32 TShopItemListWindow::handle_confirm() {
    VObj_8021F678_8021F134 *o = (VObj_8021F678_8021F134 *)this;
    if (o->m8() != 0 && (sub_80223A48__15TShopWindowBaseFv(this) != 0 || sub_802239EC__13TShopSequenceFv(this) != 0)) {
        o->m4(0xB, 1);
        ((TWindowSubItem *)(this->m_28))->clear_selected_and_update_entry();
        set_field_20(1);
    }
}

s32 TShopItemListWindow::update() {
    VObj_8021F708_8021F134 *o = (VObj_8021F708_8021F134 *)this;
    if (o->m8() != 0 && (sub_80223A48__15TShopWindowBaseFv(this) != 0 || sub_802239EC__13TShopSequenceFv(this) != 0)) {
        o->m4(0xB, 1);
        ((TWindowSubItem *)(this->m_28))->clear_selected_and_update_entry();
        set_field_20(1);
    }
}

#define W ((Win_8021F798 *)p)
s32 TShopItemListWindow::handle_tool_list_select(void *p) {
    s32 i;
    s32 n;
    u8 *e;
    if (W->list != NULL) {
        i = select_cursor_entry__22TWindowSubShortCutListFv(W->list);
        if (W->help != NULL && i != W->cur) {
            ((TWindowHelpItem *)(W->help))->set_displayed_item_colored((u32)&W->recs[i]);
        }
        if (W->status != NULL && i != W->cur) {
            n = ((TObjPlayer *)(*(s32 *)(W->player + 0xD00)))->count_items_by_id((s32)&W->recs[i]);
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
    if (sub_80223A48__15TShopWindowBaseFv(W) != 0) {
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

s32 TShopItemListWindow::check_purchase_eligibility() {
    Win_8021F964 *self = (Win_8021F964 *)this;
    s32 sel;
    s32 meseta;
    if (self->list == NULL) {
        return 0;
    }
    sel = select_cursor_entry__22TWindowSubShortCutListFv(self->list);
    meseta = obj_getPtr2B0_20((u8 *)self->player);
    if (self->recs[sel].qty > meseta) {
        return 0;
    }
    if (((TObjPlayer *)(self->player))->can_inventory_accept_item((u8 *)&self->recs[sel]) == 0) {
        return 1;
    }
    return 3;
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
    sub_8022397C__15TShopWindowBaseFv(W);
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
        ((TShopArmorListWindow *)(W->list))->reset_list();
    }
    if (W->list != NULL) {
        for (i = 0; i < W->count; i++) {
            e = (u8 *)W + i * 0x14;
            if (*(s32 *)(e + 0x68) != -1) {
                ((TWindowSubStatusDisp *)(W->list))->add_ground_item((s32)(e + 0x58), (s32)i);
            }
        }
        calc_list_content_extent(W->list);
        ((TWindowSubItem *)((s32)W->list))->clear_selected_and_update_entry();
        ((TShopArmorListWindow *)(W->list))->clamp_selection_to_valid_entry();
    }
    if (W->help == NULL) {
        o = __nw__7TObjectFUl(0xBC);
        if (o != NULL) {
            o = __ct__15TWindowHelpItemFPvUs(o, get_window_layout_position(0x27), get_entity_id(W->player));
        }
        W->help = o;
        if (W->help != NULL && TLobby::is_camera_ctrl_active() > 2) {
            ((TLobby *)(W->help))->set_position(lbl_805DC6F8, lbl_805DC6F8);
        }
        ((TWindowHelpItem *)(W->help))->set_displayed_item_colored((u32)W->recs);
    }
    if (W->status == NULL) {
        W->status = create_window_quantity(((TShopSequence *)W)->get_child_field1c());
        n = ((TObjPlayer *)(*(s32 *)(W->player + 0xD00)))->count_items_by_id((s32)W->recs);
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
        queue_destruction__7TObjectFv((arg0));
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

void *__dt__19TShopItemListWindowFv(TShopItemListWindow *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__19TShopItemListWindow;
        if (*(void **)((s8 *)arg0 + 0x28) != NULL) { TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x28))); arg0->m_28 = 0; }
        if (*(void **)((s8 *)arg0 + 0x30) != NULL) { TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x30))); arg0->m_30 = 0; }
        if (*(void **)((s8 *)arg0 + 0x34) != NULL) { TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x34))); arg0->m_34 = 0; }
        if (*(void **)((s8 *)arg0 + 0x38) != NULL) { TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x38))); arg0->m_38 = 0; }
        if (*(void **)((s8 *)arg0 + 0x3C) != NULL) { TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x3C))); arg0->m_3c = 0; }
        if (*(void **)((s8 *)arg0 + 0x40) != NULL) { TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x40))); arg0->m_40 = 0; }
        __dt__15TShopWindowBaseFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_8021FDC8___vt__19TShopItemListWindow_size[sizeof(RecoveredGlobal_8021FDC8___vt__19TShopItemListWindow) == 0x30 ? 1 : -1];
u8 *TShopItemListWindow__ct(u8 *shop_item_list_window, s32 arg1, s32 arg2, s32 arg3) {
    s32 sp8;
    __ct__15TShopWindowBaseFv((shop_item_list_window));
    *(s32 **)((s8 *)shop_item_list_window + 0x18) = &(*(RecoveredGlobal_8021FDC8___vt__19TShopItemListWindow *)&__vt__19TShopItemListWindow).value;
    *(s32 *)((s8 *)shop_item_list_window + 0) = (s32) TShopItemListWindow__class_name;
    ((TShopItemListWindow *)shop_item_list_window)->m_24 = arg3;
    ((TShopItemListWindow *)shop_item_list_window)->m_2c = arg2;
    ((TShopItemListWindow *)shop_item_list_window)->m_28 = 0;
    ((TShopItemListWindow *)shop_item_list_window)->m_30 = 0;
    ((TShopItemListWindow *)shop_item_list_window)->m_34 = 0;
    ((TShopItemListWindow *)shop_item_list_window)->m_38 = 0;
    ((TShopItemListWindow *)shop_item_list_window)->m_3c = 0;
    ((TShopItemListWindow *)shop_item_list_window)->m_40 = 0;
    ((TShopItemListWindow *)shop_item_list_window)->m_44 = 0;
    ((TShopItemListWindow *)shop_item_list_window)->m_50 = 0;
    ((TShopItemListWindow *)shop_item_list_window)->m_20 = 0;
    ((TShopItemListWindow *)shop_item_list_window)->m_1c0 = 0;
    ((TShopItemListWindow *)shop_item_list_window)->m_4c = 0;
    ((TShopItemListWindow *)shop_item_list_window)->m_54 = 0;
    ((TShopGetItemWindow *)(((TShopItemListWindow *)shop_item_list_window)->m_24))->calc_item_count(&sp8);
    TLobby::set_6264_and_call_2244B0((int)((void *) (sub_8022397C__15TShopWindowBaseFv(shop_item_list_window))), sp8);
    return shop_item_list_window;
}

}
