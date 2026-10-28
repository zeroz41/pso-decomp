#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

#include "types.h"
#include "pso/misc/TShopWindowBase.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/unk/text_80222C28.h"
#include "pso/item/TItem.h"
#include "pso/misc/TShopArmorListWindow.h"
#include "pso/player/TObjPlayer.h"
#include "pso/TShopWindowBase.h"
#include "pso/misc/TShopKeepItemWindow.h"
#include "pso/misc/TUnk_804CDFE8.h"
#include "pso/misc/TWindowMenu.h"

struct Base_80221844 { char pad[0x18]; };
struct VObj_80221844 : Base_80221844 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
};
struct Base_8022187C_80221844 { char pad[0x18]; };
struct VObj_8022187C_80221844 : Base_8022187C_80221844 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
};

struct Base_802219A0 { char pad[0x18]; };

struct V_802219A0 : Base_802219A0 {
    virtual void p0(); virtual void p1(); virtual void p2(); virtual void p3();
    virtual void m4(s32, s32);
};

struct Ent_802219A0 {
    s32 f0;
    s32 f4;
    char pad8[0x14];
};

struct Self_802219A0 {
    char pad0[0x24];
    s32 f24;
    Ent_802219A0 ents[30];
    char pad370[0x8];
    s32 f378;
    char pad37C[0x8];
    s32 f384;
    void *f388;
};

#include "pso/misc/TWindowHelpItem.h"
#include "pso/misc/TCheckRoomSequence.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TShopEquipmentSellWindow.h"
#include "pso/misc/TShopGetItemWindow.h"
#include "pso/misc/TShopJudgmentItemWindow.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowSubItem.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/ui/TMessageWindowController.h"
#include "pso/ui/TWindowInputNumber.h"
struct VBase_80221F08 { char pad[0x18]; };

struct VObj_80221F08 : VBase_80221F08 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(s32, s32);
};

struct Ent_80221F08 {
    s32 f0;
    u8 item[0x14];
    s32 f18;
};

struct Self_80221F08 {
    char pad0[0x24];
    u8 *f24;
    Ent_80221F08 ents[30];
    char pad370[0x4];
    s32 f374;
    s32 f378;
    s32 f37C;
    u32 f380;
    u32 f384;
    u32 f388;
    u32 f38C;
    u32 f390;
};

