#include "types.h"
#include "pso/ui/window/TWindowSnapShot.h"
#include "pso/ui/window/TWindowSoundBalance.h"
#include "pso/ui/window/TWindowOptionCtrl.h"

extern "C" {

s32 __nw__7TObjectFUl(s32);
s32 get_option_entry__17TWindowOptionCtrlFi(s32);

s32 TWindowOptionCtrl::create_snap_shot_window() {
    s32 window_snap_shot;

    window_snap_shot = __nw__7TObjectFUl(0x64);
    if (window_snap_shot != 0) {
        window_snap_shot = (s32)TWindowSnapShot__ct((TWindowSnapShot *)((u8 *)window_snap_shot), get_option_entry__17TWindowOptionCtrlFi(0xCF));
    }
    return window_snap_shot;
}

s32 TWindowOptionCtrl::create_sound_balance_window() {
    s32 var_r31;

    var_r31 = __nw__7TObjectFUl(0x68);
    if (var_r31 != 0) {
        var_r31 = (s32)TWindowSoundBalance__ct((u8 *)var_r31, get_option_entry__17TWindowOptionCtrlFi(0xCF));
    }
    return var_r31;
}

}
