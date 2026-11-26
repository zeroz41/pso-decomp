#include "types.h"
#include "pso/ui/window/TWindowDD.h"

void TWindowDD::enter_state_19() {
    s32 confirmed;

    confirmed = 0;
    switch (dialog_locked) {
    case 0:
        refresh_word_select_child_list();
        update_selection_state();
        if (test_input_flag_4() != 0) {
            TWindowDD::play_sound();
            confirmed = update_close_flag() == 0;
        } else if (is_word_select_cancel_input() != 0) {
            TWindowDD::play_se();
            apply_entry_layout();
        }
        break;
    case 1:
        confirmed = update_numeric_parameter_input();
        break;
    }
    if (confirmed != 0) {
        next_state = 0x13;
        begin_word_select_state();
    }
}

void TWindowDD::enter_state_18() {
    s32 confirmed;

    confirmed = 0;
    switch (dialog_locked) {
    case 0:
        refresh_word_select_child_list();
        update_selection_state();
        if (test_input_flag_4() != 0) {
            TWindowDD::play_sound();
            confirmed = update_close_flag() == 0;
        } else if (is_word_select_cancel_input() != 0) {
            TWindowDD::play_se();
            apply_entry_layout();
        }
        break;
    case 1:
        confirmed = update_numeric_parameter_input();
        break;
    }
    if (confirmed != 0) {
        next_state = 0x12;
        begin_word_select_state();
    }
}

