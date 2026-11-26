#include "pso/system/SoundEffect.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/memory.h"
#include "pso/ui/frontend/TAdTitleGC.h"
#include "pso/ui/frontend/TAdSelectCurGC.h"
#include "types.h"
#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowCallBack.h"
#include "pso/ui/frontend/TAdEnterPasswordGC.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/frontend/TAdEnterBaseGC.h"
#include "pso/ui/frontend/TAdEnterSerialAccessGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/save/CharacterFile.h"
#include "pso/quest/TQuestThread.h"
#include "pso/network/TLobby.h"
#include "pso/system/ControllerInput.h"
#include <string.h>
#include "pso/ui/keyboard/SystemBootInit.h"


static const f32 enter_password_item_rect_table[2][2] = {{155.0f, 231.0f}, {155.0f, 251.0f}};
const char *TAdEnterPasswordGC::class_name = "TAdEnterPasswordGC";


typedef void (TAdEnterPasswordGC::*StateHandler)();

#pragma explicit_zero_data on
TAdEnterPasswordGCInputBuffer TAdEnterPasswordGC::input_buffer = { 0 };
#pragma explicit_zero_data off

void TAdEnterPasswordGC::render() {
    if (TMainTask::get_render_pass() == 1) { return;
    }
}

void TAdEnterPasswordGC::close_window_and_destroy(void *arg) {
    s32 tick;
    if (prompt_window != NULL) {
        prompt_window->close();
        prompt_window = NULL;
    }
    if (callback_window != NULL) {
        callback_window->close();
        callback_window = NULL;
    }
    if (password_entry_keyboard_control != NULL) {
        password_entry_keyboard_control->queue_destruction();
        password_entry_keyboard_control = NULL;
    }
    tick = close_delay_ticks + 1;
    close_delay_ticks = tick;
    if ((f32)tick > 5.5f) {
        password_entry_dispatch_state = pending_dispatch_state;
    }
}

void TAdEnterPasswordGC::open_sn_ak_pass_confirm(void *arg) { TAdMultiChgGameModeGC::open_sn_ak_pass_confirm_scene(); }
void TAdEnterPasswordGC::request_transition(void *arg) { TAdMultiChgGameModeGC::open_lic_agreement_scene(); }

void TAdEnterPasswordGC::update_password_input(void *arg) {
  saddr buf = (saddr)password_entry_keyboard_control->realloc_buffer();
  s32 prev;
  int cur;
  if (((len == 0) && (test_pressed_buttons_packed(&controller_physical_port_bank.controllers[0], 2) != 0)) || ((len == 0) && (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)))
  {
    mem_free((void *)buf);
    memset(&TAdEnterPasswordGC::input_buffer.value, 0, 9);
    pending_dispatch_state = 2;
    password_entry_dispatch_state = 4;
    return;
  }
  prev_input_valid = input_valid;
  if (password_entry_keyboard_control != 0)
  {
    if (password_entry_keyboard_control->is_confirmed() != 0)
    {
      if ((test_pressed_buttons_packed(&controller_physical_port_bank.controllers[0], 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0))
      {
        password_entry_keyboard_control->clear_keyboard_flag60_bit1();
        input_valid = 0;
        if (select_cursor != NULL)
        {
          select_cursor->lock_navigation();
        }
      }
      else
        if (TAdEnterSerialAccessGC::forward_input(this, 2, (const char *)buf) == 0)
      {
        password_entry_keyboard_control->clear_keyboard_flag60_bit1();
        play_sound_effect(0x53F06, 0, 0, 0);
      }
      else
      {
        input_valid = 1;
        if (select_cursor != NULL)
        {
          select_cursor->request_navigation_unlock();
        }
      }
    }
    else
    {
      input_valid = 0;
      if (select_cursor != NULL)
      {
        select_cursor->lock_navigation();
      }
    }
  }
  prev = prev_input_valid;
  cur = input_valid;
  if (prev != cur)
  {
    if (cur != 0)
    {
      if (select_cursor != NULL)
      {
        select_cursor->reset_entries();
        select_cursor->append_entry(enter_password_item_rect_table[1]);
      }
    }
    else
      if (select_cursor != NULL)
    {
      select_cursor->reset_entries();
      select_cursor->append_entry(enter_password_item_rect_table[0]);
    }
  }
  if ((select_cursor->confirmation_result() == 1) && (password_entry_keyboard_control->is_confirmed() != 0))
  {
    strncpy((char *)&TAdEnterPasswordGC::input_buffer.value, (const char *)buf, 9);
    TAdEnterSerialAccessGC::set_entered_value(TAdEnterSerialAccessGC::get_serial_seed(), 2);
    pending_dispatch_state = 3;
    password_entry_dispatch_state = 4;
  }
  len = strlen((const char *)buf);
  mem_free((void *)buf);
}

void TAdEnterPasswordGC::open_keyboard_window(void *arg) {
    prompt_window = TAdEnterSerialAccessGC::show_message_window(this, (void *)2);
    callback_window = create_default_callback();
    if (select_cursor != NULL) {
        select_cursor->reset_entries();
        select_cursor->append_entry(enter_password_item_rect_table[0]);
        select_cursor->lock_navigation();
    }
    password_entry_keyboard_control = TAdEnterSerialAccessGC::create_keyboard_control((saddr)this, 2);
    password_entry_dispatch_state = 1;
}

void TAdEnterPasswordGC::run_task() {
    get_title_position(password_screen_status_line_position);
    prev_state = password_entry_dispatch_state;
    static StateHandler tbl[5] = {
        (StateHandler)&TAdEnterPasswordGC::open_keyboard_window,
        (StateHandler)&TAdEnterPasswordGC::update_password_input,
        (StateHandler)&TAdEnterPasswordGC::request_transition,
        (StateHandler)&TAdEnterPasswordGC::open_sn_ak_pass_confirm,
        (StateHandler)&TAdEnterPasswordGC::close_window_and_destroy,
    };
    (this->*tbl[password_entry_dispatch_state])();
    if (prev_state != password_entry_dispatch_state) {
        close_delay_ticks = 0;
    }
}

void TAdEnterPasswordGC::set_password(const char *password) {
    memset(&TAdEnterPasswordGC::input_buffer.value, 0, 9);
    strncpy((char *)&TAdEnterPasswordGC::input_buffer.value, password, 9);
}

TAdEnterPasswordGC::~TAdEnterPasswordGC() {}

TAdEnterPasswordGC::TAdEnterPasswordGC(TObject *parent) : TAdEnterBaseGC(parent) {
    m_name = TAdEnterPasswordGC::class_name;
    reset(2);
    password_entry_dispatch_state = 0;
    len = 0;
    if (TAdSinglePlyChrSelectGC::get_instance()->password[0] != 0) {
        set_password(TAdSinglePlyChrSelectGC::get_instance()->password);
        request_main_phase(0xF);
        queue_destruction();
        return;
    }
    create_parts();
    new TAdTitleGC(this, 0xC);
}
