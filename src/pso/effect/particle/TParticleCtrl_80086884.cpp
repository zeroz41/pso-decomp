#include "pso/effect/particle/ParticleParam.h"
#include "types.h"
#include "pso/effect/particle/TParticleCtrl_800867E4.h"

#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/task/TObject.h"

extern "C" {
s32 get_bml_model(void *, s32);
ParticleParam *particle_global_entry_table;
ParticleParam *particle_area_entry_table;
u8 *TParticleCtrl__regular_bml_resource;
int TParticleCtrl__texture_list;
extern s32 particle_pool_limit;
void *initialize_with_flags__13TParticleCtrlFPCvP13ParticleParamllllUs(void *, void *, void *, s32, s32, s32, s32, s32);
void *__ct__13TParticleCtrlFv(void *self, void *pos, void *dir, void *ent, int a, int b, int c, int d, int e);

s32 TParticleCtrl::get_particle_model(s32 arg0) {
    if (arg0 < 3) {
        return get_bml_model(TParticleCtrl__regular_bml_resource, arg0);
    }
    return 0;
}

int TParticleCtrl::get_instance() {  return TParticleCtrl__texture_list; }
}
#pragma push
#pragma opt_propagation off
void *create_timed_particle_emitter_with_flags(void *pos, s32 id, s32 a, s32 b, s32 c) {
    void *p;
    s32 idx = id;
    if (particle_pool_limit > idx) {
        p = TObject::operator new(0x78);
        if (p != 0) {
            p = initialize_with_flags__13TParticleCtrlFPCvP13ParticleParamllllUs(p, pos, &particle_global_entry_table[idx], 0, a, b, 0, c);
        }
        return p;
    }
    if (particle_pool_limit + 0x40 > idx) {
        idx -= 0x200;
        p = TObject::operator new(0x78);
        if (p != 0) {
            p = initialize_with_flags__13TParticleCtrlFPCvP13ParticleParamllllUs(p, pos, &particle_area_entry_table[idx], 0, a, b, 0, c);
        }
        return p;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma opt_propagation off

void *create_timed_particle_emitter(void *owner, s32 id, s32 b, s32 c) {
    void *p;
    s32 idx = id;
    if (particle_pool_limit > idx) {
        p = TObject::operator new(0x78);
        if (p != 0) {
            p = ((TParticleCtrl *)p)->initialize((const void *)owner, &particle_global_entry_table[idx], 0, (s32)b, (s32)c, 0);
        }
        return p;
    }
    if (particle_pool_limit + 0x40 > idx) {
        idx -= 0x200;
        p = TObject::operator new(0x78);
        if (p != 0) {
            p = ((TParticleCtrl *)p)->initialize((const void *)owner, &particle_area_entry_table[idx], 0, (s32)b, (s32)c, 0);
        }
        return p;
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
