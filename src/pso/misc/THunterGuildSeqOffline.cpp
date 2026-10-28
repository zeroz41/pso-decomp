#include "types.h"
#include "pso/TShopWindowBase.h"
#include "pso/misc/TShopSequence.h"
#include "pso/misc/TUnk_804CDFE8.h"
#include "pso/misc/TWindowSubComCardList.h"
#include "pso/misc/THunterGuildSeqOffline.h"
#include "pso/misc/TWindowMenu.h"

struct Base_A_80212D9C { char pad[0x18]; };
struct V_A_80212D9C : Base_A_80212D9C {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void m7(int, int);
    virtual s32 m8();
};
struct Base_802136A4_80212e50_80212D9C { u8 pad[0x18]; };
struct VObj_802136A4_80212e50_80212D9C : Base_802136A4_80212e50_80212D9C {
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9(s32, s32);
    virtual s32 m10();
};
struct Base_802133C4_80212D9C { char pad[0x18]; };
struct VObj_802133C4_80212D9C : Base_802133C4_80212D9C {
    virtual void m0(); virtual void m1();
};
struct Base_802136A4_80212D9C { u8 pad[0x18]; };
struct VObj_802136A4_80212D9C : Base_802136A4_80212D9C {
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9(s32, s32);
    virtual s32 m10();
};

#include <stddef.h>
#include "pso/THunterGuildWarning.h"
#include "pso/TObject.h"
#include "pso/misc/TWindowSubComCard.h"
struct VBase_18_97738d { char pad[0x18]; };

struct VObj_18_97738d : VBase_18_97738d {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual s32 m7(s32, s32);
};

struct Stack_802130AC {
    f32 sp8;
    f32 spC;
};

struct RecoveredGlobal_80213220___vt__22THunterGuildSeqOffline { s32 value; u8 remaining[0x34]; };
typedef char RecoveredGlobal_80213220___vt__22THunterGuildSeqOffline_size[sizeof(RecoveredGlobal_80213220___vt__22THunterGuildSeqOffline) == 0x38 ? 1 : -1];

struct RecoveredGlobal_80213220_THunterGuildSeqOffline__data_80513DD8 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_80213220_THunterGuildSeqOffline__data_80513DD8_size[sizeof(RecoveredGlobal_80213220_THunterGuildSeqOffline__data_80513DD8) == 0x10 ? 1 : -1];

struct VBase_18_b54460 { char pad[0x18]; };

struct VObj_18_b54460 : VBase_18_b54460 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual s32 m7(s32, s32);
    virtual s32 m8();
};

struct RecoveredGlobal_80212F34_THunterGuildSeqOffline__data_80513DC8 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_80212F34_THunterGuildSeqOffline__data_80513DC8_size[sizeof(RecoveredGlobal_80212F34_THunterGuildSeqOffline__data_80513DC8) == 0x10 ? 1 : -1];

struct RecoveredGlobal_802132F0___vt__22THunterGuildSeqOffline {
    s32 value;
    u8 remaining[0x34];
};

struct RecoveredGlobal_802132F0_THunterGuildSeqOffline__data_80513DD8 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_8021354C_THunterGuildSeqOffline__data_80513DC8 {
    s32 value;
    u8 remaining[0xC];
};

struct Base_8021317C { u8 pad[0x18]; };

struct Guild_8021317C : Base_8021317C {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void m7(int, int);
    virtual s32 m8();
    virtual void m9();
    virtual void begin();
    virtual void finish();
    u32 unknown1c;
    u32 phase;
};

struct Base_A_80213474 { char pad[0x18]; };

struct V_A_80213474 : Base_A_80213474 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void m7(int, int);
    virtual s32 m8();
};

