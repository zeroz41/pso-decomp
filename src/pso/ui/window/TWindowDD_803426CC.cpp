#include "pso/ui/window/TWindowDD_WS_Word.h"
#include "types.h"
#include "pso/ui/window/TWindowDD.h"

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
        } else if (is_word_select_cancel_input() != 0) {
            TWindowDD::play_se();
            apply_entry_layout();
        }
        break;
    case 1:
        done = update_numeric_parameter_input();
        break;
    }
    if (done != 0) {
        next_state = 0x10;
        begin_word_select_state();
    }
}

void TWindowDD::update_state() {
    refresh_word_select_child_list();
    update_selection_state();
    if (test_input_flag_4() != 0) {
        TWindowDD::play_sound();
        next_state = 0xF;
        begin_word_select_state();
        return;
    }
    if (is_word_select_cancel_input() != 0) {
        TWindowDD::play_se();
        apply_entry_layout();
    }
}

void TWindowDD::handle_state_13() {
    refresh_word_select_child_list();
    update_selection_state();
    if (test_input_flag_4() != 0) {
        TWindowDD::play_sound();
        if (static_cast<s16>(word_windows[depth]->get_selected_id()) == 0x2C8) {
            next_state = 0x11;
            message.type = 5;
            message.count = 0;
        } else {
            next_state = 0xE;
            message.type = 4;
            message.count = 1;
        }
        begin_word_select_state();
        return;
    }
    if (is_word_select_cancel_input() != 0) {
        TWindowDD::play_se();
        apply_entry_layout();
    }
}

void TWindowDD::store_selected_word() {
    TWindowDD_WS_Word *page;
    next_state = 0xD;
    selected_word = 0x37;
    page = word_windows[depth];
    if (page != NULL) {
        selected_word = page->get_selected_id();
        if (selected_word == 0x43) {
            next_state = 0x11;
            message.type = 5;
        }
        message.count = 0;
    }
}

void TWindowDD::handle_state_12() {
    refresh_word_select_child_list();
    if (test_input_flag_4() != 0) {
        TWindowDD::play_sound();
        store_selected_word();
        begin_word_select_state();
        return;
    }
    if (is_word_select_cancel_input() != 0) {
        TWindowDD::play_se();
        apply_entry_layout();
    }
}
void TWindowDD::handle_state_9() {
    s32 done;
    done = 0;
    switch (dialog_locked) {
    case 0:
        update_selection_state();
        if (test_input_flag_4() != 0) {
            TWindowDD::play_sound();
            done = update_close_flag() == 0;
        } else if (is_word_select_cancel_input() != 0) {
            TWindowDD::play_se();
            apply_entry_layout();
        }
        break;
    case 1:
        done = update_numeric_parameter_input();
        break;
    }
    if (done != 0) {
        if (TWindowDD_is_id_in_range_5AC_5F9(word_windows[depth]->get_selected_id()) != 0) {
            next_state = 0xA;
        } else {
            next_state = 0xB;
            list_ids[2] = -1;
        }
        list_ids[1] = -0x32;
        begin_word_select_state();
    }
}

