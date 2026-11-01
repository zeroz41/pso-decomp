#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#include "types.h"
#include "pso/misc/TWindowMenuIconLine.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TShopWindowBase.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/TShopWindowBase.h"
#include "pso/misc/TWindowAddition.h"
#include "pso/misc/TWindowSubComCardList.h"
#include "pso/misc/TWindowMenu.h"
#include "pso/misc/TShopDeleteItemWindow.h"
#include "pso/misc/TCheckRoomSequence.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TShopEquipmentSellWindow.h"
#include "pso/misc/TWindowHelpItem.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowSubItem.h"
#include "pso/ui/TWindowInputNumber.h"
#include "pso/misc/TShopArmorListWindow.h"
#include "pso/misc/TShopGetItemWindow.h"
#include "pso/misc/TShopJudgmentItemWindow_8026DF00.h"
#include "pso/misc/TWindowSetLevelUp.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/unk/text_80222C28.h"

struct Base_80337910 { char pad[0x18]; };
struct VObj_80337910 : Base_80337910 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
};
struct Base_80337948_80337910 { char pad[0x18]; };
struct VObj_80337948_80337910 : Base_80337948_80337910 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
};

struct Stack_803379E0 {
    s32 sp8;
    u8 trailing_storage[0x10];
};

struct VBase_80337B00 { char pad[0x18]; };

struct VObj_80337B00 : VBase_80337B00 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual s32 m4(s32, s32);
};

typedef struct Win_80337C2C {
    u8 pad0[0x24];
    void *item;
    u8 pad28[8];
    void *f30;
    void *f34;
    void *f38;
    void *f3c;
    u8 f40[0x14];
    u8 f54;
    u8 pad55[3];
    s32 room;
    s32 f5c;
    s32 f60;
} Win_80337C2C;

typedef struct Kind_80337C2C {
    u8 kind;
    u8 rest[0x13];
} Kind_80337C2C;

