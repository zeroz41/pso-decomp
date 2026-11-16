#include "types.h"
#include "pso/ui/city/TShopArmorListWindow.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/city/TShopEquipmentGearSequence.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/quest/TQuestListVM.h"
#include "pso/ui/city/TShopEquipmentSellWindow.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/city/TShopEquipmentGearSequence_8021B438.h"
#include "pso/player/TObjPlayer_801A5AEC.h"
#include "pso/unk/text_8026934C.h"
#include "pso/ui/city/TShopSequence.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/city/TCheckRoomSequence.h"
#include "pso/ui/window/TWindowSubComCard.h"

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
extern "C" {

s32 close_if_single_screen__13TShopSequenceFv(void *);
s32 sub_802239EC__13TShopSequenceFv(void *);
s32 close_window__13TShopSequenceFv(void *);

s32 lbl_805D6218;
s32 lbl_805D621C;

struct Base_8021B288 { char pad[0x18]; };
struct VObj_8021B288 : Base_8021B288 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(int, int);
};

void TShopEquipmentGearSequence::open_gear_shop() {
    if (this != NULL) {
        ((struct VObj_8021B288 *)this)->m4(0x1B, 1);
        this->set_field_20(7);
        lbl_805D6218 = 0x1A;
        lbl_805D621C = 2;
    }
}

void TShopEquipmentGearSequence::enter_quest_list() {
    struct VObj_8021B2E8 *o = (struct VObj_8021B2E8 *)this;
    if (o != NULL) {
        o->m4(0x1A, 1);
        this->set_field_20(2);
    }
}

void TShopEquipmentGearSequence::handle_confirm() {
    if ((this->vfunc_10() != 0) && ((sub_80223A48() != 0) || (sub_802239EC__13TShopSequenceFv(this) != 0))) {
        ((VObj_8021B338*)this)->m4(lbl_805D6218, 1);
        this->set_field_20(lbl_805D621C);
    }
}

void TShopEquipmentGearSequence::try_close() {
    if ((this->vfunc_10() != 0) && ((sub_80223A48() != 0) || (sub_802239EC__13TShopSequenceFv(this) != 0))) {
        close_if_single_screen__13TShopSequenceFv(this);
        close_window__13TShopSequenceFv(this);
        queue_destruction__7TObjectFv(this);
    }
}

}


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

struct RecoveredGlobal_8021B7D0___vt__26TShopEquipmentGearSequence {
    s32 value;
    u8 remaining[0x34];
};

