#include "types.h"
#include "pso/ui/window/TWindowDD.h"

extern "C" {

s32 update_numeric_parameter_input__9TWindowDDFPv();
s32 TWindowDD__sub_803435A0(void *);
s32 refresh_word_select_child_list();
s32 is_word_select_cancel_input(void *);

void TWindowDD::enter_state_19() {
    s32 confirmed;

    confirmed = 0;
    switch (numeric_input_active) {
    case 0:
        refresh_word_select_child_list();
        update_selection_state();
        if (test_input_flag_4() != 0) {
            TWindowDD::play_sound();
            confirmed = update_close_flag() == 0;
        } else if (is_word_select_cancel_input(this) != 0) {
            TWindowDD::play_se();
            apply_entry_layout();
        }
        break;
    case 1:
        confirmed = update_numeric_parameter_input__9TWindowDDFPv();
        break;
    }
    if (confirmed != 0) {
        next_state = 0x13;
        TWindowDD__sub_803435A0(this);
    }
}

void TWindowDD::enter_state_18() {
    s32 confirmed;

    confirmed = 0;
    switch (numeric_input_active) {
    case 0:
        refresh_word_select_child_list();
        update_selection_state();
        if (test_input_flag_4() != 0) {
            TWindowDD::play_sound();
            confirmed = update_close_flag() == 0;
        } else if (is_word_select_cancel_input(this) != 0) {
            TWindowDD::play_se();
            apply_entry_layout();
        }
        break;
    case 1:
        confirmed = update_numeric_parameter_input__9TWindowDDFPv();
        break;
    }
    if (confirmed != 0) {
        next_state = 0x12;
        TWindowDD__sub_803435A0(this);
    }
}

}
