#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/unk/TUnk_804CCD0C.h"
#include "pso/unk/TLobby_80226070.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/vector.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"

// The particles the lightning technique charge spawns every 10 frames.
u32 lightning_charge_particle_ids[3] = {0xA0, 0xA1, 0xA3};

void TUnk_804CCD0C::run_task() {
    ++m_age;
    if (m_age % 10 == 0) {
        for (int i = 0; i < 3; ++i) spawn_particle_effect(&m_position, lightning_charge_particle_ids[i]);
    }
    if (!m_actor->check_flag_0x80()) queue_destruction();
    else if (m_age >= 180) queue_destruction();
}

TUnk_804CCD0C::~TUnk_804CCD0C() {
    stop_sound_request(m_sound_handle);
}

TUnk_804CCD0C::TUnk_804CCD0C(s32 arg1, saddr arg2) : TObject((TObject *)((void *)arg2)) {
    *(s32 *)((s8 *)this + 0x1C) = arg1;
    VecCopy((Vec *)(((u8 *)this) + 0x20), (const Vec *)(*(saddr *)((s8 *)this + 0x1C) + 0x2FC));
    this->m_age = 0;
    *(s32 *)((s8 *)this + 0x30) = play_sound_effect(0x4002B51E, ((u8 *)this) + 0x20, 0, 0);
}