struct RecoveredGlobal_8021B89C___vt__26TShopEquipmentGearSequence {
    s32 value;
    u8 remaining[0x34];
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
unsigned short get_child_field1c__13TShopSequenceFv(void *);
s32 set_service_counter_camera(void *, int);
s32 get_window_layout_position(int, f32);
void queue_destruction__7TObjectFv(void *arg0);
void *__dt__13TShopSequenceFv(void *arg0, s16 arg1);
s32 sub_8022397C__15TShopWindowBaseFv(void *);
s32 __dl__7TObjectFPv(void *);
extern RecoveredGlobal_8021B7D0___vt__26TShopEquipmentGearSequence __vt__26TShopEquipmentGearSequence;
struct TShopEquipmentGearSequenceWindowSlotTable { s32 value; u8 remaining[0xC]; };
TShopEquipmentGearSequenceWindowSlotTable TShopEquipmentGearSequence__window_slot_table;
s32 lbl_805D6220;
u8 *TShopSequence__ct(u8 *arg0);
const char *TShopEquipmentGearSequence__class_name = "TShopEquipmentGearSequence";
s32 restore_player_state__13TShopSequenceFv(void *);
void enter_quest_list__26TShopEquipmentGearSequenceFv(void *);
void open_gear_shop__26TShopEquipmentGearSequenceFv(void *);
extern void *tl_05;
s32 get_entity_id(s32);
s32 get_shop_text(s32);
s32 align_menu_entry_positions(void *);
int forward_trade_action_default__16TObjCityMainWarpFPviii(void *p, int a1, int a2, int a3);
s32 create_window_menu(s32 arg0, s32 arg1, s32 arg2);
typedef struct Stack_8021D948 Stack_8021D948;
typedef struct VBase_18_a93f07 VBase_18_a93f07;
typedef struct VObj_18_a93f07 VObj_18_a93f07;
#define PSO_VCALL_VObj_18_a93f07_m4(_self, _arg0, _arg1) (((VObj_18_a93f07 *)(_self))->m4((_arg0), (_arg1)))

void TShopEquipmentGearSequence::open_sell_window() {
    W_8021B438 *o = (W_8021B438 *)new TShopEquipmentSellWindow((void *)tl_05, (void *)((S_8021B438 *)this), (void *)(((S_8021B438 *)this)->f24), (void *)(0x2a));
    o->cb0 = (void *)enter_quest_list__26TShopEquipmentGearSequenceFv;
    o->cb1 = (void *)open_gear_shop__26TShopEquipmentGearSequenceFv;
    reset_controller_input_state();
    this->set_field_20(5);
}

void TShopEquipmentGearSequence::open_armor_list_window() {
    W_8021B4B0 *o = (W_8021B4B0 *)new TShopArmorListWindow((s32)tl_05, (s32)((S_8021B4B0 *)this), (s32)(((S_8021B4B0 *)this)->f24));
    o->cb0 = (void *)enter_quest_list__26TShopEquipmentGearSequenceFv;
    reset_controller_input_state();
    this->set_field_20(5);
}

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

s32 TShopEquipmentGearSequence::open_greeting() {
  Stack_8021D948 stack;
  stack.sp8 = 332.0f;
  stack.spC = 80.0f;
  this->create_message_window(get_window_layout_position(0x2C, 332.0f), (s32)&stack.sp8);
  PSO_VCALL_VObj_18_a93f07_m4(this, 0x2b, 1);
  this->m_30 = create_meseta_window((s32) get_child_field1c__13TShopSequenceFv(this));
  this->set_field_20(2);
  *((s32 *) (((s8 *) ((u8 *)this)) + 0x34)) = set_service_counter_camera((void *) this, 0x4);
}
typedef char RecoveredGlobal_8021B7D0___vt__26TShopEquipmentGearSequence_size[sizeof(RecoveredGlobal_8021B7D0___vt__26TShopEquipmentGearSequence) == 0x38 ? 1 : -1];

void TShopEquipmentGearSequence::vfunc_11() {
    u8 *arg0 = (u8 *)this;
    switch (this->m_20) {
    case 0:
        restore_player_state__13TShopSequenceFv(arg0);
        ((TShopWindowBase *)arg0)->set_field_20(1);
        return;
    case 1:
        ((TShopEquipmentGearSequence *)arg0)->open_greeting();
        return;
    case 2:
        TShopEquipmentGearSequence::update_buy_sell_choice(arg0);
        return;
    case 3:
        ((TShopEquipmentGearSequence *)arg0)->open_armor_list_window();
        return;
    case 4:
        ((TShopEquipmentGearSequence *)arg0)->open_sell_window();
        return;
    case 6:
        ((TShopEquipmentGearSequence *)arg0)->try_close();
        return;
    case 7:
        ((TShopEquipmentGearSequence *)arg0)->handle_confirm();
    default:
        return;
    }
}

u8 *__dt__26TShopEquipmentGearSequenceFv(TShopEquipmentGearSequence *shop_equipment_gear_sequence, s16 arg1) {
    if (shop_equipment_gear_sequence != NULL) {
        *(s32 **)((s8 *)shop_equipment_gear_sequence + 0x18) = &__vt__26TShopEquipmentGearSequence.value;
        if ((u32) *(u32 *)((s8 *)shop_equipment_gear_sequence + 0x34) != 0U) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)shop_equipment_gear_sequence + 0x34));
            *(u32 *)((s8 *)shop_equipment_gear_sequence + 0x34) = 0U;
        }
        if ((u32) shop_equipment_gear_sequence->m_2c != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)shop_equipment_gear_sequence + 0x2C)))->close();
            shop_equipment_gear_sequence->m_2c = 0U;
        }
        if ((u32) shop_equipment_gear_sequence->m_30 != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)shop_equipment_gear_sequence + 0x30)))->close();
            shop_equipment_gear_sequence->m_30 = 0U;
        }
        ((TShopSequence *)shop_equipment_gear_sequence)->close_message_window();
        lbl_805D6220 = 0;
        *(s32 *)((s8 *)&TShopEquipmentGearSequence__window_slot_table.value + (sub_8022397C__15TShopWindowBaseFv(shop_equipment_gear_sequence) * 4)) = 0;
        __dt__13TShopSequenceFv((shop_equipment_gear_sequence), 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(shop_equipment_gear_sequence);
        }
    }
    return (u8 *)shop_equipment_gear_sequence;
}
typedef char RecoveredGlobal_8021B89C___vt__26TShopEquipmentGearSequence_size[sizeof(RecoveredGlobal_8021B89C___vt__26TShopEquipmentGearSequence) == 0x38 ? 1 : -1];
u8 *TShopEquipmentGearSequence__ct(u8 *shop_equipment_gear_sequence, s32 arg1, s32 arg2) {
    TShopSequence__ct((shop_equipment_gear_sequence));
    *(s32 **)((s8 *)shop_equipment_gear_sequence + 0x18) = &(*(RecoveredGlobal_8021B89C___vt__26TShopEquipmentGearSequence *)&__vt__26TShopEquipmentGearSequence).value;
    ((TShopEquipmentGearSequence *)shop_equipment_gear_sequence)->m_name = TShopEquipmentGearSequence__class_name;
    ((TShopEquipmentGearSequence *)shop_equipment_gear_sequence)->m_20 = 0;
    *(s32 *)((s8 *)shop_equipment_gear_sequence + 0x24) = arg2;
    ((TShopEquipmentGearSequence *)shop_equipment_gear_sequence)->m_2c = 0;
    ((TShopEquipmentGearSequence *)shop_equipment_gear_sequence)->m_30 = 0;
    *(s32 *)((s8 *)shop_equipment_gear_sequence + 0x34) = 0;
    (*(u8 * *)&lbl_805D6220) = shop_equipment_gear_sequence;
    lbl_805D6218 = 0;
    lbl_805D621C = 0;
    *(s32 *)((s8 *)(&TShopEquipmentGearSequence__window_slot_table.value) + (sub_8022397C__15TShopWindowBaseFv(shop_equipment_gear_sequence) * 4)) = 1;
    return shop_equipment_gear_sequence;
}

void TShopEquipmentGearSequence::clear_window_slots() {
    s32 i;
    for (i = 0; i < 4; i++) {
        ((s32 *)&TShopEquipmentGearSequence__window_slot_table)[i] = 0;
    }
}

void TShopEquipmentGearSequence::clear_window_slot_table() {
    s32 i;
    for (i = 0; i < 4; i++) {
        ((s32 *)&TShopEquipmentGearSequence__window_slot_table)[i] = 0;
    }
}

}
