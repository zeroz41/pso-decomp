#ifndef PSO_UI_WINDOW_TWINDOWDEPOSIT_H
#define PSO_UI_WINDOW_TWINDOWDEPOSIT_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"

struct TWindowDeposit : public TWindowBase {
    TWindowDeposit(s16 client);
    virtual ~TWindowDeposit();
    static const char *class_name;
    virtual void render();
    f32 width;
    f32 scale[2];
    void render_status(WindowDrawContext *context);
    // The bank meseta the window shows.
    void set_meseta(s32 meseta);
    virtual void run_task();
};

LAYOUT_ASSERT(TWindowDeposit_size, sizeof(TWindowDeposit) == 0x6C);


#endif
