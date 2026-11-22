#ifndef PSO_SYSTEM_CONTROLLERINPUT_H
#define PSO_SYSTEM_CONTROLLERINPUT_H

#include "types.h"

struct ControllerInputContext;

// Pad button bits, one per hold counter of a ControllerInputContext.
extern const u32 input_button_mask_table[14];

void init_stick_escape_detector(void *detector, void *target);
void accumulate_key_bits(s32 key, s32 *bits);
void update_button_hold_counter(void *pad, void *counter, int mask, int held);

extern "C" {
s32 TKeyBoardControl__sub_801A58B0(void);
s32 TKeyBoardControl__sub_801A58D8(void);
void update_state_from_input__16TKeyBoardControlFPv(u8 key);
void fn_801A6A28(ControllerInputContext *pad, u32 mask, u32 previous);
void map_c_stick_to_buttons(ControllerInputContext *pad, s16 x, s16 y, s32 previous);
void map_main_stick_to_buttons(ControllerInputContext *pad, s16 x, s16 y, s32 previous);
void update_button_hold_counters(ControllerInputContext *pad);
s32 TRaderMapCore__sub_801A6D00(void *pad, s32 mask);
s32 pack_flags__13TRaderMapCoreFii(s32 pad, s32 mask);
s32 test_flags_04_packed(void *pad, s32 mask);
s32 test_controller_flag_4c_color(void *pad, s32 mask);
s32 TWindowShortListCtrl__check_controller_button(void *pad, s32 mask);
s32 test_previous_buttons_color(void *pad, s32 mask);
s32 test_previous_buttons_remapped(void *pad, s32 mask);
s32 test_previous_buttons_packed(void *pad, s32 mask);
s32 check_packed_flag_match(ControllerInputContext *pad, u32 mask, s32 delay, s32 period);
s32 input_press_or_repeat(ControllerInputContext *pad, u32 mask, s32 delay, s32 period);
}

#endif
