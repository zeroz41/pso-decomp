#include "types.h"
#include "pso/misc/TShopWindowBase.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/unk/text_80222C28.h"
#include "pso/misc/TShopArmorListWindow.h"
#include "pso/misc/TUnk_804CDFE8.h"
#include "pso/misc/TWindowSubShortCutList.h"
#include "pso/misc/TShopSequence.h"
#include "pso/misc/TWindowMenu.h"
#include "pso/misc/TShopEquipmentSellWindow.h"
#include "pso/TShopWindowBase.h"
#include "pso/item/TItem.h"
#include "pso/misc/TCheckRoomSequence.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowSubItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TWindowInputNumber.h"

struct Base_8021C870 { char pad[0x18]; };
struct VObj_8021C870 : Base_8021C870 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
};
struct Base_8021C8A8_8021C870 { char pad[0x18]; };
struct VObj_8021C8A8_8021C870 : Base_8021C8A8_8021C870 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
};
struct Base_8021C8E0_8021C870 { char pad[0x18]; };
struct VObj_8021C8E0_8021C870 : Base_8021C8E0_8021C870 {
    virtual int m0();
    virtual int m1();
    virtual int m2();
    virtual int m3();
    virtual int m4(int, int);
    virtual int m5();
    virtual int m6();
    virtual int m7();
    virtual int m8();
};

struct ItemData_8021CF04 {
    u8 b[0xC];
    s32 id;
};

struct Entry_8021CF04 {
    u32 id;
    ItemData_8021CF04 item;
    s32 price;
    s32 index;
};

struct Owner_8021CF04 {
    u8 pad0[0xD00];
    void *inventory;
};

struct WinBase_8021CF04 { char pad[0x18]; };

struct Win_8021CF04 : WinBase_8021CF04 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(s32, s32);
    u8 pad1c[0x24 - 0x1C];
    Owner_8021CF04 *owner;
    Entry_8021CF04 entries[30];
    u8 pad370[4];
    s32 count;
    s32 text;
    u8 pad37c[4];
    s32 cursor;
    u8 pad384[8];
    void *list_win;
    u8 pad390[8];
    void *qty_win;
    void *help_win;
    void *cost_win;
};

struct ItemData_8021CC44 {
    u8 b[0xC];
    s32 id;
};

struct Entry_8021CC44 {
    u32 id;
    ItemData_8021CC44 item;
    s32 price;
    s32 index;
};

struct Owner_8021CC44 {
    u8 pad0[0xD00];
    void *inventory;
};

struct Win_8021CC44 {
    u8 pad0[0x24];
    Owner_8021CC44 *owner;
    Entry_8021CC44 entries[30];
    u8 pad370[0x37C - 0x370];
    s32 f37c;
    u8 pad380[4];
    s32 sel;
    u8 pad388[4];
    void *list_win;
    u32 menu_win;
    void *qty_win;
    void *status_win;
    void *help_win;
    void *cost_win;
};

struct VBase_8021C968 { char pad[0x18]; };

struct VObj_8021C968 : VBase_8021C968 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual s32 m4(s32, s32);
};

struct Rec_8021C968 { s32 item; s32 w[4]; s32 price; s32 w18; };

struct Win_8021C968 : VObj_8021C968 {
    u8 pad1c[0x24 - 0x1C];
    s32 player;
    Rec_8021C968 recs[30];
    u8 pad370[0x37C - 0x370];
    s32 count;
    s32 sel;
    u8 pad384[0x38C - 0x384];
    void *list;
    void *card;
};

