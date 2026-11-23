#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/CharacterSaveRecordLookup.h"
#include "pso/unk/text_8026934C.h"
#include "types.h"
#include "pso/ui/window/TWindowDeposit.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
struct TShopKeepItemWindow;

#include "pso/ui/city/TShopSequence.h"
#include "pso/ui/city/TCheckRoomSequence.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/ui/city/TShopEquipmentSellWindow.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowInputNumber.h"
#include "pso/item/TItemData.h"
#include "pso/unk/TLobby_803DE778.h"
#include "pso/object/base/TObjBase.h"

#pragma readonly_strings on


const char *TCheckRoomSequence__name = "TCheckRoomSequence";
s32 lbl_805D6160;
s32 TCheckRoomSequence__error_return_text_id;
saddr TCheckRoomSequence__error_return_state;
s32 TCheckRoomSequence__active_instance;


#pragma optimization_level 1

struct Rec_80211034 { u8 b[0x18]; };
struct Obj_80211408 { u8 pad[0x14]; s16 a; s16 b; };

struct Obj_80211584 { u8 pad[0x14]; s16 a; s16 b; };

struct TWin_8020F070 { u8 pad[0x44]; };

struct TCheckRoomSequence_8020F070 { u8 pad[0x44]; TWin_8020F070 *win; };

struct Obj_8020F268 { u8 pad[0x28]; void (*cb0)(u8 *); void (*cb1)(uaddr); };

struct Seq_8020F268 { u8 pad[0x24]; saddr f24; };

struct Obj_8020F2D8 { u8 pad[0x60]; void (*cb0)(u8 *); void (*cb1)(uaddr); };

struct Seq_8020F2D8 { u8 pad[0x24]; saddr f24; };


struct Rec_80210904 { u8 b[0x18]; };

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
    saddr f24;
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
    saddr f24;
    u8 pad28[0x34 - 0x28];
    void *f34;
};

struct Item_80210A04 { u8 b0, b1, b2, b3, b4; u8 pad5[0x14 - 5]; s16 f14; u8 pad16[2]; };

struct TWin_8020F070;

struct Win_8020F8C0 { u8 pad[0x394]; void *cb0; void *cb1; };

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
void init_item_entry__18TCheckRoomSequenceFPv(Obj_80211408 *self);
void close_window__18TCheckRoomSequenceFPv(TCheckRoomSequence_8020F070 *self);
int reset_controller_input_state(void *);
void *__ct__21TShopDeleteItemWindowFPvPvPv(void *arg0, void *arg1, void *arg2, void *arg3);
void notify_quest_list_vm__18TCheckRoomSequenceFPv(u8 *arg0);
void init_check__18TCheckRoomSequenceFUi(uaddr arg0);
extern void *tl_05;
void open_delete_item_window__18TCheckRoomSequenceFPv(Seq_8020F268 *self);
void *__ct__18TShopGetItemWindowFPvPvPv(void *arg0, void *arg1, void *arg2, void *arg3);
void open_get_item_window__18TCheckRoomSequenceFPv(Seq_8020F2D8 *self);
void finish_room_check__18TCheckRoomSequenceFPv(u8 *arg0);
void handle_error_ack__18TCheckRoomSequenceFPv(u8 *arg0);
void accept_meseta_withdrawal__18TCheckRoomSequenceFPv(u8 *arg0);
s32 try_spend_actor_meseta(u8 *arg0, s32 arg1);
void accept_meseta_deposit__18TCheckRoomSequenceFPv(u8 *arg0);
void copy_item_to_bank_entry__18TCheckRoomSequenceFPvPv(u8 *arg0, u8 *arg1);
void compact_items__18TCheckRoomSequenceFi(s32 slot);
s32 poll_memcard_result(saddr chan);
int obj_getPtr2B0_20(u8 *p);
void *__ct__18TWindowInputNumberFPvllls(void *, s32, s32, s32, s32, s16);
saddr get_window_layout_position(s32);
void begin_meseta_withdrawal__18TCheckRoomSequenceFPv(Seq_8020F478 *self);
void begin_meseta_deposit__18TCheckRoomSequenceFPv(Seq_8020F730 *self);
s32 get_max_stack_size__9TItemDataFv(void *);
s32 get_bank_deposit_capacity_for_item(Item_80210A04 *item, s32 slot);
s32 TCheckRoomSequence__sub_80210B34(u8 *, s32, s32);
s32 store_item_in_bank(u8 *item, s32 arg1, s32 slot);
s32 check_room_ready__18TCheckRoomSequenceFv(void);
s32 get_shop_text(int);

