#include "types.h"
#include "pso/misc/TShopEquipmentListWindow.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/misc/TWindowSubComCard_80265410.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/player/TObjPlayer_801A5AEC.h"
#include "pso/unk/text_80222C28.h"
#include "pso/unk/text_8026934C.h"
#include "pso/misc/TShopSequence.h"
#include "pso/misc/TUnk_804CDFE8.h"
#include "pso/misc/TWindowMenu.h"
#include "pso/misc/TShopEquipmentSequence.h"
#include "pso/misc/TCheckRoomSequence.h"
#include "pso/misc/TWindowSubComCard.h"

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

struct RecoveredGlobal_8021DA90___vt__22TShopEquipmentSequence {
    s32 value;
    u8 remaining[0x34];
};

struct RecoveredGlobal_8021DA90_TShopEquipmentSequence__data_80513EC0 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_8021DB58___vt__22TShopEquipmentSequence {
    s32 value;
    u8 remaining[0x34];
};

struct RecoveredGlobal_8021DB58_TShopEquipmentSequence__data_80513EC0 {
    s32 value;
    u8 remaining[0xC];
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
s32 set_field_20__15TShopWindowBaseFl(void *, s32);
unsigned short get_child_field1c__13TShopSequenceFv(void *);
s32 set_service_counter_camera(void *, int);
s32 get_window_layout_position(int, f32);
extern const f32 lbl_805DC6E0;
extern const f32 lbl_805DC6E4;
void *__dt__13TShopSequenceFv(void *arg0, s16 arg1);
s32 sub_8022397C__15TShopWindowBaseFv(void *);
s32 __dl__7TObjectFPv(void *);
extern RecoveredGlobal_8021DA90___vt__22TShopEquipmentSequence __vt__22TShopEquipmentSequence;
extern RecoveredGlobal_8021DA90_TShopEquipmentSequence__data_80513EC0 TShopEquipmentSequence__slot_active_flags;
u8 *TShopSequence__ct(u8 *arg0);
extern s32 TShopEquipmentSequence__class_name;
extern u8 *lbl_805D6228;
extern s32 lbl_805D622C;
extern s32 lbl_805D6230;
s32 restore_player_state__13TShopSequenceFv(void *);
void *__nw__7TObjectFUl(u32);
void *TShopEquipmentSellWindow__ct(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4);
extern void *tl_05;
u16 get_entity_id(void *);
f32 get_scale__15TShopWindowBaseFv(void *);
s32 get_selected_menu_value(void *);
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
s32 sub_80223A48__15TShopWindowBaseFv(void *);
s32 close_if_single_screen__13TShopSequenceFv(void *);
s32 close_window__13TShopSequenceFv(void *);

void init_window__22TShopEquipmentSequenceFPv(void *shop_window_base) {
    if (shop_window_base != NULL) {
        ((VObj_8021D524 *)shop_window_base)->m4(0x1B, 1);
        set_field_20__15TShopWindowBaseFl(shop_window_base, 8);
        lbl_805D622C = 0x1A;
        lbl_805D6230 = 2;
    }
}

void exit__22TShopEquipmentSequenceFPv(void *shop_window_base) {
    struct VObj_8021D584_8021D524 *o = (struct VObj_8021D584_8021D524 *)shop_window_base;
    if (o != NULL) {
        o->m4(0x1A, 1);
        set_field_20__15TShopWindowBaseFl(shop_window_base, 2);
    }
}

s32 TShopEquipmentSequence::handle_confirm() {
    if ((this->vfunc_10() != 0) && ((sub_80223A48__15TShopWindowBaseFv(this) != 0) || (sub_802239EC__13TShopSequenceFv(this) != 0))) {
        ((VObj_8021D5D4_8021D524*)this)->m4(lbl_805D622C, 1);
        set_field_20__15TShopWindowBaseFl(this, lbl_805D6230);
    }
}

s32 TShopEquipmentSequence__sub_8021D65C(void) {  }

s32 TShopEquipmentSequence::close_if_done() {
    if ((this->vfunc_10() != 0) && ((sub_80223A48__15TShopWindowBaseFv(this) != 0) || (sub_802239EC__13TShopSequenceFv(this) != 0))) {
        close_if_single_screen__13TShopSequenceFv(this);
        close_window__13TShopSequenceFv(this);
        queue_destruction__7TObjectFv(this);
    }
}
typedef struct Stack_8021D948 Stack_8021D948;
typedef struct VBase_18_a93f07 VBase_18_a93f07;
typedef struct VObj_18_a93f07 VObj_18_a93f07;

void TShopEquipmentSequence::open_sell_window() {
    W_8021D6D8 *o = (W_8021D6D8 *)__nw__7TObjectFUl(0x3ac);
    if (o != 0) {
        o = (W_8021D6D8 *)(TShopEquipmentSellWindow__ct((void *)o, (void *)tl_05, (void *)((S_8021D6D8 *)this), (void *)(((S_8021D6D8 *)this)->f24), (void *)(0x26)));
    }
    o->cb0 = (void *)exit__22TShopEquipmentSequenceFPv;
    o->cb1 = (void *)init_window__22TShopEquipmentSequenceFPv;
    reset_controller_input_state();
    set_field_20__15TShopWindowBaseFl(this, 7);
}

void TShopEquipmentSequence::open_buy_window() {
    W_8021D750 *o = (W_8021D750 *)__nw__7TObjectFUl(0x194);
    if (o != 0) {
        o = (W_8021D750 *)(TShopEquipmentListWindow__ct((u8 *)o, (s32)tl_05, (s32)((S_8021D750 *)this), (s32)(((S_8021D750 *)this)->f24)));
    }
    o->cb0 = (void *)exit__22TShopEquipmentSequenceFPv;
    reset_controller_input_state();
    set_field_20__15TShopWindowBaseFl(this, 7);
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
        ((TUnk_804CDFE8 *)(self->win))->set_position_xy(get_scale__15TShopWindowBaseFv(self), get_scale__15TShopWindowBaseFv(self));
    }
    if (self->win != NULL && ((TWindowMenu *)(self->win))->is_visible() != 0) {
        r = get_selected_menu_value(self->win);
        if (r == 0) {
            set_field_20__15TShopWindowBaseFl(self, 3);
            TWindow__close((u8 *)self->win);
            self->win = NULL;
            return;
        }
        if (r == 1) {
            set_field_20__15TShopWindowBaseFl(self, 4);
            TWindow__close((u8 *)self->win);
            self->win = NULL;
            return;
        }
    }
    if (self->win != NULL && ((TWindowSubComCard *)(self->win))->get_status_flag() != 0) {
        ((VObj_8021D7B8 *)self)->m4(0x2C, 1);
        set_field_20__15TShopWindowBaseFl(self, 9);
        TWindow__close((u8 *)self->win);
        self->win = NULL;
    }
}

