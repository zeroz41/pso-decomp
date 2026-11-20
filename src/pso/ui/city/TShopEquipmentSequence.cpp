#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/ui/city/TShopEquipmentSellWindow.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/city/TShopEquipmentListWindow.h"
#include "pso/ui/window/TWindowSubComCard_80244774.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/player/TObjPlayer_801A5AEC.h"
#include "pso/unk/text_80222C28.h"
#include "pso/unk/text_8026934C.h"
#include "pso/ui/city/TShopSequence.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/city/TShopEquipmentSequence.h"
#include "pso/ui/city/TCheckRoomSequence.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/system/task/TObject.h"

#pragma readonly_strings on

struct Base_8021D584_8021D524 { char pad[0x18]; };
struct VObj_8021D584_8021D524 : Base_8021D584_8021D524 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(int, int);
};
struct Base_8021D5D4_8021D524 { char pad[0x18]; };
struct VObj_8021D5D4_8021D524 : Base_8021D5D4_8021D524 {
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

struct Stack_8021D948
{
  f32 sp8;
  f32 spC;
};

struct W_8021D6D8 { u8 pad[0x3a4]; void *cb0; void *cb1; };

struct S_8021D6D8 { u8 pad[0x24]; s32 f24; };

struct W_8021D750 { u8 pad[0x190]; void *cb0; };

struct S_8021D750 { u8 pad[0x24]; s32 f24; };

struct Base_8021D7B8 { char pad[0x18]; };

struct VObj_8021D7B8 : Base_8021D7B8 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(int, int);
};

struct Seq_8021D7B8 { u8 pad[0x24]; void *f24; u8 pad28[4]; void *win; };

extern "C" {
unsigned short get_child_field1c__13TShopSequenceFv(void *);
s32 set_service_counter_camera(void *, int);
s32 get_window_layout_position(int, f32);
s32 TShopEquipmentSequence__slot_active_flags[4];
const char *TShopEquipmentSequence__class_name = "TShopEquipmentSequence";
TShopEquipmentSequence *lbl_805D6228;
s32 lbl_805D622C;
s32 lbl_805D6230;
extern void *tl_05;
u16 get_entity_id(void *);
void align_menu_entry_positions(void *w);
struct Base_8021D524 { char pad[0x18]; };
struct VObj_8021D524 : Base_8021D524 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(int, int);
};

s32 sub_802239EC__13TShopSequenceFv(void *);

// Written last-to-first: the unit is built with deferred code generation (see configure.py).

void TShopEquipmentSequence__sub_8021DC08(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        TShopEquipmentSequence__slot_active_flags[i] = 0;
    }
}

void TShopEquipmentSequence__sub_8021DBE0(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        TShopEquipmentSequence__slot_active_flags[i] = 0;
    }
}

}

TShopEquipmentSequence::TShopEquipmentSequence(TObject *parent, TObjPlayer *player) : TShopSequence(parent) {
    m_name = TShopEquipmentSequence__class_name;
    state = 0;
    this->player = player;
    choice_menu = NULL;
    meseta_window = NULL;
    counter_camera = NULL;
    lbl_805D6228 = this;
    lbl_805D622C = 0;
    lbl_805D6230 = 0;
    TShopEquipmentSequence__slot_active_flags[sub_8022397C()] = 1;
}

TShopEquipmentSequence::~TShopEquipmentSequence() {
    if (counter_camera != NULL) {
        counter_camera->queue_destruction();
        counter_camera = NULL;
    }
    close_message_window();
    if (choice_menu != NULL) {
        choice_menu->close();
        choice_menu = NULL;
    }
    if (meseta_window != NULL) {
        meseta_window->close();
        meseta_window = NULL;
    }
    TShopEquipmentSequence__slot_active_flags[sub_8022397C()] = 0;
}

void TShopEquipmentSequence::vfunc_11() {
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
        open_buy_window();
        return;
    case 4:
        open_sell_window();
        return;
    case 5:
        set_field_20(9);
        return;
    case 6:
        set_field_20(9);
        return;
    case 7:
        TShopEquipmentSequence__sub_8021D65C();
        return;
    case 9:
        close_if_done();
        return;
    case 8:
        handle_confirm();
    default:
        return;
    }
}

