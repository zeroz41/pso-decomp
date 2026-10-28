#ifndef PSO_SYSTEM_CONTROLLERINPUTSTATE_H
#define PSO_SYSTEM_CONTROLLERINPUTSTATE_H

#include "types.h"

struct ControllerInputContext {
    u32 buttons;
    u8 unknown_04[0x44];
    u32 previous_buttons;
    u8 unknown_4c[4];
};

struct ControllerInputState {
    u8 unknown_00[0x20];
    ControllerInputContext controllers[4];
    ControllerInputContext keyboard;
};

typedef char ControllerInputContext_size[sizeof(ControllerInputContext) == 0x50 ? 1 : -1];
typedef char ControllerInputState_size[sizeof(ControllerInputState) == 0x1B0 ? 1 : -1];

extern "C" {
extern ControllerInputState controller_input_state;
s32 is_flag_set__11TLoadingCurFv(ControllerInputContext *context, s32 mask);
}

#endif
