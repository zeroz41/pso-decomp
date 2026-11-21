#ifndef PSO_UI_KEYBOARD_TKEYBOARDCONTROL_801A57C4_H
#define PSO_UI_KEYBOARD_TKEYBOARDCONTROL_801A57C4_H

#include "types.h"
#include "pso/ui/keyboard/KeyboardInputQueries.h"

// Pad button bits, one per repeat counter of an input record (read by input_press_or_repeat).
extern const u32 input_button_mask_table[14];

void init_stick_escape_detector(void *arg0, void *arg1);
extern "C" {
void update_state_from_input__16TKeyBoardControlFPv(u8 key);
}

#endif
