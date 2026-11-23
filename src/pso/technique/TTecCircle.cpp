#define TOBJECT_OUT_OF_LINE_HELPERS

#include "pso/render/render_util.h"
#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/technique/TTecCircle.h"

#include "pso/system/vector.h"
#include "pso/technique/TTecReverser.h"

#include "pso/system/task/TObject.h"
#include "pso/math/MatrixVector.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801542CC.h"

// Built with deferred code generation (configure.py): the functions run last to first.

TTecCircle::TTecCircle(saddr source, Vec *pos, Vec *target, s32 level) : TEffect() {
    this->m_b4 = 0xFFFF;
    VecCopy(&this->position, pos);
    VecCopy(&this->target, target);
    this->scale.x = 1.0f;
    this->scale.y = 1.0f;
    this->scale.z = 1.0f;
    this->m_74 = 0;
    this->m_b8 = 0;
    this->source = source;
    if (level < 0) {
        this->m_78 = 0;
    } else if (level >= 0x1E) {
        this->m_78 = 0x1E;
    } else {
        this->m_78 = level;
    }
    this->band = TObjPlayer::get_level_tier(this->m_78);
    this->color.a = 0.2f;
    this->color.r = 1.0f;
    this->color.g = 1.0f;
    this->color.b = 1.0f;
    this->speed = 3.0f;
    this->lifetime = 150.0f;
    this->collisionBody.offset.x = 0.0f;
    this->collisionBody.offset.y = 0.0f;
    this->collisionBody.offset.z = 0.0f;
    this->collisionBody.radius = 10.0f;
    this->collisionBody.half_width = 1.0f;
    this->collisionBody.shape = 0;
    if (get_entity_id((TObjBase *)this->source) < 4U) {
        if (get_type__10TObjPlayerFPv((void *)(this->source + 0x828)) != 0) {
            this->collisionBody.flags = 0x40007;
        } else {
            this->collisionBody.flags = 0x40107;
        }
    } else {
        this->collisionBody.flags = 0x40007;
    }
    this->m_e8 = new TObjCollidable(this);
    if (this->m_e8 != NULL) {
        init_collision_body_parts(this->m_e8, &this->collisionBody, 1);
    }
}

TTecCircle::TTecCircle(saddr arg1, saddr arg2, s32 arg4) : TEffect() {
    this->m_b4 = 0xFFFF;
    VecCopy(&this->position, (const Vec *)arg2);
    this->target.x = 0.0f;
    this->target.y = 0.0f;
    this->target.z = 0.0f;
    this->m_b8 = 0;
    this->scale.x = 1.0f;
    this->scale.y = 1.0f;
    this->scale.z = 1.0f;
    this->m_74 = 0;
    this->source = arg1;
    if (arg4 < 0) {
        this->m_78 = 0;
    } else if (arg4 >= 0x1E) {
        this->m_78 = 0x1E;
    } else {
        this->m_78 = arg4;
    }
    this->band = TObjPlayer::get_level_tier(this->m_78);
    this->color.a = 0.2f;
    this->color.r = 1.0f;
    this->color.g = 1.0f;
    this->color.b = 1.0f;
    this->speed = 3.0f;
    this->lifetime = 150.0f;
    this->collisionBody.offset.x = 0.0f;
    this->collisionBody.offset.y = 0.0f;
    this->collisionBody.offset.z = 0.0f;
    this->collisionBody.radius = 10.0f;
    this->collisionBody.half_width = 1.0f;
    this->collisionBody.shape = 0;
    if (get_entity_id((TObjBase *)this->source) < 4U) {
        if (get_type__10TObjPlayerFPv((void *)(this->source + 0x828)) != 0) {
            this->collisionBody.flags = 0x40007;
        } else {
            this->collisionBody.flags = 0x40107;
        }
    } else {
        this->collisionBody.flags = 0x40007;
    }
    this->m_e8 = new TObjCollidable(this);
    if (this->m_e8 != NULL) {
        init_collision_body_parts(this->m_e8, &this->collisionBody, 1);
    }
}

TTecCircle::~TTecCircle() {
    if (this->m_e8 != NULL) {
        free_collision_body_parts(this->m_e8);
    }
}

void TTecCircle::run_task() {

    switch (this->state) {
    case 0:
        sub_8022C008();
        count_if_within_range();
        return;
    case 1:
        this->tick_lifetime();
        return;
    }
}

void TTecCircle::sub_8022C008() {
    approach_vector_fixed_distance(&this->position, &this->target, &this->position, this->speed);
}

void TTecCircle::count_if_within_range() {
    Vec diff;
    diff.x = this->position.x - this->target.x;
    diff.y = this->position.y - this->target.y;
    diff.z = this->position.z - this->target.z;
    if (vector_length(&diff) <= this->speed) {
        this->state = (this->state + 1);
    }
}

void TTecCircle::tick_lifetime() {
    this->state = 1;
    this->age = (this->age + 1);
    if ((f32) this->age > this->lifetime) {
        queue_destruction();
    }
}

void TTecCircle::render() {
    Vec full_scale = {50.0f, 50.0f, 50.0f}; // the scale it grows to once it has arrived
    switch (this->state) {
    case 0:
        break;
    case 1:
        approach_vector_in_place(&scale, &full_scale, 2.75f);
        break;
    }
    debug_draw_sphere(&this->position, &this->color, this->scale.x);
}

void TTecReverser::sub_8022BE64(u8 *arg1, s32 arg2) {
    *(f32 *)((s8 *)arg1 + 0) = (f32) (*(f32 *)((s8 *)arg1 + 0) + (f32) arg2);
    this->speed = (f32) *(f32 *)((s8 *)arg1 + 4);
    this->lifetime = *(f32 *)((s8 *)arg1 + 8);
}
