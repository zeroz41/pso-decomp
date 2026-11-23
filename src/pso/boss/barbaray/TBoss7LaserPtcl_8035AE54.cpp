#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/boss/TUnk_804F1C88.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/vector.h"
#include "pso/player/PhotonChairSeat.h"

TUnk_804F1C88::TUnk_804F1C88(TObject *parent, const Vec *origin) : TObject(parent) {
    hit_body.offset.x = 0.0f;
    hit_body.offset.y = 0.0f;
    hit_body.offset.z = 0.0f;
    hit_body.radius = 0.0f;
    hit_body.half_width = 0.0f;
    hit_body.shape = 0;
    hit_body.flags = 0x11F07;
    hit_body.center.x = 0.0f;
    hit_body.center.y = 0.0f;
    hit_body.center.z = 0.0f;
    hit_body.unk_28 = 0.0f;
    hit_set.colliders = &hit_body;
    hit_set.count = 1;
    VecCopy(&hit_set.position, origin);
    spawn_particle_effect(&hit_set.position, 0x211);
    create_timed_particle_emitter(&hit_set.position, 0x213, 0, 0x1E);
}

void TUnk_804F1C88::destroy_instance() {  }
void TUnk_804F1C88::load_static_resource() {  }
void PhotonChairSeat::update() {}
