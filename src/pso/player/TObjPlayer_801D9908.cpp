#include "types.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

s32 is_invalid_slot__10TObjPlayerFUc(u8);

u8 TObjPlayer::clamp_to_max(saddr arg0, u8 arg1, u8 arg2) {
    u8 var_r3;

    if (is_invalid_slot__10TObjPlayerFUc(arg1) != 0) {
        return arg1;
    }
    var_r3 = arg1;
    if (arg1 > arg2) {
        var_r3 = arg2;
    }
    return var_r3;
}

}
