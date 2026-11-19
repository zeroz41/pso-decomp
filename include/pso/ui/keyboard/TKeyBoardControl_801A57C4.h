#ifndef PSO_UI_KEYBOARD_TKEYBOARDCONTROL_801A57C4_H
#define PSO_UI_KEYBOARD_TKEYBOARDCONTROL_801A57C4_H

#include "types.h"

// Pad button bits, one per repeat counter of an input record (read by input_press_or_repeat).
extern const u32 input_button_mask_table[14];

void init_stick_escape_detector(void *arg0, void *arg1);
extern "C" {
void TKeyBoardControl__sub_801A58B0(void);
void TKeyBoardControl__sub_801A58D8(void);
void update_state_from_input__16TKeyBoardControlFPv(u8 arg0);
}

#endif
