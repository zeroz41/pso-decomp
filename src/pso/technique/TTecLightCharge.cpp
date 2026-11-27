#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/technique/TTecLightCharge.h"
#include "pso/audio/SoundRequests.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/vector.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/task/TObject.h"

// The particles the recovery technique charge spawns every 10 frames.
u32 recovery_technique_charge_particle_ids[2] = {0xB7, 0xB8};

void TTecLightCharge::run_task() {
    ++age;
    if (age % 10 == 0) {
        for (int i = 0; i < 2; ++i) spawn_particle_effect(&position, recovery_technique_charge_particle_ids[i]);
    }
    if (!actor->is_technique_charging()) queue_destruction();
    else if (age >= 180) queue_destruction();
}

TTecLightCharge::~TTecLightCharge() {
    stop_sound_request(sound_handle);
}

TTecLightCharge::TTecLightCharge(TObjPlayer *actor, TObject *parent) : TObject(parent) {
    this->actor = actor;
    VecCopy(&this->position, &this->actor->body_center);
    this->age = 0;
    this->sound_handle = play_sound_effect(0x4002BC20, &this->position, 0, 0);
}
