#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TUnk_804928CC.h"
#include "pso/enemy/mericarol/TObjEneBm9Mericarol_Bomb.h"
#include "pso/boss/goldragon/TBoss8Dragon_800BC53C.h"
#include "pso/system/vector.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/unk/text_800BC4C8.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/mericarol/TObjEneBm9Mericarol.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/math/MatrixVector.h"
#include "pso/map/CsnQuery.h"
#include "pso/system/MatrixOps.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/object/base/TObjBase.h"

const char *TObjEneBm9Mericarol_Bomb__class_name = "TObjEneBm9Mericarol_Bomb";

extern "C" s32 is_area_attack_target_eligible(void *, u32);

s32 TObjEneBm9Mericarol_Bomb::area_attack_deliver_direct(void *recoil, saddr desc, void *object, f32 range) {
    s32 hit;
    u32 mask;
    TObjChara *obj;
    s32 i;
    s32 ok;
    hit = 0;
    mask = 0;
    if (this->owner == 0) {
        return 0;
    }
    TObjPlayer::init_all_slots();
    if (static_cast<AreaAttackContact *>(recoil)->contact_flags & 1) {
        update_body_contact_flag(range);
        mask |= 0x80000;
    }
    if (static_cast<AreaAttackContact *>(recoil)->contact_flags & 2) {
        mark_enemy_body_contacts();
        mask |= 0x100000;
    }
    if (this->bodies->flags & mask) {
        for (i = 0; i < 0x10; i++) {
            obj = reinterpret_cast<TObjChara *>(TObjPlayer::get_battle_param(i));
            if (obj == 0) {
                break;
            }
            if (obj_is_hit_receivable(obj) != 0 && obj != this->owner &&
                is_area_attack_target_eligible(this, obj->actorFlags) != 0 &&
                !(fabs_float(pos.y - obj->body_center.y) > 3e+01f)) {
                ok = 1;
                if (object != 0 && attack_target_history_add((AreaAttackHistory *)object, obj) == 0) {
                    ok = 0;
                }
                if (ok != 0) {
                    area_attack_receive_direct(obj, (f32 *)recoil, (void *)desc);
                    hit = 1;
                }
            }
        }
    }
    return hit;
}

void TObjEneBm9Mericarol_Bomb::render() {
    if (shadow_visible != 0) {
        TObjEneDD::draw_oriented_shadow(&position, &ground_normal, 0, NULL);
    }
}


void TObjEneBm9Mericarol_Bomb::run_task() {
    Vec v;
    ParticleAngles r1;
    ParticleAngles r2;
    CsnHit *hit;
    f32 d;
    switch (state) {
    case 0:
        age++;
        if ((f32)age >= 1.5e+02f) {
            queue_destruction();
            return;
        }
        fall_speed -= 0.15f;
        VecCopy(&v, &pos);
        vec3_add_to(&v, &look_ahead);
        v.y += fall_speed - 3.0f;
        if (csnVector(&pos, &v, 0x1EFF) != 0) {
            queue_destruction();
            return;
        }
        pos.x += velocity.x;
        pos.y += velocity.y;
        pos.z += velocity.z;
        hit = csnVecterUnder(&pos, 0x16EF);
        if (hit != NULL) {
            position.y = hit->contact->point.y;
            VecCopy(&ground_normal, &hit->contact->normal);
            shadow_visible = 1;
        } else {
            shadow_visible = 0;
        }
        position.x = pos.x;
        position.z = pos.z;
        d = pos.y - position.y;
        if (d > 2e+01f) {
            bodies->flags |= 4;
            bodies->flags &= ~2;
        } else {
            bodies->flags &= ~4;
            bodies->flags |= 2;
        }
        bodies->offset.y = d;
        if (this->vfunc_16(&this->contact, &this->attack_type) != 0) {
            ((TObjEneBm9Mericarol *)(find_entity_by_id(owner_id)))->notify_bomb_hit();
            if (attack_type == 0 && this->final_blast != 0) {
                attack_type = 0x12;
                this->vfunc_16(&this->contact, &this->attack_type);
            }
            queue_destruction();
            return;
        }
    case 1:
    default:
        if (effect == NULL) {
            r1.x = 0;
            r1.y = this->m_ec + 0x4000;
            r1.z = 0;
            effect = (TParticleCtrl *)spawn_particle_effect_with_rotation(&pos, &r1, 0x207, 0x40);
            if (effect != NULL) {
                effect->enable();
            }
        } else {
            effect->set_position(&pos);
        }
        if (phase_effect == NULL) {
            r2.x = 0;
            r2.y = this->m_ec + 0x4000;
            r2.z = 0;
            phase_effect = (TParticleCtrl *)spawn_particle_effect_with_rotation(&pos, &r2, phase_effect_id, 0x40);
            if (phase_effect != NULL) {
                phase_effect->enable();
            }
        } else {
            phase_effect->set_position(&pos);
        }
        break;
    }
}

TObjEneBm9Mericarol_Bomb::~TObjEneBm9Mericarol_Bomb() {
    if (effect != NULL) {
        effect->queue_destruction();
        effect = NULL;
    }
    if (phase_effect != NULL) {
        phase_effect->queue_destruction();
        phase_effect = NULL;
    }
}


TObjEneBm9Mericarol_Bomb::TObjEneBm9Mericarol_Bomb(TObjEneBm9Mericarol *owner, Vec *start, Vec *target, f32 power, f32 speed, s32 final_blast)
    : TUnk_804928CC(owner, owner) {
    Vec d;
    f32 k;
    m_name = TObjEneBm9Mericarol_Bomb__class_name;
    if (TObjEneDD::check_v2_mode() != 0) {
        attack_type = 5;
    } else {
        switch (owner->get_phase()) {
        case 1:
            attack_type = 2;
            break;
        case 2:
            attack_type = 3;
            break;
        case 0:
        default:
            this->final_blast = final_blast;
            attack_type = 0;
            break;
        }
    }
    this->power = power;
    switch (owner->get_phase()) {
    case 1:
        phase_effect_id = 0x20A;
        break;
    case 2:
        phase_effect_id = 0x209;
        break;
    case 0:
    default:
        phase_effect_id = 0x208;
        break;
    }
    bodies->radius = 2.0f;
    owner_id = owner->get_entity_id();
    VecCopy(&pos, start);
    VecCopy(&position, &pos);
    ground_normal.x = 0.0f;
    ground_normal.y = 0.0f;
    ground_normal.z = 0.0f;
    d.x = target->x - start->x;
    d.y = 12.0f + (target->y - start->y);
    d.z = target->z - start->z;
    if (0.0f != vector_length(&d)) {
        normalize_vector(&d);
    }
    velocity.x = d.x * speed;
    k = 3.0f + speed;
    velocity.y = d.y * speed;
    velocity.z = d.z * speed;
    look_ahead.x = d.x * k;
    look_ahead.y = d.y * k;
    look_ahead.z = d.z * k;
    contact.recoil = 0.0f;
    contact.contact_flags = 1;
    fall_speed = 0.0f;
    age = 0;
    state = 0;
    effect = NULL;
    phase_effect = NULL;
    shadow_visible = 1;
}

