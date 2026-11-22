#include "pso/unk/TWindowLayoutEntry.h"
#pragma defer_codegen on

#include "types.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/ui/window/TWindowCtrl_8024A054.h"
#include "pso/ui/window/TWindowSubStatusDisp_802671F0.h"
#include "pso/map/FloorArea.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowSubShortCutList.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/item/TItem.h"
#include "pso/unk/TLobby.h"
#include "pso/object/switch/TOSwitchItem.h"
#include "pso/ui/city/TShopEquipmentSellWindow.h"
#include "pso/ui/city/TShopGetItemWindow.h"
#include "pso/ui/city/TShopJudgmentItemWindow.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/ui/window/TWindowShortListCtrl.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/window/TWindowInputNumber.h"
#include "pso/ui/city/TShopArmorListWindow.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801A6D60.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TPlyItem.h"

#pragma readonly_strings on

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
};

struct Pad_80279FFC { u8 pad0[0x20]; u8 f20[0x30]; };

extern "C" {
void TWindowSubItem__sub_8027AA30(u8 *arg0);
s32 TWindowSubItem__sub_8027AA78(s32 arg0);
s32 set_depth__11TWindowBaseFf(s32);
s32 TWindowSubEquip__sub_80263AF8(s32, s32);
s32 forward_trade_action_default__16TObjCityMainWarpFPviii(s32, s32, s32, s32);
saddr get_window_layout_position(s32);
saddr get_player_by_client_id(s32);
s32 TObjPlayer__sub_801B7B58(int, int, int);
}

saddr create_titled_window_menu(saddr arg0, s32 arg1, saddr arg2, s32 arg3);
void add_item_purpose_actions(TWindowSubItem *arg0, saddr arg1, saddr arg2);
struct En_8027AA80 { u16 flags; u8 pad2[0x2A]; u32 c2c; u32 c30; u32 c34; };

extern "C" {
struct Wn_8027AA80 { u8 pad0[0x76]; s16 f76; };
struct En_8027AB10 { u16 flags; u8 pad2[0x2A]; u32 c2c; u32 c30; u32 c34; };
struct Wn_8027AB10 { u8 pad0[0x76]; s16 f76; };
struct Quest_8027ABFC { u8 pad[0x20]; s32 count; };
struct Win_8027ABFC { u8 pad0[0x20]; s16 id; u8 pad1[0x72 - 0x22]; s16 sel; u8 pad2[0x8C - 0x74]; u32 n; };
void TWindowSubItem__sub_8027AB10(Wn_8027AB10 *arg0);
void populate_sub_item_list(Win_8027ABFC *arg0);
void decrement_clamped(void *, s32);
void play_sound_effect(s32, s32, s32, s32);
s32 __nw__7TObjectFUl(s32);
s32 TWindowCtrl__sub_8024A228(saddr);
u32 __ct__15TWindowHelpItemFPvUs(s32, s32, s32);
extern Pad_80279FFC controller_input_state[];
s32 send_6x25_equip_item(s32, s32, s32);
s32 TWindowHelpItem__set_displayed_item_by_id(u32);
s32 __ct__18TWindowInputNumberFPvllls(s32, s32, s32, s32, s32, s16);
s32 __ct__7TObjectFP7TObject();
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
s32 close_sub_window__10TObjPlayerFv();
s32 try_send_6x27_use_item(s32, s32);
s32 create_sub_item_list_window(saddr, const f32 *, s32);
}

s32 has_armor_with_unit_slot(TWindowSubItem *window_sub_item, TItem *item);
extern s32 __vt__14TWindowSubItem[];

#define F(t, o) (*(t *)(arg0 + (o)))
#define LIST F(saddr, 0x30)
#define BACK_PRESSED(idx) (TWindowShortListCtrl__check_controller_button(controller_input_state[idx].f20, 2) != 0 || test_controller_flag_4c_color(controller_input_state[4].f20, 2) != 0)
const char *TWindowSubItem__class_name = "TWindowSubItem";

// Item list window position (x, y).
extern const f32 lbl_8044F998[2] = {308.0f, 184.0f};

