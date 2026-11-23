#include "pso/effect/particle/ParticleParam.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "types.h"
#include "pso/unk/text_800870BC.h"
#include "pso/system/task/TObject.h"

extern "C" {
// Callers pass the flags as int while the constructor takes u16, so the wrapper
// hands the int on to it unconverted.
void *__ct__13TParticleCtrlFPC3VecP14ParticleAnglesP13ParticleParamllllUs(void *self, const Vec *pos, ParticleAngles *dir, ParticleParam *entry, s32 oneshot,
    s32 delay, s32 lifetime, s32 use_self, s32 flags);

#pragma push
#pragma opt_propagation off
void *spawn_particle_effect_with_rotation(void *pos, void *dir, s32 id, s32 flags) {
    s32 idx = id;
    if (particle_pool_limit > idx) {
        void *p = TObject::operator new(sizeof(TParticleCtrl));
        if (p != 0) {
            p = __ct__13TParticleCtrlFPC3VecP14ParticleAnglesP13ParticleParamllllUs(p, static_cast<const Vec *>(pos), static_cast<ParticleAngles *>(dir),
                &particle_global_entry_table[idx], 0, 0, 0, 0, flags);
        }
        return p;
    }
    if (particle_pool_limit + 0x40 > idx) {
        idx -= 0x200;
        void *p = TObject::operator new(sizeof(TParticleCtrl));
        if (p != 0) {
            p = __ct__13TParticleCtrlFPC3VecP14ParticleAnglesP13ParticleParamllllUs(p, static_cast<const Vec *>(pos), static_cast<ParticleAngles *>(dir),
                &particle_area_entry_table[idx], 0, 0, 0, 0, flags);
        }
        return p;
    }
    return 0;
}
#pragma pop

}
