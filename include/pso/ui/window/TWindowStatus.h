#ifndef PSO_UI_WINDOW_TWINDOWSTATUS_H
#define PSO_UI_WINDOW_TWINDOWSTATUS_H

#include "types.h"
#include "pso/ui/window/TWindowSimpleStatus.h"

struct TWindowStatus : public TWindowSimpleStatus {
    TWindowStatus(void *position, s32 client, u8 *descriptor);
    virtual ~TWindowStatus();
    virtual void render();
    virtual void run_task();
    void draw_background(u8 *ctx);
};

LAYOUT_ASSERT(TWindowStatus_size, sizeof(TWindowStatus) == 0x78);
#endif
