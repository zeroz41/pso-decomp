#include "types.h"
#include "pso/player/TObjPlayer.h"


u8 TObjPlayer::clamp_to_max(saddr arg0, u8 level, u8 arg2) {
    u8 var_r3;

    if (TObjPlayer::is_invalid_slot(level) != 0) {
        return level;
    }
    var_r3 = level;
    if (level > arg2) {
        var_r3 = arg2;
    }
    return var_r3;
}
