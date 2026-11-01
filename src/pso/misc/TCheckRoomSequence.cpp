#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/TShopWindowBase.h"
struct TShopKeepItemWindow;

#include "pso/misc/TShopSequence.h"
#include "pso/misc/TWindowAddition.h"
#include "pso/misc/TWindowMenu.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/misc/TShopEquipmentSellWindow.h"
#include "pso/misc/TWindowMainMenu.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TWindowInputNumber.h"

#pragma readonly_strings on

extern "C" {
const char *lbl_805D3640 = "TCheckRoomSequence";
s32 lbl_805D6160;
s32 TCheckRoomSequence__error_return_text_id;
s32 TCheckRoomSequence__error_return_state;
s32 TCheckRoomSequence__active_instance;
}


#pragma optimization_level 1

struct Rec_80211034 { u8 b[0x18]; };
struct Obj_80211408 { u8 pad[0x14]; s16 a; s16 b; };

struct Obj_80211584 { u8 pad[0x14]; s16 a; s16 b; };

struct TWin_8020F070 { u8 pad[0x44]; };

struct TCheckRoomSequence_8020F070 { u8 pad[0x44]; TWin_8020F070 *win; };

struct Obj_8020F268 { u8 pad[0x28]; void (*cb0)(u8 *); void (*cb1)(u32); };

struct Seq_8020F268 { u8 pad[0x24]; s32 f24; };

struct Obj_8020F2D8 { u8 pad[0x60]; void (*cb0)(u8 *); void (*cb1)(u32); };

struct Seq_8020F2D8 { u8 pad[0x24]; s32 f24; };

struct VBase_18_a93f07 { char pad[0x18]; };

struct VObj_18_a93f07 : VBase_18_a93f07 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual s32 m4(s32, s32);
};

struct VBase_18_f96e2e { char pad[0x18]; };

struct VObj_18_f96e2e : VBase_18_f96e2e {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual s32 m4(s32, s32);
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8();
};

struct Rec_80210904 { u8 b[0x18]; };

struct VBase_18_8d1630 { char pad[0x18]; };

struct VObj_18_8d1630 : VBase_18_8d1630 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8();
};

struct VBase_8020F478 { char pad[0x18]; };

struct VObj_8020F478 : VBase_8020F478 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual s32 m4(s32, s32);
};

struct Seq_8020F478 : VObj_8020F478 {
    u8 pad1C[0x24 - 0x1C];
    s32 f24;
    u8 pad28[0x34 - 0x28];
    void *f34;
};

struct VBase_8020F730 { char pad[0x18]; };

struct VObj_8020F730 : VBase_8020F730 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual s32 m4(s32, s32);
};

struct Seq_8020F730 : VObj_8020F730 {
    u8 pad1C[0x24 - 0x1C];
    s32 f24;
    u8 pad28[0x34 - 0x28];
    void *f34;
};

struct Item_80210A04 { u8 b0, b1, b2, b3, b4; u8 pad5[0x14 - 5]; s16 f14; u8 pad16[2]; };

struct TWin_8020F070;

struct Win_8020F8C0 { u8 pad[0x394]; void *cb0; void *cb1; };

struct Vec2_80210198 { f32 x; f32 y; };

struct Seq_80210754 {
    s32 f0; u8 pad4[0x14]; void *vt; u8 pad1c[8]; s32 f24; s32 f28; s32 f2c; s32 f30;
    s32 f34, f38, f3c, f40, f44, f48;
};

struct VBase_802102D0 { char pad[0x18]; };
class TCheckRoomSequence : public VBase_802102D0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void vt9();
    virtual void vt10();
    virtual void vt11();
    u8 pad1c[0x20 - 0x1C];
    s32 state;
    void open_bank();
    void handle_root_choice();
    void handle_deposit_choice();
    void open_deposit_item_window();
    void accept_meseta_deposit(void *);
    void begin_meseta_deposit(void *);
    void begin_meseta_withdrawal(void *);
    void open_get_item_window(void *);
    void handle_withdraw_choice();
    void accept_meseta_withdrawal(void *);
    void sub_802100FC();
    void sub_802100F8();
    void handle_error_ack(void *);
    void sub_8020F1DC();
    void set_quest_list_mode_19(void *);
    void open_delete_item_window(void *);
};
typedef void (TCheckRoomSequence::*Fn_802102D0)();

struct Item_80210E28 { u8 b0, b1, b2, b3, b4; u8 pad5[0x14 - 5]; s16 f14; u8 pad16[2]; };

struct TCheckRoomSequence_8020F070;

struct Card_8021118C { u8 pad[0x248]; s32 count; s32 meseta; u8 items[1]; };

struct Rec_80210F78
{
  u8 b[0x14];
  s16 f14;
  s16 f16;
};

