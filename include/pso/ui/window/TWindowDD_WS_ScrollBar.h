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
    void set_range(s32 count, s32 visible);
    void set_first_index(s32 index);
    f32 inverse_count;  // thumb length = track * inverse_count * visible_count; offset = track * inverse_count * first_index
    f32 count;  // entries in the list; no thumb travel while count <= visible_count
    f32 visible_count;
    f32 first_index;  // index of the first visible entry
};
LAYOUT_ASSERT(TWindowDD_WS_ScrollBar_size, sizeof(TWindowDD_WS_ScrollBar) == 0x70);

LAYOUT_ASSERT(TWindowDD_WS_ScrollBar_inverse_count, offsetof(TWindowDD_WS_ScrollBar, inverse_count) == 0x60);
LAYOUT_ASSERT(TWindowDD_WS_ScrollBar_count, offsetof(TWindowDD_WS_ScrollBar, count) == 0x64);
LAYOUT_ASSERT(TWindowDD_WS_ScrollBar_visible_count, offsetof(TWindowDD_WS_ScrollBar, visible_count) == 0x68);
LAYOUT_ASSERT(TWindowDD_WS_ScrollBar_first_index, offsetof(TWindowDD_WS_ScrollBar, first_index) == 0x6C);

#endif