void handle_root_choice__18TCheckRoomSequenceFv(u8 *arg0);
void *__ct__19TShopKeepItemWindowFPvPvPv(TShopKeepItemWindow *arg0, void *arg1, void *arg2, void *arg3);
void init_check_params__18TCheckRoomSequenceFUi(uaddr arg0);
void open_deposit_item_window__18TCheckRoomSequenceFv(u8 *arg0);
void handle_withdraw_choice__18TCheckRoomSequenceFv(u8 *arg0);
void handle_deposit_choice__18TCheckRoomSequenceFv(u8 *arg0);
s32 set_service_counter_camera(void *, int);
void open_bank__18TCheckRoomSequenceFv(u8 *arg0);
void remove_bank_item_amount__18TCheckRoomSequenceFiii(s32 idx, s32 amount, s32 slot);
void copy_bank_to_card_window(s32 slot);
extern u32 bank_item_records_by_slot[4];
void copy_data__18TCheckRoomSequenceFPvPv(void* p, void* a1);
s32 copy_bank_item_with_stack_limit(s32 idx, void *data, s32 *out, s32 slot);
void* TAdSinglePlyChrSelectGC__sub_802115C0(void* p);
void set_quest_list_mode_19__18TCheckRoomSequenceFPv(void* p);
s32 get_game_play_mode();

u32 bank_item_records_by_slot[4];
u32 lbl_80513D98[4];
u32 lbl_80513DA8[4];
u32 TCheckRoomSequence__slot_active_flags[4];
#define bank_item_records_by_slot (*(Rec_80211034 *(*)[4])bank_item_records_by_slot)
#define lbl_80513D98 (*(s32 (*)[4])lbl_80513D98)
#define lbl_80513DA8 (*(s32 (*)[4])lbl_80513DA8)

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

void init_check_params__18TCheckRoomSequenceFUi(uaddr arg0) {
    TCheckRoomSequence__error_return_text_id = 0x46;
    TCheckRoomSequence__error_return_state = 2;
    if (arg0 != 0U) {
        ((TShopWindowBase *)arg0)->set_field_20(0x10);
    }
}

#pragma push
#pragma optimization_level 1
void finish_room_check__18TCheckRoomSequenceFPv(u8 *arg0) {
    if (arg0 != NULL) {
        ((TShopWindowBase *)arg0)->display_shop_message(0x46, 1);
    }
    if (arg0 != NULL) {
        ((TShopWindowBase *)arg0)->set_field_20(2);
    }
}
#pragma pop

void init_check__18TCheckRoomSequenceFUi(uaddr arg0) {
    if (arg0 != 0U) {
        TCheckRoomSequence__error_return_text_id = 0x46;
        TCheckRoomSequence__error_return_state = 2;
        ((TShopWindowBase *)arg0)->set_field_20(0x10);
    }
}

void notify_quest_list_vm__18TCheckRoomSequenceFPv(u8 *arg0) {
    if (arg0 != NULL) {
        ((TShopWindowBase *)arg0)->display_shop_message(0x1A, 1);
        ((TShopWindowBase *)arg0)->set_field_20(2);
    }
}
}
u8 bank_has_free_row(s32 i);
s32 get_bank_meseta_capacity(s32 i);
s32 bank_credit_meseta(s32 v, s32 i);
s32 bank_debit_meseta(s32 v, s32 i);
void copy_bank_from_card_window(s32 slot);
void TCheckRoomSequence::sub_8020F1DC() {  }


#pragma push
#pragma optimization_level 1
void handle_error_ack__18TCheckRoomSequenceFPv(u8 *arg0) {
    if ((((TShopWindowBase *)(arg0))->vfunc_10() != 0) && ((((TShopWindowBase *)arg0)->sub_80223A48() != 0) || (((TShopWindowBase *)arg0)->sub_802239EC() != 0))) {
        ((TShopWindowBase *)arg0)->display_shop_message(TCheckRoomSequence__error_return_text_id, 1);
        ((TShopWindowBase *)arg0)->set_field_20(TCheckRoomSequence__error_return_state);
    }
}
#pragma pop

