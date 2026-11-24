#include "types.h"
#include "pso/ui/Language.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowKeyBoardBase.h"
#include "pso/ui/window/TWindowKeyBoardHard.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"

void TWindowKeyBoardBase::reset_input() {
    m_text.reset_state();
    m_text2.reset_state();
    active_text = &m_text;
    m_60 = 0;
    current_candidate = NULL;
    last_candidate = NULL;
}

void TWindowKeyBoardBase::set_mode3() {
    composition_flags = 530;
}

void TWindowKeyBoardBase::set_mode2() {
    set_mode0();
    composition_flags |= 0x100;
}

void TWindowKeyBoardBase::set_mode1() {
    set_mode0();
    composition_flags |= 0x80;
}

void TWindowKeyBoardBase::set_mode0() {
    composition_flags = 18;
}

void TWindowKeyBoardBase::sub_8025CC48() {
    switch (current_language) {
    case LANGUAGE_JAPANESE:
        composition_flags = 0;
        if (test_keyboard_card_flag_16(client_index) != 0) {
            composition_flags = (s32)(composition_flags | 1);
        }
        if (test_keyboard_card_flag_32(client_index) != 0) {
            composition_flags = (s32)(composition_flags | 2);
        }
        if (test_keyboard_card_flag_64(client_index) != 0) {
            composition_flags = (s32)(composition_flags | 4);
        }
        if (test_keyboard_card_flag_128(client_index) != 0) {
            composition_flags = (s32)(composition_flags | 8);
        }
        break;
    case LANGUAGE_ENGLISH:
    case LANGUAGE_GERMAN:
    case LANGUAGE_FRENCH:
    case LANGUAGE_SPANISH:
        composition_flags = 6;
        break;
    }
}
