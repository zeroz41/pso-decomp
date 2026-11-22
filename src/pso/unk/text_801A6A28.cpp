#include "types.h"
#include "pso/unk/text_801A6A28.h"
#include "pso/unk/text_801A6A5C.h"

void fn_801A6A28(void *arg0, s32 arg1, s32 arg2) {
    *(s32 *)((s8 *)arg0 + 0x48) = (s32) (*(s32 *)((s8 *)arg0 + 0x48) | arg1);
    if (arg2 & arg1) {
        *(s32 *)((s8 *)arg0 + 0x4C) = (s32) (*(s32 *)((s8 *)arg0 + 0x4C) & ~arg1);
        return;
    }
    *(s32 *)((s8 *)arg0 + 0x4C) = (s32) (*(s32 *)((s8 *)arg0 + 0x4C) | arg1);
}

void map_c_stick_to_buttons(u8 *arg0, s16 arg1, s16 arg2, s32 arg3) {
    if (arg2 > 0x30) {
        fn_801A6A28(arg0, 0x08000000, arg3);
    } else if (arg2 < -0x30) {
        fn_801A6A28(arg0, 0x04000000, arg3);
    }
    if (arg1 > 0x30) {
        fn_801A6A28(arg0, 0x20000000, arg3);
        return;
    }
    if (arg1 < -0x30) {
        fn_801A6A28(arg0, 0x10000000, arg3);
    }
}
void map_main_stick_to_buttons(u8 *arg0, s16 arg1, s16 arg2, s32 arg3) {
    if (arg2 > 0x30) {
        fn_801A6A28(arg0, 0x200000, arg3);
    } else if (arg2 < -0x30) {
        fn_801A6A28(arg0, 0x100000, arg3);
    }
    if (arg1 > 0x30) {
        fn_801A6A28(arg0, 0x800000, arg3);
        return;
    }
    if (arg1 < -0x30) {
        fn_801A6A28(arg0, 0x400000, arg3);
    }
}
void update_button_hold_counter(void *arg0, void *arg1, int mask, int held) {
    s16 value = *(s16 *)arg1;
    if (held & mask) {
        value++;
    } else {
        value = 0;
    }
    *(s16 *)arg1 = value;
}

void update_button_hold_counters(u8 *key_board_control) {
    update_button_hold_counter(key_board_control, key_board_control + 0x2C, 0x10, (int) (*(s32 *)((s8 *)key_board_control + 0x48)));
    update_button_hold_counter(key_board_control, key_board_control + 0x2E, 0x20, (int) (*(s32 *)((s8 *)key_board_control + 0x48)));
    update_button_hold_counter(key_board_control, key_board_control + 0x30, 0x40, (int) (*(s32 *)((s8 *)key_board_control + 0x48)));
    update_button_hold_counter(key_board_control, key_board_control + 0x32, 0x80, (int) (*(s32 *)((s8 *)key_board_control + 0x48)));
    update_button_hold_counter(key_board_control, key_board_control + 0x34, 0x100000, (int) (*(s32 *)((s8 *)key_board_control + 0x48)));
    update_button_hold_counter(key_board_control, key_board_control + 0x36, 0x200000, (int) (*(s32 *)((s8 *)key_board_control + 0x48)));
    update_button_hold_counter(key_board_control, key_board_control + 0x38, 0x400000, (int) (*(s32 *)((s8 *)key_board_control + 0x48)));
    update_button_hold_counter(key_board_control, key_board_control + 0x3A, 0x800000, (int) (*(s32 *)((s8 *)key_board_control + 0x48)));
    update_button_hold_counter(key_board_control, key_board_control + 0x3C, 0x04000000, (int) (*(s32 *)((s8 *)key_board_control + 0x48)));
    update_button_hold_counter(key_board_control, key_board_control + 0x3E, 0x08000000, (int) (*(s32 *)((s8 *)key_board_control + 0x48)));
    update_button_hold_counter(key_board_control, key_board_control + 0x40, 0x10000000, (int) (*(s32 *)((s8 *)key_board_control + 0x48)));
    update_button_hold_counter(key_board_control, key_board_control + 0x42, 0x20000000, (int) (*(s32 *)((s8 *)key_board_control + 0x48)));
    update_button_hold_counter(key_board_control, key_board_control + 0x44, 0x20000, (int) (*(s32 *)((s8 *)key_board_control + 0x48)));
    update_button_hold_counter(key_board_control, key_board_control + 0x46, 0x10000, (int) (*(s32 *)((s8 *)key_board_control + 0x48)));
}
