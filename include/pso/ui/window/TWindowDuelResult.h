#ifndef PSO_UI_WINDOW_TWINDOWDUELRESULT_H
#define PSO_UI_WINDOW_TWINDOWDUELRESULT_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"

struct TWindowDuelResult : public TWindowBase {
    virtual ~TWindowDuelResult();
    f32 scale_x;
    f32 scale_y;
    u32 m_68;
    void *init(void *arg1, void *arg2, void *arg3);
    static int set_default_status(void* p, int a1);
};

typedef char TWindowDuelResult_size[sizeof(TWindowDuelResult) == 0x6C ? 1 : -1];
#endif
