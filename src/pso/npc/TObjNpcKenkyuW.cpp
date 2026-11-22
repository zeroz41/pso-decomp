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

#pragma readonly_strings on

__declspec(section ".data") const char *bm_npc_kenkyu_w_model_names[2] = {"kenkyu_w_hone_body.nj", NULL};
const char *bm_npc_kenkyu_w_motion_names[] = {NULL};
BmlResourceDescriptor bm_npc_kenkyu_w_resource_descriptor = {
    "bm_npc_kenkyu_w.bml", bm_npc_kenkyu_w_model_names, bm_npc_kenkyu_w_motion_names, 1, 0,
};
const char *TObjNpcKenkyuW__name = "TObjNpcKenkyuW";
TechniqueContactList technique_contact_list;
BmlResource *TObjNpcKenkyuW__model_resource;

struct Pl_802A3DE8 {
    u8 pad0[0x30];
    u32 flags;
};

struct Obj_802A3DE8 {
    u8 pad0[0x68];
    u8 *body;
    Vec pos;
    u8 pad78[0xA0 - 0x78];
    Vec fA0;
};

struct Pl_802A41CC {
    u8 pad0[0x30];
    u32 flags;
};

struct Obj_802A41CC {
    u8 pad0[0x68];
    u8 *body;
    Vec pos;
    u8 pad78[0xA0 - 0x78];
    Vec fA0;
};

struct Pl_802A3FDC {
    u8 pad0[0x30];
    u32 flags;
};

struct Obj_802A3FDC {
    u8 pad0[0x68];
    u8 *body;
    Vec pos;
    u8 pad78[0xA0 - 0x78];
    Vec fA0;
};

extern "C" {


s32 obj_is_hit_receivable(u8 *arg0);
s32 get_entity_id(void *);
TechniqueContactList *TObjPlayer__sub_802A3DE8(Obj_802A3DE8 *self, void *src);
TechniqueContactList *TObjPlayer__sub_802A3FDC(Obj_802A3FDC *self, void *src);
void TObjPlayer__sub_802A445C(TNeedleShoot *self, int arg1);

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
    texlist = (saddr)get_bml_texlist(TObjNpcKenkyuW__model_resource, 0);
    ((TObjNpcBase *)this)->setup_common();
}

void clear_technique_contacts__10TObjPlayerFv() {
    for (s32 i=0;i<16;++i) {
        technique_contact_list.actors[i]=0;
        technique_contact_list.bodies[i]=0;
    }
    technique_contact_list.count=0;
}

s32 TObjPlayer::is_hit_receivable_target(saddr arg0, uaddr target) {
    if (target == 0U) {
        return FALSE;
    }
    return obj_is_hit_receivable((u8 *)target) ? TRUE : FALSE;
}
#define L_802A3DE8 technique_contact_list
TechniqueContactList *TObjPlayer__sub_802A3DE8(Obj_802A3DE8 *self, void *src) {
    Vec a;
    Vec d;
    Vec *sd;
    Pl_802A3DE8 *p;
    s32 i;
    TechniqueContactBody *r;
    VecCopy((Vec *)&a, (const Vec *)&self->pos);
    ((void (*)(void *))clear_technique_contacts__10TObjPlayerFv)(self);
    if (self->body == 0) return &L_802A3DE8;
    sd = (Vec *)((TNeedleShoot *)self)->get_shoot_data();
    d.x = a.x - sd->x;
    d.y = a.y - sd->y;
    d.z = a.z - sd->z;
    vector_length(&d);
    a.x = 0.5f * (a.x + sd->x);
    a.y = 0.5f * (a.y + sd->y);
    a.z = 0.5f * (a.z + sd->z);
    VecCopy((Vec *)(self->body + 0x38), (const Vec *)&a);
    copy_xyz(self->body + 0x5C, &self->fA0);
    for (i = 0; i < TLobby::get_lobby_flag(); i++) {
        p = (Pl_802A3DE8 *)TObjPlayer::get_player_data(i);
        if (p == 0) continue;
        if ((p->flags & 0x20000000) || (p->flags & 0x10000000)) {
            if ((u16)get_entity_id(p) == (u16)get_entity_id(src)) continue;
            r = (TechniqueContactBody *)((TObjCollidable *)((u8 *)self->body))->find_actor_body_contact((u8 *)p, 10000.0f);
            if (r == 0) continue;
            L_802A3DE8.bodies[L_802A3DE8.count] = r;
            L_802A3DE8.actors[L_802A3DE8.count] = (TechniqueContactActor *)p;
            if (++L_802A3DE8.count >= 0x10) {
                L_802A3DE8.count = 0xF;
                break;
            }
        } else if ((p->flags & 0x40000000) && !(p->flags & 0x80000000)) {
            if (((TObjCollidable *)((u8 *)self->body))->find_actor_body_contact((u8 *)p, 10000.0f) != 0) return 0;
        }
    }
    return &L_802A3DE8;
}
struct Pl_802A3DE8;
#define L_802A41CC technique_contact_list

