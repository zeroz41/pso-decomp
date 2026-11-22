#include "pso/system/ControllerInputState.h"
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
void update_button_hold_counter(void *key_board_control, void *arg1, int mask, int held) {
    s16 value = *(s16 *)arg1;
    if (held & mask) {
        value++;
    } else {
        value = 0;
    }
    *(s16 *)arg1 = value;
}

void update_button_hold_counters(ControllerInputContext *arg0) {
    update_button_hold_counter(arg0, &arg0->hold_counters.frames[0], 0x10, arg0->previous_buttons);
    update_button_hold_counter(arg0, &arg0->hold_counters.frames[1], 0x20, arg0->previous_buttons);
    update_button_hold_counter(arg0, &arg0->hold_counters.frames[2], 0x40, arg0->previous_buttons);
    update_button_hold_counter(arg0, &arg0->hold_counters.frames[3], 0x80, arg0->previous_buttons);
    update_button_hold_counter(arg0, &arg0->hold_counters.frames[4], 0x100000, arg0->previous_buttons);
    update_button_hold_counter(arg0, &arg0->hold_counters.frames[5], 0x200000, arg0->previous_buttons);
    update_button_hold_counter(arg0, &arg0->hold_counters.frames[6], 0x400000, arg0->previous_buttons);
    update_button_hold_counter(arg0, &arg0->hold_counters.frames[7], 0x800000, arg0->previous_buttons);
    update_button_hold_counter(arg0, &arg0->hold_counters.frames[8], 0x04000000, arg0->previous_buttons);
    update_button_hold_counter(arg0, &arg0->hold_counters.frames[9], 0x08000000, arg0->previous_buttons);
    update_button_hold_counter(arg0, &arg0->hold_counters.frames[10], 0x10000000, arg0->previous_buttons);
    update_button_hold_counter(arg0, &arg0->hold_counters.frames[11], 0x20000000, arg0->previous_buttons);
    update_button_hold_counter(arg0, &arg0->hold_counters.frames[12], 0x20000, arg0->previous_buttons);
    update_button_hold_counter(arg0, &arg0->hold_counters.frames[13], 0x10000, arg0->previous_buttons);
}
