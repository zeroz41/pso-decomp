#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/city/TShopArmorListWindow.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/city/TShopEquipmentGearSequence.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/quest/TQuestListVM.h"
#include "pso/ui/city/TShopEquipmentSellWindow.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/player/TObjPlayer_801A5AEC.h"
#include "pso/unk/text_8026934C.h"
#include "pso/ui/city/TShopSequence.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/city/TCheckRoomSequence.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/system/task/TObject.h"

#pragma readonly_strings on

struct Base_8021B2E8 { char pad[0x18]; };
struct VObj_8021B2E8 : Base_8021B2E8 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(int a, int b);
};
struct Base_8021B338 { char pad[0x18]; };
struct VObj_8021B338 : Base_8021B338 {
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

struct Base_8021B288 { char pad[0x18]; };
struct VObj_8021B288 : Base_8021B288 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(int, int);
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

struct Stack_8021D948
{
  f32 sp8;
  f32 spC;
};

struct W_8021B438 { u8 pad[0x3a4]; void *cb0; void *cb1; };

struct S_8021B438 { u8 pad[0x24]; s32 f24; };

struct W_8021B4B0 { u8 pad[0x1f4]; void *cb0; };

struct S_8021B4B0 { u8 pad[0x24]; s32 f24; };

struct Base_8021B518 { char pad[0x18]; };

struct VObj_8021B518 : Base_8021B518 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(s32, s32);
};

struct Seq_8021B518 { u8 pad[0x24]; s32 f24; u8 pad28[4]; void *win; };

extern "C" {

s32 sub_802239EC__13TShopSequenceFv(void *);
s32 close_window__13TShopSequenceFv(void *);

s32 lbl_805D6218;
s32 lbl_805D621C;

unsigned short get_child_field1c__13TShopSequenceFv(void *);
s32 set_service_counter_camera(void *, int);
s32 get_window_layout_position(int, f32);
s32 sub_8022397C__15TShopWindowBaseFv(void *);
s32 TShopEquipmentGearSequence__window_slot_table[4];
TShopEquipmentGearSequence *lbl_805D6220;
const char *TShopEquipmentGearSequence__class_name = "TShopEquipmentGearSequence";
void enter_quest_list__26TShopEquipmentGearSequenceFv(void *);
void open_gear_shop__26TShopEquipmentGearSequenceFv(void *);
extern void *tl_05;
s32 get_entity_id(s32);
s32 get_shop_text(s32);
s32 align_menu_entry_positions(void *);
int forward_trade_action_default__16TObjCityMainWarpFPviii(void *p, int a1, int a2, int a3);
s32 create_window_menu(s32 arg0, s32 arg1, s32 arg2);
#define PSO_VCALL_VObj_18_a93f07_m4(_self, _arg0, _arg1) (((VObj_18_a93f07 *)(_self))->m4((_arg0), (_arg1)))

// Written last-to-first: the unit is built with deferred code generation (see configure.py).

void TShopEquipmentGearSequence::clear_window_slot_table() {
    s32 i;
    for (i = 0; i < 4; i++) {
        TShopEquipmentGearSequence__window_slot_table[i] = 0;
    }
}

void TShopEquipmentGearSequence::clear_window_slots() {
    s32 i;
    for (i = 0; i < 4; i++) {
        TShopEquipmentGearSequence__window_slot_table[i] = 0;
    }
}

}

TShopEquipmentGearSequence::TShopEquipmentGearSequence(TObject *parent, TObjPlayer *player) : TShopSequence(parent) {
    m_name = TShopEquipmentGearSequence__class_name;
    state = 0;
    this->player = player;
    choice_menu = NULL;
    meseta_window = NULL;
    counter_camera = NULL;
    lbl_805D6220 = this;
    lbl_805D6218 = 0;
    lbl_805D621C = 0;
    TShopEquipmentGearSequence__window_slot_table[sub_8022397C__15TShopWindowBaseFv(this)] = 1;
}

TShopEquipmentGearSequence::~TShopEquipmentGearSequence() {
    if (counter_camera != NULL) {
        counter_camera->queue_destruction();
        counter_camera = NULL;
    }
    if (choice_menu != NULL) {
        choice_menu->close();
        choice_menu = NULL;
    }
    if (meseta_window != NULL) {
        meseta_window->close();
        meseta_window = NULL;
    }
    close_message_window();
    lbl_805D6220 = NULL;
    TShopEquipmentGearSequence__window_slot_table[sub_8022397C__15TShopWindowBaseFv(this)] = 0;
}

void TShopEquipmentGearSequence::vfunc_11() {
    switch (state) {
    case 0:
        TShopSequence::restore_player_state();
        set_field_20(1);
        return;
    case 1:
        open_greeting();
        return;
    case 2:
        update_buy_sell_choice(this);
        return;
    case 3:
        open_armor_list_window();
        return;
    case 4:
        open_sell_window();
        return;
    case 6:
        try_close();
        return;
    case 7:
        handle_confirm();
    default:
        return;
    }
}

