#include "types.h"

extern "C" {
s16 TWindowDD__sub_80342158(int);
s32 apply_entry_layout__9TWindowDDFPv(void *);
s32 TWindowDD__sub_803435A0(void *);
s32 update_selection_state__9TWindowDDFv(void *);
s32 TWindowDD__sub_80347C50();
s32 play_se__9TWindowDDFv();
s32 play_sound__9TWindowDDFv();
s32 TWindowDD__sub_803482B0(void *);
s32 test_input_flag_4__9TWindowDDFv(void *);
void TWindowDD__sub_80342800(u8 *arg0);
void TWindowDD__sub_803428C4(u8 *arg0);
s32 update_numeric_parameter_input__9TWindowDDFPv();
s32 update_close_flag__9TWindowDDFPv(void *);
s32 TWindowDD_is_id_in_range_5AC_5F9();
void TWindowDD__sub_803429B0(u8 *arg0);
void enter_state_16__9TWindowDDFPv(void *arg0);
void update__9TWindowDDFi(s32 arg0);
void update_state__9TWindowDDFPv(void *arg0);

void enter_state_16__9TWindowDDFPv(void *window_dd) {
    s32 temp_r0;
    s32 var_r31;

    var_r31 = 0;
    temp_r0 = *(s32 *)((s8 *)window_dd + 0xB8);
    switch (temp_r0) {
    case 0:
        TWindowDD__sub_80347C50();
        update_selection_state__9TWindowDDFv(window_dd);
        if (test_input_flag_4__9TWindowDDFv(window_dd) != 0) {
            play_sound__9TWindowDDFv();
            var_r31 = update_close_flag__9TWindowDDFPv(window_dd) == 0;
        } else if (TWindowDD__sub_803482B0(window_dd) != 0) {
            play_se__9TWindowDDFv();
            apply_entry_layout__9TWindowDDFPv(window_dd);
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

void update_state__9TWindowDDFPv(void *window_dd) {
    TWindowDD__sub_80347C50();
    update_selection_state__9TWindowDDFv(window_dd);
    if (test_input_flag_4__9TWindowDDFv(window_dd) != 0) {
        play_sound__9TWindowDDFv();
        *(s32 *)((s8 *)window_dd + 0xB4) = 0xF;
        TWindowDD__sub_803435A0(window_dd);
        return;
    }
    if (TWindowDD__sub_803482B0(window_dd) != 0) {
        play_se__9TWindowDDFv();
        apply_entry_layout__9TWindowDDFPv(window_dd);
    }
}

void TWindowDD__sub_80342800(u8 *arg0) {
    u8 *var_r31;
    u8 *var_r3;
    var_r31 = arg0;
    TWindowDD__sub_80347C50();
    var_r3 = var_r31;
    update_selection_state__9TWindowDDFv(var_r3);
    var_r3 = var_r31;
    if (test_input_flag_4__9TWindowDDFv(var_r3) != 0) {
        play_sound__9TWindowDDFv();
        var_r3 = (u8 *)(var_r31 + (*(s32 *)((s8 *)var_r31 + 0x20) * 4));
        var_r3 = (u8 *)(*(u8 **)((s8 *)var_r3 + 0x24));
        if (TWindowDD__sub_80342158((int)var_r3) == 0x2C8) {
            var_r3 = (u8 *)((void *)5);
            *(s32 *)((s8 *)var_r31 + 0xB4) = 0x11;
            *(s16 *)((s8 *)var_r31 + 0xC6) = 5;
            *(s16 *)((s8 *)var_r31 + 0xC4) = 0;
        } else {
            var_r3 = (u8 *)((void *)4);
            *(s32 *)((s8 *)var_r31 + 0xB4) = 0xE;
            *(s16 *)((s8 *)var_r31 + 0xC6) = 4;
            *(s16 *)((s8 *)var_r31 + 0xC4) = 1;
        }
        var_r3 = var_r31;
        TWindowDD__sub_803435A0(var_r3);
        return;
    }
    var_r3 = var_r31;
    if (TWindowDD__sub_803482B0(var_r3) != 0) {
        play_se__9TWindowDDFv();
        var_r3 = var_r31;
        apply_entry_layout__9TWindowDDFPv(var_r3);
    }
}

void TWindowDD__sub_803428C4(u8 *arg0) {
    u8 *var_r31;
    u8 *var_r3;
    var_r31 = arg0;
    *(s32 *)((s8 *)arg0 + 0xB4) = 0xD;
    *(s16 *)((s8 *)arg0 + 0xFC) = 0x37;
    var_r3 = (u8 *)(var_r31 + (*(s32 *)((s8 *)arg0 + 0x20) * 4));
    var_r3 = (u8 *)(*(u8 **)((s8 *)var_r3 + 0x24));
    if (var_r3 != NULL) {
        *(s16 *)((s8 *)var_r31 + 0xFC) = TWindowDD__sub_80342158((int)var_r3);
        if ((s16) *(s16 *)((s8 *)var_r31 + 0xFC) == 0x43) {
            var_r3 = (u8 *)((void *)0x11U);
            *(s32 *)((s8 *)var_r31 + 0xB4) = 0x11;
            *(s16 *)((s8 *)var_r31 + 0xC6) = 5;
        }
        *(s16 *)((s8 *)var_r31 + 0xC4) = 0;
    }
}

void update__9TWindowDDFi(s32 arg0) {
    TWindowDD__sub_80347C50();
    if (test_input_flag_4__9TWindowDDFv((void *)arg0) != 0) {
        play_sound__9TWindowDDFv();
        TWindowDD__sub_803428C4((u8 *)arg0);
        TWindowDD__sub_803435A0((void *)arg0);
        return;
    }
    if (TWindowDD__sub_803482B0((void *)arg0) != 0) {
        play_se__9TWindowDDFv();
        apply_entry_layout__9TWindowDDFPv((void *)arg0);
    }
}
void TWindowDD__sub_803429B0(u8 *window_dd) {
    s32 var_r31;
    u8 *var_r3;
    var_r31 = 0;
    switch (*(s32 *)((s8 *)window_dd + 0xB8)) {
    case 0:
        ((s32 (*)())update_selection_state__9TWindowDDFv)();
        if (test_input_flag_4__9TWindowDDFv(window_dd) != 0) {
            play_sound__9TWindowDDFv();
            var_r31 = update_close_flag__9TWindowDDFPv(window_dd) == 0;
        } else if (TWindowDD__sub_803482B0(window_dd) != 0) {
            play_se__9TWindowDDFv();
            apply_entry_layout__9TWindowDDFPv(window_dd);
        }
        break;
    case 1:
        var_r31 = update_numeric_parameter_input__9TWindowDDFPv();
        break;
    }
    if (var_r31 != 0) {
        var_r3 = (u8 *)(window_dd + (*(s32 *)((s8 *)window_dd + 0x20) * 4));
        var_r3 = (u8 *)(*(u8 **)((s8 *)var_r3 + 0x24));
        TWindowDD__sub_80342158((int)var_r3);
        if (TWindowDD_is_id_in_range_5AC_5F9() != 0) {
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
