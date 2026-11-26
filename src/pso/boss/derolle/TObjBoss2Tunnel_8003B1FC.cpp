// The De Rol Le tunnel particles' common parent: TObjBoss2Tunnel::create_parent_object creates the TObject that
// detach_children and release_children re-parent the particles to. Its own TU (twin: TObjBoss7Tunnel_802F190C.cpp for
// Boss7): its .sbss (particle_parent and pad) sits between TObjBoss2DustCtrl's and
// TObjBoss2Tunnel's 8-aligned .sbss, and TObjBoss2Tunnel's .sdata2 pool starts with render.
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"
#include "pso/system/MatrixOps.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/effect/particle/TParticle.h"


TObject *TObjBoss2Tunnel::particle_parent;

void TObjBoss2Tunnel::detach_children(TParticleCtrl *particle, const Vec *offset) {
    TParticle *child;
    while ((child = (TParticle *)particle->m_down) != NULL) {
        vec3_add_to(&child->step, offset);
        child->set_parent(particle_parent);
    }
}

void TObjBoss2Tunnel::release_children(TParticleCtrl *particle, f32 speed) {
    TParticle *child;
    while ((child = (TParticle *)particle->m_down) != NULL) {
        child->step.z = child->step.z + speed;
        child->set_parent(particle_parent);
    }
}

void TObjBoss2Tunnel::create_parent_object() {
    particle_parent = new TObject(tl_07);
}