extern "C" {
void *create_item_list_window(s32, s32, u16);
void calc_list_content_extent(void *);
void *__nw__7TObjectFUl(u32);
s32 obj_getField1c(s32);
s32 get_window_layout_position(s32);
void *__ct__15TWindowHelpItemFPvUs(void *, s32, u16);
void TWindowHelpItem__set_displayed_item_by_id(void *arg0, s32 arg1);
s32 select_cursor_entry__22TWindowSubShortCutListFv(void *);
void *create_window_quantity(u16 arg0);
u32 set_mode_and_refresh_object__10TObjPlayerFPvi(void *, void *);
void *get_owner_if_alive__10TObjPlayerFv(u32);
void *create_cost_window(u16);
void get_item_count__24TShopEquipmentSellWindowFv(void *, s32);
extern const f32 lbl_805DC6D8;
s32 get_item_type_or_default__9TItemListFv(void *);
f32 get_scale__15TShopWindowBaseFv(void *);
int sub_802239EC__13TShopSequenceFv(void *);
int sub_80223A48__15TShopWindowBaseFv(void *);
s32 play_sound_effect(s32, s32, s32, s32);
void *__ct__18TWindowInputNumberFPvllls(void *, s32, s32, s32, s32, s16);
s32 align_menu_entry_positions(u32);
s32 forward_trade_action_default__16TObjCityMainWarpFPviii(u32, s32, s32, s32);
u32 create_window_menu(s32, s32, u16);
s32 get_selected_menu_value(void *);
void *TShopEquipmentSellWindow__ct(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4);
void *__dt__24TShopEquipmentSellWindowFv(TShopEquipmentSellWindow *arg0, s16 arg1);
void __dl__7TObjectFPv(void *);
void memset(void *, int, int);

void TShopEquipmentSellWindow::vfunc_7() {
    struct VObj_8021C870 *o = (struct VObj_8021C870 *)*(void **)((s8 *)this + 0x388);
    if (o != NULL) {
        o->m5();
    }
}

void TShopEquipmentSellWindow::vfunc_6() {
    struct VObj_8021C8A8_8021C870 *o = (struct VObj_8021C8A8_8021C870 *)*(void **)((s8 *)this + 0x388);
    if (o != NULL) {
        o->m4();
    }
}

s32 TShopEquipmentSellWindow::update() {
    VObj_8021C8E0_8021C870 *o = (VObj_8021C8E0_8021C870 *)this;
    if (o->m8() != 0 && (sub_80223A48__15TShopWindowBaseFv(this) != 0 || sub_802239EC__13TShopSequenceFv(this) != 0)) {
        o->m4(0xc, 1);
        set_field_20(5);
    }
}

void TShopEquipmentSellWindow::handle_sell_confirm() {
    Win_8021C968 *w = (Win_8021C968 *)this;
    s32 r;
    if (w->card != NULL && ((TWindowMenu *)(w->card))->is_visible() != 0) {
        r = get_selected_menu_value(w->card);
        if (r == 0) {
            s32 i = select_cursor_entry__22TWindowSubShortCutListFv(w->list);
            if (((TObjPlayer *)(w->player))->try_add_sale_meseta(((TItem *)(w->recs[i].item))->get_item_id(), w->recs[i].price * w->count, w->count) != 0) {
                TWindow__close((u8 *)w->card);
                w->card = NULL;
                w->sel = i;
                ((TShopWindowBase *)w)->set_field_20(0);
                return;
            }
            w->m4(0x1C, 1);
            TWindow__close((u8 *)w->card);
            w->card = NULL;
            ((TShopWindowBase *)w)->set_field_20(4);
            return;
        }
        if (r == 1) {
            TWindow__close((u8 *)w->card);
            w->card = NULL;
            ((TShopWindowBase *)w)->set_field_20(5);
            return;
        }
    }
    if (w->card != NULL && ((TWindowSubComCard *)(w->card))->get_status_flag() != 0) {
        TWindow__close((u8 *)w->card);
        w->card = NULL;
        ((TShopWindowBase *)w)->set_field_20(5);
    }
}

void TShopEquipmentSellWindow::handle_input_window_result() {

    if (((u32) this->m_394 != 0U) && (((TWindowInputNumber *)(this->m_394))->is_confirmed() != 0)) {
        if ((u32) this->m_390 == 0U) {
            this->m_390 = create_window_menu(get_window_layout_position(0x2B), 2, (u16) obj_getField1c(this->m_24));
            forward_trade_action_default__16TObjCityMainWarpFPviii(this->m_390, get_shop_text(6), 6, 0);
            forward_trade_action_default__16TObjCityMainWarpFPviii(this->m_390, get_shop_text(7), 6, 1);
            ((TWindowSubComCard *)(this->m_390))->calc_window_size();
            align_menu_entry_positions(this->m_390);
            ((TCheckRoomSequence *)(this->m_390))->set_ready_flag();
            ((TUnk_804CDFE8 *)(this->m_390))->set_position_xy(get_scale__15TShopWindowBaseFv(this), get_scale__15TShopWindowBaseFv(this));
        }
        this->m_37c = ((TShopEquipmentSellWindow *)(this->m_394))->get_result();
        TWindow__close((u8 *)this->m_394);
        this->m_394 = 0U;
        set_field_20(2);
        return;
    }
    if (((u32) this->m_394 != 0U) && (((TShopEquipmentSellWindow *)(this->m_394))->is_confirmed() != 0)) {
        TWindow__close((u8 *)this->m_394);
        this->m_394 = 0U;
        set_field_20(5);
    }
}

s32 TShopEquipmentSellWindow::close() {
    if ((u32) this->m_38c != 0U) {
        ((TWindowSubItem *)(*(void **)((s8 *)this + 0x38C)))->clear_selected_and_update_entry();
    }
    set_field_20(1);
}

extern s32 __vt__24TShopEquipmentSellWindow[];

void TShopEquipmentSellWindow::handle_selection() {
    Win_8021CC44 *w = (Win_8021CC44 *)this;
    s32 i;
    void *n;
    s32 type;
    if (w->list_win != NULL) {
        i = select_cursor_entry__22TWindowSubShortCutListFv(w->list_win);
        if (w->help_win != NULL && i != w->sel) {
            TWindowHelpItem__set_displayed_item_by_id(w->help_win, w->entries[i].item.id);
        }
        if (w->status_win != NULL && i != w->sel) {
            if (set_mode_and_refresh_object__10TObjPlayerFPvi(w->owner->inventory, &w->entries[i].item) != 0) {
                TShopEquipmentSellWindow::set_entry_count(w->status_win, ((void *(*)(void))get_owner_if_alive__10TObjPlayerFv)());
            } else {
                TShopEquipmentSellWindow::set_entry_count(w->status_win, 0);
            }
        }
        if (w->cost_win != NULL && i != w->sel && w->entries[i].price > 0) {
            get_item_count__24TShopEquipmentSellWindowFv(w->cost_win, w->entries[i].price);
        }
        w->sel = i;
    }
    if (sub_802239EC__13TShopSequenceFv(w) != 0) {
        ((TShopWindowBase *)w)->set_field_20(8);
        play_sound_effect(0x52D01, 0, 0, 0);
        return;
    }
    if (sub_80223A48__15TShopWindowBaseFv(w) != 0) {
        w->f37c = 1;
        i = select_cursor_entry__22TWindowSubShortCutListFv(w->list_win);
        if (w->entries[i].item.b[0] == 3) {
            type = get_item_type_or_default__9TItemListFv(&w->entries[i].item);
            if (type > 1 && w->qty_win == NULL) {
                n = __nw__7TObjectFUl(0x7C);
                if (n != NULL) {
                    n = __ct__18TWindowInputNumberFPvllls(n, get_window_layout_position(0x2B), 1, type, 1, ((TShopSequence *)w)->get_child_field1c());
                }
                w->qty_win = n;
                if (w->qty_win != NULL && TLobby::is_camera_ctrl_active() > 2) {
                    ((TCheckRoomSequence *)(w->qty_win))->set_position(lbl_805DC6D8, lbl_805DC6D8);
                }
                ((TShopWindowBase *)w)->set_field_20(3);
                return;
            }
        }
        if (w->menu_win == 0) {
            w->menu_win = create_window_menu(get_window_layout_position(0x2B), 2, obj_getField1c((s32)w->owner));
            forward_trade_action_default__16TObjCityMainWarpFPviii(w->menu_win, get_shop_text(6), 6, 0);
            forward_trade_action_default__16TObjCityMainWarpFPviii(w->menu_win, get_shop_text(7), 6, 1);
            ((TWindowSubComCard *)(w->menu_win))->calc_window_size();
            align_menu_entry_positions(w->menu_win);
            ((TCheckRoomSequence *)(w->menu_win))->set_ready_flag();
            ((TUnk_804CDFE8 *)(w->menu_win))->set_position_xy(get_scale__15TShopWindowBaseFv(w), get_scale__15TShopWindowBaseFv(w));
            ((TShopWindowBase *)w)->set_field_20(2);
        }
    }
}

void TShopEquipmentSellWindow::build_sell_list() {
    Win_8021CF04 *self = (Win_8021CF04 *)this;
    u32 ids[32];
    s32 n;
    s32 i;
    s32 v;
    void *p;
    u32 r;
    n = ((TObjPlayer *)(self->owner->inventory))->count_matching_items((int)ids);
    self->count = 0;
    for (i = 0; i < n; i++) {
        if (ids[i] != 0) {
            v = TShopEquipmentSellWindow::get_item_data_value(ids[i]);
            if (v > 0 && ((TItem *)(ids[i]))->copy_to_item_data((TItemData *)&self->entries[self->count].item) != 0) {
                self->entries[self->count].id = ids[i];
                self->entries[self->count].price = v / 8;
                self->entries[self->count].index = i;
                self->count++;
            }
        }
    }
    if (self->count == 0) {
        ((TShopWindowBase *)self)->set_field_20(7);
        if (self->list_win != NULL) {
            ((TShopArmorListWindow *)(self->list_win))->reset_list();
        }
        return;
    }
    self->m4(0xC, 1);
    ((TShopWindowBase *)self)->set_field_20(1);
    if (self->list_win == NULL) {
        self->list_win = create_item_list_window(get_shop_text(self->text), self->count, obj_getField1c((s32)self->owner));
        for (i = 0; i < self->count; i++) {
            ((TShopEquipmentSellWindow *)(self->list_win))->add_item(self->entries[i].id, self->entries[i].price, i);
        }
        calc_list_content_extent(self->list_win);
    } else {
        ((TShopArmorListWindow *)(self->list_win))->reset_list();
        for (i = 0; i < self->count; i++) {
            ((TShopEquipmentSellWindow *)(self->list_win))->add_item(self->entries[i].id, self->entries[i].price, i);
        }
        if (self->cursor > self->count - 1) {
            self->cursor = self->count - 1;
        }
        calc_list_content_extent(self->list_win);
        ((TWindowSubShortCutList *)(self->list_win))->set_cursor_index(self->cursor);
        ((TWindowSubItem *)(self->list_win))->clear_selected_and_update_entry();
    }
    if (self->help_win == NULL) {
        p = __nw__7TObjectFUl(0xBC);
        if (p != NULL) {
            p = __ct__15TWindowHelpItemFPvUs(p, get_window_layout_position(0x27), obj_getField1c((s32)self->owner));
        }
        self->help_win = p;
        if (self->help_win != NULL && TLobby::is_camera_ctrl_active() > 2) {
            ((TLobby *)(self->help_win))->set_position(lbl_805DC6D8, lbl_805DC6D8);
        }
        TWindowHelpItem__set_displayed_item_by_id(self->help_win, self->entries[0].item.id);
    } else if (self->list_win != NULL) {
        v = select_cursor_entry__22TWindowSubShortCutListFv(self->list_win);
        TWindowHelpItem__set_displayed_item_by_id(self->help_win, self->entries[v].item.id);
    }
    if (self->qty_win == NULL) {
        self->qty_win = create_window_quantity(((TShopSequence *)self)->get_child_field1c());
        r = set_mode_and_refresh_object__10TObjPlayerFPvi(self->owner->inventory, &self->entries[0].item);
        if (r != 0) {
            TShopEquipmentSellWindow::set_entry_count(self->qty_win, get_owner_if_alive__10TObjPlayerFv(r));
        } else {
            TShopEquipmentSellWindow::set_entry_count(self->qty_win, 0);
        }
    } else if (self->list_win != NULL) {
        v = select_cursor_entry__22TWindowSubShortCutListFv(self->list_win);
        r = set_mode_and_refresh_object__10TObjPlayerFPvi(self->owner->inventory, &self->entries[v].item);
        if (r != 0) {
            TShopEquipmentSellWindow::set_entry_count(self->qty_win, get_owner_if_alive__10TObjPlayerFv(r));
        } else {
            TShopEquipmentSellWindow::set_entry_count(self->qty_win, 0);
        }
    }
    if (self->cost_win == NULL) {
        self->cost_win = create_cost_window(obj_getField1c((s32)self->owner));
        if (self->cost_win != NULL && self->entries[0].price > 0) {
            get_item_count__24TShopEquipmentSellWindowFv(self->cost_win, self->entries[0].price);
        }
    } else if (self->entries[self->cursor].price > 0) {
        get_item_count__24TShopEquipmentSellWindowFv(self->cost_win, self->entries[self->cursor].price);
    }
}

void TShopEquipmentSellWindow::vfunc_11() {
    u8 *arg0 = (u8 *)this;
    s32 (*temp_r12)(s32);
    s32 (*temp_r12_2)(s32);
    switch (*(u32 *)((s8 *)arg0 + 0x20)) {
    case 0:
        ((TShopEquipmentSellWindow *)arg0)->build_sell_list();
        return;
    case 1:
        ((TShopEquipmentSellWindow *)arg0)->handle_selection();
        return;
    case 2:
        ((TShopEquipmentSellWindow *)arg0)->handle_sell_confirm();
        return;
    case 3:
        ((TShopEquipmentSellWindow *)arg0)->handle_input_window_result();
        return;
    case 5:
        ((TShopEquipmentSellWindow *)arg0)->close();
        return;
    case 4:
        ((TShopEquipmentSellWindow *)arg0)->update();
        return;
    case 8:
        temp_r12 = *(s32 (**)(s32))((s8 *)arg0 + 0x3A4);
        if (temp_r12 != NULL) {
            temp_r12(*(s32 *)((s8 *)arg0 + 0x388));
        }
        queue_destruction__7TObjectFv((arg0));
        return;
    case 7:
        temp_r12_2 = *(s32 (**)(s32))((s8 *)arg0 + 0x3A8);
        if (temp_r12_2 != NULL) {
            temp_r12_2(*(s32 *)((s8 *)arg0 + 0x388));
        }
        queue_destruction__7TObjectFv((arg0));
    default:
        return;
    }
}

void *__dt__24TShopEquipmentSellWindowFv(TShopEquipmentSellWindow *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__24TShopEquipmentSellWindow;
        if (*(void **)((s8 *)arg0 + 0x38C) != NULL) { TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x38C))); arg0->m_38c = 0; }
        if (*(void **)((s8 *)arg0 + 0x390) != NULL) { TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x390))); arg0->m_390 = 0; }
        if (*(void **)((s8 *)arg0 + 0x394) != NULL) { TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x394))); arg0->m_394 = 0; }
        if (*(void **)((s8 *)arg0 + 0x39C) != NULL) { TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x39C))); arg0->m_39c = 0; }
        if (*(void **)((s8 *)arg0 + 0x398) != NULL) { TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x398))); arg0->m_398 = 0; }
        if (*(void **)((s8 *)arg0 + 0x3A0) != NULL) { TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x3A0))); arg0->m_3a0 = 0; }
        __dt__15TShopWindowBaseFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern void *TShopEquipmentSellWindow__class_name;

