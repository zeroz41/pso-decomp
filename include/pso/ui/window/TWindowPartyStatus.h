#ifndef PSO_UI_WINDOW_TWINDOWPARTYSTATUS_H
#define PSO_UI_WINDOW_TWINDOWPARTYSTATUS_H

#include "types.h"
#include "pso/ui/window/TWindowSimpleStatus.h"

struct TWindowPartyStatus : public TWindowSimpleStatus {
    TWindowPartyStatus(s32 slot, u8 *descriptor);
    virtual ~TWindowPartyStatus();
    virtual void render();
    void draw();
    void draw_background(u8 *ctx);
    virtual void run_task();
};

LAYOUT_ASSERT(TWindowPartyStatus_size, sizeof(TWindowPartyStatus) == 0x78);
#endif