s32 TShopEquipmentGearSequence::open_greeting() {
  Stack_8021D948 stack;
  stack.sp8 = 332.0f;
  stack.spC = 80.0f;
  this->create_message_window(get_window_layout_position(0x2C, 332.0f), (s32)&stack.sp8);
  PSO_VCALL_VObj_18_a93f07_m4(this, 0x2b, 1);
  meseta_window = (TWindowBase *)create_meseta_window((s32) get_child_field1c__13TShopSequenceFv(this));
  this->set_field_20(2);
  counter_camera = (TObject *)set_service_counter_camera((void *) this, 0x4);
}

extern "C" {

#define arg0 ((Seq_8021B518 *) self)
void TShopEquipmentGearSequence::update_buy_sell_choice(void *self) {
    u16 id;
    s32 r;
    if (arg0->win == NULL) {
        id = get_entity_id(arg0->f24);
        arg0->win = (void *)create_window_menu(((s32 (*)(int)) get_window_layout_position)(0x2B), 2, id);
        forward_trade_action_default__16TObjCityMainWarpFPviii(arg0->win, get_shop_text(4), 6, 0);
        forward_trade_action_default__16TObjCityMainWarpFPviii(arg0->win, get_shop_text(6), 6, 1);
        ((TWindowSubComCard *)(arg0->win))->calc_window_size();
        align_menu_entry_positions(arg0->win);
        ((TCheckRoomSequence *)(arg0->win))->set_ready_flag();
        ((TWindowAddition *)(arg0->win))->set_position_xy(((TShopWindowBase *)arg0)->get_scale(), ((TShopWindowBase *)arg0)->get_scale());
    }
    if (arg0->win != NULL && ((TWindowMenu *)(arg0->win))->is_decided() != 0) {
        r = ((TWindowMenu *)arg0->win)->get_selected_value();
        if (r == 0) {
            ((TShopWindowBase *)arg0)->set_field_20(3);
            ((TWindowBase *)arg0->win)->close();
            arg0->win = NULL;
            return;
        }
        if (r == 1) {
            ((TShopWindowBase *)arg0)->set_field_20(4);
            ((TWindowBase *)arg0->win)->close();
            arg0->win = NULL;
            return;
        }
    }
    if (arg0->win != NULL && ((TWindowMenu *)(arg0->win))->is_cancelled() != 0) {
        ((VObj_8021B518 *) arg0)->m4(0x2C, 1);
        ((TShopWindowBase *)arg0)->set_field_20(6);
        ((TWindowBase *)arg0->win)->close();
        arg0->win = NULL;
    }
}
#undef arg0

void TShopEquipmentGearSequence::open_armor_list_window() {
    W_8021B4B0 *o = (W_8021B4B0 *)new TShopArmorListWindow((s32)tl_05, (s32)((S_8021B4B0 *)this), (s32)(((S_8021B4B0 *)this)->f24));
    o->cb0 = (void *)enter_quest_list__26TShopEquipmentGearSequenceFv;
    reset_controller_input_state();
    this->set_field_20(5);
}

void TShopEquipmentGearSequence::open_sell_window() {
    W_8021B438 *o = (W_8021B438 *)new TShopEquipmentSellWindow((void *)tl_05, (void *)((S_8021B438 *)this), (void *)(((S_8021B438 *)this)->f24), (void *)(0x2a));
    o->cb0 = (void *)enter_quest_list__26TShopEquipmentGearSequenceFv;
    o->cb1 = (void *)open_gear_shop__26TShopEquipmentGearSequenceFv;
    reset_controller_input_state();
    this->set_field_20(5);
}

void TShopEquipmentGearSequence::try_close() {
    if ((this->vfunc_10() != 0) && ((sub_80223A48() != 0) || (sub_802239EC__13TShopSequenceFv(this) != 0))) {
        close_if_single_screen();
        close_window__13TShopSequenceFv(this);
        queue_destruction();
    }
}

void TShopEquipmentGearSequence::handle_confirm() {
    if ((this->vfunc_10() != 0) && ((sub_80223A48() != 0) || (sub_802239EC__13TShopSequenceFv(this) != 0))) {
        ((VObj_8021B338*)this)->m4(lbl_805D6218, 1);
        this->set_field_20(lbl_805D621C);
    }
}

void TShopEquipmentGearSequence::enter_quest_list() {
    struct VObj_8021B2E8 *o = (struct VObj_8021B2E8 *)this;
    if (o != NULL) {
        o->m4(0x1A, 1);
        this->set_field_20(2);
    }
}

void TShopEquipmentGearSequence::open_gear_shop() {
    if (this != NULL) {
        ((struct VObj_8021B288 *)this)->m4(0x1B, 1);
        this->set_field_20(7);
        lbl_805D6218 = 0x1A;
        lbl_805D621C = 2;
    }
}

}
