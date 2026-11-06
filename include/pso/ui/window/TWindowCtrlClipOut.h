#ifndef PSO_UI_WINDOW_TWINDOWCTRLCLIPOUT_H
#define PSO_UI_WINDOW_TWINDOWCTRLCLIPOUT_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowCtrlClipOut : public TObject {
    virtual ~TWindowCtrlClipOut();
    virtual void render();
};

typedef char TWindowCtrlClipOut_size[sizeof(TWindowCtrlClipOut) == 0x1C ? 1 : -1];

extern "C" {
void *TWindowCtrlClipOut__ct(void *window_ctrl_clip_out);
u8 *__dt__18TWindowCtrlClipOutFv(u8 *arg0, s16 arg1);
}

// --- C functions defined in TWindowCtrlClipOut.cpp ---
extern "C" {
void *TWindowCtrlClipOut__ct(void *window_ctrl_clip_out);
u8 *__dt__18TWindowCtrlClipOutFv(u8 *arg0, s16 arg1);
}
// --- end of C functions

#endif
