#include "types.h"
#include "pso/player/TObjPlayer_800D8A2C.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"

extern s32 player_particle_effect_enabled;

void TObjPlayer::toggle_particle_effect() {
    if ((s32) player_particle_effect_enabled != 0) {
        TParticleCtrl::end_effect_render();
        return;
    }
    TParticleCtrl::begin_effect_render();
}

void TObjPlayer__sub_800D8A60(void) { player_particle_effect_enabled = 0; }

void TObjPlayer__sub_800D8A6C(void) { player_particle_effect_enabled = 1; }
