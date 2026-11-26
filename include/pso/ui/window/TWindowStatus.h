#ifndef PSO_UI_WINDOW_TWINDOWSTATUS_H
#define PSO_UI_WINDOW_TWINDOWSTATUS_H

#include "types.h"
#include "pso/ui/window/TWindowSimpleStatus.h"

struct TWindowStatus : public TWindowSimpleStatus {
    TWindowStatus(void *position, s32 client, u8 *descriptor);
    virtual ~TWindowStatus();
    static const char *class_name;
    virtual void render();
    virtual void run_task();
    void draw_background(WindowDrawContext *context);
    void update_hp_tp_values();
};

LAYOUT_ASSERT(TWindowStatus_size, sizeof(TWindowStatus) == 0x78);

TWindowSimpleStatus *create_status_window(saddr client);
#endif
