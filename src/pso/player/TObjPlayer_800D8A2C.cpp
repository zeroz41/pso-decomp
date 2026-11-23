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

void disable_player_particle_effect(void) { player_particle_effect_enabled = 0; }

void enable_player_particle_effect(void) { player_particle_effect_enabled = 1; }
