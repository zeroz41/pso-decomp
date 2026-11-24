#include "pso/map/CsnQuery.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/enemy/flower/TObjEneRe2Flower.h"
#include "types.h"
#include "pso/system/vector.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/enemy/flower/TObjEneRe2Flower_EffCurse3.h"
#include "pso/enemy/TUnk_80493450.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TUnk_804928CC.h"
#include "pso/enemy/flower/TObjEneRe2Flower_Bomb.h"
#include "pso/enemy/flower/TObjEneRe2Flower.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/DragonAttackParams.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/enemy/beast/TObjEneBeast.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/boss/goldragon/TBoss8Dragon_800BC53C.h"
#include "pso/map/CsnGroundQuery.h"
#include "pso/object/base/TObjBase.h"
#include "pso/object/base/CollisionActorLookup.h"


typedef struct Ent_800C4B78 {
    u8 pad0[0x38];
    Vec pos;
} Ent_800C4B78;

typedef struct Obj_800C4B78 {
    u8 pad0[0x1C];
    s32 timer;
    Ent_800C4B78 *target;
    s32 effect;
} Obj_800C4B78;

typedef struct Obj_800C55E0 {
    u8 pad0[0xB8];
    s16 fB8;
    u8 padBA[0x326 - 0xBA];
    s16 state;
    s16 f328;
    u8 pad32A[0x34C - 0x32A];
    void *f34C;
} Obj_800C55E0;

extern "C" {
s32 vec3_add_to(void *, void *);
s32 is_area_attack_target_eligible(saddr, s32);

u8 *__ct__13TUnk_804928CCFP7TObjectP8TObjBase(u8 *arg0, s32 arg1, u32 arg2);
f32 sin_table_lookup(int);
f32 cos_table_lookup(int);
void *destroy_and_free__21TObjEneRe2Flower_BombFs(void *arg0, s16 arg1);
void render__21TObjEneRe2Flower_BombFv(u8 *arg0);

}

typedef struct Rot_800C4754 {
    s32 x, y, z;
} Rot_800C4754;