void populate_sub_item_list(Win_8027ABFC *arg0) {
    s32 ids[30];
    TObjPlayer *pl;
    Quest_8027ABFC *q;
    u32 i;
    void *it;

    pl = reinterpret_cast<TObjPlayer *>(get_player_by_client_id(arg0->id));
    if (pl != NULL) {
        arg0->n = pl->inventory_objects->run_and_get_result((saddr)ids);
        for (i = 0; i < arg0->n; i++) {
            it = find_item_by_id(ids[i]);
            if (it != NULL) {
                ((TShopJudgmentItemWindow *)arg0)->add_list_entry((saddr)it, ids[i]);
            }
        }
        for (i = 0; i < 5; i++) {
            add_battle_stat_entry(arg0, i, TWindowSubItem__sub_8027AA78(i), 0);
        }
        q = (Quest_8027ABFC *)pl->get_stats();
        if (q != NULL && q->count > 0) {
            push_status_disp_entry(arg0, q->count, -0xFF);
        }
        if (arg0->sel <= 0) {
            ((TWindowSubStatusDisp *)arg0)->add_list_entry(-1);
        }
        ((TWindowMenuIconLine *)arg0)->calc_content_extent();
    }
}

void TWindowSubItem::refresh() { ((TShopArmorListWindow *)this)->save_cursor_selection(); ((TWindowMenuIconLine *)this)->reset_list(); populate_sub_item_list((Win_8027ABFC*)(this)); ((TShopArmorListWindow *)this)->clamp_selection_to_valid_entry(); ((TWindowSubStatusDisp *)this)->clamp_scroll_offset(); reset_selected(); }

void TWindowSubItem__sub_8027AB10(Wn_8027AB10 *arg0) {
    s32 i;
    En_8027AB10 *e;

    for (i = 0; i < arg0->f76; i++) {
        e = (En_8027AB10 *)((TWindowBase *)arg0)->get_array_entry(i);
        if (((TWindowLayoutEntry *)e)->is_flag_4_set() != 0 && (((TWindowSubItem *)e)->get_cursor_pos() & -0x10) == -0x10) {
            e->c2c = 0xFFAAAAAA;
            e->c30 = 0xFF909090;
            e->c34 = 0xFF909090;
            e->flags |= 0x80;
        }
    }
}

void TWindowSubItem::gray_out_unusable_entries() {
    s32 i;
    En_8027AA80 *e;

    for (i = 0; i < ((Wn_8027AA80 *)this)->f76; i++) {
        e = (En_8027AA80 *)((TWindowBase *)this)->get_array_entry(i);
        if (((TWindowLayoutEntry *)e)->is_flag_4_set() != 0 && ((TWindowSubItem *)e)->get_cursor_pos() == -0xFF) {
            e->c2c = 0xFFAAAAAA;
            e->c34 = 0xFF909090;
            e->flags |= 0x80;
        }
    }
}

s32 TWindowSubItem__sub_8027AA78(s32 arg0) {
    return arg0 - 0x10;
}

s32 TWindowSubItem::get_selected_entry() {
    return ((TWindowSubItem *)((TWindowBase *)this)->get_array_entry(*(s16 *)((s8 *)this + 0x88)))->get_cursor_pos();
}

void TWindowSubItem::set_field_74(s16 v) { *(s16*)((char*)this + 0x74) = v; }

void TWindowSubItem::reset_selected() { *(s16*)((char*)this + 0x88) = -1; }

void TWindowSubItem__sub_8027AA30(u8 *arg0) {
    *(s16 *)((s8 *)arg0 + 0x88) = (s16) *(s16 *)((s8 *)arg0 + 0x74);
}

void TWindowSubItem::clear_flag_and_release() {
    *(u16 *)((s8 *)this + 0x60) = (u16) (*(u16 *)((s8 *)this + 0x60) & 0xFFFFFFFD);
    if ((u32) *(u32 *)((s8 *)this + 0x70) != 0U) {
        ((TWindowSubStatusDisp *)(*(saddr *)((s8 *)this + 0x70)))->set_entry_state(1);
    }
}

void TWindowSubItem::set_flag60_bit10() { *(u16*)((char*)this + 0x60) |= 0x10; }