extern "C" {
u8 is_item_record_empty(u8 *arg0);
void init__9TItemDataFv(void *);
void init_item_entry__18TCheckRoomSequenceFPv(Obj_80211408 *self);
void close_window__18TCheckRoomSequenceFPv(TCheckRoomSequence_8020F070 *self);
int set_field_20__15TShopWindowBaseFl(void*, void*);
int reset_controller_input_state(void *);
void *__nw__7TObjectFUl(u32);
void *TShopDeleteItemWindow__ct(void *arg0, void *arg1, void *arg2, void *arg3);
void notify_quest_list_vm__18TCheckRoomSequenceFPv(u8 *arg0);
void init_check__18TCheckRoomSequenceFUi(u32 arg0);
extern void *tl_05;
void open_delete_item_window__18TCheckRoomSequenceFPv(Seq_8020F268 *self);
void *TShopGetItemWindow__ct(void *arg0, void *arg1, void *arg2, void *arg3);
void open_get_item_window__18TCheckRoomSequenceFPv(Seq_8020F2D8 *self);
extern s32 lbl_805D6160;
extern s32 TCheckRoomSequence__error_return_text_id;
extern s32 TCheckRoomSequence__error_return_state;
extern s32 TCheckRoomSequence__active_instance;
void reset_slot_state__18TCheckRoomSequenceFv(void);
void reset_slots__18TCheckRoomSequenceFv(void);
void finish_room_check__18TCheckRoomSequenceFPv(u8 *arg0);
s32 sub_802239EC__13TShopSequenceFv(void *);
s32 sub_80223A48__15TShopWindowBaseFv(void *);
void handle_error_ack__18TCheckRoomSequenceFPv(u8 *arg0);
s32 get_room_data__18TCheckRoomSequenceFi(int);
int sub_8022397C__15TShopWindowBaseFv(void*);
void accept_meseta_withdrawal__18TCheckRoomSequenceFPv(u8 *arg0);
s32 try_spend_actor_meseta(u8 *arg0, s32 arg1);
void accept_meseta_deposit__18TCheckRoomSequenceFPv(u8 *arg0);
void copy_item_to_bank_entry__18TCheckRoomSequenceFPvPv(u8 *arg0, u8 *arg1);
void compact_items__18TCheckRoomSequenceFi(s32 slot);
void queue_destruction__7TObjectFv(void *arg0);
s8 get_chr_select_state__23TAdSinglePlyChrSelectGCFv();
s32 TAdPlayerLoadGC__sub_801E1B50(int);
s32 close_if_single_screen__13TShopSequenceFv(void *);
s32 close_window__13TShopSequenceFv(void *);
void TCheckRoomSequence__vt11(u8 *arg0);
int obj_getPtr2B0_20(u8 *p);
void set_position__18TCheckRoomSequenceFff(void* p, f32 a, f32 b);
s16 get_child_field1c__13TShopSequenceFv(void *);
void *__ct__18TWindowInputNumberFPvllls(void *, s32, s32, s32, s32, s16);
s32 get_window_layout_position(s32);
void begin_meseta_withdrawal__18TCheckRoomSequenceFPv(Seq_8020F478 *self);
void begin_meseta_deposit__18TCheckRoomSequenceFPv(Seq_8020F730 *self);
s32 get_max_stack_size__9TItemDataFv(void *);
s32 get_item_def__18TCheckRoomSequenceFUl(void *);
s32 get_bank_deposit_capacity_for_item(Item_80210A04 *item, s32 slot);
s32 TCheckRoomSequence__sub_80210B34(u8 *, s32, s32);
s32 store_item_in_bank(u8 *item, s32 arg1, s32 slot);
s32 get_entity_id(int);
s32 set_ready_flag__18TCheckRoomSequenceFv(int);
s32 check_room_ready__18TCheckRoomSequenceFv(void);
s32 get_shop_text(int);
f32 get_scale__15TShopWindowBaseFv(void *);
s32 align_menu_entry_positions(int);
s32 forward_trade_action_default__16TObjCityMainWarpFPviii(int, int, int, int);
u32 create_window_menu(s32, int, u16);
void handle_root_choice__18TCheckRoomSequenceFv(u8 *arg0);
s32 get_room_table_entry__18TCheckRoomSequenceFi(s32);
void *TShopKeepItemWindow__ct(TShopKeepItemWindow *arg0, void *arg1, void *arg2, void *arg3);
void init_check_params__18TCheckRoomSequenceFUi(u32 arg0);
void open_deposit_item_window__18TCheckRoomSequenceFv(u8 *arg0);
void handle_withdraw_choice__18TCheckRoomSequenceFv(u8 *arg0);
void handle_deposit_choice__18TCheckRoomSequenceFv(u8 *arg0);
s32 set_service_counter_camera(void *, int);
void *TWindowDeposit__ct(void *, s32);
s32 create_meseta_window(u16);
void open_bank__18TCheckRoomSequenceFv(u8 *arg0);
u8 *TShopSequence__ct(u8 *arg0);
extern u8 __vt__18TCheckRoomSequence[];
extern const char *lbl_805D3640;
void *TCheckRoomSequence__ct(void *arg0, s32 arg1, s32 arg2_);
void remove_bank_item_amount__18TCheckRoomSequenceFiii(s32 idx, s32 amount, s32 slot);
void *__dt__13TShopSequenceFv(void *arg0, s16 arg1);
s32 __dl__7TObjectFPv(void *);
u8 *__dt__18TCheckRoomSequenceFv(u8 *arg0, s16 arg1);
s32 get_character_save_record(u32 arg0);
void copy_bank_to_card_window(s32 slot);
extern u32 bank_item_records_by_slot[4];
void copy_data__18TCheckRoomSequenceFPvPv(void* p, void* a1);
s32 copy_bank_item_with_stack_limit(s32 idx, void *data, s32 *out, s32 slot);
void* TAdSinglePlyChrSelectGC__sub_802115C0(void* p);
void TCheckRoomSequence__vt10(void* p);
int set_quest_list_mode_19__18TCheckRoomSequenceFPv(void* p);
}
u8 bank_has_free_row(s32 i);
s32 get_bank_meseta_capacity(s32 i);
s32 bank_credit_meseta(s32 v, s32 i);
s32 bank_debit_meseta(s32 v, s32 i);
void copy_bank_from_card_window(s32 slot);
extern "C" {
s32 get_game_play_mode();
int restore_player_state__13TShopSequenceFv(void*);

u32 bank_item_records_by_slot[4];
u32 lbl_80513D98[4];
u32 lbl_80513DA8[4];
u32 TCheckRoomSequence__slot_active_flags[4];
#define bank_item_records_by_slot (*(Rec_80211034 *(*)[4])bank_item_records_by_slot)
#define lbl_80513D98 (*(s32 (*)[4])lbl_80513D98)
#define lbl_80513DA8 (*(s32 (*)[4])lbl_80513DA8)
#define TCheckRoomSequence__slot_active_flags (*(s32 (*)[4])TCheckRoomSequence__slot_active_flags)

s32 check_room_ready__18TCheckRoomSequenceFv(void) {
    if (TRaderMapCore::is_not_split_screen() == 0) {
        return 1;
    }
    return (u32)__cntlzw(get_game_play_mode()) >> 5;
}

#pragma push
#pragma optimization_level 1
void close_window__18TCheckRoomSequenceFPv(TCheckRoomSequence_8020F070 *self) {
    if (self->win) {
        ((TWindowBase *)self->win)->close();
        self->win = 0;
    }
}
#pragma pop

void init_check_params__18TCheckRoomSequenceFUi(u32 arg0) {
    TCheckRoomSequence__error_return_text_id = 0x46;
    TCheckRoomSequence__error_return_state = 2;
    if (arg0 != 0U) {
        set_field_20__15TShopWindowBaseFl((void*)arg0, (void*)(0x10));
    }
}

#pragma push
#pragma optimization_level 1
void finish_room_check__18TCheckRoomSequenceFPv(u8 *arg0) {
    if (arg0 != NULL) {
        ((VObj_18_a93f07 *)(arg0))->m4(0x46, 1);
    }
    if (arg0 != NULL) {
        set_field_20__15TShopWindowBaseFl(arg0, (void*)(2));
    }
}
#pragma pop

void init_check__18TCheckRoomSequenceFUi(u32 arg0) {
    if (arg0 != 0U) {
        TCheckRoomSequence__error_return_text_id = 0x46;
        TCheckRoomSequence__error_return_state = 2;
        set_field_20__15TShopWindowBaseFl((void*)arg0, (void*)(0x10));
    }
}

void notify_quest_list_vm__18TCheckRoomSequenceFPv(u8 *arg0) {
    if (arg0 != NULL) {
        ((VObj_18_a93f07 *)(arg0))->m4(0x1A, 1);
        set_field_20__15TShopWindowBaseFl(arg0, (void *) (2));
    }
}

}
void TCheckRoomSequence::sub_8020F1DC() {  }
extern "C" {

#pragma push
#pragma optimization_level 1
void handle_error_ack__18TCheckRoomSequenceFPv(u8 *arg0) {
    if ((((TShopWindowBase *)(arg0))->vfunc_10() != 0) && ((sub_80223A48__15TShopWindowBaseFv(arg0) != 0) || (sub_802239EC__13TShopSequenceFv(arg0) != 0))) {
        ((VObj_18_f96e2e *)(arg0))->m4(TCheckRoomSequence__error_return_text_id, 1);
        set_field_20__15TShopWindowBaseFl((void*)arg0, (void*)TCheckRoomSequence__error_return_state);
    }
}
#pragma pop

#pragma push
#pragma optimization_level 1
void open_delete_item_window__18TCheckRoomSequenceFPv(Seq_8020F268 *self) {
    void *o = __nw__7TObjectFUl(0x68);
    if (o != 0) {
        o = TShopDeleteItemWindow__ct((void *)o, (void *)tl_05, (void *)self, (void *)self->f24);
    }
    ((Obj_8020F268 *)o)->cb0 = notify_quest_list_vm__18TCheckRoomSequenceFPv;
    ((Obj_8020F268 *)o)->cb1 = init_check__18TCheckRoomSequenceFUi;
    reset_controller_input_state(o);
    set_field_20__15TShopWindowBaseFl(self, (void*)0x11);
}
#pragma pop

#pragma push
#pragma optimization_level 1
void open_get_item_window__18TCheckRoomSequenceFPv(Seq_8020F2D8 *self) {
    void *o = __nw__7TObjectFUl(0x68);
    if (o != 0) {
        o = TShopGetItemWindow__ct((void *)o, (void *)tl_05, (void *)self, (void *)self->f24);
    }
    ((Obj_8020F2D8 *)o)->cb0 = notify_quest_list_vm__18TCheckRoomSequenceFPv;
    ((Obj_8020F2D8 *)o)->cb1 = init_check__18TCheckRoomSequenceFUi;
    reset_controller_input_state(o);
    set_field_20__15TShopWindowBaseFl(self, (void*)0x11);
}
#pragma pop

#pragma push
#pragma optimization_level 1
void accept_meseta_withdrawal__18TCheckRoomSequenceFPv(u8 *arg0) {
    s32 temp_r31;
    s32 temp_r3;
    if (((u32) *(u32 *)((s8 *)arg0 + 0x34) != 0U) && (((s32)((TWindowInputNumber *)(*(u32 *)((s8 *)arg0 + 0x34)))->is_confirmed()) != 0)) {
        temp_r31 = ((TShopEquipmentSellWindow *)(*(u32 *)((s8 *)arg0 + 0x34)))->get_result();
        temp_r3 = ((s32)sub_8022397C__15TShopWindowBaseFv(arg0));
        bank_debit_meseta(temp_r31, temp_r3);
        ((TObjPlayer *)(*(s32 *)((s8 *)arg0 + 0x24)))->add_meseta(temp_r31);
        copy_bank_to_card_window(temp_r3);
        if ((u32) *(u32 *)((s8 *)arg0 + 0x40) != 0U) {
            TWindowMainMenu::set_entry_field_20((int) (*(u32 *)((s8 *)arg0 + 0x40)), (int) (get_room_data__18TCheckRoomSequenceFi(temp_r3)));
        }
        ((VObj_18_a93f07 *)(arg0))->m4(0x46, 1);
        set_field_20__15TShopWindowBaseFl(arg0, (void*)(2));
        ((TWindowBase *)((int) (*(u32 *)((s8 *)arg0 + 0x34))))->close();
        *(u32 *)((s8 *)arg0 + 0x34) = 0U;
    }
    if (((u32) *(u32 *)((s8 *)arg0 + 0x34) != 0U) && (((s32)((TShopEquipmentSellWindow *)(*(u32 *)((s8 *)arg0 + 0x34)))->is_confirmed()) != 0)) {
        ((VObj_18_a93f07 *)(arg0))->m4(0x46, 1);
        set_field_20__15TShopWindowBaseFl(arg0, (void*)(0xA));
        ((TWindowBase *)((int) (*(u32 *)((s8 *)arg0 + 0x34))))->close();
        *(u32 *)((s8 *)arg0 + 0x34) = 0U;
    }
}
#pragma pop

#pragma push
#pragma optimization_level 1
void begin_meseta_withdrawal__18TCheckRoomSequenceFPv(Seq_8020F478 *self) {
    s16 id;
    void *w;
    s32 count;
    s32 n;
    count = get_room_data__18TCheckRoomSequenceFi(sub_8022397C__15TShopWindowBaseFv(self));
    if (count > 0) {
        n = 999999 - obj_getPtr2B0_20((u8 *)self->f24);
        n = (n < count) ? n : count;
        if (n > 0) {
            if (self->f34 == NULL) {
                w = __nw__7TObjectFUl(0x7C);
                if (w != NULL) {
                    id = ((s32 (*)(void *))get_child_field1c__13TShopSequenceFv)(self);
                    w = __ct__18TWindowInputNumberFPvllls(w, get_window_layout_position(0x2B), 1, n, 1, id);
                }
                self->f34 = w;
                if (self->f34 != NULL && TLobby::is_camera_ctrl_active() > 2) {
                    set_position__18TCheckRoomSequenceFff(self->f34, 0.75f, 0.75f);
                }
            }
            ((void (*)())reset_controller_input_state)();
            self->m4(0x3F, 1);
            set_field_20__15TShopWindowBaseFl(self, (void *)0xC);
            return;
        }
        self->m4(0x4A, 1);
        TCheckRoomSequence__error_return_text_id = 0x46;
        TCheckRoomSequence__error_return_state = 2;
        set_field_20__15TShopWindowBaseFl(self, (void *)0x10);
        return;
    }
    self->m4(0x3D, 1);
    TCheckRoomSequence__error_return_text_id = 0x46;
    TCheckRoomSequence__error_return_state = 2;
    set_field_20__15TShopWindowBaseFl(self, (void *)0x10);
}
#pragma pop

#pragma push
#pragma optimization_level 1
void accept_meseta_deposit__18TCheckRoomSequenceFPv(u8 *arg0) {
    s32 temp_r31;
    s32 temp_r3;
    if (((u32) *(u32 *)((s8 *)arg0 + 0x34) != 0U) && (((s32)((TWindowInputNumber *)(*(u32 *)((s8 *)arg0 + 0x34)))->is_confirmed()) != 0)) {
        temp_r31 = ((TShopEquipmentSellWindow *)(*(u32 *)((s8 *)arg0 + 0x34)))->get_result();
        temp_r3 = ((s32)sub_8022397C__15TShopWindowBaseFv(arg0));
        bank_credit_meseta(temp_r31, temp_r3);
        try_spend_actor_meseta((u8 *)(*(s32 *)((s8 *)arg0 + 0x24)), (temp_r31));
        copy_bank_to_card_window(temp_r3);
        if ((u32) *(u32 *)((s8 *)arg0 + 0x40) != 0U) {
            TWindowMainMenu::set_entry_field_20((int) (*(u32 *)((s8 *)arg0 + 0x40)), (int) (get_room_data__18TCheckRoomSequenceFi(temp_r3)));
        }
        ((VObj_18_a93f07 *)(arg0))->m4(0x46, 1);
        set_field_20__15TShopWindowBaseFl(arg0, (void*)(2));
        ((TWindowBase *)((int) (*(u32 *)((s8 *)arg0 + 0x34))))->close();
        *(u32 *)((s8 *)arg0 + 0x34) = 0U;
    }
    if (((u32) *(u32 *)((s8 *)arg0 + 0x34) != 0U) && (((s32)((TShopEquipmentSellWindow *)(*(u32 *)((s8 *)arg0 + 0x34)))->is_confirmed()) != 0)) {
        ((VObj_18_a93f07 *)(arg0))->m4(0x46, 1);
        set_field_20__15TShopWindowBaseFl(arg0, (void*)(3));
        ((TWindowBase *)((int) (*(u32 *)((s8 *)arg0 + 0x34))))->close();
        *(u32 *)((s8 *)arg0 + 0x34) = 0U;
    }
}
#pragma pop

#pragma push
#pragma optimization_level 1
void begin_meseta_deposit__18TCheckRoomSequenceFPv(Seq_8020F730 *self) {
    s16 id;
    s32 meseta;
    void *w;
    s32 slot;
    s32 n;
    slot = sub_8022397C__15TShopWindowBaseFv(self);
    if (get_bank_meseta_capacity(slot) > 0) {
        meseta = obj_getPtr2B0_20((u8 *)self->f24);
        if (meseta > 0) {
            n = get_bank_meseta_capacity(slot);
            n = (n < meseta) ? n : meseta;
            if (self->f34 == NULL) {
                w = __nw__7TObjectFUl(0x7C);
                if (w != NULL) {
                    id = ((s32 (*)(void *))get_child_field1c__13TShopSequenceFv)(self);
                    w = __ct__18TWindowInputNumberFPvllls(w, get_window_layout_position(0x2B), 1, n, 1, id);
                }
                self->f34 = w;
                if (self->f34 != NULL && TLobby::is_camera_ctrl_active() > 2) {
                    set_position__18TCheckRoomSequenceFff(self->f34, 0.75f, 0.75f);
                }
            }
            ((void (*)())reset_controller_input_state)();
            self->m4(0x34, 1);
            set_field_20__15TShopWindowBaseFl(self, (void *)5);
            return;
        }
        self->m4(0x47, 1);
        TCheckRoomSequence__error_return_text_id = 0x46;
        TCheckRoomSequence__error_return_state = 2;
        set_field_20__15TShopWindowBaseFl(self, (void *)0x10);
        return;
    }
    self->m4(0x37, 1);
    TCheckRoomSequence__error_return_text_id = 0x46;
    TCheckRoomSequence__error_return_state = 2;
    set_field_20__15TShopWindowBaseFl(self, (void *)0x10);
}
#pragma pop

#pragma push
#pragma optimization_level 1
void open_deposit_item_window__18TCheckRoomSequenceFv(u8 *arg0) {
    void *mem;
    Win_8020F8C0 *w;
    if (get_room_table_entry__18TCheckRoomSequenceFi(sub_8022397C__15TShopWindowBaseFv(arg0)) > 0xC8) {
        ((VObj_18_a93f07 *)(arg0))->m4(0x3C, 1);
        TCheckRoomSequence__error_return_text_id = 0x46;
        TCheckRoomSequence__error_return_state = 2;
        set_field_20__15TShopWindowBaseFl(arg0, (void *) (0x10));
        return;
    }
    ((VObj_18_a93f07 *)(arg0))->m4(0x38, 1);
    mem = __nw__7TObjectFUl(0x39C);
    w = (Win_8020F8C0 *)mem;
    if (mem != NULL) {
        w = (Win_8020F8C0 *)TShopKeepItemWindow__ct((TShopKeepItemWindow *)((void *)mem), (void *)tl_05, (void *)arg0, (void *)(*(s32 *)((s8 *)arg0 + 0x24)));
    }
    w->cb0 = (void *)finish_room_check__18TCheckRoomSequenceFPv;
    w->cb1 = (void *)init_check_params__18TCheckRoomSequenceFUi;
    reset_controller_input_state(w);
    set_field_20__15TShopWindowBaseFl(arg0, (void *) (0x11));
}
#pragma pop

int set_quest_list_mode_19__18TCheckRoomSequenceFPv(void* p) { return set_field_20__15TShopWindowBaseFl(p, (void*)(19)); }

#pragma push
#pragma optimization_level 1
void handle_withdraw_choice__18TCheckRoomSequenceFv(u8 *arg0) {
    s32 selected_menu_value;
    switch (*(s32 *)((s8 *)arg0 + 0x2C)) {
    case 0:
        if ((u32) *(u32 *)((s8 *)arg0 + 0x3C) == 0U) {
            *(u32 *)((s8 *)arg0 + 0x3C) = create_window_menu(((s32)get_window_layout_position(0x2B)), 2, get_entity_id((int) (*(s32 *)((s8 *)arg0 + 0x24))));
            forward_trade_action_default__16TObjCityMainWarpFPviii((int) (*(u32 *)((s8 *)arg0 + 0x3C)), (int) (get_shop_text(2)), 6, 0);
            forward_trade_action_default__16TObjCityMainWarpFPviii((int) (*(u32 *)((s8 *)arg0 + 0x3C)), (int) (get_shop_text(3)), 6, 1);
            ((TWindowSubComCard *)(*(u32 *)((s8 *)arg0 + 0x3C)))->calc_window_size();
            align_menu_entry_positions((int) (*(u32 *)((s8 *)arg0 + 0x3C)));
            set_ready_flag__18TCheckRoomSequenceFv((int) (*(u32 *)((s8 *)arg0 + 0x3C)));
            ((TWindowAddition *)(*(u32 *)((s8 *)arg0 + 0x3C)))->set_position_xy(get_scale__15TShopWindowBaseFv(arg0), get_scale__15TShopWindowBaseFv(arg0));
        }
        ((VObj_18_a93f07 *)(arg0))->m4(0x32, 1);
        *(s32 *)((s8 *)arg0 + 0x2C) = 1;
        return;
    case 1:
        if (((u32) *(u32 *)((s8 *)arg0 + 0x3C) != 0U) && (((TWindowMenu *)(*(u32 *)((s8 *)arg0 + 0x3C)))->is_decided() != 0)) {
            selected_menu_value = ((TWindowMenu *)(*(u32 *)((s8 *)arg0 + 0x3C)))->get_selected_value();
            if (selected_menu_value == 0) {
                set_field_20__15TShopWindowBaseFl(arg0, (void *) (7));
                ((TWindowBase *)(*(u32 *)((s8 *)arg0 + 0x3C)))->close();
                *(u32 *)((s8 *)arg0 + 0x3C) = 0U;
            }
            if (selected_menu_value == 1) {
                set_field_20__15TShopWindowBaseFl(arg0, (void *) (9));
                ((TWindowBase *)(*(u32 *)((s8 *)arg0 + 0x3C)))->close();
                *(u32 *)((s8 *)arg0 + 0x3C) = 0U;
            }
            *(s32 *)((s8 *)arg0 + 0x2C) = 0;
        }
        if (((u32) *(u32 *)((s8 *)arg0 + 0x3C) != 0U) && (((TWindowMenu *)(*(u32 *)((s8 *)arg0 + 0x3C)))->is_cancelled() != 0)) {
            ((VObj_18_a93f07 *)(arg0))->m4(0x46, 1);
            set_field_20__15TShopWindowBaseFl(arg0, (void *) (2));
            ((TWindowBase *)(*(u32 *)((s8 *)arg0 + 0x3C)))->close();
            *(u32 *)((s8 *)arg0 + 0x3C) = 0U;
            *(s32 *)((s8 *)arg0 + 0x2C) = 0;
        }
        return;
    }
}
#pragma pop

#pragma push
#pragma optimization_level 1
void handle_deposit_choice__18TCheckRoomSequenceFv(u8 *arg0) {
    s32 selected_menu_value;
    switch (*(s32 *)((s8 *)arg0 + 0x2C)) {
    case 0:
        if ((u32) *(u32 *)((s8 *)arg0 + 0x3C) == 0U) {
            *(u32 *)((s8 *)arg0 + 0x3C) = create_window_menu(((s32)get_window_layout_position(0x2B)), 2, get_entity_id((int) (*(s32 *)((s8 *)arg0 + 0x24))));
            forward_trade_action_default__16TObjCityMainWarpFPviii((int) (*(u32 *)((s8 *)arg0 + 0x3C)), (int) (get_shop_text(2)), 6, 0);
            forward_trade_action_default__16TObjCityMainWarpFPviii((int) (*(u32 *)((s8 *)arg0 + 0x3C)), (int) (get_shop_text(3)), 6, 1);
            ((TWindowSubComCard *)(*(u32 *)((s8 *)arg0 + 0x3C)))->calc_window_size();
            align_menu_entry_positions((int) (*(u32 *)((s8 *)arg0 + 0x3C)));
            set_ready_flag__18TCheckRoomSequenceFv((int) (*(u32 *)((s8 *)arg0 + 0x3C)));
            ((TWindowAddition *)(*(u32 *)((s8 *)arg0 + 0x3C)))->set_position_xy(get_scale__15TShopWindowBaseFv(arg0), get_scale__15TShopWindowBaseFv(arg0));
        }
        ((VObj_18_a93f07 *)(arg0))->m4(0x33, 1);
        *(s32 *)((s8 *)arg0 + 0x2C) = 1;
        return;
    case 1:
        if (((u32) *(u32 *)((s8 *)arg0 + 0x3C) != 0U) && (((TWindowMenu *)(*(u32 *)((s8 *)arg0 + 0x3C)))->is_decided() != 0)) {
            selected_menu_value = ((TWindowMenu *)(*(u32 *)((s8 *)arg0 + 0x3C)))->get_selected_value();
            if (selected_menu_value == 0) {
                set_field_20__15TShopWindowBaseFl(arg0, (void *) (6));
                ((TWindowBase *)(*(u32 *)((s8 *)arg0 + 0x3C)))->close();
                *(u32 *)((s8 *)arg0 + 0x3C) = 0U;
            }
            if (selected_menu_value == 1) {
                set_field_20__15TShopWindowBaseFl(arg0, (void *) (4));
                ((TWindowBase *)(*(u32 *)((s8 *)arg0 + 0x3C)))->close();
                *(u32 *)((s8 *)arg0 + 0x3C) = 0U;
            }
            *(s32 *)((s8 *)arg0 + 0x2C) = 0;
        }
        if (((u32) *(u32 *)((s8 *)arg0 + 0x3C) != 0U) && (((TWindowMenu *)(*(u32 *)((s8 *)arg0 + 0x3C)))->is_cancelled() != 0)) {
            ((VObj_18_a93f07 *)(arg0))->m4(0x46, 1);
            set_field_20__15TShopWindowBaseFl(arg0, (void *) (2));
            ((TWindowBase *)(*(u32 *)((s8 *)arg0 + 0x3C)))->close();
            *(u32 *)((s8 *)arg0 + 0x3C) = 0U;
            *(s32 *)((s8 *)arg0 + 0x2C) = 0;
        }
        return;
    }
}
#pragma pop

#pragma push
#pragma optimization_level 1
void handle_root_choice__18TCheckRoomSequenceFv(u8 *arg0) {
    f32 temp_f31;
    f32 temp_f31_2;
    s32 selected_menu_value;
    s32 temp_r3_2;
    if (check_room_ready__18TCheckRoomSequenceFv() != 0) {
        switch (*(s32 *)((s8 *)arg0 + 0x2C)) {
        case 0:
            if ((u32) *(u32 *)((s8 *)arg0 + 0x3C) == 0U) {
                *(u32 *)((s8 *)arg0 + 0x3C) = create_window_menu(((s32)get_window_layout_position(0x2B)), 2, get_entity_id((int) (*(s32 *)((s8 *)arg0 + 0x24))));
                forward_trade_action_default__16TObjCityMainWarpFPviii((int) (*(u32 *)((s8 *)arg0 + 0x3C)), (int) (get_shop_text(8)), 6, 0);
                forward_trade_action_default__16TObjCityMainWarpFPviii((int) (*(u32 *)((s8 *)arg0 + 0x3C)), (int) (get_shop_text(9)), 6, 1);
                ((TWindowSubComCard *)(*(u32 *)((s8 *)arg0 + 0x3C)))->calc_window_size();
                align_menu_entry_positions((int) (*(u32 *)((s8 *)arg0 + 0x3C)));
                set_ready_flag__18TCheckRoomSequenceFv((int) (*(u32 *)((s8 *)arg0 + 0x3C)));
                ((TWindowAddition *)(*(u32 *)((s8 *)arg0 + 0x3C)))->set_position_xy(get_scale__15TShopWindowBaseFv(arg0), get_scale__15TShopWindowBaseFv(arg0));
            }
            *(s32 *)((s8 *)arg0 + 0x2C) = 1;
            return;
        case 1:
            if (((u32) *(u32 *)((s8 *)arg0 + 0x3C) != 0U) && (((TWindowMenu *)(*(u32 *)((s8 *)arg0 + 0x3C)))->is_decided() != 0)) {
                selected_menu_value = ((TWindowMenu *)(*(u32 *)((s8 *)arg0 + 0x3C)))->get_selected_value();
                if (selected_menu_value == 0) {
                    set_field_20__15TShopWindowBaseFl(arg0, (void *) (3));
                    ((TWindowBase *)(*(u32 *)((s8 *)arg0 + 0x3C)))->close();
                    *(u32 *)((s8 *)arg0 + 0x3C) = 0U;
                }
                if (selected_menu_value == 1) {
                    set_field_20__15TShopWindowBaseFl(arg0, (void *) (0xA));
                    ((TWindowBase *)(*(u32 *)((s8 *)arg0 + 0x3C)))->close();
                    *(u32 *)((s8 *)arg0 + 0x3C) = 0U;
                }
                *(s32 *)((s8 *)arg0 + 0x2C) = 0;
            }
            if (((u32) *(u32 *)((s8 *)arg0 + 0x3C) != 0U) && (((TWindowMenu *)(*(u32 *)((s8 *)arg0 + 0x3C)))->is_cancelled() != 0)) {
                ((VObj_18_a93f07 *)(arg0))->m4(0x48, 1);
                set_field_20__15TShopWindowBaseFl(arg0, (void *) (0xD));
                ((TWindowBase *)(*(u32 *)((s8 *)arg0 + 0x3C)))->close();
                *(u32 *)((s8 *)arg0 + 0x3C) = 0U;
                *(s32 *)((s8 *)arg0 + 0x2C) = 0;
                return;
            }
            break;
        }
    } else {
        switch (*(s32 *)((s8 *)arg0 + 0x2C)) {
        case 0:
            if ((u32) *(u32 *)((s8 *)arg0 + 0x3C) == 0U) {
                *(u32 *)((s8 *)arg0 + 0x3C) = create_window_menu(((s32)get_window_layout_position(0x2B)), 2, get_entity_id((int) (*(s32 *)((s8 *)arg0 + 0x24))));
                forward_trade_action_default__16TObjCityMainWarpFPviii((int) (*(u32 *)((s8 *)arg0 + 0x3C)), (int) (get_shop_text(0xA)), 6, 1);
                ((TWindowSubComCard *)(*(u32 *)((s8 *)arg0 + 0x3C)))->calc_window_size();
                align_menu_entry_positions((int) (*(u32 *)((s8 *)arg0 + 0x3C)));
                set_ready_flag__18TCheckRoomSequenceFv((int) (*(u32 *)((s8 *)arg0 + 0x3C)));
                ((TWindowAddition *)(*(u32 *)((s8 *)arg0 + 0x3C)))->set_position_xy(get_scale__15TShopWindowBaseFv(arg0), get_scale__15TShopWindowBaseFv(arg0));
            }
            *(s32 *)((s8 *)arg0 + 0x2C) = 1;
            return;
        case 1:
            if (((u32) *(u32 *)((s8 *)arg0 + 0x3C) != 0U) && (((TWindowMenu *)(*(u32 *)((s8 *)arg0 + 0x3C)))->is_decided() != 0)) {
                temp_r3_2 = ((TWindowMenu *)(*(u32 *)((s8 *)arg0 + 0x3C)))->get_selected_value();
                if (temp_r3_2 == 0) {
                    set_field_20__15TShopWindowBaseFl(arg0, (void *) (0xA));
                    ((TWindowBase *)(*(u32 *)((s8 *)arg0 + 0x3C)))->close();
                    *(u32 *)((s8 *)arg0 + 0x3C) = 0U;
                }
                if (temp_r3_2 == 1) {
                    set_field_20__15TShopWindowBaseFl(arg0, (void *) (0x12));
                    ((TWindowBase *)(*(u32 *)((s8 *)arg0 + 0x3C)))->close();
                    *(u32 *)((s8 *)arg0 + 0x3C) = 0U;
                }
                *(s32 *)((s8 *)arg0 + 0x2C) = 0;
            }
            if (((u32) *(u32 *)((s8 *)arg0 + 0x3C) != 0U) && (((TWindowMenu *)(*(u32 *)((s8 *)arg0 + 0x3C)))->is_cancelled() != 0)) {
                ((VObj_18_a93f07 *)(arg0))->m4(0x48, 1);
                set_field_20__15TShopWindowBaseFl(arg0, (void *) (0xD));
                ((TWindowBase *)(*(u32 *)((s8 *)arg0 + 0x3C)))->close();
                *(u32 *)((s8 *)arg0 + 0x3C) = 0U;
                *(s32 *)((s8 *)arg0 + 0x2C) = 0;
            }
            return;
        }
    }
}
#pragma pop

}
void TCheckRoomSequence::sub_802100F8() {  }
void TCheckRoomSequence::sub_802100FC() {  }
extern "C" {

#pragma push
#pragma optimization_level 1
void TCheckRoomSequence__vt11(u8 *arg0) {
    if ((((VObj_18_8d1630 *)(arg0))->m8() != 0) && ((sub_80223A48__15TShopWindowBaseFv(arg0) != 0) || (sub_802239EC__13TShopSequenceFv(arg0) != 0)) && (TAdPlayerLoadGC__sub_801E1B50((int) (get_chr_select_state__23TAdSinglePlyChrSelectGCFv())) == 0)) {
        copy_bank_to_card_window((s32)(sub_8022397C__15TShopWindowBaseFv(arg0)));
        close_if_single_screen__13TShopSequenceFv(arg0);
        close_window__13TShopSequenceFv(arg0);
        queue_destruction__7TObjectFv((arg0));
    }
}
#pragma pop

#pragma push
#pragma optimization_level 1
void open_bank__18TCheckRoomSequenceFv(u8 *arg0) {
    void *w;
    Vec2_80210198 v;
    v.x = 332.0f;
    v.y = 80.0f;
    ((TShopSequence *)arg0)->create_message_window((s32)(get_window_layout_position(0x2C)), (s32)&v);
    ((VObj_18_a93f07 *)(arg0))->m4(0x31, 1);
    *(s32 *)((s8 *)arg0 + 0x38) = create_meseta_window(get_child_field1c__13TShopSequenceFv(arg0));
    w = __nw__7TObjectFUl(0x6C);
    if (w != NULL) {
        w = TWindowDeposit__ct(w, get_child_field1c__13TShopSequenceFv(arg0));
    }
    *(void **)((s8 *)arg0 + 0x40) = w;
    TWindowMainMenu::set_entry_field_20(*(s32 *)((s8 *)arg0 + 0x40), get_room_data__18TCheckRoomSequenceFi(sub_8022397C__15TShopWindowBaseFv(arg0)));
    *(s32 *)((s8 *)arg0 + 0x2C) = 0;
    *(s32 *)((s8 *)arg0 + 0x48) = set_service_counter_camera(arg0, 6);
    set_field_20__15TShopWindowBaseFl(arg0, (void *)2);
}
#pragma pop

void TCheckRoomSequence__vt10(void* p) { restore_player_state__13TShopSequenceFv(p); sub_8022397C__15TShopWindowBaseFv(p); ((int (*)(void))copy_bank_from_card_window)(); set_field_20__15TShopWindowBaseFl(p, (void*)((void*)1)); }

void TCheckRoomSequence__vt9(TCheckRoomSequence *self) {
    static Fn_802102D0 fns[20] = {
        (Fn_802102D0)&TCheckRoomSequence::vt10,
        (Fn_802102D0)&TCheckRoomSequence::open_bank,
        (Fn_802102D0)&TCheckRoomSequence::handle_root_choice,
        (Fn_802102D0)&TCheckRoomSequence::handle_deposit_choice,
        (Fn_802102D0)&TCheckRoomSequence::open_deposit_item_window,
        (Fn_802102D0)&TCheckRoomSequence::accept_meseta_deposit,
        (Fn_802102D0)&TCheckRoomSequence::begin_meseta_deposit,
        (Fn_802102D0)&TCheckRoomSequence::begin_meseta_withdrawal,
        0,
        (Fn_802102D0)&TCheckRoomSequence::open_get_item_window,
        (Fn_802102D0)&TCheckRoomSequence::handle_withdraw_choice,
        (Fn_802102D0)&TCheckRoomSequence::vt11,
        (Fn_802102D0)&TCheckRoomSequence::accept_meseta_withdrawal,
        (Fn_802102D0)&TCheckRoomSequence::vt11,
        (Fn_802102D0)&TCheckRoomSequence::sub_802100FC,
        (Fn_802102D0)&TCheckRoomSequence::sub_802100F8,
        (Fn_802102D0)&TCheckRoomSequence::handle_error_ack,
        (Fn_802102D0)&TCheckRoomSequence::sub_8020F1DC,
        (Fn_802102D0)&TCheckRoomSequence::set_quest_list_mode_19,
        (Fn_802102D0)&TCheckRoomSequence::open_delete_item_window,
    };
    if (fns[self->state]) {
        (self->*fns[self->state])();
    }
}

#define self ((Seq_80210754 *)arg0)

#pragma push
#pragma optimization_level 1
u8 *__dt__18TCheckRoomSequenceFv(u8 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = ((s32 *)&__vt__18TCheckRoomSequence);
        if (*(void **)((s8 *)arg0 + 0x48) != NULL) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x48));
            *(void **)((s8 *)arg0 + 0x48) = NULL;
        }
        ((TShopSequence *)arg0)->close_message_window();
        if (*(TWin_8020F070 **)((s8 *)arg0 + 0x34) != NULL) {
            ((TWindowBase *)(*(TWin_8020F070 **)((s8 *)arg0 + 0x34)))->close();
            *(TWin_8020F070 **)((s8 *)arg0 + 0x34) = NULL;
        }
        if (*(TWin_8020F070 **)((s8 *)arg0 + 0x40) != NULL) {
            ((TWindowBase *)(*(TWin_8020F070 **)((s8 *)arg0 + 0x40)))->close();
            *(TWin_8020F070 **)((s8 *)arg0 + 0x40) = NULL;
        }
        if (*(TWin_8020F070 **)((s8 *)arg0 + 0x38) != NULL) {
            ((TWindowBase *)(*(TWin_8020F070 **)((s8 *)arg0 + 0x38)))->close();
            *(TWin_8020F070 **)((s8 *)arg0 + 0x38) = NULL;
        }
        if (*(TWin_8020F070 **)((s8 *)arg0 + 0x3C) != NULL) {
            ((TWindowBase *)(*(TWin_8020F070 **)((s8 *)arg0 + 0x3C)))->close();
            *(TWin_8020F070 **)((s8 *)arg0 + 0x3C) = NULL;
        }
        close_window__18TCheckRoomSequenceFPv((TCheckRoomSequence_8020F070 *)arg0);
        TCheckRoomSequence__slot_active_flags[sub_8022397C__15TShopWindowBaseFv(arg0)] = 0;
        if (*(u32 *)((s8 *)arg0 + 0x30) != 0) {
            TAdSinglePlyChrSelectGC::safe_free(*(s32 *)((s8 *)arg0 + 0x30));
            *(s32 *)((s8 *)arg0 + 0x30) = 0;
        }
        __dt__13TShopSequenceFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
