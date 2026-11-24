#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801C00C4.h"

extern "C" {
u8 TObjPlayer__sub_801C010C(const PlayerTechniqueState *state, s32 technique);
u8 get_effective_technique_level__10TObjPlayerFPvs(PlayerTechniqueState *state, s32 technique);

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

s32 PlayerTechniqueState::check_technique_level(s32 technique, u8 level) {
    if (TObjPlayer::is_invalid_slot(level) != 0) {
        return 1;
    }
    if (level > TObjPlayer__sub_801C010C(this, technique)) {
        return 0;
    }
    return level <= get_effective_technique_level__10TObjPlayerFPvs(this, technique) ? 1 : 0;
}

}
