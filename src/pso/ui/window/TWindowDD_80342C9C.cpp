#include "types.h"
#include "pso/ui/window/TWindowDD.h"

extern "C" {
s32 TWindowDD__sub_803428C4(void *);
void TWindowDD__sub_80342B5C(TWindowDD *window_dd);
s32 update_numeric_parameter_input__9TWindowDDFPv();
s32 TWindowDD__sub_803435A0(void *);
s32 refresh_word_select_child_list();
s32 is_word_select_cancel_input(void *);
void TWindowDD::update_transition() {
    refresh_word_select_child_list();
    update_selection_state();
    if (test_input_flag_4() != 0) {
        TWindowDD::play_sound();
        next_state = 6;
        TWindowDD__sub_803435A0(this);
        return;
    }
    if (is_word_select_cancel_input(this) != 0) {
        TWindowDD::play_se();
        TWindowDD::apply_entry_layout(this);
    }
}
void TWindowDD__sub_80342D14(TWindowDD *window_dd) {
    s32 var_r31;
    var_r31 = 0;
    window_dd->message.type = 1;
    switch (window_dd->numeric_input_active) {
    case 0:
        refresh_word_select_child_list();
        window_dd->update_selection_state();
        if (window_dd->test_input_flag_4() != 0) {
            TWindowDD::play_sound();
            var_r31 = !TWindowDD::update_close_flag(window_dd);
        } else if (is_word_select_cancel_input(window_dd) != 0) {
            TWindowDD::play_se();
            window_dd->selection_confirmed = 0;
            TWindowDD::apply_entry_layout(window_dd);
        }
        break;
    case 1:
        var_r31 = update_numeric_parameter_input__9TWindowDDFPv();
        break;
    }
    if (var_r31) {
        window_dd->selection_confirmed = 1;
        if (window_dd->list_ids[1] == -0x3C) {
            window_dd->next_state = 0x14;
        } else {
            switch (TWindowDD::window_mode) {
            case 0:
                TWindowDD__sub_80342B5C(window_dd);
                window_dd->message.init_item_slots();
                window_dd->message.type = 3;
                break;
            case 1:
            case 2:
            case 3:
            case 4:
            default:
                window_dd->message.init_item_slots();
                window_dd->message.type = 4;
                TWindowDD__sub_803428C4(window_dd);
                break;
            }
        }
        TWindowDD__sub_803435A0(window_dd);
    }
}

}
