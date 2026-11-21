#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/boss/barbaray/TBoss7LaserPtcl_8035AE54.h"
#include "pso/boss/TUnk_804F1C88.h"
#include "pso/effect/particle/TParticleCtrl_800867E4.h"
#include "pso/system/vector.h"

// TBoss7DeRolLeC.cpp calls this as a C function on memory it allocated, so it
// stays one until that caller can use the TUnk_804F1C88 constructor itself.
extern "C" {
void __ct__7TObjectFP7TObject(void *, void *);
extern s32 __vt__13TUnk_804F1C88[];
}

u8 *TBoss7LaserPtcl__sub_8035AE54(u8 *object, saddr parent, saddr origin) {
    TUnk_804F1C88 *wave = (TUnk_804F1C88 *)object;
    __ct__7TObjectFP7TObject((void *)object, (void *)parent);
    *(s32 **)((s8 *)object + 0x18) = __vt__13TUnk_804F1C88;
    wave->hit_body.offset.x = 0.0f;
    wave->hit_body.offset.y = 0.0f;
    wave->hit_body.offset.z = 0.0f;
    wave->hit_body.radius = 0.0f;
    wave->hit_body.half_width = 0.0f;
    wave->hit_body.shape = 0;
    wave->hit_body.flags = 0x11F07;
    wave->hit_body.center.x = 0.0f;
    wave->hit_body.center.y = 0.0f;
    wave->hit_body.center.z = 0.0f;
    wave->hit_body.unk_28 = 0.0f;
    wave->hit_set.colliders = &wave->hit_body;
    wave->hit_set.count = 1;
    VecCopy(&wave->hit_set.position, (const Vec *)origin);
    spawn_particle_effect(&wave->hit_set.position, 0x211);
    create_timed_particle_emitter(&wave->hit_set.position, 0x213, 0, 0x1E);
    return object;
}

void TBoss7LaserPtcl__sub_8035AF0C(void) {  }
void TBoss7LaserPtcl__sub_8035AF10(void) {  }
void TBoss7LaserPtcl__sub_8035AF14(void) {  }