extern "C" {
s32 get_window_layout_position(s32);
s32 set_service_counter_camera(void *, int);
extern const f32 lbl_805DC650;
extern const f32 lbl_805DC654;
void queue_destruction__7TObjectFv(void *arg0);
void *__dt__13TShopSequenceFv(void *arg0, s16 arg1);
s32 sub_8022397C__15TShopWindowBaseFv(void *);
s32 __dl__7TObjectFPv(void *);
void TWindow__close(u8 *arg0);
extern RecoveredGlobal_80213220___vt__22THunterGuildSeqOffline __vt__22THunterGuildSeqOffline;
extern RecoveredGlobal_80213220_THunterGuildSeqOffline__data_80513DD8 THunterGuildSeqOffline__instance_table;
extern s32 THunterGuildSeqOffline__active_instance;
u8 *__dt__22THunterGuildSeqOfflineFv(u8 *arg0, s16 arg1);
int is_quest_active(void);
u8 *create_quest_thread(s32 arg0);
s32 get_register__12TQuestThreadFPvi(u8 *arg0, s32 arg1);
s32 sub_802239EC__13TShopSequenceFv(void *);
s32 sub_80223A48__15TShopWindowBaseFv(void *);
extern s32 THunterGuildSeqOffline__quest_result_callbacks[];
extern u8 *quest_mission_manager;
u8 *TShopSequence__ct(u8 *arg0);
extern s32 lbl_805D3658;
u8 *THunterGuildSeqOffline__ct(u8 *arg0, s32 arg1, s32 arg2);
s32 get_selected_menu_value(void *);
void THunterGuildSeqOffline__sub_8021339C(void);
u16 get_entity_id(s32);
void THunterGuildSeqOffline__sub_8021E180(void);
void close_window__13TShopSequenceFv(void *);
void *__nw__7TObjectFUl(u32);
extern u8 reset_random_enemies_mode[];
extern void *tl_00;
void THunterGuildSeqOffline__sub_80213474(void *arg0);
void THunterGuildSeqOffline__sub_80213410(void* p);
s32 THunterGuildSeqOffline__sub_80213458(void);
u8 *create_yes_no_window(s32 arg0, s32 arg1, u32 arg2, u32 arg3);
u32 create__12TQuestThreadFi(s32 arg0);
int fn_80223480(void*);
f32 get_scale__15TShopWindowBaseFv(void *);
int restore_player_state__13TShopSequenceFv(void*);

void THunterGuildSeqOffline::handle_select() {
    void *p = *(void * *)&this->m_34;
    if (p != NULL) {
        if (((TObject *)p)->all_parents_unqueued_for_destruction() != 1) {
            this->m_34 = 0U;
            goto block_3;
        }
    } else {
block_3:
        if ((this->vfunc_10() != 0) && ((sub_80223A48__15TShopWindowBaseFv(this) != 0) || (sub_802239EC__13TShopSequenceFv(this) != 0))) {
            ((V_A_80212D9C *) this)->m7(0xC, 1);
            *(s32 *)&this->unk_38 = 1;
            set_field_20((s32)((void*)(5)));
        }
    }
}

void THunterGuildSeqOffline::open_judgment_window() {

    if ((this->vfunc_10() != 0)
        && ((sub_80223A48__15TShopWindowBaseFv(this) != 0) || (sub_802239EC__13TShopSequenceFv(this) != 0))) {
        *(s32 *)&this->m_2c = (s32)create_yes_no_window(get_window_layout_position(0x2B), (u16)get_entity_id(this->m_24), 0, 0);
        ((TWindowSubComCardList *)(this->m_2c))->set_selected_index(1);
        ((TUnk_804CDFE8 *)(this->m_2c))->set_position_xy(get_scale__15TShopWindowBaseFv(this), get_scale__15TShopWindowBaseFv(this));
        ((VObj_802136A4_80212e50_80212D9C *)this)->m9(8, 1);
        set_field_20((s32)((void*)(6)));
    }
}

void THunterGuildSeqOffline::resolve_active_quest_result() {
    u8 *arg0 = (u8 *)this;
    if ((this->vfunc_10() != 0) && ((sub_80223A48__15TShopWindowBaseFv(arg0) != 0) || (sub_802239EC__13TShopSequenceFv(arg0) != 0))) {
        if (is_quest_active() == 1) {
            if (get_register__12TQuestThreadFPvi(quest_mission_manager, 0xFF) == 1) {
                ((VObj_18_b54460 *)(arg0))->m7(0xB, 1);
                if ((s32) *(s32 *)((s8 *)(&(*(RecoveredGlobal_80212F34_THunterGuildSeqOffline__data_80513DC8 *)&THunterGuildSeqOffline__quest_result_callbacks).value) + 4) != -1) {
                    this->m_34 = (s32)create_quest_thread(*(s32 *)((s8 *)(&(*(RecoveredGlobal_80212F34_THunterGuildSeqOffline__data_80513DC8 *)&THunterGuildSeqOffline__quest_result_callbacks).value) + 4));
                }
                ((TShopWindowBase *)arg0)->set_field_20((s32)((void*)(7)));
                return;
            }
            if (get_register__12TQuestThreadFPvi(quest_mission_manager, 0xFD) == 1) {
                ((VObj_18_b54460 *)(arg0))->m7(0x12, 1);
                if ((s32) *(s32 *)((s8 *)(&(*(RecoveredGlobal_80212F34_THunterGuildSeqOffline__data_80513DC8 *)&THunterGuildSeqOffline__quest_result_callbacks).value) + 0) != -1) {
                    this->m_34 = (s32)create_quest_thread(*(s32 *)((s8 *)(&(*(RecoveredGlobal_80212F34_THunterGuildSeqOffline__data_80513DC8 *)&THunterGuildSeqOffline__quest_result_callbacks).value) + 0));
                }
                ((TShopWindowBase *)arg0)->set_field_20((s32)((void*)(8)));
                return;
            }
            ((VObj_18_b54460 *)(arg0))->m7(2, 1);
            ((TShopWindowBase *)arg0)->set_field_20((s32)((void*)(3)));
            return;
        }
        ((VObj_18_b54460 *)(arg0))->m7(4, 1);
        ((TShopWindowBase *)arg0)->set_field_20((s32)((void*)(4)));
    }
}

void THunterGuildSeqOffline::open_greeting() {
    u8 *arg0 = (u8 *)this;
    typedef char sp8_offset[(offsetof(Stack_802130AC, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_802130AC, spC) == 0x4) ? 1 : -1];
    Stack_802130AC stack;
    stack.sp8 = lbl_805DC650;
    stack.spC = lbl_805DC654;
    ((TShopSequence *)arg0)->create_message_window((s32)((int) (((u8 *)get_window_layout_position(0x2C)))), (s32)&stack.sp8);
    ((VObj_18_97738d *)(arg0))->m7(1, 1);
    *(s32 *)((s8 *)arg0 + 0x30) = set_service_counter_camera(arg0, 1);
    ((TShopWindowBase *)arg0)->set_field_20((s32)((void*)(2)));
}

void THunterGuildSeqOffline::restore_player_state() { restore_player_state__13TShopSequenceFv(this); fn_80223480(this); THunterGuildWarning::create_instance((s32)((void*)2)); set_field_20((s32)((void*)((void*)1))); }

void THunterGuildSeqOffline::vfunc_11() {
    Guild_8021317C *self = (Guild_8021317C *)this;
    switch (self->phase) {
    case 0: self->begin(); break;
    case 1: ((THunterGuildSeqOffline *)self)->open_greeting(); break;
    case 2: ((THunterGuildSeqOffline *)self)->resolve_active_quest_result(); break;
    case 3: ((THunterGuildSeqOffline *)self)->open_judgment_window(); break;
    case 4: ((THunterGuildSeqOffline *)self)->open_quest_list(); break;
    case 5: self->finish(); break;
    case 6: ((THunterGuildSeqOffline *)self)->handle_cancel_choice(); break;
    case 7: ((THunterGuildSeqOffline *)self)->handle_select(); break;
    case 8: ((THunterGuildSeqOffline *)self)->handle_window_input(); break;
    case 9: ((THunterGuildSeqOffline *)self)->handle_click(); break;
    case 10: break;
    }
}

u8 *__dt__22THunterGuildSeqOfflineFv(u8 *arg0, s16 arg1) {
    u32 temp_r3;
    u32 temp_r3_2;
    u32 temp_r3_3;
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = &__vt__22THunterGuildSeqOffline.value;
        temp_r3 = *(u32 *)((s8 *)arg0 + 0x30);
        if (temp_r3 != 0U) {
            queue_destruction__7TObjectFv((void *)temp_r3);
            *(u32 *)((s8 *)arg0 + 0x30) = 0U;
        }
        ((TShopSequence *)arg0)->close_message_window();
        temp_r3_2 = *(u32 *)((s8 *)arg0 + 0x2C);
        if (temp_r3_2 != 0U) {
            TWindow__close((u8 *)temp_r3_2);
            *(u32 *)((s8 *)arg0 + 0x2C) = 0U;
        }
        temp_r3_3 = ((THunterGuildSeqOffline *)arg0)->m_34;
        if (temp_r3_3 != 0U) {
            queue_destruction__7TObjectFv((void *)temp_r3_3);
            ((THunterGuildSeqOffline *)arg0)->m_34 = 0U;
        }
        *(s32 *)((s8 *)&THunterGuildSeqOffline__instance_table.value + (sub_8022397C__15TShopWindowBaseFv(arg0) * 4)) = 0;
        THunterGuildSeqOffline__active_instance = 0;
        __dt__13TShopSequenceFv((arg0), 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

typedef char RecoveredGlobal_802132F0___vt__22THunterGuildSeqOffline_size[sizeof(RecoveredGlobal_802132F0___vt__22THunterGuildSeqOffline) == 0x38 ? 1 : -1];
typedef char RecoveredGlobal_802132F0_THunterGuildSeqOffline__data_80513DD8_size[sizeof(RecoveredGlobal_802132F0_THunterGuildSeqOffline__data_80513DD8) == 0x10 ? 1 : -1];
u8 *THunterGuildSeqOffline__ct(u8 *hunter_guild_seq_offline, s32 arg1, s32 arg2) {
    TShopSequence__ct((hunter_guild_seq_offline));
    *(s32 **)((s8 *)hunter_guild_seq_offline + 0x18) = &(*(RecoveredGlobal_802132F0___vt__22THunterGuildSeqOffline *)&__vt__22THunterGuildSeqOffline).value;
    *(s32 *)((s8 *)hunter_guild_seq_offline + 0) = (s32) lbl_805D3658;
    *(s32 *)((s8 *)hunter_guild_seq_offline + 0x20) = 0;
    *(s32 *)((s8 *)hunter_guild_seq_offline + 0x2C) = 0;
    ((THunterGuildSeqOffline *)hunter_guild_seq_offline)->m_24 = arg2;
    *(s32 *)((s8 *)hunter_guild_seq_offline + 0x30) = 0;
    ((THunterGuildSeqOffline *)hunter_guild_seq_offline)->m_34 = 0;
    *(s32 *)((s8 *)hunter_guild_seq_offline + 0x38) = 0;
    (*(u8 * *)&THunterGuildSeqOffline__active_instance) = hunter_guild_seq_offline;
    *(s32 *)((s8 *)(&(*(RecoveredGlobal_802132F0_THunterGuildSeqOffline__data_80513DD8 *)&THunterGuildSeqOffline__instance_table).value) + (sub_8022397C__15TShopWindowBaseFv(hunter_guild_seq_offline) * 4)) = 1;
    return hunter_guild_seq_offline;
}

void THunterGuildSeqOffline::clear_instance_table() {
    s32 i;
    for (i = 0; i < 4; i++) ((s32 *)&THunterGuildSeqOffline__instance_table)[i] = 0;
}

void THunterGuildSeqOffline__sub_8021339C(void) {
    s32 i;
    for (i = 0; i < 4; i++) ((s32 *)&THunterGuildSeqOffline__instance_table)[i] = 0;
}

void THunterGuildSeqOffline::notify_quest_thread() {
    s32 v = THunterGuildSeqOffline__quest_result_callbacks[3];
    if (v != -1) {
        void *obj = (void *)create__12TQuestThreadFi(v);
        if (obj != NULL) {
            ((VObj_802133C4_80212D9C *)obj)->m1();
        }
    }
}

void THunterGuildSeqOffline__sub_80213410(void* p) { THunterGuildSeqOffline::reset_quest_result_callbacks(p); }

extern void *hunter_guild_seq_online_client_instance;

void THunterGuildSeqOffline::reset_quest_result_callbacks(void* _w0) {
    s32 i;
    for (i = 0; i < 4; i++) THunterGuildSeqOffline__quest_result_callbacks[i] = -1;
}

s32 THunterGuildSeqOffline__sub_80213458(void) {
    if ((void *) hunter_guild_seq_online_client_instance != NULL) {
        return *(s32 *)((s8 *)hunter_guild_seq_online_client_instance + 0x20);
    }
    return -1;
}

typedef char RecoveredGlobal_8021354C_THunterGuildSeqOffline__data_80513DC8_size[sizeof(RecoveredGlobal_8021354C_THunterGuildSeqOffline__data_80513DC8) == 0x10 ? 1 : -1];

void THunterGuildSeqOffline__sub_80213474(void *shop_sequence) {
    void *p = *(void **)((s8 *)shop_sequence + 0x38);
    if (p != NULL) {
        if (((TObject *)p)->all_parents_unqueued_for_destruction() != 0) {
            return;
        }
        *(u32 *)((s8 *)shop_sequence + 0x38) = 0U;
    }
    if ((((V_A_80213474 *) shop_sequence)->m8() != 0) && ((sub_80223A48__15TShopWindowBaseFv(shop_sequence) != 0) || (sub_802239EC__13TShopSequenceFv(shop_sequence) != 0))) {
        switch (*(s32 *)((s8 *)shop_sequence + 0x34)) {
        case 1: {
            void *o = __nw__7TObjectFUl(0x28);
            if (o != NULL) {
                ((THunterGuildSeqOffline *)o)->init(tl_00, reset_random_enemies_mode);
            }
            get_entity_id(*(s32 *)((s8 *)shop_sequence + 0x24));
            THunterGuildSeqOffline__sub_8021E180();
            break;
        }
        case 0:
            break;
        case 2:
            break;
        }
        close_window__13TShopSequenceFv(shop_sequence);
        queue_destruction__7TObjectFv(shop_sequence);
    }
}

void THunterGuildSeqOffline::handle_confirm_window() {
    u8 *arg0 = (u8 *)this;
    s32 selected_menu_value;
    u8 *window_menu;
    u8 *window_sub_com_card;
    window_menu = (u8 *)(*(u8 **)((s8 *)arg0 + 0x3C));
    if ((window_menu != NULL) && (((TWindowMenu *)window_menu)->is_visible() != 0)) {
        selected_menu_value = get_selected_menu_value(*(u8 **)((s8 *)arg0 + 0x3C));
        switch (selected_menu_value) {
        case 0:
            TWindow__close((*(u8 **)((s8 *)arg0 + 0x3C)));
            *(u8 **)((s8 *)arg0 + 0x3C) = NULL;
            ((VObj_18_97738d *)(arg0))->m7(9, 1);
            this->m_34 = 1;
            if ((s32) *(s32 *)((s8 *)(&(*(RecoveredGlobal_8021354C_THunterGuildSeqOffline__data_80513DC8 *)&THunterGuildSeqOffline__quest_result_callbacks).value) + 8) != -1) {
                *(s32 *)&this->unk_38 = (s32)create_quest_thread(*(s32 *)((s8 *)(&(*(RecoveredGlobal_8021354C_THunterGuildSeqOffline__data_80513DC8 *)&THunterGuildSeqOffline__quest_result_callbacks).value) + 8));
            }
            ((TShopWindowBase *)arg0)->set_field_20((s32)((void*)(0xC)));
            break;
        case 1:
            TWindow__close((*(u8 **)((s8 *)arg0 + 0x3C)));
            *(u8 **)((s8 *)arg0 + 0x3C) = NULL;
            ((VObj_18_97738d *)(arg0))->m7(0xA, 1);
            this->m_34 = 0;
            ((TShopWindowBase *)arg0)->set_field_20((s32)((void*)(0xC)));
            break;
        }
    }
    window_sub_com_card = (u8 *)(*(u8 **)((s8 *)arg0 + 0x3C));
    if ((window_sub_com_card != NULL) && (((TWindowSubComCard *)window_sub_com_card)->get_status_flag() != 0)) {
        TWindow__close((*(u8 **)((s8 *)arg0 + 0x3C)));
        *(u8 **)((s8 *)arg0 + 0x3C) = NULL;
        ((VObj_18_97738d *)(arg0))->m7(0xA, 1);
        this->m_34 = 0;
        ((TShopWindowBase *)arg0)->set_field_20((s32)((void*)(0xC)));
    }
}

void THunterGuildSeqOffline::open_judgment_item_window() {

    if ((this->vfunc_10() != 0)
        && ((sub_80223A48__15TShopWindowBaseFv(this) != 0) || (sub_802239EC__13TShopSequenceFv(this) != 0))) {
        *(s32 *)((s8 *)this + 0x3C) = (s32)create_yes_no_window(get_window_layout_position(0x2B), (u16)get_entity_id(this->m_24), 0, 0);
        ((TWindowSubComCardList *)(*(s32 *)((s8 *)this + 0x3C)))->set_selected_index(1);
        ((TUnk_804CDFE8 *)(*(s32 *)((s8 *)this + 0x3C)))->set_position_xy(get_scale__15TShopWindowBaseFv(this), get_scale__15TShopWindowBaseFv(this));
        ((VObj_802136A4_80212D9C *)this)->m9(8, 1);
        set_field_20((s32)((void*)(7)));
    }
}

}
