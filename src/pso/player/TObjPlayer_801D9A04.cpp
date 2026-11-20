#include "types.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

u8 TObjPlayer__sub_801C010C(s32, s32);
s32 is_invalid_slot__10TObjPlayerFUc(u8);
u8 get_effective_technique_level__10TObjPlayerFPvs(s32, s32);

u8 TObjPlayer::is_valid_technique_id(s16 arg0) {
    s32 var_r4;

    var_r4 = 0;
    if ((arg0 >= 0) && (arg0 < 0x13)) {
        var_r4 = 1;
    }
    return (u8)var_r4;
}

u8 TObjPlayer::is_valid_technique_slot(u8 arg0) {
    return (u8) (arg0 <= 0xFU);
}

s32 TObjPlayer::check_technique_level(saddr arg0, s32 arg1, u8 arg2) {
    if (is_invalid_slot__10TObjPlayerFUc(arg2) != 0) {
        return 1;
    }
    if (arg2 > TObjPlayer__sub_801C010C(arg0, arg1)) {
        return 0;
    }
    return arg2 <= get_effective_technique_level__10TObjPlayerFPvs(arg0, arg1) ? 1 : 0;
}

}
