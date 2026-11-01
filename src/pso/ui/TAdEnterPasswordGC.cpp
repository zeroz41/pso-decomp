#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/ui/TAdEnterBaseGC_8032B38C.h"
#include "pso/ui/TAdEnterPasswordGC.h"
#include "pso/TLevelSelect.h"
#include "pso/TMainTask.h"
#include "pso/TObject.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/ui/TAdEnterBaseGC.h"
#include "pso/ui/TAdEnterSerialAccessGC.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/TAdSnAkPassConfirmGC.h"
#include "pso/quest/TQuestThread.h"

struct Elt80364258_80364258 { s32 f0; };

struct RecoveredGlobal_8032B904_lbl_80477278 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_8032B904_lbl_80477278_size[sizeof(RecoveredGlobal_8032B904_lbl_80477278) == 0x10 ? 1 : -1];

struct RecoveredGlobal_8032BA8C_TAdEnterPasswordGC__data_804EDA20 {
    char value;
    u8 remaining[8];
};

struct RecoveredGlobal_8032BB34___vt__18TAdEnterPasswordGC {
    s32 value;
    u8 remaining[0x18];
};

struct T_8032BBF0 { u8 pad[0x20]; s32 arr[24]; s32 count; };

struct B_8032BC1C { u8 pad[0x18]; };

struct VObj_8032BC1C : B_8032BC1C {
    virtual void m0();
    virtual void m1();
    virtual void m2();
};

struct O_8032BC1C { u8 pad[0x20]; VObj_8032BC1C *items[1]; };

struct O2_8032BC1C { u8 pad[0x80]; s32 n; };

struct Pw_8032B6A0
{
  u8 pad0[0x20];
  s32 f20;
  u8 pad24[0x2C - 0x24];
  u32 serial;
  u8 pad30[0x38 - 0x30];
  s32 f38;
  s32 f3C;
  s32 len;
};

struct TAdEnterPasswordGC {
    virtual void m0();
    char pad[0x18];
    s32 state;
    s32 f20;
    s32 f24;
    void open_keyboard_window(void *);
    void update_password_input(void *);
    void request_transition(void *);
    void set_multi_chg_game_mode_0x14(void *);
    void close_window_and_destroy(void *);
};
typedef TAdEnterPasswordGC TAdEnterPasswordGC_8032B984;
typedef void (TAdEnterPasswordGC_8032B984::*Pmf_8032B984)();

extern "C" {
extern TAdEnterBaseGC::Position password_screen_status_line_position[];
extern s32 password_entry_dispatch_state;
#pragma explicit_zero_data on
RecoveredGlobal_8032BA8C_TAdEnterPasswordGC__data_804EDA20 TAdEnterPasswordGC__input_buffer = { 0 };
#pragma explicit_zero_data off
void queue_destruction__7TObjectFv(void *);
extern u8 *password_entry_keyboard_control;
extern const f32 lbl_805DF780;
s32 create_default_callback__22TAdEnterSerialAccessGCFv(void *);
extern RecoveredGlobal_8032B904_lbl_80477278 enter_password_item_rect_table;
void strncpy(s32, s32, s32);
s32 memset(void *, int, int);
extern RecoveredGlobal_8032BA8C_TAdEnterPasswordGC__data_804EDA20 TAdEnterPasswordGC__input_buffer;
void TKeyBoardControl__sub_8000F9CC(s32 arg0);
u32 __nw__7TObjectFUl(int);
s32 __ct__10TAdTitleGCFP7TObjectl(int, void *, int);
extern s32 __vt__18TAdEnterPasswordGC[];
extern s32 TAdEnterPasswordGC__class_name;
void clear_password__18TAdEnterPasswordGCFPv(T_8032BBF0 *self);
void update_children__18TAdEnterPasswordGCFPv(O_8032BC1C *arg0);
void mem_free(void *p);
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, int);
s32 TWindowShortListCtrl__check_controller_button(void *, int);
s32 get_field_118__22TAdEnterSerialAccessGCFv(void);
s32 play_sound_effect(int, int, int, int);
s32 forward_input__22TAdEnterSerialAccessGCFPv(void *, int, s32);
s32 strlen(s32);
extern u8 controller_input_state[];
extern u8 controller_physical_port_bank[];
void update_password_input__18TAdEnterPasswordGCFPv(Pw_8032B6A0 *self);
void __dl__7TObjectFPv(void *);
void *__dt__14TAdEnterBaseGCFv(void *arg0, s16 arg1);
int request_transition__21TAdMultiChgGameModeGCFv(void*);
int set_mode_0x14__21TAdMultiChgGameModeGCFv(void*);

