#include "pso/system/SoundEffect.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/technique/TTecSupportCharge.h"

#include "pso/system/vector.h"

#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/audio/SoundRequests.h"
extern "C" {
__declspec(section ".data") u32 support_charge_effect_ids[2] = {0x1F4, 0x1F5};
}

void TTecSupportCharge::run_task() {
    ++age;
    if(age%10==0) {
        for(int i=0;i<2;++i)spawn_particle_effect(&position,support_charge_effect_ids[i]);
    }
    if(!actor->is_technique_charging())queue_destruction();
    else if(age>=180)queue_destruction();
}

TTecSupportCharge::~TTecSupportCharge() {
    stop_sound_request(sound);
}

TTecSupportCharge::TTecSupportCharge(TObjPlayer *actor, TObject *parent) : TObject(parent) {
    this->actor = actor;
    VecCopy(&position, &this->actor->body_center);
    age = 0;
    sound = play_sound_effect(0x4002B71B, &position, 0, 0);
}
