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
#include "pso/unk/TUnk_8048E728.h"
#include "pso/unk/text_802F0E24.h"

// Barba Ray's twin of TObjBoss2Tunnel_8003B1FC.cpp: the parent the tunnel's particles are handed
// over to, created by sub_802F19C0.
TObject *lbl_805D6960;

void TObjBoss7Tunnel::detach_children(TParticleCtrl *particle, const Vec *offset) {
    TUnk_8048E728 *child;
    while ((child = (TUnk_8048E728 *)particle->m_down) != NULL) {
        vec3_add_to(&child->step, offset);
        child->set_parent(lbl_805D6960);
    }
}

void TObjBoss7Tunnel::release_children(TParticleCtrl *particle, f32 speed) {
    TUnk_8048E728 *child;
    while ((child = (TUnk_8048E728 *)particle->m_down) != NULL) {
        child->step.z = child->step.z + speed;
        child->set_parent(lbl_805D6960);
    }
}

void TObjBoss7Tunnel::sub_802F19C0() {
    lbl_805D6960 = new TObject(tl_07);
}

void TUnk_804E4AD4::draw_particle_effect() {
    set_draw_list_mask(3);

    TParticleCtrl::begin_effect_render();
    TObjFish::set_global_param((saddr)boss7_common_texture_list);
    set_motion_packed_rotation();

    draw_ginja_model_with_motion(model, motion, frame);

    clear_motion_packed_rotation();
    TParticleCtrl::end_effect_render();
    restore_draw_list_mask();
}
