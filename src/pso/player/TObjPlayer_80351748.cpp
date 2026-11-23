#include "types.h"
#include "pso/system/ControllerInputState.h"
#include "pso/quest/TQuestListVM_8007EAF8.h"
#include "pso/player/PlayerPadBinding.h"

s32 PlayerPadBinding::get_stick_angle() {
    if (controller == NULL) {
        return 0;
    }
    if (stick_enabled() != 0) {
        return controller->stick_angle;
    }
    return 0;
}


f32 PlayerPadBinding::get_stick_magnitude() {
    if (controller == NULL) {
        return 0.0f;
    }
    if (stick_enabled() != 0) {
        return controller->stick_magnitude;
    }
    return 0.0f;
}
s32 PlayerPadBinding::is_button_held(s32 mask) {
    if (controller == NULL) {
        return 0;
    }
    if ((buttons_enabled() == 0) || (is_button_enabled(mask) == 0)) {
        return 0;
    }
    return controller->is_held(mask);
}
s32 PlayerPadBinding::is_button_pressed(s32 mask) {
    if (controller == NULL) {
        return 0;
    }
    if ((buttons_enabled() == 0) || (is_button_enabled(mask) == 0)) {
        return 0;
    }
    return controller->is_pressed(mask);
}

void PlayerPadBinding::init(u16 entity_id, s16 port) {
    this->entity_id = entity_id;
    this->port = port;
    flags = -1;
    enabled_buttons = -1;
    controller = &controller_input_state.controllers[this->port];
    state.reset();
}

PlayerPadBinding::~PlayerPadBinding() {}

PlayerPadBinding::PlayerPadBinding() {
    entity_id = 0xFFFF;
    port = 0;
    flags = -1;
    enabled_buttons = -1;
    controller = NULL;
    state.reset();
}

int PlayerPadBinding::stick_enabled() { return (flags >> 1) & 0x1; }
s32 PlayerPadBinding::is_button_enabled(s32 mask) {
    return (u8)((enabled_buttons & mask) != 0);
}
int PlayerPadBinding::buttons_enabled() { return flags & 0x1; }
s32 ControllerInputContext::is_held(s32 mask) {
    return (u8)((buttons & mask) != 0);
}
s32 ControllerInputContext::is_pressed(s32 mask) {
    return (u8)((pressed_buttons & mask) != 0);
}
