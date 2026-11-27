#pragma fp_contract on

#include "pso/boss/volopt/TBoss3VoloptParticleSpray.h"
#include "pso/system/task/TMainTask.h"
#include "pso/math/AngleLookup.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/vector.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include <stdlib.h>

void TBoss3VoloptParticleSpray::run_task() {
    pending += rate;
    while (pending >= 1.0f) {
        s32 angle = (s32)(182.04445f * (360.0f * (3.0517578e-05f * (f32)rand())));
        Vec at = pos;
        f32 distance = spread * (3.0517578e-05f * (f32)rand());
        at.x += distance * cos_table_lookup(angle);
        at.z += distance * sin_table_lookup(angle);
        spawn_directional_particle(&at, &rotation, effect_id);
        pending -= 1.0f;
    }
    if (--lifetime <= 0) {
        queue_destruction();
    }
}

TBoss3VoloptParticleSpray::~TBoss3VoloptParticleSpray() {}

TBoss3VoloptParticleSpray::TBoss3VoloptParticleSpray(Vec *pos, s32 effect_id, s32 lifetime, s32 *rotation, f32 rate, f32 spread)
    : TObject(tl_07) {
    VecCopy(&this->pos, pos);
    this->effect_id = effect_id;
    this->lifetime = lifetime;
    this->rate = rate;
    if (rotation != NULL) {
        copy_xyz(&this->rotation, rotation);
    } else {
        this->rotation.x = 0;
        this->rotation.y = 0;
        this->rotation.z = 0;
    }
    pending = 0.0f;
    this->spread = spread;
}
