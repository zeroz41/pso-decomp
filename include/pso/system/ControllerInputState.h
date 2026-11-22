#ifndef PSO_SYSTEM_CONTROLLERINPUTSTATE_H
#define PSO_SYSTEM_CONTROLLERINPUTSTATE_H

#include "types.h"
#include <stddef.h>

union ControllerButtonHoldCounters {
    s16 frames[14];
    u32 words[7];
};

struct ControllerInputContext {
    s32 poll_key_state();

    u32 buttons;
    u32 flags_04;
    u32 pressed_buttons;  // set the frame a button goes down (controller_stuff's edge bits)
    u32 released;
    u16 trigger_left;
    u16 trigger_right;
    // Analog stick, signed (inferred: scaled into a turn rate by TAdLdQuestPrtGC).
    s16 stick_x;
    s16 stick_y;
    /* PADStatus-style sticks (field names from the pad copy loop at 0x801A5F1C) */
    s16 cstick_x;
    s16 cstick_y;
    // Stick directions (atan2 of the sticks plus the camera's yaw, from controller_stuff).
    s32 stick_angle;
    s32 cstick_angle;
    f32 stick_magnitude;  // inferred: TObjWarpBoss::sub_8019E418 cancels the warp prompt above 0.25
    f32 cstick_magnitude;
    ControllerButtonHoldCounters hold_counters;
    u32 previous_buttons;
    u32 flags_4c;
};

struct PadSlot;

struct ControllerInputState {
    PadSlot *sources[4];
    s32 source_status[4];
    ControllerInputContext controllers[4];
    ControllerInputContext keyboard;
};

LAYOUT_ASSERT(ControllerInputContext_size, sizeof(ControllerInputContext) == 0x50);
LAYOUT_ASSERT(ControllerInputContext_stick_angle_offset, offsetof(ControllerInputContext, stick_angle) == 0x1C);
LAYOUT_ASSERT(ControllerInputContext_hold_counters_offset, offsetof(ControllerInputContext, hold_counters) == 0x2C);
LAYOUT_ASSERT(ControllerInputState_keyboard_offset, offsetof(ControllerInputState, keyboard) == 0x160);
LAYOUT_ASSERT(ControllerInputState_controllers_offset, offsetof(ControllerInputState, controllers) == 0x20);
LAYOUT_ASSERT(ControllerInputState_size, sizeof(ControllerInputState) == 0x1B0);

extern "C" {
extern ControllerInputState controller_input_state;
extern ControllerInputState controller_physical_port_bank;
}

#endif
