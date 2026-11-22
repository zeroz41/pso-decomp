#include "types.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/keyboard/TKeyBoardControl_80131C58.h"
#include "pso/ui/keyboard/TKeyBoardControl_803F0C50.h"
#include "pso/ui/window/TWindowCtrl_8024A054.h"
#include "pso/ui/window/TWindowSubComCard_80244774.h"
#include "pso/unk/text_803F1804.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/keyboard/KeyboardKeyState.h"
#include "pso/ui/window/TWindowLockOn.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/ui/window/TWindowMakeTeam.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/ui/window/TWindowKeyBoardBase.h"
#include "pso/ui/window/TWindowKeyBoardHard.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801A6D60.h"
#include "pso/system/task/TObject.h"


KeyboardKeyState hardware_keyboard_state;

void TKeyBoardControl__sub_80131F5C(void) {  }
void TKeyBoardControl__sub_80131F60(void) {  }
void TWindowKeyBoardHard::set_flag60_bit200() { m_60 |= 0x200; }
void TWindowKeyBoardHard::clear_flag60_bit200() { m_60 &= 0xfffffdff; }
int TWindowKeyBoardHard::is_key_held() { return (m_60 >> 8) & 0x1; }
void TWindowKeyBoardBase::set_flag62_bit2() { m_62 |= 0x2; }
int TWindowKeyBoardBase::is_cancelled() { return (m_60 >> 5) & 0x1; }
int TWindowKeyBoardBase::is_confirmed() { return m_60 & 0x1; }
void TWindowKeyBoardBase::set_flag62_bit8() { m_62 |= 0x8; }

s32 KeyboardKeyState::append_char(s8 arg1) {
    s32 r;
    u8 *p;
    if (raw_count >= 0x7C) {
        return 1;
    }
    r = poll_keyboard_port((arg1), (u8 *)((s32 *)((s32 *)&raw[raw_count])));
    if (r == -1) {
        return 0;
    }
    if (r == 0) {
        p = raw;
        while (*p != 0) {
            p++;
            raw_count++;
        }
    }
    mode = TKeyBoardControl__sub_803F1548(arg1);
    port = arg1;
    return 1;
}

void KeyboardKeyState::append_next_char() {
    s32 i = 0;
    reports = reports + 1;
    do {
        if (((s32)append_char(i)) != 0) {
            return;
        }
        i++;
    } while (i < 4);
    port = 4;
}

void KeyboardKeyState::append_next_char_global() { hardware_keyboard_state.append_next_char(); }

void KeyboardKeyState::disable_disconnected_ports() {
    s32 sp8;
    s32 temp_r3;
    s32 chan;
    chan = 0;
    do {
        temp_r3 = poll_keyboard_port(chan, (u8 *)&sp8);
        if ((temp_r3 == -1) || (temp_r3 == -0x80)) {
            TKeyBoardControl__sub_803F0E90(chan, 0);
        }
        chan += 1;
    } while (chan < 4);
}
s32 KeyboardKeyState::check_input_ready() {
    if (sub_80132310() != 0) {
        return 0;
    }
    if (is_key_57_pressed() != 0) {
        return 0;
    }
    if (sub_801321B4() != 0) {
        return 0;
    }
    return 1;
}
#pragma push
#pragma bool off
s32 KeyboardKeyState::sub_801321B4() {
    if (sub_801323C8(0x56) != 0) {
        return 1;
    }
    if (hardware_keyboard_state.get_key_state() == 0) {
        return 0;
    }
    if ((hardware_keyboard_state.get_key_state() == 2) || (hardware_keyboard_state.get_key_state() == 4) || (hardware_keyboard_state.get_key_state() == 3)) {
        return 0;
    }
    return sub_801323C8(0x5B) != 0;
}

s32 KeyboardKeyState::sub_80132274() {
    if ((hardware_keyboard_state.get_key_state() == 0) || (hardware_keyboard_state.get_key_state() == 1)) {
        return 0;
    }
    return sub_801323C8(0x5B) != 0;
}

s32 KeyboardKeyState::is_key_57_pressed() {
    return sub_801323C8(0x57) != 0;
}
#pragma pop
s32 KeyboardKeyState::sub_80132310() {
    if ((sub_801323C8(0x54) != 0) || (sub_801323C8(0x55) != 0)) {
        return 1;
    }
    return 0;
}

s32 KeyboardKeyState::has_any_key_pressed() {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (pressed[i] != 0) {
            return 1;
        }
    }
    return 0;
}

u8 KeyboardKeyState::sub_8013239C(u8 arg1) {
    if (arg1 >= pending_count) {
        return 0;
    }
    return pending[arg1];
}

u8 KeyboardKeyState::get_pending_count() { return pending_count; }

