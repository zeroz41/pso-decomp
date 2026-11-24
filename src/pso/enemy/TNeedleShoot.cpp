#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/vector.h"

#include <stddef.h>
#include "pso/enemy/TNeedleShoot.h"
#include "pso/technique/TechniqueContact.h"
#include "pso/unk/TLobby.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/player/TObjPlayer.h"
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

const char *TNeedleShoot::class_name = "TNeedleShoot";

TechniqueContactList technique_contact_list;

void TNeedleShoot::clear_technique_contacts() {
    for (s32 i = 0; i < 16; ++i) {
        technique_contact_list.actors[i] = 0;
        technique_contact_list.bodies[i] = 0;
    }
    technique_contact_list.count = 0;
}

s32 TNeedleShoot::is_hit_receivable_target(TObjCollidable *target) {
    if (target == NULL) {
        return FALSE;
    }
    return obj_is_hit_receivable(target) ? TRUE : FALSE;
}

TechniqueContactList *TNeedleShoot::collect_contacts(TObjBase *src) {
    Vec a;
    Vec d;
    Vec *sd;
    TObjCollidable *p;
    s32 i;
    CollisionBody *r;
    VecCopy(&a, &pos);
    clear_technique_contacts();
    if (collider == 0) return &technique_contact_list;
    sd = get_shoot_data();
    d.x = a.x - sd->x;
    d.y = a.y - sd->y;
    d.z = a.z - sd->z;
    vector_length(&d);
    a.x = 0.5f * (a.x + sd->x);
    a.y = 0.5f * (a.y + sd->y);
    a.z = 0.5f * (a.z + sd->z);
    VecCopy(&collider->position, &a);
    copy_xyz(&collider->rotation_x, &rotation_x);
    for (i = 0; i < TLobby::get_lobby_flag(); i++) {
        p = TObjPlayer::get_player_data(i);
        if (p == 0) continue;
        if ((p->actorFlags & 0x20000000) || (p->actorFlags & 0x10000000)) {
            if ((u16)p->get_entity_id() == (u16)src->get_entity_id()) continue;
            r = collider->find_actor_body_contact(p, 10000.0f);
            if (r == 0) continue;
            technique_contact_list.bodies[technique_contact_list.count] = r;
            technique_contact_list.actors[technique_contact_list.count] = p;
            if (++technique_contact_list.count >= 0x10) {
                technique_contact_list.count = 0xF;
                break;
            }
        } else if ((p->actorFlags & 0x40000000) && !(p->actorFlags & 0x80000000)) {
            if (collider->find_actor_body_contact(p, 10000.0f) != 0) return 0;
        }
    }
    return &technique_contact_list;
}

TechniqueContactList *TNeedleShoot::collect_contacts_from_game_mode(TObjBase *src) {
    Vec a;
    Vec d;
    s32 i;
    Vec *sd;
    TObjCollidable *p;
    CollisionBody *r;
    VecCopy(&a, &pos);
    clear_technique_contacts();
    if (collider == 0) return &technique_contact_list;
    sd = get_shoot_data();
    d.x = a.x - sd->x;
    d.y = a.y - sd->y;
    d.z = a.z - sd->z;
    vector_length(&d);
    a.x = 0.5f * (a.x + sd->x);
    a.y = 0.5f * (a.y + sd->y);
    a.z = 0.5f * (a.z + sd->z);
    VecCopy(&collider->position, &a);
    copy_xyz(&collider->rotation_x, &rotation_x);
    for (i = TLobby::get_game_mode(); i < TLobby::get_lobby_flag(); i++) {
        p = TObjPlayer::get_player_data(i);
        if (p == 0) continue;
        if (p->actorFlags & 0x20000000) {
            if ((u16)p->get_entity_id() != (u16)src->get_entity_id()) {
                r = collider->find_actor_body_contact(p, 10000.0f);
                if (r != 0) {
                    technique_contact_list.bodies[technique_contact_list.count] = r;
                    technique_contact_list.actors[technique_contact_list.count] = p;
                    if (++technique_contact_list.count >= 0x10) {
                        technique_contact_list.count = 0xF;
                        break;
                    }
                }
            }
        } else if ((p->actorFlags & 0x40000000) && !(p->actorFlags & 0x80000000)) {
            if (collider->find_actor_body_contact(p, 10000.0f) != 0) return 0;
        }
    }
    return &technique_contact_list;
}

