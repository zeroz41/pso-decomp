#ifndef PSO_UI_CHARCREATE_CREATIONINPUT_H
#define PSO_UI_CHARCREATE_CREATIONINPUT_H

#include "types.h"

struct CreationInputState {
    s32 m_0;
    s32 repeat_direction;
    s32 repeat_frames;
    s32 held_buttons;
    s32 pressed_buttons;
    s32 repeated_buttons;
};

typedef char CreationInputState_size[sizeof(CreationInputState) == 0x18 ? 1 : -1];

extern CreationInputState creation_input_state;
extern CreationInputState lbl_80465150;

__declspec(section ".sdata2") extern const f32 creation_stick_range;
__declspec(section ".sdata2") extern const f32 creation_stick_dead_zone;
__declspec(section ".sdata2") extern const f32 creation_stick_zero;

s32 creation_buttons_held(s32 mask);
s32 creation_buttons_pressed(s32 mask);
s32 creation_direction_repeated(s32 mask);
void update_creation_direction_repeat();
void get_creation_pad_stick(s32 *angle, f32 *magnitude);

#endif
