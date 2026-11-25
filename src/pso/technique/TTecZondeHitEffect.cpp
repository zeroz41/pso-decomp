#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/technique/TTecZondeHitEffect.h"
#include "pso/effect/particle/ParticleFactory.h"

void TTecZondeHitEffect::run_task() {
    m_timer = m_timer + 1;
    if (m_timer >= 70) {
        queue_destruction();
    }
}

TTecZondeHitEffect::~TTecZondeHitEffect() {
}

TTecZondeHitEffect::TTecZondeHitEffect(Vec *hit_pos, Vec *source_pos, TObject *parent, s32 effect_id) : TObject(parent) {
    VecCopy(&m_hit_pos, hit_pos);
    VecCopy(&m_source_pos, source_pos);
    m_effect_id = effect_id;
    m_timer = 0;
    spawn_particle_effect_with_flags(&m_hit_pos, m_effect_id, 0x40);
}
