#include "pso/effect/particle/ParticleParam.h"
#include "types.h"
#include "pso/unk/text_80086B64.h"
#include "pso/system/task/TObject.h"

extern "C" {
void *initialize_with_direction__13TParticleCtrlFPvPvPviiiii(void *self, void *pos, void *dir, void *ent, int a, int b, int c, int d);
}
extern s32 particle_pool_limit;
#pragma push
#pragma opt_propagation off
TParticleCtrl *create_particle_controller_with_rotation(Vec *pos, ParticleAngles *dir, s32 id, s32 a, s32 b) {
    TParticleCtrl *p;
    s32 idx = id;
    if (particle_pool_limit > idx) {
        p = (TParticleCtrl *)TObject::operator new(0x78);
        if (p != 0) {
            p = (TParticleCtrl *)initialize_with_direction__13TParticleCtrlFPvPvPviiiii(p, pos, dir, &particle_global_entry_table[idx], 0, a, b, 0);
        }
        return p;
    }
    if (particle_pool_limit + 0x40 > idx) {
        idx -= 0x200;
        p = (TParticleCtrl *)TObject::operator new(0x78);
        if (p != 0) {
            p = (TParticleCtrl *)initialize_with_direction__13TParticleCtrlFPvPvPviiiii(p, pos, dir, &particle_area_entry_table[idx], 0, a, b, 0);
        }
        return p;
    }
    return 0;
}
#pragma pop