extern "C" {


void vfunc_6__8TObjBaseFPsl();
void interact__14TObjCollidableFUs();
void call_vt16_with_default__13TUnk_804928CCFPvPv();
void vfunc_16__13TUnk_804928CCFPvPv();
void call_vt13_with_default__13TUnk_804928CCFPvPvl();
void get_name__8TObjBaseFv();
void get_center__8TObjBaseFv();
void apply_hit_if_active__13TUnk_804928CCFPvPf();
void apply_object_set_data__8TObjBaseFPv();
void area_attack_apply_recoil__13TUnk_804928CCFPvf();
void area_attack_deliver_physical__13TUnk_804928CCFPvPvf();
void area_attack_receive_direct__13TUnk_804928CCFPvPfPv();
void classify_actor_view_detail__8TObjBaseFfff();
void vfunc_19__13TUnk_804928CCFPv();
void area_attack_deliver_direct__21TObjEneRe2Flower_BombFPvlPvf();
void reset_motion_fields__14TObjCollidableFv();
void render_shadows__7TObjectFv();
void update_object_view_visibility__8TObjBaseFff();
void run_task__21TObjEneRe2Flower_BombFv(TObjEneRe2Flower_Bomb *o);
extern const DragonAttackParams lbl_8043BC10 = { 0xF, 2.0f, 2.0f, { 0.0f, 1 } };
extern const char lbl_8043BC24[] = "TObjEneRe2Flower_Bomb";
s32 lbl_805D2A50 = (saddr)lbl_8043BC24;
void *lbl_804933D8[24] = {
    (void *)0x0, (void *)0x0, (void *)&destroy_and_free__21TObjEneRe2Flower_BombFs, (void *)&run_task__21TObjEneRe2Flower_BombFv,
    (void *)&render__21TObjEneRe2Flower_BombFv, (void *)&render_shadows__7TObjectFv, (void *)&vfunc_6__8TObjBaseFPsl, (void *)&apply_object_set_data__8TObjBaseFPv,
    (void *)&reset_motion_fields__14TObjCollidableFv, (void *)&get_center__8TObjBaseFv, (void *)&update_object_view_visibility__8TObjBaseFff, (void *)&classify_actor_view_detail__8TObjBaseFfff,
    (void *)&get_name__8TObjBaseFv, (void *)&interact__14TObjCollidableFUs, (void *)&call_vt13_with_default__13TUnk_804928CCFPvPvl, (void *)&area_attack_deliver_direct__21TObjEneRe2Flower_BombFPvlPvf,
    (void *)&vfunc_16__13TUnk_804928CCFPvPv, (void *)&call_vt16_with_default__13TUnk_804928CCFPvPv, (void *)&area_attack_deliver_physical__13TUnk_804928CCFPvPvf, (void *)&vfunc_19__13TUnk_804928CCFPv,
    (void *)&area_attack_apply_recoil__13TUnk_804928CCFPvf, (void *)&area_attack_receive_direct__13TUnk_804928CCFPvPfPv, (void *)&apply_hit_if_active__13TUnk_804928CCFPvPf, (void *)0x0,
};

// The bomb's first function: its 30.0 opens this file's literal pool at
// 0x805DA000, while the Flower file's pool already holds 30.0 at 0x805D9FEC.
s32 TObjEneRe2Flower_Bomb::area_attack_deliver_direct(void *recoil, saddr arg2, void *object, f32 range) {
    s32 result;
    s32 flags;
    TObjChara *p;
    s32 i;
    s32 ok;
    result = 0;
    flags = 0;
    if (this->owner == 0) {
        return 0;
    }
    TObjPlayer::init_all_slots();
    if (static_cast<AreaAttackContact *>(recoil)->contact_flags & 1) {
        this->update_body_contact_flag(range);
        flags |= 0x80000;
    }
    if (static_cast<AreaAttackContact *>(recoil)->contact_flags & 2) {
        this->mark_enemy_body_contacts();
        flags |= 0x100000;
    }
    if (this->bodies->flags & flags) {
        for (i = 0; i < 0x10; i++) {
            p = reinterpret_cast<TObjChara *>(TObjPlayer::get_battle_param(i));
            if (p == 0) {
                break;
            }
            if (obj_is_hit_receivable(p) != 0 && p != this->owner &&
                is_area_attack_target_eligible((saddr)this, p->actorFlags) != 0 &&
                !(fabs_float(start_position.y - p->body_center.y) > 30.0f)) {
                ok = 1;
                if (object != 0 && attack_target_history_add((AreaAttackHistory *)object, p) == 0) {
                    ok = 0;
                }
                if (ok != 0) {
                    this->area_attack_receive_direct(p, (f32 *)((u8 *)recoil), (void *)arg2);
                    result = 1;
                }
            }
        }
    }
    return result;
}


void TObjEneRe2Flower_Bomb::render() {
    if (has_ground != 0) {
        TObjEneDD::draw_oriented_shadow(&position, &ground_normal, 0, NULL);
    }
}
void TObjEneRe2Flower_Bomb::run_task() {
    TObjEneRe2Flower_Bomb *o = this;
    Vec tmp;
    Rot_800C4754 rot;
    CsnHit *hit;
    f32 d;

    switch (o->state) {
    case 0:
        o->age++;
        if ((f32)o->age >= (1.5e+02f)) {
            o->queue_destruction();
            return;
        }
        if (o->age >= 0x12) {
            o->vertical_speed -= (0.1f);
        }
        VecCopy(&tmp, &o->start_position);
        vec3_add_to(&tmp, &o->probe_velocity);
        tmp.y += o->vertical_speed - (3.0f);
        if (csnVector(&o->start_position, &tmp, 0x1EFF) != 0) {
            o->queue_destruction();
            return;
        }
        o->start_position.x += o->velocity.x;
        o->start_position.y += o->vertical_speed;
        o->start_position.z += o->velocity.z;
        hit = csnVecterUnder(&o->start_position, 0x16EF);
        if (hit != NULL) {
            o->position.y = hit->contact->point.y;
            VecCopy(&o->ground_normal, &hit->contact->normal);
            o->has_ground = 1;
        } else {
            o->has_ground = 0;
        }
        o->position.x = o->start_position.x;
        o->position.z = o->start_position.z;
        d = o->start_position.y - o->position.y;
        if (d > (2e+01f)) {
            o->bodies->flags |= 4;
            o->bodies->flags &= ~2;
        } else {
            o->bodies->flags &= ~4;
            o->bodies->flags |= 2;
        }
        o->bodies->offset.y = d;
        if (o->age >= 0x14) {
            o->contact.contact_flags |= 2;
        }
        if (o->vfunc_16(&o->contact, const_cast<DragonAttackParams *>(&lbl_8043BC10)) != 0) {
            static_cast<TObjEneRe2Flower *>(find_entity_by_id(o->owner_id))->notify_bomb_hit();
            o->queue_destruction();
            return;
        }
    case 1:
        break;
    }
    if (o->effect == NULL) {
        rot.x = 0x8000;
        rot.y = o->heading;
        rot.z = 0;
        o->effect = static_cast<TParticleCtrl *>(spawn_particle_effect_with_rotation(&o->start_position, &rot, 0xD0, 0x40));
        if (o->effect != NULL) {
            o->effect->enable();
        }
    } else {
        o->effect->set_position(&o->start_position);
    }
}

void *TObjEneRe2Flower_Bomb::destroy_and_free(s16 arg1) {
    if (this != NULL) {
        *(void ***)((s8 *)this + 0x18) = lbl_804933D8;
        if (effect != NULL) {
            effect->queue_destruction();
            effect = NULL;
        }
        __dt__13TUnk_804928CCFv(this, 0);
        if (arg1 > 0) {
            TObject::operator delete(this);
        }
    }
    return this;
}

TObjEneRe2Flower_Bomb *TObjPlayer__sub_800C4A5C(TObjEneRe2Flower_Bomb *o, TObjEneRe2Flower *owner, const Vec *start, s32 angle) {
    f32 s;
    f32 c;
    __ct__13TUnk_804928CCFP7TObjectP8TObjBase((u8 *)o, reinterpret_cast<saddr>(owner), reinterpret_cast<uaddr>(owner));
    *reinterpret_cast<void ***>(reinterpret_cast<u8 *>(o) + 0x18) = lbl_804933D8;
    o->m_name = reinterpret_cast<const char *>(lbl_805D2A50);
    o->bodies->radius = lbl_8043BC10.radius;
    o->heading = angle;
    o->owner_id = static_cast<TObjBase *>(owner)->get_entity_id();
    VecCopy(&o->start_position, start);
    VecCopy(&o->position, &o->start_position);
    o->ground_normal.x = (0.0f);
    o->ground_normal.y = (0.0f);
    o->ground_normal.z = (0.0f);
    s = sin_table_lookup(o->heading);
    c = cos_table_lookup(o->heading);
    o->velocity.x = (4.0f) * s;
    o->velocity.y = (0.0f);
    o->velocity.z = (4.0f) * c;
    o->probe_velocity.x = (7.0f) * s;
    o->probe_velocity.y = (0.0f);
    o->probe_velocity.z = (7.0f) * c;
    o->contact.recoil = (0.0f);
    o->contact.contact_flags = 1;
    o->vertical_speed = (0.0f);
    o->age = 0;
    o->state = 0;
    o->effect = 0;
    o->has_ground = 1;
    return o;
}

}
