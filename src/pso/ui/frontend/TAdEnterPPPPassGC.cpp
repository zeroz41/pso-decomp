#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/frontend/TAdSelectCurGC.h"
#include "types.h"
#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/frontend/TAdEnterPPPPassGC.h"
#include "pso/unk/text_8014618C.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/frontend/TAdEnterBaseGC.h"
#include "pso/ui/frontend/TAdEnterSerialAccessGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/quest/TQuestThread.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801A6D60.h"
#include <string.h>
#include "pso/ui/frontend/TAdEnterSerialAccessGC_8032AD30.h"

static const f32 TAdEnterPPPPassGC__selection_positions[4][2] = {{155.0f, 231.0f}, {155.0f, 251.0f}, {87.0f, 231.0f}, {87.0f, 251.0f}};
const char *TAdEnterPPPPassGC__name = "TAdEnterPPPPassGC";

typedef void (TAdEnterPPPPassGC::*Pmf_80339378)();

extern "C" {
extern u8 *password_entry_keyboard_control;
extern s32 password_entry_dispatch_state;
extern TAdEnterBaseGC::Position password_screen_status_line_position[];
void request_main_phase(int);
s32 load_network_info(void);
s32 TLobby__sub_80145DB4(int);
s8 *TLobby__sub_80146D14(void);
s8 *TLobby__sub_80146D44(void);
void mem_free(void *);
void play_sound_effect(int, int, int, int);
extern u8 controller_input_state[];
extern u8 controller_physical_port_bank[];

void TAdEnterPPPPassGC::render() {
    if (TMainTask::get_render_pass() == 1) { return;
    }
}

void close_windows_and_advance__17TAdEnterPPPPassGCFPv(u8 *arg0) {
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

void forward_chg_game_mode__17TAdEnterPPPPassGCFPv(void* p) { TAdMultiChgGameModeGC::reset_mode_state(); }
void request_transition__17TAdEnterPPPPassGCFPv(void* p) { TAdMultiChgGameModeGC::request_transition(); }

void update_password_input__17TAdEnterPPPPassGCFPv(u8 *ad_enter_serial_access_gc) {
    char *buf;
    s32 cur;
    buf = ((TKeyBoardControl *)password_entry_keyboard_control)->realloc_buffer();
    if ((*(s32 *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_40 == 0 && TWindowShortListCtrl__check_controller_button(controller_physical_port_bank + 0x20, 2) != 0) ||
        (*(s32 *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_40 == 0 && test_controller_flag_4c_color(controller_input_state + 0x160, 2) != 0)) {
        mem_free(buf);
        set_password__17TAdEnterPPPPassGCFi((saddr)"");
        *(s32 *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_20 = 2;
        password_entry_dispatch_state = 4;
        return;
    }
    ((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_3c = *(s32 *)((s8 *)ad_enter_serial_access_gc + 0x38);
    if (password_entry_keyboard_control != NULL) {
        if (((TKeyBoardControl *)password_entry_keyboard_control)->is_confirmed() != 0) {
            if (TWindowShortListCtrl__check_controller_button(controller_physical_port_bank + 0x20, 2) != 0 ||
                test_controller_flag_4c_color(controller_input_state + 0x160, 2) != 0) {
                reinterpret_cast<TKeyBoardControl *>(password_entry_keyboard_control)->clear_keyboard_flag60_bit1();
                *(s32 *)((s8 *)ad_enter_serial_access_gc + 0x38) = 0;
                if (*(u32 *)((s8 *)ad_enter_serial_access_gc + 0x2C) != 0) {
                    ((TAdSelectCurGC *)(*(saddr *)((s8 *)ad_enter_serial_access_gc + 0x2C)))->lock_navigation();
                }
            } else if (TAdEnterSerialAccessGC::forward_input(ad_enter_serial_access_gc, 3, buf) == 0) {
                reinterpret_cast<TKeyBoardControl *>(password_entry_keyboard_control)->clear_keyboard_flag60_bit1();
                play_sound_effect(0x53F06, 0, 0, 0);
            } else {
                *(s32 *)((s8 *)ad_enter_serial_access_gc + 0x38) = 1;
                if (*(u32 *)((s8 *)ad_enter_serial_access_gc + 0x2C) != 0) {
                    ((TAdSelectCurGC *)(*(saddr *)((s8 *)ad_enter_serial_access_gc + 0x2C)))->request_navigation_unlock();
                }
            }
        } else {
            *(s32 *)((s8 *)ad_enter_serial_access_gc + 0x38) = 0;
            if (*(u32 *)((s8 *)ad_enter_serial_access_gc + 0x2C) != 0) {
                ((TAdSelectCurGC *)(*(saddr *)((s8 *)ad_enter_serial_access_gc + 0x2C)))->lock_navigation();
            }
        }
    }
    if (((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_3c != (cur = *(s32 *)((s8 *)ad_enter_serial_access_gc + 0x38))) {
        if (cur != 0) {
            if (*(u32 *)((s8 *)ad_enter_serial_access_gc + 0x2C) != 0) {
                ((TAdSelectCurGC *)(*(saddr *)((s8 *)ad_enter_serial_access_gc + 0x2C)))->reset_entries();
                ((TAdSelectCurGC *)(*(saddr *)((s8 *)ad_enter_serial_access_gc + 0x2C)))->append_entry((void *)TAdEnterPPPPassGC__selection_positions[3]);
            }
        } else if (*(u32 *)((s8 *)ad_enter_serial_access_gc + 0x2C) != 0) {
            ((TAdSelectCurGC *)(*(saddr *)((s8 *)ad_enter_serial_access_gc + 0x2C)))->reset_entries();
            ((TAdSelectCurGC *)(*(saddr *)((s8 *)ad_enter_serial_access_gc + 0x2C)))->append_entry((void *)TAdEnterPPPPassGC__selection_positions[2]);
        }
    }
    if (((TAdSelectCurGC *)(*(saddr *)((s8 *)ad_enter_serial_access_gc + 0x2C)))->confirmation_result() == 1 &&
        ((TKeyBoardControl *)password_entry_keyboard_control)->is_confirmed() != 0) {
        set_password__17TAdEnterPPPPassGCFi((saddr)buf);
        *(s32 *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_20 = 3;
        password_entry_dispatch_state = 4;
    }
    *(s32 *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_40 = strlen(buf);
    mem_free(buf);
}

void open_keyboard_window__17TAdEnterPPPPassGCFPv(u8 *ad_enter_serial_access_gc) {
    uaddr temp_r3;
    ((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_30 = TAdEnterSerialAccessGC::show_message_window((void *)ad_enter_serial_access_gc, (void *)3);
    *(s32 *)((s8 *)ad_enter_serial_access_gc + 0x34) = (saddr)((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->create_default_callback();
    temp_r3 = *(u32 *)((s8 *)ad_enter_serial_access_gc + 0x2C);
    if (temp_r3 != 0U) {
        ((TAdSelectCurGC *)temp_r3)->reset_entries();
        ((TAdSelectCurGC *)(*(uaddr *)((s8 *)ad_enter_serial_access_gc + 0x2C)))->append_entry((void *)TAdEnterPPPPassGC__selection_positions[2]);
        ((TAdSelectCurGC *)(*(uaddr *)((s8 *)ad_enter_serial_access_gc + 0x2C)))->lock_navigation();
    }
    (*(s32 *)&password_entry_keyboard_control) = TAdEnterSerialAccessGC::create_keyboard_control((saddr)ad_enter_serial_access_gc, 3);
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
        self->m_24 = 0;
    }
}

void set_password__17TAdEnterPPPPassGCFi(saddr arg0) {
    if ((TLobby__sub_8014618C() != 0) && (TLobby::is_state_active() != 0)) {
        TLobby::set_ppp_password(arg0);
        return;
    }
    memset(ppp_password_buffer, 0, 0x20);
    strncpy((char *)ppp_password_buffer, (const char *)arg0, 0x1F);
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

}
