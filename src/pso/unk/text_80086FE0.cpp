#include "pso/effect/particle/ParticleParam.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "types.h"
#include "pso/unk/text_80086FE0.h"
#include "pso/system/task/TObject.h"

extern "C" {
void *fn_80086FE0(void *arg0, void *arg1, s32 arg2, s32 use_self) {
    if (particle_pool_limit > arg2) {
        return new TParticleCtrl(static_cast<const Vec *>(arg0), static_cast<ParticleAngles *>(arg1), &particle_global_entry_table[arg2], 0, 0, 0, use_self);
    }
    if (particle_pool_limit + 0x40 > arg2) {
        s32 idx = arg2 - 0x200;
        return new TParticleCtrl(static_cast<const Vec *>(arg0), static_cast<ParticleAngles *>(arg1), &particle_area_entry_table[idx], 0, 0, 0, use_self);
    }
    return NULL;
}

}
