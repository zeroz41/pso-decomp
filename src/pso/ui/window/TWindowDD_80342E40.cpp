#include "pso/ui/window/TWindowDD_80341A08.h"
#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowDD_80342E40.h"
#include "pso/ui/window/TWindowDD_80348D0C.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/city/TShopEquipmentSellWindow.h"
#include "pso/ui/window/TWindowInputNumber.h"

const s32 word_select_numeric_limits[6] = { 999999, 99, 30, 15, 200, 999 };

extern "C" {
s32 open_numeric_parameter_input__9TWindowDDFPviii(void *, int, int, void *);
s32 classify_id__9TWindowDDFs();
s32 refresh_word_select_message(void *, void *);
s32 begin_word_select_state(void *);
s32 refresh_word_select_child_list();
s32 is_word_select_cancel_input(void *);
s32 TWindowDD__sub_80348424(void *, s16);
s16 TWindowDD__sub_80348448(void *, s32);
s32 push_recent_id(s32);
s32 finish_word_select(void *);

void TWindowDD::update() {
    this->update_selection_state();
    if (test_input_flag_4() != 0) {
        TWindowDD::play_sound();
        if ((s32) state == 1) {
            next_state = 0x14;
            this->m_8c = -0x3C;
            begin_word_select_state(this);
            return;
        }
        finish_word_select(this);
        return;
    }
    if (is_word_select_cancel_input(this) != 0) {
        TWindowDD::play_se();
        TWindowDD::apply_entry_layout(this);
    }
}

void TWindowDD::handle_confirm_input() {
    s32 id;
    refresh_word_select_child_list();
    if (test_input_flag_4() != 0) {
        TWindowDD::play_sound();
        id = get_word_select_selected_id(reinterpret_cast<TWindowDD_WS_Word *>(word_windows[depth]));
        message.type = TWindowDD__sub_80348448(this, id);
        next_state = TWindowDD__sub_80348424(this, id);
        push_recent_id(id);
        m_104 = 0;
        begin_word_select_state(this);
        return;
    }
    if (is_word_select_cancel_input(this) != 0) {
        TWindowDD::play_se();
        set_state();
    }
}

u8 update_numeric_parameter_input__9TWindowDDFPv(u8 *arg0) {
    s32 kind;
    s32 result;
    u8 *word_window;
    TWindowDD *w = (TWindowDD *)arg0;
    result = 0;
    if ((u32) w->number_window == 0U) {
        w->get_current_child_index();
        kind = classify_id__9TWindowDDFs();
        if (kind != 7) {
            open_numeric_parameter_input__9TWindowDDFPviii(arg0, 0, word_select_numeric_limits[kind], (void *) (w->message.get_numeric_parameter()));
            return 0U;
        }
        return 1U;
    }
    refresh_word_select_message(arg0, &w->message);
    if (((u32) w->number_window != 0U) || (((TObject *)w->number_window)->all_parents_unqueued_for_destruction() != 0)) {
        w->message.set_numeric_parameter((int) (((TWindowInputNumber *)w->number_window)->get_value()));
        if (((TWindowInputNumber *)w->number_window)->is_cancelled() != 0) {
            result = 2;
            w->message.reset_numeric_parameter();
            ((TWindowBase *)w->number_window)->close();
        } else if (((TWindowInputNumber *)w->number_window)->is_confirmed() != 0) {
            result = 1;
            ((TWindowBase *)w->number_window)->close();
        }
    } else {
        result = 2;
    }
    if (result != 0) {
        word_window = (u8 *)w->word_windows[w->depth];
        show_word_select_selection(word_window);
        w->number_window = 0U;
        w->dialog_locked = 0;
    }
    return (u8) (result == 1);
}

}
