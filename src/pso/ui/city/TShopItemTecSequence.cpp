#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/city/TShopEquipmentSellWindow.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/city/TShopItemListWindow.h"
#include "pso/player/TObjPlayer_801A5AEC.h"
#include "pso/unk/text_8026934C.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/city/TShopSequence.h"
#include "pso/ui/city/TShopItemTecSequence.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/ui/city/TCheckRoomSequence.h"
#include "pso/quest/TQuestListVM.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TObject.h"

#pragma readonly_strings on

struct Base_8021FEE0_8021FE6C { char pad[0x18]; };
struct VObj_8021FEE0_8021FE6C : Base_8021FEE0_8021FE6C {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(int, int);
};
struct Base_8021FF30_8021FE6C { char pad[0x18]; };
struct VObj_8021FF30_8021FE6C : Base_8021FF30_8021FE6C {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(s32, s32);
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32  m8();
};
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

struct Stack_802202BC
{
  f32 sp8;
  f32 spC;
};

struct W_80220030 { u8 pad[0x3a4]; void *cb0; void *cb1; };

struct S_80220030 { u8 pad[0x24]; s32 f24; };

struct W_802200A8 { u8 pad[0x1c0]; void *cb0; };

struct S_802200A8 { u8 pad[0x24]; s32 f24; };

struct VBase_18_80220110 { char pad[0x18]; };

struct Seq_80220110 : VBase_18_80220110 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual s32 m4(s32, s32);
    u8 pad1C[0x24 - 0x1C];
    void *x24;
    u8 pad28[0x30 - 0x28];
    void *win;
};

extern "C" {
s32 sub_8022397C__15TShopWindowBaseFv(void *);
s32 set_service_counter_camera(void *, int);
s32 get_window_layout_position(int, f32);
// Per-player slot flags, set by the ctor and cleared by the dtor (as THunterGuildSeqOffline__instance_table).
s32 TShopItemTecSequence__slot_table[4];
s32 lbl_805D6248;
s32 lbl_805D624C;
TShopItemTecSequence *item_tec_sequence_instance;
const char *TShopItemTecSequence__class_name = "TShopItemTecSequence";
extern void *tl_05;
s32 get_entity_id(void *);
s32 get_shop_text(s32 arg0);
int align_menu_entry_positions(void *);
int forward_trade_action_default__16TObjCityMainWarpFPviii(void* p, int a1, int a2, int a3);
saddr create_window_menu(s32 arg0, s32 arg1, s32 arg2);
struct Base_8021FE80_8021FE6C { char pad[0x18]; };
struct VObj_8021FE80_8021FE6C : Base_8021FE80_8021FE6C {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(int, int);
};

s32 sub_802239EC__13TShopSequenceFv(void *);

    extern int shop_tool_stock_counts[];
typedef struct Stack_802202BC Stack_802202BC;
typedef struct VBase_18_a93f07 VBase_18_a93f07;
typedef struct VObj_18_a93f07 VObj_18_a93f07;

// Written last-to-first: the unit is built with deferred code generation (see configure.py).

void set_judgment_target_flag(void *arg0, void *arg1) {
    uaddr temp_r3;
    if ((TRaderMapCore::is_not_split_screen() == 1) && ((temp_r3 = (uaddr)find_item_by_id(*(s32 *)((s8 *)arg1 + 0xC))) != 0U) && ((s32) *(s32 *)((s8 *)arg0 + 0x168) != 0)) {
        ((TItem *)temp_r3)->add_item_flags(0x80);
    }
}

void TShopItemTecSequence__sub_80220560(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        TShopItemTecSequence__slot_table[i] = 0;
    }
}

void TShopItemTecSequence__sub_80220538(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        TShopItemTecSequence__slot_table[i] = 0;
    }
}

TShopItemTecSequence::TShopItemTecSequence(TObject *parent, TObjPlayer *player) : TShopSequence(parent) {
    m_name = TShopItemTecSequence__class_name;
    state = 0;
    this->player = player;
    choice_menu = NULL;
    meseta_window = NULL;
    counter_camera = NULL;
    item_tec_sequence_instance = this;
    lbl_805D6248 = 0;
    lbl_805D624C = 0;
    TShopItemTecSequence__slot_table[sub_8022397C__15TShopWindowBaseFv(this)] = 1;
}

TShopItemTecSequence::~TShopItemTecSequence() {
    if (counter_camera != NULL) {
        counter_camera->queue_destruction();
        counter_camera = NULL;
    }
    if (meseta_window != NULL) {
        meseta_window->close();
        meseta_window = NULL;
    }
    close_message_window();
    if (choice_menu != NULL) {
        choice_menu->close();
        choice_menu = NULL;
    }
    item_tec_sequence_instance = NULL;
    TShopItemTecSequence__slot_table[sub_8022397C__15TShopWindowBaseFv(this)] = 0;
}

void TShopItemTecSequence::vfunc_11() {
    switch (state) {
    case 0:
        TShopSequence::restore_player_state();
        set_field_20(1);
        return;
    case 1:
        open_greeting();
        return;
    case 2:
        update_buy_sell_choice();
        return;
    case 3:
        open_item_list_window();
        return;
    case 4:
        open_sell_window();
        return;
    case 7:
        close_if_done();
        return;
    case 6:
        handle_select();
    default:
        return;
    }
}