#pragma pop

void *TCheckRoomSequence__ct(void *arg0, s32 arg1, s32 arg2_) {
    s32 arg2 = arg2_;
    TShopSequence__ct((u8 *)arg0);
    self->vt = __vt__18TCheckRoomSequence;
    self->f0 = ((s32)lbl_805D3640);
    self->f24 = arg2;
    self->f34 = 0;
    self->f38 = 0;
    self->f3c = 0;
    self->f40 = 0;
    self->f44 = 0;
    self->f48 = 0;
    self->f2c = 0;
    set_field_20__15TShopWindowBaseFl(arg0, 0);
    TCheckRoomSequence__active_instance = (s32)arg0;
    self->f30 = 0;
    TCheckRoomSequence__slot_active_flags[sub_8022397C__15TShopWindowBaseFv(arg0)] = 1;
    return arg0;
}
#undef self

#pragma push
#pragma optimization_level 1
void reset_slot_state__18TCheckRoomSequenceFv(void) {
    lbl_805D6160 = 0;
    TCheckRoomSequence__error_return_text_id = 0;
    TCheckRoomSequence__error_return_state = 0;
    TCheckRoomSequence__active_instance = 0;
    for (s32 i = 0; i < 4; i++) {
        TCheckRoomSequence__slot_active_flags[i] = 0;
    }
}
#pragma pop

