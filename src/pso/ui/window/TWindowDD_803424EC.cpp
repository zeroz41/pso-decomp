#include "types.h"
#include "pso/ui/window/TWindowDD.h"

extern "C" {

s32 is_word_select_cancel_input(void *);
s32 TWindowDD__sub_803484C4(void *);

}

void TWindowDD::handle_input() {
    update_selection_state();
    if (test_input_flag_4() != 0) {
        TWindowDD::play_sound();
        TWindowDD__sub_803484C4(this);
        return;
    }
    if (is_word_select_cancel_input(this) != 0) {
        TWindowDD::play_se();
        apply_entry_layout();
    }
}
