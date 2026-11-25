#include "pso/ui/window/TWindowDD_80341A08.h"
#include "types.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowDD_80341A08.h"

extern "C" {
s32 update_numeric_parameter_input__9TWindowDDFPv();
s32 TWindowDD__sub_803435A0(void *);
s32 refresh_word_select_child_list();
s32 is_word_select_cancel_input(void *);

void TWindowDD::enter_state_9() {
    s32 var_r31;

    var_r31 = 0;
    switch (numeric_input_active) {
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
        TWindowDD__sub_803435A0(this);
    }
}
void TWindowDD__sub_80342B5C(TWindowDD *window_dd) {
    TWindowDD_WS_Word *page;
    window_dd->next_state = 8;
    window_dd->selected_word = 0x37;
    page = window_dd->pages[window_dd->depth];
    if (page != NULL) {
        window_dd->selected_word = get_word_select_selected_id(page);
    }
}

}
