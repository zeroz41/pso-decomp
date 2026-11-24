#include "pso/map/CsnGroundCandidates.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/vector.h"
#include "pso/technique/TTecShot.h"
#include <stddef.h>
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/task/TObject.h"
#include "pso/math/AngleLookup.h"
#include "pso/math/AngleUnits.h"
#include "pso/math/MatrixVector.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/map/CsnQuery.h"
#include "pso/render/render_util.h"
#include "pso/object/base/TObjBase.h"

void TTecShot::check_technique_projectile_wall_hit() {
    Vec to;
    Vec from;
    CsnHit *wall;
    from.x = previous.x;
    from.y = previous.y;
    from.z = previous.z;
    to.x = position.x;
    to.y = position.y;
    to.z = position.z;
    wall = csnVector(&from, &to, 0x100);
    if (wall != NULL) {
        VecCopy(&position, &wall->contact->point);
        this->vfunc_6();
        queue_destruction();
    }
}

void TTecShot::render() {  }
void TTecShot::advance_lifetime_or_destroy() {
    f32 distance;

    distance = this->traveled;
    if (distance > this->range) {
        queue_destruction();
        return;
    }
    this->traveled = (f32) (distance + this->speed);
}

#pragma push
#pragma opt_common_subs off
#pragma fp_contract on
void TTecShot::step_ground_technique_projectile() {
    Vec to;
    Vec from;
    Vec probe;
    Vec normal;
    s32 yaw;
    s32 pitch;
    f32 height;
    CsnHit *ground;
    CsnHit *wall;
    CsnContact *contact;
    VecCopy(&previous, &position);
    position.x = (direction.x * speed) + position.x;
    position.z = (direction.z * speed) + position.z;
    VecCopy(&probe, &position);
    probe.y += 1e+01f;
    ground = csnVecterUnder(&probe, 0x16EF);
    if (ground != NULL) {
        position.y = 5.0f + ground->contact->point.y;
    }
    if (fabs_float(previous.y - position.y) > 12.0f) {
        position.y = previous.y;
        queue_destruction();
        return;
    }
    from.x = previous.x;
    height = 5.0f + previous.y;
    from.y = height;
    from.z = previous.z;
    to.x = position.x;
    to.y = height;
    to.z = position.z;
    wall = csnVector(&from, &to, 0x100);
    if (wall != NULL) {
        contact = wall->contact;
        normal.x = contact->normal.x;
        normal.y = contact->normal.y;
        normal.z = contact->normal.z;
        direction_to_rotation_xy((u8 *)&normal, &yaw, &pitch);
        if (angle_difference_abs(0, yaw) >= 0x1555) {
            queue_destruction();
        }
    }
}
#pragma pop

void TTecShot::move_ground_technique_projectile() { step_ground_technique_projectile(); }

#pragma push
#pragma fp_contract on
void TTecShot::move_technique_projectile() {
    VecCopy(&previous, &position);
    position.x = (direction.x * speed) + position.x;
    position.y = (direction.y * speed) + position.y;
    position.z = (direction.z * speed) + position.z;
    check_technique_projectile_wall_hit();
}
#pragma pop

void TTecShot::run_task() { move_technique_projectile(); this->advance_lifetime_or_destroy(); }

TTecShot::~TTecShot() {
    if (collidable != NULL) {
        free_collision_body_parts(collidable);
        collidable = 0;
    }
}

