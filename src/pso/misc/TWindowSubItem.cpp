#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TLobby_80132ED0.h"
#include "pso/misc/TWindowCtrl_8024A054.h"
#include "pso/misc/TWindowSubStatusDisp_802671F0.h"
#include "pso/map/FloorArea.h"
#include "pso/misc/TWindowMenu.h"
#include "pso/misc/TWindowSubComCardList.h"
#include "pso/misc/TWindowSubShortCutList.h"
#include "pso/misc/TWindowMenuIconLine.h"
#include "pso/misc/TWindowSubItem.h"
#include "pso/item/TItem.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOSwitchItem.h"
#include "pso/misc/TShopEquipmentSellWindow.h"
#include "pso/misc/TShopGetItemWindow.h"
#include "pso/misc/TShopJudgmentItemWindow.h"
#include "pso/misc/TWindowOptionCtrl.h"
#include "pso/misc/TWindowShortListCtrl.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/object/TObjCityMainWarp.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/TWindowInputNumber.h"
#include "pso/map/FloorArea.h"

struct Base_A_80279714 { char pad[0x18]; };
struct V_A_80279714 : Base_A_80279714 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual s32 m31();
};

struct ItemData_80279754 {
    u8 b[0x14];
};

struct VBase_18_1de278 { char pad[0x18]; };

struct VObj_18_1de278 : VBase_18_1de278 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual s32 m7();
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
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual s32 m34();
};

struct Pad_80279FFC { u8 pad0[0x20]; u8 f20[0x30]; };

extern "C" {
void TWindowSubItem__sub_8027AA30(u8 *arg0);
s32 TWindowSubItem__sub_8027AA78(s32 arg0);
s32 get_message_10__20TWindowSubStatusDispFl(s32);
s32 set_depth__11TWindowBaseFf(s32);
s32 TWindowSubEquip__sub_80263AF8(s32, s32);
s32 align_menu_entry_positions(int);
s32 forward_trade_action_default__16TObjCityMainWarpFPviii(s32, s32, s32, s32);
s32 get_window_layout_position(s32);
s32 get_player_by_client_id(s32);
s32 TObjPlayer__sub_801B7B58(int, int, int);
s32 get_cursor_value__19TWindowMenuIconLineFv(int);
s32 check_equip_requirements__5TItemFP10TObjPlayerPs(int, int, void *);
}
s32 create_titled_window_menu(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void add_item_purpose_actions(TWindowSubItem *arg0, s32 arg1, s32 arg2);
struct En_8027AA80 { u16 flags; u8 pad2[0x2A]; u32 c2c; u32 c30; u32 c34; };
extern "C" {
s32 is_flag_4_set__20TWindowSubStatusDispFv();

struct Wn_8027AA80 { u8 pad0[0x76]; s16 f76; };
struct En_8027AB10 { u16 flags; u8 pad2[0x2A]; u32 c2c; u32 c30; u32 c34; };

struct Wn_8027AB10 { u8 pad0[0x76]; s16 f76; };
struct Quest_8027ABFC { u8 pad[0x20]; s32 count; };
struct Player_8027ABFC { u8 pad[0xD00]; s32 inv; };
struct Win_8027ABFC { u8 pad0[0x20]; s16 id; u8 pad1[0x72 - 0x22]; s16 sel; u8 pad2[0x8C - 0x74]; u32 n; };

void TWindowSubItem__sub_8027AB10(Wn_8027AB10 *arg0);
void populate_sub_item_list(Win_8027ABFC *arg0);
u32 get_slot_value__10TObjPlayerFPvi(s32, s8);
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, s32);
s32 TWindowShortListCtrl__check_controller_button(void *, s32);
u32 is_action_active__10TObjPlayerFv(s32);
void decrement_clamped(void *, s32);
void play_sound_effect(s32, s32, s32, s32);
s32 __nw__7TObjectFUl(s32);
s32 TWindowCtrl__sub_8024A228(s32);
u32 __ct__15TWindowHelpItemFPvUs(s32, s32, s32);
extern Pad_80279FFC controller_input_state[];
void *TWindowSubItem__ct(TWindowSubItem *arg0, s32 arg1, s32 arg2);
void *__dt__14TWindowSubItemFv(TWindowSubItem *arg0, s16 arg1);
s32 send_6x26_unequip_item__10TObjPlayerFPvPv(s32, s32);
s32 send_6x25_equip_item(s32, s32, s32);
int clamp_selection_to_valid_entry__20TShopArmorListWindowFv(void*);
int reset_list__19TWindowMenuIconLineFv(void*);
s32 TWindowHelpItem__set_displayed_item_by_id(u32);
s32 __ct__18TWindowInputNumberFPvllls(s32, s32, s32, s32, s32, s16);
int clamp_scroll_offset__20TWindowSubStatusDispFv(void*);
s32 __ct__7TObjectFP7TObject();
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
s32 close_sub_window__10TObjPlayerFv();
s32 try_send_6x27_use_item(s32, s32);
s32 create_sub_item_list_window(s32, s32 *, s32);
s32 get_array_entry__11TWindowBaseFi(void *, s16);
s32 get_cursor_pos__14TWindowSubItemFv();
s32 get_item_id__5TItemFv();
int save_cursor_selection__20TShopArmorListWindowFv(void*);

void TWindowSubItem::set_displayed_item(s32 arg1) {
    if (((u32) this->m_40 != 0U) && (arg1 != (s32) this->m_20)) {
        this->m_20 = arg1;
        TWindowHelpItem__set_displayed_item_by_id(this->m_40);
    }
}
}
s32 has_armor_with_unit_slot(TWindowSubItem *arg0, int arg1);
s32 has_armor_with_unit_slot(TWindowSubItem *window_sub_item, int arg1) {
    ItemData_80279754 d;
    s32 pl;
    u32 item;
    pl = get_player_by_client_id(window_sub_item->m_24);
    if (pl == 0) {
        return 0;
    }
    if (((TItem *)arg1)->get_item_type() != 1) {
        return 1;
    }
    if (((TItem *)arg1)->get_item_group() != 3) {
        return 1;
    }
    item = get_slot_value__10TObjPlayerFPvi(pl + 0xD04, 2);
    if (item == 0) {
        return 0;
    }
    ((TItem *)item)->copy_to_item_data((TItemData *)&d);
    return d.b[5] != 0 ? 1 : 0;
}

