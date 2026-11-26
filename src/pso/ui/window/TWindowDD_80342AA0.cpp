#include "pso/ui/window/TWindowDD_WS_Word.h"
#include "types.h"
#include "pso/ui/window/TWindowDD.h"

extern "C" {
s32 update_numeric_parameter_input__9TWindowDDFPv();
s32 begin_word_select_state(void *);
s32 refresh_word_select_child_list();
s32 is_word_select_cancel_input(void *);

void TWindowDD::enter_state_9() {
    s32 confirmed;

    confirmed = 0;
    switch (dialog_locked) {
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
        next_state = 9;
        begin_word_select_state(this);
    }
}
void TWindowDD__sub_80342B5C(TWindowDD *window_dd) {
    TWindowDD_WS_Word *word_window;
    window_dd->next_state = 8;
    window_dd->selected_word = 0x37;
    word_window = window_dd->word_windows[window_dd->depth];
    if (word_window != NULL) {
        window_dd->selected_word = word_window->get_selected_id();
    }
}

}
