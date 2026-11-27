#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/frontend/TAdSelectCurGC.h"
#include "types.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/frontend/TAdEp3Exist.h"
#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"
#include "pso/quest/TQuestListVM_8007EAF8.h"
#include "pso/ui/frontend/TAdAgreementBaseGC.h"

#include "pso/ui/TLevelSelect.h"
#include "pso/network/TLobby.h"
#include "pso/ui/frontend/TAdEnterSerialAccessGC.h"
#include "pso/ui/frontend/TAdScrollWinGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/save/CharacterFile.h"
#include "pso/ui/frontend/TAdSubPlyItemGC.h"
#include "pso/system/task/TObject.h"
#include "pso/system/ControllerInput.h"
#include "pso/ui/keyboard/KeyBoardMenu.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"
#include "pso/ui/MenuText.h"

#pragma readonly_strings on

const f32 ep3_exist_cursor_pos[2] = { 89.0f, 394.0f };
const f32 ep3_exist_cursor_size[2] = { 462.0f, 18.0f };
const char *TAdEp3Exist::name = "TAdEp3Exist";
const NJS_POINT2 serial_access_window_pos = { 85.0f, 384.0f };
const NJS_POINT2 serial_access_window_size = { 470.0f, 32.0f };

void *TAdEp3Exist::create_callback_window() {
    return TAdEnterSerialAccessGC::create_callback(&serial_access_window_pos, &serial_access_window_size, draw_message_window);
}



void TAdEp3Exist::draw_message_window(void *window, void *frame_context) {
    ((TWindowBase *)window)->draw_window_frame((WindowDrawContext *)frame_context);
    f32 x = 320.0f - (f32)(calc_text_width(get_localized_text_entry(0x2C, 0xA)) >> 1U);
    draw_menu_text_scaled(x, 394.0f, 0.8f, get_localized_text_entry(0x2C, 0xA), -1);
}

void TAdEp3Exist::render() {
    if (TMainTask::get_render_pass() == 1) {
        return;
    }
}

void TAdEp3Exist::request_game_mode_transition() { TAdMultiChgGameModeGC::open_lic_agreement_scene(); }
void TAdEp3Exist::request_scene_change() { TAdMultiChgGameModeGC::open_time_set_scene(); }
void TAdEp3Exist::request_ppp_pass_scene() { TAdMultiChgGameModeGC::open_enter_ppp_pass_scene(); }
void TAdEp3Exist::close_window() { if (scroll_window != NULL) { scroll_window->close_window(); scroll_window = NULL; } }

void TAdEp3Exist::run_task() {
    prev_state = state;
    switch (state) {
    case 0:
        callback_window = create_callback_window();
        state = 1;
        break;
    case 1:
        if (cursor->confirmation_result() == 1) {
            switch (cursor->selection_index()) {
            case 0:
                state = 2;
                next_state = 3;
                break;
            case 1:
                state = 2;
                next_state = 4;
                break;
            }
        } else if (test_pressed_buttons_packed(&controller_physical_port_bank.controllers[0], 2) != 0 ||
                   test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0) {
            state = 2;
            next_state = 5;
        }
        break;
    case 2:
        if (callback_window != NULL) {
            ((TWindowBase *)callback_window)->close();
            callback_window = NULL;
        }
        close_window();
        if ((f32)++frames > 4.5f) {
            state = next_state;
        }
        break;
    case 3:
        request_ppp_pass_scene();
        break;
    case 4:
        request_scene_change();
        break;
    case 5:
        request_game_mode_transition();
        break;
    }
    if (prev_state != state) {
        frames = 0;
    }
}

TAdEp3Exist::~TAdEp3Exist() {
    if (callback_window != NULL) { ((TObject *)callback_window)->queue_destruction(); callback_window = NULL; }
    if (cursor != NULL) { cursor->queue_destruction(); cursor = NULL; }
}

TAdEp3Exist::TAdEp3Exist(TObject *parent) : TObject(parent) {
    char flag[16];
    u8 save[16];
    s32 res;
    bool ok;
    bool go;
    m_name = TAdEp3Exist::name;
    scroll_window = NULL;
    cursor = NULL;
    callback_window = NULL;
    frames = 0;
    state = 0;
    next_state = 0;
    flag[0] = 0;
    res = load_and_verify_character_save(flag, (char *)save);
    ok = false;
    if (res != 0) {
        if (flag[0] != 0) {
            ok = true;
        }
    }
    go = false;
    if (ok) {
        if (TAdSinglePlyChrSelectGC::get_instance()->serial_number[0] == 0) {
            go = true;
        }
    }
    if (!go) {
        TAdMultiChgGameModeGC::open_enter_ppp_pass_scene();
        queue_destruction();
        return;
    }
    new TAdBackGC(this);
    new TAdBackTxtGC(this);
    scroll_window = new TAdScrollWinGC(this, 3, get_localized_text_entry(0x2C, 9));
    cursor = new TAdSelectCurGC(tl_clipout, (const NJS_POINT2 *)ep3_exist_cursor_pos, (const NJS_POINT2 *)ep3_exist_cursor_size);
    cursor->append_entry(ep3_exist_cursor_pos);
    cursor->set_wait_directions_released();
    cursor->set_selection_index(0);
}
