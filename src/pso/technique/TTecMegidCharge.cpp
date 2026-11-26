#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/TParticleCtrl.h"
#include "types.h"
#include "pso/technique/TechniqueBoost.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/object/TTecMegidCharge.h"
#include "pso/audio/SoundRequests.h"
#include "pso/system/vector.h"
#include "pso/system/SoundEffect.h"
#include "pso/technique/TTecDeband.h"
#include "pso/system/SoundEffect.h"

void TechniqueBoostTable::set(s32 index, TechniqueBoost *boost) {
    if (index < 6) {
        boosts[index].copy_from(boost);
    }
}

void TechniqueBoost::copy_from(TechniqueBoost *src) {
    technique = src->technique;
    flags = src->flags;
    amount = src->amount;
}

void TechniqueBoostTable::clear() {
    int i;
    for (i = 0; i < 6; i++) {
        boosts[i].clear();
    }
}

u32 dark_technique_charge_effect_ids[3] = {0x1E7, 0x1E8, 0x1EF};
TechniqueBoostTable::TechniqueBoostTable() {
    clear();
}

void TTecMegidCharge::run_task() {
    ++m_age;
    if(m_age%10==0) {
        for(int i=0;i<3;++i)spawn_particle_effect(&m_position,dark_technique_charge_effect_ids[i]);
    }
    if(!m_actor->check_flag_0x80())queue_destruction();
    else if(m_age>=180)queue_destruction();
}

TTecMegidCharge::~TTecMegidCharge() {
    stop_sound_request(m_sound_handle);
}

TTecMegidCharge::TTecMegidCharge(TObjPlayer *actor, TObject *parent) : TObject(parent) {
    m_actor = actor;
    VecCopy(&m_position, &m_actor->body_center);
    m_age = 0;
    m_sound_handle = play_sound_effect(0x4002BB1F, &m_position, 0, 0);
}

void TTecDeband::play_state_sound() {
    s32 r;
    switch (band) {
    case 0:
    case 1:
        r = play_sound_effect(0x4002AA16, &position, 0, 0);
        if (r >= 0) {
            set_sound_pitch_request(r, 0x100, 0);
        }
        break;
    case 2:
    case 3:
        play_sound_effect(0x4002AA16, &position, 0, 0);
        break;
    case 4:
    case 5:
        r = play_sound_effect(0x4002AA16, &position, 0, 0);
        if (r >= 0) {
            set_sound_pitch_request(r, -0x100, 0);
        }
        break;
    }
}
