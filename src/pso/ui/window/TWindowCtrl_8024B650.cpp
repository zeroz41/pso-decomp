#include "types.h"
#include "pso/ui/window/TWindowCtrl.h"

extern "C" {

s32 update_child_2c__15TWindowCtrlMainFv(u32, s32, s32);

void TWindowCtrl::set_window_flags(void *client_id, s32 flags, s32 arg2) {
    u32 window;

    window = (u32)TWindowCtrl::get_window((saddr)client_id);
    if (window != 0U) {
        update_child_2c__15TWindowCtrlMainFv(window, flags, arg2 | 0xE);
    }
}

}
