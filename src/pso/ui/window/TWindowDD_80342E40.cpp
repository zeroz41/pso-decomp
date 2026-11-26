#include "pso/ui/window/TWindowDD_WS_Word.h"
#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowDD_80348D0C.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/city/TShopEquipmentSellWindow.h"
#include "pso/ui/window/TWindowInputNumber.h"

const s32 word_select_numeric_limits[6] = { 999999, 99, 30, 15, 200, 999 };

extern "C" {
s32 classify_id__9TWindowDDFs();
s32 TWindowDD__sub_80348424(void *, s16);
s16 TWindowDD__sub_80348448(void *, s32);
s32 push_recent_id(s32);
}

void TWindowDD::update() {
    this->update_selection_state();
    if (test_input_flag_4() != 0) {
        TWindowDD::play_sound();
        if (state == 1) {
            next_state = 0x14;
            list_ids[1] = -0x3C;
            begin_word_select_state();
            return;
        }
        finish_word_select();
        return;
    }
    if (is_word_select_cancel_input() != 0) {
        TWindowDD::play_se();
        apply_entry_layout();
    }
}

void TWindowDD::handle_confirm_input() {
    s32 id;
    refresh_word_select_child_list();
    if (test_input_flag_4() != 0) {
        TWindowDD::play_sound();
        id = word_windows[depth]->get_selected_id();
        message.type = TWindowDD__sub_80348448(this, id);
        next_state = TWindowDD__sub_80348424(this, id);
        push_recent_id(id);
        pad_104 = 0;
        begin_word_select_state();
        return;
    }
    if (is_word_select_cancel_input() != 0) {
        TWindowDD::play_se();
        set_state();
    }
}

s32 TWindowDD::update_numeric_parameter_input() {
    s32 kind;
    s32 result;
    result = 0;
    if (number_window == NULL) {
        get_current_child_index();
        kind = classify_id__9TWindowDDFs();
        if (kind != 7) {
            open_numeric_parameter_input(0, word_select_numeric_limits[kind], message.get_numeric_parameter());
            return 0;
        }
        return 1;
    }
    refresh_word_select_message(&message);
    if (number_window != NULL || number_window->all_parents_unqueued_for_destruction() != 0) {
        message.set_numeric_parameter(number_window->get_value());
        if (number_window->is_cancelled() != 0) {
            result = 2;
            message.reset_numeric_parameter();
            number_window->close();
        } else if (number_window->is_confirmed() != 0) {
            result = 1;
            number_window->close();
        }
    } else {
        result = 2;
    }
    if (result != 0) {
        word_windows[depth]->enable_input();
        number_window = NULL;
        dialog_locked = 0;
    }
    return result == 1;
}

