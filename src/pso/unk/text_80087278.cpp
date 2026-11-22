#include "pso/effect/particle/ParticleParam.h"
#include "types.h"
#include "pso/unk/text_80087278.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/task/TObject.h"


extern "C" {
extern s32 particle_pool_limit;

#pragma push
#pragma opt_propagation off
TParticleCtrl *spawn_particle_effect_with_flags(const Vec *pos, s32 id, s32 flags) {
    void *p;
    s32 idx = id;
    if (particle_pool_limit > idx) {
        p = TObject::operator new((u32)(0x78));
        if (p != 0) {
            p = initialize_flagged_particle(p, pos, &particle_global_entry_table[idx], 1, 0, 0, 0, flags);
        }
        return static_cast<TParticleCtrl *>(p);
    }
    if (particle_pool_limit + 0x40 > idx) {
        idx -= 0x200;
        p = TObject::operator new((u32)(0x78));
        if (p != 0) {
            p = initialize_flagged_particle(p, pos, &particle_area_entry_table[idx], 1, 0, 0, 0, flags);
        }
        return static_cast<TParticleCtrl *>(p);
    }
    return 0;
}
#pragma pop

TParticleCtrl *spawn_particle_effect(const Vec *pos, s32 id) {
    void *p;
    if (particle_pool_limit > id) {
        p = TObject::operator new((u32)(0x78));
        if (p != 0) {
            p = ((TParticleCtrl *)p)->initialize((const void *)pos, &particle_global_entry_table[id], 1, 0, 0, 0);
        }
        return static_cast<TParticleCtrl *>(p);
    }
    if (particle_pool_limit + 0x40 > id) {
        s32 idx = id - 0x200;
        p = TObject::operator new((u32)(0x78));
        if (p != 0) {
            p = ((TParticleCtrl *)p)->initialize((const void *)pos, &particle_area_entry_table[idx], 1, 0, 0, 0);
        }
        return static_cast<TParticleCtrl *>(p);
    }
    return 0;
}

TParticleCtrl *spawn_continuous_particle_effect_with_flags(void *parent, s32 idx, s32 flags) {
    void *p;
    if (particle_pool_limit > idx) {
        p = TObject::operator new(0x78);
        if (p != 0) {
            p = initialize_flagged_particle(p, parent, &particle_global_entry_table[idx], 0, 0, 0, 0, flags);
        }
        return (TParticleCtrl *)p;
    } else if (particle_pool_limit + 0x40 > idx) {
        s32 j = idx - 0x200;
        p = TObject::operator new(0x78);
        if (p != 0) {
            p = initialize_flagged_particle(p, parent, &particle_area_entry_table[j], 0, 0, 0, 0, flags);
        }
        return (TParticleCtrl *)p;
    } else {
        return 0;
    }
}

}
