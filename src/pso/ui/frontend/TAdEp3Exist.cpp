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
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801334D4.h"

#include "pso/ui/TLevelSelect.h"
#include "pso/network/TLobby.h"
#include "pso/ui/frontend/TAdEnterSerialAccessGC.h"
#include "pso/ui/frontend/TAdScrollWinGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/frontend/TAdSubPlyItemGC.h"
#include "pso/system/task/TObject.h"
#include "pso/system/ControllerInput.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"

#pragma readonly_strings on

const f32 lbl_8047B8A8[2] = { 89.0f, 394.0f };
const f32 lbl_8047B8B0[2] = { 462.0f, 18.0f };
const char *TAdEp3Exist::name = "TAdEp3Exist";
const f32 lbl_8047B8C4[2] = { 85.0f, 384.0f };
const f32 lbl_8047B8CC[2] = { 470.0f, 32.0f };

void *TAdEp3Exist::create_callback_window() {
    return TAdEnterSerialAccessGC::create_callback((void *)lbl_8047B8C4, (void *)lbl_8047B8CC, draw_message_window);
}

extern "C" {


void TAdEp3Exist::draw_message_window(void *window, void *frame_context) {
    ((TWindowBase *)window)->draw_window_frame(frame_context);
    f32 x = 320.0f - (f32)(calc_text_width((char *)get_localized_text_entry(0x2C, 0xA)) >> 1U);
    TAdSubPlyItemGC::render_status_line(x, 394.0f, 0.8f, (const char *)get_localized_text_entry(0x2C, 0xA), -1);
}

void TAdEp3Exist::render() {
    if (TMainTask::get_render_pass() == 1) {
        return;
    }
}

void TAdEp3Exist::request_game_mode_transition() { TAdMultiChgGameModeGC::request_transition(); }
void TAdEp3Exist::request_scene_change() { TAdMultiChgGameModeGC::request_scene_change(); }
void TAdEp3Exist__sub_8036F0AC(TAdEp3Exist *p) { TAdMultiChgGameModeGC::reset_and_set_mode(); }
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
        TAdEp3Exist__sub_8036F0AC(this);
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

}
TAdEp3Exist::~TAdEp3Exist() {
    if (callback_window != NULL) { ((TObject *)callback_window)->queue_destruction(); callback_window = NULL; }
    if (cursor != NULL) { cursor->queue_destruction(); cursor = NULL; }
}

TAdEp3Exist::TAdEp3Exist(TObject *parent) : TObject(parent) {
    s8 flag[16];
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
    res = ((TAdSinglePlyChrSelectGC *)flag)->load_and_verify_character_save((char *)save);
    ok = false;
    if (res != 0) {
        if (flag[0] != 0) {
            ok = true;
        }
    }
    go = false;
    if (ok) {
        if ((s8)((u8 *)TAdSinglePlyChrSelectGC::get_instance())[0x1152C] == 0) {
            go = true;
        }
    }
    if (!go) {
        TAdMultiChgGameModeGC::reset_and_set_mode();
        queue_destruction();
        return;
    }
    new TAdBackGC(this);
    new TAdBackTxtGC(this);
    scroll_window = new TAdScrollWinGC(this, 3, (s32)get_localized_text_entry(0x2C, 9));
    cursor = new TAdSelectCurGC(tl_clipout, (const NJS_POINT2 *)lbl_8047B8A8, (const NJS_POINT2 *)lbl_8047B8B0);
    cursor->append_entry((void *)lbl_8047B8A8);
    cursor->set_wait_directions_released();
    cursor->set_selection_index(0);
}