#define L_802A3FDC technique_contact_list
TechniqueContactList *TObjPlayer__sub_802A3FDC(Obj_802A3FDC *self, void *src) {
    Vec a;
    Vec d;
    s32 i;
    Vec *sd;
    u32 id;
    Pl_802A3FDC *p;
    TechniqueContactBody *r;
    VecCopy((Vec *)&a, (const Vec *)&self->pos);
    ((void (*)(void *))clear_technique_contacts__10TObjPlayerFv)(self);
    if (self->body == 0) return &L_802A3FDC;
    sd = ((Vec *)((TNeedleShoot *)self)->get_shoot_data());
    d.x = a.x - sd->x;
    d.y = a.y - sd->y;
    d.z = a.z - sd->z;
    vector_length(&d);
    a.x = 0.5f * (a.x + sd->x);
    a.y = 0.5f * (a.y + sd->y);
    a.z = 0.5f * (a.z + sd->z);
    VecCopy((Vec *)(self->body + 0x38), (const Vec *)&a);
    copy_xyz(self->body + 0x5C, &self->fA0);
    for (i = TLobby::get_game_mode(); i < TLobby::get_lobby_flag(); i++) {
        p = ((Pl_802A3FDC *)TObjPlayer::get_player_data(i));
        if (p == 0) continue;
        if (p->flags & 0x20000000) {
            if ((u16)get_entity_id(p) != (u16)get_entity_id(src)) {
                r = (TechniqueContactBody *)((TObjCollidable *)((u8 *)self->body))->find_actor_body_contact((u8 *)p, 10000.0f);
                if (r != 0) {
                    L_802A3FDC.bodies[L_802A3FDC.count] = r;
                    L_802A3FDC.actors[L_802A3FDC.count] = (TechniqueContactActor *)p;
                    if (++L_802A3FDC.count >= 0x10) {
                        L_802A3FDC.count = 0xF;
                        break;
                    }
                }
            }
        } else if ((p->flags & 0x40000000) && !(p->flags & 0x80000000)) {
            if (((TObjCollidable *)((u8 *)self->body))->find_actor_body_contact((u8 *)p, 10000.0f) != 0) return 0;
        }
    }
    return &L_802A3FDC;
}

TechniqueContactList *TObjPlayer::collect_technique_contacts(void *src) {
    Vec a;
    Vec d;
    Vec *sd;
    Pl_802A41CC *p;
    s32 i;
    s32 n;
    TechniqueContactBody *r;
    VecCopy((Vec *)&a, (const Vec *)(&((Obj_802A41CC *)this)->pos));
    ((void (*)(void *))clear_technique_contacts__10TObjPlayerFv)(this);
    if (((Obj_802A41CC *)this)->body == 0) return &L_802A41CC;
    sd = (Vec *)((TNeedleShoot *)this)->get_shoot_data();
    d.x = a.x - sd->x;
    d.y = a.y - sd->y;
    d.z = a.z - sd->z;
    vector_length(&d);
    a.x = 0.5f * (a.x + sd->x);
    a.y = 0.5f * (a.y + sd->y);
    a.z = 0.5f * (a.z + sd->z);
    VecCopy((Vec *)(((Obj_802A41CC *)this)->body + 0x38), (const Vec *)&a);
    copy_xyz(((Obj_802A41CC *)this)->body + 0x5C, &((Obj_802A41CC *)this)->fA0);
    if ((u16)get_entity_id(src) < 4) {
        n = TLobby::get_lobby_flag();
        for (i = 0; i < n; i++) {
            p = (Pl_802A41CC *)TObjPlayer::get_player_data(i);
            if (p == 0) continue;
            if ((u16)get_entity_id(p) == (u16)get_entity_id(src)) continue;
            r = (TechniqueContactBody *)((TObjCollidable *)(((Obj_802A41CC *)this)->body))->find_actor_body_contact((u8 *)p, 10000.0f);
            if (r == 0) continue;
            if ((p->flags & 0x20000000) || (p->flags & 0x10000000)) {
                L_802A41CC.bodies[L_802A41CC.count] = r;
                L_802A41CC.actors[L_802A41CC.count] = (TechniqueContactActor *)p;
                if (++L_802A41CC.count >= 0x10) {
                    L_802A41CC.count = 0xF;
                    break;
                }
            }
        }
    } else {
        s32 j;
        for (j = 0; j < 4; j++) {
            p = (Pl_802A41CC *)find_entity_by_id(j);
            if (p == 0) continue;
            if ((u16)get_entity_id(p) == (u16)get_entity_id(src)) continue;
            r = (TechniqueContactBody *)((TObjCollidable *)(((Obj_802A41CC *)this)->body))->find_actor_body_contact((u8 *)p, 10000.0f);
            if (r == 0) continue;
            if (p->flags & 0x10000000) {
                L_802A41CC.bodies[L_802A41CC.count] = r;
                L_802A41CC.actors[L_802A41CC.count] = (TechniqueContactActor *)p;
                if (++L_802A41CC.count >= 0x10) {
                    L_802A41CC.count = 0xF;
                    break;
                }
            }
        }
    }
    return &L_802A41CC;
}


#pragma push
#pragma scheduling off
#pragma global_optimizer off
void TObjPlayer__sub_802A445C(TNeedleShoot *self, int arg1) {
    TechniqueContactList *list;
    if (self->m_68 == 0) {
        self->TObject::queue_destruction();
        return;
    }
    switch (self->m_b0) {
    case 1:
        list = ((TObjPlayer *)self)->collect_technique_contacts((void *)self->m_1c);
        break;
    case 2:
        list = TObjPlayer__sub_802A3FDC((Obj_802A3FDC *)self, (void *)self->m_1c);
        break;
    default: {
        void *source = (void *)self->m_1c;
        list = TObjPlayer__sub_802A3DE8((Obj_802A3DE8 *)self, source);
        break;
    }
    }
    if (list == NULL) {
        self->vfunc_6();
    } else if (TObjPlayer::is_hit_receivable_target((saddr)self, (uaddr)list->actors[0])) {
        TechniqueContactActor *target = list->actors[0];
        if (target != NULL) {
            TechniqueContactBody *body = list->bodies[0];
            self->vfunc_9((self->m_38 = body, static_cast<TechniqueContactActor *>(target)));
        }
    }
}
#pragma pop
