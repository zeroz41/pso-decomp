#include "pso/effect/particle/ParticleParam.h"
#include "types.h"
#include "pso/unk/text_80086E28.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/ui/frontend/TAdLoadQuestPrtTxtGC.h"
#include "pso/system/task/TObject.h"


extern "C" {
}
void *TAdLoadQuestPrtTxtGC::create_particle(void *position, s32 arg1, s32 use_self) {
    if (particle_pool_limit > arg1) {
        return new TParticleCtrl(static_cast<const Vec *>(position), &particle_global_entry_table[arg1], 0, 0, 0, use_self);
    }
    if (particle_pool_limit + 0x40 > arg1) {
        s32 idx = arg1 - 0x200;
        return new TParticleCtrl(static_cast<const Vec *>(position), &particle_area_entry_table[idx], 0, 0, 0, use_self);
    }
    return NULL;
}
void *create_particle_controller_with_angles(void *joint_positions, void *ang, s32 arg2, s32 use_self, u16 flags) {
    if (particle_pool_limit > arg2) {
        return new TParticleCtrl(static_cast<const Vec *>(joint_positions), static_cast<ParticleAngles *>(ang), &particle_global_entry_table[arg2], 0, 0, 0, use_self, flags);
    }
    if (particle_pool_limit + 0x40 > arg2) {
        s32 idx = arg2 - 0x200;
        return new TParticleCtrl(static_cast<const Vec *>(joint_positions), static_cast<ParticleAngles *>(ang), &particle_area_entry_table[idx], 0, 0, 0, use_self, flags);
    }
    return NULL;
}
