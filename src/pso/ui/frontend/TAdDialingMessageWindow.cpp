#define TOBJECT_OUT_OF_LINE_HELPERS
#pragma readonly_strings on
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"
#include "types.h"
#include "pso/ui/frontend/TAdDialingMessageWindow.h"
#include "pso/ui/frontend/TAdDialingGC_80328B20.h"

#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/frontend/TAdDrawLineCtrl.h"

#include "pso/system/task/TMainTask.h"


extern "C" {
const char *TAdDialingMessageWindow__name = "TAdDialingMessageWindow";

const NJS_POINT2 lbl_8047A400 = {0.0f, 28.0f};
const NJS_POINT2 lbl_8047A408 = {640.0f, 84.0f};
}

void TAdDialingMessageWindow::set_flag_and_notify() {
    flags |= 1;
    create_draw_line_ctrl(line_root, 17, 0.0f);
}

void TAdDialingMessageWindow::run_child_tasks() {
    if (line_root != NULL) {
        line_root->run_tasks();
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

TAdDialingMessageWindow::~TAdDialingMessageWindow() {
    if (timer != NULL) {
        timer->queue_destruction();
    }
    if (line_root != NULL) {
        delete line_root;
    }
}

TAdDialingMessageWindow::TAdDialingMessageWindow(const char *message, u32 delay) : TObject(tl_fadeafter) {
    m_name = TAdDialingMessageWindow__name;
    flags = 0;
    this->message = message;
    timer = new TUnk_804F3428(tl_camera, this, delay);
    line_root = new TObject(NULL);
}
