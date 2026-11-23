#ifndef PSO_PLAYER_PLAYERPADBINDING_H
#define PSO_PLAYER_PLAYERPADBINDING_H

#include "types.h"
#include "pso/system/ControllerInputState.h"

// The controller a player reads (TObjPlayer + 0x550): the port's input
// context, which of its buttons the player may use, and whether its buttons
// and stick are enabled.
struct PlayerPadBinding {
    PlayerPadBinding();
    ~PlayerPadBinding();
    // Binds the player to the controller in port.
    void init(u16 entity_id, s16 port);
    s32 get_stick_angle();
    f32 get_stick_magnitude();
    // Whether a button in mask is held / went down this frame (0 while the
    // buttons are disabled or mask is not enabled).
    s32 is_button_held(s32 mask);
    s32 is_button_pressed(s32 mask);
    int stick_enabled();
    int buttons_enabled();
    s32 is_button_enabled(s32 mask);
    // Lets / stops the player use the buttons in mask (enabled_buttons).
    void enable_buttons(u32 mask);
    void disable_buttons(u32 mask);
    ControllerInputContext *get_controller();

    u16 entity_id;
    s16 port;
    // Bit 0: buttons enabled, bit 1: stick enabled.
    u32 flags;
    s32 enabled_buttons;
    ControllerInputContext *controller;
    ControllerInputContext state;
};

LAYOUT_ASSERT(PlayerPadBindingSize, sizeof(PlayerPadBinding) == 0x60);

#endif
