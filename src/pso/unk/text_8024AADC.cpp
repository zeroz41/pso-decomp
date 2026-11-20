#include "types.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/unk/text_8024AADC.h"

extern "C" {
s32 free_member__15TWindowCtrlMainFv(u32 a0 = 0, s32 a1 = 0);
void fn_8024AADC(s32 arg0, s32 arg1) {
    u32 temp_r3 = (u32)TWindowCtrl::get_window(arg0);
    if (temp_r3 != 0U) {
        free_member__15TWindowCtrlMainFv(temp_r3, arg1);
    }
}

}