#pragma push
#pragma optimization_level 1
void reset_slots__18TCheckRoomSequenceFv(void) {
    lbl_805D6160 = 0;
    TCheckRoomSequence__error_return_text_id = 0;
    TCheckRoomSequence__error_return_state = 0;
    TCheckRoomSequence__active_instance = 0;
    for (s32 i = 0; i < 4; i++) {
        TCheckRoomSequence__slot_active_flags[i] = 0;
    }
}
}
#pragma pop

#pragma push
#pragma optimization_level 1
u8 bank_has_free_row(s32 i) {
    return lbl_80513D98[i] <= 0xc7;
}
#pragma pop

#pragma push
#pragma optimization_level 1
s32 get_bank_meseta_capacity(s32 i) {
    return 999999 - lbl_80513DA8[i];
}
#pragma pop

#pragma push
#pragma optimization_level 1
extern "C" {
void compact_items__18TCheckRoomSequenceFi(s32 slot) {
    u8 *a;
    u8 *b;
    u8 *base;
    base = (u8 *)((Rec_80210904 * *)&bank_item_records_by_slot)[slot];
    for (a = base; a < base + 0x12A8; a += 0x18) {
        if (((s32 (*)(u8 *))is_item_record_empty)(a) != 0) {
            for (b = a + 0x18; b < base + 0x12C0; b += 0x18) {
                if (((s32 (*)(u8 *))is_item_record_empty)(b) == 0) {
                    ((TAdSinglePlyChrSelectGC *)a)->copy_item_data(b);
                    init_item_entry__18TCheckRoomSequenceFPv((Obj_80211408 *)(b));
                    break;
                }
            }
        }
    }
}
#pragma pop

void sort_bank_items(s32 slot) {
    compact_items__18TCheckRoomSequenceFi(0);
    ((TLobby *)((void *)bank_item_records_by_slot[slot]))->sort_records(lbl_80513D98[slot], 2);
}

#pragma push
#pragma optimization_level 1
s32 get_bank_deposit_capacity_for_item(Item_80210A04 *item, s32 slot) {
    Item_80210A04 *recs = (Item_80210A04 *)bank_item_records_by_slot[slot];
    s32 i;
    if (item->b0 != 3) {
        return 0;
    }
    if (get_item_def__18TCheckRoomSequenceFUl(item) == 0) {
        return 0;
    }
    for (i = 0; i < 200; i++) {
        if (((s32 (*)(u8 *))is_item_record_empty)((u8 *)&recs[i]) == 0 &&
            item->b0 == recs[i].b0 && item->b1 == recs[i].b1 &&
            item->b2 == recs[i].b2 && item->b4 == recs[i].b4) {
            return get_max_stack_size__9TItemDataFv(&recs[i]) - recs[i].f14;
        }
    }
    if (((s32 (*)(s32))bank_has_free_row)(slot) == 0) {
        return 0;
    }
    return get_max_stack_size__9TItemDataFv(item);
}
}
#pragma pop