s32 KeyboardKeyState::sub_801323C8(u8 key) {
    return (pressed[key / 32] & (1 << (key % 32))) != 0 ? 1 : 0;
}

u8 KeyboardKeyState::get_key_state() { return mode; }

void KeyboardKeyState::push_key_to_buffer(u8 key) {
    u8 t;
    if ((hardware_keyboard_state.get_key_state() != 0 && key == 0x5B) || (u8)(key - 0x54) <= 2 || key == 0x57) {
        return;
    }
    t = pending_count;
    if (t < 8) {
        pending_count = t + 1;
        pending[t] = key;
    }
}

void KeyboardKeyState::reset_inactive_keys() {
    s32 i;
    KeyboardKeyRepeat *p;
    i = 0;
    p = repeat;
    do {
        if (sub_801323C8(p->key) == 0) {
            p->key = 0;
            p->timer = 0x23;
        }
        i += 1;
        p += 1;
    } while (i < 8);
}

void KeyboardKeyState::tick_key_repeat_timer(u8 arg1) {
    KeyboardKeyRepeat *p;
    KeyboardKeyRepeat *q;
    s32 i;
    p = repeat;
    for (i = 0; i < 8; i++, p++) {
        if (p->key == arg1) {
            p->timer--;
            if (p->timer <= 0) {
                push_key_to_buffer(arg1);
                p->timer += 6;
            }
            return;
        }
    }
    q = repeat;
    for (i = 0; i < 8; i++, q++) {
        if (q->key == 0) {
            q->key = arg1;
            q->timer = 0x23;
        }
    }
}

// One bit per key code 0x00-0x7F: the codes that enter the key buffer (name inferred).
static u32 valid_key_mask[4] = { 0xFFFF00C0, 0xFFFFFFFF, 0xFF0FFFFF, 0xC0000003 };

void KeyboardKeyState::sub_80132598(KeyboardKeyState *kb, u8 key, u32 *pressed) {
    if (key != 0) {
        s32 code = key & 0x7F;
        s32 word = code / 32;
        u32 bit = 1 << (code % 32);
        s32 valid = bit & valid_key_mask[word];
        if (!(key & 0x80)) {
            if (valid != 0) {
                if (!(bit & (kb->pressed[word] | pressed[(u32)word]))) {
                    kb->push_key_to_buffer(key);
                }
                kb->tick_key_repeat_timer(key);
            }
            pressed[word] |= bit;
        }
    }
}

void KeyboardKeyState::sub_80132650() {
    u32 bits[4];
    s32 i;
    if (reports <= 0) {
        pending_count = 0;
        return;
    }
    reports = 0;
    if (port >= 4) {
        clear_key_state();
        reset_keys();
        return;
    }
    pending_count = 0;
    for (i = 0; i < 4; i++) {
        bits[i] = 0;
    }
    for (i = 0; i < raw_count; i++) {
        sub_80132598(this, raw[i], bits);
        raw[i] = 0;
    }
    raw_count = 0;
    for (i = 0; i < 4; i++) {
        pressed[i] = bits[i];
    }
    reset_inactive_keys();
}

void KeyboardKeyState::reset_keys() {
    s32 i;
    reports = 0;
    raw_count = 0;
    for (i = 0; i < 128; i++) {
        raw[i] = 0;
    }
}

void KeyboardKeyState::clear_key_state() {
    s32 i;
    pending_count = 0;
    for (i = 0; i < 8; i++) {
        pending[i] = 0;
    }
    for (i = 0; i < 8; i++) {
        repeat[i].key = 0;
        repeat[i].timer = 0x23;
    }
    for (i = 0; i < 4; i++) {
        pressed[i] = 0;
    }
}

void KeyboardKeyState::sub_801327DC(u8 chan) {
    s32 sp8;
    if (poll_keyboard_port(chan, (u8 *)&sp8) == 0) {
        TKeyBoardControl__sub_803F0E90(chan, (void *)(0));
    }
}

#pragma push
#pragma opt_loop_invariants off
void KeyboardKeyState::reset_state() {
    s32 i;
    port = 4;
    mode = 1;
    clear_key_state();
    reset_keys();
    for (i = 0; i < 4; i++) {
        sub_801327DC(i);
    }
}
#pragma pop

void KeyboardKeyState::reset_input() {
    TKeyBoardControl::init_pad_states();
    reset_state();
    fn_803F1864((uaddr)((s32 *)KeyboardKeyState::append_next_char_global));
}
void KeyboardKeyState::reset_global_keys_a() {
    hardware_keyboard_state.clear_key_state();
    hardware_keyboard_state.reset_keys();
}
void KeyboardKeyState::reset_global_keys_b() {
    hardware_keyboard_state.clear_key_state();
    hardware_keyboard_state.reset_keys();
}