extern "C" {

s32 TShopEquipmentSequence::open_greeting() {
    u8 *arg0 = (u8 *)this;
  Stack_8021D948 stack;
  stack.sp8 = 332.0f;
  stack.spC = 80.0f;
  ((TShopSequence *)arg0)->create_message_window(get_window_layout_position(0x2C, 332.0f), (s32)&stack.sp8);
  (((VObj_18_a93f07 *)(arg0))->m4(0x27, 1));
  meseta_window = (TWindowBase *)create_meseta_window((s32) get_child_field1c__13TShopSequenceFv(arg0));
  ((TShopWindowBase *)arg0)->set_field_20(2);
  counter_camera = (TObject *)set_service_counter_camera((void *) arg0, 3);
}

void TShopEquipmentSequence::update_buy_sell_choice() {
#define self ((Seq_8021D7B8 *)this)
    s32 r;
    if (self->win == NULL) {
        s32 id = get_entity_id(self->f24);
        self->win = (void *)create_window_menu(((s32 (*)(int))get_window_layout_position)(0x2B), 2, id);
        forward_trade_action_default__16TObjCityMainWarpFPviii(self->win, get_shop_text(4), 6, 0);
        forward_trade_action_default__16TObjCityMainWarpFPviii(self->win, get_shop_text(6), 6, 1);
        ((TWindowSubComCard *)(self->win))->calc_window_size();
        align_menu_entry_positions(self->win);
        ((TCheckRoomSequence *)(self->win))->set_ready_flag();
        ((TWindowAddition *)(self->win))->set_position_xy(((TShopWindowBase *)self)->get_scale(), ((TShopWindowBase *)self)->get_scale());
    }
    if (self->win != NULL && ((TWindowMenu *)(self->win))->is_decided() != 0) {
        r = ((TWindowMenu *)self->win)->get_selected_value();
        if (r == 0) {
            ((TShopWindowBase *)self)->set_field_20(3);
            ((TWindowBase *)self->win)->close();
            self->win = NULL;
            return;
        }
        if (r == 1) {
            ((TShopWindowBase *)self)->set_field_20(4);
            ((TWindowBase *)self->win)->close();
            self->win = NULL;
            return;
        }
    }
    if (self->win != NULL && ((TWindowMenu *)(self->win))->is_cancelled() != 0) {
        ((VObj_8021D7B8 *)self)->m4(0x2C, 1);
        ((TShopWindowBase *)self)->set_field_20(9);
        ((TWindowBase *)self->win)->close();
        self->win = NULL;
    }
}

void TShopEquipmentSequence::open_buy_window() {
    W_8021D750 *o = (W_8021D750 *)new TShopEquipmentListWindow((s32)tl_05, (s32)((S_8021D750 *)this), (s32)(((S_8021D750 *)this)->f24));
    o->cb0 = (void *)exit__22TShopEquipmentSequenceFPv;
    reset_controller_input_state();
    set_field_20(7);
}

void TShopEquipmentSequence::open_sell_window() {
    W_8021D6D8 *o = (W_8021D6D8 *)new TShopEquipmentSellWindow((void *)tl_05, (void *)((S_8021D6D8 *)this), (void *)(((S_8021D6D8 *)this)->f24), (void *)(0x26));
    o->cb0 = (void *)exit__22TShopEquipmentSequenceFPv;
    o->cb1 = (void *)init_window__22TShopEquipmentSequenceFPv;
    reset_controller_input_state();
    set_field_20(7);
}

s32 TShopEquipmentSequence::close_if_done() {
    if ((this->vfunc_10() != 0) && ((sub_80223A48() != 0) || (sub_802239EC__13TShopSequenceFv(this) != 0))) {
        close_if_single_screen();
        TShopSequence::close_window();
        queue_destruction();
    }
}

s32 TShopEquipmentSequence__sub_8021D65C(void) {  }

s32 TShopEquipmentSequence::handle_confirm() {
    if ((this->vfunc_10() != 0) && ((sub_80223A48() != 0) || (sub_802239EC__13TShopSequenceFv(this) != 0))) {
        ((VObj_8021D5D4_8021D524*)this)->m4(lbl_805D622C, 1);
        set_field_20(lbl_805D6230);
    }
}

void exit__22TShopEquipmentSequenceFPv(void *shop_window_base) {
    struct VObj_8021D584_8021D524 *o = (struct VObj_8021D584_8021D524 *)shop_window_base;
    if (o != NULL) {
        o->m4(0x1A, 1);
        ((TShopWindowBase *)shop_window_base)->set_field_20(2);
    }
}

void init_window__22TShopEquipmentSequenceFPv(void *shop_window_base) {
    if (shop_window_base != NULL) {
        ((VObj_8021D524 *)shop_window_base)->m4(0x1B, 1);
        ((TShopWindowBase *)shop_window_base)->set_field_20(8);
        lbl_805D622C = 0x1A;
        lbl_805D6230 = 2;
    }
}

}