void render__18TAdEnterPasswordGCFv(void *self) {
    if (TMainTask::get_render_pass() == 1) { return;
    }
}

void close_window_and_destroy__18TAdEnterPasswordGCFPv(u8 *arg0) {
    s32 temp_r4;
    u8 *temp_r3;
    u8 *temp_r3_2;
    temp_r3 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x30));
    if (temp_r3 != NULL) {
        ((TWindowBase *)temp_r3)->close();
        *(u8 **)((s8 *)arg0 + 0x30) = NULL;
    }
    temp_r3_2 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x34));
    if (temp_r3_2 != NULL) {
        ((TWindowBase *)temp_r3_2)->close();
        *(u8 **)((s8 *)arg0 + 0x34) = NULL;
    }
    if ((void *) password_entry_keyboard_control != NULL) {
        queue_destruction__7TObjectFv(password_entry_keyboard_control);
        password_entry_keyboard_control = NULL;
    }
    temp_r4 = *(s32 *)((s8 *)arg0 + 0x24) + 1;
    *(s32 *)((s8 *)arg0 + 0x24) = temp_r4;
    if ((f32) temp_r4 > lbl_805DF780) {
        password_entry_dispatch_state = *(s32 *)((s8 *)arg0 + 0x20);
    }
}

int set_multi_chg_game_mode_0x14__18TAdEnterPasswordGCFPv(void* p) { return set_mode_0x14__21TAdMultiChgGameModeGCFv(p); }
int request_transition__18TAdEnterPasswordGCFPv(void* p) { return request_transition__21TAdMultiChgGameModeGCFv(p); }

