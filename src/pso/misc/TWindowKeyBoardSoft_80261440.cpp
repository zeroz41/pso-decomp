#include "types.h"
#include "pso/misc/TWindowCtrl_8024A054.h"
#include "pso/misc/TWindowKeyBoardSoft_80261440.h"
#include "pso/misc/TKeyBoardControl.h"
#include "pso/misc/TWindowKeyBoardSoft.h"
#include "pso/misc/TWindowDD.h"
#pragma fp_contract on

extern "C" {

s32 TWindowKeyBoardSoft__sub_80260904(void *, s32);
s32 TWindowKeyBoardSoft__sub_80260E30(void *, s32);
s32 sub_80244994__11TWindowBaseFv();
s32 update_fade__11TWindowBaseFv(void *);
s32 initialize_subwindow__9TWindowDDFv(void *);

extern const f32 lbl_805DD0D4;

void TWindowKeyBoardSoft::run_task() {
    f32 temp_f0;
    s32 temp_r3;

    if ((u32) *(u32 *)((s8 *)this + 0x6C) != 0U) {
        if ((sub_80244994__11TWindowBaseFv() != 0) && (((TKeyBoardControl *)(*(u32 *)((s8 *)this + 0x6C)))->is_key_active() == 0)) {
            temp_r3 = is_player_input_active(*(s16 *)((s8 *)this + 0x20));
            handle_page_cycle_input(temp_r3);
            TWindowKeyBoardSoft__sub_80260E30(this, temp_r3);
            TWindowKeyBoardSoft__sub_80260904(this, temp_r3);
            update_keyboard_child_input_from_controller(temp_r3);
            sub_80260808(temp_r3);
        }
        initialize_subwindow__9TWindowDDFv(this);
        update_fade__11TWindowBaseFv(this);
        *(f32 *)((s8 *)this + 0x68) -= lbl_805DD0D4 * *(f32 *)((s8 *)this + 0x68);
    }
}

}

#pragma fp_contract off

struct RecoveredGlobal_80262740___vt__19TWindowKeyBoardSoft {
    s32 value;
    u8 remaining[0x220];
};

struct RecoveredGlobal_80262740_lbl_804D0004 {
    s32 value;
    u8 remaining[0x18];
};

extern "C" {
s32 construct_base__9TWindowDDFPUcsPUc(void *, void *, void *, int);
s32 get_window_layout_position(int);
extern RecoveredGlobal_80262740___vt__19TWindowKeyBoardSoft soft_keyboard_window_and_action_data;
extern s32 __vt__19TWindowKeyBoardSoft[];
extern s32 keyboard_soft_type_name_pointer;
extern const f32 TWindowKeyBoardSoft__data_805DD090;
void __dl__7TObjectFPv(void *);

void *__dt__19TWindowKeyBoardSoftFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__19TWindowKeyBoardSoft;
        ((TWindowDD *)arg0)->destroy_window_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_80262740___vt__19TWindowKeyBoardSoft_size[sizeof(RecoveredGlobal_80262740___vt__19TWindowKeyBoardSoft) == 0x224 ? 1 : -1];
typedef char RecoveredGlobal_80262740_lbl_804D0004_size[sizeof(RecoveredGlobal_80262740_lbl_804D0004) == 0x1C ? 1 : -1];
u8 *TWindowKeyBoardSoft__ct(u8 *arg0, s32 arg1, s16 arg2) {
    construct_base__9TWindowDDFPUcsPUc((void *)arg0, &soft_keyboard_window_and_action_data.value, (void *)arg2, (int) (get_window_layout_position(0xBA)));
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_80262740_lbl_804D0004 *)&__vt__19TWindowKeyBoardSoft).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) keyboard_soft_type_name_pointer;
    *(s32 *)((s8 *)arg0 + 0x60) = 0;
    *(s8 *)((s8 *)arg0 + 0x64) = 0;
    *(s8 *)((s8 *)arg0 + 0x65) = 2;
    *(s8 *)((s8 *)arg0 + 0x66) = 1;
    *(f32 *)((s8 *)arg0 + 0x68) = (f32) TWindowKeyBoardSoft__data_805DD090;
    *(s32 *)((s8 *)arg0 + 0x6C) = arg1;
    ((TWindowKeyBoardSoft *)arg0)->close();
    return arg0;
}

}
