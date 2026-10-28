#include "pso/misc/TMedicalCenterMes.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/TShopWindowBase.h"
#include "pso/misc/TUnk_804CDFE8.h"
#include "pso/misc/TShopSequence.h"
#include "pso/misc/TMedicalCenterSequence.h"
#include "pso/misc/TWindowMenu.h"
#include "pso/player/TObjPlayer.h"
#include "types.h"

struct TMedicalCenterMesMessagePos { s32 x; s32 y; };

extern "C" {
s32 TShopGenerator__sub_80222DAC(s32);
s32 get_entity_id(s32);
void *get_player_by_client_id(s32);
void THunterGuildSeqOffline__sub_8021E180(s32);
s32 get_window_layout_position(int, f32);
s32 TWindowShortListCtrl__check_controller_button(void *, s32);
void queue_destruction__7TObjectFv(void *arg0);
void TMedicalCenterMes__sub_80216260(void);

extern const char *TMedicalCenterMes__class_name;
extern s32 TMedicalCenterMes__slot_flags[4];
extern TMedicalCenterMesMessagePos lbl_8044BD94[];
extern s32 local_client_id;
}

struct TMedicalCenterMesInput { u8 pad[0x20]; u8 buttons[0x30]; };
TMedicalCenterMesInput controller_input_state[];

#include "pso/misc/TShopGenerator.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/misc/TWindowSubComCard.h"

struct Base_8021641C_802163AC { char pad[0x18]; };
struct VObj_8021641C_802163AC : Base_8021641C_802163AC {
    virtual int m0();
    virtual int m1();
    virtual int m2();
    virtual int m3();
    virtual int m4(int, int);
    virtual int m5();
    virtual int m6();
    virtual int m7();
    virtual int m8();
};
struct Base_802165D8_802163AC { char pad[0x18]; };
struct VObj_802165D8_802163AC : Base_802165D8_802163AC {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(s32, s32);
};
struct Base_80216784_802163AC { char pad[0x18]; };
struct VObj_80216784_802163AC : Base_80216784_802163AC {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual int m8();
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

struct Stack_80216830
{
  f32 sp8;
  f32 spC;
};

struct RecoveredGlobal_802169A8___vt__22TMedicalCenterSequence {
    s32 value;
    u8 remaining[0x34];
};

struct RecoveredGlobal_802169A8_TMedicalCenterSequence__data_80513E90 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_80216A70___vt__22TMedicalCenterSequence {
    s32 value;
    u8 remaining[0x34];
};

struct RecoveredGlobal_80216A70_TMedicalCenterSequence__data_80513E90 {
    s32 value;
    u8 remaining[0xC];
};

struct Base_802164A4 { char pad[0x18]; };

struct VObj_802164A4 : Base_802164A4 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(s32, s32);
    char pad2[0x24 - 0x1C];
    s32 f24;
    char pad3[0x30 - 0x28];
    s32 f30;
};

struct Base_80216540 { char pad[0x18]; };

struct VObj_80216540 : Base_80216540 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(s32, s32);
};

struct Base_8021658C { char pad[0x18]; };

struct VObj_8021658C : Base_8021658C {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(s32, s32);
};

