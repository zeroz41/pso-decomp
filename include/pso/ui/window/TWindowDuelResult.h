#ifndef PSO_UI_WINDOW_TWINDOWDUELRESULT_H
#define PSO_UI_WINDOW_TWINDOWDUELRESULT_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"

struct PageIndicator;

struct TWindowDuelResult : public TWindowBase {
    TWindowDuelResult(s32 client);
    virtual ~TWindowDuelResult();
    virtual void run_task();
    virtual void render();
    void sub_8024F094();
    void sub_8024EF40();
    void sub_8024F090();
    void sub_8024EF3C();
    void sub_8024F3CC();
    void sub_8024F330();

    f32 scale_x;
    f32 scale_y;
    PageIndicator *page_indicator;
    static int set_default_status(void *p, int a1);
};

LAYOUT_ASSERT(TWindowDuelResult_size, sizeof(TWindowDuelResult) == 0x6C);
#endif
