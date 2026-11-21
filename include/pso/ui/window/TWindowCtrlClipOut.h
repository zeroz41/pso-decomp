#ifndef PSO_UI_WINDOW_TWINDOWCTRLCLIPOUT_H
#define PSO_UI_WINDOW_TWINDOWCTRLCLIPOUT_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowCtrlClipOut : public TObject {
    TWindowCtrlClipOut(TObject *parent);
    virtual ~TWindowCtrlClipOut();
    virtual void render();
};

LAYOUT_ASSERT(TWindowCtrlClipOut_size, sizeof(TWindowCtrlClipOut) == 0x1C);

#endif
