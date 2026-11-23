#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/object/TUnk_804CC948.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"
#include "pso/unk/TLobby_80226070.h"

__declspec(section ".data") u32 ice_technique_charge_particle_ids[2] = {0xBB, 0xBC};

void TUnk_804CC948::run_task() {
    ++m_age;
    if (m_age % 10 == 0) {
        for (int i = 0; i < 2; ++i) {
            spawn_particle_effect(&m_position, ice_technique_charge_particle_ids[i]);
        }
    }
    if (!m_actor->check_flag_0x80()) {
        queue_destruction();
    } else if (m_age >= 180) {
        queue_destruction();
    }
}

TUnk_804CC948::~TUnk_804CC948() {
    stop_sound_request(m_sound_handle);
}

TUnk_804CC948::TUnk_804CC948(TObjPlayer *actor, TObject *parent) : TObject(parent) {
    m_actor = actor;
    VecCopy(&m_position, &m_actor->body_center);
    m_age = 0;
    m_sound_handle = play_sound_effect(0x4002B21D, &m_position, 0, 0);
}
