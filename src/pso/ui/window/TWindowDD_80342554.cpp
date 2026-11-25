#include "types.h"
#include "pso/ui/window/TWindowDD.h"

extern "C" {

s32 update_numeric_parameter_input__9TWindowDDFPv();
s32 begin_word_select_state(void *);
s32 refresh_word_select_child_list();
s32 is_word_select_cancel_input(void *);

void TWindowDD::enter_state_19() {
    s32 var_r31;

    var_r31 = 0;
    switch (dialog_locked) {
    case 0:
        refresh_word_select_child_list();
        update_selection_state();
        if (test_input_flag_4() != 0) {
            TWindowDD::play_sound();
            var_r31 = TWindowDD::update_close_flag(this) == 0;
        } else if (is_word_select_cancel_input(this) != 0) {
            TWindowDD::play_se();
            TWindowDD::apply_entry_layout(this);
        }
        break;
    case 1:
        var_r31 = update_numeric_parameter_input__9TWindowDDFPv();
        break;
    }
    if ((s32) var_r31 != 0) {
        next_state = 0x13;
        begin_word_select_state(this);
    }
}

void TWindowDD::enter_state_18() {
    s32 var_r31;

    var_r31 = 0;
    switch (dialog_locked) {
    case 0:
        refresh_word_select_child_list();
        update_selection_state();
        if (test_input_flag_4() != 0) {
            TWindowDD::play_sound();
            var_r31 = TWindowDD::update_close_flag(this) == 0;
        } else if (is_word_select_cancel_input(this) != 0) {
            TWindowDD::play_se();
            TWindowDD::apply_entry_layout(this);
        }
        break;
    case 1:
        var_r31 = update_numeric_parameter_input__9TWindowDDFPv();
        break;
    }
    if ((s32) var_r31 != 0) {
        next_state = 0x12;
        begin_word_select_state(this);
    }
}

}
