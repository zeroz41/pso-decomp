#ifndef PSO_UI_WINDOW_TWINDOWCTRLSCREEN_H
#define PSO_UI_WINDOW_TWINDOWCTRLSCREEN_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowCtrlScreen : public TObject {
    virtual ~TWindowCtrlScreen();
    virtual void render();
};

typedef char TWindowCtrlScreen_size[sizeof(TWindowCtrlScreen) == 0x1C ? 1 : -1];

extern "C" {
void *TWindowCtrlScreen__ct(void *window_ctrl_screen);
}

// --- C functions defined in TWindowCtrlScreen.cpp ---
extern "C" {
void *TWindowCtrlScreen__ct(void *window_ctrl_screen);
}
// --- end of C functions

#endif