#pragma push
#pragma optimization_level 1
s32 TCheckRoomSequence__sub_80210B34(u8 *item, s32 amount, s32 slot) {
    Item_80210A04 *recs = (Item_80210A04 *)bank_item_records_by_slot[slot];
    s32 i;
    if (item[0] != 3) {
        return 0;
    }
    if (get_item_def__18TCheckRoomSequenceFUl(item) == 0) {
        return 0;
    }
    for (i = 0; i < 200; i++) {
        if (((s32 (*)(u8 *))is_item_record_empty)((u8 *)&recs[i]) == 0 &&
            item[0] == recs[i].b0 && item[1] == recs[i].b1 && item[2] == recs[i].b2) {
            recs[i].f14 += amount;
            if (recs[i].f14 > get_max_stack_size__9TItemDataFv(&recs[i])) {
                recs[i].f14 = get_max_stack_size__9TItemDataFv(&recs[i]);
            }
            return 1;
        }
    }
    for (i = 0; i < 200; i++) {
        if (((s32 (*)(u8 *))is_item_record_empty)((u8 *)&recs[i]) != 0) {
            copy_item_to_bank_entry__18TCheckRoomSequenceFPvPv((u8 *)&recs[i], item);
            recs[i].f14 = amount;
            lbl_80513D98[slot]++;
            return 1;
        }
    }
    return 0;
}
#pragma pop

