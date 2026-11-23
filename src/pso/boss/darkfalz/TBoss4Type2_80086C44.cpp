#include "pso/effect/particle/ParticleParam.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/boss/darkfalz/TBoss4Type2_80086C44.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/task/TObject.h"


extern "C" {

}

void TParticleCtrl::release(void *emitter) {
    if (emitter != NULL) {
        ((TParticleCtrl *)emitter)->queue_destruction();
    }
}
#pragma push
#pragma opt_propagation off
void *create_oneshot_particle_emitter(void *pos, void *dir, s32 id, u16 flags) {
    s32 idx = id;
    if (particle_pool_limit > idx) {
        return new TParticleCtrl(static_cast<const Vec *>(pos), static_cast<ParticleAngles *>(dir), &particle_global_entry_table[idx], 1, 0, 0, 0, flags);
    }
    if (particle_pool_limit + 0x40 > idx) {
        idx -= 0x200;
        return new TParticleCtrl(static_cast<const Vec *>(pos), static_cast<ParticleAngles *>(dir), &particle_area_entry_table[idx], 1, 0, 0, 0, flags);
    }
    return 0;
}
#pragma pop