extern "C" {
s32 create_meseta_window(unsigned short);
s32 set_service_counter_camera(void *, int);
extern const f32 lbl_805DC688;
extern const f32 lbl_805DC68C;
void *__dt__13TShopSequenceFv(void *arg0, s16 arg1);
s32 sub_8022397C__15TShopWindowBaseFv(void *);
s32 __dl__7TObjectFPv(void *);
void TWindow__close(u8 *arg0);
extern RecoveredGlobal_802169A8___vt__22TMedicalCenterSequence __vt__22TMedicalCenterSequence;
extern RecoveredGlobal_802169A8_TMedicalCenterSequence__data_80513E90 TMedicalCenterSequence__data_80513E90;
u8 *__dt__22TMedicalCenterSequenceFv(TMedicalCenterSequence *arg0, s16 arg1);
u8 *TShopSequence__ct(u8 *arg0);
extern s32 TMedicalCenterSequence__class_name;
u8 *TMedicalCenterSequence__ct(u8 *arg0, s32 arg1, s32 arg2);
f32 get_scale__15TShopWindowBaseFv(void *);
u8 *create_yes_no_window(s32 arg0, s32 arg1, u32 arg2, u32 arg3);
s32 play_sound_effect(s32, s32, s32, s32);
s32 try_spend_actor_meseta(u8 *arg0, s32 arg1);
int sub_802239EC__13TShopSequenceFv(void *);
int sub_80223A48__15TShopWindowBaseFv(void *);
s32 get_selected_menu_value(u32);
s32 close_window__13TShopSequenceFv(void *);
int obj_getPtr2B0_20(u8 *p);
int restore_player_state__13TShopSequenceFv(void*);
void send_code50_packet__10TObjPlayerFi(s32 arg0);
void send_code_49_1__10TObjPlayerFi(s32 arg0);

void TMedicalCenterSequence::clear_window_slots() {
    s32 i;
    for (i = 0; i < 4; i++) {
        ((s32 *)&TMedicalCenterSequence__data_80513E90)[i] = 0;
    }
}

void TMedicalCenterSequence::clear_slot_data() {
    s32 i;
    for (i = 0; i < 4; i++) {
        ((s32 *)&TMedicalCenterSequence__data_80513E90)[i] = 0;
    }
}

typedef char RecoveredGlobal_80216A70___vt__22TMedicalCenterSequence_size[sizeof(RecoveredGlobal_80216A70___vt__22TMedicalCenterSequence) == 0x38 ? 1 : -1];
typedef char RecoveredGlobal_80216A70_TMedicalCenterSequence__data_80513E90_size[sizeof(RecoveredGlobal_80216A70_TMedicalCenterSequence__data_80513E90) == 0x10 ? 1 : -1];
u8 *TMedicalCenterSequence__ct(u8 *medical_center_sequence, s32 arg1, s32 arg2) {
    TShopSequence__ct((medical_center_sequence));
    *(s32 **)((s8 *)medical_center_sequence + 0x18) = &(*(RecoveredGlobal_80216A70___vt__22TMedicalCenterSequence *)&__vt__22TMedicalCenterSequence).value;
    *(s32 *)((s8 *)medical_center_sequence + 0) = (s32) TMedicalCenterSequence__class_name;
    ((TMedicalCenterSequence *)medical_center_sequence)->m_20 = 0;
    *(s32 *)((s8 *)medical_center_sequence + 0x24) = arg2;
    ((TMedicalCenterSequence *)medical_center_sequence)->m_2c = 0;
    ((TMedicalCenterSequence *)medical_center_sequence)->m_30 = 0;
    *(s32 *)((s8 *)medical_center_sequence + 0x34) = 0;
    *(s32 *)((s8 *)(&(*(RecoveredGlobal_80216A70_TMedicalCenterSequence__data_80513E90 *)&TMedicalCenterSequence__data_80513E90).value) + (sub_8022397C__15TShopWindowBaseFv(medical_center_sequence) * 4)) = 1;
    return medical_center_sequence;
}

u8 *__dt__22TMedicalCenterSequenceFv(TMedicalCenterSequence *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = &__vt__22TMedicalCenterSequence.value;
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
        *(s32 *)((s8 *)&TMedicalCenterSequence__data_80513E90.value + (sub_8022397C__15TShopWindowBaseFv(arg0) * 4)) = 0;
        __dt__13TShopSequenceFv((arg0), 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return (u8 *)arg0;
}

typedef char RecoveredGlobal_802169A8___vt__22TMedicalCenterSequence_size[sizeof(RecoveredGlobal_802169A8___vt__22TMedicalCenterSequence) == 0x38 ? 1 : -1];
typedef char RecoveredGlobal_802169A8_TMedicalCenterSequence__data_80513E90_size[sizeof(RecoveredGlobal_802169A8_TMedicalCenterSequence__data_80513E90) == 0x10 ? 1 : -1];

void TMedicalCenterSequence::vfunc_11() {
    u8 *arg0 = (u8 *)this;
    switch (this->m_20) {
    case 0:
        this->restore_player_state();
        return;
    case 1:
        ((TMedicalCenterSequence *)arg0)->open_greeting_window();
        return;
    case 2:
        ((TMedicalCenterSequence *)arg0)->handle_confirm();
        return;
    case 6:
        ((TMedicalCenterSequence *)arg0)->show_already_healthy();
        return;
    case 7:
        ((TMedicalCenterSequence *)arg0)->show_fee_prompt();
        return;
    case 3:
        ((TMedicalCenterSequence *)arg0)->handle_window_result();
        return;
    case 4:
        ((TMedicalCenterSequence *)arg0)->exec_heal();
        return;
    case 5:
        ((TMedicalCenterSequence *)arg0)->show_declined();
        return;
    case 8:
        ((TMedicalCenterSequence *)arg0)->handle_window_input();
        return;
    case 10:
        this->close_window();
    default:
        return;
    }
}

void TMedicalCenterSequence::restore_player_state() { restore_player_state__13TShopSequenceFv(this); set_field_20((s32)((void*)((void*)1))); }

typedef struct Stack_80216830 Stack_80216830;
typedef struct VBase_18_a93f07 VBase_18_a93f07;
typedef struct VObj_18_a93f07 VObj_18_a93f07;
s32 TMedicalCenterSequence::open_greeting_window() {
    u8 *arg0 = (u8 *)this;
  Stack_80216830 stack;
  stack.sp8 = lbl_805DC688;
  stack.spC = lbl_805DC68C;
  ((TShopSequence *)arg0)->create_message_window(get_window_layout_position(0x2C, (f32) lbl_805DC688), (s32)&stack.sp8);
  (((VObj_18_a93f07 *)(arg0))->m4(0x1F, 1));
  this->m_2c = create_meseta_window((s32) ((TShopSequence *)arg0)->get_child_field1c());
  ((TShopWindowBase *)arg0)->set_field_20((s32)((void*)(2)));
  *((s32 *) (((s8 *) arg0) + 0x34)) = set_service_counter_camera((void *) arg0, 0);
}

void TMedicalCenterSequence::handle_confirm() {
    struct VObj_80216784_802163AC *o = (struct VObj_80216784_802163AC *)this;
    if ((o->m8() != 0) && ((sub_80223A48__15TShopWindowBaseFv(this) != 0) || (sub_802239EC__13TShopSequenceFv(this) != 0))) {
        if ((((TObjPlayer *)(*(s32 *)((s8 *)this + 0x24)))->get_recovery_need_flags() != 0U) || ((((TObjPlayer *)(*(s32 *)((s8 *)this + 0x24)))->is_alive_and_ready() != 0) && (((TObjPlayer *)(*(s32 *)((s8 *)this + 0x24)))->are_traps_full() == 0))) {
            set_field_20((s32)((void*)(7)));
            return;
        }
        set_field_20((s32)((void*)(6)));
    }
}

void TMedicalCenterSequence::handle_window_result() {
    s32 selected_menu_value;

    if (((u32) this->m_30 != 0U) && (((TWindowMenu *)((u32) this->m_30))->is_visible() != 0)) {
        selected_menu_value = get_selected_menu_value(this->m_30);
        if (selected_menu_value == 0) {
            TWindow__close((u8 *)this->m_30);
            this->m_30 = 0U;
            set_field_20((s32)((void*)(4)));
            return;
        }
        if (selected_menu_value == 1) {
            TWindow__close((u8 *)this->m_30);
            this->m_30 = 0U;
            set_field_20((s32)((void*)(5)));
            return;
        }
        goto block_6;
    }
block_6:
    if (((u32) this->m_30 != 0U) && (((TWindowSubComCard *)((u32) this->m_30))->get_status_flag() != 0)) {
        TWindow__close((u8 *)this->m_30);
        this->m_30 = 0U;
        set_field_20((s32)((void*)(5)));
    }
}

void TMedicalCenterSequence::exec_heal() {
    if (obj_getPtr2B0_20((u8 *)(*(s32 *)((s8 *)this + 0x24))) < 0xA) {
        ((VObj_802165D8_802163AC *)this)->m4(0xF, 1);
        set_field_20((s32)((void*)(0xA)));
        return;
    }
    play_sound_effect(0x42D08, 0, 0, 0);
    send_code_49_1__10TObjPlayerFi(*(s32 *)((s8 *)this + 0x24));
    send_code50_packet__10TObjPlayerFi(*(s32 *)((s8 *)this + 0x24));
    if (((TObjPlayer *)(*(s32 *)((s8 *)this + 0x24)))->is_alive_and_ready() != 0) {
        ((TObjPlayer *)(*(s32 *)((s8 *)this + 0x24)))->refill_traps();
    }
    ((TObjPlayer *)(*(s32 *)((s8 *)this + 0x24)))->send_field_state();
    try_spend_actor_meseta((u8 *)(*(s32 *)((s8 *)this + 0x24)), 0xA);
    ((VObj_802165D8_802163AC *)this)->m4(0x22, 1);
    set_field_20((s32)((void*)(0xA)));
}

void TMedicalCenterSequence::show_declined() {
    VObj_8021658C *self = (VObj_8021658C *)this;
    self->m4(0x24, 1);
    ((TShopWindowBase *)self)->set_field_20((s32)((void *)8));
}

void TMedicalCenterSequence::show_already_healthy() {
    VObj_80216540 *self = (VObj_80216540 *)this;
    self->m4(0x21, 1);
    ((TShopWindowBase *)self)->set_field_20((s32)((void *)8));
}

void TMedicalCenterSequence::show_fee_prompt() {
    u16 v;
    ((VObj_802164A4 *)this)->m4(0x20, 1);
    v = get_entity_id(((VObj_802164A4 *)this)->f24);
    ((VObj_802164A4 *)this)->f30 = (s32)create_yes_no_window(((s32 (*)(int))get_window_layout_position)(0x2B), v, 0, 0);
    ((TUnk_804CDFE8 *)(((VObj_802164A4 *)this)->f30))->set_position_xy(get_scale__15TShopWindowBaseFv(((VObj_802164A4 *)this)), get_scale__15TShopWindowBaseFv(((VObj_802164A4 *)this)));
    this->set_field_20((s32)((void *)3));
}

s32 TMedicalCenterSequence::handle_window_input() {
    VObj_8021641C_802163AC *o = (VObj_8021641C_802163AC *)this;
    if (o->m8() != 0 && (sub_80223A48__15TShopWindowBaseFv(this) != 0 || sub_802239EC__13TShopSequenceFv(this) != 0)) {
        o->m4(0x22, 1);
        set_field_20((s32)((void*)(0xa)));
    }
}

void TMedicalCenterSequence::close_window() {
    if ((this->vfunc_10() != 0) && ((sub_80223A48__15TShopWindowBaseFv(this) != 0) || (sub_802239EC__13TShopSequenceFv(this) != 0))) {
        close_window__13TShopSequenceFv(this);
        queue_destruction__7TObjectFv(this);
    }
}
}

TMedicalCenterMes::TMedicalCenterMes(TObject *parent, TObjPlayer *player) : TObject(parent) {
    m_name = TMedicalCenterMes__class_name;
    state = 0;
    this->player = player;
    if (this->player != NULL) {
        s32 slot = TShopGenerator__sub_80222DAC(get_entity_id((s32)this->player));
        TMedicalCenterMes__slot_flags[(u16)slot] = 1;
    }
}

TMedicalCenterMes::~TMedicalCenterMes() {
    if (player != NULL) {
        s32 slot = TShopGenerator__sub_80222DAC(get_entity_id((s32)player));
        TMedicalCenterMes__slot_flags[(u16)slot] = 0;
    }
}

void TMedicalCenterMes__sub_80216260(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        TMedicalCenterMes__slot_flags[i] = 0;
    }
}

