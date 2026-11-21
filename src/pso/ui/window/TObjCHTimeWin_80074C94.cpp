#include "types.h"
#include "pso/ui/window/TObjCHTimeWin_80074C94.h"
#include "pso/ui/window/TObjCHTimeWin.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/system/task/TObject.h"

#pragma readonly_strings on

extern "C" {

s32 has_window_task_root();
void __ct__7TObjectFP7TObject(void *);

extern saddr TObjCHTimeWin__timer_value;
extern s32 __vt__13TObjCHTimeWin[];
const char *TObjCHTimeWin__class_name = "TObjCHTimeWin";

void TObjCHTimeWin::run_task() {
    if ((s32) *(s32 *)((s8 *)this + 0x1C) != 0) {
        ((TWindowCtrl *)TObjCHTimeWin__timer_value)->set_timer_window_time();
        return;
    }
    if (has_window_task_root() == 1) {
        ((s32 (*)(void *))TObjCHTimeWin::init_timer)(this);
        *(s32 *)((s8 *)this + 0x1C) = 1;
    }
}

void TObjCHTimeWin::init_timer(void) { TWindowCtrl::create_alt_timer(); ((TWindowCtrl *)TObjCHTimeWin__timer_value)->set_timer_window_time(); }

}

TObjCHTimeWin::~TObjCHTimeWin() {}

void *__ct__13TObjCHTimeWinFv(void *obj_ch_time_win) {
    __ct__7TObjectFP7TObject(obj_ch_time_win);
    *(s32 **)((s8 *)obj_ch_time_win + 0x18) = __vt__13TObjCHTimeWin;
    ((TObjCHTimeWin *)obj_ch_time_win)->m_name = TObjCHTimeWin__class_name;
    *(u32 *)((s8 *)obj_ch_time_win + 0x1C) = 0;
    return obj_ch_time_win;
}

void *create_ch_time_win(void *arg0) {
    void *o = TObject::operator new(0x20);
    if (o != NULL) {
        o = ((void *(*)(void *, void *))__ct__13TObjCHTimeWinFv)(o, arg0);
    }
    return o;
}
