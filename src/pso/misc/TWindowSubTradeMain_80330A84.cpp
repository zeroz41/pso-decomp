#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowCtrl_8024A054.h"
#include "pso/misc/TWindowSubComCard_802A5748.h"
#include "pso/misc/TWindowSubEquip_80263AB0.h"
#include "pso/misc/TWindowSubTradeMain_802D2808.h"
#include "pso/misc/TWindowSubTradeMain_80330A84.h"
#include "pso/protocol/TradeSession.h"
#include "pso/unk/text_80076BC4.h"
#include "pso/unk/text_802D298C.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowHelpItem.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowSubComCardList.h"
#include "pso/ui/TAdChrSelASlotGC.h"
#include "pso/ui/TWindowInputNumber.h"
#include "pso/misc/TWindowLockOn.h"
#include "pso/misc/TWindowSubTradeMain.h"
#include "pso/misc/TWindowMenu.h"
#include "pso/misc/TWindowMessageYesNo.h"
#include "pso/misc/TWindowMenuIconLine.h"

typedef struct TradeMain_80330BCC {
    u8 pad0[0x1C];
    u8 state;
    u8 pad1D[0x30 - 0x1D];
    void *w30;
    void *w34;
    void *w38;
    void *w3C;
    void *w40;
    void *w44;
    void *w48;
    void *w4C;
} TradeMain_80330BCC;

struct PB_803310BC { u8 pad[0x18]; };

class Plr_803310BC : public PB_803310BC {
public:
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual s32 m10();
};

struct Self_803310BC { u8 pad[0x28]; s32 f28; s32 f2c; };

struct PB_80331178 { u8 pad[0x18]; };

class Plr_80331178 : public PB_80331178 {
public:
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual s32 m10();
};

struct Self_80331178 { u8 pad[0x28]; s32 f28; s32 f2c; };

