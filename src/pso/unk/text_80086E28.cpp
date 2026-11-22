#include "pso/effect/particle/ParticleParam.h"
#include "types.h"
#include "pso/unk/text_80086E28.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/ui/frontend/TAdLoadQuestPrtTxtGC.h"
#include "pso/system/task/TObject.h"


extern "C" {
extern s32 particle_pool_limit;
void *__ct__13TParticleCtrlFv(void *, void *, void *, void *, s32, s32, s32, s32, u16);
}
void *TAdLoadQuestPrtTxtGC::create_particle(void *position, s32 arg1, s32 use_self) {
    void *o;
    if (particle_pool_limit > arg1) {
        o = TObject::operator new(0x78);
        if (o != NULL) {
            o = ((TParticleCtrl *)o)->initialize((const void *)position, &particle_global_entry_table[arg1], 0, 0, 0, (s32)use_self);
        }
        return o;
    }
    if (particle_pool_limit + 0x40 > arg1) {
        s32 idx = arg1 - 0x200;
        o = TObject::operator new(0x78);
        if (o != NULL) {
            o = ((TParticleCtrl *)o)->initialize((const void *)position, &particle_area_entry_table[idx], 0, 0, 0, (s32)use_self);
        }
        return o;
    }
    return NULL;
}
void *create_particle_controller_with_angles(void *joint_positions, void *ang, s32 arg2, s32 use_self, u16 flags) {
    void *o;
    if (particle_pool_limit > arg2) {
        o = TObject::operator new(0x78);
        if (o != NULL) {
            o = __ct__13TParticleCtrlFv(o, joint_positions, ang, &particle_global_entry_table[arg2], 0, 0, 0, use_self, flags);
        }
        return o;
    }
    if (particle_pool_limit + 0x40 > arg2) {
        s32 idx = arg2 - 0x200;
        o = TObject::operator new(0x78);
        if (o != NULL) {
            o = __ct__13TParticleCtrlFv(o, joint_positions, ang, &particle_area_entry_table[idx], 0, 0, 0, use_self, flags);
        }
        return o;
    }
    return NULL;
}
