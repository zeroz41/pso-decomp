#include "types.h"
#include "pso/ui/window/TWindowDD.h"

extern "C" {

void TWindowDD__sub_80342B5C(TWindowDD *window_dd);
s32 TWindowDD__sub_803435A0(void *);
s32 refresh_word_select_child_list();
s32 is_word_select_cancel_input(void *);

void TWindowDD::update_dispatch() {
    refresh_word_select_child_list();
    if (test_input_flag_4() != 0) {
        TWindowDD::play_sound();
        TWindowDD__sub_80342B5C(this);
        TWindowDD__sub_803435A0(this);
        return;
    }
    if (is_word_select_cancel_input(this) != 0) {
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
        TWindowDD__sub_803435A0(this);
        return;
    }
    if (is_word_select_cancel_input(this) != 0) {
        TWindowDD::play_se();
        apply_entry_layout();
    }
}

}
