#include "types.h"
#include "pso/ui/window/TWindowDD.h"

extern "C" {
s32 TWindowDD__sub_803428C4(void *);
s32 TWindowDD__sub_80342B5C(void *);
s32 update_numeric_parameter_input__9TWindowDDFPv();
s32 TWindowDD__sub_803435A0(void *);
s32 TWindowDD__sub_80347C50();
s32 TWindowDD__sub_803482B0(void *);
extern s32 TWindowDD__window_mode;
void TWindowDD__sub_80342D14(u8 *window_dd);
void TWindowDD::update_transition() {
    TWindowDD__sub_80347C50();
    update_selection_state();
    if (test_input_flag_4() != 0) {
        TWindowDD::play_sound();
        *(s32 *)((s8 *)this + 0xB4) = 6;
        TWindowDD__sub_803435A0(this);
        return;
    }
    if (TWindowDD__sub_803482B0(this) != 0) {
        TWindowDD::play_se();
        TWindowDD::apply_entry_layout(this);
    }
}
void TWindowDD__sub_80342D14(u8 *window_dd) {
    s32 var_r31;
    var_r31 = 0;
    *(s16 *)((s8 *)window_dd + 0xC6) = 1;
    switch (*(s32 *)((s8 *)window_dd + 0xB8)) {
    case 0:
        TWindowDD__sub_80347C50();
        ((TWindowDD *)window_dd)->update_selection_state();
        if (((TWindowDD *)window_dd)->test_input_flag_4() != 0) {
            TWindowDD::play_sound();
            var_r31 = !TWindowDD::update_close_flag(window_dd);
        } else if (TWindowDD__sub_803482B0(window_dd) != 0) {
            TWindowDD::play_se();
            ((TWindowDD *)window_dd)->m_a4 = 0;
            TWindowDD::apply_entry_layout(window_dd);
        }
        break;
    case 1:
        var_r31 = update_numeric_parameter_input__9TWindowDDFPv();
        break;
    }
    if (var_r31) {
        ((TWindowDD *)window_dd)->m_a4 = 1;
        if ((s32) ((TWindowDD *)window_dd)->m_8c == -0x3C) {
            *(s32 *)((s8 *)window_dd + 0xB4) = 0x14;
        } else {
            switch (TWindowDD__window_mode) {
            case 0:
                TWindowDD__sub_80342B5C(window_dd);
                ((TWindowDD *)(window_dd + 0xC4))->init_item_slots();
                *(s16 *)((s8 *)window_dd + 0xC6) = 3;
                break;
            case 1:
            case 2:
            case 3:
            case 4:
            default:
                ((TWindowDD *)(window_dd + 0xC4))->init_item_slots();
                *(s16 *)((s8 *)window_dd + 0xC6) = 4;
                TWindowDD__sub_803428C4(window_dd);
                break;
            }
        }
        TWindowDD__sub_803435A0(window_dd);
    }
}

}
