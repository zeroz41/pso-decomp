#include "pso/map/CsnGroundCandidates.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/vector.h"
#include "pso/effect/TUnk_804CCC68.h"
#include <stddef.h>
#include "pso/technique/TTecGiZonde.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/math/AngleLookup.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/map/CsnQuery.h"
#include "pso/render/render_util.h"


struct RecoveredFields_8023A510_arg0 {
    u8 unknown_0[0x20];
    f32 field_20;
    f32 field_24;
    f32 field_28;
    u8 unknown_2C[0x1C];
    f32 field_48;
    u8 unknown_4C[0x4];
    f32 field_50;
    u8 unknown_54[0x10];
    f32 field_64;
    u8 unknown_68[0x10];
    f32 field_78;
    f32 field_7C;
    f32 field_80;
};




extern "C" {
s32 check_technique_projectile_wall_hit__13TUnk_804CCC68Fv(void *, f32, f32);
f32 fabs_float(f32);
void step_ground_technique_projectile(RecoveredFields_8023A510_arg0 *arg0);
}
void direction_to_rotation_xy(u8 *arg0, s32 *arg1, s32 *arg2);

void move_ground_technique_projectile(void* p);

void TUnk_804CCC68::check_technique_projectile_wall_hit() {
    Vec to;
    Vec from;
    CsnHit *wall;
    from.x = previous[0];
    from.y = previous[1];
    from.z = previous[2];
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

void TUnk_804CCC68::render() {  }
void TUnk_804CCC68::advance_lifetime_or_destroy() {
    f32 temp_f1;

    temp_f1 = this->traveled;
    if (temp_f1 > this->range) {
        queue_destruction();
        return;
    }
    this->traveled = (f32) (temp_f1 + this->speed);
}

#pragma push
#pragma opt_common_subs off
#pragma fp_contract on
LAYOUT_ASSERT(RecoveredFields_8023A510_arg0_20_offset, offsetof(RecoveredFields_8023A510_arg0, field_20) == 0x20);
LAYOUT_ASSERT(RecoveredFields_8023A510_arg0_24_offset, offsetof(RecoveredFields_8023A510_arg0, field_24) == 0x24);
LAYOUT_ASSERT(RecoveredFields_8023A510_arg0_28_offset, offsetof(RecoveredFields_8023A510_arg0, field_28) == 0x28);
LAYOUT_ASSERT(RecoveredFields_8023A510_arg0_48_offset, offsetof(RecoveredFields_8023A510_arg0, field_48) == 0x48);
LAYOUT_ASSERT(RecoveredFields_8023A510_arg0_50_offset, offsetof(RecoveredFields_8023A510_arg0, field_50) == 0x50);
LAYOUT_ASSERT(RecoveredFields_8023A510_arg0_64_offset, offsetof(RecoveredFields_8023A510_arg0, field_64) == 0x64);
LAYOUT_ASSERT(RecoveredFields_8023A510_arg0_78_offset, offsetof(RecoveredFields_8023A510_arg0, field_78) == 0x78);
LAYOUT_ASSERT(RecoveredFields_8023A510_arg0_7C_offset, offsetof(RecoveredFields_8023A510_arg0, field_7C) == 0x7C);
LAYOUT_ASSERT(RecoveredFields_8023A510_arg0_80_offset, offsetof(RecoveredFields_8023A510_arg0, field_80) == 0x80);

void step_ground_technique_projectile(RecoveredFields_8023A510_arg0 *arg0) {
    Vec to;
    Vec from;
    Vec probe;
    Vec dir;
    s32 yaw;
    s32 pitch;
    f32 temp_f1;
    CsnHit *ground;
    CsnHit *wall;
    CsnContact *contact;
    VecCopy((Vec *)(((u8 *)arg0) + 0x78), (const Vec *)(((u8 *)arg0) + 0x20));
    arg0->field_20 = (f32) ((arg0->field_48 * arg0->field_64) + arg0->field_20);
    arg0->field_28 = (f32) ((arg0->field_50 * arg0->field_64) + arg0->field_28);
    VecCopy(&probe, (const Vec *)(((u8 *)arg0) + 0x20));
    probe.y += 1e+01f;
    ground = csnVecterUnder(&probe, 0x16EF);
    if (ground != NULL) {
        arg0->field_24 = 5.0f + ground->contact->point.y;
    }
    if (fabs_float(arg0->field_7C - arg0->field_24) > 12.0f) {
        arg0->field_24 = (f32) arg0->field_7C;
        ((TObject *)arg0)->queue_destruction();
        return;
    }
    from.x = arg0->field_78;
    temp_f1 = 5.0f + arg0->field_7C;
    from.y = temp_f1;
    from.z = arg0->field_80;
    to.x = arg0->field_20;
    to.y = temp_f1;
    to.z = arg0->field_28;
    wall = csnVector(&from, &to, 0x100);
    if (wall != NULL) {
        contact = wall->contact;
        dir.x = contact->normal.x;
        dir.y = contact->normal.y;
        dir.z = contact->normal.z;
        direction_to_rotation_xy((u8 *)&dir, &yaw, &pitch);
        if (angle_difference_abs(0, yaw) >= 0x1555) {
            ((TObject *)arg0)->queue_destruction();
        }
    }
}
#pragma pop

void move_ground_technique_projectile(void* p) { step_ground_technique_projectile((RecoveredFields_8023A510_arg0 *)(p)); }

#pragma push
#pragma fp_contract on
void TUnk_804CCC68::move_technique_projectile() {
    f32 temp_f1;
    f32 temp_f2;
    u8 *arg0 = (u8 *)this;
    VecCopy((Vec *)(arg0 + 0x78), (const Vec *)(arg0 + 0x20));
    *(f32 *)((s8 *)arg0 + 0x20) = (f32) ((*(f32 *)((s8 *)arg0 + 0x48) * this->speed) + *(f32 *)((s8 *)arg0 + 0x20));
    *(f32 *)((s8 *)arg0 + 0x24) = (f32) ((*(f32 *)((s8 *)arg0 + 0x4C) * this->speed) + *(f32 *)((s8 *)arg0 + 0x24));
    temp_f2 = *(f32 *)((s8 *)arg0 + 0x50);
    temp_f1 = this->speed;
    *(f32 *)((s8 *)arg0 + 0x28) = (f32) ((temp_f2 * temp_f1) + *(f32 *)((s8 *)arg0 + 0x28));
    check_technique_projectile_wall_hit__13TUnk_804CCC68Fv(arg0, temp_f1, temp_f2);
}
#pragma pop

void TUnk_804CCC68::run_task() { move_technique_projectile(); this->advance_lifetime_or_destroy(); }

extern "C" {
u16 get_entity_id(s32);
s32 get_type__10TObjPlayerFPv(void *p);
f32 atan2_float(f32 y, f32 x);
s32 init_collision_body_parts(u32, void *, int);
u32 __ct__14TObjCollidableFP7TObject(u32, void *);
f32 vector_length(void *);
extern const f64 lbl_8044DC00;

void free_collision_body_parts(void *);

TUnk_804CCC68::~TUnk_804CCC68() {
    if (proxy != NULL) { free_collision_body_parts(proxy); proxy = 0; }
}
}
void direction_to_rotation_xz(u8 *arg0, s32 *arg1, s32 *arg2);
TUnk_804CCC68::TUnk_804CCC68(saddr arg1, u8 *arg2, u8 *arg3, s32 arg4) : TEffect() {
    f32 dx;
    f32 dz;
    f32 dy;
    f64 t;
    s32 ang;
    uaddr var_r0;
    initialize_ground_candidates(ground_candidates);
    this->sourceId = 0xFFFF;
    dx = *(f32 *)((s8 *)arg3 + 0) - *(f32 *)((s8 *)arg2 + 0);
    dz = *(f32 *)((s8 *)arg3 + 8) - *(f32 *)((s8 *)arg2 + 8);
    dy = *(f32 *)((s8 *)arg3 + 4) - *(f32 *)((s8 *)arg2 + 4);
    t = atan2_float(dx, dz);
    ang = (s32)(lbl_8044DC00 * t);
    *(f32 *)((s8 *)this + 0x20) = *(f32 *)((s8 *)arg2 + 0);
    *(f32 *)((s8 *)this + 0x24) = *(f32 *)((s8 *)arg2 + 4);
    *(f32 *)((s8 *)this + 0x28) = *(f32 *)((s8 *)arg2 + 8);
    *(s32 *)((s8 *)this + 0x54) = 0;
    *(s32 *)((s8 *)this + 0x58) = ang;
    *(s32 *)((s8 *)this + 0x5C) = 0;
    this->halfWidth = 4.0f;
    *(f32 *)((s8 *)this + 0x3C) = 1.0f;
    *(f32 *)((s8 *)this + 0x40) = 1.0f;
    *(f32 *)((s8 *)this + 0x44) = 1.0f;
    this->traveled = 0.0f;
    this->source = arg1;
    if (arg4 < 0) {
        this->level = 0;
    } else if (arg4 >= 0x1E) {
        this->level = 0x1E;
    } else {
        this->level = arg4;
    }
    this->band = TObjPlayer::get_level_tier(this->level);
    *(f32 *)((s8 *)this + 0x2C) = 1.0f;
    *(f32 *)((s8 *)this + 0x30) = 1.0f;
    *(f32 *)((s8 *)this + 0x34) = 1.0f;
    *(f32 *)((s8 *)this + 0x38) = 1.0f;
    this->speed = 3.0f;
    this->range = 3e+01f;
    *(f32 *)((s8 *)this + 0x48) = dx;
    *(f32 *)((s8 *)this + 0x4C) = dy;
    *(f32 *)((s8 *)this + 0x50) = dz;
    if (0.0f != vector_length(((u8 *)this) + 0x48)) {
        normalize_vector((Vec *)((u8 *)this + 0x48));
    }
    direction_to_rotation_xz((((u8 *)this) + 0x48), (s32 *)(((u8 *)this) + 0x54), (s32 *)(((u8 *)this) + 0x5C));
    this->collisionBody.offset.x = 0.0f;
    this->collisionBody.offset.y = 0.0f;
    this->collisionBody.offset.z = 0.0f;
    if (get_entity_id(this->source) < 4U && get_type__10TObjPlayerFPv((void *)(this->source + 0x828)) != 0) {
        this->collisionBody.offset.z = (-1e+01f);
    }
    this->collisionBody.radius = 5.0f;
    this->collisionBody.half_width = 1.0f;
    this->collisionBody.shape = 1;
    if (get_entity_id(this->source) < 4U) {
        if (get_type__10TObjPlayerFPv((void *)(this->source + 0x828)) != 0) {
            this->collisionBody.flags = 0x40007;
        } else {
            this->collisionBody.flags = 0x40107;
        }
    } else {
        this->collisionBody.flags = 0x40007;
    }
    var_r0 = (uaddr)TObject::operator new(0xAC);
    if (var_r0 != 0U) {
        var_r0 = __ct__14TObjCollidableFP7TObject(var_r0, this);
    }
    *(u32 *)((s8 *)this + 0x128) = var_r0;
    if (*(u32 *)((s8 *)this + 0x128) != 0U) {
        init_collision_body_parts(*(u32 *)((s8 *)this + 0x128), &this->collisionBody, 1);
    }
}

// The facing form: the technique starts at `pos` and flies along the y angle
// `angle` instead of towards a target point.
TUnk_804CCC68::TUnk_804CCC68(saddr source, Vec *pos, s32 angle, s32 level) : TEffect() {
    uaddr var_r0;
    initialize_ground_candidates(ground_candidates);
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
    if (get_entity_id(this->source) < 4U && get_type__10TObjPlayerFPv((void *)(this->source + 0x828)) != 0) {
        this->collisionBody.offset.z = (-1e+01f);
    }
    this->collisionBody.radius = 5.0f;
    this->collisionBody.half_width = 1.0f;
    this->collisionBody.shape = 1;
    if (get_entity_id(this->source) < 4U) {
        if (get_type__10TObjPlayerFPv((void *)(this->source + 0x828)) != 0) {
            this->collisionBody.flags = 0x40007;
        } else {
            this->collisionBody.flags = 0x40107;
        }
    } else {
        this->collisionBody.flags = 0x40007;
    }
    var_r0 = (uaddr)TObject::operator new(0xAC);
    if (var_r0 != 0U) {
        var_r0 = __ct__14TObjCollidableFP7TObject(var_r0, this);
    }
    *(u32 *)((s8 *)this + 0x128) = var_r0;
    if (*(u32 *)((s8 *)this + 0x128) != 0U) {
        init_collision_body_parts(*(u32 *)((s8 *)this + 0x128), &this->collisionBody, 1);
    }
}

void TUnk_804CCC68::vfunc_8(void *) {  }

__declspec(section ".rodata") extern const f64 lbl_8044DC00 = 10430.38043493439;
