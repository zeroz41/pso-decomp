#ifndef PSO_UI_WINDOW_TWINDOWAREA_H
#define PSO_UI_WINDOW_TWINDOWAREA_H

#include "types.h"
#include "pso/ui/window/TWindowRoom.h"

class TWindowArea : public TWindowRoom {
public:
    TWindowArea();
    virtual ~TWindowArea();
    virtual void run_task();
};

#endif
