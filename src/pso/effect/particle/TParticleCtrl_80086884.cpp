#include "pso/system/BmlAccessors.h"
#include "pso/effect/particle/ParticleParam.h"
#include "types.h"
#include "pso/effect/particle/TParticleCtrl_800867E4.h"

#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/task/TObject.h"

extern "C" {

ParticleParam *particle_global_entry_table;
ParticleParam *particle_area_entry_table;
u8 *TParticleCtrl__regular_bml_resource;
GinjaTextureList *TParticleCtrl__texture_list;
extern s32 particle_pool_limit;
void *__ct__13TParticleCtrlFv(void *self, void *pos, void *dir, void *ent, int a, int b, int c, int d, int e);

NJS_OBJECT *TParticleCtrl::get_particle_model(s32 arg0) {
    if (arg0 < 3) {
        return get_bml_model((BmlResource *)TParticleCtrl__regular_bml_resource, arg0);
    }
    return 0;
}

GinjaTextureList *TParticleCtrl::get_instance() {  return TParticleCtrl__texture_list; }
}
#pragma push
#pragma opt_propagation off
TParticleCtrl *create_timed_particle_emitter_with_flags(void *pos, s32 id, s32 delay, s32 duration, s32 flags) {
    TParticleCtrl *particle;
    s32 idx = id;
    if (particle_pool_limit > idx) {
        particle = static_cast<TParticleCtrl *>(TObject::operator new(0x78));
        if (particle != 0) {
            particle = initialize_flagged_particle(particle, pos, &particle_global_entry_table[idx], 0, delay, duration, 0, flags);
        }
        return particle;
    }
    if (particle_pool_limit + 0x40 > idx) {
        idx -= 0x200;
        particle = static_cast<TParticleCtrl *>(TObject::operator new(0x78));
        if (particle != 0) {
            particle = initialize_flagged_particle(particle, pos, &particle_area_entry_table[idx], 0, delay, duration, 0, flags);
        }
        return particle;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma opt_propagation off

TParticleCtrl *create_timed_particle_emitter(const void *pos, s32 id, s32 delay, s32 duration) {
    TParticleCtrl *particle;
    s32 idx = id;
    if (particle_pool_limit > idx) {
        particle = static_cast<TParticleCtrl *>(TObject::operator new(0x78));
        if (particle != 0) {
            particle = particle->initialize(pos, &particle_global_entry_table[idx], 0, delay, duration, 0);
        }
        return particle;
    }
    if (particle_pool_limit + 0x40 > idx) {
        idx -= 0x200;
        particle = static_cast<TParticleCtrl *>(TObject::operator new(0x78));
        if (particle != 0) {
            particle = particle->initialize(pos, &particle_area_entry_table[idx], 0, delay, duration, 0);
        }
        return particle;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma opt_propagation off
void *create_timed_particle_emitter_with_angles(void *pos, void *dir, s32 id, s32 a, s32 b, s32 flags) {
    void *p;
    s32 idx = id;
    if (particle_pool_limit > idx) {
        p = TObject::operator new(0x78);
        if (p != 0) {
            p = __ct__13TParticleCtrlFv(p, pos, dir, &particle_global_entry_table[idx], 0, a, b, 0, flags);
        }
        return p;
    }
    if (particle_pool_limit + 0x40 > idx) {
        idx -= 0x200;
        p = TObject::operator new(0x78);
        if (p != 0) {
            p = __ct__13TParticleCtrlFv(p, pos, dir, &particle_area_entry_table[idx], 0, a, b, 0, flags);
        }
        return p;
    }
    return 0;
}
#pragma pop