void *TWindowSubItem__ct(TWindowSubItem *window_sub_item, s32 parent, s32 client_id) {
    __ct__7TObjectFP7TObject();
    *(s32 **)((s8 *)window_sub_item + 0x18) = __vt__14TWindowSubItem;
    *(s32 *)((s8 *)window_sub_item + 0) = (saddr) TWindowSubItem__class_name;
    window_sub_item->m_2c = parent;
    window_sub_item->client_id = client_id;
    window_sub_item->m_30 = create_sub_item_list_window(get_window_layout_position(3), lbl_8044F998, window_sub_item->client_id);
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

TWindowSubItem::~TWindowSubItem() {
    if (m_3c != 0) { ((TWindowBase *)m_3c)->close(); m_3c = 0; }
    if (m_38 != 0) { ((TWindowBase *)m_38)->close(); m_38 = 0; }
    if (m_34 != 0) { ((TWindowBase *)m_34)->close(); m_34 = 0; }
    if (m_40 != 0) { ((TWindowBase *)m_40)->close(); m_40 = 0; }
    if (m_30 != 0) { ((TWindowBase *)m_30)->close(); m_30 = 0; }
}

void TWindowSubItem::run_task() {
    u8 *arg0 = (u8 *)this;
    saddr p;
    s32 idx;
    u32 w;
    p = get_player_by_client_id(F(s32, 0x24));
    if (p != 0) {
        idx = is_player_input_active(F(s32, 0x24));
        switch (F(u8, 0x1C)) {
        case 0:
        case 1:
            if (F(u32, 0x3C) != 0) {
                ((TWindowBase *)(F(uaddr, 0x3C)))->close();
                F(u32, 0x3C) = 0;
            }
            if (F(u32, 0x38) != 0) {
                ((TWindowBase *)(F(uaddr, 0x38)))->close();
                F(u32, 0x38) = 0;
            }
            if (F(u32, 0x34) != 0) {
                ((TWindowBase *)(F(uaddr, 0x34)))->close();
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
            set_displayed_item(((TWindowMenuIconLine *)LIST)->get_cursor_value());
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
                ((TWindowBase *)(F(uaddr, 0x3C)))->close();
                F(u32, 0x3C) = 0;
            }
            if (F(u32, 0x38) != 0) {
                ((TWindowBase *)(F(uaddr, 0x38)))->close();
                F(u32, 0x38) = 0;
            }
            if (F(u32, 0x40) != 0) {
                ((TWindowBase *)(F(uaddr, 0x40)))->close();
                F(u32, 0x40) = 0;
            }
            if (F(u32, 0x34) == 0) {
                F(u32, 0x34) = ((TWindowSubItem *)arg0)->open_purpose_window(((TWindowMenuIconLine *)LIST)->get_cursor_value());
            }
            ((TWindowMenu *)(F(uaddr, 0x34)))->clear_flag_and_release();
            ((TWindowMenu *)(F(uaddr, 0x34)))->clear_transition_flag();
            F(u8, 0x1C) = 4;
        case 4:
            if (((TWindowMenu *)(F(uaddr, 0x34)))->get_selected_value() == 0) {
                TWindowShortListCtrl::assign_item_to_palette(((TWindowMenuIconLine *)LIST)->get_cursor_value(), F(s32, 0x24));
            }
            if (((TWindowMenu *)(F(uaddr, 0x34)))->is_cancelled() != 0) {
                F(u8, 0x1C) = 1;
            }
            if (((TWindowMenu *)(F(uaddr, 0x34)))->is_decided() != 0) {
                set_cursor_row_for_mode((s32)(((TWindowMenu *)(F(uaddr, 0x34)))->get_selected_value()));
                return;
            }
            break;
        case 5:
            if (BACK_PRESSED(idx)) {
                play_sound_effect(0x52F16, 0, 0, 0);
                F(u8, 0x1C) = 3;
            }
            if (TWindowSubItem::is_usable(p) != 0) {
                exec_item_command(((TWindowMenuIconLine *)LIST)->get_cursor_value(), ((TWindowMenu *)(F(uaddr, 0x34)))->get_selected_value());
                return;
            }
            break;
        case 6:
            ((TWindowOptionCtrl *)(F(uaddr, 0x34)))->open();
            F(u32, 0x38) = create_menu_window();
            F(u8, 0x1C) = 7;
        case 7:
            if (((TWindowMenu *)(F(uaddr, 0x38)))->is_cancelled() != 0) {
                F(u8, 0x1C) = 3;
            }
            if (((TWindowMenu *)(F(uaddr, 0x38)))->is_decided() != 0) {
                close_windows(((TWindowMenu *)(F(uaddr, 0x38)))->get_selected_value());
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
            s32 n = find_item_by_id(((TWindowMenuIconLine *)LIST)->get_cursor_value())->get_amount();
            if (n <= 1) {
                F(s32, 0x28) = 1;
                F(u8, 0x1C) = 0xE;
                return;
            }
            ((TWindowOptionCtrl *)(F(uaddr, 0x34)))->open();
            if (F(u32, 0x3C) == 0) {
                F(u32, 0x3C) = create_count_input(n);
            }
            reinterpret_cast<TWindowSubItem *>(F(uaddr, 0x3C))->clear_flag_and_release();
            F(u8, 0x1C) = 0xD;
        }
        case 13:
            if (((TShopEquipmentSellWindow *)(F(uaddr, 0x3C)))->is_confirmed() != 0) {
                F(u8, 0x1C) = 3;
            }
            if (((TWindowInputNumber *)(F(uaddr, 0x3C)))->is_confirmed() != 0) {
                F(s32, 0x28) = ((TShopEquipmentSellWindow *)(F(uaddr, 0x3C)))->get_result();
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
                ((TObjPlayer *)p)->request_item_drop(((TWindowMenuIconLine *)LIST)->get_cursor_value(), F(s32, 0x28));
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
                ((TObjPlayer *)p)->send_trap_packet(((TWindowMenuIconLine *)LIST)->get_cursor_value() & 0xF);
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
            ((TWindowOptionCtrl *)(F(uaddr, 0x34)))->open();
            if (F(u32, 0x3C) == 0) {
                F(u32, 0x3C) = create_count_input(n);
            }
            reinterpret_cast<TWindowSubItem *>(F(uaddr, 0x3C))->clear_flag_and_release();
            F(u8, 0x1C) = 0x14;
        }
        case 20:
            if (((TShopEquipmentSellWindow *)(F(uaddr, 0x3C)))->is_confirmed() != 0) {
                F(u8, 0x1C) = 3;
            }
            if (((TWindowInputNumber *)(F(uaddr, 0x3C)))->is_confirmed() != 0) {
                F(s32, 0x28) = ((TShopEquipmentSellWindow *)(F(uaddr, 0x3C)))->get_result();
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
            if ((u32)((TObjPlayer *)p)->is_action_active() == 0) {
                F(u8, 0x1C) = 1;
            }
            break;
        case 23:
            break;
        }
    }
}

#undef F
#undef LIST
#undef BACK_PRESSED
void TWindowSubItem::render() {  }

s32 TWindowSubItem::open_purpose_window(s32 arg1) {
    saddr titled_window_menu;
    titled_window_menu = create_titled_window_menu(((int)get_window_layout_position(4)), 3, (saddr)TWindowSubStatusDisp::get_message_10(0x26), this->client_id);
    if (arg1 == -0xFF) {
        TWindowSubItem::add_meseta_purpose_actions((saddr)this, titled_window_menu);
    } else if ((s32) (arg1 & 0xFFFFFFF0) == -0x10) {
        TWindowSubItem::draw_slot((saddr)this, titled_window_menu, arg1);
    } else {
        add_item_purpose_actions((TWindowSubItem *)this, titled_window_menu, arg1);
    }
    TWindowSubEquip__sub_80263AF8(this->m_2c, 1);
    set_depth__11TWindowBaseFf(titled_window_menu);
    ((TWindowMenu *)titled_window_menu)->set_flag70_bit10();
    ((TWindowMenu *)titled_window_menu)->update_layout_height(224.0f);
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(titled_window_menu));
    return titled_window_menu;
}

s32 TWindowSubItem::create_menu_window() {
    saddr titled_window_menu;
    titled_window_menu = create_titled_window_menu(((int)get_window_layout_position(6)), 2, (saddr)TWindowSubStatusDisp::get_message_10(0x27), this->client_id);
    forward_trade_action_default__16TObjCityMainWarpFPviii(titled_window_menu, (saddr)TWindowSubStatusDisp::get_message_10(0x5D), 6, 0);
    forward_trade_action_default__16TObjCityMainWarpFPviii(titled_window_menu, (saddr)TWindowSubStatusDisp::get_message_10(0x5E), 6, 1);
    TWindowSubEquip__sub_80263AF8(this->m_2c, 2);
    set_depth__11TWindowBaseFf(titled_window_menu);
    ((TWindowMenu *)titled_window_menu)->set_flag70_bit10();
    ((TWindowMenu *)titled_window_menu)->update_layout_height(224.0f);
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(titled_window_menu));
    return titled_window_menu;
}

