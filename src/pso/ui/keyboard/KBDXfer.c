#include "types.h"
#include <stddef.h>
#include <string.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/os/OSReset.h>
#include <dolphin/os/OSThread.h>
#include <dolphin/os/OSTime.h>
#include <dolphin/si.h>
#include "pso/ui/keyboard/KeyboardDeviceDriver.h"

KeyboardChannelState keyboard_pad_state_table[4];
s32 keyboard_polling_disabled;

static OSResetFunctionInfo keyboard_reset_func_info = {
    (OSResetFunction)disable_all_channels, 127
};

void init_pad_states(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        KeyboardChannelState *state = &keyboard_pad_state_table[i];
        state->delay_words.lo = 0;
        state->delay_words.hi = 0;
        state->type = 0;
        state->layout = 0;
        state->err = 0;
        memset(state->cur, 0, 4);
        memset(state->prev, 0, 4);
        OSInitThreadQueue(&state->queue);
    }
    SIRefreshSamplingRate();
    keyboard_polling_disabled = 0;
    OSRegisterResetFunction(&keyboard_reset_func_info);
}

void parse_pad_event(s32 chan, u32 type) {
    u32 halfword = type >> 16U;
    s32 prefix = (type >> 16U) & 0xFFF0;
    KeyboardChannelState *state = &keyboard_pad_state_table[chan];
    switch (prefix) {
    case 0x820:
        state->type = 1;
        state->layout = (s8)(halfword & 0xF);
        state->delay_words.lo = 0;
        state->delay_words.hi = 0;
        return;
    case 0x830:
        state->type = 2;
        state->layout = (s8)(halfword & 0xF);
        state->delay_words.lo = 0;
        state->delay_words.hi = 0;
        return;
    default:
        state->layout = 0;
        state->type = 0;
        return;
    }
}

void detect_device_type(s32 chan) {
    KeyboardChannelState *state = &keyboard_pad_state_table[chan];
    u32 type;
    if (state->err != 0) {
        return;
    }
    type = (state->in[0] << 24) | (state->in[1] << 16);
    switch ((type >> 16) & 0xFFF0) {
    case 0x820:
        state->type = 1;
        state->layout = (type >> 16) & 0xF;
        state->delay_words.lo = 0;
        state->delay_words.hi = 0;
        break;
    case 0x830:
        state->type = 2;
        state->layout = (type >> 16) & 0xF;
        state->delay_words.lo = 0;
        state->delay_words.hi = 0;
        break;
    default:
        state->layout = 0;
        state->type = 0;
        break;
    }
    if ((s32)state->type >= 3 || (s32)state->type < 1) {
        state->err = -1;
        return;
    }
    if (state->in[2] & 0x10) {
        state->err = -0x80;
        return;
    }
    if (state->in[2] & 8) {
        state->err = -3;
        return;
    }
    if (state->out[0] == 0xFF && keyboard_polling_disabled == 0) {
        enable_keyboard_polling(chan);
    }
}

void noop_keyboard_callback(s32 chan, s32 err) {
}

s32 reset_keyboard_port(s32 chan, KeyboardCallback callback) {
    KeyboardChannelState *state = &keyboard_pad_state_table[chan];
    KeyboardCallback cb;
    s32 ret;
    s32 lvl;
    cb = callback != NULL ? callback : noop_keyboard_callback;
    lvl = OSDisableInterrupts();
    if (state->callback != NULL) {
        ret = -2;
    } else {
        state->callback = cb;
        ret = 0;
    }
    OSRestoreInterrupts(lvl);
    if (ret != 0) {
        return ret;
    }
    state->out[0] = 0xFF;
    return start_get_type_async(chan, 1, 3, detect_device_type);
}

s32 disable_all_channels(void) {
    u32 mask;
    while ((mask = (u32)key_board_control_polling_channel_mask) != 0) {
        disable_channel_polling(__cntlzw(mask));
    }
    keyboard_polling_disabled = 1;
    return 1;
}

