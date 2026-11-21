#ifndef PSO_UI_WINDOW_TWINDOWCOST_H
#define PSO_UI_WINDOW_TWINDOWCOST_H

#include "types.h"
#include "pso/ui/window/TWindowMeseta.h"

struct TWindowCost : public TWindowMeseta {
    TWindowCost(void *position, s32 client, s32 text);
    virtual ~TWindowCost();
    virtual void run_task();
    void set_cost(s32 cost);
};

LAYOUT_ASSERT(TWindowCost_size, sizeof(TWindowCost) == 0x74);
extern "C" {
TWindowCost *create_cost_window(s32 client);
}

#endif
