#include "types.h"
#include "pso/ui/charcreate/TObjCMProportion.h"
#include "pso/ui/charcreate/CreationInput.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/keyboard/TKeyBoardControl_803DE9C4.h"
#include "pso/ui/charcreate/TChCrCharSelect.h"
#include "pso/unk/text_802993F0.h"
#include "pso/unk/text_80299420.h"
#include "pso/system/ControllerInput.h"
#include "pso/player/TObjPlayer_80011014.h"
__declspec(section ".rodata") CreationInputState default_creation_input_state = { 0 };

static s32 cm_proportion_pad_button_masks[4] = {0x10, 0x20, 0x40, 0x80};
static s32 creation_direction_priority_masks[4] = {0x10, 0x20, 0x40, 0x80};
CreationInputState creation_input_state;

f32 TObjCMProportion::get_ratio() {
    return (f32) get_creation_pad()->trigR / 255.0f;
}
f32 TObjCMProportion::get_right_trigger_ratio() {
    return (f32) get_creation_pad()->trigL / 255.0f;
}

#pragma push
#pragma fp_contract on
void get_creation_pad_stick(s32 *angle, f32 *magnitude) {
    f32 x;
    f32 y;
    f32 d;
    s32 ang;
    x = (f32)get_creation_pad()->stickX;
    y = (f32)get_creation_pad()->stickY;
    ang = (s32)(10430.38043493439 * atan2_float(x, -y));
    d = newton_sqrtf(x * x + y * y) / creation_stick_range;
    if (d > 1.0f) {
        d = 1.0f;
    }
    if (d < creation_stick_dead_zone) {
        ang = 0;
        d = creation_stick_zero;
    }
    if (angle != NULL) {
        *angle = ang;
    }
    if (magnitude != NULL) {
        *magnitude = d;
    }
}
#pragma pop

s32 creation_buttons_held(s32 mask) {
    return (u8) ((creation_input_state.held_buttons & mask) != 0);
}
s32 creation_buttons_pressed(s32 mask) {
    return (u8) ((creation_input_state.pressed_buttons & mask) != 0);
}
void update_creation_direction_repeat(void) {
    s32 held;
    s32 rest;
    s32 *p;
    held = creation_input_state.held_buttons & 0xF0;
    creation_input_state.repeated_buttons = 0;
    if (held == 0) {
        creation_input_state.repeat_frames = 0;
        creation_input_state.repeat_direction = 0;
        creation_input_state.repeated_buttons = 0;
        return;
    }
    if (held & creation_input_state.repeat_direction) {
        creation_input_state.repeat_frames++;
        if (creation_input_state.repeat_frames == 7 || creation_input_state.repeat_frames >= 10) {
            creation_input_state.repeated_buttons = creation_input_state.repeat_direction;
            creation_input_state.repeat_frames = 7;
        }
        return;
    }
    rest = held;
    p = creation_direction_priority_masks;
    while ((rest &= ~*p) != 0) {
        p++;
    }
    creation_input_state.repeat_direction = held & *p;
    creation_input_state.repeated_buttons = creation_input_state.repeat_direction;
    creation_input_state.repeat_frames = 0;
}
void TObjCMProportion::poll_pad_buttons() {
    s32 old;
    s32 i;
    old = creation_input_state.held_buttons;
    creation_input_state.held_buttons = get_creation_pad()->held;
    if (!(creation_input_state.held_buttons & 0xF0)) {
        if (get_creation_pad()->stickX < -0x73) {
            creation_input_state.held_buttons |= 0x40;
        } else if (get_creation_pad()->stickX > 0x73) {
            creation_input_state.held_buttons |= 0x80;
        } else if (get_creation_pad()->stickY < -0x73) {
            creation_input_state.held_buttons |= 0x10;
        } else if (get_creation_pad()->stickY > 0x73) {
            creation_input_state.held_buttons |= 0x20;
        } else {
            for (i = 0; i < 4; i++) {
                if (test_previous_buttons_color(&controller_input_state.keyboard, cm_proportion_pad_button_masks[i]) != 0) {
                    creation_input_state.held_buttons |= cm_proportion_pad_button_masks[i];
                    break;
                }
            }
        }
    }
    if (!(creation_input_state.held_buttons & 4) && test_previous_buttons_color(&controller_input_state.keyboard, 4) != 0) {
        creation_input_state.held_buttons |= 4;
    }
    if (!(creation_input_state.held_buttons & 2) && test_previous_buttons_color(&controller_input_state.keyboard, 2) != 0) {
        creation_input_state.held_buttons |= 2;
    }
    creation_input_state.pressed_buttons = creation_input_state.held_buttons & ~old;
}

__declspec(section ".sdata2") extern const f32 creation_stick_range = 115.2f;
__declspec(section ".sdata2") extern const f32 creation_stick_dead_zone = 0.1f;
__declspec(section ".sdata2") extern const f32 creation_stick_zero = 0.0f;

void TChCrCharSelect::reset_proportions() { TObjCMProportion::poll_pad_buttons(); update_creation_direction_repeat(); }

void fn_802993F0(void) {
    fn_80299420(&creation_input_state, &default_creation_input_state);
}
