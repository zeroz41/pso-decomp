#include "pso/system/SoundEffect.h"
#include "types.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/frontend/TAdWarningBaseGC.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/ControllerInput.h"
#include "pso/system/task/TObject.h"
#include "pso/system/GbaAramCache.h"

const char *lbl_805D4208 = "TAdWarningBaseGC";
static const f32 lbl_80477334[2] = {46.0f, 131.0f};
static const f32 lbl_8047733C[2] = {548.0f, 220.0f};

extern "C" {

void clear_aram_request_busy(uaddr request) { aram_request_busy_flag = 0; }


void TAdWarningBaseGC::vfunc_9() {
    if (TMainTask::get_render_pass() == 1) { return;
    }
}

saddr TAdWarningBaseGC::sub_8032D214() {
    saddr r = (saddr)create_message_window_for_size((NJS_POINT2 *)lbl_80477334, (NJS_POINT2 *)lbl_8047733C);
    ((TWindowMessage *)r)->append_line(vfunc_7(), 3);
    return r;
}

void TAdWarningBaseGC::vfunc_8() {
    ControllerInputContext *a;
    ControllerInputContext *b;
    prev_state = state;
    switch (state) {
    case 0:
        message_window = (TWindowBase *)sub_8032D214();
        state = 1;
        break;
    case 1:
        play_sound_effect(0x53F06, 0, 0, 0);
        state = 2;
        break;
    case 2:
        if (test_pressed_buttons_packed(a = &controller_physical_port_bank.controllers[0], 4) != 0 ||
            test_controller_flag_4c_color(b = &controller_input_state.keyboard, 4) != 0 ||
            test_pressed_buttons_packed(a, 2) != 0 ||
            test_controller_flag_4c_color(b, 2) != 0) {
            state = 3;
            next_state = 4;
        }
        break;
    case 3:
        if (message_window != NULL) {
            message_window->close();
            message_window = NULL;
        }
        if ((f32)++frames > 4.5f) {
            state = next_state;
        }
        break;
    case 4:
        vfunc_6();
        break;
    }
    if (prev_state != state) {
        frames = 0;
    }
}

TAdWarningBaseGC::~TAdWarningBaseGC() {
    if (message_window != NULL) {
        message_window->queue_destruction();
        message_window = NULL;
    }
}


TAdWarningBaseGC::TAdWarningBaseGC(TObject *parent) : TObject(parent) {
    m_name = lbl_805D4208;
    frames = 0;
    state = 0;
    next_state = 0;
    message_window = NULL;
    new TAdBackGC(this);
    new TAdBackTxtGC(this);
}

}
