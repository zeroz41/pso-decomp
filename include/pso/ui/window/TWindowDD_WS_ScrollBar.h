#ifndef PSO_UI_WINDOW_TWINDOWDD_WS_SCROLLBAR_H
#define PSO_UI_WINDOW_TWINDOWDD_WS_SCROLLBAR_H
#include "types.h"
#include "pso/ui/window/TWindowBase.h"

class TWindowDD_WS_ScrollBar : public TWindowBase {
public:
    virtual ~TWindowDD_WS_ScrollBar();
    TWindowDD_WS_ScrollBar();
    static TWindowDD_WS_ScrollBar *create();
    virtual void run_task();
    virtual void render();
    void set_scale(s32 total, s32 visible);
    void set_value_f32(s32 row);
    f32 inv_total_rows;
    f32 total_rows; // no thumb travel while total_rows <= visible_rows
    f32 visible_rows;
    f32 scroll_row;
};
LAYOUT_ASSERT(TWindowDD_WS_ScrollBar_size, sizeof(TWindowDD_WS_ScrollBar) == 0x70);

LAYOUT_ASSERT(TWindowDD_WS_ScrollBar_pad_60, offsetof(TWindowDD_WS_ScrollBar, inv_total_rows) == 0x60);
LAYOUT_ASSERT(TWindowDD_WS_ScrollBar_pad_64, offsetof(TWindowDD_WS_ScrollBar, total_rows) == 0x64);
LAYOUT_ASSERT(TWindowDD_WS_ScrollBar_pad_68, offsetof(TWindowDD_WS_ScrollBar, visible_rows) == 0x68);
LAYOUT_ASSERT(TWindowDD_WS_ScrollBar_pad_6C, offsetof(TWindowDD_WS_ScrollBar, scroll_row) == 0x6C);

#endif
