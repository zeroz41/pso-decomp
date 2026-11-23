#include "pso/effect/particle/ParticleParam.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "types.h"
#include "pso/unk/text_800871A0.h"
#include "pso/system/task/TObject.h"

extern "C" {
#pragma push
#pragma opt_propagation off
void *spawn_continuous_particle_with_direction(void *pos, void *dir, s32 id) {
    s32 idx = id;
    if (particle_pool_limit > idx) {
        return new TParticleCtrl(static_cast<const Vec *>(pos), static_cast<ParticleAngles *>(dir), &particle_global_entry_table[idx], 0x0, 0, 0, 0);
    }
    if (particle_pool_limit + 0x40 > idx) {
        idx -= 0x200;
        return new TParticleCtrl(static_cast<const Vec *>(pos), static_cast<ParticleAngles *>(dir), &particle_area_entry_table[idx], 0x0, 0, 0, 0);
    }
    return 0;
}
#pragma pop

}
