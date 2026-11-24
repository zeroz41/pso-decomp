#ifndef PSO_SYSTEM_CONTROLLERINPUT_H
#define PSO_SYSTEM_CONTROLLERINPUT_H

#include "types.h"
#include "pso/system/ControllerInputState.h"

// Pad button bits, one per hold counter of a ControllerInputContext.
extern const u32 input_button_mask_table[14];

struct StickEscapeDetector;
void init_stick_escape_detector(StickEscapeDetector *detector, const ControllerInputContext *input);
void accumulate_key_bits(s32 key, u32 *buttons);
void update_button_hold_counter(void *pad, void *counter, int mask, int held);

void controller_stuff();

extern "C" {
void bind_controller_devices(void);
void reset_controller_input_state(void);
void update_pad_recalibration(void);
s32 TKeyBoardControl__sub_801A58B0(void);
s32 TKeyBoardControl__sub_801A58D8(void);
s32 update_state_from_input__16TKeyBoardControlFPv(u8 key);
void fn_801A6A28(ControllerInputContext *pad, u32 mask, u32 previous);
void map_c_stick_to_buttons(ControllerInputContext *pad, s16 x, s16 y, s32 previous);
void map_main_stick_to_buttons(ControllerInputContext *pad, s16 x, s16 y, s32 previous);
void update_button_hold_counters(ControllerInputContext *pad);
s32 TRaderMapCore__sub_801A6D00(ControllerInputContext *pad, s32 mask);
s32 pack_flags__13TRaderMapCoreFii(s32 pad, s32 mask);
s32 test_flags_04_packed(ControllerInputContext *pad, s32 mask);
s32 test_controller_flag_4c_color(ControllerInputContext *pad, s32 mask);
s32 test_pressed_buttons_packed(void *pad, s32 mask);
s32 test_previous_buttons_color(ControllerInputContext *pad, s32 mask);
s32 test_previous_buttons_remapped(ControllerInputContext *pad, s32 mask);
s32 test_previous_buttons_packed(void *pad, s32 mask);
s32 test_buttons_press_or_repeat(ControllerInputContext *pad, s32 buttons, s32 delay, s32 period);
s32 check_packed_flag_match(ControllerInputContext *pad, u32 mask, s32 delay, s32 period);
s32 input_press_or_repeat(ControllerInputContext *pad, u32 mask, s32 delay, s32 period);
}

s32 func_801A5E54(void);

#endif
