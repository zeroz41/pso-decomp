#ifndef PSO_UI_WINDOW_TWINDOWCALLBACK_H
#define PSO_UI_WINDOW_TWINDOWCALLBACK_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"

struct TWindowCallBack : public TWindowBase {
    TWindowCallBack(saddr arg1, u8 *arg2, s32 arg3);
    virtual ~TWindowCallBack();
    void render();
    void run_task();
    void (*callback)(TWindowCallBack *, s32);
};

LAYOUT_ASSERT(TWindowCallBack_size, sizeof(TWindowCallBack) == 0x64);
extern "C" {
void set_field_60__15TWindowCallBackFPvi(void *p, s32 v);
}

#endif
