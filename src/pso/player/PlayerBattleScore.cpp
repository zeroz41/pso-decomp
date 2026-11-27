#include "types.h"
#include "pso/player/PlayerBattleScore.h"
#include "pso/player/TObjPlayer.h"

void PlayerBattleScore::reset() {
    TObjPlayer::reset_particle_ctrl(&timer);
    kills.reset();
    deaths.reset();
    damage_taken.reset();
    damage_given.reset();
    meseta.reset();
}