#pragma push
#pragma scheduling off

void TWindowSubItem::use_selected_item() {
    s32 player;
    player = get_player_by_client_id(this->m_24);
    if (player != 0) {
        TObjPlayer__sub_801B7B58(player, (int) (get_cursor_value__19TWindowMenuIconLineFv(this->m_30)), ((TWindowSubItem *)(this->m_30))->get_selected_entry());
    }
}
#pragma pop

void TWindowSubItem::close_windows(s32 arg1) {
    if (get_player_by_client_id(this->m_24) != 0U) {
        switch (arg1) {
        case 0:
            close_sub_window__10TObjPlayerFv();
            this->m_1c = 0x16;
            return;
        case 1:
            if (this->m_38 != NULL) {
                ((TWindowBase *)this->m_38)->close();
                this->m_38 = 0U;
            }
            if (this->m_34 != NULL) {
                ((TWindowBase *)this->m_34)->close();
                this->m_34 = 0U;
            }
            this->m_1c = 0xA;
            break;
        }
    }
}

void TWindowSubItem::exec_item_command(s32 arg1, s32 arg2) {
    s32 temp_r3;
    void *temp_r3_2;
    s32 t;

    temp_r3 = get_player_by_client_id(this->m_24);
    if ((temp_r3 != 0) && (temp_r3_2 = find_item_by_id(arg1), ((temp_r3_2 == NULL) == 0))) {
        switch (arg2) {
        case 3:
            break;
        case 0:
            try_send_6x27_use_item(temp_r3, arg1);
            this->m_1c = 0x16;
            break;
        case 1:
            if (get_slot_value__10TObjPlayerFPvi(temp_r3 + 0xD04, (s8) ((V_A_80279714 *) temp_r3_2)->m31()) != 0U) {
                t = get_item_id__5TItemFv();
                send_6x26_unequip_item__10TObjPlayerFPvPv(temp_r3, t);
            }
            send_6x25_equip_item(temp_r3, arg1, 0);
            this->m_1c = 0x16;
            break;
        case 2:
            send_6x26_unequip_item__10TObjPlayerFPvPv(temp_r3, arg1);
            this->m_1c = 0x16;
            break;
        }
    }
}

