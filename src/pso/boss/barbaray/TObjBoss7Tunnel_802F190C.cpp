#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/MatrixOps.h"
#include "pso/render/render_util.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/boss/TUnk_804E4AD4.h"
#include "pso/boss/barbaray/TObjBoss7Tunnel.h"
#include "pso/effect/particle/TParticle.h"
#include "pso/unk/text_802F0E24.h"

// Barba Ray's twin of TObjBoss2Tunnel_8003B1FC.cpp: the parent the tunnel's particles are handed
// over to, created by create_parent_object.
TObject *TObjBoss7Tunnel_parent_object;

void TObjBoss7Tunnel::detach_children(TParticleCtrl *particle, const Vec *offset) {
    TParticle *child;
    while ((child = (TParticle *)particle->m_down) != NULL) {
        vec3_add_to(&child->step, offset);
        child->set_parent(TObjBoss7Tunnel_parent_object);
    }
}

void TObjBoss7Tunnel::release_children(TParticleCtrl *particle, f32 speed) {
    TParticle *child;
    while ((child = (TParticle *)particle->m_down) != NULL) {
        child->step.z = child->step.z + speed;
        child->set_parent(TObjBoss7Tunnel_parent_object);
    }
}

void TObjBoss7Tunnel::create_parent_object() {
    TObjBoss7Tunnel_parent_object = new TObject(tl_07);
}

void TUnk_804E4AD4::draw_particle_effect() {
    set_draw_list_mask(3);

    TParticleCtrl::begin_effect_render();
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(boss7_common_texture_list));
    set_motion_packed_rotation();

    draw_ginja_model_with_motion(model, motion, frame);

    clear_motion_packed_rotation();
    TParticleCtrl::end_effect_render();
    restore_draw_list_mask();
}