extern "C" {
u8 * create__19TWindowMessageYesNoFPvPvPvPv(void *, void *, void *, void *);
s32 get_window_layout_position(s32);
extern f32 TWindowSubTradeMain__data_805DF858;
s32 TWindowSubTradeMain__sub_802448E4(void *, void *);
void TWindowSubTradeMain__sub_803323A8(void *);
void TWindowSubTradeMain__sub_803323B8(void *);
Plr_803310BC *get_player_by_client_id(s32);
s32 set_depth__11TWindowBaseFf(s32);
s32 create_equip_kind_window(s32, s32 *, s32);
extern s32 lbl_8047748C[];
s32 open_trade_equip_window__19TWindowSubTradeMainFv(Self_803310BC *arg0);
s8 get_trade_mode__6TLobbyFv();
extern s32 lbl_80477484[];
s32 create_trade_window__19TWindowSubTradeMainFv(Self_80331178 *arg0);
s32 get_message_10__20TWindowSubStatusDispFl(s32);
s32 free_member__17TWindowSubComCardFv(u8 *, int);
s32 create_help_item__19TWindowSubTradeMainFv(void *arg0);
s32 create_input_number__19TWindowSubTradeMainFl(void *arg0, s32 arg1);
s32 create_list__19TWindowSubTradeMainFv(void *arg0);
s32 TLobby__sub_802D268C();
s32 __ct__15TWindowHelpItemFPvUs(s32, s32, s32);
s32 TWindowHelpItem__set_displayed_item_by_id(u32);
s32 __ct__18TWindowInputNumberFPvllls(s32, s32, s32, s32, s32, s16);
s32 update_label_positions__17TWindowSubComCardFPvPv(u32, s32);
s32 __nw__7TObjectFUl(s32);

void TWindowSubTradeMain__sub_80330A84(void* p) { *(u8*)((char*)p + 0x1c) = 30; }
void TWindowSubTradeMain::forward_to_child(s32 arg1) {
    u32 temp = this->m_40;
    if (temp != 0U) {
        ((TWindowSubTradeMain *)temp)->set_trade_state((s16) arg1);
    }
}
void TWindowSubTradeMain::notify_child_if_present(s32 arg1) {
    u32 temp = this->m_3c;
    if (temp != 0U) {
        ((TWindowSubTradeMain *)temp)->set_trade_state((s16) arg1);
    }
}
void TWindowSubTradeMain::draw_item_slot() {
    if ((u32) this->m_40 != 0U) {
        ((TWindowSubTradeMain *)(this->m_40))->refresh_item_list((void*)(get_trade_window_state()));
    }
}
void TWindowSubTradeMain::update_trade_window() {
    if ((u32) this->m_3c != 0U) {
        ((TWindowSubTradeMain *)(this->m_3c))->refresh_item_list((void*)(TLobby__sub_802D299C()));
        ((TWindowSubTradeMain *)(this->m_3c))->set_trade_state(3);
    }
}

void TWindowSubTradeMain::update_position_if_changed(s32 arg0, u8 *arg1, u8 *arg2) {
    if ((*(f32 *)((s8 *)arg1 + 0x30) != *(f32 *)((s8 *)arg2 + 0)) || (*(f32 *)((s8 *)arg1 + 0x34) != *(f32 *)((s8 *)arg2 + 4))) {
        TWindowSubTradeMain__sub_802448E4(arg1, arg2);
    }
}

void TWindowSubTradeMain::set_child_windows_enabled(s32 on) {
    switch (((TradeMain_80330BCC *)this)->state) {
    case 2:
        if (((TradeMain_80330BCC *)this)->w30 != 0) {
            if (on != 0) {
                ((TWindowSubTradeMain *)(((TradeMain_80330BCC *)this)->w30))->clear_trade_flag();
            } else {
                ((TAdChrSelASlotGC *)(((TradeMain_80330BCC *)this)->w30))->set_flag_40();
            }
        }
        break;
    case 4:
        if (((TradeMain_80330BCC *)this)->w4C != 0) {
            if (on != 0) {
                ((TWindowHelpItem *)(((TradeMain_80330BCC *)this)->w4C))->sub_80255E24();
            } else {
                ((TWindowHelpItem *)(((TradeMain_80330BCC *)this)->w4C))->set_flag60_bit4();
            }
        }
        if (((TradeMain_80330BCC *)this)->w44 != 0) {
            if (on != 0) {
                ((TWindowSubTradeMain *)(((TradeMain_80330BCC *)this)->w44))->clear_flag();
            } else {
                ((TWindowSubTradeMain *)(((TradeMain_80330BCC *)this)->w44))->set_visible();
            }
        }
        break;
    case 7:
    case 14:
        if (((TradeMain_80330BCC *)this)->w48 != 0) {
            if (on != 0) {
                TWindowSubTradeMain__sub_803323B8(((TradeMain_80330BCC *)this)->w48);
            } else {
                TWindowSubTradeMain__sub_803323A8(((TradeMain_80330BCC *)this)->w48);
            }
        }
        break;
    case 11:
        if (((TradeMain_80330BCC *)this)->w4C != 0) {
            if (on != 0) {
                ((TWindowHelpItem *)(((TradeMain_80330BCC *)this)->w4C))->sub_80255E24();
            } else {
                ((TWindowHelpItem *)(((TradeMain_80330BCC *)this)->w4C))->set_flag60_bit4();
            }
        }
        if (((TradeMain_80330BCC *)this)->w40 != 0) {
            if (on != 0) {
                ((TWindowSubTradeMain *)(((TradeMain_80330BCC *)this)->w40))->clear_flag();
            } else {
                ((TWindowSubTradeMain *)(((TradeMain_80330BCC *)this)->w40))->set_visible();
            }
        }
        break;
    case 18:
        if (((TradeMain_80330BCC *)this)->w4C != 0) {
            if (on != 0) {
                ((TWindowHelpItem *)(((TradeMain_80330BCC *)this)->w4C))->sub_80255E24();
            } else {
                ((TWindowHelpItem *)(((TradeMain_80330BCC *)this)->w4C))->set_flag60_bit4();
            }
        }
        if (((TradeMain_80330BCC *)this)->w3C != 0) {
            if (on != 0) {
                ((TWindowSubTradeMain *)(((TradeMain_80330BCC *)this)->w3C))->clear_flag();
            } else {
                ((TWindowSubTradeMain *)(((TradeMain_80330BCC *)this)->w3C))->set_visible();
            }
        }
        break;
    case 21:
        if (((TradeMain_80330BCC *)this)->w34 != 0) {
            if (on != 0) {
                ((TWindowSubTradeMain *)(((TradeMain_80330BCC *)this)->w34))->clear_trade_flag();
            } else {
                ((TAdChrSelASlotGC *)(((TradeMain_80330BCC *)this)->w34))->set_flag_40();
            }
        }
        break;
    case 24:
    case 27:
        if (((TradeMain_80330BCC *)this)->w38 != 0) {
            if (on != 0) {
                ((TWindowSubComCard *)(((TradeMain_80330BCC *)this)->w38))->notify_trade_main();
            } else {
                ((TWindowSubComCard *)(((TradeMain_80330BCC *)this)->w38))->update_card_slot();
            }
        }
        break;
    case 34:
        break;
    }
}

void TWindowSubTradeMain::set_labels(s32 arg1) {
    if ((u32) this->m_30 != 0U) {
        TWindowSubTradeMain::update_position_if_changed((s32)this, (u8 *)this->m_30, (u8 *)((s32)(get_window_layout_position(arg1 + 0x5C))));
    }
    if ((u32) this->m_34 != 0U) {
        TWindowSubTradeMain::update_position_if_changed((s32)this, (u8 *)this->m_34, (u8 *)((s32)(get_window_layout_position(arg1 + 0x5E))));
    }
    if ((u32) this->m_38 != 0U) {
        update_label_positions__17TWindowSubComCardFPvPv(this->m_38, get_window_layout_position(arg1 + 0x5F));
    }
    if ((u32) this->m_3c != 0U) {
        if ((u32) this->m_44 != 0U) {
            TWindowSubTradeMain::update_position_if_changed((s32)this, (u8 *)this->m_3c, (u8 *)((s32)(get_window_layout_position(arg1 + 0x62))));
        } else {
            TWindowSubTradeMain::update_position_if_changed((s32)this, (u8 *)this->m_3c, (u8 *)((s32)(get_window_layout_position(arg1 + 0x60))));
        }
    }
    if ((u32) this->m_40 != 0U) {
        if ((u32) this->m_44 != 0U) {
            TWindowSubTradeMain::update_position_if_changed((s32)this, (u8 *)this->m_40, (u8 *)((s32)(get_window_layout_position(arg1 + 0x63))));
        } else {
            TWindowSubTradeMain::update_position_if_changed((s32)this, (u8 *)this->m_40, (u8 *)((s32)(get_window_layout_position(arg1 + 0x61))));
        }
    }
    if ((u32) this->m_44 != 0U) {
        TWindowSubTradeMain::update_position_if_changed((s32)this, (u8 *)this->m_44, (u8 *)((s32)(get_window_layout_position(arg1 + 0x64))));
    }
    if ((u32) this->m_48 != 0U) {
        TWindowSubTradeMain::update_position_if_changed((s32)this, (u8 *)this->m_48, (u8 *)((s32)(get_window_layout_position(arg1 + 0x5D))));
    }
    if ((u32) this->m_4c != 0U) {
        TWindowSubTradeMain::update_position_if_changed((s32)this, (u8 *)this->m_4c, (u8 *)((s32)(get_window_layout_position(arg1 + 0x65))));
    }
}

void TWindowSubTradeMain::set_displayed_item(s32 arg1) {
    if (((u32) this->m_4c != 0U) && (arg1 != (s32) this->m_24)) {
        this->m_24 = arg1;
        TWindowHelpItem__set_displayed_item_by_id(this->m_4c);
    }
}

s32 TWindowSubTradeMain::create_help_item() {
    s32 var_r31;

    var_r31 = __nw__7TObjectFUl(0xBC);
    if (var_r31 != 0) {
        var_r31 = __ct__15TWindowHelpItemFPvUs(var_r31, get_window_layout_position(2), this->m_28);
    }
    this->m_24 = -1;
    return var_r31;
}

s32 TWindowSubTradeMain::create_input_number(s32 maximum) {
    s32 storage;

    storage = __nw__7TObjectFUl(0x7C);
    if (storage != 0) {
        storage = __ct__18TWindowInputNumberFPvllls(storage, get_window_layout_position(0x5D), 1, maximum, 1, (s16) this->m_28);
    }
    ((TWindowInputNumber *)storage)->create(get_message_10__20TWindowSubStatusDispFl(0x28));
    ((TWindowInputNumber *)storage)->set_value(TWindowSubTradeMain__data_805DF858);
    return storage;
}

extern s32 lbl_80477494[];

s32 TWindowSubTradeMain::create_list() {
    s32 equip_kind_window;

    equip_kind_window = create_equip_kind_window(get_window_layout_position(0x64), lbl_80477494, this->m_28);
    ((TWindowMenuIconLine *)equip_kind_window)->ensure_status_display(get_message_10__20TWindowSubStatusDispFl(0x24));
    ((TWindowSubTradeMain *)equip_kind_window)->refresh_item_list((void*)(TLobby__sub_802D298C()));
    TWindowSubEquip__sub_80263AF8((u8 *)this->m_2c, 2);
    set_depth__11TWindowBaseFf(equip_kind_window);
    return equip_kind_window;
}

s32 TWindowSubTradeMain::open_trade_equip_window() {
    Plr_803310BC *p;
    s32 w;
    p = get_player_by_client_id(((Self_803310BC *)this)->f28);
    if (p == NULL) {
        return 0;
    }
    w = create_equip_kind_window(get_window_layout_position(0x61), lbl_8047748C, ((Self_803310BC *)this)->f28);
    ((TWindowMenuIconLine *)w)->ensure_status_display(p->m10());
    ((TWindowSubTradeMain *)w)->set_trade_state(0);
    ((TWindowSubTradeMain *)w)->refresh_item_list((void*)(get_trade_window_state()));
    ((TWindowSubTradeMain *)w)->close();
    TWindowSubEquip__sub_80263AF8((u8 *)(((Self_803310BC *)this)->f2c), 1);
    set_depth__11TWindowBaseFf(w);
    return w;
}

s32 TWindowSubTradeMain::create_trade_window() {
    Plr_80331178 *p;
    s32 w;
    p = ((Plr_80331178 *)get_player_by_client_id(get_trade_mode__6TLobbyFv()));
    if (p == NULL) {
        return 0;
    }
    w = create_equip_kind_window(get_window_layout_position(0x60), lbl_80477484, ((Self_80331178 *)this)->f28);
    ((TWindowMenuIconLine *)w)->ensure_status_display(p->m10());
    ((TWindowSubTradeMain *)w)->set_trade_state(0);
    ((TWindowSubTradeMain *)w)->refresh_item_list((void*)(TLobby__sub_802D299C()));
    ((TWindowSubTradeMain *)w)->close();
    TWindowSubEquip__sub_80263AF8((u8 *)(((Self_80331178 *)this)->f2c), 0);
    set_depth__11TWindowBaseFf(w);
    return w;
}

u8 *TWindowSubTradeMain::open_confirm_prompt() {
    u8 *w;
    w = create__19TWindowMessageYesNoFPvPvPvPv(this, *(void **)(((u8 *)this) + 0x28), NULL, NULL);
    open_yes_no_prompt((TChCrTagPlBack *)w, (u32)(get_message_10__20TWindowSubStatusDispFl(0x20)), (s32)(get_message_10__20TWindowSubStatusDispFl(0xE4)), (s32)(get_window_layout_position(0x5F)), (f32)TWindowSubTradeMain__data_805DF858);
    free_member__17TWindowSubComCardFv(w, 1);
    return w;
}

u8 *open_option_dialog__19TWindowSubTradeMainFPvi(u8 *window_message_yes_no, s32 arg1) {
    u8 *temp_r31;
    temp_r31 = (u8 *)(create__19TWindowMessageYesNoFPvPvPvPv(window_message_yes_no, *(u8 **)((s8 *)window_message_yes_no + 0x28), NULL, NULL));
    initialize_option_dialog(temp_r31, arg1, get_window_layout_position(0x5F), TWindowSubTradeMain__data_805DF858);
    return temp_r31;
}

u8 * open_option_dialog_thunk__19TWindowSubTradeMainFPvPv(void* p, void* _w1) { return open_option_dialog__19TWindowSubTradeMainFPvi((u8 *)p, (s32)_w1); }

}

