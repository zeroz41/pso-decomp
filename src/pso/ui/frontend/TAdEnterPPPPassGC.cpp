#include "pso/system/SoundEffect.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/memory.h"
#include "pso/ui/frontend/TAdSelectCurGC.h"
#include "types.h"
#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowCallBack.h"
#include "pso/ui/frontend/TAdEnterPPPPassGC.h"
#include "pso/unk/text_8014618C.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/system/task/TMainTask.h"
#include "pso/network/TLobby.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/frontend/TAdEnterBaseGC.h"
#include "pso/ui/frontend/TAdEnterSerialAccessGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/quest/TQuestThread.h"
#include "pso/system/task/TObject.h"
#include "pso/system/ControllerInput.h"
#include <string.h>
#include "pso/ui/frontend/TAdEnterSerialAccessGC_8032AD30.h"
#include "pso/system/SoundEffect.h"

static const f32 TAdEnterPPPPassGC__selection_positions[4][2] = {{155.0f, 231.0f}, {155.0f, 251.0f}, {87.0f, 231.0f}, {87.0f, 251.0f}};
const char *TAdEnterPPPPassGC__name = "TAdEnterPPPPassGC";

typedef void (TAdEnterPPPPassGC::*Pmf_80339378)();

extern "C" {
extern s32 password_entry_dispatch_state;
extern TAdEnterBaseGC::Position password_screen_status_line_position[];
void request_main_phase(int);
s32 load_network_info(void);
s32 TLobby__sub_80145DB4(int);
s8 *TLobby__sub_80146D14(void);
s8 *TLobby__sub_80146D44(void);
}

void TAdEnterPPPPassGC::render() {
    if (TMainTask::get_render_pass() == 1) { return;
    }
}

void TAdEnterPPPPassGC::close_windows_and_advance(void *arg) {
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

void TAdEnterPPPPassGC::forward_chg_game_mode(void *arg) { TAdMultiChgGameModeGC::reset_mode_state(); }
void TAdEnterPPPPassGC::request_transition(void *arg) { TAdMultiChgGameModeGC::request_transition(); }

void TAdEnterPPPPassGC::update_password_input(void *arg) {
    char *buf;
    s32 cur;
    buf = password_entry_keyboard_control->realloc_buffer();
    if ((m_40 == 0 && test_pressed_buttons_packed(&controller_physical_port_bank.controllers[0], 2) != 0) ||
        (m_40 == 0 && test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
        mem_free(buf);
        TAdEnterPPPPassGC::set_password("");
        pending_dispatch_state = 2;
        password_entry_dispatch_state = 4;
        return;
    }
    prev_input_valid = input_valid;
    if (password_entry_keyboard_control != NULL) {
        if (password_entry_keyboard_control->is_confirmed() != 0) {
            if (test_pressed_buttons_packed(&controller_physical_port_bank.controllers[0], 2) != 0 ||
                test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0) {
                password_entry_keyboard_control->clear_keyboard_flag60_bit1();
                input_valid = 0;
                if (select_cursor != NULL) {
                    select_cursor->lock_navigation();
                }
            } else if (TAdEnterSerialAccessGC::forward_input(this, 3, buf) == 0) {
                password_entry_keyboard_control->clear_keyboard_flag60_bit1();
                play_sound_effect(0x53F06, 0, 0, 0);
            } else {
                input_valid = 1;
                if (select_cursor != NULL) {
                    select_cursor->request_navigation_unlock();
                }
            }
        } else {
            input_valid = 0;
            if (select_cursor != NULL) {
                select_cursor->lock_navigation();
            }
        }
    }
    if (prev_input_valid != (cur = input_valid)) {
        if (cur != 0) {
            if (select_cursor != NULL) {
                select_cursor->reset_entries();
                select_cursor->append_entry((void *)TAdEnterPPPPassGC__selection_positions[3]);
            }
        } else if (select_cursor != NULL) {
            select_cursor->reset_entries();
            select_cursor->append_entry((void *)TAdEnterPPPPassGC__selection_positions[2]);
        }
    }
    if (select_cursor->confirmation_result() == 1 &&
        password_entry_keyboard_control->is_confirmed() != 0) {
        TAdEnterPPPPassGC::set_password(buf);
        pending_dispatch_state = 3;
        password_entry_dispatch_state = 4;
    }
    m_40 = strlen(buf);
    mem_free(buf);
}

void TAdEnterPPPPassGC::open_keyboard_window(void *arg) {
    prompt_window = TAdEnterSerialAccessGC::show_message_window(this, (void *)3);
    callback_window = create_default_callback();
    if (select_cursor != NULL) {
        select_cursor->reset_entries();
        select_cursor->append_entry((void *)TAdEnterPPPPassGC__selection_positions[2]);
        select_cursor->lock_navigation();
    }
    password_entry_keyboard_control = TAdEnterSerialAccessGC::create_keyboard_control((saddr)this, 3);
    password_entry_dispatch_state = 1;
}

void *ppp_password_buffer[8] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
};

void TAdEnterPPPPassGC::run_task() {
    TAdEnterPPPPassGC *self = this;
    self->fn_8032B318(password_screen_status_line_position);
    self->m_1c = password_entry_dispatch_state;
    static Pmf_80339378 tbl[5] = {
        (Pmf_80339378)&TAdEnterPPPPassGC::open_keyboard_window,
        (Pmf_80339378)&TAdEnterPPPPassGC::update_password_input,
        (Pmf_80339378)&TAdEnterPPPPassGC::request_transition,
        (Pmf_80339378)&TAdEnterPPPPassGC::forward_chg_game_mode,
        (Pmf_80339378)&TAdEnterPPPPassGC::close_windows_and_advance,
    };
    (self->*tbl[password_entry_dispatch_state])();
    if (self->m_1c != password_entry_dispatch_state) {
        self->close_delay_ticks = 0;
    }
}

void TAdEnterPPPPassGC::set_password(const char *password) {
    if ((TLobby__sub_8014618C() != 0) && (TLobby::is_state_active() != 0)) {
        TLobby::set_ppp_password(password);
        return;
    }
    memset(ppp_password_buffer, 0, 0x20);
    strncpy((char *)ppp_password_buffer, password, 0x1F);
}

TAdEnterPPPPassGC::~TAdEnterPPPPassGC() {}

TAdEnterPPPPassGC::TAdEnterPPPPassGC(TObject *parent) : TAdEnterBaseGC(parent) {
    s32 ok;
    m_name = TAdEnterPPPPassGC__name;
    sub_8032B460(3);
    password_entry_dispatch_state = 0;
    m_40 = 0;
    if (load_network_info() != 0) {
        TLobby::init_account_entries();
    } else {
        request_main_phase(0x13);
        queue_destruction();
        return;
    }
    ok = 0;
    if (TLobby__sub_8014618C() != 0) {
        if (TLobby::is_state_active() != 0) {
            if (*TLobby__sub_80146D14() != 0) {
                ok = 1;
            }
        } else {
            ok = 1;
        }
    } else if (TLobby__sub_80145DB4(1) != 0 && *TLobby__sub_80146D44() != 0) {
        ok = 1;
    }
    if (ok != 0) {
        TAdMultiChgGameModeGC::reset_mode_state();
        queue_destruction();
        return;
    }
    create_parts();
}
