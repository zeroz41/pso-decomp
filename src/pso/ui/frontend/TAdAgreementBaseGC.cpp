#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/frontend/TAdSelectCurGC.h"
#include "types.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/frontend/TAdAgreementBaseGC.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801334D4.h"

#include "pso/ui/TLevelSelect.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/frontend/TAdEnterSerialAccessGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/frontend/TAdSubPlyItemGC.h"
#include "pso/system/task/TObject.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/ControllerInput.h"

static const NJS_POINT2 agreement_item_rect_table[2] = {{89.0f, 394.0f}, {89.0f, 414.0f}};
static const NJS_POINT2 lbl_804770A0 = {462.0f, 18.0f};
const char *lbl_805D41B8 = "TAdAgreementBaseGC";
static const NJS_POINT2 lbl_804770BC = {85.0f, 384.0f};
static const NJS_POINT2 lbl_804770C4 = {470.0f, 60.0f};

extern "C" {
void *__ct__14TAdSelectCurGCFv(void *, TObject *, void *, void *);
void *get_localized_text_entry(int, u32);

void TAdAgreementBaseGC::check_main_task_state() {
    if (TMainTask::get_render_pass() == 1) { return;
    }
}

#pragma push
#pragma fp_contract on
void TAdAgreementBaseGC::draw_agreement_text(void *window, void *frame_context) {
    NJS_POINT2 pos[2];
    u32 i;
    ((TWindowBase *)window)->draw_window_frame(frame_context);
    for (i = 0; i < 2; i++) {
        pos[i].x = 320.0f - (f32) (calc_text_width((char *)(get_localized_text_entry(0x1B, i))) >> 1);
        pos[i].y = 20.0f * (f32) i + 394.0f;
        TAdSubPlyItemGC::render_status_line(pos[i].x, pos[i].y, 0.8f, (const char *)get_localized_text_entry(0x1B, i), -1);
    }
}
#pragma pop

void TAdAgreementBaseGC::vfunc_9() { state = 4; }

void *TAdAgreementBaseGC::create_agreement_callback() {
    return TAdEnterSerialAccessGC::create_callback((void *)&lbl_804770BC, (void *)&lbl_804770C4, TAdAgreementBaseGC::draw_agreement_text);
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
        vfunc_6();
        count = frames + 1;
        frames = count;
        if ((f32) count > 4.5f) {
            state = next_state;
        }
        break;
    case 3:
        vfunc_7();
        break;
    case 4:
        vfunc_8();
        break;
    case 5:
        vfunc_9();
        break;
    }
    if (prev_state != state) {
        frames = 0;
    }
}

}
TAdAgreementBaseGC::~TAdAgreementBaseGC() {
    if (callback_window != NULL) { ((TObject *)callback_window)->queue_destruction(); callback_window = NULL; }
    if (cursor != NULL) { cursor->queue_destruction(); cursor = NULL; }
}


TAdAgreementBaseGC::TAdAgreementBaseGC(TObject *parent) : TObject(parent) {
    m_name = lbl_805D41B8;
    frames = 0;
    state = 0;
    next_state = 0;
    m_34 = 0;
    callback_window = NULL;
    cursor = NULL;
    new TAdBackGC(this);
    new TAdBackTxtGC(this);
    cursor = new TAdSelectCurGC(tl_clipout, agreement_item_rect_table, &lbl_804770A0);
    cursor->append_entry((void *)&agreement_item_rect_table[0]);
    cursor->append_entry((void *)&agreement_item_rect_table[1]);
    fn_80329BAC(cursor);
    cursor->set_selection_index(1);
}

void TAdAgreementBaseGC::vfunc_6() {  }
void TAdAgreementBaseGC::vfunc_7() {  }
void TAdAgreementBaseGC::vfunc_8() {  }
void fn_80329BAC(void* p) { *(s32*)((char*)p + 0xb8) = 1; }