s32 TShopItemTecSequence::open_greeting() {
  Stack_802202BC stack;
  stack.sp8 = 332.0f;
  stack.spC = 80.0f;
  this->create_message_window(get_window_layout_position(0x2C, 332.0f), (saddr)&stack.sp8);
  (((VObj_18_a93f07 *)(this))->m4(0x2E, 1));
  meseta_window = (TWindowBase *)create_meseta_window((s32) ((((this->get_child_field1c() & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF));
  this->set_field_20(2);
  counter_camera = (TObject *)set_service_counter_camera((void *) this, 5);
}

void TShopItemTecSequence::update_buy_sell_choice() {
    s32 r;
    if (((Seq_80220110 *)this)->win == NULL) {
        u16 id = get_entity_id(((Seq_80220110 *)this)->x24);
        ((Seq_80220110 *)this)->win = (void *)create_window_menu((saddr)((void *)((s32 (*)(int))get_window_layout_position)(0x2B)), (saddr)((void *)2), id);
        forward_trade_action_default__16TObjCityMainWarpFPviii(((Seq_80220110 *)this)->win, get_shop_text(4), 6, 0);
        forward_trade_action_default__16TObjCityMainWarpFPviii(((Seq_80220110 *)this)->win, get_shop_text(6), 6, 1);
        ((TWindowSubComCard *)(((Seq_80220110 *)this)->win))->calc_window_size();
        align_menu_entry_positions(((Seq_80220110 *)this)->win);
        ((TCheckRoomSequence *)(((Seq_80220110 *)this)->win))->set_ready_flag();
        ((TWindowAddition *)(((Seq_80220110 *)this)->win))->set_position_xy(get_scale(), get_scale());
    }
    if (((Seq_80220110 *)this)->win != NULL && ((TWindowMenu *)(((Seq_80220110 *)this)->win))->is_decided() != 0) {
        r = ((TWindowMenu *)(((Seq_80220110 *)this)->win))->get_selected_value();
        if (r == 0) {
            ((Seq_80220110 *)this)->m4(0xB, 1);
            ((TShopWindowBase *)((Seq_80220110 *)this))->set_field_20(3);
            ((TWindowBase *)(((Seq_80220110 *)this)->win))->close();
            ((Seq_80220110 *)this)->win = NULL;
            return;
        }
        if (r == 1) {
            ((TShopWindowBase *)((Seq_80220110 *)this))->set_field_20(4);
            ((TWindowBase *)(((Seq_80220110 *)this)->win))->close();
            ((Seq_80220110 *)this)->win = NULL;
            return;
        }
    }
    if (((Seq_80220110 *)this)->win != NULL && ((TWindowMenu *)(((Seq_80220110 *)this)->win))->is_cancelled() != 0) {
        ((Seq_80220110 *)this)->m4(0x2C, 1);
        ((TShopWindowBase *)((Seq_80220110 *)this))->set_field_20(7);
        ((TWindowBase *)(((Seq_80220110 *)this)->win))->close();
        ((Seq_80220110 *)this)->win = NULL;
    }
}

void TShopItemTecSequence::open_item_list_window() {
    W_802200A8 *o = (W_802200A8 *)new TShopItemListWindow((saddr)tl_05, (saddr)((S_802200A8 *)this), (s32)(((S_802200A8 *)this)->f24));
    o->cb0 = (void *)close__20TShopItemTecSequenceFPv;
    reset_controller_input_state();
    this->set_field_20(5);
}

void TShopItemTecSequence::open_sell_window() {
    W_80220030 *o = (W_80220030 *)new TShopEquipmentSellWindow((void *)tl_05, (void *)((S_80220030 *)this), (void *)(((S_80220030 *)this)->f24), (void *)(0x2d));
    o->cb0 = (void *)close__20TShopItemTecSequenceFPv;
    o->cb1 = (void *)select_and_advance__20TShopItemTecSequenceFPv;
    reset_controller_input_state();
    this->set_field_20(5);
}

s32 TShopItemTecSequence::close_if_done() {
    if ((this->vfunc_10() != 0) && ((sub_80223A48() != 0) || (sub_802239EC__13TShopSequenceFv(this) != 0))) {
        close_if_single_screen();
        TShopSequence::close_window();
        queue_destruction();
    }
}

s32 TShopItemTecSequence::handle_select() {
    if ((this->vfunc_10() != 0) && ((sub_80223A48() != 0) || (sub_802239EC__13TShopSequenceFv(this) != 0))) {
        ((VObj_8021FF30_8021FE6C*)this)->m4(lbl_805D6248, 1);
        this->set_field_20(lbl_805D624C);
    }
}

void close__20TShopItemTecSequenceFPv(void *shop_window_base) {
    struct VObj_8021FEE0_8021FE6C *o = (struct VObj_8021FEE0_8021FE6C *)shop_window_base;
    if (o != NULL) {
        o->m4(0x1A, 1);
        ((TShopWindowBase *)shop_window_base)->set_field_20(2);
    }
}

void select_and_advance__20TShopItemTecSequenceFPv(void *shop_window_base) {
    if (shop_window_base != NULL) {
        ((VObj_8021FE80_8021FE6C *)shop_window_base)->m4(0x1B, 1);
        ((TShopWindowBase *)shop_window_base)->set_field_20(6);
        lbl_805D6248 = 0x1A;
        lbl_805D624C = 2;
    }
}

int TShopItemTecSequence__sub_8021FE6C(int a0) {  return shop_tool_stock_counts[a0]; }


}
