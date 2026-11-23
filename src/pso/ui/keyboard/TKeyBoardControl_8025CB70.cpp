#include "pso/ui/window/TWindowKeyBoardBase.h"
#include "types.h"
#include "pso/ui/chat/TWindowChat.h"
#include "pso/ui/window/TWindowKeyBoardHard.h"
#include "pso/ui/window/TWindowKeyBoardBase.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/ui/Language.h"


void TWindowKeyBoardBase::reset_input() {
    u8 *arg0 = (u8 *)this;
    this->m_text.reset_state();
    this->m_text2.reset_state();
    *(s32 *)((s8 *)arg0 + 0x68) = (saddr)(arg0 + 0x6C);
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
    switch (current_language) {
    case LANGUAGE_JAPANESE:
        m_b4 = 0;
        if (test_keyboard_card_flag_16(client_index) != 0) {
            m_b4 = (s32) (m_b4 | 1);
        }
        if (test_keyboard_card_flag_32(client_index) != 0) {
            m_b4 = (s32) (m_b4 | 2);
        }
        if (test_keyboard_card_flag_64(client_index) != 0) {
            m_b4 = (s32) (m_b4 | 4);
        }
        if (test_keyboard_card_flag_128(client_index) != 0) {
            m_b4 = (s32) (m_b4 | 8);
        }
        break;
    case LANGUAGE_ENGLISH:
    case LANGUAGE_GERMAN:
    case LANGUAGE_FRENCH:
    case LANGUAGE_SPANISH:
        m_b4 = 6;
        break;
    }
}
