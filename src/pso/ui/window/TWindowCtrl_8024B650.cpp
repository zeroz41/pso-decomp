#include "types.h"
#include "pso/ui/window/TWindowCtrl.h"

extern "C" {

u32 get_window__11TWindowCtrlFl();
s32 update_child_2c__15TWindowCtrlMainFv(u32, s32, s32);

void TWindowCtrl::set_window_flags(void *arg0, s32 arg1, s32 arg2) {
    u32 temp_r3;

    temp_r3 = get_window__11TWindowCtrlFl();
    if (temp_r3 != 0U) {
        update_child_2c__15TWindowCtrlMainFv(temp_r3, arg1, arg2 | 0xE);
    }
}

}