void TWindowSubItem::set_cursor_row_for_mode(s32 arg1) {
    switch (arg1) {
    case 3:
        this->m_1c = 0xC;
        return;
    case 4:
        this->m_1c = 0xF;
        return;
    case 5:
        this->m_1c = 0x11;
        return;
    case 6:
        this->m_1c = 0x13;
        return;
    case 7:
        this->m_1c = 6;
        return;
    case 0:
    case 1:
    case 2:
        this->m_1c = 5;
        return;
    }
}

void add_item_purpose_actions(TWindowSubItem *window_sub_item, s32 arg1, s32 arg2) {
  s32 sp8;
  s32 item;
  s32 player;
  item = ((s32)find_item_by_id((s32)((void *) arg2)));
  if (item != 0)
  {
    if (((TItem *)item)->get_usable_action_flags(2, 0) != 0U)
    {
      if ((((TItem *)item)->get_usable_action_flags(1, 0) != 0U) || (get_current_floor_area() == AREA_LOBBY))
      {
        TWindowSubComCard::draw_text_gray((s32)((void *) arg1), (s32)((int) get_message_10__20TWindowSubStatusDispFl(0x60)), 6, 0);
      }
      else
      {
        forward_trade_action_default__16TObjCityMainWarpFPviii((s32)((void *) arg1), (s32)((int) get_message_10__20TWindowSubStatusDispFl(0x60)), 6, 0);
      }
    }
    ((TItem *)(0, (int) (item & 0xFFFFFFFFu)))->get_item_type();
    if (((TItem *)item)->get_usable_action_flags(8, 0) != 0U)
    {
      if (((TItem *)item)->test_item_flags(8) != 0U)
      {
        if (get_current_floor_area() == AREA_LOBBY)
        {
          TWindowSubComCard::draw_text_gray((s32)((void *) arg1), (s32)((int) get_message_10__20TWindowSubStatusDispFl(0x61)), 6, 2);
        }
        else
        {
          forward_trade_action_default__16TObjCityMainWarpFPviii((s32)((void *) arg1), (s32)((int) get_message_10__20TWindowSubStatusDispFl(0x61)), 6, 2);
        }
      }
      else
      {
        player = get_player_by_client_id(window_sub_item->m_24);
        if (player != 0)
        {
          if (((check_equip_requirements__5TItemFP10TObjPlayerPs((int) item, (int) player, &sp8) != 0) && (has_armor_with_unit_slot((TWindowSubItem *)((void *)((void *) window_sub_item)), (int)((int) item)) != 0)) && (get_current_floor_area() != AREA_LOBBY))
          {
            forward_trade_action_default__16TObjCityMainWarpFPviii((s32)((void *) arg1), (s32)((int) get_message_10__20TWindowSubStatusDispFl(0x62)), 6, 1);
          }
          else
          {
            TWindowSubComCard::draw_text_gray((s32)((void *) arg1), (s32)((int) get_message_10__20TWindowSubStatusDispFl(0x62)), 6, 1);
          }
        }
      }
    }
    if ((get_current_floor_area() == AREA_LOBBY) || (((TItem *)item)->get_usable_action_flags(0x10, 0) != 0U))
    {
      TWindowSubComCard::draw_text_gray((s32)((void *) arg1), (s32)((int) get_message_10__20TWindowSubStatusDispFl(0x5F)), 6, 3);
    }
    else
    {
      forward_trade_action_default__16TObjCityMainWarpFPviii((s32)((void *) arg1), (s32)((int) get_message_10__20TWindowSubStatusDispFl(0x5F)), 6, 3);
    }
    if (get_current_floor_area() == AREA_LOBBY)
    {
      TWindowSubComCard::draw_text_gray((s32)((void *) arg1), (s32)((int) get_message_10__20TWindowSubStatusDispFl(0x63)), 6, 7);
      return;
    }
    forward_trade_action_default__16TObjCityMainWarpFPviii((s32)((void *) arg1), (s32)((int) get_message_10__20TWindowSubStatusDispFl(0x63)), 6, 7);
  }
}

void TWindowSubItem::draw_slot(s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_r31;
    s32 temp_r3;

    temp_r3 = (u32)__cntlzw(4 - (arg3 & 0xF)) >> 5;
    temp_r31 = temp_r3 + 4;
    if ((is_current_area_item_enabled() == 0) || (is_boss_area() != 0)) {
        TWindowSubComCard::draw_text_gray(arg2, (s32)(get_localized_text_entry(0x10, 0xF)), 6, temp_r31);
        return;
    }
    forward_trade_action_default__16TObjCityMainWarpFPviii(arg2, (s32)(get_localized_text_entry(0x10, 0xF)), 0x26, temp_r31);
}