extern "C" {
s32 compact_items__18TCheckRoomSequenceFi(int);
s32 remove_bank_item_amount__18TCheckRoomSequenceFiii(int, int, int);
s32 copy_item_record__18TCheckRoomSequenceFiPvi(int, void *, int);
s32 copy_bank_to_card_window(int);
s32 sub_8022397C__15TShopWindowBaseFv(void *);
s32 get_cursor_value__19TWindowMenuIconLineFv(int);
void TShopDeleteItemWindow__sub_80337E2C(Win_80337C2C *win);
u16 get_entity_id(void *);
f32 get_scale__15TShopWindowBaseFv(void *);
u8 *create_yes_no_window(s32 arg0, s32 arg1, u32 arg2, u32 arg3);
void *get_window_layout_position(int);
s32 copy_bank_item_with_stack_limit(s32 idx, void *data, s32 *out, s32 slot);
s32 sub_802239EC__13TShopSequenceFv(void *);
s32 sub_80223A48__15TShopWindowBaseFv(void *);
s16 get_child_field1c__13TShopSequenceFv(void *);
void *__nw__7TObjectFUl(u32);
void *__ct__18TWindowInputNumberFPvllls(void *, void *, int, s32, int, int);
extern const f32 lbl_805DF998;
struct Base_80337980_80337910 { char pad[0x18]; };
struct VObj_80337980_80337910 : Base_80337980_80337910 {
    virtual void m0();virtual void m1();virtual void m2();virtual void m3();
    virtual void m4(int a, int b);
};

void *TShopDeleteItemWindow__ct(void *arg0, void *arg1, void *arg2, void *arg3);
void *__dt__21TShopDeleteItemWindowFv(TShopDeleteItemWindow *arg0, s16 arg1);
void __dl__7TObjectFPv(void *);
void init__9TItemDataFv(void *);

void TShopDeleteItemWindow::display_message(const char *text, s32 flags) {
    struct VObj_80337910 *o = (struct VObj_80337910 *)*(void **)((s8 *)this + 0x64);
    if (o != NULL) {
        o->m5();
    }
}

void TShopDeleteItemWindow::vfunc_6() {
    struct VObj_80337948_80337910 *o = (struct VObj_80337948_80337910 *)*(void **)((s8 *)this + 0x64);
    if (o != NULL) {
        o->m4();
    }
}

s32 TShopDeleteItemWindow::destroy() {
    if ((u32) this->m_30 != 0U) {
        ((TWindowMenuIconLine *)(*(void **)((s8 *)this + 0x30)))->clear_decided();
    }
    set_field_20(1);
    ((VObj_80337980_80337910 *)this)->m4(0x4C, 1);
}

extern s32 __vt__21TShopDeleteItemWindow[];

void TShopDeleteItemWindow::handle_confirm_dialog() {
    Stack_803379E0 stack;
    s32 slot;
    s32 selected_menu_value;
    s32 idx;
    u32 temp_r3;
    u32 temp_r3_4;
    temp_r3 = this->m_34;
    if ((temp_r3 != 0U) && (((TWindowMenu *)temp_r3)->is_decided() != 0)) {
        slot = sub_8022397C__15TShopWindowBaseFv(this);
        selected_menu_value = ((TWindowMenu *)this->m_34)->get_selected_value();
        if (selected_menu_value == 0) {
            idx = get_cursor_value__19TWindowMenuIconLineFv(this->m_30);
            if (copy_item_record__18TCheckRoomSequenceFiPvi(idx, &stack.sp8, slot) != 0) {
                remove_bank_item_amount__18TCheckRoomSequenceFiii(idx, this->m_5c, slot);
                compact_items__18TCheckRoomSequenceFi(slot);
                copy_bank_to_card_window(slot);
                this->set_field_20(0);
            }
            ((TWindowBase *)this->m_34)->close();
            this->m_34 = 0U;
            return;
        }
        if (selected_menu_value == 1) {
            ((TWindowBase *)this->m_34)->close();
            this->m_34 = 0U;
            this->set_field_20(4);
            return;
        }
        goto block_8;
    }
block_8:
    temp_r3_4 = this->m_34;
    if ((temp_r3_4 != 0U) && (((TWindowMenu *)temp_r3_4)->is_cancelled() != 0)) {
        ((TWindowBase *)this->m_34)->close();
        this->m_34 = 0U;
        this->set_field_20(4);
    }
}

void TShopDeleteItemWindow::handle_number_input() {
    if (*(void **)(((u8 *)this) + 0x38) != 0 && ((TWindowInputNumber *)(*(void **)(((u8 *)this) + 0x38)))->is_confirmed() != 0) {
        if (*(void **)(((u8 *)this) + 0x34) == 0) {
            u32 id = get_entity_id(*(void **)(((u8 *)this) + 0x24));
            *(void **)(((u8 *)this) + 0x34) = create_yes_no_window((s32)(get_window_layout_position(0x2B)), id, 0, 0);
            ((TCheckRoomSequence *)(*(void **)(((u8 *)this) + 0x34)))->set_ready_flag();
            ((TWindowSubComCardList *)(*(void **)(((u8 *)this) + 0x34)))->set_selected_index(1);
            ((TWindowAddition *)(*(void **)(((u8 *)this) + 0x34)))->set_position_xy(get_scale__15TShopWindowBaseFv(this), get_scale__15TShopWindowBaseFv(this));
        }
        this->m_5c = ((TShopEquipmentSellWindow *)(*(void **)(((u8 *)this) + 0x38)))->get_result();
        ((TWindowBase *)(*(void **)(((u8 *)this) + 0x38)))->close();
        *(void **)(((u8 *)this) + 0x38) = 0;
        this->set_field_20(3);
        ((VObj_80337B00 *)(this))->m4(0x4D, 1);
        return;
    }
    if (*(void **)(((u8 *)this) + 0x38) != 0 && ((TShopEquipmentSellWindow *)(*(void **)(((u8 *)this) + 0x38)))->is_confirmed() != 0) {
        ((TWindowBase *)(*(void **)(((u8 *)this) + 0x38)))->close();
        *(void **)(((u8 *)this) + 0x38) = 0;
        this->set_field_20(4);
    }
}

#pragma push
#pragma opt_common_subs off
#define self ((Win_80337C2C *)arg0)
s32 TShopDeleteItemWindow::update_item_select(void *arg0) {
    Kind_80337C2C kind;
    s32 count;
    s32 base;
    s32 cursor;
    void *p;
    s32 id;
    base = sub_8022397C__15TShopWindowBaseFv(self);
    if (self->f30 != NULL) {
        cursor = ((TWindowMenuIconLine *)self->f30)->get_cursor_value();
        if (self->f3c != NULL && cursor != self->f60) {
            if (copy_item_record__18TCheckRoomSequenceFiPvi(cursor, self->f40, base) != 0) {
                ((TWindowHelpItem *)(self->f3c))->set_displayed_item_colored((u32)self->f40);
            }
            self->f60 = cursor;
        }
    }
    if (sub_802239EC__13TShopSequenceFv(self) != 0) {
        ((TShopWindowBase *)self)->set_field_20(7);
    } else if (sub_80223A48__15TShopWindowBaseFv(self) != 0) {
        if (copy_bank_item_with_stack_limit(((TWindowMenuIconLine *)self->f30)->get_cursor_value(), &kind, &count, base) != 0) {
            if (kind.kind == 3 && count > 1) {
                p = __nw__7TObjectFUl(0x7C);
                if (p != NULL) {
                    id = get_child_field1c__13TShopSequenceFv(self);
                    p = __ct__18TWindowInputNumberFPvllls(p, get_window_layout_position(0x2B), 1, count, 1, id);
                }
                self->f38 = p;
                if (self->f38 != NULL && TLobby::is_camera_ctrl_active() > 2) {
                    ((TCheckRoomSequence *)(self->f38))->set_position(lbl_805DF998, lbl_805DF998);
                }
                ((TShopWindowBase *)self)->set_field_20(2);
            } else {
                id = get_entity_id(self->item);
                self->f34 = create_yes_no_window((s32)(get_window_layout_position(0x2B)), id, 0, 0);
                ((TCheckRoomSequence *)(self->f34))->set_ready_flag();
                ((TWindowSubComCardList *)(self->f34))->set_selected_index(1);
                ((TWindowAddition *)(self->f34))->set_position_xy(get_scale__15TShopWindowBaseFv(self), get_scale__15TShopWindowBaseFv(self));
                ((TShopWindowBase *)self)->set_field_20(3);
                ((VObj_80337B00 *)self)->m4(0x4D, 1);
            }
        }
    }
}
#undef self
#pragma pop

#pragma push
#pragma opt_loop_invariants off
void TShopDeleteItemWindow__sub_80337E2C(Win_80337C2C *win) {
    s32 base;
    s32 cursor;
    s32 i;
    win->f5c = 1;
    base = sub_8022397C__15TShopWindowBaseFv(win);
    win->room = TCheckRoomSequence::get_room_table_entry(base);
    if (win->room == 0) {
        ((VObj_80337B00 *)win)->m4(0x3E, 1);
        ((TShopWindowBase *)win)->set_field_20(6);
        if (win->f30 != NULL) {
            ((TWindowMenuIconLine *)win->f30)->reset_list();
        }
        return;
    }
    ((VObj_80337B00 *)win)->m4(0x4C, 1);
    if (win->f30 == NULL) {
        Kind_80337C2C item;
        s32 count;
        win->f30 = create_item_list_window(get_shop_text(0x30), 200, get_entity_id(win->item));
        TWindowSetLevelUp__sub_8026DE28(win->f30, 200);
        for (i = 0; i < 200; i++) {
            if (copy_bank_item_with_stack_limit(i, &item, &count, base) != 0) {
                if (count > 1) {
                    ((TWindowSubStatusDisp *)win->f30)->add_item_info_entry((s32)&item, i, count);
                } else {
                    ((TWindowSubStatusDisp *)win->f30)->add_item_info_entry((s32)&item, i, 0);
                }
            }
        }
        ((TWindowMenuIconLine *)win->f30)->calc_content_extent();
        cursor = ((TShopGetItemWindow *)win->f30)->get_cursor_index();
    } else {
        Kind_80337C2C item;
        s32 count;
        s32 j;
        ((TShopArmorListWindow *)win->f30)->save_cursor_selection();
        ((TWindowMenuIconLine *)win->f30)->reset_list();
        for (j = 0; j < 200; j++) {
            if (copy_bank_item_with_stack_limit(j, &item, &count, base) != 0) {
                if (count > 1) {
                    ((TWindowSubStatusDisp *)win->f30)->add_item_info_entry((s32)&item, j, count);
                } else {
                    ((TWindowSubStatusDisp *)win->f30)->add_item_info_entry((s32)&item, j, 0);
                }
            }
        }
        ((TShopArmorListWindow *)win->f30)->clamp_selection_to_valid_entry();
        ((TWindowMenuIconLine *)win->f30)->calc_content_extent();
        ((TWindowMenuIconLine *)win->f30)->clear_decided();
        cursor = ((TShopGetItemWindow *)win->f30)->get_cursor_index();
    }
    if (win->f3c == NULL) {
        if (copy_item_record__18TCheckRoomSequenceFiPvi(cursor, win->f40, base) != 0) {
            win->f3c = new TWindowHelpItem(get_window_layout_position(0x27), (u32)get_entity_id(win->item));
            if (win->f3c != NULL && TLobby::is_camera_ctrl_active() > 2) {
                ((TLobby *)win->f3c)->set_position(lbl_805DF998, lbl_805DF998);
            }
            ((TWindowHelpItem *)win->f3c)->set_displayed_item_colored((u32)win->f40);
            win->f60 = cursor;
        }
    } else if (copy_item_record__18TCheckRoomSequenceFiPvi(cursor, win->f40, base) != 0) {
        ((TWindowHelpItem *)win->f3c)->set_displayed_item_colored((u32)win->f40);
        win->f60 = cursor;
    }
    ((TShopWindowBase *)win)->set_field_20(1);
}
#pragma pop

void TShopDeleteItemWindow::vfunc_11() {
    u8 *arg0 = (u8 *)this;
    s32 (*temp_r12)(s32);
    s32 (*temp_r12_2)(s32);
    switch (*(u32 *)((s8 *)arg0 + 0x20)) {
    case 0:
        TShopDeleteItemWindow__sub_80337E2C((Win_80337C2C *)arg0);
        return;
    case 1:
        TShopDeleteItemWindow::update_item_select(arg0);
        return;
    case 2:
        ((TShopDeleteItemWindow *)arg0)->handle_number_input();
        return;
    case 3:
        ((TShopDeleteItemWindow *)arg0)->handle_confirm_dialog();
        return;
    case 4:
        ((TShopDeleteItemWindow *)arg0)->destroy();
        return;
    case 6:
        temp_r12 = *(s32 (**)(s32))((s8 *)arg0 + 0x2C);
        if (temp_r12 != NULL) {
            temp_r12(*(s32 *)((s8 *)arg0 + 0x64));
        }
        queue_destruction__7TObjectFv((arg0));
        return;
    case 7:
        temp_r12_2 = *(s32 (**)(s32))((s8 *)arg0 + 0x28);
        if (temp_r12_2 != NULL) {
            temp_r12_2(*(s32 *)((s8 *)arg0 + 0x64));
        }
        queue_destruction__7TObjectFv((arg0));
    default:
        return;
    }
}

void *__dt__21TShopDeleteItemWindowFv(TShopDeleteItemWindow *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__21TShopDeleteItemWindow;
        if (*(void **)((s8 *)arg0 + 0x30) != NULL) { ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x30)))->close(); arg0->m_30 = 0; }
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