#pragma push
#pragma optimization_level 1
void open_delete_item_window__18TCheckRoomSequenceFPv(Seq_8020F268 *self) {
    void *o = TObject::operator new(0x68);
    if (o != 0) {
        o = __ct__21TShopDeleteItemWindowFPvPvPv((void *)o, (void *)tl_05, (void *)self, (void *)self->f24);
    }
    ((Obj_8020F268 *)o)->cb0 = notify_quest_list_vm__18TCheckRoomSequenceFPv;
    ((Obj_8020F268 *)o)->cb1 = init_check__18TCheckRoomSequenceFUi;
    reset_controller_input_state(o);
    ((TShopWindowBase *)self)->set_field_20(0x11);
}
#pragma pop

#pragma push
#pragma optimization_level 1
void open_get_item_window__18TCheckRoomSequenceFPv(Seq_8020F2D8 *self) {
    void *o = TObject::operator new(0x68);
    if (o != 0) {
        o = __ct__18TShopGetItemWindowFPvPvPv((void *)o, (void *)tl_05, (void *)self, (void *)self->f24);
    }
    ((Obj_8020F2D8 *)o)->cb0 = notify_quest_list_vm__18TCheckRoomSequenceFPv;
    ((Obj_8020F2D8 *)o)->cb1 = init_check__18TCheckRoomSequenceFUi;
    reset_controller_input_state(o);
    ((TShopWindowBase *)self)->set_field_20(0x11);
}
#pragma pop

