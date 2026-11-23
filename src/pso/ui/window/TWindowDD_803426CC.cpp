#include "pso/ui/window/TWindowDD_80341A08.h"
#include "types.h"
#include "pso/ui/window/TWindowDD.h"

extern "C" {
s32 TWindowDD__sub_803435A0(void *);
s32 TWindowDD__sub_80347C50();
s32 TWindowDD__sub_803482B0(void *);
void TWindowDD__sub_80342800(u8 *arg0);
void TWindowDD__sub_803428C4(u8 *window_dd);
s32 update_numeric_parameter_input__9TWindowDDFPv();
void TWindowDD__sub_803429B0(u8 *window_dd);
void update__9TWindowDDFi(saddr window_dd);

void TWindowDD::enter_state_16(void *window_dd) {
    s32 var_r31;

    var_r31 = 0;
    switch (*(s32 *)((s8 *)window_dd + 0xB8)) {
    case 0:
        TWindowDD__sub_80347C50();
        ((TWindowDD *)window_dd)->update_selection_state();
        if (((TWindowDD *)window_dd)->test_input_flag_4() != 0) {
            TWindowDD::play_sound();
            var_r31 = TWindowDD::update_close_flag(window_dd) == 0;
        } else if (TWindowDD__sub_803482B0(window_dd) != 0) {
            TWindowDD::play_se();
            TWindowDD::apply_entry_layout(window_dd);
        }
        break;
    case 1:
        var_r31 = update_numeric_parameter_input__9TWindowDDFPv();
        break;
    }
    if ((s32) var_r31 != 0) {
        *(s32 *)((s8 *)window_dd + 0xB4) = 0x10;
        TWindowDD__sub_803435A0(window_dd);
    }
}

void TWindowDD::update_state(void *window_dd) {
    TWindowDD__sub_80347C50();
    ((TWindowDD *)window_dd)->update_selection_state();
    if (((TWindowDD *)window_dd)->test_input_flag_4() != 0) {
        TWindowDD::play_sound();
        *(s32 *)((s8 *)window_dd + 0xB4) = 0xF;
        TWindowDD__sub_803435A0(window_dd);
        return;
    }
    if (TWindowDD__sub_803482B0(window_dd) != 0) {
        TWindowDD::play_se();
        TWindowDD::apply_entry_layout(window_dd);
    }
}

void TWindowDD__sub_80342800(u8 *arg0) {
    u8 *var_r31;
    u8 *window_dd;
    var_r31 = arg0;
    TWindowDD__sub_80347C50();
    window_dd = var_r31;
    ((TWindowDD *)window_dd)->update_selection_state();
    window_dd = var_r31;
    if (((TWindowDD *)window_dd)->test_input_flag_4() != 0) {
        TWindowDD::play_sound();
        window_dd = (u8 *)(var_r31 + (*(s32 *)((s8 *)var_r31 + 0x20) * 4));
        window_dd = (u8 *)(*(u8 **)((s8 *)window_dd + 0x24));
        if (static_cast<s16>(TWindowDD__sub_80342158(reinterpret_cast<const TWindowDD_WS_Word *>(window_dd))) == 0x2C8) {
            window_dd = (u8 *)((void *)5);
            *(s32 *)((s8 *)var_r31 + 0xB4) = 0x11;
            *(s16 *)((s8 *)var_r31 + 0xC6) = 5;
            *(s16 *)((s8 *)var_r31 + 0xC4) = 0;
        } else {
            window_dd = (u8 *)((void *)4);
            *(s32 *)((s8 *)var_r31 + 0xB4) = 0xE;
            *(s16 *)((s8 *)var_r31 + 0xC6) = 4;
            *(s16 *)((s8 *)var_r31 + 0xC4) = 1;
        }
        window_dd = var_r31;
        TWindowDD__sub_803435A0(window_dd);
        return;
    }
    window_dd = var_r31;
    if (TWindowDD__sub_803482B0(window_dd) != 0) {
        TWindowDD::play_se();
        window_dd = var_r31;
        TWindowDD::apply_entry_layout(window_dd);
    }
}

void TWindowDD__sub_803428C4(u8 *window_dd) {
    u8 *var_r31;
    u8 *var_r3;
    var_r31 = window_dd;
    *(s32 *)((s8 *)window_dd + 0xB4) = 0xD;
    *(s16 *)((s8 *)window_dd + 0xFC) = 0x37;
    var_r3 = (u8 *)(var_r31 + (*(s32 *)((s8 *)window_dd + 0x20) * 4));
    var_r3 = (u8 *)(*(u8 **)((s8 *)var_r3 + 0x24));
    if (var_r3 != NULL) {
        *(s16 *)((s8 *)var_r31 + 0xFC) = TWindowDD__sub_80342158(reinterpret_cast<TWindowDD_WS_Word *>(var_r3));
        if ((s16) *(s16 *)((s8 *)var_r31 + 0xFC) == 0x43) {
            var_r3 = (u8 *)((void *)0x11U);
            *(s32 *)((s8 *)var_r31 + 0xB4) = 0x11;
            *(s16 *)((s8 *)var_r31 + 0xC6) = 5;
        }
        *(s16 *)((s8 *)var_r31 + 0xC4) = 0;
    }
}

void update__9TWindowDDFi(saddr window_dd) {
    TWindowDD__sub_80347C50();
    if (((TWindowDD *)window_dd)->test_input_flag_4() != 0) {
        TWindowDD::play_sound();
        TWindowDD__sub_803428C4((u8 *)window_dd);
        TWindowDD__sub_803435A0((void *)window_dd);
        return;
    }
    if (TWindowDD__sub_803482B0((void *)window_dd) != 0) {
        TWindowDD::play_se();
        TWindowDD::apply_entry_layout((void *)window_dd);
    }
}
void TWindowDD__sub_803429B0(u8 *window_dd) {
    s32 var_r31;
    u8 *var_r3;
    var_r31 = 0;
    switch (*(s32 *)((s8 *)window_dd + 0xB8)) {
    case 0:
        ((TWindowDD *)window_dd)->update_selection_state();
        if (((TWindowDD *)window_dd)->test_input_flag_4() != 0) {
            TWindowDD::play_sound();
            var_r31 = TWindowDD::update_close_flag(window_dd) == 0;
        } else if (TWindowDD__sub_803482B0(window_dd) != 0) {
            TWindowDD::play_se();
            TWindowDD::apply_entry_layout(window_dd);
        }
        break;
    case 1:
        var_r31 = update_numeric_parameter_input__9TWindowDDFPv();
        break;
    }
    if (var_r31 != 0) {
        var_r3 = (u8 *)(window_dd + (*(s32 *)((s8 *)window_dd + 0x20) * 4));
        var_r3 = (u8 *)(*(u8 **)((s8 *)var_r3 + 0x24));
        if (TWindowDD_is_id_in_range_5AC_5F9(TWindowDD__sub_80342158(reinterpret_cast<TWindowDD_WS_Word *>(var_r3))) != 0) {
            *(s32 *)((s8 *)window_dd + 0xB4) = 0xA;
        } else {
            *(s32 *)((s8 *)window_dd + 0xB4) = 0xB;
            *(s32 *)((s8 *)window_dd + 0x90) = -1;
        }
        *(s32 *)((s8 *)window_dd + 0x8C) = -0x32;
        TWindowDD__sub_803435A0(window_dd);
    }
}

}
