#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/effect/item/TItemEffBringer.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/vector.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"

#include "types.h"
#include "dolphin/mtx.h"
#include "pso/system/task/TObject.h"
#include "pso/system/MatrixStack.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/math/AngleLookup.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/MatrixStack.h"

const char *TItemEffBringer::class_name = "TItemEffBringer";

void TItemEffBringer::hook() {
    Vec work = m_pos;
    for (int i = 0; i != particle_count; i++) {
        spawn_particle_effect(&work, 0x9C);
        subtract_vector(&work, &particle_step);
    }
}

TItemEffBringer::~TItemEffBringer() {
    for (int i = 0; i != particle_count; i++) {
        TParticleCtrl::release(particles[i]);
    }
}

#pragma push
#pragma fp_contract on
TItemEffBringer::TItemEffBringer(void *owner, const Vec *pos, const Vec *dir, f32 life)
    : TItemShoot(owner, pos, dir, life) {
    Vec to_shot;
    Vec camera;
    Vec origin;
    f32 cross;
    f32 count;
    s32 i;
    m_name = class_name;
    push_matrix();
    origin.x = origin.y = origin.z = 0.0f;
    TObjPlayer::invert_matrix_in_place(0);
    transform_point_by_current_matrix(&origin.x, &camera);
    VecCopy(&to_shot, pos);
    subtract_vector(&to_shot, &camera);
    pop_matrix();
    cross = sin_table_lookup(m_count - (s32)((65536.0 / (2.0 * 3.141592f)) * atan2_float(to_shot.x, to_shot.z)));
    if (cross < 0.0f) {
        cross *= -1.0f;
    }
    count = 4.0f * cross + 1.0f;
    VecCopy(&particle_step, &m_dir);
    particle_step.x /= count;
    particle_step.y /= count;
    particle_step.z /= count;
    particle_count = (s32)count + 1;
    for (i = 0; i != particle_count; i++) {
        particles[i] = 0;
    }
    disallow_rendering();
}
#pragma pop

void *TItemEffBringer::create(void *owner, const Vec *pos, const Vec *dir, f32 life) {
    if ((0.0f != life) && (owner != NULL)) {
        return new TItemEffBringer(owner, pos, dir, life);
    }
    return NULL;
}
