#include "types.h"
#include "pso/ui/window/TWindowDD.h"


void TWindowDD::handle_input() {
    update_selection_state();
    if (test_input_flag_4() != 0) {
        TWindowDD::play_sound();
        finish_word_select();
        return;
    }
    if (is_word_select_cancel_input() != 0) {
        TWindowDD::play_se();
        apply_entry_layout();
    }
}
