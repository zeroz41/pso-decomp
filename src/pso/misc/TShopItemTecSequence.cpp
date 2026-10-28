#include "types.h"
#include "pso/misc/TShopItemListWindow.h"
#include "pso/player/TObjPlayer_801A5AEC.h"
#include "pso/unk/text_8026934C.h"
#include "pso/misc/TUnk_804CDFE8.h"
#include "pso/misc/TShopSequence.h"
#include "pso/misc/TShopItemTecSequence.h"
#include "pso/misc/TWindowMenu.h"
#include "pso/TShopWindowBase.h"
#include "pso/misc/TCheckRoomSequence.h"
#include "pso/quest/TQuestListVM.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"

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

struct RecoveredGlobal_802203E4___vt__20TShopItemTecSequence {
    s32 value;
    u8 remaining[0x34];
};

struct RecoveredGlobal_802203E4_TShopItemTecSequence__data_80513EE0 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_802204B0___vt__20TShopItemTecSequence {
    s32 value;
    u8 remaining[0x34];
};

struct RecoveredGlobal_802204B0_TShopItemTecSequence__data_80513EE0 {
    s32 value;
    u8 remaining[0xC];
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
s32 set_service_counter_camera(void *, int);
s32 get_window_layout_position(int, f32);
extern const f32 lbl_805DC700;
extern const f32 lbl_805DC704;
void queue_destruction__7TObjectFv(void *arg0);
void *__dt__13TShopSequenceFv(void *arg0, s16 arg1);
s32 sub_8022397C__15TShopWindowBaseFv(void *);
s32 __dl__7TObjectFPv(void *);
void TWindow__close(u8 *arg0);
extern RecoveredGlobal_802203E4___vt__20TShopItemTecSequence __vt__20TShopItemTecSequence;
extern RecoveredGlobal_802203E4_TShopItemTecSequence__data_80513EE0 TShopItemTecSequence__slot_table;
extern s32 lbl_805D6250;
u8 *TShopSequence__ct(u8 *arg0);
extern s32 TShopItemTecSequence__class_name;
extern s32 lbl_805D6248;
extern s32 lbl_805D624C;
s32 restore_player_state__13TShopSequenceFv(void *);
void *__nw__7TObjectFUl(u32);
void *TShopEquipmentSellWindow__ct(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4);
extern void *tl_05;
s32 get_entity_id(void *);
s32 get_shop_text(s32 arg0);
f32 get_scale__15TShopWindowBaseFv(void *);
s32 get_selected_menu_value(void *);
int align_menu_entry_positions(void *);
int forward_trade_action_default__16TObjCityMainWarpFPviii(void* p, int a1, int a2, int a3);
s32 create_window_menu(s32 arg0, s32 arg1, s32 arg2);
struct Base_8021FE80_8021FE6C { char pad[0x18]; };
struct VObj_8021FE80_8021FE6C : Base_8021FE80_8021FE6C {
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

