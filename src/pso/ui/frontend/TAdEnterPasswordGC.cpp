#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/frontend/TAdEnterBaseGC_8032B38C.h"
#include "pso/ui/frontend/TAdEnterPasswordGC.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/frontend/TAdEnterBaseGC.h"
#include "pso/ui/frontend/TAdEnterSerialAccessGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/quest/TQuestThread.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801A6D60.h"


static const f32 enter_password_item_rect_table[2][2] = {{155.0f, 231.0f}, {155.0f, 251.0f}};
const char *TAdEnterPasswordGC__class_name = "TAdEnterPasswordGC";

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

typedef void (TAdEnterPasswordGC::*Pmf_8032B984)();

extern "C" {
extern TAdEnterBaseGC::Position password_screen_status_line_position[];
extern s32 password_entry_dispatch_state;
#pragma explicit_zero_data on
TAdEnterPasswordGCInputBuffer TAdEnterPasswordGC__input_buffer = { 0 };
#pragma explicit_zero_data off
extern u8 *password_entry_keyboard_control;
s32 create_default_callback__22TAdEnterSerialAccessGCFv(void *);
void strncpy(s32, s32, s32);
s32 memset(void *, int, int);
void request_main_phase(s32 arg0);
u32 __nw__7TObjectFUl(int);
s32 __ct__10TAdTitleGCFP7TObjectl(int, void *, int);
void mem_free(void *p);
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, int);
s32 get_field_118__22TAdEnterSerialAccessGCFv(void);
s32 play_sound_effect(int, int, int, int);
s32 forward_input__22TAdEnterSerialAccessGCFPv(void *, int, s32);
s32 strlen(s32);
extern u8 controller_input_state[];
extern u8 controller_physical_port_bank[];
void update_password_input__18TAdEnterPasswordGCFPv(Pw_8032B6A0 *self);
void __dl__7TObjectFPv(void *);
int request_transition__21TAdMultiChgGameModeGCFv(void*);
int set_mode_0x14__21TAdMultiChgGameModeGCFv(void*);

void TAdEnterPasswordGC::render() {
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
        ((TObject *)password_entry_keyboard_control)->queue_destruction();
        password_entry_keyboard_control = NULL;
    }
    temp_r4 = *(s32 *)((s8 *)arg0 + 0x24) + 1;
    *(s32 *)((s8 *)arg0 + 0x24) = temp_r4;
    if ((f32) temp_r4 > 5.5f) {
        password_entry_dispatch_state = *(s32 *)((s8 *)arg0 + 0x20);
    }
}

int set_multi_chg_game_mode_0x14__18TAdEnterPasswordGCFPv(void* p) { return set_mode_0x14__21TAdMultiChgGameModeGCFv(p); }
int request_transition__18TAdEnterPasswordGCFPv(void* p) { return request_transition__21TAdMultiChgGameModeGCFv(p); }

typedef struct Pw_8032B6A0 Pw_8032B6A0;
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
        ((TLevelSelect *)(self->serial))->add_item_rect((void *)enter_password_item_rect_table[1]);
      }
    }
    else
      if (self->serial != 0)
    {
      ((TAdEnterSerialAccessGC *)((void *) self->serial))->reset_input_state();
      ((TLevelSelect *)(self->serial))->add_item_rect((void *)enter_password_item_rect_table[0]);
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
        ((TLevelSelect *)(*(u32 *)((s8 *)arg0 + 0x2C)))->add_item_rect((void *)enter_password_item_rect_table[0]);
        ((TAdEnterSerialAccessGC *)(*(u32 *)((s8 *)arg0 + 0x2C)))->set_active();
    }
    (*(u32 *)&password_entry_keyboard_control) = TAdEnterSerialAccessGC::create_keyboard_control(arg0, 2);
    password_entry_dispatch_state = 1;
}

void TAdEnterPasswordGC::run_task() {
    fn_8032B318(password_screen_status_line_position);
    m_1c = password_entry_dispatch_state;
    static Pmf_8032B984 tbl[5] = {
        (Pmf_8032B984)&TAdEnterPasswordGC::open_keyboard_window,
        (Pmf_8032B984)&TAdEnterPasswordGC::update_password_input,
        (Pmf_8032B984)&TAdEnterPasswordGC::request_transition,
        (Pmf_8032B984)&TAdEnterPasswordGC::set_multi_chg_game_mode_0x14,
        (Pmf_8032B984)&TAdEnterPasswordGC::close_window_and_destroy,
    };
    (this->*tbl[password_entry_dispatch_state])();
    if (m_1c != password_entry_dispatch_state) {
        m_24 = 0;
    }
}

void set_password__18TAdEnterPasswordGCFi(s32 arg0) {
    memset(&TAdEnterPasswordGC__input_buffer.value, 0, 9);
    strncpy((s32) &TAdEnterPasswordGC__input_buffer.value, arg0, 9);
}

TAdEnterPasswordGC::~TAdEnterPasswordGC() {}

TAdEnterPasswordGC::TAdEnterPasswordGC(TObject *parent) : TAdEnterBaseGC(parent) {
    u32 temp_r3;
    m_name = TAdEnterPasswordGC__class_name;
    sub_8032B460(2);
    password_entry_dispatch_state = 0;
    len = 0;
    if ((s8) *(u8 *)((s8 *)(TAdSinglePlyChrSelectGC::get_instance()) + 0x1154C) != 0) {
        set_password__18TAdEnterPasswordGCFi((s32)((void *) (TAdSinglePlyChrSelectGC::get_instance() + 0x1154C)));
        request_main_phase(0xF);
        queue_destruction();
        return;
    }
    create_parts();
    temp_r3 = __nw__7TObjectFUl(0x138);
    if (temp_r3 != 0U) {
        __ct__10TAdTitleGCFP7TObjectl(temp_r3, this, 0xC);
    }
}

}