TTecShot::TTecShot(saddr source, u8 *pos, u8 *target, s32 level) : TEffect() {
    f32 dx;
    f32 dz;
    f32 dy;
    s32 yaw;
    this->sourceId = 0xFFFF;
    dx = ((Vec *)target)->x - ((Vec *)pos)->x;
    dz = ((Vec *)target)->z - ((Vec *)pos)->z;
    dy = ((Vec *)target)->y - ((Vec *)pos)->y;
    yaw = (s32)(RADIANS_TO_ANGLE * atan2_float(dx, dz));
    this->position.x = ((Vec *)pos)->x;
    this->position.y = ((Vec *)pos)->y;
    this->position.z = ((Vec *)pos)->z;
    this->angles[0] = 0;
    this->angles[1] = yaw;
    this->angles[2] = 0;
    this->halfWidth = 4.0f;
    this->scale.x = 1.0f;
    this->scale.y = 1.0f;
    this->scale.z = 1.0f;
    this->traveled = 0.0f;
    this->source = source;
    if (level < 0) {
        this->level = 0;
    } else if (level >= 0x1E) {
        this->level = 0x1E;
    } else {
        this->level = level;
    }
    this->band = TObjPlayer::get_level_tier(this->level);
    this->color.a = 1.0f;
    this->color.r = 1.0f;
    this->color.g = 1.0f;
    this->color.b = 1.0f;
    this->speed = 3.0f;
    this->range = 3e+01f;
    this->direction.x = dx;
    this->direction.y = dy;
    this->direction.z = dz;
    if (0.0f != vector_length(&this->direction)) {
        normalize_vector(&this->direction);
    }
    direction_to_rotation_xz((u8 *)&this->direction, &this->angles[0], &this->angles[2]);
    this->collisionBody.offset.x = 0.0f;
    this->collisionBody.offset.y = 0.0f;
    this->collisionBody.offset.z = 0.0f;
    if (((TObjBase *)this->source)->get_entity_id() < 4U && get_type__10TObjPlayerFPv((void *)(this->source + 0x828)) != 0) {
        this->collisionBody.offset.z = (-1e+01f);
    }
    this->collisionBody.radius = 5.0f;
    this->collisionBody.half_width = 1.0f;
    this->collisionBody.shape = 1;
    if (((TObjBase *)this->source)->get_entity_id() < 4U) {
        if (get_type__10TObjPlayerFPv((void *)(this->source + 0x828)) != 0) {
            this->collisionBody.flags = 0x40007;
        } else {
            this->collisionBody.flags = 0x40107;
        }
    } else {
        this->collisionBody.flags = 0x40007;
    }
    this->collidable = new TObjCollidable(this);
    if (this->collidable != NULL) {
        init_collision_body_parts(this->collidable, &this->collisionBody, 1);
    }
}

// The facing form: the technique starts at `pos` and flies along the y angle
// `angle` instead of towards a target point.
TTecShot::TTecShot(saddr source, Vec *pos, s32 angle, s32 level) : TEffect() {
    this->sourceId = 0xFFFF;
    this->position.x = pos->x;
    this->position.y = pos->y;
    this->position.z = pos->z;
    this->scale.x = 1.0f;
    this->scale.y = 1.0f;
    this->scale.z = 1.0f;
    this->traveled = 0.0f;
    this->source = source;
    if (level < 0) {
        this->level = 0;
    } else if (level >= 0x1E) {
        this->level = 0x1E;
    } else {
        this->level = level;
    }
    this->band = TObjPlayer::get_level_tier(this->level);
    this->color.a = 1.0f;
    this->color.r = 1.0f;
    this->color.g = 1.0f;
    this->color.b = 1.0f;
    this->angles[0] = 0;
    this->angles[1] = angle;
    this->angles[0] = 0;
    this->halfWidth = 4.0f;
    this->speed = 3.0f;
    this->range = 3e+01f;
    this->direction.x = sin_table_lookup(this->angles[1]);
    this->direction.y = 0.0f;
    this->direction.z = cos_table_lookup(this->angles[1]);
    if (0.0f != vector_length(&this->direction)) {
        normalize_vector(&this->direction);
    }
    direction_to_rotation_xz((u8 *)&this->direction, &this->angles[0], &this->angles[2]);
    this->collisionBody.offset.x = 0.0f;
    this->collisionBody.offset.y = 0.0f;
    this->collisionBody.offset.z = 0.0f;
    if (((TObjBase *)this->source)->get_entity_id() < 4U && get_type__10TObjPlayerFPv((void *)(this->source + 0x828)) != 0) {
        this->collisionBody.offset.z = (-1e+01f);
    }
    this->collisionBody.radius = 5.0f;
    this->collisionBody.half_width = 1.0f;
    this->collisionBody.shape = 1;
    if (((TObjBase *)this->source)->get_entity_id() < 4U) {
        if (get_type__10TObjPlayerFPv((void *)(this->source + 0x828)) != 0) {
            this->collisionBody.flags = 0x40007;
        } else {
            this->collisionBody.flags = 0x40107;
        }
    } else {
        this->collisionBody.flags = 0x40007;
    }
    this->collidable = new TObjCollidable(this);
    if (this->collidable != NULL) {
        init_collision_body_parts(this->collidable, &this->collisionBody, 1);
    }
}

void TTecShot::vfunc_8(void *) {  }
