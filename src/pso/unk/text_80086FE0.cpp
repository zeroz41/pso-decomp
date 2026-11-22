#include "pso/effect/particle/ParticleParam.h"
#include "types.h"
#include "pso/unk/text_80086FE0.h"
#include "pso/system/task/TObject.h"

extern "C" {
void *initialize_with_direction__13TParticleCtrlFPvPvPviiiii(void *, void *, void *, void *, s32, s32, s32, s32);
extern s32 particle_pool_limit;
void *fn_80086FE0(void *arg0, void *arg1, s32 arg2, s32 use_self) {
    void *o;
    if (particle_pool_limit > arg2) {
        o = TObject::operator new(0x78);
        if (o != NULL) {
            o = initialize_with_direction__13TParticleCtrlFPvPvPviiiii(o, arg0, arg1, &particle_global_entry_table[arg2], 0, 0, 0, use_self);
        }
        return o;
    }
    if (particle_pool_limit + 0x40 > arg2) {
        s32 idx = arg2 - 0x200;
        o = TObject::operator new(0x78);
        if (o != NULL) {
            o = initialize_with_direction__13TParticleCtrlFPvPvPviiiii(o, arg0, arg1, &particle_area_entry_table[idx], 0, 0, 0, use_self);
        }
        return o;
    }
    return NULL;
}

}
