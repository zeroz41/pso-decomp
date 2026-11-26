#include "types.h"
#include "pso/ui/window/TWindowDD.h"



void TWindowDD::update_dispatch() {
    refresh_word_select_child_list();
    if (test_input_flag_4() != 0) {
        TWindowDD::play_sound();
        store_selected_word_plain();
        begin_word_select_state();
        return;
    }
    if (is_word_select_cancel_input() != 0) {
        TWindowDD::play_sound();
        apply_entry_layout();
    }
}

void TWindowDD::update_layout() {
    this->update_selection_state();
    if (test_input_flag_4() != 0) {
        TWindowDD::play_sound();
        next_state = 0x14;
        list_ids[1] = -0x3C;
        begin_word_select_state();
        return;
    }
    if (is_word_select_cancel_input() != 0) {
        TWindowDD::play_se();
        apply_entry_layout();
    }
}

