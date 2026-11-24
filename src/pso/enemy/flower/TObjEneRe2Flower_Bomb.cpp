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
#include "pso/system/MatrixOps.h"
#include "pso/math/AngleLookup.h"


extern "C" s32 is_area_attack_target_eligible(saddr, s32);

extern const DragonAttackParams flower_bomb_attack = { 0xF, 2.0f, 2.0f, { 0.0f, 1 } };
const char *TObjEneRe2Flower_Bomb::class_name = "TObjEneRe2Flower_Bomb";

// The bomb's first function: its 30.0 opens this file's literal pool at
// 0x805DA000, while the Flower file's pool already holds 30.0 at 0x805D9FEC.
s32 TObjEneRe2Flower_Bomb::area_attack_deliver_direct(void *recoil, saddr desc, void *object, f32 range) {
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
            if (obj_is_hit_receivable(reinterpret_cast<u8 *>(p)) != 0 && p != this->owner &&
                is_area_attack_target_eligible((saddr)this, p->actorFlags) != 0 &&
                !(fabs_float(start_position.y - p->body_center.y) > 30.0f)) {
                ok = 1;
                if (object != 0 && attack_target_history_add((AreaAttackHistory *)object, p) == 0) {
                    ok = 0;
                }
                if (ok != 0) {
                    this->area_attack_receive_direct(p, (f32 *)recoil, (void *)desc);
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
    Vec tmp;
    ParticleAngles rot;
    CsnHit *hit;
    f32 d;

    switch (state) {
    case 0:
        age++;
        if ((f32)age >= 150.0f) {
            queue_destruction();
            return;
        }
        if (age >= 0x12) {
            vertical_speed -= 0.1f;
        }
        VecCopy(&tmp, &start_position);
        vec3_add_to(&tmp, &probe_velocity);
        tmp.y += vertical_speed - 3.0f;
        if (csnVector(&start_position, &tmp, 0x1EFF) != 0) {
            queue_destruction();
            return;
        }
        start_position.x += velocity.x;
        start_position.y += vertical_speed;
        start_position.z += velocity.z;
        hit = csnVecterUnder(&start_position, 0x16EF);
        if (hit != NULL) {
            position.y = hit->contact->point.y;
            VecCopy(&ground_normal, &hit->contact->normal);
            has_ground = 1;
        } else {
            has_ground = 0;
        }
        position.x = start_position.x;
        position.z = start_position.z;
        d = start_position.y - position.y;
        if (d > 20.0f) {
            bodies->flags |= 4;
            bodies->flags &= ~2;
        } else {
            bodies->flags &= ~4;
            bodies->flags |= 2;
        }
        bodies->offset.y = d;
        if (age >= 0x14) {
            contact.contact_flags |= 2;
        }
        if (vfunc_16(&contact, const_cast<DragonAttackParams *>(&flower_bomb_attack)) != 0) {
            static_cast<TObjEneRe2Flower *>(find_entity_by_id(owner_id))->notify_bomb_hit();
            queue_destruction();
            return;
        }
    case 1:
        break;
    }
    if (effect == NULL) {
        rot.x = 0x8000;
        rot.y = heading;
        rot.z = 0;
        effect = static_cast<TParticleCtrl *>(spawn_particle_effect_with_rotation(&start_position, &rot, 0xD0, 0x40));
        if (effect != NULL) {
            effect->enable();
        }
    } else {
        effect->set_position(&start_position);
    }
}

TObjEneRe2Flower_Bomb::~TObjEneRe2Flower_Bomb() {
    if (effect != NULL) {
        effect->queue_destruction();
        effect = NULL;
    }
}

TObjEneRe2Flower_Bomb::TObjEneRe2Flower_Bomb(TObjEneRe2Flower *owner, const Vec *start, s32 heading)
    : TUnk_804928CC(owner, owner) {
    f32 s;
    f32 c;
    m_name = class_name;
    bodies->radius = flower_bomb_attack.radius;
    this->heading = heading;
    owner_id = owner->get_entity_id();
    VecCopy(&start_position, start);
    VecCopy(&position, &start_position);
    ground_normal.x = 0.0f;
    ground_normal.y = 0.0f;
    ground_normal.z = 0.0f;
    s = sin_table_lookup(this->heading);
    c = cos_table_lookup(this->heading);
    velocity.x = 4.0f * s;
    velocity.y = 0.0f;
    velocity.z = 4.0f * c;
    probe_velocity.x = 7.0f * s;
    probe_velocity.y = 0.0f;
    probe_velocity.z = 7.0f * c;
    contact.recoil = 0.0f;
    contact.contact_flags = 1;
    vertical_speed = 0.0f;
    age = 0;
    state = 0;
    effect = 0;
    has_ground = 1;
}
