#ifndef PSO_UI_WINDOW_TWINDOWDUELRESULT_H
#define PSO_UI_WINDOW_TWINDOWDUELRESULT_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"

struct PageIndicator;

struct TWindowDuelResult : public TWindowBase {
    static const char *class_name;
    static void * layout_entries[140];
    TWindowDuelResult(s32 client);
    virtual ~TWindowDuelResult();
    virtual void run_task();
    virtual void render();
    void build_ranking_page();
    void build_stats_page();
    void update_ranking_page();
    void update_stats_page();
    void build_page();
    void update_page();

    f32 scale_x;
    f32 scale_y;
    PageIndicator *page_indicator;
    static int set_default_status(void *p, const char *text);
};

LAYOUT_ASSERT(TWindowDuelResult_size, sizeof(TWindowDuelResult) == 0x6C);
#endif
