#include "pso/effect/particle/ParticleParam.h"
#include "types.h"
#include "pso/unk/text_80086D50.h"
#include "pso/system/task/TObject.h"

extern "C" {
extern s32 particle_pool_limit;
void *initialize_with_direction__13TParticleCtrlFPvPvPviiiii(void *self, void *pos, void *dir, void *ent, int a, int b, int c, int d);
#pragma push
#pragma opt_propagation off
void *spawn_directional_particle(void *pos, void *dir, s32 id) {
    void *p;
    s32 idx = id;
    if (particle_pool_limit > idx) {
        p = TObject::operator new(0x78);
        if (p != 0) {
            p = initialize_with_direction__13TParticleCtrlFPvPvPviiiii(p, pos, dir, &particle_global_entry_table[idx], 1, 0, 0, 0);
        }
        return p;
    }
    if (particle_pool_limit + 0x40 > idx) {
        idx -= 0x200;
        p = TObject::operator new(0x78);
        if (p != 0) {
            p = initialize_with_direction__13TParticleCtrlFPvPvPviiiii(p, pos, dir, &particle_area_entry_table[idx], 1, 0, 0, 0);
        }
        return p;
    }
    return 0;
}
#pragma pop

}