#include "pso/misc/TShopEquipmentSellWindow.h"
#include "pso/misc/TWindowChat.h"
#include "pso/misc/TWindowOptionCtrl.h"
#include "pso/misc/TWindowSubItem.h"

struct RecoveredFields_80331434_arg0
{
  u8 unknown_0[0x28];
  s32 field_28;
};

struct RecoveredFields_80331520_arg0
{
  u8 unknown_0[0x28];
  s32 field_28;
};

struct VBase_18_204a81 { char pad[0x18]; };

struct VObj_18_204a81 : VBase_18_204a81 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
};

struct Ctrl_8033162C {
    u8 pad0[0x20];
    u8 btn[0x30];
};

struct TWindowSubTradeMain_8033162C {
    u8 pad0[0x1C];
    u8 state;
    u8 flags;
    u8 pad1E[2];
    s32 timer;
    u8 pad24[4];
    s32 player;
    VObj_18_204a81 *obj2C;
    void *menu;
    void *confirm;
    void *card;
    void *offer;
    void *request;
    void *list;
    void *number;
    void *help;
    void *chat;
    u8 submission[4];
};

extern "C" {
s32 align_menu_entry_positions(int);
int forward_trade_action_default__16TObjCityMainWarpFPviii(void *p, int a1, int a2, int a3);
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, int);
s32 TWindowShortListCtrl__check_controller_button(void *, int);
void play_sound_effect(int, int, int, int);
}
s32 create_titled_window_menu(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void window_request_show(void *);
extern "C" {
s32 TWindowCtrl__sub_8024701C(void *);
void TWindowChat__sub_80247DFC(u8 *arg0);
void TWindowChat__sub_80247E50(u8 *arg0);
void TWindowSubComCard__sub_80265680(u8 *arg0, s16 arg1);
void *get_cursor_value__19TWindowMenuIconLineFv(void *);
s32 get_state__19TWindowSubTradeMainFv(void *, void *);
void TWindowSubTradeMain__sub_803323C8(void *);
extern Ctrl_8033162C controller_input_state[];

void open_status_window__19TWindowSubTradeMainFi(s32 arg0) {
    ((int (*)(void*, void* a1 = 0))open_option_dialog__19TWindowSubTradeMainFPvi)((void*)arg0, (void*)(get_message_10__20TWindowSubStatusDispFl(0xF7)));
}
void update_from_lobby__19TWindowSubTradeMainFi(s32 arg0) {
    ((int (*)(void*, void* a1 = 0))open_option_dialog__19TWindowSubTradeMainFPvi)((void*)arg0, (void*)(TLobby__sub_802D268C()));
}

typedef struct RecoveredFields_80331434_arg0 RecoveredFields_80331434_arg0;
#pragma fp_contract on

s32 TWindowSubTradeMain::open_confirm_yes_no() {
    u8 *arg0 = (u8 *)this;
    s32 w = ((s32 (*)(void *, s32, s32, s32))create__19TWindowMessageYesNoFPvPvPvPv)(arg0, this->m_28, 0, 0);
    open_yes_no_prompt((TChCrTagPlBack *)((u8 *)w), (u32)(get_message_10__20TWindowSubStatusDispFl(0x20)), (s32)(get_message_10__20TWindowSubStatusDispFl(0xE6)), (s32)(((s32 (*)(int))get_window_layout_position)(0x5F)), (f32)TWindowSubTradeMain__data_805DF858);
    ((s32 (*)(s32, int))free_member__17TWindowSubComCardFv)(w, 1);
    return w;
}

s32 TWindowSubTradeMain::create_trade_menu() {
    u8 *arg0 = (u8 *)this;
  s32 titled_window_menu;
  titled_window_menu = create_titled_window_menu((int) ((s32 (*)(int))get_window_layout_position)(0x5E), 4, (0, get_message_10__20TWindowSubStatusDispFl(0xDD)), (int) ((RecoveredFields_80331434_arg0 *) arg0)->field_28);
  forward_trade_action_default__16TObjCityMainWarpFPviii((void *)titled_window_menu, (int)((int) get_message_10__20TWindowSubStatusDispFl(0xDC)), 6, 0x11);
  forward_trade_action_default__16TObjCityMainWarpFPviii((void *)titled_window_menu, (int)((int) get_message_10__20TWindowSubStatusDispFl(0xE3)), 6, 0x16);
  ((TWindowSubTradeMain *)titled_window_menu)->add_text_entry((int) get_message_10__20TWindowSubStatusDispFl(0xDE), 6, 0x1A, (int) 0xFFEE946E);
  ((TWindowSubTradeMain *)titled_window_menu)->add_text_entry((int) get_message_10__20TWindowSubStatusDispFl(0xDF), 6, 0x17, (int) 0xFFEE6ED8);
  ((TWindowSubComCardList *)titled_window_menu)->update_layout_height((f32) TWindowSubTradeMain__data_805DF858);
  align_menu_entry_positions((int) titled_window_menu);
  return titled_window_menu;
}

typedef struct RecoveredFields_80331520_arg0 RecoveredFields_80331520_arg0;
#pragma fp_contract on
s32 TWindowSubTradeMain::build_trade_menu() {
    u8 *arg0 = (u8 *)this;
  s32 titled_window_menu;
  titled_window_menu = create_titled_window_menu((int) ((s32 (*)(int))get_window_layout_position)(0x5C), 5, (0, get_message_10__20TWindowSubStatusDispFl(0x26)), (int) ((RecoveredFields_80331520_arg0 *) arg0)->field_28);
  forward_trade_action_default__16TObjCityMainWarpFPviii((void *)titled_window_menu, (int)((int) get_message_10__20TWindowSubStatusDispFl(0xDA)), 6, 3);
  forward_trade_action_default__16TObjCityMainWarpFPviii((void *)titled_window_menu, (int)((int) get_message_10__20TWindowSubStatusDispFl(0xDB)), 6, 0xA);
  forward_trade_action_default__16TObjCityMainWarpFPviii((void *)titled_window_menu, (int)((int) get_message_10__20TWindowSubStatusDispFl(0xDC)), 6, 0x11);
  ((TWindowSubTradeMain *)titled_window_menu)->add_text_entry((int) get_message_10__20TWindowSubStatusDispFl(0xDD), 6, 0x14, (int) 0xFFEE946E);
  ((TWindowSubTradeMain *)titled_window_menu)->add_text_entry((int) get_message_10__20TWindowSubStatusDispFl(0xDF), 6, 0x17, (int) 0xFFEE6ED8);
  ((TWindowSubComCardList *)titled_window_menu)->update_layout_height((f32) TWindowSubTradeMain__data_805DF858);
  align_menu_entry_positions((int) titled_window_menu);
  return titled_window_menu;
}

void TWindowSubTradeMain::render() {  }
void TWindowSubTradeMain::run_task() {
    TWindowSubTradeMain_8033162C *o = (TWindowSubTradeMain_8033162C *)this;
    s32 player;
    void *entry;
    s32 n;
    player = is_player_input_active(o->player);
    if (((TWindowChat *)(o->chat))->is_mode_bit4() != 0 && chat_accept_submission((s32)o->submission) != 0) {
        TWindowChat__sub_80247E50((u8 *)o->chat);
    }
    if (((TWindowChat *)(o->chat))->is_visible() != 0) {
        TWindowChat__sub_80247DFC((u8 *)o->chat);
    }
    if (TWindowCtrl__sub_8024701C(o->chat) != 0) {
        ((TWindowSubTradeMain *)o)->set_labels(0xA);
        ((TWindowSubTradeMain *)o)->set_child_windows_enabled(0);
        o->flags |= 1;
    } else {
        ((TWindowSubTradeMain *)o)->set_labels(0);
        ((TWindowSubTradeMain *)o)->set_child_windows_enabled(1);
        o->flags &= ~1;
    }
    switch (o->state) {
    case 0:
    case 1:
        if (o->offer == 0) {
            o->offer = ((void * (*)(void *))create_trade_window__19TWindowSubTradeMainFv)(o);
        }
        if (o->request == 0) {
            o->request = ((void * (*)(void *))open_trade_equip_window__19TWindowSubTradeMainFv)(o);
        }
        if (o->menu == 0) {
            o->menu = (void *)build_trade_menu();
        }
        window_request_show(o->menu);
        ((TWindowSubComCard *)(o->menu))->clear_flag_and_release();
        ((TWindowOptionCtrl *)(o->menu))->clear_flag70_bit4();
        o->state = 2;
    case 2:
        if (((TWindowMenu *)(o->menu))->is_cancelled() != 0) {
            o->state = 0x17;
        } else if (((TWindowMenu *)(o->menu))->is_decided() != 0) {
            o->state = ((TWindowMenu *)o->menu)->get_selected_value();
        }
        break;
    case 3:
        if (o->menu != 0) {
            ((TWindowLockOn *)(o->menu))->request_close();
        }
        if (o->offer != 0) {
            ((void (*)(void *, s32))TWindowSubTradeMain__sub_802448E4)(o->offer, ((s32 (*)(int))get_window_layout_position)(0x62));
        }
        if (o->request != 0) {
            ((void (*)(void *, s32))TWindowSubTradeMain__sub_802448E4)(o->request, ((s32 (*)(int))get_window_layout_position)(0x63));
        }
        if (o->list == 0) {
            o->list = ((void * (*)(void *))create_list__19TWindowSubTradeMainFv)(o);
        }
        if (o->help == 0) {
            o->help = ((void * (*)(void *))create_help_item__19TWindowSubTradeMainFv)(o);
        }
        ((TWindowMenuIconLine *)(o->list))->clear_decided();
        o->state = 4;
    case 4:
        ((TWindowSubTradeMain *)o)->set_displayed_item((s32)(get_cursor_value__19TWindowMenuIconLineFv(o->list)));
        if (((TWindowMenuIconLine *)(o->list))->is_cancelled() != 0) {
            o->state = 5;
        } else if (((TWindowMenuIconLine *)(o->list))->is_decided() != 0) {
            o->state = 6;
        }
        break;
    case 5:
        if (o->help != 0) {
            ((TWindowBase *)o->help)->close();
            o->help = 0;
        }
        if (o->list != 0) {
            ((TWindowBase *)o->list)->close();
            o->list = 0;
        }
        if (o->offer != 0) {
            ((void (*)(void *, s32))TWindowSubTradeMain__sub_802448E4)(o->offer, ((s32 (*)(int))get_window_layout_position)(0x60));
        }
        if (o->request != 0) {
            ((void (*)(void *, s32))TWindowSubTradeMain__sub_802448E4)(o->request, ((s32 (*)(int))get_window_layout_position)(0x61));
        }
        o->state = 1;
        break;
    case 6:
        if (o->help != 0) {
            ((TWindowBase *)o->help)->close();
            o->help = 0;
        }
        entry = get_cursor_value__19TWindowMenuIconLineFv(o->list);
        n = get_state__19TWindowSubTradeMainFv(TLobby__sub_802D298C(), entry);
        if (n <= 1) {
            TWindowSubTradeMain::draw_request((void *)entry, (void *)1);
            o->state = 9;
            break;
        }
        if (o->number == 0) {
            o->number = ((void * (*)(void *, s32))create_input_number__19TWindowSubTradeMainFl)(o, n);
        }
        o->state = 7;
    case 7:
        if (((TShopEquipmentSellWindow *)(o->number))->is_confirmed() != 0) {
            o->state = 8;
        }
        if (((TWindowInputNumber *)(o->number))->is_confirmed() != 0) {
            n = ((TShopEquipmentSellWindow *)(o->number))->get_result();
            TWindowSubTradeMain::draw_request((void *)(get_cursor_value__19TWindowMenuIconLineFv(o->list)), (void *)n);
            o->state = 9;
        }
        break;
    case 8:
        if (o->number != 0) {
            ((TWindowBase *)o->number)->close();
            o->number = 0;
        }
        o->state = 3;
        break;
    case 9:
        if (o->number != 0) {
            ((TWindowBase *)o->number)->close();
            o->number = 0;
        }
        o->state = 5;
        break;
    case 10:
        if (o->menu != 0) {
            ((TWindowLockOn *)(o->menu))->request_close();
        }
        if (o->request != 0) {
            ((TWindowSubTradeMain *)(o->request))->update_trade_state();
        }
        if (o->help == 0) {
            o->help = ((void * (*)(void *))create_help_item__19TWindowSubTradeMainFv)(o);
        }
        ((TWindowMenuIconLine *)(o->request))->clear_decided();
        o->state = 0xB;
    case 11:
        ((TWindowSubTradeMain *)o)->set_displayed_item((s32)(get_cursor_value__19TWindowMenuIconLineFv(o->request)));
        if (((TWindowMenuIconLine *)(o->request))->is_cancelled() != 0) {
            o->state = 0xC;
        } else if (((TWindowMenuIconLine *)(o->request))->is_decided() != 0) {
            o->state = 0xD;
        }
        break;
    case 12:
        if (o->help != 0) {
            ((TWindowBase *)o->help)->close();
            o->help = 0;
        }
        if (o->request != 0) {
            ((TWindowMenuIconLine *)(o->request))->clear_decided();
            TWindowSubTradeMain__sub_803323C8(o->request);
            ((TWindowSubTradeMain *)(o->request))->close();
        }
        o->state = 1;
        break;
    case 13:
        if (o->help != 0) {
            ((TWindowBase *)o->help)->close();
            o->help = 0;
        }
        entry = get_cursor_value__19TWindowMenuIconLineFv(o->request);
        n = get_state__19TWindowSubTradeMainFv(get_trade_window_state(), entry);
        if (n <= 1) {
            TWindowSubTradeMain::draw_offer((void *)entry, (void *)1);
            o->state = 0x10;
            break;
        }
        if (o->number == 0) {
            o->number = ((void * (*)(void *, s32))create_input_number__19TWindowSubTradeMainFl)(o, n);
        }
        o->state = 0xE;
    case 14:
        if (((TShopEquipmentSellWindow *)(o->number))->is_confirmed() != 0) {
            o->state = 0xF;
        }
        if (((TWindowInputNumber *)(o->number))->is_confirmed() != 0) {
            n = ((TShopEquipmentSellWindow *)(o->number))->get_result();
            TWindowSubTradeMain::draw_offer((void *)(get_cursor_value__19TWindowMenuIconLineFv(o->request)), (void *)n);
            o->state = 0x10;
        }
        break;
    case 15:
        if (o->number != 0) {
            ((TWindowBase *)o->number)->close();
            o->number = 0;
        }
        o->state = 0xA;
        break;
    case 16:
        if (o->number != 0) {
            ((TWindowBase *)o->number)->close();
            o->number = 0;
        }
        o->state = 0xC;
        break;
    case 17:
        if (o->menu != 0) {
            ((TWindowLockOn *)(o->menu))->request_close();
        }
        if (o->offer != 0) {
            ((TWindowSubTradeMain *)(o->offer))->update_trade_state();
        }
        if (o->help == 0) {
            o->help = ((void * (*)(void *))create_help_item__19TWindowSubTradeMainFv)(o);
        }
        o->state = 0x12;
    case 18:
        ((TWindowSubTradeMain *)o)->set_displayed_item((s32)(get_cursor_value__19TWindowMenuIconLineFv(o->offer)));
        if (((TWindowMenuIconLine *)(o->offer))->is_cancelled() != 0) {
            o->state = 0x13;
        } else if (((TWindowMenuIconLine *)(o->offer))->is_decided() != 0) {
            o->state = 0x13;
        }
        break;
    case 19:
        if (o->help != 0) {
            ((TWindowBase *)o->help)->close();
            o->help = 0;
        }
        if (o->offer != 0) {
            ((TWindowMenuIconLine *)(o->offer))->clear_decided();
            TWindowSubTradeMain__sub_803323C8(o->offer);
            ((TWindowSubTradeMain *)(o->offer))->close();
        }
        if (is_local_trade_offer_confirmation_requested() != 0) {
            o->state = 0x14;
        } else {
            o->state = 1;
        }
        break;
    case 20:
        if (o->menu != 0) {
            ((TWindowOptionCtrl *)(o->menu))->open();
        }
        window_request_show(o->menu);
        if (o->confirm == 0) {
            o->confirm = (void *)create_trade_menu();
        }
        window_request_show(o->confirm);
        ((TWindowSubComCard *)(o->confirm))->clear_flag_and_release();
        set_local_trade_offer_confirmation();
        o->state = 0x15;
    case 21:
        if (are_both_trade_offers_confirmed() != 0) {
            ((TWindowSubComCard *)(o->confirm))->set_entry_value_clear_flag(2, 0xFFEE946E);
        } else {
            TWindowSubComCard__sub_80265680((u8 *)o->confirm, 2);
        }
        if (((TWindowMenu *)(o->confirm))->is_cancelled() != 0) {
            o->state = 0x16;
        } else if (((TWindowMenu *)(o->confirm))->is_decided() != 0) {
            o->state = ((TWindowMenu *)o->confirm)->get_selected_value();
            if (o->confirm != 0) {
                ((TWindowLockOn *)(o->confirm))->request_close();
            }
            if (o->menu != 0) {
                ((TWindowSubComCard *)(o->menu))->clear_transition_flag();
            }
        }
        break;
    case 22:
        if (o->confirm != 0) {
            ((TWindowBase *)o->confirm)->close();
            o->confirm = 0;
        }
        if (o->menu != 0) {
            ((TWindowSubComCard *)(o->menu))->clear_transition_flag();
        }
        clear_local_trade_offer_confirmation();
        o->state = 1;
        break;
    case 23:
        if (o->menu != 0) {
            ((TWindowLockOn *)(o->menu))->request_close();
        }
        if (o->card == 0) {
            o->card = ((TWindowSubTradeMain *)o)->open_confirm_prompt();
        }
        o->state = 0x18;
    case 24:
        if (((TWindowSubComCard *)(o->card))->get_card_data() != 0) {
            o->state = 0x19;
        } else if (((TWindowMessageYesNo *)(o->card))->is_child_visible() != 0) {
            if (((TWindowSubComCard *)(o->card))->get_slot_or_neg1() == 0) {
                o->obj2C->m7();
                o->state = 0x22;
            } else {
                o->state = 0x19;
            }
        }
        break;
    case 25:
        if (o->card != 0) {
            ((TWindowSubComCard *)(o->card))->close();
            o->card = 0;
        }
        if (is_local_trade_offer_confirmation_requested() != 0) {
            o->state = 0x14;
        } else {
            o->state = 1;
        }
        break;
    case 26:
        if (o->menu != 0) {
            ((TWindowLockOn *)(o->menu))->request_close();
        }
        if ((n = TLobby::check_trade_items_and_show_error()) != 0) {
            if (o->card == 0) {
                o->card = (void *)((int (*)(void *, s32))open_option_dialog_thunk__19TWindowSubTradeMainFPvPv)(o, n);
            }
            o->state = 0x1C;
        } else {
            if (o->card == 0) {
                o->card = ((void *)open_confirm_yes_no());
            }
            o->state = 0x1B;
        }
    case 27:
        if (are_both_trade_offers_confirmed() == 0) {
            o->state = 0x1D;
        }
        if (((TWindowSubComCard *)(o->card))->get_card_data() != 0) {
            o->state = 0x1D;
        } else if (((TWindowMessageYesNo *)(o->card))->is_child_visible() != 0) {
            if (((TWindowSubComCard *)(o->card))->get_slot_or_neg1() == 0) {
                ((TWindowSubComCard *)(o->card))->close();
                o->card = ((void *(*)(void *))update_from_lobby__19TWindowSubTradeMainFi)(o);
                set_local_trade_final_confirmation();
                o->state = 0x1C;
            } else {
                o->state = 0x1D;
            }
        }
        break;
    case 28:
        if (are_both_trade_offers_confirmed() == 0 ||
            (!(o->flags & 1) &&
             (TWindowShortListCtrl__check_controller_button(controller_input_state[player].btn, 2) != 0 ||
              test_flag_4c__23TAdSinglePlyChrSelectGCFv(controller_input_state[4].btn, 2) != 0))) {
            play_sound_effect(0x52F16, 0, 0, 0);
            clear_local_trade_final_confirmation();
            o->state = 0x1D;
        }
        break;
    case 29:
        if (o->card != 0) {
            ((TWindowSubComCard *)(o->card))->close();
            o->card = 0;
        }
        o->state = 0x14;
        break;
    case 30:
        if (o->card != 0) {
            ((TWindowSubComCard *)(o->card))->close();
            o->card = 0;
        }
        o->card = ((void *(*)(void *))open_status_window__19TWindowSubTradeMainFi)(o);
        o->timer = 900;
        o->state = 0x1F;
    case 31:
        if (o->timer > 0) {
            o->timer--;
        } else if (!(o->flags & 1) &&
                   (TWindowShortListCtrl__check_controller_button(controller_input_state[player].btn, 2) != 0 ||
                    test_flag_4c__23TAdSinglePlyChrSelectGCFv(controller_input_state[4].btn, 2) != 0)) {
            play_sound_effect(0x52F16, 0, 0, 0);
            TLobby::clear_flag400();
            o->timer = 900;
            o->state = 0x20;
        }
        break;
    case 32:
        if (o->timer > 0) {
            o->timer--;
        } else {
            reset__6TLobbyFv();
            o->state = 0x22;
        }
        break;
    case 33:
    case 34:
        break;
    }
}
}