void TWindowSubItem::add_meseta_purpose_actions(s32 arg0, s32 arg1) {
    if (get_current_floor_area() == AREA_LOBBY) {
        TWindowSubComCard::draw_text_gray(arg1, (s32)(get_message_10__20TWindowSubStatusDispFl(0x5F)), 6, 6);
        return;
    }
    forward_trade_action_default__16TObjCityMainWarpFPviii(arg1, (s32)(get_message_10__20TWindowSubStatusDispFl(0x5F)), 6, 6);
}

extern const f32 lbl_805DD630;

s32 TWindowSubItem::create_count_input(s32 maximum) {
    s32 storage;

    storage = __nw__7TObjectFUl(0x7C);
    if (storage != 0) {
        storage = __ct__18TWindowInputNumberFPvllls(storage, get_window_layout_position(5), 1, maximum, 1, (s16) this->m_24);
    }
    ((TWindowInputNumber *)storage)->create(get_message_10__20TWindowSubStatusDispFl(0x28));
    TWindowSubEquip__sub_80263AF8(this->m_2c, 3);
    set_depth__11TWindowBaseFf(storage);
    ((TWindowInputNumber *)storage)->set_value(lbl_805DD630);
    ((TWindowSubItem *)storage)->set_flag60_bit10();
    return storage;
}

s32 TWindowSubItem::create_menu_window() {
    s32 titled_window_menu;
    titled_window_menu = create_titled_window_menu(((int)get_window_layout_position(6)), 2, get_message_10__20TWindowSubStatusDispFl(0x27), this->m_24);
    forward_trade_action_default__16TObjCityMainWarpFPviii(titled_window_menu, (s32)((int) (get_message_10__20TWindowSubStatusDispFl(0x5D))), 6, 0);
    forward_trade_action_default__16TObjCityMainWarpFPviii(titled_window_menu, (s32)((int) (get_message_10__20TWindowSubStatusDispFl(0x5E))), 6, 1);
    TWindowSubEquip__sub_80263AF8(this->m_2c, 2);
    set_depth__11TWindowBaseFf(titled_window_menu);
    ((TWindowSubComCardList *)titled_window_menu)->set_flag70_bit10();
    ((TWindowSubComCardList *)titled_window_menu)->update_layout_height(lbl_805DD630);
    align_menu_entry_positions(titled_window_menu);
    return titled_window_menu;
}

s32 TWindowSubItem::open_purpose_window(s32 arg1) {
    s32 titled_window_menu;
    titled_window_menu = create_titled_window_menu(((int)get_window_layout_position(4)), 3, get_message_10__20TWindowSubStatusDispFl(0x26), this->m_24);
    if (arg1 == -0xFF) {
        TWindowSubItem::add_meseta_purpose_actions((s32)this, titled_window_menu);
    } else if ((s32) (arg1 & 0xFFFFFFF0) == -0x10) {
        TWindowSubItem::draw_slot((s32)this, titled_window_menu, arg1);
    } else {
        add_item_purpose_actions((TWindowSubItem *)this, titled_window_menu, arg1);
    }
    TWindowSubEquip__sub_80263AF8(this->m_2c, 1);
    set_depth__11TWindowBaseFf(titled_window_menu);
    ((TWindowSubComCardList *)titled_window_menu)->set_flag70_bit10();
    ((TWindowSubComCardList *)titled_window_menu)->update_layout_height(lbl_805DD630);
    align_menu_entry_positions(titled_window_menu);
    return titled_window_menu;
}

void TWindowSubItem::render() {  }

extern s32 __vt__14TWindowSubItem[];

