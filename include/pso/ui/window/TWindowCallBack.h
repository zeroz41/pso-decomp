#ifndef PSO_UI_WINDOW_TWINDOWCALLBACK_H
#define PSO_UI_WINDOW_TWINDOWCALLBACK_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/WindowCallback.h"

struct TWindowCallBack : public TWindowBase {
    TWindowCallBack(u8 *position, u8 *scale, WindowCallback callback_function);
    virtual ~TWindowCallBack();
    void render();
    void run_task();
    void set_field_60(WindowCallback callback_function);
    WindowCallback callback;
};

LAYOUT_ASSERT(TWindowCallBack_size, sizeof(TWindowCallBack) == 0x64);
LAYOUT_ASSERT(TWindowCallBack_callback_offset, offsetof(TWindowCallBack, callback) == 0x60);

#endif