s32 TShopEquipmentSequence::open_greeting() {
    u8 *arg0 = (u8 *)this;
  Stack_8021D948 stack;
  stack.sp8 = lbl_805DC6E0;
  stack.spC = lbl_805DC6E4;
  ((TShopSequence *)arg0)->create_message_window(get_window_layout_position(0x2C, (f32) lbl_805DC6E0), (s32)&stack.sp8);
  (((VObj_18_a93f07 *)(arg0))->m4(0x27, 1));
  this->m_30 = create_meseta_window((s32) get_child_field1c__13TShopSequenceFv(arg0));
  set_field_20__15TShopWindowBaseFl(arg0, 2);
  *((s32 *) (((s8 *) arg0) + 0x34)) = set_service_counter_camera((void *) arg0, 3);
}
typedef char RecoveredGlobal_8021DA90___vt__22TShopEquipmentSequence_size[sizeof(RecoveredGlobal_8021DA90___vt__22TShopEquipmentSequence) == 0x38 ? 1 : -1];
typedef char RecoveredGlobal_8021DA90_TShopEquipmentSequence__data_80513EC0_size[sizeof(RecoveredGlobal_8021DA90_TShopEquipmentSequence__data_80513EC0) == 0x10 ? 1 : -1];

void TShopEquipmentSequence::vfunc_11() {
    u8 *arg0 = (u8 *)this;
    switch (this->m_20) {
    case 0:
        restore_player_state__13TShopSequenceFv(arg0);
        set_field_20__15TShopWindowBaseFl(arg0, 1);
        return;
    case 1:
        ((TShopEquipmentSequence *)arg0)->open_greeting();
        return;
    case 2:
        ((TShopEquipmentSequence *)arg0)->update_buy_sell_choice();
        return;
    case 3:
        ((TShopEquipmentSequence *)arg0)->open_buy_window();
        return;
    case 4:
        ((TShopEquipmentSequence *)arg0)->open_sell_window();
        return;
    case 5:
        ((s32)set_field_20__15TShopWindowBaseFl(arg0, 9));
        return;
    case 6:
        ((s32)set_field_20__15TShopWindowBaseFl(arg0, 9));
        return;
    case 7:
        TShopEquipmentSequence__sub_8021D65C();
        return;
    case 9:
        ((TShopEquipmentSequence *)arg0)->close_if_done();
        return;
    case 8:
        ((TShopEquipmentSequence *)arg0)->handle_confirm();
    default:
        return;
    }
}

