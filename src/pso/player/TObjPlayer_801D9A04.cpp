#include "types.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

u8 TObjPlayer__sub_801C010C(s32, s32);
u8 get_effective_technique_level__10TObjPlayerFPvs(s32, s32);

s32 TObjPlayer::is_valid_technique_id(s16 arg0) {
    s32 var_r4;

    var_r4 = 0;
    if ((arg0 >= 0) && (arg0 < 0x13)) {
        var_r4 = 1;
    }
    return (u8)((u8)var_r4);
}

s32 TObjPlayer::is_valid_technique_slot(u8 arg0) {
    return (u8)((u8) (arg0 <= 0xFU));
}

s32 TObjPlayer::check_technique_level(saddr arg0, s32 idx, u8 level) {
    if (TObjPlayer::is_invalid_slot(level) != 0) {
        return 1;
    }
    if (level > TObjPlayer__sub_801C010C(arg0, idx)) {
        return 0;
    }
    return level <= get_effective_technique_level__10TObjPlayerFPvs(arg0, idx) ? 1 : 0;
}

}
