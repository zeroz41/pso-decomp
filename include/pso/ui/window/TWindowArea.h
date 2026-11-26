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

void update_area_count_text(TWindowArea *area);
extern "C" {
TWindowArea *create_area_window(void *text);
}
TWindowArea *create_window_area();

#endif
