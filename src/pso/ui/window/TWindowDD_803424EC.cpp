#include "types.h"
#include "pso/ui/window/TWindowDD_803424EC.h"
#include "pso/ui/window/TWindowDD.h"

extern "C" {

s32 is_word_select_cancel_input(s32);
s32 finish_word_select(s32);

void handle_input__9TWindowDDFi(saddr window_dd) {
    ((TWindowDD *)window_dd)->update_selection_state();
    if (((TWindowDD *)window_dd)->test_input_flag_4() != 0) {
        TWindowDD::play_sound();
        finish_word_select(window_dd);
        return;
    }
    if (is_word_select_cancel_input(window_dd) != 0) {
        TWindowDD::play_se();
        TWindowDD::apply_entry_layout((void *)window_dd);
    }
}

}