s32 TWindowSubItem::create_count_input(s32 maximum) {
    saddr storage;

    storage = __nw__7TObjectFUl(0x7C);
    if (storage != 0) {
        storage = __ct__18TWindowInputNumberFPvllls(storage, get_window_layout_position(5), 1, maximum, 1, (s16) this->client_id);
    }
    ((TWindowInputNumber *)storage)->create((saddr)TWindowSubStatusDisp::get_message_10(0x28));
    TWindowSubEquip__sub_80263AF8(this->m_2c, 3);
    set_depth__11TWindowBaseFf(storage);
    ((TWindowInputNumber *)storage)->set_value(224.0f);
    ((TWindowSubItem *)storage)->set_flag60_bit10();
    return storage;
}

void TWindowSubItem::add_meseta_purpose_actions(saddr arg0, saddr arg1) {
    if (get_current_floor_area() == AREA_LOBBY) {
        add_gray_text_entry((TWindowSubTradeMain *)arg1, (const char *)(TWindowSubStatusDisp::get_message_10(0x5F)), 6, 6);
        return;
    }
    forward_trade_action_default__16TObjCityMainWarpFPviii(arg1, (saddr)(TWindowSubStatusDisp::get_message_10(0x5F)), 6, 6);
}

void TWindowSubItem::draw_slot(saddr arg1, saddr arg2, s32 arg3) {
    s32 id;

    id = ((u32)__cntlzw(4 - (arg3 & 0xF)) >> 5) + 4;
    if ((is_current_area_item_enabled() == 0) || (is_boss_area() != 0)) {
        add_gray_text_entry((TWindowSubTradeMain *)arg2, (const char *)(get_localized_text_entry(0x10, 0xF)), 6, id);
        return;
    }
    forward_trade_action_default__16TObjCityMainWarpFPviii(arg2, (s32)(get_localized_text_entry(0x10, 0xF)), 0x26, id);
}