#define F(t, o) (*(t *)(arg0 + (o)))
#define LIST F(s32, 0x30)
#define BACK_PRESSED(idx) (TWindowShortListCtrl__check_controller_button(controller_input_state[idx].f20, 2) != 0 || test_flag_4c__23TAdSinglePlyChrSelectGCFv(controller_input_state[4].f20, 2) != 0)
void TWindowSubItem::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 p;
    s32 idx;
    u32 w;
    p = get_player_by_client_id(F(s32, 0x24));
    if (p != 0) {
        idx = is_player_input_active(F(s32, 0x24));
        switch (F(u8, 0x1C)) {
        case 0:
        case 1:
            if (F(u32, 0x3C) != 0) {
                ((TWindowBase *)(F(u32, 0x3C)))->close();
                F(u32, 0x3C) = 0;
            }
            if (F(u32, 0x38) != 0) {
                ((TWindowBase *)(F(u32, 0x38)))->close();
                F(u32, 0x38) = 0;
            }
            if (F(u32, 0x34) != 0) {
                ((TWindowBase *)(F(u32, 0x34)))->close();
                F(u32, 0x34) = 0;
            }
            if (F(u32, 0x40) == 0) {
                w = __nw__7TObjectFUl(0xBC);
                if (w != 0) {
                    w = __ct__15TWindowHelpItemFPvUs(w, get_window_layout_position(2), F(s32, 0x24));
                }
                F(u32, 0x40) = w;
                TWindowSubEquip__sub_80263AF8(F(s32, 0x2C), 4);
                set_depth__11TWindowBaseFf(F(u32, 0x40));
                F(s32, 0x20) = -1;
            }
            ((TWindowSubItem *)LIST)->refresh();
            ((TWindowMenuIconLine *)LIST)->clear_decided();
            F(u8, 0x1C) = 2;
        case 2:
            set_displayed_item(get_cursor_value__19TWindowMenuIconLineFv(LIST));
            if (((TWindowMenuIconLine *)LIST)->is_cancelled() != 0) {
                ((VObj_18_1de278 *) F(u8 *, 0x2C))->m7();
                F(u8, 0x1C) = 0x17;
                return;
            }
            if (((TWindowMenuIconLine *)LIST)->is_decided() != 0) {
                F(u8, 0x1C) = 3;
                return;
            }
            break;
        case 3:
            if (F(u32, 0x3C) != 0) {
                ((TWindowBase *)(F(u32, 0x3C)))->close();
                F(u32, 0x3C) = 0;
            }
            if (F(u32, 0x38) != 0) {
                ((TWindowBase *)(F(u32, 0x38)))->close();
                F(u32, 0x38) = 0;
            }
            if (F(u32, 0x40) != 0) {
                ((TWindowBase *)(F(u32, 0x40)))->close();
                F(u32, 0x40) = 0;
            }
            if (F(u32, 0x34) == 0) {
                F(u32, 0x34) = ((TWindowSubItem *)arg0)->open_purpose_window(get_cursor_value__19TWindowMenuIconLineFv(LIST));
            }
            ((TWindowSubComCard *)(F(u32, 0x34)))->clear_flag_and_release();
            ((TWindowSubComCard *)(F(u32, 0x34)))->clear_transition_flag();
            F(u8, 0x1C) = 4;
        case 4:
            if (((TWindowMenu *)(F(u32, 0x34)))->get_selected_value() == 0) {
                TWindowShortListCtrl::assign_item_to_palette(get_cursor_value__19TWindowMenuIconLineFv(LIST), F(s32, 0x24));
            }
            if (((TWindowMenu *)(F(u32, 0x34)))->is_cancelled() != 0) {
                F(u8, 0x1C) = 1;
            }
            if (((TWindowMenu *)(F(u32, 0x34)))->is_decided() != 0) {
                set_cursor_row_for_mode((s32)(((TWindowMenu *)(F(u32, 0x34)))->get_selected_value()));
                return;
            }
            break;
        case 5:
            if (BACK_PRESSED(idx)) {
                play_sound_effect(0x52F16, 0, 0, 0);
                F(u8, 0x1C) = 3;
            }
            if (TWindowSubItem::is_usable(p) != 0) {
                exec_item_command(get_cursor_value__19TWindowMenuIconLineFv(LIST), ((TWindowMenu *)(F(u32, 0x34)))->get_selected_value());
                return;
            }
            break;
        case 6:
            ((TWindowOptionCtrl *)(F(u32, 0x34)))->open();
            F(u32, 0x38) = create_menu_window();
            F(u8, 0x1C) = 7;
        case 7:
            if (((TWindowMenu *)(F(u32, 0x38)))->is_cancelled() != 0) {
                F(u8, 0x1C) = 3;
            }
            if (((TWindowMenu *)(F(u32, 0x38)))->is_decided() != 0) {
                close_windows(((TWindowMenu *)(F(u32, 0x38)))->get_selected_value());
                return;
            }
            break;
        case 8: {
            s16 cur = ((TShopGetItemWindow *)LIST)->get_cursor_index();
            ((TWindowSubItem *)LIST)->refresh();
            TWindowSubItem__sub_8027AB10((Wn_8027AB10 *) LIST);
            ((TWindowSubItem *)LIST)->gray_out_unusable_entries();
            ((TWindowSubItem *)LIST)->set_field_74(cur);
            ((TWindowMenuIconLine *)LIST)->clear_decided();
            ((TWindowSubItem *)LIST)->reset_selected();
            F(u8, 0x1C) = 9;
        }
        case 9:
            if (((TWindowMenuIconLine *)LIST)->is_cancelled() != 0) {
                ((VObj_18_1de278 *) F(u8 *, 0x2C))->m7();
                F(u8, 0x1C) = 0x17;
                return;
            }
            if (((TWindowMenuIconLine *)LIST)->is_decided() != 0) {
                ((TWindowMenuIconLine *)LIST)->clear_decided();
                F(u8, 0x1C) = 0xA;
                return;
            }
            break;
        case 10:
            TWindowSubItem__sub_8027AB10((Wn_8027AB10 *) LIST);
            ((TWindowSubItem *)LIST)->gray_out_unusable_entries();
            TWindowSubItem__sub_8027AA30((u8 *) LIST);
            ((TWindowMenuIconLine *)LIST)->clear_decided();
            F(u8, 0x1C) = 0xB;
        case 11:
            if (((TWindowMenuIconLine *)LIST)->is_cancelled() != 0) {
                F(u8, 0x1C) = 8;
                return;
            }
            if (((TWindowMenuIconLine *)LIST)->is_decided() != 0) {
                use_selected_item();
                ((TWindowMenuIconLine *)LIST)->clear_decided();
                F(u8, 0x1C) = 8;
                return;
            }
            break;
        case 12: {
            s32 n = ((VObj_18_1de278 *) find_item_by_id(get_cursor_value__19TWindowMenuIconLineFv(LIST)))->m34();
            if (n <= 1) {
                F(s32, 0x28) = 1;
                F(u8, 0x1C) = 0xE;
                return;
            }
            ((TWindowOptionCtrl *)(F(u32, 0x34)))->open();
            if (F(u32, 0x3C) == 0) {
                F(u32, 0x3C) = create_count_input(n);
            }
            ((TWindowSubItem *)((void *) F(u32, 0x3C)))->clear_flag_and_release();
            F(u8, 0x1C) = 0xD;
        }
        case 13:
            if (((TShopEquipmentSellWindow *)(F(u32, 0x3C)))->is_confirmed() != 0) {
                F(u8, 0x1C) = 3;
            }
            if (((TWindowInputNumber *)(F(u32, 0x3C)))->is_confirmed() != 0) {
                F(s32, 0x28) = ((TShopEquipmentSellWindow *)(F(u32, 0x3C)))->get_result();
                F(u8, 0x1C) = 0xE;
                return;
            }
            break;
        case 14:
            if (BACK_PRESSED(idx)) {
                play_sound_effect(0x52F16, 0, 0, 0);
                F(u8, 0x1C) = 3;
            }
            if (TWindowSubItem::is_usable(p) != 0) {
                ((TObjPlayer *)p)->request_item_drop(get_cursor_value__19TWindowMenuIconLineFv(LIST), F(s32, 0x28));
                F(u8, 0x1C) = 0x16;
                return;
            }
            break;
        case 15:
            F(u8, 0x1C) = 0x10;
        case 16:
            if (BACK_PRESSED(idx)) {
                play_sound_effect(0x52F16, 0, 0, 0);
                F(u8, 0x1C) = 1;
            }
            p = get_player_by_client_id(F(s32, 0x24));
            if (p != 0 && TWindowSubItem::is_usable(p) != 0 && TWindowCtrl__sub_8024A228(F(s32, 0x24)) != 0) {
                ((TObjPlayer *)p)->send_trap_packet(get_cursor_value__19TWindowMenuIconLineFv(LIST) & 0xF);
                F(u8, 0x1C) = 1;
                return;
            }
            break;
        case 17:
            F(u8, 0x1C) = 0x12;
        case 18:
            if (BACK_PRESSED(idx)) {
                play_sound_effect(0x52F16, 0, 0, 0);
                F(u8, 0x1C) = 1;
            }
            p = get_player_by_client_id(F(s32, 0x24));
            if (p != 0 && TWindowSubItem::is_usable(p) != 0 && TAdSinglePlyChrSelectGC::create_if_key_pressed() != 0) {
                decrement_clamped((void *)(p + 0x7C8), 1);
                F(u8, 0x1C) = 1;
                return;
            }
            break;
        case 19: {
            Quest_8027ABFC *q = (Quest_8027ABFC *)((TObjPlayer *)p)->get_stats();
            s32 n;
            if (q == NULL) {
                F(u8, 0x1C) = 0x16;
                return;
            }
            n = q->count;
            if (n <= 1) {
                if (n == 1) {
                    F(s32, 0x28) = 1;
                    F(u8, 0x1C) = 0x15;
                    return;
                }
                F(u8, 0x1C) = 0x16;
                return;
            }
            ((TWindowOptionCtrl *)(F(u32, 0x34)))->open();
            if (F(u32, 0x3C) == 0) {
                F(u32, 0x3C) = create_count_input(n);
            }
            ((TWindowSubItem *)((void *) F(u32, 0x3C)))->clear_flag_and_release();
            F(u8, 0x1C) = 0x14;
        }
        case 20:
            if (((TShopEquipmentSellWindow *)(F(u32, 0x3C)))->is_confirmed() != 0) {
                F(u8, 0x1C) = 3;
            }
            if (((TWindowInputNumber *)(F(u32, 0x3C)))->is_confirmed() != 0) {
                F(s32, 0x28) = ((TShopEquipmentSellWindow *)(F(u32, 0x3C)))->get_result();
                F(u8, 0x1C) = 0x15;
                return;
            }
            break;
        case 21:
            if (BACK_PRESSED(idx)) {
                play_sound_effect(0x52F16, 0, 0, 0);
                F(u8, 0x1C) = 3;
            }
            if (TWindowSubItem::is_usable(p) != 0) {
                ((TObjPlayer *)p)->request_meseta_drop(F(s32, 0x28));
                F(u8, 0x1C) = 0x16;
                return;
            }
            break;
        case 22:
            if (is_action_active__10TObjPlayerFv(p) == 0) {
                F(u8, 0x1C) = 1;
            }
            break;
        case 23:
            break;
        }
    }
}