    extern int shop_tool_stock_counts[];
int TShopItemTecSequence__sub_8021FE6C(int a0) {  return shop_tool_stock_counts[a0]; }

void select_and_advance__20TShopItemTecSequenceFPv(void *shop_window_base) {
    if (shop_window_base != NULL) {
        ((VObj_8021FE80_8021FE6C *)shop_window_base)->m4(0x1B, 1);
        ((TShopWindowBase *)shop_window_base)->set_field_20(6);
        lbl_805D6248 = 0x1A;
        lbl_805D624C = 2;
    }
}

void close__20TShopItemTecSequenceFPv(void *shop_window_base) {
    struct VObj_8021FEE0_8021FE6C *o = (struct VObj_8021FEE0_8021FE6C *)shop_window_base;
    if (o != NULL) {
        o->m4(0x1A, 1);
        ((TShopWindowBase *)shop_window_base)->set_field_20(2);
    }
}

s32 TShopItemTecSequence::handle_select() {
    if ((this->vfunc_10() != 0) && ((sub_80223A48__15TShopWindowBaseFv(this) != 0) || (sub_802239EC__13TShopSequenceFv(this) != 0))) {
        ((VObj_8021FF30_8021FE6C*)this)->m4(lbl_805D6248, 1);
        this->set_field_20(lbl_805D624C);
    }
}

s32 TShopItemTecSequence::close_if_done() {
    if ((this->vfunc_10() != 0) && ((sub_80223A48__15TShopWindowBaseFv(this) != 0) || (sub_802239EC__13TShopSequenceFv(this) != 0))) {
        close_if_single_screen__13TShopSequenceFv(this);
        close_window__13TShopSequenceFv(this);
        queue_destruction__7TObjectFv(this);
    }
}

typedef struct Stack_802202BC Stack_802202BC;
typedef struct VBase_18_a93f07 VBase_18_a93f07;
typedef struct VObj_18_a93f07 VObj_18_a93f07;

void TShopItemTecSequence::open_sell_window() {
    W_80220030 *o = (W_80220030 *)__nw__7TObjectFUl(0x3ac);
    if (o != 0) {
        o = (W_80220030 *)(TShopEquipmentSellWindow__ct((void *)o, (void *)tl_05, (void *)((S_80220030 *)this), (void *)(((S_80220030 *)this)->f24), (void *)(0x2d)));
    }
    o->cb0 = (void *)close__20TShopItemTecSequenceFPv;
    o->cb1 = (void *)select_and_advance__20TShopItemTecSequenceFPv;
    reset_controller_input_state();
    this->set_field_20(5);
}

void TShopItemTecSequence::open_item_list_window() {
    W_802200A8 *o = (W_802200A8 *)__nw__7TObjectFUl(0x1c4);
    if (o != 0) {
        o = (W_802200A8 *)(TShopItemListWindow__ct((u8 *)o, (s32)tl_05, (s32)((S_802200A8 *)this), (s32)(((S_802200A8 *)this)->f24)));
    }
    o->cb0 = (void *)close__20TShopItemTecSequenceFPv;
    reset_controller_input_state();
    this->set_field_20(5);
}

void TShopItemTecSequence::update_buy_sell_choice() {
    s32 r;
    if (((Seq_80220110 *)this)->win == NULL) {
        u16 id = get_entity_id(((Seq_80220110 *)this)->x24);
        ((Seq_80220110 *)this)->win = (void *)create_window_menu((s32)((void *)((s32 (*)(int))get_window_layout_position)(0x2B)), (s32)((void *)2), id);
        forward_trade_action_default__16TObjCityMainWarpFPviii(((Seq_80220110 *)this)->win, get_shop_text(4), 6, 0);
        forward_trade_action_default__16TObjCityMainWarpFPviii(((Seq_80220110 *)this)->win, get_shop_text(6), 6, 1);
        ((TWindowSubComCard *)(((Seq_80220110 *)this)->win))->calc_window_size();
        align_menu_entry_positions(((Seq_80220110 *)this)->win);
        ((TCheckRoomSequence *)(((Seq_80220110 *)this)->win))->set_ready_flag();
        ((TUnk_804CDFE8 *)(((Seq_80220110 *)this)->win))->set_position_xy(get_scale__15TShopWindowBaseFv(((Seq_80220110 *)this)), get_scale__15TShopWindowBaseFv(((Seq_80220110 *)this)));
    }
    if (((Seq_80220110 *)this)->win != NULL && ((TWindowMenu *)(((Seq_80220110 *)this)->win))->is_visible() != 0) {
        r = get_selected_menu_value(((Seq_80220110 *)this)->win);
        if (r == 0) {
            ((Seq_80220110 *)this)->m4(0xB, 1);
            ((TShopWindowBase *)((Seq_80220110 *)this))->set_field_20(3);
            TWindow__close((u8 *)(((Seq_80220110 *)this)->win));
            ((Seq_80220110 *)this)->win = NULL;
            return;
        }
        if (r == 1) {
            ((TShopWindowBase *)((Seq_80220110 *)this))->set_field_20(4);
            TWindow__close((u8 *)(((Seq_80220110 *)this)->win));
            ((Seq_80220110 *)this)->win = NULL;
            return;
        }
    }
    if (((Seq_80220110 *)this)->win != NULL && ((TWindowSubComCard *)(((Seq_80220110 *)this)->win))->get_status_flag() != 0) {
        ((Seq_80220110 *)this)->m4(0x2C, 1);
        ((TShopWindowBase *)((Seq_80220110 *)this))->set_field_20(7);
        TWindow__close((u8 *)(((Seq_80220110 *)this)->win));
        ((Seq_80220110 *)this)->win = NULL;
    }
}

s32 TShopItemTecSequence::open_greeting() {
  Stack_802202BC stack;
  stack.sp8 = lbl_805DC700;
  stack.spC = lbl_805DC704;
  this->create_message_window(get_window_layout_position(0x2C, (f32) lbl_805DC700), (s32)&stack.sp8);
  (((VObj_18_a93f07 *)(this))->m4(0x2E, 1));
  this->m_2c = create_meseta_window((s32) ((((this->get_child_field1c() & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF));
  this->set_field_20(2);
  this->m_34 = set_service_counter_camera((void *) this, 5);
}

typedef char RecoveredGlobal_802203E4___vt__20TShopItemTecSequence_size[sizeof(RecoveredGlobal_802203E4___vt__20TShopItemTecSequence) == 0x38 ? 1 : -1];
typedef char RecoveredGlobal_802203E4_TShopItemTecSequence__data_80513EE0_size[sizeof(RecoveredGlobal_802203E4_TShopItemTecSequence__data_80513EE0) == 0x10 ? 1 : -1];

void TShopItemTecSequence::vfunc_11() {
    u8 *arg0 = (u8 *)this;
    switch (this->m_20) {
    case 0:
        restore_player_state__13TShopSequenceFv(arg0);
        ((TShopWindowBase *)arg0)->set_field_20(1);
        return;
    case 1:
        ((TShopItemTecSequence *)arg0)->open_greeting();
        return;
    case 2:
        ((TShopItemTecSequence *)arg0)->update_buy_sell_choice();
        return;
    case 3:
        ((TShopItemTecSequence *)arg0)->open_item_list_window();
        return;
    case 4:
        ((TShopItemTecSequence *)arg0)->open_sell_window();
        return;
    case 7:
        ((TShopItemTecSequence *)arg0)->close_if_done();
        return;
    case 6:
        ((TShopItemTecSequence *)arg0)->handle_select();
    default:
        return;
    }
}

u8 *__dt__20TShopItemTecSequenceFv(TShopItemTecSequence *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = &__vt__20TShopItemTecSequence.value;
        if ((u32) arg0->m_34 != 0U) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x34));
            arg0->m_34 = 0U;
        }
        if ((u32) arg0->m_2c != 0U) {
            TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x2C)));
            arg0->m_2c = 0U;
        }
        ((TShopSequence *)arg0)->close_message_window();
        if ((u32) *(u32 *)((s8 *)arg0 + 0x30) != 0U) {
            TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x30)));
            *(u32 *)((s8 *)arg0 + 0x30) = 0U;
        }
        lbl_805D6250 = 0;
        *(s32 *)((s8 *)&TShopItemTecSequence__slot_table.value + (sub_8022397C__15TShopWindowBaseFv(arg0) * 4)) = 0;
        __dt__13TShopSequenceFv((arg0), 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return (u8 *)arg0;
}

