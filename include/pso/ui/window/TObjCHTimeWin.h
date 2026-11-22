#ifndef PSO_UI_WINDOW_TOBJCHTIMEWIN_H
#define PSO_UI_WINDOW_TOBJCHTIMEWIN_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TObjCHTimeWin : public TObject {
public:
    TObjCHTimeWin(TObject *parent);
    virtual ~TObjCHTimeWin();
    virtual void run_task();
    void init_timer();

    s32 timer_created; // set once init_timer has created the timer window
};

TObjCHTimeWin *create_ch_time_win(TObject *parent);

void set_challenge_time_window_timer(int a0);

#endif
