#ifndef PSO_UI_WINDOW_TWINDOWSIMPLESTATUS_H
#define PSO_UI_WINDOW_TWINDOWSIMPLESTATUS_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"

struct TWindowSimpleStatus : public TWindowBase {
    TWindowSimpleStatus(void *position, s32 client, u8 *descriptor);
    virtual ~TWindowSimpleStatus();
    void draw_background(u8 *);
    void apply_random_shake();
    void update_status_icons(void *);
    s32 get_width();
    virtual void render();
    u32 m_60;
    virtual void run_task();
    static TWindowSimpleStatus *create(void *position, s32 client);
    TWindowBase *w[5]; // child windows; the dtor closes the first four
};

LAYOUT_ASSERT(TWindowSimpleStatus_size, sizeof(TWindowSimpleStatus) == 0x78);

#endif