void handle_pad_transfer_done(s32 chan, u32 status, OSContext *ctx) {
    KeyboardChannelState *state = &keyboard_pad_state_table[chan];
    u8 unused[8];
    OSContext tmp;
    void (*type_cb)(s32);
    void (*cb)(s32, s32);
    if (keyboard_polling_disabled != 0) {
        return;
    }
    if (status & 8) {
        state->type = 0;
        state->err = -1;
    } else if (status & 7) {
        state->err = -3;
    } else {
        state->err = 0;
    }
    if ((type_cb = state->type_callback) != NULL) {
        state->type_callback = NULL;
        type_cb(chan);
    }
    if (state->callback != NULL) {
        OSClearContext(&tmp);
        OSSetCurrentContext(&tmp);
        cb = state->callback;
        state->callback = NULL;
        cb(chan, state->err);
        OSClearContext(&tmp);
        OSSetCurrentContext(ctx);
    }
}

void on_keyboard_type_event(s32 chan, u32 type) {
    KeyboardChannelState *state = &keyboard_pad_state_table[chan];
    u8 unused[8];
    OSContext tmp;
    OSContext *old;
    void (*type_cb)(s32);
    void (*cb)(s32, s32);

    if (keyboard_polling_disabled != 0) {
        return;
    }
    parse_pad_event(chan, type);
    if (state->type != 0) {
        if (SITransfer(chan, state->out, state->out_bytes, state->in, state->in_bytes, handle_pad_transfer_done,
                       state->delay) != 0) {
            return;
        }
        state->err = -2;
    } else {
        state->err = -1;
    }
    if ((type_cb = state->type_callback) != NULL) {
        state->type_callback = NULL;
        type_cb(chan);
    }
    if (state->callback != NULL) {
        old = OSGetCurrentContext();
        OSClearContext(&tmp);
        OSSetCurrentContext(&tmp);
        cb = state->callback;
        state->callback = NULL;
        cb(chan, state->err);
        OSClearContext(&tmp);
        OSSetCurrentContext(old);
        __OSReschedule();
    }
}

s32 start_get_type_async(s32 chan, s32 out_bytes, s32 in_bytes, KeyboardTypeCallback callback) {
    s32 en;
    KeyboardChannelState *state = &keyboard_pad_state_table[chan];
    en = OSDisableInterrupts();
    state->type_callback = callback;
    state->out_bytes = out_bytes;
    state->in_bytes = in_bytes;
    SIGetTypeAsync(chan, on_keyboard_type_event);
    OSRestoreInterrupts(en);
    return 0;
}