typedef struct Pw_8032B6A0 Pw_8032B6A0;
typedef struct RecoveredGlobal_8032B904_lbl_80477278 RecoveredGlobal_8032B904_lbl_80477278;
typedef struct RecoveredGlobal_8032BA8C_TAdEnterPasswordGC__data_804EDA20 RecoveredGlobal_8032BA8C_TAdEnterPasswordGC__data_804EDA20;
void update_password_input__18TAdEnterPasswordGCFPv(Pw_8032B6A0 *self) {
  s32 buf = ((TWindowSubComCard *)password_entry_keyboard_control)->realloc_buffer();
  s32 prev;
  int cur;
  if (((self->len == 0) && (TWindowShortListCtrl__check_controller_button(controller_physical_port_bank + 0x20, 2) != 0)) || ((self->len == 0) && (test_flag_4c__23TAdSinglePlyChrSelectGCFv(controller_input_state + 0x160, 2) != 0)))
  {
    mem_free((void *)buf);
    memset(&TAdEnterPasswordGC__input_buffer.value, 0, 9);
    self->f20 = 2;
    password_entry_dispatch_state = 4;
    return;
  }
  self->f3C = self->f38;
  if (password_entry_keyboard_control != 0)
  {
    if (((TWindowSubComCard *)password_entry_keyboard_control)->update_keyboard() != 0)
    {
      if ((TWindowShortListCtrl__check_controller_button(controller_physical_port_bank + 0x20, 2) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv(controller_input_state + 0x160, 2) != 0))
      {
        free_menu_object(password_entry_keyboard_control);
        self->f38 = 0;
        if (self->serial != 0)
        {
          ((TAdEnterSerialAccessGC *)(self->serial))->set_active();
        }
      }
      else
        if (forward_input__22TAdEnterSerialAccessGCFPv(self, 2, buf) == 0)
      {
        free_menu_object(password_entry_keyboard_control);
        play_sound_effect(0x53F06, 0, 0, 0);
      }
      else
      {
        self->f38 = 1;
        if (self->serial != 0)
        {
          ((TAdEnterSerialAccessGC *)(self->serial))->set_state_3();
        }
      }
    }
    else
    {
      self->f38 = 0;
      if (self->serial != 0)
      {
        ((TAdEnterSerialAccessGC *)(self->serial))->set_active();
      }
    }
  }
  prev = self->f3C;
  cur = self->f38;
  if (prev != cur)
  {
    if (cur != 0)
    {
      if (self->serial != 0)
      {
        ((TAdEnterSerialAccessGC *)((void *) self->serial))->reset_input_state();
        ((TLevelSelect *)(self->serial))->add_item_rect(((u8 *)&enter_password_item_rect_table.value) + 8);
      }
    }
    else
      if (self->serial != 0)
    {
      ((TAdEnterSerialAccessGC *)((void *) self->serial))->reset_input_state();
      ((TLevelSelect *)(self->serial))->add_item_rect(&enter_password_item_rect_table.value);
    }
  }
  if ((((TAdSinglePlyChrSelectGC *)(self->serial))->get_selected_slot() == 1) && (((TWindowSubComCard *)password_entry_keyboard_control)->update_keyboard() != 0))
  {
    strncpy((s32)&TAdEnterPasswordGC__input_buffer.value, buf, 9);
    TAdEnterSerialAccessGC__sub_80322418(get_field_118__22TAdEnterSerialAccessGCFv(), 2);
    self->f20 = 3;
    password_entry_dispatch_state = 4;
  }
  self->len = strlen(buf);
  mem_free((void *)buf);
}

void open_keyboard_window__18TAdEnterPasswordGCFPv(s32 arg0) {
    ((TAdEnterSerialAccessGC *)arg0)->m_30 = TAdEnterSerialAccessGC::show_message_window((void *)arg0, (void *)2);
    *(s32 *)((s8 *)arg0 + 0x34) = create_default_callback__22TAdEnterSerialAccessGCFv((void *)arg0);
    if ((u32) *(u32 *)((s8 *)arg0 + 0x2C) != 0U) {
        ((TAdEnterSerialAccessGC *)(*(void **)((s8 *)arg0 + 0x2C)))->reset_input_state();
        ((TLevelSelect *)(*(u32 *)((s8 *)arg0 + 0x2C)))->add_item_rect(&enter_password_item_rect_table.value);
        ((TAdEnterSerialAccessGC *)(*(u32 *)((s8 *)arg0 + 0x2C)))->set_active();
    }
    (*(u32 *)&password_entry_keyboard_control) = TAdEnterSerialAccessGC::create_keyboard_control(arg0, 2);
    password_entry_dispatch_state = 1;
}

void run_task__18TAdEnterPasswordGCFv(TAdEnterPasswordGC_8032B984 *self) {
    ((TAdEnterBaseGC *)self)->fn_8032B318(password_screen_status_line_position);
    self->state = password_entry_dispatch_state;
    static Pmf_8032B984 tbl[5] = {
        (Pmf_8032B984)&TAdEnterPasswordGC::open_keyboard_window,
        (Pmf_8032B984)&TAdEnterPasswordGC::update_password_input,
        (Pmf_8032B984)&TAdEnterPasswordGC::request_transition,
        (Pmf_8032B984)&TAdEnterPasswordGC::set_multi_chg_game_mode_0x14,
        (Pmf_8032B984)&TAdEnterPasswordGC::close_window_and_destroy,
    };
    (self->*tbl[password_entry_dispatch_state])();
    if (self->state != password_entry_dispatch_state) {
        self->f24 = 0;
    }
}

