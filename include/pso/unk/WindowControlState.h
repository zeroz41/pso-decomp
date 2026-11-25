#ifndef PSO_UNK_WINDOWCONTROLSTATE_H
#define PSO_UNK_WINDOWCONTROLSTATE_H

#include "types.h"
#include <stddef.h>

class TObject;

struct WindowControlState {
    void init();
    TObject *window_root; // per-viewport parent of the window tasks (TWindowCtrlMain ct; rendered by TWindowCtrlScreen)
    s32 fill_color;      // packed colour drawn over the whole screen (death tint, scene fades)
    f32 backdrop_alpha;  // fades in while the view is smaller than the screen
    f32 left;            // the view rectangle the windows are kept inside; the whole screen when unset
    f32 top;
    f32 right;
    f32 bottom;
};

LAYOUT_ASSERT(WindowControlState_size, sizeof(WindowControlState) == 0x1C);
LAYOUT_ASSERT(WindowControlState_left, offsetof(WindowControlState, left) == 0xC);
LAYOUT_ASSERT(WindowControlState_bottom, offsetof(WindowControlState, bottom) == 0x18);

WindowControlState* get_window_control_state(s32 viewport_index);

#endif
