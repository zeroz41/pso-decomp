#include "pso/system/SoundEffect.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/memory.h"
#include "pso/ui/frontend/TAdTitleGC.h"
#include "pso/ui/frontend/TAdSelectCurGC.h"
#include "types.h"
#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
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
#include "pso/system/ControllerInput.h"
#include <string.h>
#include "pso/ui/frontend/TAdEnterSerialAccessGC_8032AD30.h"


static const f32 enter_password_item_rect_table[2][2] = {{155.0f, 231.0f}, {155.0f, 251.0f}};
const char *TAdEnterPasswordGC__class_name = "TAdEnterPasswordGC";

struct Pw_8032B6A0
{
  u8 pad0[0x20];
  s32 f20;
  u8 pad24[0x2C - 0x24];
  uaddr serial;
  u8 pad30[0x38 - 0x30];
  s32 f38;
  s32 f3C;
  s32 len;
};

typedef void (TAdEnterPasswordGC::*Pmf_8032B984)();

#pragma explicit_zero_data on
TAdEnterPasswordGCInputBuffer TAdEnterPasswordGC__input_buffer = { 0 };
#pragma explicit_zero_data off
extern "C" {
extern TAdEnterBaseGC::Position password_screen_status_line_position[];
extern s32 password_entry_dispatch_state;
void request_main_phase(s32 arg0);
s32 get_field_118__22TAdEnterSerialAccessGCFv(void);
void update_password_input__18TAdEnterPasswordGCFPv(Pw_8032B6A0 *self);
void __dl__7TObjectFPv(void *);

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
    if (password_entry_keyboard_control != NULL) {
        password_entry_keyboard_control->queue_destruction();
        password_entry_keyboard_control = NULL;
    }
    temp_r4 = *(s32 *)((s8 *)arg0 + 0x24) + 1;
    *(s32 *)((s8 *)arg0 + 0x24) = temp_r4;
    if ((f32) temp_r4 > 5.5f) {
        password_entry_dispatch_state = *(s32 *)((s8 *)arg0 + 0x20);
    }
}

void set_multi_chg_game_mode_0x14__18TAdEnterPasswordGCFPv(void* p) { TAdMultiChgGameModeGC::set_mode_0x14(); }
void request_transition__18TAdEnterPasswordGCFPv(void* p) { TAdMultiChgGameModeGC::request_transition(); }

typedef struct Pw_8032B6A0 Pw_8032B6A0;
void update_password_input__18TAdEnterPasswordGCFPv(Pw_8032B6A0 *self) {
  saddr buf = (saddr)password_entry_keyboard_control->realloc_buffer();
  s32 prev;
  int cur;
  if (((self->len == 0) && (test_pressed_buttons_packed(&controller_physical_port_bank.controllers[0], 2) != 0)) || ((self->len == 0) && (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)))
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
    if (password_entry_keyboard_control->is_confirmed() != 0)
    {
      if ((test_pressed_buttons_packed(&controller_physical_port_bank.controllers[0], 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0))
      {
        password_entry_keyboard_control->clear_keyboard_flag60_bit1();
        self->f38 = 0;
        if (self->serial != 0)
        {
          ((TAdSelectCurGC *)(self->serial))->lock_navigation();
        }
      }
      else
        if (TAdEnterSerialAccessGC::forward_input(self, 2, (const char *)buf) == 0)
      {
        password_entry_keyboard_control->clear_keyboard_flag60_bit1();
        play_sound_effect(0x53F06, 0, 0, 0);
      }
      else
      {
        self->f38 = 1;
        if (self->serial != 0)
        {
          ((TAdSelectCurGC *)(self->serial))->request_navigation_unlock();
        }
      }
    }
    else
    {
      self->f38 = 0;
      if (self->serial != 0)
      {
        ((TAdSelectCurGC *)(self->serial))->lock_navigation();
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
        ((TAdSelectCurGC *)((void *) self->serial))->reset_entries();
        ((TAdSelectCurGC *)(self->serial))->append_entry((void *)enter_password_item_rect_table[1]);
      }
    }
    else
      if (self->serial != 0)
    {
      ((TAdSelectCurGC *)((void *) self->serial))->reset_entries();
      ((TAdSelectCurGC *)(self->serial))->append_entry((void *)enter_password_item_rect_table[0]);
    }
  }
  if ((((TAdSelectCurGC *)(self->serial))->confirmation_result() == 1) && (password_entry_keyboard_control->is_confirmed() != 0))
  {
    strncpy((char *)&TAdEnterPasswordGC__input_buffer.value, (const char *)buf, 9);
    TAdEnterSerialAccessGC::set_entered_value(get_field_118__22TAdEnterSerialAccessGCFv(), 2);
    self->f20 = 3;
    password_entry_dispatch_state = 4;
  }
  self->len = strlen((const char *)buf);
  mem_free((void *)buf);
}

void open_keyboard_window__18TAdEnterPasswordGCFPv(saddr arg0) {
    ((TAdEnterSerialAccessGC *)arg0)->m_30 = TAdEnterSerialAccessGC::show_message_window((void *)arg0, (void *)2);
    *(s32 *)((s8 *)arg0 + 0x34) = (saddr)((TAdEnterSerialAccessGC *)arg0)->create_default_callback();
    if ((u32) *(u32 *)((s8 *)arg0 + 0x2C) != 0U) {
        ((TAdSelectCurGC *)(*(void **)((s8 *)arg0 + 0x2C)))->reset_entries();
        ((TAdSelectCurGC *)(*(uaddr *)((s8 *)arg0 + 0x2C)))->append_entry((void *)enter_password_item_rect_table[0]);
        ((TAdSelectCurGC *)(*(uaddr *)((s8 *)arg0 + 0x2C)))->lock_navigation();
    }
    password_entry_keyboard_control = TAdEnterSerialAccessGC::create_keyboard_control(arg0, 2);
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

void set_password__18TAdEnterPasswordGCFi(saddr arg0) {
    memset(&TAdEnterPasswordGC__input_buffer.value, 0, 9);
    strncpy((char *)&TAdEnterPasswordGC__input_buffer.value, (const char *)arg0, 9);
}

TAdEnterPasswordGC::~TAdEnterPasswordGC() {}

TAdEnterPasswordGC::TAdEnterPasswordGC(TObject *parent) : TAdEnterBaseGC(parent) {
    m_name = TAdEnterPasswordGC__class_name;
    sub_8032B460(2);
    password_entry_dispatch_state = 0;
    len = 0;
    if ((s8) *(u8 *)((s8 *)(TAdSinglePlyChrSelectGC::get_instance()) + 0x1154C) != 0) {
        set_password__18TAdEnterPasswordGCFi((saddr)((void *) (TAdSinglePlyChrSelectGC::get_instance() + 0x1154C)));
        request_main_phase(0xF);
        queue_destruction();
        return;
    }
    create_parts();
    new TAdTitleGC(this, 0xC);
}

}
