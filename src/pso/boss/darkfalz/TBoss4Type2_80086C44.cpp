#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/boss/darkfalz/TBoss4Type2_80086C44.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/effect/particle/TParticleCtrl.h"

struct Ent_800868C4 { u8 data[0x98]; };

extern "C" {
void *__ct__13TParticleCtrlFv(void *self, void *pos, void *dir, void *ent, int a, int b, int c, int d, int e);
void *__nw__7TObjectFUl(int);
extern s32 particle_pool_limit;
extern Ent_800868C4 *particle_global_entry_table;
extern Ent_800868C4 *particle_area_entry_table;

}

void TParticleCtrl::release(void *emitter) {
    if (emitter != NULL) {
        ((TParticleCtrl *)emitter)->queue_destruction();
    }
}
#pragma push
#pragma opt_propagation off
void *create_oneshot_particle_emitter(void *pos, void *dir, s32 id, s32 flags) {
    void *p;
    s32 idx = id;
    if (particle_pool_limit > idx) {
        p = __nw__7TObjectFUl(0x78);
        if (p != 0) {
            p = __ct__13TParticleCtrlFv(p, pos, dir, &particle_global_entry_table[idx], 1, 0, 0, 0, flags);
        }
        return p;
    }
    if (particle_pool_limit + 0x40 > idx) {
        idx -= 0x200;
        p = __nw__7TObjectFUl(0x78);
        if (p != 0) {
            p = __ct__13TParticleCtrlFv(p, pos, dir, &particle_area_entry_table[idx], 1, 0, 0, 0, flags);
        }
        return p;
    }
    return 0;
}
#pragma pop
