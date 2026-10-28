#include "types.h"
#include "pso/misc/TShopEquipmentGearSequence_8021B438.h"
#include "pso/player/TObjPlayer_801A5AEC.h"
#include "pso/unk/text_8026934C.h"
#include "pso/misc/TShopSequence.h"
#include "pso/misc/TUnk_804CDFE8.h"
#include "pso/TShopWindowBase.h"
#include "pso/misc/TShopEquipmentGearSequence.h"
#include "pso/misc/TWindowMenu.h"
#include "pso/misc/TCheckRoomSequence.h"
#include "pso/misc/TQuestListVM.h"
#include "pso/misc/TWindowSubComCard.h"

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

struct RecoveredGlobal_8021B7D0_TShopEquipmentGearSequence__data_80513EB0 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_8021B89C___vt__26TShopEquipmentGearSequence {
    s32 value;
    u8 remaining[0x34];
};

struct RecoveredGlobal_8021B89C_TShopEquipmentGearSequence__data_80513EB0 {
    s32 value;
    u8 remaining[0xC];
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
extern const f32 lbl_805DC6C8;
extern const f32 lbl_805DC6CC;
void queue_destruction__7TObjectFv(void *arg0);
void *__dt__13TShopSequenceFv(void *arg0, s16 arg1);
s32 sub_8022397C__15TShopWindowBaseFv(void *);
s32 __dl__7TObjectFPv(void *);
void TWindow__close(u8 *arg0);
extern RecoveredGlobal_8021B7D0___vt__26TShopEquipmentGearSequence __vt__26TShopEquipmentGearSequence;
extern RecoveredGlobal_8021B7D0_TShopEquipmentGearSequence__data_80513EB0 TShopEquipmentGearSequence__window_slot_table;
extern s32 lbl_805D6220;
u8 *TShopSequence__ct(u8 *arg0);
extern s32 TShopEquipmentGearSequence__class_name;
extern s32 lbl_805D6218;
extern s32 lbl_805D621C;
s32 restore_player_state__13TShopSequenceFv(void *);
void *__nw__7TObjectFUl(u32);
void *TShopEquipmentSellWindow__ct(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4);
void enter_quest_list__26TShopEquipmentGearSequenceFv(void *);
void open_gear_shop__26TShopEquipmentGearSequenceFv(void *);
extern void *tl_05;
u8 *TShopArmorListWindow__ct(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
s32 get_entity_id(s32);
s32 get_shop_text(s32);
f32 get_scale__15TShopWindowBaseFv(void *);
s32 get_selected_menu_value(void *);
s32 align_menu_entry_positions(void *);
int forward_trade_action_default__16TObjCityMainWarpFPviii(void *p, int a1, int a2, int a3);
s32 create_window_menu(s32 arg0, s32 arg1, s32 arg2);
typedef struct Stack_8021D948 Stack_8021D948;
typedef struct VBase_18_a93f07 VBase_18_a93f07;
typedef struct VObj_18_a93f07 VObj_18_a93f07;
#define PSO_VCALL_VObj_18_a93f07_m4(_self, _arg0, _arg1) (((VObj_18_a93f07 *)(_self))->m4((_arg0), (_arg1)))

void TShopEquipmentGearSequence::open_sell_window() {
    W_8021B438 *o = (W_8021B438 *)__nw__7TObjectFUl(0x3ac);
    if (o != 0) {
        o = (W_8021B438 *)(TShopEquipmentSellWindow__ct((void *)o, (void *)tl_05, (void *)((S_8021B438 *)this), (void *)(((S_8021B438 *)this)->f24), (void *)(0x2a)));
    }
    o->cb0 = (void *)enter_quest_list__26TShopEquipmentGearSequenceFv;
    o->cb1 = (void *)open_gear_shop__26TShopEquipmentGearSequenceFv;
    reset_controller_input_state();
    this->set_field_20(5);
}

void TShopEquipmentGearSequence::open_armor_list_window() {
    W_8021B4B0 *o = (W_8021B4B0 *)__nw__7TObjectFUl(0x1f8);
    if (o != 0) {
        o = (W_8021B4B0 *)(TShopArmorListWindow__ct((u8 *)o, (s32)tl_05, (s32)((S_8021B4B0 *)this), (s32)(((S_8021B4B0 *)this)->f24)));
    }
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
        ((TUnk_804CDFE8 *)(arg0->win))->set_position_xy(get_scale__15TShopWindowBaseFv(arg0), get_scale__15TShopWindowBaseFv(arg0));
    }
    if (arg0->win != NULL && ((TWindowMenu *)(arg0->win))->is_visible() != 0) {
        r = get_selected_menu_value(arg0->win);
        if (r == 0) {
            ((TShopWindowBase *)arg0)->set_field_20(3);
            TWindow__close((u8 *)arg0->win);
            arg0->win = NULL;
            return;
        }
        if (r == 1) {
            ((TShopWindowBase *)arg0)->set_field_20(4);
            TWindow__close((u8 *)arg0->win);
            arg0->win = NULL;
            return;
        }
    }
    if (arg0->win != NULL && ((TWindowSubComCard *)(arg0->win))->get_status_flag() != 0) {
        ((VObj_8021B518 *) arg0)->m4(0x2C, 1);
        ((TShopWindowBase *)arg0)->set_field_20(6);
        TWindow__close((u8 *)arg0->win);
        arg0->win = NULL;
    }
}
#undef arg0

s32 TShopEquipmentGearSequence::open_greeting() {
  Stack_8021D948 stack;
  stack.sp8 = lbl_805DC6C8;
  stack.spC = lbl_805DC6CC;
  this->create_message_window(get_window_layout_position(0x2C, (f32) lbl_805DC6C8), (s32)&stack.sp8);
  PSO_VCALL_VObj_18_a93f07_m4(this, 0x2b, 1);
  this->m_30 = create_meseta_window((s32) get_child_field1c__13TShopSequenceFv(this));
  this->set_field_20(2);
  *((s32 *) (((s8 *) ((u8 *)this)) + 0x34)) = set_service_counter_camera((void *) this, 0x4);
}
typedef char RecoveredGlobal_8021B7D0___vt__26TShopEquipmentGearSequence_size[sizeof(RecoveredGlobal_8021B7D0___vt__26TShopEquipmentGearSequence) == 0x38 ? 1 : -1];
typedef char RecoveredGlobal_8021B7D0_TShopEquipmentGearSequence__data_80513EB0_size[sizeof(RecoveredGlobal_8021B7D0_TShopEquipmentGearSequence__data_80513EB0) == 0x10 ? 1 : -1];

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

u8 *__dt__26TShopEquipmentGearSequenceFv(TShopEquipmentGearSequence *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = &__vt__26TShopEquipmentGearSequence.value;
        if ((u32) *(u32 *)((s8 *)arg0 + 0x34) != 0U) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x34));
            *(u32 *)((s8 *)arg0 + 0x34) = 0U;
        }
        if ((u32) arg0->m_2c != 0U) {
            TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x2C)));
            arg0->m_2c = 0U;
        }
        if ((u32) arg0->m_30 != 0U) {
            TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x30)));
            arg0->m_30 = 0U;
        }
        ((TShopSequence *)arg0)->close_message_window();
        lbl_805D6220 = 0;
        *(s32 *)((s8 *)&TShopEquipmentGearSequence__window_slot_table.value + (sub_8022397C__15TShopWindowBaseFv(arg0) * 4)) = 0;
        __dt__13TShopSequenceFv((arg0), 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return (u8 *)arg0;
}
typedef char RecoveredGlobal_8021B89C___vt__26TShopEquipmentGearSequence_size[sizeof(RecoveredGlobal_8021B89C___vt__26TShopEquipmentGearSequence) == 0x38 ? 1 : -1];
typedef char RecoveredGlobal_8021B89C_TShopEquipmentGearSequence__data_80513EB0_size[sizeof(RecoveredGlobal_8021B89C_TShopEquipmentGearSequence__data_80513EB0) == 0x10 ? 1 : -1];
u8 *TShopEquipmentGearSequence__ct(u8 *shop_equipment_gear_sequence, s32 arg1, s32 arg2) {
    TShopSequence__ct((shop_equipment_gear_sequence));
    *(s32 **)((s8 *)shop_equipment_gear_sequence + 0x18) = &(*(RecoveredGlobal_8021B89C___vt__26TShopEquipmentGearSequence *)&__vt__26TShopEquipmentGearSequence).value;
    *(s32 *)((s8 *)shop_equipment_gear_sequence + 0) = (s32) TShopEquipmentGearSequence__class_name;
    ((TShopEquipmentGearSequence *)shop_equipment_gear_sequence)->m_20 = 0;
    *(s32 *)((s8 *)shop_equipment_gear_sequence + 0x24) = arg2;
    ((TShopEquipmentGearSequence *)shop_equipment_gear_sequence)->m_2c = 0;
    ((TShopEquipmentGearSequence *)shop_equipment_gear_sequence)->m_30 = 0;
    *(s32 *)((s8 *)shop_equipment_gear_sequence + 0x34) = 0;
    (*(u8 * *)&lbl_805D6220) = shop_equipment_gear_sequence;
    lbl_805D6218 = 0;
    lbl_805D621C = 0;
    *(s32 *)((s8 *)(&(*(RecoveredGlobal_8021B89C_TShopEquipmentGearSequence__data_80513EB0 *)&TShopEquipmentGearSequence__window_slot_table).value) + (sub_8022397C__15TShopWindowBaseFv(shop_equipment_gear_sequence) * 4)) = 1;
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
