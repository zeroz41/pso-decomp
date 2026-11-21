#ifndef PSO_UI_WINDOW_TWINDOWBREAKIN_H
#define PSO_UI_WINDOW_TWINDOWBREAKIN_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"

struct TWindowBreakIn : public TWindowBase {
    TWindowBreakIn();
    virtual ~TWindowBreakIn();
    virtual void render();
    virtual void run_task();
};

LAYOUT_ASSERT(TWindowBreakIn_size, sizeof(TWindowBreakIn) == 0x60);

#endif