#pragma push
#pragma optimization_level 1
s32 bank_debit_meseta(s32 v, s32 i) {
    if (lbl_80513DA8[i] < v) {
        return 0;
    }
    lbl_80513DA8[i] -= v;
    return 1;
}
#pragma pop

#pragma push
#pragma optimization_level 1
s32 bank_credit_meseta(s32 v, s32 i) {
    lbl_80513DA8[i] += v;
    return 1;
}
#pragma pop

#pragma push
#pragma optimization_level 1
extern "C" {
s32 TCheckRoomSequence__sub_80210D44(u8 *item, s32 slot) {
    Rec_80211034 *rec = bank_item_records_by_slot[slot];
    s32 i;
    for (i = 0; i < 200; i++, rec++) {
        if (((s32 (*)(u8 *))is_item_record_empty)(rec->b) == 0 &&
            rec->b[0] == item[0] && rec->b[1] == item[1] && rec->b[2] == item[2] &&
            rec->b[3] == item[3] && rec->b[4] == item[4] && rec->b[5] == item[5]) {
            init_item_entry__18TCheckRoomSequenceFPv((Obj_80211408 *)rec);
            copy_bank_to_card_window(slot);
            return 1;
        }
    }
    return 0;
}

void remove_bank_item_amount__18TCheckRoomSequenceFiii(s32 idx, s32 amount, s32 slot) {
    Item_80210E28 *recs = (Item_80210E28 *)bank_item_records_by_slot[slot];
    s32 n;
    if (idx <= 199) {
        if (recs[idx].b0 != 3) {
            init_item_entry__18TCheckRoomSequenceFPv((Obj_80211408 *)&recs[idx]);
            lbl_80513D98[slot]--;
            copy_bank_to_card_window(slot);
        } else if (get_item_def__18TCheckRoomSequenceFUl(&recs[idx]) == 0) {
            init_item_entry__18TCheckRoomSequenceFPv((Obj_80211408 *)&recs[idx]);
            lbl_80513D98[slot]--;
            copy_bank_to_card_window(slot);
        } else if (((s32 (*)(u8 *))is_item_record_empty)((u8 *)&recs[idx]) == 0) {
            n = recs[idx].f14;
            n -= amount;
            if (n >= 0) {
                if (n == 0) {
                    init_item_entry__18TCheckRoomSequenceFPv((Obj_80211408 *)&recs[idx]);
                    lbl_80513D98[slot]--;
                    copy_bank_to_card_window(slot);
                } else {
                    recs[idx].f14 = n;
                    copy_bank_to_card_window(slot);
                }
            }
        }
    }
}
#pragma pop

typedef struct Rec_80210F78 Rec_80210F78;
#pragma optimization_level 1
s32 copy_bank_item_with_stack_limit(s32 idx, void *data, s32 *out, s32 slot) {
  s32 base = (s32) bank_item_records_by_slot[slot];
  Rec_80210F78 *t;
  s32 new_var;
  if (idx > 199)
  {
    return 0;
  }
  if (((s32 (*)(u8 *)) is_item_record_empty)((u8 *) (base + (idx * 0x18))) != 0)
  {
    return 0;
  }
  copy_data__18TCheckRoomSequenceFPvPv((void*)((void *) (base + (idx * 0x18))), data);
  t = (Rec_80210F78 *) (base + (idx * 0x18));
  *out = t->f14;
  {
    s32 r = ((s32 (*)(void *, void *))get_max_stack_size__9TItemDataFv)(data, t);
    if (r < (*out))
    {
      *out = r;
      r = base + (idx * 0x18);
      {
        Rec_80210F78 *t2 = (Rec_80210F78 *) r;
        new_var = *out;
        t2->f14 = new_var;
      }
    }
  }
  return 1;
}

#pragma push
#pragma optimization_level 1
s32 copy_item_record__18TCheckRoomSequenceFiPvi(s32 idx, void *data, s32 slot) {
    Rec_80211034 *recs = bank_item_records_by_slot[slot];
    if (idx > 199) {
        return 0;
    }
    if (((s32 (*)(u8 *))is_item_record_empty)((u8 *)&recs[idx]) != 0) {
        return 0;
    }
    copy_data__18TCheckRoomSequenceFPvPv(&recs[idx], data);
    return 1;
}
#pragma pop

#pragma push
#pragma optimization_level 1
s32 store_item_in_bank(u8 *item, s32 arg1, s32 slot) {
    Rec_80211034 *recs = bank_item_records_by_slot[slot];
    s32 i;
    if (TCheckRoomSequence__sub_80210B34(item, arg1, slot) != 0) {
        return 1;
    }
    if (((s32 (*)(s32))bank_has_free_row)(slot) == 0) {
        return 0;
    }
    for (i = 0; i < 200; i++) {
        if (((s32 (*)(u8 *))is_item_record_empty)((u8 *)&recs[i]) != 0) {
            copy_item_to_bank_entry__18TCheckRoomSequenceFPvPv((u8 *)&recs[i], item);
            lbl_80513D98[slot]++;
            copy_bank_to_card_window(slot);
            return 1;
        }
    }
    return 0;
}
#pragma pop

#pragma push
#pragma optimization_level 1
void copy_bank_to_card_window(s32 slot) {
    Card_8021118C *w;
    if (TAdSinglePlyChrSelectGC::is_ready() != 0) {
        w = (Card_8021118C *)get_character_save_record(slot);
        if (w != 0) {
            w->meseta = lbl_80513DA8[slot];
            w->count = lbl_80513D98[slot];
            ((TLobby *)(w->items))->move_data(bank_item_records_by_slot[slot], 0x12C0);
        }
    }
}
}
#pragma pop

