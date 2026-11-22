#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/vector.h"

#include <stddef.h>
#include "pso/enemy/TNeedleShoot.h"
#include "pso/map/CsnQuery.h"
#include "pso/math/AngleUnits.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/render/render_util.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/math/MatrixVector.h"

#pragma readonly_strings on

const char *TNeedleShoot__name = "TNeedleShoot";

void TNeedleShoot::vfunc_8() {  }

#pragma push
#pragma opt_common_subs off
void TNeedleShoot::check_wall_hit() {
    Vec to;
    Vec from;
    CsnHit *hit;
    from.x = prev_pos.x;
    from.y = prev_pos.y;
    from.z = prev_pos.z;
    to.x = pos.x;
    to.y = pos.y;
    to.z = pos.z;
    hit = csnVector(&from, &to, 0x100);
    if (hit != NULL) {
        VecCopy(&pos, &hit->contact->point);
        on_wall_hit();
    }
}
#pragma pop

void TNeedleShoot::render() {
    NJS_ARGB color = {1.0f, 1.0f, 1.0f, 1.0f};
    debug_draw_sphere(&this->pos, &color, 10.0f);
}

void TNeedleShoot::update_lifetime() {
    f32 travelled;

    travelled = distance;
    if (travelled > range) {
        TObject::queue_destruction();
        return;
    }
    distance = travelled + speed;
}

void TNeedleShoot::update_stopped() {
    queue_destruction();
}

#pragma push
#pragma fp_contract on
void TNeedleShoot::update_position() {
    VecCopy(&this->prev_pos, &this->pos);
    this->pos.x = (this->dir.x * speed) + this->pos.x;
    this->pos.y = (this->dir.y * speed) + this->pos.y;
    this->pos.z = (this->dir.z * speed) + this->pos.z;
    check_wall_hit();
}
#pragma pop

void TNeedleShoot::run_task() {
    if (active == 1) {
        update_position();
        update_lifetime();
        return;
    }
    update_stopped();
}

TNeedleShoot::~TNeedleShoot() {
    if (this->collider != NULL) { free_collision_body_parts(this->collider); this->collider = 0; }
}

TNeedleShoot::TNeedleShoot(s32 owner, Vec *from, Vec *to) : TObject(tl_06) {
    f32 dx;
    f32 dz;
    f32 dy;
    m_name = TNeedleShoot__name;
    owner_id = 0xFFFF;
    dx = to->x - from->x;
    dz = to->z - from->z;
    dy = to->y - from->y;
    pos.x = from->x;
    pos.y = from->y;
    pos.z = from->z;
    rotation_x = RADIANS_TO_ANGLE * atan2_float(fabs_float(dy), fabs_float(dz));
    rotation_y = RADIANS_TO_ANGLE * atan2_float(dx, dz);
    rotation_z = RADIANS_TO_ANGLE * atan2_float(dx, dy);
    pad_b4 = 4.0f;
    pad_88.x = 1.0f;
    pad_88.y = 1.0f;
    pad_88.z = 1.0f;
    distance = 0.0f;
    this->owner = owner;
    speed = 5.0f;
    range = 1000.0f;
    contact_mode = 0;
    active = 1;
    dir.x = dx;
    dir.y = dy;
    dir.z = dz;
    if (0.0f != vector_length(&dir)) {
        normalize_vector(&dir);
    }
    collision_body.offset.x = 0.0f;
    collision_body.offset.y = 0.0f;
    collision_body.offset.z = 0.0f;
    collision_body.radius = 5.0f;
    collision_body.half_width = 1.0f;
    collision_body.shape = 1;
    collision_body.flags = 0x40007;
    collider = new TObjCollidable(this);
    if (collider != NULL) {
        init_collision_body_parts(collider, &collision_body, 1);
    }
}

void TNeedleShoot::on_wall_hit() { TObject::queue_destruction(); }
void TNeedleShoot::queue_destruction() { TObject::queue_destruction(); }
void TNeedleShoot::on_target_hit(void *) {  }
