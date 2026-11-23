#include "types.h"
#include "pso/ui/frontend/TAdDialingMessageWindow.h"

void TUnk_804F3428::run_task() {
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

TUnk_804F3428::~TUnk_804F3428() {
}

TUnk_804F3428::TUnk_804F3428(TObject *parent, TAdDialingMessageWindow *window, u32 delay) : TObject(parent) {
    this->window = window;
    countdown = delay;
}
