#ifndef PSO_UI_KEYBOARD_KEYBOARDKEYSTATE_H
#define PSO_UI_KEYBOARD_KEYBOARDKEYSTATE_H

#include "types.h"

// The state of the hardware keyboard: the port it was last read from, the raw key codes of the current report,
// the keys waiting to be handled, one pressed bit per key code and the auto-repeat timers.
// Descriptive name: the binary has no name for it.
struct KeyboardKeyRepeat {
    u8 key;
    s8 timer;
};

struct KeyboardKeyState {
    s8 port;
    u8 mode;
    u8 pending_count;
    u8 raw_count;
    s8 reports;
    u8 raw[0x80];
    u8 pending[8];
    u8 pad_8d[3];
    u32 pressed[4];
    KeyboardKeyRepeat repeat[8];

    s32 append_char(s8 port_index);
    void append_next_char();
    static void append_next_char_global();
    void disable_disconnected_ports();
    s32 has_any_key_pressed();
    u8 get_pending_count();
    void push_key_to_buffer(u8 key);
    void tick_key_repeat_timer(u8 key);
    void reset_keys();
    void clear_key_state();
    void reset_input();
    static void reset_global_keys_a();
    static void reset_global_keys_b();
    void reset_inactive_keys();
    s32 check_input_ready();
    s32 sub_801321B4();
    s32 sub_80132274();
    s32 is_key_57_pressed();
    s32 sub_80132310();
    u8 sub_8013239C(u8 index);
    s32 sub_801323C8(u8 key);
    u8 get_key_state();
    static void process_raw_key(KeyboardKeyState *kb, u8 key, u32 *pressed);
    void sub_80132650();
    void reset_port_if_connected(u8 chan);
    void reset_state();
};

LAYOUT_ASSERT(KeyboardKeyState_size, sizeof(KeyboardKeyState) == 0xB0);
extern KeyboardKeyState hardware_keyboard_state;

#endif
