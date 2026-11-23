#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/boss/galgryphon/TBoss5GryphonColli.h"
#include "pso/boss/galgryphon/TBoss5GryphonDemo.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/boss/galgryphon/TBoss5GryphonColli_C.h"
#include <stddef.h>
#include "pso/system/vector.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D8F74.h"


#pragma readonly_strings on

CollisionBody TBoss5GryphonColli_sphere_chain_desc = {
    {0.0f, 0.0f, 0.0f}, 1.0f, 0.0f, 0, 0x8003,
};

const char *TBoss5GryphonColli_C__name = "TBoss5GryphonColli_C";
const char *TBoss5GryphonColli__name = "TBoss5GryphonColli";

// Written last to first: the unit is generated deferred (see configure.py).

TBoss5GryphonColli_C::TBoss5GryphonColli_C(TObject *parent, s32 count, const Vec *pos, f32 len) : TObjCollidable(parent) {
    f32 zero;
    f32 step;
    f32 z;
    CollisionBody *body;
    s32 i;
    m_name = TBoss5GryphonColli_C__name;
    entity_id = alloc_object_ids(0);
    VecCopy(&local_position, pos);
    body_count = count;
    bodies = (CollisionBody *)mem_alloc(body_count * sizeof(CollisionBody));
    step = 2.0f * len;
    body = bodies;
    zero = 0.0f;
    i = 0;
    z = len * (body_count - 1);
    for (; i < body_count; i++) {
        copy_collision_body(body, &TBoss5GryphonColli_sphere_chain_desc);
        body->offset.x = zero;
        body->offset.y = zero;
        body->offset.z = z;
        z -= step;
        body->radius = len;
        body->flags = 0x10003;
        body++;
    }
    refresh_collision_body_centers();
    register_entity_by_id(this);
    clear_segment_flags();
}

TBoss5GryphonColli_C::~TBoss5GryphonColli_C() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void TBoss5GryphonColli_C::set_segment_flags() {
    s32 i;
    for (i = 0; i < this->body_count; i++) {
        this->bodies[i].flags |= 1;
    }
}

void TBoss5GryphonColli_C::clear_segment_flags() {
    s32 i;
    for (i = 0; i < this->body_count; i++) {
        this->bodies[i].flags &= ~1;
    }
}

// Places the chain at local_position from pos turned by angle and enables its bodies.
void TBoss5GryphonColli_C::enable_at(Vec *pos, s32 angle) {
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

void TBoss5GryphonColli_C::disable() { this->clear_segment_flags(); }

void TBoss5GryphonColli_C::render() {  }

TBoss5GryphonColli::TBoss5GryphonColli(TObject *parent) : TObject(parent) {
    Vec offset;
    m_name = TBoss5GryphonColli__name;
    offset.x = 0.0f;
    offset.y = 0.0f;
    offset.z = 3e+01f;
    this->objects[0] = new TBoss5GryphonColli_C(this, 1, &offset, 35.0f);
}

TBoss5GryphonColli::~TBoss5GryphonColli() {
    for (s32 index = 0; index < 1; ++index) {
        if (objects[index] != NULL) {
            objects[index]->queue_destruction();
            objects[index] = NULL;
        }
    }
}

void TBoss5GryphonColli::enable_blocking_bodies(Vec *pos, s32 angle) { this->objects[0]->enable_at(pos, angle); }

void TBoss5GryphonColli::disable_blocking_bodies() { this->objects[0]->disable(); }
