#ifndef PSO_UI_WINDOW_TWINDOWDUELRESULT_H
#define PSO_UI_WINDOW_TWINDOWDUELRESULT_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"

struct PageIndicator;

struct TWindowDuelResult : public TWindowBase {
    static void * layout_entries[140];
    TWindowDuelResult(s32 client);
    virtual ~TWindowDuelResult();
    virtual void run_task();
    virtual void render();
    void build_page_0();
    void build_page_1();
    void update_page_0();
    void update_page_1();
    void sub_8024F3CC();
    void sub_8024F330();

    f32 scale_x;
    f32 scale_y;
    PageIndicator *page_indicator;
    static int set_default_status(void *p, int a1);
};

LAYOUT_ASSERT(TWindowDuelResult_size, sizeof(TWindowDuelResult) == 0x6C);
#endif
