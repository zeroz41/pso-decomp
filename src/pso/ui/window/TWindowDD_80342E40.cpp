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
s32 TWindowDD__sub_80347CC8(void *, void *);
s32 TWindowDD__sub_803435A0(void *);
s32 refresh_word_select_child_list();
s32 is_word_select_cancel_input(void *);
s32 TWindowDD__sub_80348424(void *, s16);
s16 TWindowDD__sub_80348448(void *, s32);
s32 push_recent_id(s32);
s32 TWindowDD__sub_803484C4(void *);

void TWindowDD::update() {
    this->update_selection_state();
    if (test_input_flag_4() != 0) {
        TWindowDD::play_sound();
        if (state == 1) {
            next_state = 0x14;
            list_ids[1] = -0x3C;
            TWindowDD__sub_803435A0(this);
            return;
        }
        TWindowDD__sub_803484C4(this);
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
        id = get_word_select_selected_id(pages[depth]);
        message.type = TWindowDD__sub_80348448(this, id);
        next_state = TWindowDD__sub_80348424(this, id);
        push_recent_id(id);
        pad_104 = 0;
        TWindowDD__sub_803435A0(this);
        return;
    }
    if (is_word_select_cancel_input(this) != 0) {
        TWindowDD::play_se();
        set_state();
    }
}

u8 update_numeric_parameter_input__9TWindowDDFPv(TWindowDD *window_dd) {
    s32 kind;
    s32 result;
    result = 0;
    if (window_dd->number_window == NULL) {
        window_dd->get_current_child_index();
        kind = classify_id__9TWindowDDFs();
        if (kind != 7) {
            open_numeric_parameter_input__9TWindowDDFPviii(window_dd, 0, word_select_numeric_limits[kind], (void *) (TWindowDD__sub_80348D88(&window_dd->message)));
            return 0U;
        }
        return 1U;
    }
    TWindowDD__sub_80347CC8(window_dd, &window_dd->message);
    if (window_dd->number_window != NULL || window_dd->number_window->all_parents_unqueued_for_destruction() != 0) {
        window_dd->message.set_field14(window_dd->number_window->get_value());
        if (window_dd->number_window->is_cancelled() != 0) {
            result = 2;
            window_dd->message.reset_index();
            window_dd->number_window->close();
        } else if (window_dd->number_window->is_confirmed() != 0) {
            result = 1;
            window_dd->number_window->close();
        }
    } else {
        result = 2;
    }
    if (result != 0) {
        TWindowDD__sub_80341AF8(window_dd->pages[window_dd->depth]);
        window_dd->number_window = NULL;
        window_dd->numeric_input_active = 0;
    }
    return (u8) (result == 1);
}

}
