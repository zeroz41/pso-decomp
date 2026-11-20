#ifndef PSO_UI_WINDOW_TWINDOWCOST_H
#define PSO_UI_WINDOW_TWINDOWCOST_H

#include "types.h"
#include "pso/ui/window/TWindowMeseta.h"

struct TWindowCost : public TWindowMeseta {
    virtual ~TWindowCost();
    virtual void run_task();
};

LAYOUT_ASSERT(TWindowCost_size, sizeof(TWindowCost) == 0x74);
#endif
