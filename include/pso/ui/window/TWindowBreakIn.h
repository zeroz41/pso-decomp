#ifndef PSO_UI_WINDOW_TWINDOWBREAKIN_H
#define PSO_UI_WINDOW_TWINDOWBREAKIN_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/unk/WindowLayoutRecord.h"

struct TWindowBreakIn : public TWindowBase {
    TWindowBreakIn();
    virtual ~TWindowBreakIn();
    virtual void render();
    virtual void run_task();
};

LAYOUT_ASSERT(TWindowBreakIn_size, sizeof(TWindowBreakIn) == 0x60);

// window_break_in_layout_entries, the layout table window_break_in_layout points at
// (eight sprite parts, cf. window_timer_layout_entries).
struct BreakInWindowLayout {
    u32 cols;
    u32 rows;
    SpritePartLayoutRecord rec[8];
};


#endif
