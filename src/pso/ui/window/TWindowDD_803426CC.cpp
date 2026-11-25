#include "pso/ui/window/TWindowDD_WS_Word.h"
#include "types.h"
#include "pso/ui/window/TWindowDD.h"

extern "C" {
s32 begin_word_select_state(void *);
s32 refresh_word_select_child_list();
s32 is_word_select_cancel_input(void *);
s32 update_numeric_parameter_input__9TWindowDDFPv();

void TWindowDD::enter_state_16() {
    s32 done;

    done = 0;
    switch (dialog_locked) {
    case 0:
        refresh_word_select_child_list();
        update_selection_state();
        if (test_input_flag_4() != 0) {
            TWindowDD::play_sound();
            done = update_close_flag() == 0;
        } else if (is_word_select_cancel_input(this) != 0) {
            TWindowDD::play_se();
            apply_entry_layout();
        }
        break;
    case 1:
        done = update_numeric_parameter_input__9TWindowDDFPv();
        break;
    }
    if (done != 0) {
        next_state = 0x10;
        begin_word_select_state(this);
    }
}

void TWindowDD::update_state() {
    refresh_word_select_child_list();
    update_selection_state();
    if (test_input_flag_4() != 0) {
        TWindowDD::play_sound();
        next_state = 0xF;
        begin_word_select_state(this);
        return;
    }
    if (is_word_select_cancel_input(this) != 0) {
        TWindowDD::play_se();
        apply_entry_layout();
    }
}

void TWindowDD__sub_80342800(TWindowDD *window_dd) {
    refresh_word_select_child_list();
    window_dd->update_selection_state();
    if (window_dd->test_input_flag_4() != 0) {
        TWindowDD::play_sound();
        if (static_cast<s16>(window_dd->word_windows[window_dd->depth]->get_selected_id()) == 0x2C8) {
            window_dd->next_state = 0x11;
            window_dd->message.type = 5;
            window_dd->message.count = 0;
        } else {
            window_dd->next_state = 0xE;
            window_dd->message.type = 4;
            window_dd->message.count = 1;
        }
        begin_word_select_state(window_dd);
        return;
    }
    if (is_word_select_cancel_input(window_dd) != 0) {
        TWindowDD::play_se();
        window_dd->apply_entry_layout();
    }
}

void TWindowDD__sub_803428C4(TWindowDD *window_dd) {
    TWindowDD_WS_Word *page;
    window_dd->next_state = 0xD;
    window_dd->selected_word = 0x37;
    page = window_dd->word_windows[window_dd->depth];
    if (page != NULL) {
        window_dd->selected_word = page->get_selected_id();
        if (window_dd->selected_word == 0x43) {
            window_dd->next_state = 0x11;
            window_dd->message.type = 5;
        }
        window_dd->message.count = 0;
    }
}

void update__9TWindowDDFi(TWindowDD *window_dd) {
    refresh_word_select_child_list();
    if (window_dd->test_input_flag_4() != 0) {
        TWindowDD::play_sound();
        TWindowDD__sub_803428C4(window_dd);
        begin_word_select_state(window_dd);
        return;
    }
    if (is_word_select_cancel_input(window_dd) != 0) {
        TWindowDD::play_se();
        window_dd->apply_entry_layout();
    }
}
void TWindowDD__sub_803429B0(TWindowDD *window_dd) {
    s32 done;
    done = 0;
    switch (window_dd->dialog_locked) {
    case 0:
        window_dd->update_selection_state();
        if (window_dd->test_input_flag_4() != 0) {
            TWindowDD::play_sound();
            done = window_dd->update_close_flag() == 0;
        } else if (is_word_select_cancel_input(window_dd) != 0) {
            TWindowDD::play_se();
            window_dd->apply_entry_layout();
        }
        break;
    case 1:
        done = update_numeric_parameter_input__9TWindowDDFPv();
        break;
    }
    if (done != 0) {
        if (TWindowDD_is_id_in_range_5AC_5F9(window_dd->word_windows[window_dd->depth]->get_selected_id()) != 0) {
            window_dd->next_state = 0xA;
        } else {
            window_dd->next_state = 0xB;
            window_dd->list_ids[2] = -1;
        }
        window_dd->list_ids[1] = -0x32;
        begin_word_select_state(window_dd);
    }
}

}
