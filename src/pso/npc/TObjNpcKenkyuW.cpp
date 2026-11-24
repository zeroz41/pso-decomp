#include "pso/player/TObjPlayer_80011014.h"
#include "pso/object/base/HitEligibility.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlAccessors.h"
#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/npc/TUnk_804A9F50.h"
#include "pso/npc/TObjNpcKenkyuW.h"
#include "pso/system/vector.h"
#include "pso/player/TObjPlayer.h"

#include "pso/enemy/TNeedleShoot.h"


#include "pso/technique/TechniqueContact.h"

#include "pso/unk/TLobby.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcLappy.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

#include "pso/system/BmlResourceDescriptor.h"
#include "pso/math/MatrixVector.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/object/base/TObjBase.h"

#pragma readonly_strings on

__declspec(section ".data") const char *bm_npc_kenkyu_w_model_names[2] = {"kenkyu_w_hone_body.nj", NULL};
const char *bm_npc_kenkyu_w_motion_names[] = {NULL};
BmlResourceDescriptor bm_npc_kenkyu_w_resource_descriptor = {
    "bm_npc_kenkyu_w.bml", bm_npc_kenkyu_w_model_names, bm_npc_kenkyu_w_motion_names, 1, 0,
};
const char *TObjNpcKenkyuW__name = "TObjNpcKenkyuW";
TechniqueContactList technique_contact_list;
BmlResource *TObjNpcKenkyuW__model_resource;

extern "C" {

void TObjNpcKenkyuW::destroy_instance() {
    if (TObjNpcKenkyuW__model_resource != NULL) {
        delete TObjNpcKenkyuW__model_resource;
        TObjNpcKenkyuW__model_resource = NULL;
    }
}

void TObjNpcKenkyuW::load_resource_instance() {
    TObjNpcKenkyuW__model_resource = new BmlResource(1, &bm_npc_kenkyu_w_resource_descriptor, 0, 0, NULL);
}

}
TObjNpcKenkyuW::~TObjNpcKenkyuW() {}


TObjNpcKenkyuW::TObjNpcKenkyuW(TObject *parent, void *arg2) : TUnk_804A9F50(parent) {
    ((TObject *)this)->m_name = TObjNpcKenkyuW__name;
    ((TObjNpcKenkyuW *)this)->apply_set_data(arg2);
    init_position_vectors();
    model = get_bml_model(TObjNpcKenkyuW__model_resource, 0);
    texlist = get_bml_texlist(TObjNpcKenkyuW__model_resource, 0);
    ((TObjNpcBase *)this)->setup_common();
}

void TNeedleShoot::clear_technique_contacts() {
    for (s32 i=0;i<16;++i) {
        technique_contact_list.actors[i]=0;
        technique_contact_list.bodies[i]=0;
    }
    technique_contact_list.count=0;
}

s32 TNeedleShoot::is_hit_receivable_target(TObjCollidable *target) {
    if (target == NULL) {
        return FALSE;
    }
    return obj_is_hit_receivable(target) ? TRUE : FALSE;
}
TechniqueContactList *TNeedleShoot::collect_technique_contacts_default(TObjBase *src) {
    Vec a;
    Vec d;
    Vec *sd;
    TObjCollidable *p;
    s32 i;
    CollisionBody *r;
    VecCopy(&a, &pos);
    clear_technique_contacts();
    if (collider == NULL) return &technique_contact_list;
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
            r = (CollisionBody *)collider->find_actor_body_contact(p, 10000.0f);
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

TechniqueContactList *TNeedleShoot::collect_technique_contacts_mode_two(TObjBase *src) {
    Vec a;
    Vec d;
    s32 i;
    Vec *sd;
    u32 id;
    TObjCollidable *p;
    CollisionBody *r;
    VecCopy(&a, &pos);
    clear_technique_contacts();
    if (collider == NULL) return &technique_contact_list;
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
                r = (CollisionBody *)collider->find_actor_body_contact(p, 10000.0f);
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
    if (collider == NULL) return &technique_contact_list;
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
            r = (CollisionBody *)collider->find_actor_body_contact(p, 10000.0f);
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
            r = (CollisionBody *)collider->find_actor_body_contact(p, 10000.0f);
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
        list = collect_technique_contacts_mode_two(owner);
        break;
    default: {
        TObjBase *source = owner;
        list = collect_technique_contacts_default(source);
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
