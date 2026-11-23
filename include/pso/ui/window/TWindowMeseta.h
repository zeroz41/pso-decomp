#ifndef PSO_UI_WINDOW_TWINDOWMESETA_H
#define PSO_UI_WINDOW_TWINDOWMESETA_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"

struct TWindowMeseta : public TWindowBase {
    TWindowMeseta(void *position, s32 client, s32 text);
    virtual ~TWindowMeseta();
    virtual void render();
    f32 width;
    u32 client;
    u32 meseta;
    f32 draw_scale[2];
    void run_task();
    s32 get_meseta_value();
    void draw_value(WindowDrawContext *context);
    void set_value(s32 value);
};

LAYOUT_ASSERT(TWindowMeseta_scale_offset, offsetof(TWindowMeseta, draw_scale) == 0x6C);
LAYOUT_ASSERT(TWindowMeseta_size, sizeof(TWindowMeseta) == 0x74);
#endif
