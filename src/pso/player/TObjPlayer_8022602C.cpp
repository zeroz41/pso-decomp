#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/dd/TObjEneDD.h"

extern "C" {

s32 update_technique_slot__10TTecRaFoieFl(s32, s32, s32);

extern s32 last_sound_effect_slot;

void TObjPlayer::play_effect_if_v2(s32 arg0) {
    if (TObjEneDD::check_v2_mode() != 0) {
        update_technique_slot__10TTecRaFoieFl(last_sound_effect_slot, arg0, 0);
    }
}

}
