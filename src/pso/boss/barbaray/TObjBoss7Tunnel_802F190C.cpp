#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/MatrixOps.h"
#include "pso/render/render_util.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/render/ChunkModelDraw.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/unk/text_803DA798.h"
#include "pso/boss/TObjBoss7TunnelNode.h"
#include "pso/boss/barbaray/TObjBoss7Tunnel.h"
#include "pso/effect/particle/TParticle.h"
#include "pso/boss/barbaray/Boss7CommonResource.h"

// Barba Ray's twin of TObjBoss2Tunnel_8003B1FC.cpp: the parent the tunnel's particles are handed
// over to, created by create_parent_object.
TObject *TObjBoss7Tunnel::particle_parent;

void TObjBoss7Tunnel::detach_children(TParticleCtrl *particle, const Vec *offset) {
    TParticle *child;
    while ((child = (TParticle *)particle->m_down) != NULL) {
        vec3_add_to(&child->step, offset);
        child->set_parent(particle_parent);
    }
}

void TObjBoss7Tunnel::release_children(TParticleCtrl *particle, f32 speed) {
    TParticle *child;
    while ((child = (TParticle *)particle->m_down) != NULL) {
        child->step.z = child->step.z + speed;
        child->set_parent(particle_parent);
    }
}

void TObjBoss7Tunnel::create_parent_object() {
    particle_parent = new TObject(tl_07);
}

void TObjBoss7TunnelNode::draw_particle_effect() {
    set_draw_list_mask(3);

    TParticleCtrl::begin_effect_render();
    set_texture_list(reinterpret_cast<NJS_TEXLIST *>(boss7_common_texture_list));
    set_motion_packed_rotation();

    draw_ginja_model_with_motion(model, motion, frame);

    clear_motion_packed_rotation();
    TParticleCtrl::end_effect_render();
    restore_draw_list_mask();
}