#pragma push
#pragma optimization_level 1
void copy_bank_from_card_window(s32 slot) {
    Card_8021118C *w = (Card_8021118C *)get_character_save_record(slot);
    if (w != 0) {
        lbl_80513DA8[slot] = w->meseta;
        lbl_80513D98[slot] = w->count;
        ((TLobby *)(bank_item_records_by_slot[slot]))->move_data(w->items, 0x12C0);
    }
}
#pragma pop
extern "C" {

void mem_free(void *p);

#pragma push
#pragma optimization_level 1
void TCheckRoomSequence__sub_80211284(void) {
    Rec_80211034 *recs;
    s32 i;
    for (i = 3; i >= 0; i--) {
        if (bank_item_records_by_slot[i] != NULL) {
            recs = bank_item_records_by_slot[i];
            if (recs != NULL) {
                mem_free((u8 *)recs - 0x10);
            }
            bank_item_records_by_slot[i] = NULL;
        }
        lbl_80513DA8[i] = 0;
        lbl_80513D98[i] = 0;
    }
}
#pragma pop

s32 is_split_screen();
void *mem_alloc(int);
u32 __construct_new_array(void *, void *, void *, int, int);
void alloc_item_buffers__18TCheckRoomSequenceFv(void) {
    s32 i;
    s32 j;

    for (j = 0; j < 4; j++) {
        lbl_80513DA8[j] = 0;
        lbl_80513D98[j] = 0;
        ((u32 *)bank_item_records_by_slot)[j] = 0;
    }
    if (is_split_screen() == 1) {
        for (i = 0; i < 4; i++) {
            ((u32 *)bank_item_records_by_slot)[i] = __construct_new_array(mem_alloc(0x12D0),
                (void *)TAdSinglePlyChrSelectGC__sub_802115C0, NULL, 0x18, 200);
        }
    } else {
        ((u32 *)bank_item_records_by_slot)[0] = __construct_new_array(mem_alloc(0x12D0),
            (void *)TAdSinglePlyChrSelectGC__sub_802115C0, NULL, 0x18, 200);
    }
}

#pragma push
#pragma optimization_level 1
void init_item_entry__18TCheckRoomSequenceFPv(Obj_80211408 *self) {
    init__9TItemDataFv(self);
    self->a = 0;
    self->b = 0;
}
#pragma pop

void copy_data__18TCheckRoomSequenceFPvPv(void* p, void* a1) { *(unsigned char*)(a1) = *(unsigned char*)(p); *(unsigned char*)((char*)a1 + 0x1) = *(unsigned char*)((char*)p + 0x1); *(unsigned char*)((char*)a1 + 0x2) = *(unsigned char*)((char*)p + 0x2); *(unsigned char*)((char*)a1 + 0x3) = *(unsigned char*)((char*)p + 0x3); *(unsigned char*)((char*)a1 + 0x4) = *(unsigned char*)((char*)p + 0x4); *(unsigned char*)((char*)a1 + 0x5) = *(unsigned char*)((char*)p + 0x5); ((TObjPlayer *)((char*)a1 + 0x6))->copy_entry_bytes((char*)p + 0x6); ((TObjPlayer *)((char*)a1 + 0x8))->copy_entry_bytes((char*)p + 0x8); ((TObjPlayer *)((char*)a1 + 0xa))->copy_entry_bytes((char*)p + 0xa); *(void**)((char*)a1 + 0xc) = *(void**)((char*)p + 0xc); *(void**)((char*)a1 + 0x10) = *(void**)((char*)p + 0x10); }

#pragma push
#pragma optimization_level 1
void copy_item_to_bank_entry__18TCheckRoomSequenceFPvPv(u8 *arg0, u8 *arg1) {
    *(u8 *)((s8 *)arg0 + 0) = (u8) *(u8 *)((s8 *)arg1 + 0);
    *(u8 *)((s8 *)arg0 + 1) = (u8) *(u8 *)((s8 *)arg1 + 1);
    *(u8 *)((s8 *)arg0 + 2) = (u8) *(u8 *)((s8 *)arg1 + 2);
    *(u8 *)((s8 *)arg0 + 3) = (u8) *(u8 *)((s8 *)arg1 + 3);
    *(u8 *)((s8 *)arg0 + 4) = (u8) *(u8 *)((s8 *)arg1 + 4);
    *(u8 *)((s8 *)arg0 + 5) = (u8) *(u8 *)((s8 *)arg1 + 5);
    ((TObjPlayer *)(arg0 + 6))->copy_entry_bytes(arg1 + 6);
    ((TObjPlayer *)(arg0 + 8))->copy_entry_bytes(arg1 + 8);
    ((TObjPlayer *)(arg0 + 0xA))->copy_entry_bytes(arg1 + 0xA);
    *(s32 *)((s8 *)arg0 + 0xC) = (s32) *(s32 *)((s8 *)arg1 + 0xC);
    *(s32 *)((s8 *)arg0 + 0x10) = (s32) *(s32 *)((s8 *)arg1 + 0x10);
    *(s16 *)((s8 *)arg0 + 0x14) = 1;
    *(s16 *)((s8 *)arg0 + 0x16) = 1;
}
#pragma pop

u8 is_item_record_empty(u8 *arg0) {
    return (u8) (*(s16 *)((s8 *)arg0 + 0x16) == 0);
}

#pragma push
#pragma optimization_level 1
void TAdSinglePlyChrSelectGC::init_item_entry() {
    Obj_80211584 *self = (Obj_80211584 *)this;
    init__9TItemDataFv(self);
    self->a = 0;
    self->b = 0;
}
#pragma pop

void* TAdSinglePlyChrSelectGC__sub_802115C0(void* p) { ((TAdSinglePlyChrSelectGC *)p)->init_item_entry(); return p; }

void TShopWindowBase::vfunc_6() {  }
}