extern void *TShopDeleteItemWindow__name;

void *TShopDeleteItemWindow__ct(void *shop_delete_item_window, void *arg1, void *arg2, void *arg3) {
    __ct__15TShopWindowBaseFv(shop_delete_item_window);
    *(s32 **)((s8 *)shop_delete_item_window + 0x18) = __vt__21TShopDeleteItemWindow;
    *(void * *)&((TShopDeleteItemWindow *)shop_delete_item_window)->m_name = TShopDeleteItemWindow__name;
    ((TShopDeleteItemWindow *)shop_delete_item_window)->m_20 = 0;
    *(void **)((s8 *)shop_delete_item_window + 0x24) = arg3;
    ((TShopDeleteItemWindow *)shop_delete_item_window)->m_5c = 1;
    ((TShopDeleteItemWindow *)shop_delete_item_window)->m_54 = 0;
    ((TShopDeleteItemWindow *)shop_delete_item_window)->m_60 = 0;
    ((TShopDeleteItemWindow *)shop_delete_item_window)->m_28 = 0;
    ((TShopDeleteItemWindow *)shop_delete_item_window)->m_2c = 0;
    ((TShopDeleteItemWindow *)shop_delete_item_window)->m_30 = 0;
    ((TShopDeleteItemWindow *)shop_delete_item_window)->m_34 = 0;
    ((TShopDeleteItemWindow *)shop_delete_item_window)->m_38 = 0;
    ((TShopDeleteItemWindow *)shop_delete_item_window)->m_3c = 0;
    *(void **)((s8 *)shop_delete_item_window + 0x64) = arg2;
    init__9TItemDataFv((void *)((char *)shop_delete_item_window + 64));
    return shop_delete_item_window;
}

}
