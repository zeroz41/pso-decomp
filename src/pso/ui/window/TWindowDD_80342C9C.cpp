#include "types.h"
#include "pso/ui/window/TWindowDD.h"

extern "C" {
s32 TWindowDD__sub_803428C4(void *);
s32 TWindowDD__sub_80342B5C(void *);
s32 update_numeric_parameter_input__9TWindowDDFPv();
s32 begin_word_select_state(void *);
s32 refresh_word_select_child_list();
s32 is_word_select_cancel_input(void *);
void TWindowDD::update_transition() {
    refresh_word_select_child_list();
    update_selection_state();
    if (test_input_flag_4() != 0) {
        TWindowDD::play_sound();
        next_state = 6;
        begin_word_select_state(this);
        return;
    }
    if (is_word_select_cancel_input(this) != 0) {
        TWindowDD::play_se();
        TWindowDD::apply_entry_layout(this);
    }
}
void TWindowDD__sub_80342D14(u8 *window_dd) {
    s32 done;
    TWindowDD *w = (TWindowDD *)window_dd;
    done = 0;
    w->message.type = 1;
    switch (w->dialog_locked) {
    case 0:
        refresh_word_select_child_list();
        w->update_selection_state();
        if (w->test_input_flag_4() != 0) {
            TWindowDD::play_sound();
            done = !TWindowDD::update_close_flag(window_dd);
        } else if (is_word_select_cancel_input(window_dd) != 0) {
            TWindowDD::play_se();
            w->m_a4 = 0;
            TWindowDD::apply_entry_layout(window_dd);
        }
        break;
    case 1:
        done = update_numeric_parameter_input__9TWindowDDFPv();
        break;
    }
    if (done) {
        w->m_a4 = 1;
        if ((s32) w->m_8c == -0x3C) {
            w->next_state = 0x14;
        } else {
            switch (TWindowDD::window_mode) {
            case 0:
                TWindowDD__sub_80342B5C(window_dd);
                w->message.init();
                w->message.type = 3;
                break;
            case 1:
            case 2:
            case 3:
            case 4:
            default:
                w->message.init();
                w->message.type = 4;
                TWindowDD__sub_803428C4(window_dd);
                break;
            }
        }
        begin_word_select_state(window_dd);
    }
}

}
