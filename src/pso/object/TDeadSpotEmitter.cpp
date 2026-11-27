#pragma defer_codegen on

#include "pso/system/task/TObject.h"
#include "types.h"
#include "pso/object/TDeadSpotEmitter.h"
#include "pso/object/TDeadSpotGroundEmitter.h"
#include "pso/system/vector.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/AngleLookup.h"
#include "pso/boss/derolle/RandomAngle.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/effect/particle/TParticleCtrl.h"

#pragma push
#pragma fp_contract on
TDeadSpotEmitter::TDeadSpotEmitter(TObject *parent, Vec *position, TParticleCtrl *emitter, f32 radius) : TObject(parent) {
    VecCopy(&this->position, position);
    this->radius = radius;
    timer = 0;
    interval = 2;
    this->emitter = emitter;
}
#pragma pop
TDeadSpotEmitter::~TDeadSpotEmitter() {}

void TDeadSpotEmitter::place_emitter() {
  Vec stack;
  f32 x;
  s32 angle;
  angle = random_angle();
  x = radius * sin_table_lookup((int) (angle & 0xFFFFFFFFu));
  stack.y = 0.0f;
  stack.x = x;
  stack.z = radius * cos_table_lookup((int) angle);
  vec3_add_to(&stack, &position);
  emitter->set_position(&stack);
}

void TDeadSpotEmitter::run_task() {
    if (emitter == NULL || emitter->all_parents_unqueued_for_destruction() == 0) {
        queue_destruction();
        return;
    }
    timer++;
    if (timer >= interval) {
        timer = 0;
        place_emitter();
    }
}

TDeadSpotGroundEmitter::TDeadSpotGroundEmitter(TObject *parent, Vec *position, TParticleCtrl *emitter, f32 radius) : TDeadSpotEmitter(parent, position, emitter, radius) {
    interval = 8;
}

TDeadSpotGroundEmitter::~TDeadSpotGroundEmitter() {}
#pragma push
#pragma opt_common_subs off
void TDeadSpotGroundEmitter::place_emitter() {
    Vec stack;
    f32 x;
    s32 angle;
    angle = random_angle();
    x = radius * sin_table_lookup(angle);
    stack.y = 0.0f;
    stack.x = x;
    stack.z = radius * cos_table_lookup(angle);
    vec3_add_to(&stack, &position);
    TObjBoss2Tunnel::adjust_to_ground(&stack, &stack);
    emitter->set_position(&stack);
}

#pragma pop
