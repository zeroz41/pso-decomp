#ifndef PSO_SYSTEM_CONTROLLERINPUTSTATE_H
#define PSO_SYSTEM_CONTROLLERINPUTSTATE_H

#include "types.h"
#include <stddef.h>

struct ControllerInputContext {
    s32 poll_key_state();
    // Clears the buttons, triggers and sticks.
    void reset();
    // Whether a button in mask is held / went down this frame.
    s32 is_held(s32 mask);
    s32 is_pressed(s32 mask);

    u32 buttons;
    u32 not_held;  // ~buttons
    u32 pressed_buttons;  // set the frame a button goes down
    u32 released;
    u16 trigger_r;
    u16 trigger_l;
    // Main analog stick, signed.
    s16 stick_x;
    s16 stick_y;
    // C stick, signed.
    s16 cstick_x;
    s16 cstick_y;
    // Stick directions: atan2 of each stick plus the camera's yaw.
    s32 stick_angle;
    s32 cstick_angle;
    f32 stick_magnitude;
    f32 cstick_magnitude;
    s16 hold_frames[14];  // frames each input_button_mask_table button has been held
    // buttons plus the stick directions as digital bits (main stick 0x100000-0x800000,
    // C stick 0x04000000-0x20000000), and the bits of it that went down this frame.
    u32 held_with_sticks;
    u32 pressed_with_sticks;
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
LAYOUT_ASSERT(ControllerInputContext_hold_frames_offset, offsetof(ControllerInputContext, hold_frames) == 0x2C);
LAYOUT_ASSERT(ControllerInputState_keyboard_offset, offsetof(ControllerInputState, keyboard) == 0x160);
LAYOUT_ASSERT(ControllerInputState_controllers_offset, offsetof(ControllerInputState, controllers) == 0x20);
LAYOUT_ASSERT(ControllerInputState_size, sizeof(ControllerInputState) == 0x1B0);

extern ControllerInputState controller_input_state;
extern ControllerInputState controller_physical_port_bank;

#endif
