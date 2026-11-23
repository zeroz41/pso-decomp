#include "pso/effect/particle/ParticleParam.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "types.h"
#include "pso/unk/text_80086B64.h"
#include "pso/system/task/TObject.h"

extern "C" {
}
#pragma push
#pragma opt_propagation off
TParticleCtrl *create_particle_controller_with_rotation(Vec *pos, ParticleAngles *dir, s32 id, s32 a, s32 b) {
    s32 idx = id;
    if (particle_pool_limit > idx) {
        return new TParticleCtrl(pos, dir, &particle_global_entry_table[idx], 0, a, b, 0);
    }
    if (particle_pool_limit + 0x40 > idx) {
        idx -= 0x200;
        return new TParticleCtrl(pos, dir, &particle_area_entry_table[idx], 0, a, b, 0);
    }
    return 0;
}
#pragma pop
