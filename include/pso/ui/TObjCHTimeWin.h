#ifndef PSO_UI_TOBJCHTIMEWIN_H
#define PSO_UI_TOBJCHTIMEWIN_H

#include "pso/TObject.h"
#include "types.h"

class TObjCHTimeWin : public TObject {
public:
    virtual ~TObjCHTimeWin();
    virtual void run_task();
};

void set_challenge_time_window_timer(int a0);

#endif
