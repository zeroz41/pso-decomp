#include "types.h"
#include "pso/ui/window/TWindowDD.h"

void TWindowDD::update_transition() {
    refresh_word_select_child_list();
    update_selection_state();
    if (test_input_flag_4() != 0) {
        TWindowDD::play_sound();
        next_state = 6;
        begin_word_select_state();
        return;
    }
    if (is_word_select_cancel_input() != 0) {
        TWindowDD::play_se();
        apply_entry_layout();
    }
}
void TWindowDD::handle_state_3() {
    s32 done;
    done = 0;
    message.type = 1;
    switch (dialog_locked) {
    case 0:
        refresh_word_select_child_list();
        update_selection_state();
        if (test_input_flag_4() != 0) {
            TWindowDD::play_sound();
            done = !update_close_flag();
        } else if (is_word_select_cancel_input() != 0) {
            TWindowDD::play_se();
            selection_confirmed = 0;
            apply_entry_layout();
        }
        break;
    case 1:
        done = update_numeric_parameter_input();
        break;
    }
    if (done) {
        selection_confirmed = 1;
        if (list_ids[1] == -0x3C) {
            next_state = 0x14;
        } else {
            switch (TWindowDD::window_mode) {
            case 0:
                store_selected_word_plain();
                message.init();
                message.type = 3;
                break;
            case 1:
            case 2:
            case 3:
            case 4:
            default:
                message.init();
                message.type = 4;
                store_selected_word();
                break;
            }
        }
        begin_word_select_state();
    }
}

