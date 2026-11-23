#include "pso/system/BmlAccessors.h"
#include "pso/effect/particle/ParticleParam.h"
#include "types.h"

#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/task/TObject.h"

extern "C" {

ParticleParam *particle_global_entry_table;
ParticleParam *particle_area_entry_table;
BmlResource *TParticleCtrl__regular_bml_resource;
GinjaTextureList *TParticleCtrl__texture_list;

NJS_OBJECT *TParticleCtrl::get_particle_model(s32 model) {
    if (model < 3) {
        return get_bml_model(TParticleCtrl__regular_bml_resource, model);
    }
    return 0;
}

GinjaTextureList *TParticleCtrl::get_instance() {  return TParticleCtrl__texture_list; }

// Callers pass the flags as int while the constructor takes u16, so the wrapper
// hands the int on to it unconverted.
void *__ct__13TParticleCtrlFPC3VecP14ParticleAnglesP13ParticleParamllllUs(void *self, const Vec *pos, ParticleAngles *dir, ParticleParam *entry, s32 oneshot,
    s32 delay, s32 lifetime, s32 use_self, s32 flags);
}
#pragma push
#pragma opt_propagation off
TParticleCtrl *create_timed_particle_emitter_with_flags(void *pos, s32 id, s32 delay, s32 duration, u16 flags) {
    s32 idx = id;
    if (particle_pool_limit > idx) {
        return new TParticleCtrl(static_cast<const Vec *>(pos), &particle_global_entry_table[idx], 0, delay, duration, 0, flags);
    }
    if (particle_pool_limit + 0x40 > idx) {
        idx -= 0x200;
        return new TParticleCtrl(static_cast<const Vec *>(pos), &particle_area_entry_table[idx], 0, delay, duration, 0, flags);
    }
    return 0;
}
#pragma pop

#pragma push
#pragma opt_propagation off

TParticleCtrl *create_timed_particle_emitter(const void *pos, s32 id, s32 delay, s32 duration) {
    s32 idx = id;
    if (particle_pool_limit > idx) {
        return new TParticleCtrl(static_cast<const Vec *>(pos), &particle_global_entry_table[idx], 0, delay, duration, 0);
    }
    if (particle_pool_limit + 0x40 > idx) {
        idx -= 0x200;
        return new TParticleCtrl(static_cast<const Vec *>(pos), &particle_area_entry_table[idx], 0, delay, duration, 0);
    }
    return 0;
}
#pragma pop

#pragma push
#pragma opt_propagation off
void *create_timed_particle_emitter_with_angles(void *pos, void *dir, s32 id, s32 a, s32 b, s32 flags) {
    s32 idx = id;
    if (particle_pool_limit > idx) {
        void *p = TObject::operator new(sizeof(TParticleCtrl));
        if (p != 0) {
            p = __ct__13TParticleCtrlFPC3VecP14ParticleAnglesP13ParticleParamllllUs(p, static_cast<const Vec *>(pos), static_cast<ParticleAngles *>(dir),
                &particle_global_entry_table[idx], 0, a, b, 0, flags);
        }
        return p;
    }
    if (particle_pool_limit + 0x40 > idx) {
        idx -= 0x200;
        void *p = TObject::operator new(sizeof(TParticleCtrl));
        if (p != 0) {
            p = __ct__13TParticleCtrlFPC3VecP14ParticleAnglesP13ParticleParamllllUs(p, static_cast<const Vec *>(pos), static_cast<ParticleAngles *>(dir),
                &particle_area_entry_table[idx], 0, a, b, 0, flags);
        }
        return p;
    }
    return 0;
}
#pragma pop
