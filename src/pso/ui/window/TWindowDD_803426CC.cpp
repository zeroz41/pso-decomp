#include "pso/ui/window/TWindowDD_80341A08.h"
#include "types.h"
#include "pso/ui/window/TWindowDD.h"

extern "C" {
s32 begin_word_select_state(void *);
s32 refresh_word_select_child_list();
s32 is_word_select_cancel_input(void *);
s32 update_numeric_parameter_input__9TWindowDDFPv();

void TWindowDD::enter_state_16(void *window_dd) {
    s32 done;
    TWindowDD *w = (TWindowDD *)window_dd;

    done = 0;
    switch (w->dialog_locked) {
    case 0:
        refresh_word_select_child_list();
        w->update_selection_state();
        if (w->test_input_flag_4() != 0) {
            TWindowDD::play_sound();
            done = TWindowDD::update_close_flag(window_dd) == 0;
        } else if (is_word_select_cancel_input(window_dd) != 0) {
            TWindowDD::play_se();
            TWindowDD::apply_entry_layout(window_dd);
        }
        break;
    case 1:
        done = update_numeric_parameter_input__9TWindowDDFPv();
        break;
    }
    if ((s32) done != 0) {
        w->next_state = 0x10;
        begin_word_select_state(window_dd);
    }
}

void TWindowDD::update_state(void *window_dd) {
    TWindowDD *w = (TWindowDD *)window_dd;
    refresh_word_select_child_list();
    w->update_selection_state();
    if (w->test_input_flag_4() != 0) {
        TWindowDD::play_sound();
        w->next_state = 0xF;
        begin_word_select_state(window_dd);
        return;
    }
    if (is_word_select_cancel_input(window_dd) != 0) {
        TWindowDD::play_se();
        TWindowDD::apply_entry_layout(window_dd);
    }
}

void TWindowDD__sub_80342800(u8 *arg0) {
    TWindowDD *w = (TWindowDD *)arg0;
    refresh_word_select_child_list();
    w->update_selection_state();
    if (w->test_input_flag_4() != 0) {
        TWindowDD::play_sound();
        if (static_cast<s16>(get_word_select_selected_id(reinterpret_cast<const TWindowDD_WS_Word *>(w->word_windows[w->depth]))) == 0x2C8) {
            w->next_state = 0x11;
            w->message.type = 5;
            w->message.count = 0;
        } else {
            w->next_state = 0xE;
            w->message.type = 4;
            w->message.count = 1;
        }
        begin_word_select_state(arg0);
        return;
    }
    if (is_word_select_cancel_input(arg0) != 0) {
        TWindowDD::play_se();
        TWindowDD::apply_entry_layout(arg0);
    }
}

void TWindowDD__sub_803428C4(u8 *window_dd) {
    TWindowDD *w = (TWindowDD *)window_dd;
    u8 *word_window;
    w->next_state = 0xD;
    w->selected_word = 0x37;
    word_window = (u8 *)w->word_windows[w->depth];
    if (word_window != NULL) {
        w->selected_word = get_word_select_selected_id(reinterpret_cast<TWindowDD_WS_Word *>(word_window));
        if ((s16)w->selected_word == 0x43) {
            w->next_state = 0x11;
            w->message.type = 5;
        }
        w->message.count = 0;
    }
}

void update__9TWindowDDFi(saddr window_dd) {
    refresh_word_select_child_list();
    if (((TWindowDD *)window_dd)->test_input_flag_4() != 0) {
        TWindowDD::play_sound();
        TWindowDD__sub_803428C4((u8 *)window_dd);
        begin_word_select_state((void *)window_dd);
        return;
    }
    if (is_word_select_cancel_input((void *)window_dd) != 0) {
        TWindowDD::play_se();
        TWindowDD::apply_entry_layout((void *)window_dd);
    }
}

void TWindowDD__sub_803429B0(u8 *window_dd) {
    s32 done;
    u8 *word_window;
    TWindowDD *w = (TWindowDD *)window_dd;
    done = 0;
    switch (w->dialog_locked) {
    case 0:
        w->update_selection_state();
        if (w->test_input_flag_4() != 0) {
            TWindowDD::play_sound();
            done = TWindowDD::update_close_flag(window_dd) == 0;
        } else if (is_word_select_cancel_input(window_dd) != 0) {
            TWindowDD::play_se();
            TWindowDD::apply_entry_layout(window_dd);
        }
        break;
    case 1:
        done = update_numeric_parameter_input__9TWindowDDFPv();
        break;
    }
    if (done != 0) {
        word_window = (u8 *)w->word_windows[w->depth];
        if (TWindowDD_is_id_in_range_5AC_5F9(get_word_select_selected_id(reinterpret_cast<TWindowDD_WS_Word *>(word_window))) != 0) {
            w->next_state = 0xA;
        } else {
            w->next_state = 0xB;
            w->m_90 = -1;
        }
        w->m_8c = -0x32;
        begin_word_select_state(window_dd);
    }
}

}