typedef char RecoveredGlobal_802204B0___vt__20TShopItemTecSequence_size[sizeof(RecoveredGlobal_802204B0___vt__20TShopItemTecSequence) == 0x38 ? 1 : -1];
typedef char RecoveredGlobal_802204B0_TShopItemTecSequence__data_80513EE0_size[sizeof(RecoveredGlobal_802204B0_TShopItemTecSequence__data_80513EE0) == 0x10 ? 1 : -1];
u8 *TShopItemTecSequence__ct(u8 *shop_item_tec_sequence, s32 arg1, s32 arg2) {
    TShopSequence__ct((shop_item_tec_sequence));
    *(s32 **)((s8 *)shop_item_tec_sequence + 0x18) = &(*(RecoveredGlobal_802204B0___vt__20TShopItemTecSequence *)&__vt__20TShopItemTecSequence).value;
    *(s32 *)((s8 *)shop_item_tec_sequence + 0) = (s32) TShopItemTecSequence__class_name;
    ((TShopItemTecSequence *)shop_item_tec_sequence)->m_20 = 0;
    *(s32 *)((s8 *)shop_item_tec_sequence + 0x24) = arg2;
    *(s32 *)((s8 *)shop_item_tec_sequence + 0x30) = 0;
    ((TShopItemTecSequence *)shop_item_tec_sequence)->m_2c = 0;
    ((TShopItemTecSequence *)shop_item_tec_sequence)->m_34 = 0;
    (*(u8 * *)&lbl_805D6250) = shop_item_tec_sequence;
    lbl_805D6248 = 0;
    lbl_805D624C = 0;
    *(s32 *)((s8 *)(&(*(RecoveredGlobal_802204B0_TShopItemTecSequence__data_80513EE0 *)&TShopItemTecSequence__slot_table).value) + (sub_8022397C__15TShopWindowBaseFv(shop_item_tec_sequence) * 4)) = 1;
    return shop_item_tec_sequence;
}

void TShopItemTecSequence__sub_80220538(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        ((s32 *)&TShopItemTecSequence__slot_table)[i] = 0;
    }
}

void TShopItemTecSequence__sub_80220560(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        ((s32 *)&TShopItemTecSequence__slot_table)[i] = 0;
    }
}

void set_judgment_target_flag(void *arg0, void *arg1) {
    u32 temp_r3;
    if ((TRaderMapCore::is_not_split_screen() == 1) && ((temp_r3 = (u32)find_item_by_id(*(s32 *)((s8 *)arg1 + 0xC))) != 0U) && ((s32) *(s32 *)((s8 *)arg0 + 0x168) != 0)) {
        ((TItem *)temp_r3)->add_item_flags(0x80);
    }
}

}
