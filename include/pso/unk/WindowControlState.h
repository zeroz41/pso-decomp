#ifndef PSO_UNK_WINDOWCONTROLSTATE_H
#define PSO_UNK_WINDOWCONTROLSTATE_H

#include "types.h"
#include <stddef.h>

struct WindowControlState {
    s32 field00;
    s32 field04;
    f32 field08;
    f32 field0C;
    f32 field10;
    f32 field14;
    f32 field18;
};

typedef char WindowControlState_size[sizeof(WindowControlState) == 0x1C ? 1 : -1];
typedef char WindowControlState_field0C[offsetof(WindowControlState, field0C) == 0xC ? 1 : -1];
typedef char WindowControlState_field18[offsetof(WindowControlState, field18) == 0x18 ? 1 : -1];

WindowControlState* get_window_control_state(s32 viewport_index);

#endif
