#ifndef PSO_UI_WINDOW_TWINDOWCOST_H
#define PSO_UI_WINDOW_TWINDOWCOST_H

#include "types.h"
#include "pso/ui/window/TWindowMeseta.h"

struct TWindowCost : public TWindowMeseta {
    TWindowCost(s32 arg1, s32 arg2, s32 str);
    virtual ~TWindowCost();
    virtual void run_task();
};

typedef char TWindowCost_size[sizeof(TWindowCost) == 0x74 ? 1 : -1];
#endif
