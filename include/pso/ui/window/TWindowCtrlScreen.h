#ifndef PSO_UI_WINDOW_TWINDOWCTRLSCREEN_H
#define PSO_UI_WINDOW_TWINDOWCTRLSCREEN_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowCtrlScreen : public TObject {
    static const char *class_name;
    TWindowCtrlScreen(TObject *parent);
    virtual ~TWindowCtrlScreen();
    virtual void render();
};

LAYOUT_ASSERT(TWindowCtrlScreen_size, sizeof(TWindowCtrlScreen) == 0x1C);

#endif
