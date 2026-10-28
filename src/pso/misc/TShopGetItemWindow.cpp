#include "types.h"
#include "pso/misc/TShopWindowBase.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/unk/text_80222C28.h"
#include "pso/misc/TUnk_804CDFE8.h"
#include "pso/misc/TShopSequence.h"
#include "pso/misc/TWindowMenu.h"
#include "pso/misc/TShopGetItemWindow.h"
#include "pso/TShopWindowBase.h"
#include "pso/misc/TCheckRoomSequence.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TShopArmorListWindow.h"
#include "pso/misc/TShopEquipmentSellWindow.h"
#include "pso/misc/TWindowHelpItem.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowSubItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TWindowInputNumber.h"

struct VBase_18_a93f07
{
  char pad[0x18];
};

struct VObj_18_a93f07 : VBase_18_a93f07 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual s32 m4(s32, s32);
};

struct Stack_8021E5D8
{
  s32 sp8;
  u8 pad_C[0x8];
  s32 sp14;
};

struct RecoveredFields_8021E5D8_arg0
{
  u8 unknown_0[0x24];
  s32 field_24;
  s32 field_28;
  u32 field_2C;
  u8 unknown_30[0x24];
  s32 field_54;
};

struct Item_8021E870 { u8 kind; u8 data[0x13]; };

struct Win_8021E870 {
    u8 pad0[0x24];
    s32 f24;
    u32 f28;
    u32 f2C;
    u32 f30;
    u32 f34;
    Item_8021E870 item;
    u8 pad4C[0x58 - 0x4C];
    s32 f58;
};

struct Item_8021EA48 { u8 data[0x14]; };

struct VBase_8021EA48 { char pad[0x18]; };

struct Win_8021EA48 : VBase_8021EA48 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(s32, s32);
    u8 pad1C[0x24 - 0x1C];
    s32 f24;
    u32 f28;
    u32 f2C;
    u32 f30;
    u32 f34;
    Item_8021EA48 item;
    u8 pad4C[0x50 - 0x4C];
    s32 f50;
    s32 f54;
    s32 f58;
};

