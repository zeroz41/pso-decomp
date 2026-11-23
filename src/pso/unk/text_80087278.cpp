#include "pso/effect/particle/ParticleParam.h"
#include "types.h"
#include "pso/unk/text_80087278.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/task/TObject.h"

// Callers pass the flags as int while the constructor takes u16, so the wrapper
// hands the int on to it unconverted.
extern "C" void *__ct__13TParticleCtrlFPC3VecP13ParticleParamllllUs(void *self, const Vec *pos, ParticleParam *entry, s32 oneshot,
    s32 delay, s32 lifetime, s32 use_self, s32 flags);

#pragma push
#pragma opt_propagation off
TParticleCtrl *spawn_particle_effect_with_flags(const Vec *pos, s32 id, s32 flags) {
    s32 idx = id;
    if (particle_pool_limit > idx) {
        void *p = TObject::operator new(sizeof(TParticleCtrl));
        if (p != 0) {
            p = __ct__13TParticleCtrlFPC3VecP13ParticleParamllllUs(p, pos, &particle_global_entry_table[idx], 1, 0, 0, 0, flags);
        }
        return static_cast<TParticleCtrl *>(p);
    }
    if (particle_pool_limit + 0x40 > idx) {
        idx -= 0x200;
        void *p = TObject::operator new(sizeof(TParticleCtrl));
        if (p != 0) {
            p = __ct__13TParticleCtrlFPC3VecP13ParticleParamllllUs(p, pos, &particle_area_entry_table[idx], 1, 0, 0, 0, flags);
        }
        return static_cast<TParticleCtrl *>(p);
    }
    return 0;
}
#pragma pop

TParticleCtrl *spawn_particle_effect(const Vec *pos, s32 id) {
    if (particle_pool_limit > id) {
        return new TParticleCtrl(pos, &particle_global_entry_table[id], 1, 0, 0, 0);
    }
    if (particle_pool_limit + 0x40 > id) {
        s32 idx = id - 0x200;
        return new TParticleCtrl(pos, &particle_area_entry_table[idx], 1, 0, 0, 0);
    }
    return 0;
}

TParticleCtrl *spawn_continuous_particle_effect_with_flags(void *parent, s32 idx, u16 flags) {
    if (particle_pool_limit > idx) {
        return new TParticleCtrl(static_cast<const Vec *>(parent), &particle_global_entry_table[idx], 0, 0, 0, 0, flags);
    } else if (particle_pool_limit + 0x40 > idx) {
        s32 j = idx - 0x200;
        return new TParticleCtrl(static_cast<const Vec *>(parent), &particle_area_entry_table[j], 0, 0, 0, 0, flags);
    } else {
        return 0;
    }
}

