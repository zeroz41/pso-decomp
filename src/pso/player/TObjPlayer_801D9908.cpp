#include "types.h"
#include "pso/player/TObjPlayer.h"


u8 TObjPlayer::clamp_to_max(saddr arg0, u8 arg1, u8 arg2) {
    u8 var_r3;

    if (TObjPlayer::is_invalid_slot(arg1) != 0) {
        return arg1;
    }
    var_r3 = arg1;
    if (arg1 > arg2) {
        var_r3 = arg2;
    }
    return var_r3;
}

