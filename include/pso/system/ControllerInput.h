#ifndef PSO_SYSTEM_CONTROLLERINPUT_H
#define PSO_SYSTEM_CONTROLLERINPUT_H

#include "types.h"
#include "pso/system/ControllerInputState.h"

// Pad button bits, one per hold counter of a ControllerInputContext.
extern const u32 input_button_mask_table[14];

struct StickEscapeDetector;
void init_stick_escape_detector(StickEscapeDetector *detector, const ControllerInputContext *input);
void accumulate_key_bits(s32 key, u32 *buttons);
void update_button_hold_counter(ControllerInputContext *pad, s16 *counter, s32 mask, s32 held);

void controller_stuff();

void bind_controller_devices(void);
void reset_controller_input_state(void);
// Clears the pending reset request (controller_reset_requested).
void clear_controller_reset_request(void);
// Whether any pad has a button down or a trigger or the main stick pushed past 10.
s32 any_pad_input_active(void);
// 1 the frame the reset button is let go.
s32 check_reset_button(void);
s32 keyboard_check_and_read(s32 key);
s32 keyboard_read_input(u8 key);
s32 keyboard_is_key_down(s32 key);
s32 keyboard_get_ascii_key(void);
s32 keyboard_read_key_checked(u8 key);
void update_keyboard_input_frame(void);
void init_pad_state(void);
void update_pad_recalibration(void);
// inferred: key 0x56 (left control) held; key 0x5B also counts in some keyboard states.
s32 is_keyboard_control_held(void);
// inferred: keys 0x54/0x55 held, the shift test get_ascii_key uses.
s32 is_keyboard_shift_held(void);
s32 is_keyboard_key_pressed(u8 key);
void copy_controller_input(ControllerInputContext *destination, ControllerInputContext *source);
void set_stick_button_bits(ControllerInputContext *pad, u32 mask, u32 previous);
void map_c_stick_to_buttons(ControllerInputContext *pad, s16 x, s16 y, s32 previous);
void map_main_stick_to_buttons(ControllerInputContext *pad, s16 x, s16 y, s32 previous);
void update_button_hold_counters(ControllerInputContext *pad);
// Direction bits (0x10..0x80) mirrored onto the stick bits: the main stick (<< 16) and the C stick (<< 22).
s32 all_direction_mask(ControllerInputContext *pad, s32 mask);
s32 cstick_direction_mask(ControllerInputContext *pad, s32 mask);
s32 pack_button_mask(ControllerInputContext *pad, s32 mask);
s32 test_flags_04_packed(ControllerInputContext *pad, s32 mask);
s32 test_controller_flag_4c_color(ControllerInputContext *pad, s32 mask);
s32 test_pressed_buttons_packed(void *pad, s32 mask);
s32 test_previous_buttons_color(ControllerInputContext *pad, s32 mask);
s32 test_previous_buttons_remapped(ControllerInputContext *pad, s32 mask);
s32 test_previous_buttons_packed(void *pad, s32 mask);
s32 test_buttons_press_or_repeat_color(ControllerInputContext *input, s32 buttons, s32 delay, s32 period);
s32 test_buttons_repeat_packed(ControllerInputContext *input, s32 buttons, s32 delay, s32 period);
s32 test_buttons_press_or_repeat(ControllerInputContext *pad, s32 buttons, s32 delay, s32 period);
s32 check_packed_flag_match(ControllerInputContext *pad, u32 mask, s32 delay, s32 period);
s32 input_press_or_repeat(ControllerInputContext *pad, u32 mask, s32 delay, s32 period);

s32 poll_reset_request(void);

struct ControllerHoldFrameBlock {
    u32 words[7];
};

#endif