void TMedicalCenterMes::clear_slot_flags() {
    s32 i;
    for (i = 0; i < 4; i++) {
        TMedicalCenterMes__slot_flags[i] = 0;
    }
}

void TMedicalCenterMes::run_task() {
    switch (state) {
    case 0: {
        if (player == NULL) {
            player = (TObjPlayer *)get_player_by_client_id(local_client_id);
        }
        THunterGuildSeqOffline__sub_8021E180(get_entity_id((s32)player));
        ((TWindowCtrl *)((u16)get_entity_id((s32)player)))->suppress_slot();
        TMedicalCenterMesMessagePos pos = lbl_8044BD94[0];
        u16 id = (u16)get_entity_id((s32)player);
        create_message_window(((s32 (*)(int))get_window_layout_position)(0x2C), (s32)&pos, id);
        format_shop_message(0x25, 1);
        if (player != NULL) {
            ((TObjPlayer *)player)->init_effect_5f0();
        }
        state = 1;
        break;
    }
    case 1:
        if (is_ready() != 0 && player != NULL) {
            if (TWindowShortListCtrl__check_controller_button(controller_input_state[((TRaderMapCore *)player)->get_map_id()].buttons, 4) != 0) {
                state = 2;
            }
        }
        break;
    case 2:
        if (player != NULL) {
            TObjPlayer::clear_lobby_flag(player);
        }
        close();
        if (player != NULL) {
            ((TWindowCtrl *)((u16)get_entity_id((s32)player)))->unsuppress_slot();
        }
        TShopGenerator::clear_slot_active(get_entity_id((s32)player));
        queue_destruction__7TObjectFv(this);
        break;
    }
}
s32 TMedicalCenterMes::get_slot_flag(int client) {
    return TMedicalCenterMes__slot_flags[(u16)TShopGenerator__sub_80222DAC(client)];
}
