#include "pso/ui/window/TWindowDD_80341A08.h"
#include "types.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowDD_80341A08.h"

extern "C" {
s32 update_numeric_parameter_input__9TWindowDDFPv();
s32 begin_word_select_state(void *);
s32 refresh_word_select_child_list();
s32 is_word_select_cancel_input(void *);

void TWindowDD::enter_state_9() {
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
        next_state = 9;
        begin_word_select_state(this);
    }
}
void TWindowDD__sub_80342B5C(u8 *window_dd) {
    TWindowDD *w = (TWindowDD *)window_dd;
    u8 *word_window;
    w->next_state = 8;
    w->selected_word = 0x37;
    word_window = (u8 *)w->word_windows[w->depth];
    if (word_window != NULL) {
        w->selected_word = get_word_select_selected_id(reinterpret_cast<TWindowDD_WS_Word *>(word_window));
    }
}

}