#pragma push
#pragma optimization_level 1
void accept_meseta_withdrawal__18TCheckRoomSequenceFPv(u8 *arg0) {
    s32 amount;
    s32 slot;
    if (((u32) *(u32 *)((s8 *)arg0 + 0x34) != 0U) && (((s32)((TWindowInputNumber *)(*(uaddr *)((s8 *)arg0 + 0x34)))->is_confirmed()) != 0)) {
        amount = ((TShopEquipmentSellWindow *)(*(uaddr *)((s8 *)arg0 + 0x34)))->get_result();
        slot = ((s32)((TShopWindowBase *)arg0)->sub_8022397C());
        bank_debit_meseta(amount, slot);
        ((TObjPlayer *)(*(saddr *)((s8 *)arg0 + 0x24)))->add_meseta(amount);
        copy_bank_to_card_window(slot);
        if ((u32) *(u32 *)((s8 *)arg0 + 0x40) != 0U) {
            TWindowMainMenu::set_entry_field_20((int) (*(u32 *)((s8 *)arg0 + 0x40)), (int) (TCheckRoomSequence::get_room_data(slot)));
        }
        ((TShopWindowBase *)arg0)->display_shop_message(0x46, 1);
        ((TShopWindowBase *)arg0)->set_field_20(2);
        ((TWindowBase *)(*(uaddr *)((s8 *)arg0 + 0x34)))->close();
        *(u32 *)((s8 *)arg0 + 0x34) = 0U;
    }
    if (((u32) *(u32 *)((s8 *)arg0 + 0x34) != 0U) && (((s32)((TShopEquipmentSellWindow *)(*(uaddr *)((s8 *)arg0 + 0x34)))->is_confirmed()) != 0)) {
        ((TShopWindowBase *)arg0)->display_shop_message(0x46, 1);
        ((TShopWindowBase *)arg0)->set_field_20(0xA);
        ((TWindowBase *)(*(uaddr *)((s8 *)arg0 + 0x34)))->close();
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
    count = TCheckRoomSequence::get_room_data(((TShopWindowBase *)self)->sub_8022397C());
    if (count > 0) {
        n = 999999 - obj_getPtr2B0_20((u8 *)self->f24);
        n = (n < count) ? n : count;
        if (n > 0) {
            if (self->f34 == NULL) {
                w = TObject::operator new(0x7C);
                if (w != NULL) {
                    id = ((s16)((TShopSequence *)self)->get_child_field1c());
                    w = __ct__18TWindowInputNumberFPvllls(w, get_window_layout_position(0x2B), 1, n, 1, id);
                }
                self->f34 = w;
                if (self->f34 != NULL && TLobby::is_camera_ctrl_active() > 2) {
                    ((TCheckRoomSequence *)self->f34)->set_position(0.75f, 0.75f);
                }
            }
            ((void (*)())reset_controller_input_state)();
            self->m4(0x3F, 1);
            ((TShopWindowBase *)self)->set_field_20(0xC);
            return;
        }
        self->m4(0x4A, 1);
        TCheckRoomSequence__error_return_text_id = 0x46;
        TCheckRoomSequence__error_return_state = 2;
        ((TShopWindowBase *)self)->set_field_20(0x10);
        return;
    }
    self->m4(0x3D, 1);
    TCheckRoomSequence__error_return_text_id = 0x46;
    TCheckRoomSequence__error_return_state = 2;
    ((TShopWindowBase *)self)->set_field_20(0x10);
}
#pragma pop

#pragma push
#pragma optimization_level 1
void accept_meseta_deposit__18TCheckRoomSequenceFPv(u8 *arg0) {
    s32 temp_r31;
    s32 slot;
    if (((u32) *(u32 *)((s8 *)arg0 + 0x34) != 0U) && (((s32)((TWindowInputNumber *)(*(uaddr *)((s8 *)arg0 + 0x34)))->is_confirmed()) != 0)) {
        temp_r31 = ((TShopEquipmentSellWindow *)(*(uaddr *)((s8 *)arg0 + 0x34)))->get_result();
        slot = ((s32)((TShopWindowBase *)arg0)->sub_8022397C());
        bank_credit_meseta(temp_r31, slot);
        try_spend_actor_meseta((u8 *)(*(saddr *)((s8 *)arg0 + 0x24)), (temp_r31));
        copy_bank_to_card_window(slot);
        if ((u32) *(u32 *)((s8 *)arg0 + 0x40) != 0U) {
            TWindowMainMenu::set_entry_field_20((int) (*(u32 *)((s8 *)arg0 + 0x40)), (int) (TCheckRoomSequence::get_room_data(slot)));
        }
        ((TShopWindowBase *)arg0)->display_shop_message(0x46, 1);
        ((TShopWindowBase *)arg0)->set_field_20(2);
        ((TWindowBase *)(*(uaddr *)((s8 *)arg0 + 0x34)))->close();
        *(u32 *)((s8 *)arg0 + 0x34) = 0U;
    }
    if (((u32) *(u32 *)((s8 *)arg0 + 0x34) != 0U) && (((s32)((TShopEquipmentSellWindow *)(*(uaddr *)((s8 *)arg0 + 0x34)))->is_confirmed()) != 0)) {
        ((TShopWindowBase *)arg0)->display_shop_message(0x46, 1);
        ((TShopWindowBase *)arg0)->set_field_20(3);
        ((TWindowBase *)(*(uaddr *)((s8 *)arg0 + 0x34)))->close();
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
    slot = ((TShopWindowBase *)self)->sub_8022397C();
    if (get_bank_meseta_capacity(slot) > 0) {
        meseta = obj_getPtr2B0_20((u8 *)self->f24);
        if (meseta > 0) {
            n = get_bank_meseta_capacity(slot);
            n = (n < meseta) ? n : meseta;
            if (self->f34 == NULL) {
                w = TObject::operator new(0x7C);
                if (w != NULL) {
                    id = ((s16)((TShopSequence *)self)->get_child_field1c());
                    w = __ct__18TWindowInputNumberFPvllls(w, get_window_layout_position(0x2B), 1, n, 1, id);
                }
                self->f34 = w;
                if (self->f34 != NULL && TLobby::is_camera_ctrl_active() > 2) {
                    ((TCheckRoomSequence *)self->f34)->set_position(0.75f, 0.75f);
                }
            }
            ((void (*)())reset_controller_input_state)();
            self->m4(0x34, 1);
            ((TShopWindowBase *)self)->set_field_20(5);
            return;
        }
        self->m4(0x47, 1);
        TCheckRoomSequence__error_return_text_id = 0x46;
        TCheckRoomSequence__error_return_state = 2;
        ((TShopWindowBase *)self)->set_field_20(0x10);
        return;
    }
    self->m4(0x37, 1);
    TCheckRoomSequence__error_return_text_id = 0x46;
    TCheckRoomSequence__error_return_state = 2;
    ((TShopWindowBase *)self)->set_field_20(0x10);
}
#pragma pop

#pragma push
#pragma optimization_level 1
void open_deposit_item_window__18TCheckRoomSequenceFv(u8 *arg0) {
    void *mem;
    Win_8020F8C0 *w;
    if (TCheckRoomSequence::get_room_table_entry(((TShopWindowBase *)arg0)->sub_8022397C()) > 0xC8) {
        ((TShopWindowBase *)arg0)->display_shop_message(0x3C, 1);
        TCheckRoomSequence__error_return_text_id = 0x46;
        TCheckRoomSequence__error_return_state = 2;
        ((TShopWindowBase *)arg0)->set_field_20(0x10);
        return;
    }
    ((TShopWindowBase *)arg0)->display_shop_message(0x38, 1);
    mem = TObject::operator new(0x39C);
    w = (Win_8020F8C0 *)mem;
    if (mem != NULL) {
        w = (Win_8020F8C0 *)__ct__19TShopKeepItemWindowFPvPvPv((TShopKeepItemWindow *)((void *)mem), (void *)tl_05, (void *)arg0, (void *)(*(saddr *)((s8 *)arg0 + 0x24)));
    }
    w->cb0 = (void *)finish_room_check__18TCheckRoomSequenceFPv;
    w->cb1 = (void *)init_check_params__18TCheckRoomSequenceFUi;
    reset_controller_input_state(w);
    ((TShopWindowBase *)arg0)->set_field_20(0x11);
}
#pragma pop

void set_quest_list_mode_19__18TCheckRoomSequenceFPv(void* p) { ((TShopWindowBase *)p)->set_field_20(19); }

#pragma push
#pragma optimization_level 1
void handle_withdraw_choice__18TCheckRoomSequenceFv(u8 *arg0) {
    TCheckRoomSequence *sequence = reinterpret_cast<TCheckRoomSequence *>(arg0);
    s32 selected_menu_value;
    switch (*(s32 *)((s8 *)arg0 + 0x2C)) {
    case 0:
        if (sequence->choice_menu == NULL) {
            sequence->choice_menu = create_window_menu((saddr)get_window_layout_position(0x2B), 2, (u16)((TObjBase *)((saddr) (*(saddr *)((s8 *)arg0 + 0x24))))->get_entity_id());
            sequence->choice_menu->add_text_entry(get_shop_text(2), 6, 0);
            sequence->choice_menu->add_text_entry(get_shop_text(3), 6, 1);
            sequence->choice_menu->calc_window_size();
            align_menu_entry_positions(sequence->choice_menu);
            sequence->choice_menu->set_ready_flag();
            sequence->choice_menu->set_position_xy(((TShopWindowBase *)arg0)->get_scale(), ((TShopWindowBase *)arg0)->get_scale());
        }
        ((TShopWindowBase *)arg0)->display_shop_message(0x32, 1);
        *(s32 *)((s8 *)arg0 + 0x2C) = 1;
        return;
    case 1:
        if ((sequence->choice_menu != NULL) && (sequence->choice_menu->is_decided() != 0)) {
            selected_menu_value = sequence->choice_menu->get_selected_value();
            if (selected_menu_value == 0) {
                sequence->set_field_20(7);
                sequence->choice_menu->close();
                sequence->choice_menu = NULL;
            }
            if (selected_menu_value == 1) {
                sequence->set_field_20(9);
                sequence->choice_menu->close();
                sequence->choice_menu = NULL;
            }
            *(s32 *)((s8 *)arg0 + 0x2C) = 0;
        }
        if ((sequence->choice_menu != NULL) && (sequence->choice_menu->is_cancelled() != 0)) {
            ((TShopWindowBase *)arg0)->display_shop_message(0x46, 1);
            sequence->set_field_20(2);
            sequence->choice_menu->close();
            sequence->choice_menu = NULL;
            *(s32 *)((s8 *)arg0 + 0x2C) = 0;
        }
        return;
    }
}
#pragma pop

#pragma push
#pragma optimization_level 1
void handle_deposit_choice__18TCheckRoomSequenceFv(u8 *arg0) {
    TCheckRoomSequence *sequence = reinterpret_cast<TCheckRoomSequence *>(arg0);
    s32 selected_menu_value;
    switch (*(s32 *)((s8 *)arg0 + 0x2C)) {
    case 0:
        if (sequence->choice_menu == NULL) {
            sequence->choice_menu = create_window_menu((saddr)get_window_layout_position(0x2B), 2, (u16)((TObjBase *)((saddr) (*(saddr *)((s8 *)arg0 + 0x24))))->get_entity_id());
            sequence->choice_menu->add_text_entry(get_shop_text(2), 6, 0);
            sequence->choice_menu->add_text_entry(get_shop_text(3), 6, 1);
            sequence->choice_menu->calc_window_size();
            align_menu_entry_positions(sequence->choice_menu);
            sequence->choice_menu->set_ready_flag();
            sequence->choice_menu->set_position_xy(((TShopWindowBase *)arg0)->get_scale(), ((TShopWindowBase *)arg0)->get_scale());
        }
        ((TShopWindowBase *)arg0)->display_shop_message(0x33, 1);
        *(s32 *)((s8 *)arg0 + 0x2C) = 1;
        return;
    case 1:
        if ((sequence->choice_menu != NULL) && (sequence->choice_menu->is_decided() != 0)) {
            selected_menu_value = sequence->choice_menu->get_selected_value();
            if (selected_menu_value == 0) {
                sequence->set_field_20(6);
                sequence->choice_menu->close();
                sequence->choice_menu = NULL;
            }
            if (selected_menu_value == 1) {
                sequence->set_field_20(4);
                sequence->choice_menu->close();
                sequence->choice_menu = NULL;
            }
            *(s32 *)((s8 *)arg0 + 0x2C) = 0;
        }
        if ((sequence->choice_menu != NULL) && (sequence->choice_menu->is_cancelled() != 0)) {
            ((TShopWindowBase *)arg0)->display_shop_message(0x46, 1);
            sequence->set_field_20(2);
            sequence->choice_menu->close();
            sequence->choice_menu = NULL;
            *(s32 *)((s8 *)arg0 + 0x2C) = 0;
        }
        return;
    }
}
#pragma pop

#pragma push
#pragma optimization_level 1
void handle_root_choice__18TCheckRoomSequenceFv(u8 *arg0) {
    TCheckRoomSequence *sequence = reinterpret_cast<TCheckRoomSequence *>(arg0);
    f32 temp_f31;
    f32 temp_f31_2;
    s32 selected_menu_value;
    s32 selected_value;
    if (check_room_ready__18TCheckRoomSequenceFv() != 0) {
        switch (*(s32 *)((s8 *)arg0 + 0x2C)) {
        case 0:
            if (sequence->choice_menu == NULL) {
                sequence->choice_menu = create_window_menu((saddr)get_window_layout_position(0x2B), 2, (u16)((TObjBase *)((saddr) (*(saddr *)((s8 *)arg0 + 0x24))))->get_entity_id());
                sequence->choice_menu->add_text_entry(get_shop_text(8), 6, 0);
                sequence->choice_menu->add_text_entry(get_shop_text(9), 6, 1);
                sequence->choice_menu->calc_window_size();
                align_menu_entry_positions(sequence->choice_menu);
                sequence->choice_menu->set_ready_flag();
                sequence->choice_menu->set_position_xy(((TShopWindowBase *)arg0)->get_scale(), ((TShopWindowBase *)arg0)->get_scale());
            }
            *(s32 *)((s8 *)arg0 + 0x2C) = 1;
            return;
        case 1:
            if ((sequence->choice_menu != NULL) && (sequence->choice_menu->is_decided() != 0)) {
                selected_menu_value = sequence->choice_menu->get_selected_value();
                if (selected_menu_value == 0) {
                    sequence->set_field_20(3);
                    sequence->choice_menu->close();
                    sequence->choice_menu = NULL;
                }
                if (selected_menu_value == 1) {
                    sequence->set_field_20(0xA);
                    sequence->choice_menu->close();
                    sequence->choice_menu = NULL;
                }
                *(s32 *)((s8 *)arg0 + 0x2C) = 0;
            }
            if ((sequence->choice_menu != NULL) && (sequence->choice_menu->is_cancelled() != 0)) {
                ((TShopWindowBase *)arg0)->display_shop_message(0x48, 1);
                sequence->set_field_20(0xD);
                sequence->choice_menu->close();
                sequence->choice_menu = NULL;
                *(s32 *)((s8 *)arg0 + 0x2C) = 0;
                return;
            }
            break;
        }
    } else {
        switch (*(s32 *)((s8 *)arg0 + 0x2C)) {
        case 0:
            if (sequence->choice_menu == NULL) {
                sequence->choice_menu = create_window_menu((saddr)get_window_layout_position(0x2B), 2, (u16)((TObjBase *)((saddr) (*(saddr *)((s8 *)arg0 + 0x24))))->get_entity_id());
                sequence->choice_menu->add_text_entry(get_shop_text(0xA), 6, 1);
                sequence->choice_menu->calc_window_size();
                align_menu_entry_positions(sequence->choice_menu);
                sequence->choice_menu->set_ready_flag();
                sequence->choice_menu->set_position_xy(((TShopWindowBase *)arg0)->get_scale(), ((TShopWindowBase *)arg0)->get_scale());
            }
            *(s32 *)((s8 *)arg0 + 0x2C) = 1;
            return;
        case 1:
            if ((sequence->choice_menu != NULL) && (sequence->choice_menu->is_decided() != 0)) {
                selected_value = sequence->choice_menu->get_selected_value();
                if (selected_value == 0) {
                    sequence->set_field_20(0xA);
                    sequence->choice_menu->close();
                    sequence->choice_menu = NULL;
                }
                if (selected_value == 1) {
                    sequence->set_field_20(0x12);
                    sequence->choice_menu->close();
                    sequence->choice_menu = NULL;
                }
                *(s32 *)((s8 *)arg0 + 0x2C) = 0;
            }
            if ((sequence->choice_menu != NULL) && (sequence->choice_menu->is_cancelled() != 0)) {
                ((TShopWindowBase *)arg0)->display_shop_message(0x48, 1);
                sequence->set_field_20(0xD);
                sequence->choice_menu->close();
                sequence->choice_menu = NULL;
                *(s32 *)((s8 *)arg0 + 0x2C) = 0;
            }
            return;
        }
    }
}
#pragma pop

void TCheckRoomSequence::sub_802100F8() {  }
void TCheckRoomSequence::sub_802100FC() {  }
extern "C" {

#pragma push
#pragma optimization_level 1
void TCheckRoomSequence::close_window() {
    if ((vfunc_10() != 0) && ((sub_80223A48() != 0) || (sub_802239EC() != 0)) && (poll_memcard_result(((s8)TAdSinglePlyChrSelectGC::get_chr_select_state())) == 0)) {
        copy_bank_to_card_window(sub_8022397C());
        close_if_single_screen();
        TShopSequence::close_window();
        queue_destruction();
    }
}
#pragma pop

#pragma push
#pragma optimization_level 1
void open_bank__18TCheckRoomSequenceFv(u8 *sequence) {
    void *w;
    NJS_POINT2 v;
    v.x = 332.0f;
    v.y = 80.0f;
    ((TShopSequence *)sequence)->create_message_window((s32)(get_window_layout_position(0x2C)), (saddr)&v);
    ((TShopWindowBase *)sequence)->display_shop_message(0x31, 1);
    *(s32 *)((s8 *)sequence + 0x38) = (saddr)create_meseta_window((u16)((TShopSequence *)sequence)->get_child_field1c());
    *(void **)((s8 *)sequence + 0x40) = new TWindowDeposit((s16)((TShopSequence *)sequence)->get_child_field1c());
    TWindowMainMenu::set_entry_field_20(*(s32 *)((s8 *)sequence + 0x40), TCheckRoomSequence::get_room_data(((TShopWindowBase *)sequence)->sub_8022397C()));
    *(s32 *)((s8 *)sequence + 0x2C) = 0;
    *(s32 *)((s8 *)sequence + 0x48) = set_service_counter_camera(sequence, 6);
    ((TShopWindowBase *)sequence)->set_field_20(2);
}
#pragma pop

void TCheckRoomSequence::restore_player_state() {
    TShopSequence::restore_player_state();
    copy_bank_from_card_window(sub_8022397C());
    set_field_20(1);
}

void TCheckRoomSequence::vfunc_11() {
    static Fn_802102D0 fns[20] = {
        (Fn_802102D0)&TCheckRoomSequence::restore_player_state,
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
        (Fn_802102D0)&TCheckRoomSequence::close_window,
        (Fn_802102D0)&TCheckRoomSequence::accept_meseta_withdrawal,
        (Fn_802102D0)&TCheckRoomSequence::close_window,
        (Fn_802102D0)&TCheckRoomSequence::sub_802100FC,
        (Fn_802102D0)&TCheckRoomSequence::sub_802100F8,
        (Fn_802102D0)&TCheckRoomSequence::handle_error_ack,
        (Fn_802102D0)&TCheckRoomSequence::sub_8020F1DC,
        (Fn_802102D0)&TCheckRoomSequence::set_quest_list_mode_19,
        (Fn_802102D0)&TCheckRoomSequence::open_delete_item_window,
    };
    if (fns[state]) {
        (this->*fns[state])();
    }
}


#pragma push
#pragma optimization_level 1
TCheckRoomSequence::~TCheckRoomSequence() {
    if (counter_camera != NULL) {
        counter_camera->queue_destruction();
        counter_camera = NULL;
    }
    close_message_window();
    if (pad_34 != NULL) {
        pad_34->close();
        pad_34 = NULL;
    }
    if (deposit_window != NULL) {
        deposit_window->close();
        deposit_window = NULL;
    }
    if (meseta_window != NULL) {
        meseta_window->close();
        meseta_window = NULL;
    }
    if (choice_menu != NULL) {
        choice_menu->close();
        choice_menu = NULL;
    }
    close_window__18TCheckRoomSequenceFPv((TCheckRoomSequence_8020F070 *)this);
    TCheckRoomSequence__slot_active_flags[sub_8022397C()] = 0;
    if (pad_30 != 0) {
        TAdSinglePlyChrSelectGC::safe_free(pad_30);
        pad_30 = 0;
    }
}
#pragma pop

}

TCheckRoomSequence::TCheckRoomSequence(TObject *parent, TObjPlayer *player) : TShopSequence(parent) {
    m_name = TCheckRoomSequence__name;
    this->player = player;
    pad_34 = NULL;
    meseta_window = NULL;
    choice_menu = NULL;
    deposit_window = NULL;
    pad_44 = 0;
    counter_camera = NULL;
    pad_2c = 0;
    set_field_20(0);
    TCheckRoomSequence__active_instance = (saddr)this;
    pad_30 = 0;
    TCheckRoomSequence__slot_active_flags[sub_8022397C()] = 1;
}

extern "C" {

#pragma push
#pragma optimization_level 1
void TCheckRoomSequence::reset_slot_state() {
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
void TCheckRoomSequence::reset_slots() {
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
    if (TCheckRoomSequence::get_item_def((uaddr)item) == 0) {
        return 0;
    }
    for (i = 0; i < 200; i++) {
        if (((s32 (*)(u8 *))is_item_record_empty)((u8 *)&recs[i]) == 0 &&
            item->b0 == recs[i].b0 && item->b1 == recs[i].b1 &&
            item->b2 == recs[i].b2 && item->b4 == recs[i].b4) {
            return ((TItemData *)(&recs[i]))->get_max_stack_size() - recs[i].f14;
        }
    }
    if (((s32 (*)(s32))bank_has_free_row)(slot) == 0) {
        return 0;
    }
    return ((TItemData *)item)->get_max_stack_size();
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
    if (TCheckRoomSequence::get_item_def((uaddr)item) == 0) {
        return 0;
    }
    for (i = 0; i < 200; i++) {
        if (((s32 (*)(u8 *))is_item_record_empty)((u8 *)&recs[i]) == 0 &&
            item[0] == recs[i].b0 && item[1] == recs[i].b1 && item[2] == recs[i].b2) {
            recs[i].f14 += amount;
            if (recs[i].f14 > ((TItemData *)(&recs[i]))->get_max_stack_size()) {
                recs[i].f14 = ((TItemData *)(&recs[i]))->get_max_stack_size();
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
s32 TCheckRoomSequence__delete_bank_item(u8 *item, s32 slot) {
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
        } else if (TCheckRoomSequence::get_item_def((uaddr)(&recs[idx])) == 0) {
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
  saddr base = (saddr) bank_item_records_by_slot[slot];
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
    saddr r = ((s32 (*)(void *, void *))get_max_stack_size__9TItemDataFv)(data, t);
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
s32 store_item_in_bank(u8 *item, s32 amount, s32 slot) {
    Rec_80211034 *recs = bank_item_records_by_slot[slot];
    s32 i;
    if (TCheckRoomSequence__sub_80210B34(item, amount, slot) != 0) {
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
            move_data((void *)((w->items)), (const void *)(bank_item_records_by_slot[slot]), 0x12C0);
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
        move_data((void *)((bank_item_records_by_slot[slot])), (const void *)(w->items), 0x12C0);
    }
}
#pragma pop
extern "C" {

void mem_free(void *p);

#pragma push
#pragma optimization_level 1
void TCheckRoomSequence__free_bank_item_records(void) {
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
    ((TItemData *)self)->init();
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
    ((TItemData *)self)->init();
    self->a = 0;
    self->b = 0;
}
#pragma pop

void* TAdSinglePlyChrSelectGC__sub_802115C0(void* p) { ((TAdSinglePlyChrSelectGC *)p)->init_item_entry(); return p; }

void TShopWindowBase::display_shop_message(s32 id, s32 flags) {  }
}
