// The De Rol Le tunnel particles' common parent: TObjBoss2Tunnel__sub_8003B2B0 creates the TObject that
// detach_children and release_children re-parent the particles to. Its own TU (twin: text_802F190C.cpp for
// Boss7): its .sbss (TObjBoss2Tunnel_parent_object and pad, 0x805D4BF8) sits between TObjBoss2DustCtrl's and
// TObjBoss2Tunnel's 8-aligned .sbss, and TObjBoss2Tunnel's .sdata2 pool starts with render (0x8003B2EC).
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8003B138.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"
#include "pso/system/MatrixOps.h"
#include "pso/effect/particle/TParticleCtrl.h"

// One particle of an emitter; only its position (0x3C) is known.
struct Particle_8003B1FC : public TObject {
    u8 pad_1c[0x3C - 0x1C];
    Vec position;
};

TObject *TObjBoss2Tunnel_parent_object;

void TObjBoss2Tunnel::detach_children(TParticleCtrl *particle, const Vec *offset) {
    Particle_8003B1FC *child;
    while ((child = (Particle_8003B1FC *)particle->m_down) != NULL) {
        vec3_add_to(&child->position, offset);
        child->set_parent(TObjBoss2Tunnel_parent_object);
    }
}

void TObjBoss2Tunnel::release_children(TParticleCtrl *particle, f32 speed) {
    Particle_8003B1FC *child;
    while ((child = (Particle_8003B1FC *)particle->m_down) != NULL) {
        child->position.z = child->position.z + speed;
        child->set_parent(TObjBoss2Tunnel_parent_object);
    }
}

void TObjBoss2Tunnel__sub_8003B2B0(void) {
    TObjBoss2Tunnel_parent_object = new TObject(tl_07);
}
