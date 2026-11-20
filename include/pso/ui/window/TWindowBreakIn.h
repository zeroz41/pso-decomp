#ifndef PSO_UI_WINDOW_TWINDOWBREAKIN_H
#define PSO_UI_WINDOW_TWINDOWBREAKIN_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"

struct TWindowBreakIn : public TWindowBase {
    TWindowBreakIn();
    virtual ~TWindowBreakIn();
    u8 _pad1C[0x8];
    void* m_24;
    virtual void render();
    virtual void run_task();
    u8 unk_28[0x38];
};

LAYOUT_ASSERT(TWindowBreakIn_size, sizeof(TWindowBreakIn) == 0x60);

#endif
