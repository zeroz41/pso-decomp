#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/object/TUnk_804CC794.h"
#include "pso/unk/TLobby_80226070.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/vector.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"

// The particles the fire technique charge spawns every 10 frames.
u32 fire_technique_charge_effect_ids[3] = {0x3C, 0x3D, 0x3E};

void TUnk_804CC794::run_task() {
    ++m_age;
    if (m_age % 10 == 0) {
        for (int i = 0; i < 3; ++i) spawn_particle_effect(&m_position, fire_technique_charge_effect_ids[i]);
    }
    if (!m_actor->check_flag_0x80()) queue_destruction();
    else if (m_age >= 180) queue_destruction();
}

TUnk_804CC794::~TUnk_804CC794() {
    stop_sound_request(m_sound_handle);
}

TUnk_804CC794::TUnk_804CC794(TObjPlayer *actor, TObject *parent) : TObject(parent) {
    m_actor = actor;
    VecCopy(&m_position, &m_actor->body_center);
    m_age = 0;
    m_sound_handle = play_sound_effect(0x4002B21C, &m_position, 0, 0);
}