void update_pressed_keys(KeyboardChannelState *state) {
    s32 n;
    memcpy(state->prev, state->cur, 4);
    if (state->in[4] == 1 || state->in[4] == 2) {
        return;
    }
    n = 0;
    if (state->in[4] != 0) {
        n = 1;
        state->cur[0] = state->in[4];
    }
    if (state->in[5] != 0) {
        ((u8 *)state)[n++ + offsetof(KeyboardChannelState, cur)] = state->in[5];
    }
    if (state->in[6] != 0) {
        ((u8 *)state)[n++ + offsetof(KeyboardChannelState, cur)] = state->in[6];
    }
    for (; n < 4; n++) {
        state->cur[n] = 0;
    }
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
static inline s32 push_key_to_queue(KeyboardChannelState *state, u8 key) {
    if (state->count < 32) {
        state->key_queue[(state->head + state->count) & 31] = key;
        state->count++;
        return 1;
    }
    return 0;
}

void update_key_events(s32 chan) {
    KeyboardChannelState *state;
    u8 key;
    s32 j;
    s32 i;
    s32 j2;
    u8 key2;
    s32 i2;
    state = &keyboard_pad_state_table[chan];
    if (state->err == -1) {
        memset(state->prev, 0, 4);
        memset(state->cur, 0, 4);
    }
    if (state->err != 0) {
        return;
    }
    switch (state->type) {
    case 1:
    case 2:
        update_pressed_keys(state);
        break;
    default:
        return;
    }
    for (i = 0; i < 4 && state->count < 32; i++) {
        key = state->prev[i];
        if (key != 0) {
            for (j = 0; j < 4; j++) {
                if (key == state->cur[j]) {
                    break;
                }
            }
            if (j == 4) {
                if (!push_key_to_queue(state, key | 0x80)) {
                    state->err = -4;
                    return;
                }
            }
        }
    }
    for (i2 = 0; i2 < 4; i2++) {
        key2 = state->cur[i2];
        if (key2 != 0) {
            for (j2 = 0; j2 < 4; j2++) {
                if (key2 == state->prev[j2]) {
                    break;
                }
            }
            if (j2 == 4) {
                if (!push_key_to_queue(state, key2)) {
                    state->err = -4;
                    return;
                }
            }
        }
    }
}
#pragma pop

u8 get_keyboard_port_layout(s32 chan) {
    KeyboardChannelState *state = &keyboard_pad_state_table[chan];
    return state->layout;
}

void enable_keyboard_polling(s32 chan) {
    u32 cmd;
    u32 buf[2];
    u32 bit = 0x80000000U >> chan;
    if (!(key_board_control_polling_channel_mask & bit)) {
        key_board_control_polling_channel_mask |= bit;
        SIGetResponse(chan, buf);
        cmd = 0x540000;
        SISetCommand(chan, cmd);
        SIEnablePolling(key_board_control_polling_channel_mask);
    }
}

void disable_channel_polling(s32 chan) {
    u32 bit = 0x80000000U >> chan;
    SIDisablePolling(bit);
    key_board_control_polling_channel_mask &= ~bit;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
static inline u32 verify_keyboard_checksum(u32 *resp) {
    u32 sum;
    sum = resp[0] >> 24;
    sum ^= (u8)(resp[0] >> 16);
    sum ^= (u8)(resp[0] >> 8);
    sum ^= (u8)resp[0];
    sum ^= resp[1] >> 24;
    sum ^= (u8)(resp[1] >> 16);
    sum ^= (u8)(resp[1] >> 8);
    return sum == (u8)resp[1];
}

s32 poll_keyboard_port(s32 chan, u8 *out) {
    u32 resp[2];
    u8 unused[4];
    u32 bit;
    s32 enabled;
    KeyboardChannelState *state;
    s32 err;
    s32 ret;
    enabled = OSDisableInterrupts();
    state = &keyboard_pad_state_table[chan];
    bit = 0x80000000U >> chan;
    if (state->type != 1 && state->type != 2) {
        state->err = -1;
    } else if (SIIsChanBusy(chan)) {
        state->err = -2;
    } else if (!(key_board_control_polling_channel_mask & bit)) {
        state->err = -1;
    } else if (SIGetStatus(chan) & 8) {
        SIGetResponse(chan, resp);
        SIDisablePolling(bit);
        key_board_control_polling_channel_mask &= ~bit;
        state->type = 0;
        state->err = -1;
    } else if (!SIGetResponse(chan, resp) || (resp[0] & 0x80000000)) {
        state->err = -3;
    } else {
        if (resp[0] & 0x20000000) {
            err = -128;
        } else if (resp[0] & 0x10000000) {
            err = -3;
        } else {
            if (!verify_keyboard_checksum(resp)) {
                err = -3;
            } else {
                err = 0;
            }
        }
        state->err = err;
        switch (state->err) {
        case -128:
            SIDisablePolling(bit);
            key_board_control_polling_channel_mask &= ~bit;
            state->type = 0;
            break;
        case 0:
            memcpy(state->in, resp, 8);
            break;
        }
    }
    update_key_events(chan);
    if (out != NULL) {
        memmove(out, state->cur, 4);
    }
    ret = state->err;
    OSRestoreInterrupts(enabled);
    return ret;
}
#pragma pop
