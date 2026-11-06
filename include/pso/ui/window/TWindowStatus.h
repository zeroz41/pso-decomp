#ifndef PSO_UI_WINDOW_TWINDOWSTATUS_H
#define PSO_UI_WINDOW_TWINDOWSTATUS_H

#include "types.h"
#include "pso/ui/window/TWindowSimpleStatus.h"

struct TWindowStatus : public TWindowSimpleStatus {
    virtual ~TWindowStatus();
    virtual void render();
    virtual void run_task();
    void draw_background(u8 *arg1);
};

typedef char TWindowStatus_size[sizeof(TWindowStatus) == 0x78 ? 1 : -1];
#endif