void set_password__18TAdEnterPasswordGCFi(s32 arg0) {
    memset(&TAdEnterPasswordGC__input_buffer.value, 0, 9);
    strncpy((s32) &TAdEnterPasswordGC__input_buffer.value, arg0, 9);
}

void *__dt__18TAdEnterPasswordGCFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__18TAdEnterPasswordGC;
        __dt__14TAdEnterBaseGCFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern u32 lbl_805D6CB8;

typedef char RecoveredGlobal_8032BB34___vt__18TAdEnterPasswordGC_size[sizeof(RecoveredGlobal_8032BB34___vt__18TAdEnterPasswordGC) == 0x1C ? 1 : -1];
u8 *TAdEnterPasswordGC__ct(u8 *parent) {
    u32 temp_r3;
    TAdEnterBaseGC__ct((parent));
    *(s32 **)((s8 *)parent + 0x18) = &(*(RecoveredGlobal_8032BB34___vt__18TAdEnterPasswordGC *)&__vt__18TAdEnterPasswordGC).value;
    *(s32 *)((s8 *)parent + 0) = (s32) TAdEnterPasswordGC__class_name;
    ((TAdEnterBaseGC *)parent)->sub_8032B460(2);
    password_entry_dispatch_state = 0;
    *(s32 *)((s8 *)parent + 0x40) = 0;
    if ((s8) *(u8 *)((s8 *)(TAdSinglePlyChrSelectGC::get_instance()) + 0x1154C) != 0) {
        set_password__18TAdEnterPasswordGCFi((s32)((void *) (TAdSinglePlyChrSelectGC::get_instance() + 0x1154C)));
        TKeyBoardControl__sub_8000F9CC(0xF);
        queue_destruction__7TObjectFv(parent);
        return parent;
    }
    ((TAdEnterBaseGC *)parent)->create_parts();
    temp_r3 = __nw__7TObjectFUl(0x138);
    if (temp_r3 != 0U) {
        __ct__10TAdTitleGCFP7TObjectl(temp_r3, parent, 0xC);
    }
    return parent;
}

void clear_password__18TAdEnterPasswordGCFPv(T_8032BBF0 *self) {
    s32 i;
    for (i = 0; i < 24; i++) {
        self->arr[i] = 0;
    }
    self->count = 0;
}

void update_children__18TAdEnterPasswordGCFPv(O_8032BC1C *arg0) {
    s32 i;
    for (i = 0; i < ((O2_8032BC1C *)arg0)->n; i++) {
        if (arg0->items[i] != 0 && ((TObject *)(arg0->items[i]))->all_parents_unqueued_for_destruction() != 0) {
            arg0->items[i]->m2();
        }
    }
}

void TAdEnterPasswordGC__sub_8032BC94(u8 *arg0, s32 arg1) {
    s32 temp_r0;
    temp_r0 = *(s32 *)((s8 *)arg0 + 0x80);
    if (temp_r0 < 0x18) {
        ((struct Elt80364258_80364258 *)(arg0 + 0x20))[temp_r0].f0 = arg1;
        *(s32 *)((s8 *)arg0 + 0x80) = (s32) (*(s32 *)((s8 *)arg0 + 0x80) + 1);
    }
}

s32 dispatch_input_to_instance__18TAdEnterPasswordGCFi(s32 arg0) {
    if ((u32) lbl_805D6CB8 != 0U) {
        if (((TAdSnAkPassConfirmGC *)lbl_805D6CB8)->get_confirm_state() != 0) {
            return 0;
        }
        TAdEnterPasswordGC__sub_8032BC94((u8 *)lbl_805D6CB8, (s32)arg0);
        return 1;
    }
    return 0;
}

}