void add_item_purpose_actions(TWindowSubItem *window_sub_item, saddr list, saddr arg2) {
  s32 sp8;
  saddr item;
  saddr player;
  item = ((saddr)find_item_by_id((saddr)((void *) arg2)));
  if (item != 0)
  {
    if (((TItem *)item)->get_usable_action_flags(2, 0) != 0U)
    {
      if ((((TItem *)item)->get_usable_action_flags(1, 0) != 0U) || (get_current_floor_area() == AREA_LOBBY))
      {
        add_gray_text_entry((TWindowSubTradeMain *)list, (const char *)(TWindowSubStatusDisp::get_message_10(0x60)), 6, 0);
      }
      else
      {
        forward_trade_action_default__16TObjCityMainWarpFPviii((saddr)((void *) list), (saddr)TWindowSubStatusDisp::get_message_10(0x60), 6, 0);
      }
    }
    ((TItem *)item)->get_item_type();
    if (((TItem *)item)->get_usable_action_flags(8, 0) != 0U)
    {
      if (((TItem *)item)->test_item_flags(8) != 0U)
      {
        if (get_current_floor_area() == AREA_LOBBY)
        {
          add_gray_text_entry((TWindowSubTradeMain *)list, (const char *)(TWindowSubStatusDisp::get_message_10(0x61)), 6, 2);
        }
        else
        {
          forward_trade_action_default__16TObjCityMainWarpFPviii((saddr)((void *) list), (saddr)TWindowSubStatusDisp::get_message_10(0x61), 6, 2);
        }
      }
      else
      {
        player = get_player_by_client_id(window_sub_item->client_id);
        if (player != 0)
        {
          if (((((TItem *)item)->check_equip_requirements((TObjPlayer *)player, (s16 *)(&sp8)) != 0) && (has_armor_with_unit_slot(window_sub_item, (TItem *)item) != 0)) && (get_current_floor_area() != AREA_LOBBY))
          {
            forward_trade_action_default__16TObjCityMainWarpFPviii((saddr)((void *) list), (saddr)TWindowSubStatusDisp::get_message_10(0x62), 6, 1);
          }
          else
          {
            add_gray_text_entry((TWindowSubTradeMain *)list, (const char *)(TWindowSubStatusDisp::get_message_10(0x62)), 6, 1);
          }
        }
      }
    }
    if ((get_current_floor_area() == AREA_LOBBY) || (((TItem *)item)->get_usable_action_flags(0x10, 0) != 0U))
    {
      add_gray_text_entry((TWindowSubTradeMain *)list, (const char *)(TWindowSubStatusDisp::get_message_10(0x5F)), 6, 3);
    }
    else
    {
      forward_trade_action_default__16TObjCityMainWarpFPviii((saddr)((void *) list), (saddr)TWindowSubStatusDisp::get_message_10(0x5F), 6, 3);
    }
    if (get_current_floor_area() == AREA_LOBBY)
    {
      add_gray_text_entry((TWindowSubTradeMain *)list, (const char *)(TWindowSubStatusDisp::get_message_10(0x63)), 6, 7);
      return;
    }
    forward_trade_action_default__16TObjCityMainWarpFPviii((saddr)((void *) list), (saddr)TWindowSubStatusDisp::get_message_10(0x63), 6, 7);
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

void TWindowSubItem::exec_item_command(saddr item_id, s32 arg2) {
    saddr player;
    TItem *item;
    saddr t;

    player = get_player_by_client_id(this->client_id);
    if ((player != 0) && (item = find_item_by_id(item_id), ((item == NULL) == 0))) {
        switch (arg2) {
        case 3:
            break;
        case 0:
            try_send_6x27_use_item(player, item_id);
            this->m_1c = 0x16;
            break;
        case 1: {
            TItem *held = (TItem *)TObjPlayer::get_slot_value((void *)(player + 0xD04), item->get_attach_slot());
            if (held != NULL) {
                t = held->get_item_id();
                TObjPlayer::send_6x26_unequip_item((void *)player, t);
            }
            send_6x25_equip_item(player, item_id, 0);
            this->m_1c = 0x16;
            break;
        }
        case 2:
            TObjPlayer::send_6x26_unequip_item((void *)player, item_id);
            this->m_1c = 0x16;
            break;
        }
    }
}

void TWindowSubItem::close_windows(s32 arg1) {
    if (get_player_by_client_id(this->client_id) != 0U) {
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

#pragma push
#pragma scheduling off
void TWindowSubItem::use_selected_item() {
    s32 player;
    player = get_player_by_client_id(this->client_id);
    if (player != 0) {
        TObjPlayer__sub_801B7B58(player, (int) (((TWindowMenuIconLine *)this->m_30)->get_cursor_value()), ((TWindowSubItem *)(this->m_30))->get_selected_entry());
    }
}

#pragma pop
s32 has_armor_with_unit_slot(TWindowSubItem *window_sub_item, TItem *item) {
    ItemData_80279754 d;
    saddr pl;
    uaddr armor;
    pl = get_player_by_client_id(window_sub_item->client_id);
    if (pl == 0) {
        return 0;
    }
    if (item->get_item_type() != 1) {
        return 1;
    }
    if (item->get_item_group() != 3) {
        return 1;
    }
    armor = TObjPlayer::get_slot_value((void *)(pl + 0xD04), (int)2);
    if (armor == 0) {
        return 0;
    }
    ((TItem *)armor)->copy_to_item_data((TItemData *)&d);
    return d.b[5] != 0 ? 1 : 0;
}

extern "C" {
void TWindowSubItem::set_displayed_item(s32 arg1) {
    if (((u32) this->m_40 != 0U) && (arg1 != (s32) this->m_20)) {
        this->m_20 = arg1;
        TWindowHelpItem__set_displayed_item_by_id(this->m_40);
    }
}
}
