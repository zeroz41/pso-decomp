#include "pso/boss/olgaflow/TBoss6CrushPtcl.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"

#include "types.h"
#include "pso/effect/particle/TParticleCtrl.h"

struct Vec_80359EF0 { s32 x, y, z; };

extern "C" {
void *create_particle_emitter(void *pos, s32 id);
void *__ct__7TObjectFP7TObject(void *, void *);
extern s32 __vt__15TBoss6CrushPtcl[];
extern s32 TBoss6CrushPtcl__name;
u8 *TBoss6CrushPtcl__ct(u8 *arg0, void *arg1, Vec_80359EF0 *arg2);
}

void TBoss6CrushPtcl::run_task() {
    m_1C++;
    if (m_1C >= 6) {
        if (m_20 != 0) {
            TParticleCtrl::release((void *)m_20);
            m_20 = 0;
        }
        if (m_24 != 0) {
            TParticleCtrl::release((void *)m_24);
            m_24 = 0;
        }
        queue_destruction__7TObjectFv(this);
    }
}

TBoss6CrushPtcl::~TBoss6CrushPtcl() {}

extern "C" {

void *__nw__7TObjectFUl(int);

extern void *tl_02;

u8 *TBoss6CrushPtcl__ct(u8 *boss6_crush_ptcl, void *arg1, Vec_80359EF0 *arg2) {
    __ct__7TObjectFP7TObject(boss6_crush_ptcl, arg1);
    *(s32 **)((s8 *)boss6_crush_ptcl + 0x18) = __vt__15TBoss6CrushPtcl;
    *(s32 *)((s8 *)boss6_crush_ptcl + 0) = TBoss6CrushPtcl__name;
    Vec_80359EF0 v = *arg2;
    ((TBoss6CrushPtcl *)boss6_crush_ptcl)->m_20 = (s32)create_particle_emitter(&v, 0x203);
    ((TBoss6CrushPtcl *)boss6_crush_ptcl)->m_24 = (s32)create_particle_emitter(&v, 0x204);
    ((TBoss6CrushPtcl *)boss6_crush_ptcl)->m_1C = 0;
    return boss6_crush_ptcl;
}

void *TBoss6CrushPtcl::create() {
    void *o = __nw__7TObjectFUl(0x28);
    if (o != NULL) {
        o = TBoss6CrushPtcl__ct((u8 *)o, (void *)tl_02, (Vec_80359EF0 *)(this));
    }
    return o;
}

}