extern "C" {
s32 get_entity_id(s32);
f32 get_scale__15TShopWindowBaseFv(void *);
void TWindow__close(void *);
u8 *create_yes_no_window(s32 arg0, s32 arg1, u32 arg2, u32 arg3);
s32 get_window_layout_position(s32);
s32 set_stack_count__24TShopEquipmentListWindowFSc(void *, int);
s32 compact_items__18TCheckRoomSequenceFi(int);
s32 remove_bank_item_amount__18TCheckRoomSequenceFiii(int, int, int);
s32 copy_item_record__18TCheckRoomSequenceFiPvi(int, void *, int);
s32 copy_bank_to_card_window(int);
s32 sub_8022397C__15TShopWindowBaseFv(void *);
s32 get_selected_menu_value(int);
s32 select_cursor_entry__22TWindowSubShortCutListFv(int);
s32 copy_bank_item_with_stack_limit(s32 idx, void *data, s32 *out, s32 slot);
s32 sub_802239EC__13TShopSequenceFv(void *);
s32 sub_80223A48__15TShopWindowBaseFv(void *);
void *__nw__7TObjectFUl(u32);
u32 __ct__18TWindowInputNumberFPvllls(void *, s32, s32, s32, s32, s16);
extern const f32 lbl_805DC6F0;
s32 get_room_table_entry__18TCheckRoomSequenceFi(void);
u32 __ct__15TWindowHelpItemFPvUs(void *, s32, u16);
void calc_list_content_extent(u32);
void add_item_info_entry__20TWindowSubStatusDispFlll(u32, void *, s32, s32);
void TWindowSetLevelUp__sub_8026DE28(u32, s32);
u32 create_item_list_window(s32, s32, u16);
void *TShopGetItemWindow__ct(void *arg0, void *arg1, void *arg2, void *arg3);
void *__dt__18TShopGetItemWindowFv(TShopGetItemWindow *arg0, s16 arg1);
void __dl__7TObjectFPv(void *);
void init__9TItemDataFv(void *);

s32 TShopGetItemWindow::close() {
    if ((u32) this->m_28 != 0U) {
        ((TWindowSubItem *)(*(void **)((s8 *)this + 0x28)))->clear_selected_and_update_entry();
    }
    set_field_20(1);
}

extern s32 __vt__18TShopGetItemWindow[];

typedef struct RecoveredFields_8021E5D8_arg0 RecoveredFields_8021E5D8_arg0;
typedef struct Stack_8021E5D8 Stack_8021E5D8;
typedef struct VBase_18_a93f07 VBase_18_a93f07;
typedef struct VObj_18_a93f07 VObj_18_a93f07;
#define PSO_VCALL_VObj_18_a93f07_m4(_self, _arg0, _arg1) (((VObj_18_a93f07 *)(_self))->m4((_arg0), (_arg1)))
void TShopGetItemWindow::handle_withdraw_confirm() {
  Stack_8021E5D8 stack;
  s32 slot;
  s32 selected_menu_value;
  s32 idx;
  u32 temp_r3;
  u32 temp_r3_4;
  temp_r3 = ((RecoveredFields_8021E5D8_arg0 *) ((u8 *)this))->field_2C;
  if ((temp_r3 != 0U) && (((TWindowMenu *)temp_r3)->is_visible() != 0))
  {
    slot = sub_8022397C__15TShopWindowBaseFv((void *) ((u8 *)this));
    selected_menu_value = get_selected_menu_value((int) ((RecoveredFields_8021E5D8_arg0 *) ((u8 *)this))->field_2C);
    if (selected_menu_value == 0)
    {
      idx = select_cursor_entry__22TWindowSubShortCutListFv((int) ((RecoveredFields_8021E5D8_arg0 *) ((u8 *)this))->field_28);
      if (copy_item_record__18TCheckRoomSequenceFiPvi((int) idx, &stack.sp8, (int) (slot & 0xFFFFFFFFFFFFFFFFu)) != 0)
      {
        stack.sp14 = -1;
        if (TCheckRoomSequence::get_item_def((u32)&stack.sp8) != 0)
        {
          set_stack_count__24TShopEquipmentListWindowFSc(&stack.sp8, (int) ((s32) ((u8) ((RecoveredFields_8021E5D8_arg0 *) ((u8 *)this))->field_54)));
        }
        if (((TObjPlayer *)((int) ((RecoveredFields_8021E5D8_arg0 *) ((u8 *)this))->field_24))->can_inventory_accept_item((u8 *)&stack.sp8) == 0)
        {
          PSO_VCALL_VObj_18_a93f07_m4(this, 0x4B, 1);
          this->set_field_20(6);
        }
        else
        {
          ((TObjPlayer *)((int) ((RecoveredFields_8021E5D8_arg0 *) ((u8 *)this))->field_24))->request_inventory_item((TItemData*)(&stack.sp8));
          remove_bank_item_amount__18TCheckRoomSequenceFiii((int) idx, (int) ((RecoveredFields_8021E5D8_arg0 *) ((u8 *)this))->field_54, (int) slot);
          compact_items__18TCheckRoomSequenceFi((int) slot);
          copy_bank_to_card_window((int) slot);
          this->set_field_20(0);
        }
      }
      TWindow__close((void *)((int) ((RecoveredFields_8021E5D8_arg0 *) ((u8 *)this))->field_2C));
      ((RecoveredFields_8021E5D8_arg0 *) ((u8 *)this))->field_2C = 0U;
      return;
    }
    if (selected_menu_value == 1)
    {
      TWindow__close((void *)((int) ((RecoveredFields_8021E5D8_arg0 *) ((u8 *)this))->field_2C));
      ((RecoveredFields_8021E5D8_arg0 *) ((u8 *)this))->field_2C = 0U;
      this->set_field_20(4);
      return;
    }
    goto block_12;
  }
  block_12:
  temp_r3_4 = ((RecoveredFields_8021E5D8_arg0 *) ((u8 *)this))->field_2C;
  if ((temp_r3_4 != 0U) && (((TWindowSubComCard *)temp_r3_4)->get_status_flag() != 0))
  {
    TWindow__close((void *)((int) ((RecoveredFields_8021E5D8_arg0 *) ((u8 *)this))->field_2C));
    ((RecoveredFields_8021E5D8_arg0 *) ((u8 *)this))->field_2C = 0U;
    ((TShopWindowBase *)((u8 *)this))->set_field_20(4);
  }
}

void TShopGetItemWindow::update_input_number() {
    u32 w;
    w = this->m_30;
    if ((w != 0U) && (((TWindowInputNumber *)w)->is_confirmed() != 0)) {
        if ((u32) this->m_2c == 0U) {
            this->m_2c = (u32)create_yes_no_window(get_window_layout_position(0x2B), (u16) get_entity_id(this->m_24), 0, 0);
            ((TCheckRoomSequence *)(this->m_2c))->set_ready_flag();
            ((TUnk_804CDFE8 *)(this->m_2c))->set_position_xy(get_scale__15TShopWindowBaseFv(this), get_scale__15TShopWindowBaseFv(this));
        }
        this->m_54 = ((TShopEquipmentSellWindow *)(this->m_30))->get_result();
        TWindow__close((void *)this->m_30);
        this->m_30 = 0U;
        set_field_20(3);
        return;
    }
    w = this->m_30;
    if ((w != 0U) && (((TShopEquipmentSellWindow *)w)->is_confirmed() != 0)) {
        TWindow__close((void *)this->m_30);
        this->m_30 = 0U;
        set_field_20(4);
    }
}

s32 TShopGetItemWindow::handle_withdraw_list_input() {
    s32 sel;
    s32 x;
    Win_8021E870 *arg0 = (Win_8021E870 *)this;
    s32 count;
    Item_8021E870 kind;
    f32 scale;
    u32 w;
    x = sub_8022397C__15TShopWindowBaseFv(arg0);
    if (arg0->f28 != 0U) {
        sel = select_cursor_entry__22TWindowSubShortCutListFv(arg0->f28);
        if (arg0->f34 != 0U && sel != arg0->f58) {
            if (copy_item_record__18TCheckRoomSequenceFiPvi(sel, &arg0->item, x) != 0) {
                ((TWindowHelpItem *)(arg0->f34))->set_displayed_item_colored((u32)&arg0->item);
            }
            arg0->f58 = sel;
        }
    }
    if (sub_802239EC__13TShopSequenceFv(arg0) != 0) {
        ((TShopWindowBase *)arg0)->set_field_20(7);
        return;
    }
    if (sub_80223A48__15TShopWindowBaseFv(arg0) != 0) {
        if (copy_bank_item_with_stack_limit(select_cursor_entry__22TWindowSubShortCutListFv(arg0->f28), &kind.kind, &count, x) != 0) {
            if (kind.kind == 3 && count > 1) {
                void *obj = __nw__7TObjectFUl(0x7C);
                if (obj != NULL) {
                    sel = (s16)((TShopSequence *)arg0)->get_child_field1c();
                    obj = (void *)__ct__18TWindowInputNumberFPvllls(obj, get_window_layout_position(0x2B), 1, count, 1, sel);
                }
                arg0->f30 = (u32)obj;
                if (arg0->f30 != 0U && TLobby::is_camera_ctrl_active() > 2) {
                    ((TCheckRoomSequence *)(arg0->f30))->set_position(lbl_805DC6F0, lbl_805DC6F0);
                }
                ((TShopWindowBase *)arg0)->set_field_20(2);
                return;
            }
            sel = (u16)get_entity_id(arg0->f24);
            arg0->f2C = (u32)create_yes_no_window(get_window_layout_position(0x2B), sel, 0, 0);
            ((TCheckRoomSequence *)(arg0->f2C))->set_ready_flag();
            scale = get_scale__15TShopWindowBaseFv(arg0);
            ((TUnk_804CDFE8 *)(arg0->f2C))->set_position_xy(get_scale__15TShopWindowBaseFv(arg0), scale);
            ((TShopWindowBase *)arg0)->set_field_20(3);
        }
    }
}

void TShopGetItemWindow::rebuild_item_list() {
    u16 id;
    s32 x;
    s32 sel;
    s32 i;
    void *obj;
    Win_8021EA48 *arg0 = (Win_8021EA48 *)this;
    arg0->f54 = 1;
    x = sub_8022397C__15TShopWindowBaseFv(arg0);
    arg0->f50 = get_room_table_entry__18TCheckRoomSequenceFi();
    if (arg0->f50 == 0) {
        arg0->m4(0x3E, 1);
        ((TShopWindowBase *)arg0)->set_field_20(6);
        if (arg0->f28 != 0U) {
            ((TShopArmorListWindow *)(arg0->f28))->reset_list();
        }
    } else {
    if (arg0->f28 == 0U) {
        Item_8021EA48 item;
        s32 count;
        arg0->f28 = create_item_list_window(get_shop_text(0x30), 0xC8, get_entity_id(arg0->f24));
        TWindowSetLevelUp__sub_8026DE28(arg0->f28, 0xC8);
        for (i = 0; i < 0xC8; i++) {
            if (copy_bank_item_with_stack_limit(i, &item, &count, x) != 0) {
                if (count > 1) {
                    add_item_info_entry__20TWindowSubStatusDispFlll(arg0->f28, &item, i, count);
                } else {
                    add_item_info_entry__20TWindowSubStatusDispFlll(arg0->f28, &item, i, 0);
                }
            }
        }
        calc_list_content_extent(arg0->f28);
        sel = ((TShopGetItemWindow *)(arg0->f28))->get_cursor_index();
    } else {
        Item_8021EA48 item;
        s32 count;
        s32 j;
        ((TShopArmorListWindow *)(arg0->f28))->save_cursor_selection();
        ((TShopArmorListWindow *)(arg0->f28))->reset_list();
        for (j = 0; j < 0xC8; j++) {
            if (copy_bank_item_with_stack_limit(j, &item, &count, x) != 0) {
                if (count > 1) {
                    add_item_info_entry__20TWindowSubStatusDispFlll(arg0->f28, &item, j, count);
                } else {
                    add_item_info_entry__20TWindowSubStatusDispFlll(arg0->f28, &item, j, 0);
                }
            }
        }
        ((TShopArmorListWindow *)(arg0->f28))->clamp_selection_to_valid_entry();
        calc_list_content_extent(arg0->f28);
        ((TWindowSubItem *)((void *)arg0->f28))->clear_selected_and_update_entry();
        sel = ((TShopGetItemWindow *)(arg0->f28))->get_cursor_index();
    }
    if (arg0->f34 == 0U) {
        if (copy_item_record__18TCheckRoomSequenceFiPvi(sel, &arg0->item, x) != 0) {
            obj = __nw__7TObjectFUl(0xBC);
            if (obj != NULL) {
                id = (u16)get_entity_id(arg0->f24);
                obj = (void *)__ct__15TWindowHelpItemFPvUs(obj, get_window_layout_position(0x27), id);
            }
            arg0->f34 = (u32)obj;
            if (arg0->f34 != 0U && TLobby::is_camera_ctrl_active() > 2) {
                ((TLobby *)(arg0->f34))->set_position(lbl_805DC6F0, lbl_805DC6F0);
            }
            ((TWindowHelpItem *)(arg0->f34))->set_displayed_item_colored((u32)&arg0->item);
            arg0->f58 = sel;
        }
    } else if (copy_item_record__18TCheckRoomSequenceFiPvi(sel, &arg0->item, x) != 0) {
        ((TWindowHelpItem *)(arg0->f34))->set_displayed_item_colored((u32)&arg0->item);
        arg0->f58 = sel;
    }
    ((TShopWindowBase *)arg0)->set_field_20(1);
    }
}

void TShopGetItemWindow::vfunc_11() {
    u8 *arg0 = (u8 *)this;
    s32 (*temp_r12)(s32);
    s32 (*temp_r12_2)(s32);
    switch (*(u32 *)((s8 *)arg0 + 0x20)) {
    case 0:
        ((TShopGetItemWindow *)arg0)->rebuild_item_list();
        return;
    case 1:
        ((TShopGetItemWindow *)arg0)->handle_withdraw_list_input();
        return;
    case 2:
        ((TShopGetItemWindow *)arg0)->update_input_number();
        return;
    case 3:
        ((TShopGetItemWindow *)arg0)->handle_withdraw_confirm();
        return;
    case 4:
        ((TShopGetItemWindow *)arg0)->close();
        return;
    case 6:
        temp_r12 = *(s32 (**)(s32))((s8 *)arg0 + 0x64);
        if (temp_r12 != NULL) {
            temp_r12(*(s32 *)((s8 *)arg0 + 0x5C));
        }
        queue_destruction__7TObjectFv((arg0));
        return;
    case 7:
        temp_r12_2 = *(s32 (**)(s32))((s8 *)arg0 + 0x60);
        if (temp_r12_2 != NULL) {
            temp_r12_2(*(s32 *)((s8 *)arg0 + 0x5C));
        }
        queue_destruction__7TObjectFv((arg0));
    default:
        return;
    }
}

void *__dt__18TShopGetItemWindowFv(TShopGetItemWindow *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__18TShopGetItemWindow;
        if (*(void **)((s8 *)arg0 + 0x28) != NULL) { TWindow__close(*(void **)((s8 *)arg0 + 0x28)); arg0->m_28 = 0; }
        if (*(void **)((s8 *)arg0 + 0x2C) != NULL) { TWindow__close(*(void **)((s8 *)arg0 + 0x2C)); arg0->m_2c = 0; }
        if (*(void **)((s8 *)arg0 + 0x30) != NULL) { TWindow__close(*(void **)((s8 *)arg0 + 0x30)); arg0->m_30 = 0; }
        if (*(void **)((s8 *)arg0 + 0x34) != NULL) { TWindow__close(*(void **)((s8 *)arg0 + 0x34)); arg0->m_34 = 0; }
        __dt__15TShopWindowBaseFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern void *TShopGetItemWindow__class_name;

void *TShopGetItemWindow__ct(void *shop_get_item_window, void *arg1, void *arg2, void *arg3) {
    __ct__15TShopWindowBaseFv(shop_get_item_window);
    *(s32 **)((s8 *)shop_get_item_window + 0x18) = __vt__18TShopGetItemWindow;
    *(void * *)&((TShopGetItemWindow *)shop_get_item_window)->m_name = TShopGetItemWindow__class_name;
    ((TShopGetItemWindow *)shop_get_item_window)->m_20 = 0;
    *(void **)((s8 *)shop_get_item_window + 0x24) = arg3;
    ((TShopGetItemWindow *)shop_get_item_window)->m_54 = 1;
    ((TShopGetItemWindow *)shop_get_item_window)->m_4c = 0;
    ((TShopGetItemWindow *)shop_get_item_window)->m_58 = 0;
    ((TShopGetItemWindow *)shop_get_item_window)->m_60 = 0;
    ((TShopGetItemWindow *)shop_get_item_window)->m_64 = 0;
    ((TShopGetItemWindow *)shop_get_item_window)->m_28 = 0;
    ((TShopGetItemWindow *)shop_get_item_window)->m_2c = 0;
    ((TShopGetItemWindow *)shop_get_item_window)->m_30 = 0;
    ((TShopGetItemWindow *)shop_get_item_window)->m_34 = 0;
    *(void **)((s8 *)shop_get_item_window + 0x5C) = arg2;
    init__9TItemDataFv((void *)((char *)shop_get_item_window + 56));
    return shop_get_item_window;
}

}
