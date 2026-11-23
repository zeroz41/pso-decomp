#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/frontend/TAdDialingMessageWindow.h"
#include "pso/ui/frontend/TAdDialingGC_80328B20.h"
#include "pso/ui/frontend/TAdDrawLineCtrl.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"
#include "pso/system/task/TMainTask.h"

extern "C" {
const char *TAdDialingMessageWindow__name = "TAdDialingMessageWindow";

const NJS_POINT2 lbl_8047A400 = {0.0f, 28.0f};
const NJS_POINT2 lbl_8047A408 = {640.0f, 84.0f};
}

TAdDialingMessageWindow::TAdDialingMessageWindow(const char *message, u32 delay) : TObject(tl_fadeafter) {
    m_name = TAdDialingMessageWindow__name;
    flags = 0;
    this->message = message;
    timer = new TAdDialingMessageTimer(tl_camera, this, delay);
    line_root = new TObject(NULL);
}

TAdDialingMessageWindow::~TAdDialingMessageWindow() {
    if (timer != NULL) {
        timer->queue_destruction();
    }
    if (line_root != NULL) {
        delete line_root;
    }
}

void TAdDialingMessageWindow::render() {
    if (flags & 1) {
        draw_dialing_rectangle(&lbl_8047A400, &lbl_8047A408);
        if (message != NULL) {
            draw_menu_font_string_white(message, 23.0f, 356.0f);
        }
    }
    if (line_root != NULL) {
        line_root->render_nodes();
    }
}

void TAdDialingMessageWindow::run_child_tasks() {
    if (line_root != NULL) {
        line_root->run_tasks();
    }
}

void TAdDialingMessageWindow::set_flag_and_notify() {
    flags |= 1;
    create_draw_line_ctrl(line_root, 17, 0.0f);
}

TAdDialingMessageTimer::TAdDialingMessageTimer(TObject *parent, TAdDialingMessageWindow *window, u32 delay) : TObject(parent) {
    this->window = window;
    countdown = delay;
}

TAdDialingMessageTimer::~TAdDialingMessageTimer() {
}

void TAdDialingMessageTimer::run_task() {
    if (window != NULL) {
        if (countdown != 0) {
            countdown = countdown - 1;
            if (countdown == 0 && window != NULL) {
                window->set_flag_and_notify();
            }
        }
        window->run_child_tasks();
    }
}