void *__dt__14TWindowSubItemFv(TWindowSubItem *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__14TWindowSubItem;
        if (*(void **)((s8 *)arg0 + 0x3C) != NULL) { ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x3C)))->close(); arg0->m_3c = 0; }
        if (*(void **)((s8 *)arg0 + 0x38) != NULL) { ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x38)))->close(); arg0->m_38 = 0; }
        if (*(void **)((s8 *)arg0 + 0x34) != NULL) { ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x34)))->close(); arg0->m_34 = 0; }
        if (*(void **)((s8 *)arg0 + 0x40) != NULL) { ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x40)))->close(); arg0->m_40 = 0; }
        if (*(void **)((s8 *)arg0 + 0x30) != NULL) { ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x30)))->close(); arg0->m_30 = 0; }
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern s32 lbl_8044F998[];
extern s32 TWindowSubItem__class_name;

void *TWindowSubItem__ct(TWindowSubItem *window_sub_item, s32 arg1, s32 arg2) {
    __ct__7TObjectFP7TObject();
    *(s32 **)((s8 *)window_sub_item + 0x18) = __vt__14TWindowSubItem;
    *(s32 *)((s8 *)window_sub_item + 0) = (s32) TWindowSubItem__class_name;
    window_sub_item->m_2c = arg1;
    window_sub_item->m_24 = arg2;
    window_sub_item->m_30 = create_sub_item_list_window(get_window_layout_position(3), lbl_8044F998, window_sub_item->m_24);
    TWindowSubEquip__sub_80263AF8(window_sub_item->m_2c, 0);
    set_depth__11TWindowBaseFf(window_sub_item->m_30);
    ((TWindowSubShortCutList *)(window_sub_item->m_30))->set_flag70_bit10();
    window_sub_item->m_40 = 0;
    window_sub_item->m_34 = 0;
    window_sub_item->m_38 = 0;
    window_sub_item->m_3c = 0;
    window_sub_item->m_20 = -1;
    window_sub_item->m_28 = 0;
    window_sub_item->m_1c = 0;
    return window_sub_item;
}

