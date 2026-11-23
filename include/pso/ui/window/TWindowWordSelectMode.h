#ifndef PSO_UI_WINDOW_TWINDOW_WORD_SELECT_MODE_H
#define PSO_UI_WINDOW_TWINDOW_WORD_SELECT_MODE_H
#include "types.h"
#include "pso/ui/window/TWindowBase.h"

// The three-row mode indicator owned by the Word Select window.
class TWindowWordSelectMode : public TWindowBase {
public:
    TWindowWordSelectMode();
    virtual ~TWindowWordSelectMode();
    virtual void run_task();
    virtual void render();
    s32 pad_60; // nonzero hides the selected row's highlight
    s32 pad_64; // rows below this index draw grey, the rest white
    s32 pad_68; // selected row
};
LAYOUT_ASSERT(TWindowWordSelectMode_size, sizeof(TWindowWordSelectMode) == 0x6C);

LAYOUT_ASSERT(TWindowWordSelectMode_pad_60, offsetof(TWindowWordSelectMode, pad_60) == 0x60);
LAYOUT_ASSERT(TWindowWordSelectMode_pad_64, offsetof(TWindowWordSelectMode, pad_64) == 0x64);
LAYOUT_ASSERT(TWindowWordSelectMode_pad_68, offsetof(TWindowWordSelectMode, pad_68) == 0x68);

#endif