void *TShopEquipmentSellWindow__ct(void *shop_equipment_sell_window, void *arg1, void *arg2, void *arg3, void *arg4) {
    __ct__15TShopWindowBaseFv(shop_equipment_sell_window);
    *(s32 **)((s8 *)shop_equipment_sell_window + 0x18) = __vt__24TShopEquipmentSellWindow;
    *(void * *)&((TShopEquipmentSellWindow *)shop_equipment_sell_window)->m_name = TShopEquipmentSellWindow__class_name;
    ((TShopEquipmentSellWindow *)shop_equipment_sell_window)->m_370 = 0;
    ((TShopEquipmentSellWindow *)shop_equipment_sell_window)->m_374 = 0;
    *(void **)((s8 *)shop_equipment_sell_window + 0x378) = arg4;
    ((TShopEquipmentSellWindow *)shop_equipment_sell_window)->m_20 = 0;
    ((TShopEquipmentSellWindow *)shop_equipment_sell_window)->m_37c = 1;
    ((TShopEquipmentSellWindow *)shop_equipment_sell_window)->m_380 = 0;
    ((TShopEquipmentSellWindow *)shop_equipment_sell_window)->m_384 = 0;
    *(void **)((s8 *)shop_equipment_sell_window + 0x388) = arg2;
    ((TShopEquipmentSellWindow *)shop_equipment_sell_window)->m_38c = 0;
    ((TShopEquipmentSellWindow *)shop_equipment_sell_window)->m_390 = 0;
    ((TShopEquipmentSellWindow *)shop_equipment_sell_window)->m_394 = 0;
    ((TShopEquipmentSellWindow *)shop_equipment_sell_window)->m_39c = 0;
    ((TShopEquipmentSellWindow *)shop_equipment_sell_window)->m_398 = 0;
    ((TShopEquipmentSellWindow *)shop_equipment_sell_window)->m_3a0 = 0;
    *(void **)((s8 *)shop_equipment_sell_window + 0x24) = arg3;
    ((TShopEquipmentSellWindow *)shop_equipment_sell_window)->m_3a4 = 0;
    ((TShopEquipmentSellWindow *)shop_equipment_sell_window)->m_3a8 = 0;
    memset((void *)((char *)shop_equipment_sell_window + 40), 0, 840);
    return shop_equipment_sell_window;
}

}
