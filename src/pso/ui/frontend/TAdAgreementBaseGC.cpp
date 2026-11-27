#include "pso/ui/frontend/TAdSelectCurGC.h"
#include "types.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/frontend/TAdAgreementBaseGC.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"

#include "pso/ui/TLevelSelect.h"
#include "pso/network/TLobby.h"
#include "pso/ui/frontend/TAdEnterSerialAccessGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/frontend/TAdSubPlyItemGC.h"
#include "pso/system/task/TObject.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/ControllerInput.h"
#include "pso/ui/MenuText.h"
#include "pso/ui/keyboard/KeyBoardMenu.h"

static const NJS_POINT2 agreement_item_rect_table[2] = {{89.0f, 394.0f}, {89.0f, 414.0f}};
static const NJS_POINT2 agreement_cursor_size = {462.0f, 18.0f};
const char *TAdAgreementBaseGC_class_name = "TAdAgreementBaseGC";
static const NJS_POINT2 agreement_text_window_pos = {85.0f, 384.0f};
static const NJS_POINT2 agreement_text_window_size = {470.0f, 60.0f};


void TAdAgreementBaseGC::check_main_task_state() {
    if (TMainTask::get_render_pass() == 1) { return;
    }
}

#pragma push
#pragma fp_contract on
void TAdAgreementBaseGC::draw_agreement_text(void *window, void *frame_context) {
    NJS_POINT2 pos[2];
    u32 i;
    ((TWindowBase *)window)->draw_window_frame((WindowDrawContext *)frame_context);
    for (i = 0; i < 2; i++) {
        pos[i].x = 320.0f - (f32) (calc_text_width((char *)(get_localized_text_entry(0x1B, i))) >> 1);
        pos[i].y = 20.0f * (f32) i + 394.0f;
        draw_menu_text_scaled(pos[i].x, pos[i].y, 0.8f, get_localized_text_entry(0x1B, i), -1);
    }
}
#pragma pop

void TAdAgreementBaseGC::on_cancel() { state = 4; }

void *TAdAgreementBaseGC::create_agreement_callback() {
    return TAdEnterSerialAccessGC::create_callback(&agreement_text_window_pos, &agreement_text_window_size, TAdAgreementBaseGC::draw_agreement_text);
}

void TAdAgreementBaseGC::update_state() {
    s32 count;
    prev_state = state;
    switch (state) {
    case 0:
        callback_window = create_agreement_callback();
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
        } else if ((test_pressed_buttons_packed(&controller_physical_port_bank.controllers[0], 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
            state = 2;
            next_state = 5;
        }
        break;
    case 2:
        if (callback_window != NULL) {
            ((TWindowBase *)callback_window)->close();
            callback_window = NULL;
        }
        on_closing();
        count = frames + 1;
        frames = count;
        if ((f32) count > 4.5f) {
            state = next_state;
        }
        break;
    case 3:
        on_agree();
        break;
    case 4:
        on_decline();
        break;
    case 5:
        on_cancel();
        break;
    }
    if (prev_state != state) {
        frames = 0;
    }
}

TAdAgreementBaseGC::~TAdAgreementBaseGC() {
    if (callback_window != NULL) { ((TObject *)callback_window)->queue_destruction(); callback_window = NULL; }
    if (cursor != NULL) { cursor->queue_destruction(); cursor = NULL; }
}


TAdAgreementBaseGC::TAdAgreementBaseGC(TObject *parent) : TObject(parent) {
    m_name = TAdAgreementBaseGC_class_name;
    frames = 0;
    state = 0;
    next_state = 0;
    m_34 = 0;
    callback_window = NULL;
    cursor = NULL;
    new TAdBackGC(this);
    new TAdBackTxtGC(this);
    cursor = new TAdSelectCurGC(tl_clipout, agreement_item_rect_table, &agreement_cursor_size);
    cursor->append_entry(&agreement_item_rect_table[0]);
    cursor->append_entry(&agreement_item_rect_table[1]);
    cursor->set_wait_directions_released();
    cursor->set_selection_index(1);
}

void TAdAgreementBaseGC::on_closing() {  }
void TAdAgreementBaseGC::on_agree() {  }
void TAdAgreementBaseGC::on_decline() {  }
void TAdSelectCurGC::set_wait_directions_released() { wait_directions_released = 1; }
