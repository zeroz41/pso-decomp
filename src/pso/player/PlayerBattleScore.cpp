#include "types.h"
#include "pso/player/PlayerBattleScore.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/memory.h"
#include "pso/effect/particle/TParticleCtrl.h"

void PlayerBattleScore::reset() {
    TObjPlayer::reset_particle_ctrl(&timer);
    kills.reset();
    deaths.reset();
    damage_taken.reset();
    damage_given.reset();
    meseta.reset();
}

void TObjPlayer::reset_particle_ctrl(s32 *ctrl) {
    *ctrl = 0;
    ((TParticleCtrl *)ctrl)->destroy_particle();
}

PlayerBattleScore::~PlayerBattleScore() {
    ((TParticleCtrl *)&timer)->destroy_particle();
}

PlayerBattleScore::PlayerBattleScore() {
    pad_4 = 0;
    TObjPlayer::reset_particle_ctrl(&timer);
}
