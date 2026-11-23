#pragma defer_codegen on

#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/task/TObject.h"

#include "pso/player/TObjPlayer.h"

#include "pso/system/vector.h"

#include "pso/object/base/TObjMotion.h"

#include "pso/boss/dragon/TBoss1DragonColli_C.h"

#include "pso/boss/dragon/TBoss1DragonColli.h"

#include "pso/unk/text_803D96A8.h"

#include "types.h"

#include <stddef.h>

#include "pso/boss/darkfalz/TOBoss4Rock.h"

#pragma readonly_strings on

// Stored in the object name field by the constructors.
const char *TBoss1DragonColli_C__name = "TBoss1DragonColli_C";

const char *TBoss1DragonColli__name = "TBoss1DragonColli";

#include "pso/boss/dragon/TBoss1DragonDemo.h"

#include "pso/unk/TLobby.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_801542CC.h"

#pragma inline_depth(1)

#pragma auto_inline off

#pragma dont_inline off

CollisionBody TBoss1DragonColli_sphere_chain_desc = {
    {0.0f, 0.0f, 0.0f}, 25.0f, 0.0f, 0, 0x8003,
};

#pragma push
#pragma scheduling off
// Copies one collision body.
void copy_collision_body(CollisionBody *dst, const CollisionBody *src) {
    *dst = *src;
}

#pragma pop
TBoss1DragonColli_C::TBoss1DragonColli_C(TObject *parent, s32 count, Vec *pos, f32 scale) : TObjCollidable(parent) {
    CollisionBody *e;
    s32 i;
    f32 zero;
    f32 step;
    f32 z;
    this->m_name = TBoss1DragonColli_C__name;
    VecCopy(&this->local_position, pos);
    this->entity_id = alloc_object_ids(0);
    this->body_count = count;
    this->bodies = (CollisionBody *)mem_alloc(this->body_count * sizeof(CollisionBody));
    step = 2.0f * scale;
    e = this->bodies;
    zero = 0.0f;
    z = scale * (this->body_count - 1);
    for (i = 0; i < this->body_count; i++) {
        copy_collision_body(e, &TBoss1DragonColli_sphere_chain_desc);
        e->offset.x = zero;
        e->offset.y = zero;
        e->offset.z = z;
        z -= step;
        e->radius = scale;
        e->flags = 0x10003;
        e++;
    }
    this->refresh_collision_body_centers();
    register_entity_by_id(this);
    this->clear_segment_flags();
}

TBoss1DragonColli_C::~TBoss1DragonColli_C() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void TBoss1DragonColli_C::set_segment_flags() {
    s32 i;
    for (i = 0; i < this->body_count; i++) {
        this->bodies[i].flags |= 1;
    }
}

void TBoss1DragonColli_C::clear_segment_flags() {
    s32 i;
    for (i = 0; i < this->body_count; i++) {
        this->bodies[i].flags &= ~1;
    }
}

// Places the chain at local_position from pos turned by angle and enables its bodies.
void TBoss1DragonColli_C::enable_at(Vec *pos, s32 angle) {
    push_matrix();
    set_matrix_identity(NULL);
    post_translate_matrix(&pos->x);
    rotate_matrix_y(NULL, angle);
    matrix_mult_vec(NULL, &this->local_position, &this->position);
    pop_matrix();
    this->rotation_y = angle;
    this->refresh_collision_body_centers();
    this->set_segment_flags();
}

void TBoss1DragonColli_C::disable() { this->clear_segment_flags(); }

void TBoss1DragonColli_C::render() {  }

TBoss1DragonColli::TBoss1DragonColli(TObject *parent) : TObject(parent) {
    Vec stack;
    m_name = TBoss1DragonColli__name;
    stack.x = 0.0f;
    stack.y = 0.0f;
    stack.z = 0.0f;
    objects[0] = new TBoss1DragonColli_C(this, 1, &stack, 25.0f);
    stack.x = -4.0f;
    stack.y = 0.0f;
    stack.z = 40.0f;
    objects[1] = new TBoss1DragonColli_C(this, 3, &stack, 10.0f);
    stack.x = -4.0f;
    stack.y = 0.0f;
    stack.z = -100.0f;
    objects[2] = new TBoss1DragonColli_C(this, 5, &stack, 10.0f);
}

TBoss1DragonColli::~TBoss1DragonColli() {
    for (s32 index = 0; index < 3; ++index) {
        if (objects[index] != NULL) {
            objects[index]->queue_destruction();
            objects[index] = NULL;
        }
    }
}

void TBoss1DragonColli::enable_blocking_bodies(Vec *pos, s32 angle) {
    s32 i;
    for (i = 0; i < 3; i++) {
        this->objects[i]->enable_at(pos, angle);
    }
}

void TBoss1DragonColli::disable_blocking_bodies() {
    s32 i;
    for (i = 0; i < 3; i++) {
        this->objects[i]->disable();
    }
}

TBoss1DragonColli_C *TBoss1DragonColli::get_object(s32 index) {
    return this->objects[index];
}
