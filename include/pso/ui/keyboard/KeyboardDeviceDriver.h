#ifndef PSO_UI_KEYBOARD_KEYBOARDDEVICEDRIVER_H
#define PSO_UI_KEYBOARD_KEYBOARDDEVICEDRIVER_H

#include "types.h"
#include <stddef.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSThread.h>

typedef void (*KeyboardCallback)(s32 chan, s32 err);
typedef void (*KeyboardTypeCallback)(s32 chan);

struct KeyboardChannelState {
    u8 type;
    u8 layout;
    u8 pad_02;
    u8 out[4];
    u8 in[9];
    u32 out_bytes;
    u32 in_bytes;
    KeyboardCallback callback;
    s32 err;
    OSThreadQueue queue;
    union {
        s64 delay;
        struct {
            s32 hi;
            s32 lo;
        } delay_words;
    };
    KeyboardTypeCallback type_callback;
    u8 prev[4];
    u8 cur[4];
    u8 key_queue[32];
    u32 count;
    u32 head;
    u8 pad_64[4];

    void update_pressed_keys();
};

LAYOUT_ASSERT(KeyboardChannelState_size, sizeof(KeyboardChannelState) == 0x68);
LAYOUT_ASSERT(KeyboardChannelState_delay_offset, offsetof(KeyboardChannelState, delay) == 0x28);
LAYOUT_ASSERT(KeyboardChannelState_prev_offset, offsetof(KeyboardChannelState, prev) == 0x34);
LAYOUT_ASSERT(KeyboardChannelState_cur_offset, offsetof(KeyboardChannelState, cur) == 0x38);

extern KeyboardChannelState keyboard_pad_state_table[4];

extern "C" {
extern s32 TKeyBoardControl__polling_channel_mask;
s32 __OSReschedule(void);

void noop_keyboard_callback(s32 chan, s32 err);
s32 reset_keyboard_port(s32 chan, KeyboardCallback callback);
void on_keyboard_type_event(s32 chan, u32 type);
u8 get_keyboard_port_layout(s32 chan);
}

void handle_pad_transfer_done(s32 chan, u32 status, OSContext *ctx);
s32 poll_keyboard_port(s32 chan, u8 *out);

#endif
