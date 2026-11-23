#include "types.h"
#include "pso/ui/window/TObjCHTimeWin_80074C94.h"
#include "pso/ui/window/TObjCHTimeWin.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowCtrlMain_8024CB7C.h"

#pragma readonly_strings on

extern "C" {


extern saddr TObjCHTimeWin__timer_value;
const char *TObjCHTimeWin__class_name = "TObjCHTimeWin";

}

void TObjCHTimeWin::run_task() {
    if (timer_created != 0) {
        TWindowCtrl::set_timer_window_time(TObjCHTimeWin__timer_value);
        return;
    }
    if (has_window_task_root() == 1) {
        init_timer();
        timer_created = 1;
    }
}

void TObjCHTimeWin::init_timer(void) { TWindowCtrl::create_alt_timer(); TWindowCtrl::set_timer_window_time(TObjCHTimeWin__timer_value); }

TObjCHTimeWin::~TObjCHTimeWin() {}

TObjCHTimeWin::TObjCHTimeWin(TObject *parent) : TObject(parent) {
    m_name = TObjCHTimeWin__class_name;
    timer_created = 0;
}

TObjCHTimeWin *create_ch_time_win(TObject *parent) {
    return new TObjCHTimeWin(parent);
}
