#include "pso/effect/particle/ParticleParam.h"
#include "types.h"
#include "pso/unk/text_800870BC.h"
#include "pso/system/task/TObject.h"

extern "C" {
extern s32 particle_pool_limit;
void *__ct__13TParticleCtrlFv(void *self, void *pos, void *dir, void *ent, int a, int b, int c, int d, int e);
#pragma push
#pragma opt_propagation off
void *spawn_particle_effect_with_rotation(void *pos, void *dir, s32 id, int e) {
    void *p;
    s32 idx = id;
    if (particle_pool_limit > idx) {
        p = TObject::operator new(0x78);
        if (p != 0) {
            p = __ct__13TParticleCtrlFv(p, pos, dir, &particle_global_entry_table[idx], 0, 0, 0, 0, e);
        }
        return p;
    }
    if (particle_pool_limit + 0x40 > idx) {
        idx -= 0x200;
        p = TObject::operator new(0x78);
        if (p != 0) {
            p = __ct__13TParticleCtrlFv(p, pos, dir, &particle_area_entry_table[idx], 0, 0, 0, 0, e);
        }
        return p;
    }
    return 0;
}
#pragma pop

}
