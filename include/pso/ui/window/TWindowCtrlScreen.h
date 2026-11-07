#ifndef PSO_UI_WINDOW_TWINDOWCTRLSCREEN_H
#define PSO_UI_WINDOW_TWINDOWCTRLSCREEN_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowCtrlScreen : public TObject {
    TWindowCtrlScreen(TObject *parent);
    virtual ~TWindowCtrlScreen();
    virtual void render();
};

typedef char TWindowCtrlScreen_size[sizeof(TWindowCtrlScreen) == 0x1C ? 1 : -1];

#endif
