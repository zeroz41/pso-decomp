#ifndef PSO_UI_WINDOW_TWINDOWUSERSORT_H
#define PSO_UI_WINDOW_TWINDOWUSERSORT_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"

struct TWindowUserSort : public TWindowBase {
    TWindowUserSort(s32 arg1, s32 arg2);
    virtual void render();
    virtual ~TWindowUserSort();
    u32 m_60;
    virtual void run_task();
};

typedef char TWindowUserSort_size[sizeof(TWindowUserSort) == 0x64 ? 1 : -1];
#endif
