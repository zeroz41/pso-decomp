#include "types.h"
#include "pso/ui/window/TWindowDD.h"

extern "C" {

s32 update_numeric_parameter_input__9TWindowDDFPv();
s32 apply_entry_layout__9TWindowDDFPv(void *);
s32 TWindowDD__sub_803435A0(void *);
s32 TWindowDD__sub_80347C50();
s32 TWindowDD__sub_803482B0(void *);
s32 update_close_flag__9TWindowDDFPv(void *);

void TWindowDD::enter_state_19() {
    s32 temp_r0;
    s32 var_r31;

    var_r31 = 0;
    temp_r0 = *(s32 *)((s8 *)this + 0xB8);
    switch (temp_r0) {
    case 0:
        TWindowDD__sub_80347C50();
        update_selection_state();
        if (test_input_flag_4() != 0) {
            TWindowDD::play_sound();
            var_r31 = update_close_flag__9TWindowDDFPv(this) == 0;
        } else if (TWindowDD__sub_803482B0(this) != 0) {
            TWindowDD::play_se();
            apply_entry_layout__9TWindowDDFPv(this);
        }
        break;
    case 1:
        var_r31 = update_numeric_parameter_input__9TWindowDDFPv();
        break;
    }
    if ((s32) var_r31 != 0) {
        *(s32 *)((s8 *)this + 0xB4) = 0x13;
        TWindowDD__sub_803435A0(this);
    }
}

void TWindowDD::enter_state_18() {
    s32 temp_r0;
    s32 var_r31;

    var_r31 = 0;
    temp_r0 = *(s32 *)((s8 *)this + 0xB8);
    switch (temp_r0) {
    case 0:
        TWindowDD__sub_80347C50();
        update_selection_state();
        if (test_input_flag_4() != 0) {
            TWindowDD::play_sound();
            var_r31 = update_close_flag__9TWindowDDFPv(this) == 0;
        } else if (TWindowDD__sub_803482B0(this) != 0) {
            TWindowDD::play_se();
            apply_entry_layout__9TWindowDDFPv(this);
        }
        break;
    case 1:
        var_r31 = update_numeric_parameter_input__9TWindowDDFPv();
        break;
    }
    if ((s32) var_r31 != 0) {
        *(s32 *)((s8 *)this + 0xB4) = 0x12;
        TWindowDD__sub_803435A0(this);
    }
}

}