TechniqueContactList *TNeedleShoot::collect_technique_contacts(TObjBase *src) {
    Vec a;
    Vec d;
    Vec *sd;
    TObjCollidable *p;
    s32 i;
    s32 n;
    CollisionBody *r;
    VecCopy(&a, &pos);
    clear_technique_contacts();
    if (collider == 0) return &technique_contact_list;
    sd = get_shoot_data();
    d.x = a.x - sd->x;
    d.y = a.y - sd->y;
    d.z = a.z - sd->z;
    vector_length(&d);
    a.x = 0.5f * (a.x + sd->x);
    a.y = 0.5f * (a.y + sd->y);
    a.z = 0.5f * (a.z + sd->z);
    VecCopy(&collider->position, &a);
    copy_xyz(&collider->rotation_x, &rotation_x);
    if ((u16)src->get_entity_id() < 4) {
        n = TLobby::get_lobby_flag();
        for (i = 0; i < n; i++) {
            p = TObjPlayer::get_player_data(i);
            if (p == 0) continue;
            if ((u16)p->get_entity_id() == (u16)src->get_entity_id()) continue;
            r = collider->find_actor_body_contact(p, 10000.0f);
            if (r == 0) continue;
            if ((p->actorFlags & 0x20000000) || (p->actorFlags & 0x10000000)) {
                technique_contact_list.bodies[technique_contact_list.count] = r;
                technique_contact_list.actors[technique_contact_list.count] = p;
                if (++technique_contact_list.count >= 0x10) {
                    technique_contact_list.count = 0xF;
                    break;
                }
            }
        }
    } else {
        s32 j;
        for (j = 0; j < 4; j++) {
            p = find_entity_by_id(j);
            if (p == 0) continue;
            if ((u16)p->get_entity_id() == (u16)src->get_entity_id()) continue;
            r = collider->find_actor_body_contact(p, 10000.0f);
            if (r == 0) continue;
            if (p->actorFlags & 0x10000000) {
                technique_contact_list.bodies[technique_contact_list.count] = r;
                technique_contact_list.actors[technique_contact_list.count] = p;
                if (++technique_contact_list.count >= 0x10) {
                    technique_contact_list.count = 0xF;
                    break;
                }
            }
        }
    }
    return &technique_contact_list;
}

#pragma push
#pragma scheduling off
#pragma global_optimizer off
void TNeedleShoot::check_target_hit(s32) {
    TechniqueContactList *list;
    if (this->collider == 0) {
        TObject::queue_destruction();
        return;
    }
    switch (this->contact_mode) {
    case 1:
        list = collect_technique_contacts(owner);
        break;
    case 2:
        list = collect_contacts_from_game_mode(owner);
        break;
    default: {
        TObjBase *source = owner;
        list = collect_contacts(source);
        break;
    }
    }
    if (list == NULL) {
        this->on_wall_hit();
    } else if (is_hit_receivable_target(list->actors[0])) {
        TObjCollidable *target = list->actors[0];
        if (target != NULL) {
            CollisionBody *body = list->bodies[0];
            this->on_target_hit((this->contact_body = body, static_cast<TObjCollidable *>(target)));
        }
    }
}
#pragma pop

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

TNeedleShoot::TNeedleShoot(TObjBase *owner, Vec *from, Vec *to) : TObject(tl_06) {
    f32 dx;
    f32 dz;
    f32 dy;
    m_name = class_name;
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
    this->owner = (TObjBase *)owner;
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
void TNeedleShoot::on_target_hit(TObjCollidable *) {  }
