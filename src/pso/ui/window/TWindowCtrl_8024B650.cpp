#include "types.h"
#include "pso/ui/window/TWindowCtrl.h"

extern "C" {

s32 update_child_2c__15TWindowCtrlMainFv(u32, s32, s32);

void TWindowCtrl::set_window_flags(void *arg0, s32 flags, s32 arg2) {
    u32 temp_r3;

    temp_r3 = (u32)TWindowCtrl::get_window((saddr)arg0);
    if (temp_r3 != 0U) {
        update_child_2c__15TWindowCtrlMainFv(temp_r3, flags, arg2 | 0xE);
    }
}

}