void TWindowSubItem::set_flag60_bit10() { *(u16*)((char*)this + 0x60) |= 0x10; }
void TWindowSubItem::clear_flag_and_release() {
    *(u16 *)((s8 *)this + 0x60) = (u16) (*(u16 *)((s8 *)this + 0x60) & 0xFFFFFFFD);
    if ((u32) *(u32 *)((s8 *)this + 0x70) != 0U) {
        ((TWindowSubStatusDisp *)(*(s32 *)((s8 *)this + 0x70)))->set_entry_state(1);
    }
}

void TWindowSubItem__sub_8027AA30(u8 *arg0) {
    *(s16 *)((s8 *)arg0 + 0x88) = (s16) *(s16 *)((s8 *)arg0 + 0x74);
}

void TWindowSubItem::reset_selected() { *(s16*)((char*)this + 0x88) = -1; }
void TWindowSubItem::set_field_74(s16 v) { *(s16*)((char*)this + 0x74) = v; }
s32 TWindowSubItem::get_selected_entry() {
    get_array_entry__11TWindowBaseFi(this, *(s16 *)((s8 *)this + 0x88));
    get_cursor_pos__14TWindowSubItemFv();
}

s32 TWindowSubItem__sub_8027AA78(s32 arg0) {
    return arg0 - 0x10;
}

