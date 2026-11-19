#include "types.h"
#include "pso/ui/keyboard/TKeyBoardControl_8025CB70.h"
#include "pso/ui/chat/TWindowChat.h"
#include "pso/ui/window/TWindowKeyBoardHard.h"
#include "pso/ui/window/TWindowKeyBoardBase.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/ui/Language.h"


void TWindowKeyBoardBase::reset_input() {
    u8 *arg0 = (u8 *)this;
    ((KeyboardTextBuffer *)(arg0 + 0x6C))->reset_state();
    ((KeyboardTextBuffer *)(arg0 + 0x84))->reset_state();
    *(s32 *)((s8 *)arg0 + 0x68) = (s32)(arg0 + 0x6C);
    *(s16 *)((s8 *)arg0 + 0x60) = 0;
    *(s32 *)((s8 *)arg0 + 0xA0) = 0;
    *(s32 *)((s8 *)arg0 + 0xA4) = 0;
}

void TWindowKeyBoardBase::set_mode3() { m_b4 = 530; }

void TWindowKeyBoardBase::set_mode2() {
    set_mode0();
    m_b4 |= 0x100;
}

void TWindowKeyBoardBase::set_mode1() {
    set_mode0();
    m_b4 |= 0x80;
}

void TWindowKeyBoardBase::set_mode0() { m_b4 = 18; }
void TWindowKeyBoardBase::sub_8025CC48() {
    void * arg0 = (void *)this;
    switch (current_language) {
    case LANGUAGE_JAPANESE:
        *(s32 *)((s8 *)arg0 + 0xB4) = 0;
        if (test_keyboard_card_flag_16(*(s16 *)((s8 *)arg0 + 0x20)) != 0) {
            *(s32 *)((s8 *)arg0 + 0xB4) = (s32) (*(s32 *)((s8 *)arg0 + 0xB4) | 1);
        }
        if (test_keyboard_card_flag_32(*(s16 *)((s8 *)arg0 + 0x20)) != 0) {
            *(s32 *)((s8 *)arg0 + 0xB4) = (s32) (*(s32 *)((s8 *)arg0 + 0xB4) | 2);
        }
        if (test_keyboard_card_flag_64(*(s16 *)((s8 *)arg0 + 0x20)) != 0) {
            *(s32 *)((s8 *)arg0 + 0xB4) = (s32) (*(s32 *)((s8 *)arg0 + 0xB4) | 4);
        }
        if (test_keyboard_card_flag_128(*(s16 *)((s8 *)arg0 + 0x20)) != 0) {
            *(s32 *)((s8 *)arg0 + 0xB4) = (s32) (*(s32 *)((s8 *)arg0 + 0xB4) | 8);
        }
        break;
    case LANGUAGE_ENGLISH:
    case LANGUAGE_GERMAN:
    case LANGUAGE_FRENCH:
    case LANGUAGE_SPANISH:
        *(s32 *)((s8 *)arg0 + 0xB4) = 6;
        break;
    }
}
