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

TUnk_804CC794::TUnk_804CC794(s32 arg1, saddr arg2) : TObject((TObject *)((void *)arg2)) {
    *(s32 *)((s8 *)this + 0x1C) = arg1;
    VecCopy((Vec *)(((u8 *)this) + 0x20), (const Vec *)(*(saddr *)((s8 *)this + 0x1C) + 0x2FC));
    this->m_age = 0;
    *(s32 *)((s8 *)this + 0x30) = play_sound_effect(0x4002B21C, ((u8 *)this) + 0x20, 0, 0);
}