u8 *__dt__22TShopEquipmentSequenceFv(TShopEquipmentSequence *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = &__vt__22TShopEquipmentSequence.value;
        if ((u32) *(u32 *)((s8 *)arg0 + 0x34) != 0U) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x34));
            *(u32 *)((s8 *)arg0 + 0x34) = 0U;
        }
        ((TShopSequence *)arg0)->close_message_window();
        if ((u32) arg0->m_2c != 0U) {
            TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x2C)));
            arg0->m_2c = 0U;
        }
        if ((u32) arg0->m_30 != 0U) {
            TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x30)));
            arg0->m_30 = 0U;
        }
        *(s32 *)((s8 *)&TShopEquipmentSequence__slot_active_flags.value + (sub_8022397C__15TShopWindowBaseFv(arg0) * 4)) = 0;
        __dt__13TShopSequenceFv((arg0), 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return (u8 *)arg0;
}
typedef char RecoveredGlobal_8021DB58___vt__22TShopEquipmentSequence_size[sizeof(RecoveredGlobal_8021DB58___vt__22TShopEquipmentSequence) == 0x38 ? 1 : -1];
typedef char RecoveredGlobal_8021DB58_TShopEquipmentSequence__data_80513EC0_size[sizeof(RecoveredGlobal_8021DB58_TShopEquipmentSequence__data_80513EC0) == 0x10 ? 1 : -1];
u8 *TShopEquipmentSequence__ct(u8 *shop_equipment_sequence, s32 arg1, s32 arg2) {
    TShopSequence__ct((shop_equipment_sequence));
    *(s32 **)((s8 *)shop_equipment_sequence + 0x18) = &(*(RecoveredGlobal_8021DB58___vt__22TShopEquipmentSequence *)&__vt__22TShopEquipmentSequence).value;
    *(s32 *)((s8 *)shop_equipment_sequence + 0) = (s32) TShopEquipmentSequence__class_name;
    ((TShopEquipmentSequence *)shop_equipment_sequence)->m_20 = 0;
    *(s32 *)((s8 *)shop_equipment_sequence + 0x24) = arg2;
    ((TShopEquipmentSequence *)shop_equipment_sequence)->m_2c = 0;
    ((TShopEquipmentSequence *)shop_equipment_sequence)->m_30 = 0;
    *(s32 *)((s8 *)shop_equipment_sequence + 0x34) = 0;
    lbl_805D6228 = shop_equipment_sequence;
    lbl_805D622C = 0;
    lbl_805D6230 = 0;
    *(s32 *)((s8 *)(&(*(RecoveredGlobal_8021DB58_TShopEquipmentSequence__data_80513EC0 *)&TShopEquipmentSequence__slot_active_flags).value) + (sub_8022397C__15TShopWindowBaseFv(shop_equipment_sequence) * 4)) = 1;
    return shop_equipment_sequence;
}

void TShopEquipmentSequence__sub_8021DBE0(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        ((s32 *)&TShopEquipmentSequence__slot_active_flags)[i] = 0;
    }
}

void TShopEquipmentSequence__sub_8021DC08(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        ((s32 *)&TShopEquipmentSequence__slot_active_flags)[i] = 0;
    }
}

}
