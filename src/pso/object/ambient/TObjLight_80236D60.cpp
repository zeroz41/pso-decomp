#include "pso/system/SoundEffect.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/object/TUnk_804CCAC8.h"

#include "pso/system/vector.h"

#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
extern "C" {
__declspec(section ".data") u32 TObjLight__support_charge_effect_ids[2] = {0x1F4, 0x1F5};
void stop_sound_request(s32 idx);
}

void TUnk_804CCAC8::run_task() {
    ++age;
    if(age%10==0) {
        for(int i=0;i<2;++i)spawn_particle_effect(&position,TObjLight__support_charge_effect_ids[i]);
    }
    if(!actor->check_flag_0x80())queue_destruction();
    else if(age>=180)queue_destruction();
}

TUnk_804CCAC8::~TUnk_804CCAC8() {
    stop_sound_request(sound);
}

TUnk_804CCAC8::TUnk_804CCAC8(TObjPlayer *actor, TObject *parent) : TObject(parent) {
    this->actor = actor;
    VecCopy(&position, &this->actor->body_center);
    age = 0;
    sound = play_sound_effect(0x4002B71B, &position, 0, 0);
}
