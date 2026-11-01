#include "types.h"
#include "pso/ui/TWindowInputNumber.h"
#include "pso/misc/TWindowHelpItem.h"
#include "pso/misc/TWindowSubMag.h"
#include "pso/misc/TWindowSubStatusDisp.h"

extern "C" {

s32 play_sound_effect(s32 a0 = 0, s32 a1 = 0, s32 a2 = 0, s32 a3 = 0);
s32 is_confirmed__18TWindowInputNumberFv();
s32 save_position__11TWindowBaseFv();

void TWindowInputNumber::mark_confirmed() {
    if (!(this->inputFlags & 8) && (is_confirmed__18TWindowInputNumberFv() == 0)) {
        this->inputFlags = (u16) (this->inputFlags | 4);
    }
}
void TWindowInputNumber::confirm_input() {
    s32 temp_r3;
    u32 temp;

    temp_r3 = this->value;
    if ((temp_r3 < (s32) this->minimum) || (temp_r3 > (s32) this->maximum)) {
        play_sound_effect(0x53F06, 0, 0, 0);
        return;
    }
    play_sound_effect(0x52D01, 0, 0, 0);
    this->inputFlags = (u16) (this->inputFlags | 2);
    temp = (u32) this->unknown70;
    if (temp != 0U) {
        ((TWindowSubStatusDisp *)temp)->set_entry_state(2);
    }
}

extern s32 number_input_decimal_place_values[];

void TWindowInputNumber::update() {
    play_sound_effect(0x54100, 0, 0, 0);
    this->value = (s32) (this->value - number_input_decimal_place_values[(s8) this->selectedDigit]);
    if ((s32) this->value < (s32) this->minimum) {
        this->value = (s32) this->maximum;
    }
    refresh_digit_entries();
    align_digits();
}

void TWindowInputNumber::update_value() {
    play_sound_effect(0x54100, 0, 0, 0);
    this->value = (s32) (this->value + number_input_decimal_place_values[(s8) this->selectedDigit]);
    if ((s32) this->value > (s32) this->maximum) {
        this->value = (s32) this->minimum;
    }
    refresh_digit_entries();
    align_digits();
}

void TWindowInputNumber::handle_decrement() {
    play_sound_effect(0x54100, 0, 0, 0);
    this->selectedDigit = (this->selectedDigit - 1);
    if ((s8) this->selectedDigit < 0) {
        if (this->inputFlags & 1) {
            this->selectedDigit = 0U;
            return;
        }
        this->selectedDigit = (this->digitCount - 1);
    }
}

void TWindowInputNumber::move_cursor_next() {
    u8 temp_r4;

    play_sound_effect(0x54100, 0, 0, 0);
    *(u8 *)&this->selectedDigit = (u8) (*(u8 *)&this->selectedDigit + 1);
    if ((s8) *(u8 *)&this->selectedDigit >= (s8) (temp_r4 = *(u8 *)&this->digitCount)) {
        if (this->inputFlags & 1) {
            *(u8 *)&this->selectedDigit = (temp_r4 - 1);
            return;
        }
        *(u8 *)&this->selectedDigit = 0U;
    }
}

void TWindowInputNumber::set_value(f32 farg0) {
    this->m_38 = farg0;
    save_position__11TWindowBaseFv();
    align_digits();
}

}
