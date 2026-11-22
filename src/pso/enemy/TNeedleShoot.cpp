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
        vfunc_6();
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

void TNeedleShoot::sub_802A4668() {
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
    if (m_b8 == 1) {
        update_position();
        update_lifetime();
        return;
    }
    sub_802A4668();
}

TNeedleShoot::~TNeedleShoot() {
    if (this->m_68 != NULL) { free_collision_body_parts(this->m_68); this->m_68 = 0; }
}

TNeedleShoot::TNeedleShoot(s32 owner, Vec *from, Vec *to) : TObject(tl_06) {
    f32 dx;
    f32 dz;
    f32 dy;
    m_name = TNeedleShoot__name;
    m_34 = 0xFFFF;
    dx = to->x - from->x;
    dz = to->z - from->z;
    dy = to->y - from->y;
    pos.x = from->x;
    pos.y = from->y;
    pos.z = from->z;
    m_a0 = RADIANS_TO_ANGLE * atan2_float(fabs_float(dy), fabs_float(dz));
    m_a4 = RADIANS_TO_ANGLE * atan2_float(dx, dz);
    m_a8 = RADIANS_TO_ANGLE * atan2_float(dx, dy);
    pad_b4 = 4.0f;
    pad_88.x = 1.0f;
    pad_88.y = 1.0f;
    pad_88.z = 1.0f;
    distance = 0.0f;
    m_1c = owner;
    speed = 5.0f;
    range = 1000.0f;
    m_b0 = 0;
    m_b8 = 1;
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
    m_68 = new TObjCollidable(this);
    if (m_68 != NULL) {
        init_collision_body_parts(m_68, &collision_body, 1);
    }
}

void TNeedleShoot::vfunc_6() { TObject::queue_destruction(); }
void TNeedleShoot::queue_destruction() { TObject::queue_destruction(); }
void TNeedleShoot::vfunc_9(void *) {  }
