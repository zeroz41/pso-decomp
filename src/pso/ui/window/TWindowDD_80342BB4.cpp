#include "types.h"
#include "pso/ui/window/TWindowDD.h"

extern "C" {

s32 TWindowDD__sub_80342B5C(s32);
s32 begin_word_select_state(void *);
s32 refresh_word_select_child_list();
s32 is_word_select_cancel_input(void *);

void TWindowDD::update_dispatch() {
    saddr arg0 = (saddr)this;
    refresh_word_select_child_list();
    if (((TWindowDD *)arg0)->test_input_flag_4() != 0) {
        TWindowDD::play_sound();
        TWindowDD__sub_80342B5C(arg0);
        begin_word_select_state((void *)arg0);
        return;
    }
    if (is_word_select_cancel_input((void *)arg0) != 0) {
        TWindowDD::play_sound();
        TWindowDD::apply_entry_layout((void *)arg0);
    }
}

void TWindowDD::update_layout() {
    this->update_selection_state();
    if (test_input_flag_4() != 0) {
        TWindowDD::play_sound();
        next_state = 0x14;
        this->m_8c = -0x3C;
        begin_word_select_state(this);
        return;
    }
    if (is_word_select_cancel_input(this) != 0) {
        TWindowDD::play_se();
        TWindowDD::apply_entry_layout(this);
    }
}

}
