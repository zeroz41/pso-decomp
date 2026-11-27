#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/technique/TTecThunderCharge.h"
#include "pso/audio/SoundRequests.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/vector.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"

// The particles the lightning technique charge spawns every 10 frames.
u32 lightning_charge_particle_ids[3] = {0xA0, 0xA1, 0xA3};

void TTecThunderCharge::run_task() {
    ++m_age;
    if (m_age % 10 == 0) {
        for (int i = 0; i < 3; ++i) spawn_particle_effect(&m_position, lightning_charge_particle_ids[i]);
    }
    if (!m_actor->is_technique_charging()) queue_destruction();
    else if (m_age >= 180) queue_destruction();
}

TTecThunderCharge::~TTecThunderCharge() {
    stop_sound_request(m_sound_handle);
}

TTecThunderCharge::TTecThunderCharge(TObjPlayer *actor, TObject *parent) : TObject(parent) {
    m_actor = actor;
    VecCopy(&m_position, &m_actor->body_center);
    m_age = 0;
    m_sound_handle = play_sound_effect(0x4002B51E, &m_position, 0, 0);
}
