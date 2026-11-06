#ifndef PSO_UI_WINDOW_TWINDOWPARTYSTATUS_H
#define PSO_UI_WINDOW_TWINDOWPARTYSTATUS_H

#include "types.h"
#include "pso/ui/window/TWindowSimpleStatus.h"

struct TWindowPartyStatus : public TWindowSimpleStatus {
    virtual ~TWindowPartyStatus();
    virtual void render();
    void draw();
    void draw_background(u8 *arg1);
    virtual void run_task();
};

typedef char TWindowPartyStatus_size[sizeof(TWindowPartyStatus) == 0x78 ? 1 : -1];
#endif
