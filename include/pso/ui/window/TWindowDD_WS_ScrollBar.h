#ifndef PSO_UI_WINDOW_TWINDOWDD_WS_SCROLLBAR_H
#define PSO_UI_WINDOW_TWINDOWDD_WS_SCROLLBAR_H
#include "types.h"
#include "pso/ui/window/TWindowBase.h"

class TWindowDD_WS_ScrollBar : public TWindowBase {
public:
    virtual ~TWindowDD_WS_ScrollBar();
    TWindowDD_WS_ScrollBar();
    virtual void run_task();
    virtual void render();
    f32 pad_60; // thumb length = track * pad_60 * pad_68; offset = track * pad_60 * pad_6C
    f32 pad_64; // no thumb travel while pad_64 <= pad_68
    f32 pad_68;
    f32 pad_6C;
};
LAYOUT_ASSERT(TWindowDD_WS_ScrollBar_size, sizeof(TWindowDD_WS_ScrollBar) == 0x70);

LAYOUT_ASSERT(TWindowDD_WS_ScrollBar_pad_60, offsetof(TWindowDD_WS_ScrollBar, pad_60) == 0x60);
LAYOUT_ASSERT(TWindowDD_WS_ScrollBar_pad_64, offsetof(TWindowDD_WS_ScrollBar, pad_64) == 0x64);
LAYOUT_ASSERT(TWindowDD_WS_ScrollBar_pad_68, offsetof(TWindowDD_WS_ScrollBar, pad_68) == 0x68);
LAYOUT_ASSERT(TWindowDD_WS_ScrollBar_pad_6C, offsetof(TWindowDD_WS_ScrollBar, pad_6C) == 0x6C);

#endif
