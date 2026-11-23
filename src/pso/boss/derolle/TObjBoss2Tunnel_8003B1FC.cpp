// The De Rol Le tunnel particles' common parent: TObjBoss2Tunnel::create_parent_object creates the TObject that
// detach_children and release_children re-parent the particles to. Its own TU (twin: TObjBoss7Tunnel_802F190C.cpp for
// Boss7): its .sbss (TObjBoss2Tunnel_parent_object and pad, 0x805D4BF8) sits between TObjBoss2DustCtrl's and
// TObjBoss2Tunnel's 8-aligned .sbss, and TObjBoss2Tunnel's .sdata2 pool starts with render (0x8003B2EC).
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"
#include "pso/system/MatrixOps.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/effect/particle/TParticle.h"


TObject *TObjBoss2Tunnel_parent_object;

void TObjBoss2Tunnel::detach_children(TParticleCtrl *particle, const Vec *offset) {
    TParticle *child;
    while ((child = (TParticle *)particle->m_down) != NULL) {
        vec3_add_to(&child->step, offset);
        child->set_parent(TObjBoss2Tunnel_parent_object);
    }
}

void TObjBoss2Tunnel::release_children(TParticleCtrl *particle, f32 speed) {
    TParticle *child;
    while ((child = (TParticle *)particle->m_down) != NULL) {
        child->step.z = child->step.z + speed;
        child->set_parent(TObjBoss2Tunnel_parent_object);
    }
}

void TObjBoss2Tunnel::create_parent_object() {
    TObjBoss2Tunnel_parent_object = new TObject(tl_07);
}