extern "C" {
u32 obj_getField1c(s32);
f32 get_scale__15TShopWindowBaseFv(void *);
u8 *create_yes_no_window(s32 arg0, s32 arg1, u32 arg2, u32 arg3);
s32 get_window_layout_position(s32);
void memset(void *, int, int);
s32 get_item_record__23TShopJudgmentItemWindowFPv(s32, s32, s32);
s32 store_item_in_bank(u8 *item, s32 arg1, s32 slot);
void copy_bank_to_card_window(s32 slot);
s32 sub_8022397C__15TShopWindowBaseFv(void *);
s32 play_sound_effect(s32, s32, s32, s32);
s32 get_selected_menu_value(void *);
s32 select_cursor_entry__22TWindowSubShortCutListFv(s32);
void TWindowHelpItem__set_displayed_item_by_id(u32, s32);
void calc_list_content_extent(u32);
u32 create_item_list_window(s32, s32, u16);
extern f32 lbl_805DC710;
void sort_bank_items(s32 slot);
void __dl__7TObjectFPv(void *);

void TShopKeepItemWindow::vfunc_7() {
    struct VObj_80221844 *temp_r3;

    temp_r3 = (struct VObj_80221844 *)this->m_380;
    if (temp_r3 != NULL) {
        temp_r3->m5();
    }
}

void TShopKeepItemWindow::vfunc_6() {
    struct VObj_8022187C_80221844 *o = (struct VObj_8022187C_80221844 *)this->m_380;
    if (o != NULL) {
        o->m4();
    }
}

s32 TShopKeepItemWindow::close_with_cancel_callback() {
    s32 (*temp_r12)(s32);

    temp_r12 = *(s32 (**)(s32))((s8 *)this + 0x398);
    if (temp_r12 != NULL) {
        temp_r12(this->m_380);
    }
    sort_bank_items(sub_8022397C__15TShopWindowBaseFv(this));
    queue_destruction__7TObjectFv(this);
}

s32 TShopKeepItemWindow::close_with_ok_callback() {
    s32 (*temp_r12)(s32);

    temp_r12 = *(s32 (**)(s32))((s8 *)this + 0x394);
    if (temp_r12 != NULL) {
        temp_r12(this->m_380);
    }
    sort_bank_items(sub_8022397C__15TShopWindowBaseFv(this));
    queue_destruction__7TObjectFv(this);
}

s32 TShopKeepItemWindow::close() {
    if ((u32) this->m_384 != 0U) {
        ((TWindowSubItem *)(this->m_384))->clear_selected_and_update_entry();
    }
    set_field_20(1);
}

extern s32 __vt__19TShopKeepItemWindow[];

void TShopKeepItemWindow::handle_deposit_confirm() {
    Self_802219A0 *self = (Self_802219A0 *)this;
    s32 base;
    s32 r;
    s32 i;
    void *win;
    win = self->f388;
    if (win != NULL && ((TWindowMenu *)win)->is_visible() != 0) {
        base = sub_8022397C__15TShopWindowBaseFv(this);
        r = get_selected_menu_value(self->f388);
        if (r == 0) {
            i = select_cursor_entry__22TWindowSubShortCutListFv(this->m_384);
            if (store_item_in_bank((u8 *)&self->ents[i].f4, this->m_378, base) != 0) {
                get_item_record__23TShopJudgmentItemWindowFPv(this->m_24, ((TItem *)(self->ents[i].f0))->get_item_id(), this->m_378);
                copy_bank_to_card_window(base);
                play_sound_effect(0x52D01, 0, 0, 0);
                TWindow__close((u8 *)self->f388);
                self->f388 = NULL;
                set_field_20(0);
                return;
            }
            ((V_802219A0 *) this)->m4(0x3C, 1);
            play_sound_effect(0x53F06, 0, 0, 0);
            TWindow__close((u8 *)self->f388);
            self->f388 = NULL;
            set_field_20(7);
            return;
        }
        if (r == 1) {
            TWindow__close((u8 *)self->f388);
            self->f388 = NULL;
            set_field_20(3);
            return;
        }
    }
    win = self->f388;
    if (win != NULL && ((TWindowSubComCard *)win)->get_status_flag() != 0) {
        TWindow__close((u8 *)self->f388);
        self->f388 = NULL;
        set_field_20(3);
    }
}

void TShopKeepItemWindow::update_number_input() {
    f32 temp_f31;
    u16 temp_r31;
    u32 w;
    w = this->m_38c;
    if ((w != 0U) && (((TWindowInputNumber *)w)->is_confirmed() != 0)) {
        if ((u32) this->m_388 == 0U) {
            temp_r31 = obj_getField1c(this->m_24);
            this->m_388 = (u32)create_yes_no_window(get_window_layout_position(0x2B), temp_r31, 0, 0);
            ((TCheckRoomSequence *)(this->m_388))->set_ready_flag();
            temp_f31 = get_scale__15TShopWindowBaseFv(this);
            ((TUnk_804CDFE8 *)(this->m_388))->set_position_xy(get_scale__15TShopWindowBaseFv(this), temp_f31);
        }
        this->m_378 = ((TShopEquipmentSellWindow *)(this->m_38c))->get_result();
        TWindow__close((u8 *)this->m_38c);
        this->m_38c = 0U;
        set_field_20(2);
        return;
    }
    w = this->m_38c;
    if ((w != 0U) && (((TShopEquipmentSellWindow *)w)->is_confirmed() != 0)) {
        TWindow__close((u8 *)this->m_38c);
        this->m_38c = 0U;
        set_field_20(3);
    }
}

s32 TShopKeepItemWindow::rebuild_item_list() {
    Self_80221F08 *self = (Self_80221F08 *)this;
    u32 buf[30];
    s32 count;
    s32 i;
    s32 cur;
    self->f378 = 1;
    count = ((TObjPlayer *)(*(s32 *)((s8 *)self->f24 + 0xD00)))->count_matching_items((int)buf);
    self->f374 = 0;
    for (i = 0; i < count; i++) {
        if (buf[i] != 0 && ((TItem *)(buf[i]))->copy_to_item_data((TItemData *)self->ents[self->f374].item) != 0) {
            self->ents[self->f374].f0 = buf[i];
            self->ents[self->f374].f18 = i;
            self->f374++;
        }
    }
    if (self->f374 != 0) {
        set_field_20(1);
    } else {
        ((VObj_80221F08 *)this)->m4(0x49, 1);
        set_field_20(7);
        return;
    }
    if (self->f384 == 0U) {
        self->f384 = create_item_list_window(get_shop_text(0x30), 0x40, obj_getField1c((s32)self->f24));
        for (s32 j = 0; j < self->f374; j++) {
            ((TShopJudgmentItemWindow *)(self->f384))->add_list_entry(self->ents[j].f0, j);
        }
        calc_list_content_extent(self->f384);
        cur = ((TShopGetItemWindow *)(self->f384))->get_cursor_index();
    } else {
        ((TShopArmorListWindow *)(self->f384))->save_cursor_selection();
        ((TShopArmorListWindow *)(self->f384))->reset_list();
        for (s32 j = 0; j < self->f374; j++) {
            ((TShopJudgmentItemWindow *)(self->f384))->add_list_entry(self->ents[j].f0, j);
        }
        ((TShopArmorListWindow *)(self->f384))->clamp_selection_to_valid_entry();
        calc_list_content_extent(self->f384);
        ((TWindowSubItem *)((void *)self->f384))->clear_selected_and_update_entry();
        cur = ((TShopGetItemWindow *)(self->f384))->get_cursor_index();
    }
    if (self->f390 == 0U) {
        self->f390 = (u32)new TWindowHelpItem((void *)get_window_layout_position(0x27), obj_getField1c((s32)self->f24));
        if (self->f390 != 0U && TLobby::is_camera_ctrl_active() > 2) {
            ((TLobby *)(self->f390))->set_position(lbl_805DC710, lbl_805DC710);
        }
        TWindowHelpItem__set_displayed_item_by_id(self->f390, ((TItem *)(self->ents[cur].f0))->get_item_id());
        self->f37C = cur;
    } else {
        TWindowHelpItem__set_displayed_item_by_id(self->f390, ((TItem *)(self->ents[cur].f0))->get_item_id());
        self->f37C = cur;
    }
}

void TShopKeepItemWindow::vfunc_11() {
    u8 *arg0 = (u8 *)this;
    switch (this->m_20) {
    case 0:
        ((TShopKeepItemWindow *)arg0)->rebuild_item_list();
        return;
    case 1:
        ((TShopKeepItemWindow *)arg0)->handle_deposit_list_select();
        return;
    case 2:
        ((TShopKeepItemWindow *)arg0)->handle_deposit_confirm();
        return;
    case 3:
        ((TShopKeepItemWindow *)arg0)->close();
        return;
    case 4:
        ((TShopKeepItemWindow *)arg0)->update_number_input();
        return;
    case 5:
        ((TShopKeepItemWindow *)arg0)->close_with_ok_callback();
        return;
    case 7:
        ((TShopKeepItemWindow *)arg0)->close_with_cancel_callback();
    default:
        return;
    }
}

void *__dt__19TShopKeepItemWindowFv(TShopKeepItemWindow *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__19TShopKeepItemWindow;
        if (*(void **)((s8 *)arg0 + 0x384) != NULL) { TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x384))); arg0->m_384 = 0; }
        if (*(void **)((s8 *)arg0 + 0x388) != NULL) { TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x388))); arg0->m_388 = 0; }
        if (*(void **)((s8 *)arg0 + 0x38C) != NULL) { TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x38C))); arg0->m_38c = 0; }
        if (*(void **)((s8 *)arg0 + 0x390) != NULL) { TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x390))); arg0->m_390 = 0; }
        __dt__15TShopWindowBaseFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern void *TShopKeepItemWindow__class_name;

void *TShopKeepItemWindow__ct(TShopKeepItemWindow *shop_keep_item_window, void *arg1, void *arg2, void *arg3) {
    __ct__15TShopWindowBaseFv(shop_keep_item_window);
    *(s32 **)((s8 *)shop_keep_item_window + 0x18) = __vt__19TShopKeepItemWindow;
    *(void * *)&shop_keep_item_window->m_name = TShopKeepItemWindow__class_name;
    shop_keep_item_window->m_370 = 0;
    shop_keep_item_window->m_374 = 0;
    shop_keep_item_window->m_378 = 1;
    shop_keep_item_window->m_37c = 0;
    shop_keep_item_window->m_20 = 0;
    *(void **)((s8 *)shop_keep_item_window + 0x380) = arg2;
    shop_keep_item_window->m_384 = 0;
    shop_keep_item_window->m_388 = 0;
    shop_keep_item_window->m_390 = 0;
    shop_keep_item_window->m_38c = 0;
    *(void **)((s8 *)shop_keep_item_window + 0x24) = arg3;
    shop_keep_item_window->m_394 = 0;
    shop_keep_item_window->m_398 = 0;
    memset((void *)((char *)shop_keep_item_window + 40), 0, 840);
    return shop_keep_item_window;
}

}