void TWindowSubItem::gray_out_unusable_entries() {
    s32 i;
    En_8027AA80 *e;

    for (i = 0; i < ((Wn_8027AA80 *)this)->f76; i++) {
        e = (En_8027AA80 *)((s32 (*)(void *, s32))get_array_entry__11TWindowBaseFi)(this, i);
        if (is_flag_4_set__20TWindowSubStatusDispFv() != 0 && ((s32 (*)(void *))get_cursor_pos__14TWindowSubItemFv)(e) == -0xFF) {
            e->c2c = 0xFFAAAAAA;
            e->c34 = 0xFF909090;
            e->flags |= 0x80;
        }
    }
}
void TWindowSubItem__sub_8027AB10(Wn_8027AB10 *arg0) {
    s32 i;
    En_8027AB10 *e;

    for (i = 0; i < arg0->f76; i++) {
        e = (En_8027AB10 *)((s32 (*)(void *, s32))get_array_entry__11TWindowBaseFi)(arg0, i);
        if (is_flag_4_set__20TWindowSubStatusDispFv() != 0 && (((s32 (*)(void *))get_cursor_pos__14TWindowSubItemFv)(e) & -0x10) == -0x10) {
            e->c2c = 0xFFAAAAAA;
            e->c30 = 0xFF909090;
            e->c34 = 0xFF909090;
            e->flags |= 0x80;
        }
    }
}

void TWindowSubItem::refresh() { save_cursor_selection__20TShopArmorListWindowFv(this); reset_list__19TWindowMenuIconLineFv(this); populate_sub_item_list((Win_8027ABFC*)(this)); clamp_selection_to_valid_entry__20TShopArmorListWindowFv(this); clamp_scroll_offset__20TWindowSubStatusDispFv(this); reset_selected(); }

void populate_sub_item_list(Win_8027ABFC *arg0) {
    s32 ids[30];
    Player_8027ABFC *pl;
    Quest_8027ABFC *q;
    u32 i;
    void *it;

    pl = (Player_8027ABFC *)get_player_by_client_id(arg0->id);
    if (pl != NULL) {
        arg0->n = ((TObjPlayer *)(pl->inv))->run_and_get_result((int)ids);
        for (i = 0; i < arg0->n; i++) {
            it = find_item_by_id(ids[i]);
            if (it != NULL) {
                ((TShopJudgmentItemWindow *)arg0)->add_list_entry((s32)it, ids[i]);
            }
        }
        for (i = 0; i < 5; i++) {
            add_battle_stat_entry(arg0, i, TWindowSubItem__sub_8027AA78(i), 0);
        }
        q = (Quest_8027ABFC *)((TObjPlayer *)pl)->get_stats();
        if (q != NULL && q->count > 0) {
            push_status_disp_entry(arg0, q->count, -0xFF);
        }
        if (arg0->sel <= 0) {
            ((TWindowSubStatusDisp *)arg0)->add_list_entry(-1);
        }
        ((TWindowMenuIconLine *)arg0)->calc_content_extent();
    }
}
