#include "types.h"
#include "pso/object/base/TAttackCollider.h"
#include "pso/object/base/HitEligibility.h"
#include "pso/system/vector.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/boss/goldragon/AreaAttackHistory.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/AreaAttackContact.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/ActorCollision.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/object/base/TObjChara.h"
#include "pso/boss/dragon/TBoss1Dragon.h"

extern "C" {


void TAttackCollider::apply_hit_if_active(TObjChara *target, const f32 *recoil) {
    target->receive_physical_attack((TObjChara *)owner, 1.0f);
    if (target->obj_isState2_324() == 0) {
        this->area_attack_apply_recoil(target, *recoil);
    }
}

void TAttackCollider::area_attack_receive_direct(TObjChara *target, const f32 *recoil, DirectAttackPayload *attack) {
    s32 i;
    CollisionBody *rec;
    for (i = 0; i < target->body_count; i++) {
        rec = &target->bodies[i];
        if (rec->flags & 0x04000000) {
            target->receive_direct_attack(owner, *attack, rec, -1, -1);
            if (target->obj_isState2_324() == 0) {
                area_attack_apply_recoil(target, *recoil);
            }
            return;
        }
    }
}

#pragma push
#pragma fp_contract on
void TAttackCollider::area_attack_apply_recoil(TObjChara *target, f32 recoil) {
    Vec v;
    VecCopy(&v, &target->position);
    subtract_vector(&v, &position);
    normalize_vector_xz(&v);
    target->velocity.x = v.x * recoil + target->velocity.x;
    target->velocity.z = v.z * recoil + target->velocity.z;
}
#pragma pop

void TAttackCollider::deliver_physical_no_history(const AreaAttackContact *contact) {
    this->call_vt16_with_default(contact, 0);
}

s32 TAttackCollider::area_attack_deliver_physical(const AreaAttackContact *contact, AreaAttackHistory *history, f32 range) {
    s32 hit = 0;
    s32 mask = 0;
    TObjChara *t;
    s32 i;
    s32 ok;
    s32 j;
    s32 n;
    if (owner == NULL) {
        return 0;
    }
    clear_battle_param_slots();
    if (contact->contact_flags & 1) {
        update_body_contact_flag(range);
        mask |= 0x80000;
    }
    if (contact->contact_flags & 2) {
        mark_enemy_body_contacts();
        mask |= 0x100000;
    }
    if (bodies->flags & mask) {
        for (i = 0; i < 0x10; i++) {
            t = TObjPlayer::get_battle_param(i);
            if (t == NULL) {
                break;
            }
            if (obj_is_hit_receivable(t) != 0 && t != owner && is_target_eligible(t->actorFlags) != 0) {
                ok = 1;
                if (history != NULL && attack_target_history_add(history, t) == 0) {
                    ok = 0;
                }
                if (ok != 0) {
                    this->apply_hit_if_active(t, &contact->recoil);
                    hit = 1;
                } else {
                    n = t->body_count;
                    for (j = 0; j < n; j++) {
                        t->bodies[j].flags &= ~0x04000000;
                    }
                }
            }
        }
    }
    return hit;
}

#pragma push
#pragma fp_contract on
void TAttackCollider::call_vt16_with_default(const AreaAttackContact *contact, AreaAttackHistory *history) {
    area_attack_deliver_physical(contact, history, 100.0f);
}
#pragma pop

s32 TAttackCollider::deliver_direct_no_history(const AreaAttackContact *contact, DirectAttackPayload *attack) {
    return call_vt13_with_default(contact, attack, NULL);
}

s32 TAttackCollider::area_attack_deliver_direct(const AreaAttackContact *contact, DirectAttackPayload *attack,
                                                AreaAttackHistory *history, f32 range) {
    s32 hit = 0;
    s32 mask = 0;
    TObjChara *t;
    s32 i;
    s32 ok;
    if (owner == NULL) {
        return 0;
    }
    clear_battle_param_slots();
    if (contact->contact_flags & 1) {
        update_body_contact_flag(range);
        mask |= 0x80000;
    }
    if (contact->contact_flags & 2) {
        mark_enemy_body_contacts();
        mask |= 0x100000;
    }
    if (bodies->flags & mask) {
        for (i = 0; i < 0x10; i++) {
            t = TObjPlayer::get_battle_param(i);
            if (t == NULL) {
                break;
            }
            if (obj_is_hit_receivable(t) != 0 && t != owner && is_target_eligible(t->actorFlags) != 0) {
                ok = 1;
                if (history != NULL && attack_target_history_add(history, t) == 0) {
                    ok = 0;
                }
                if (ok != 0) {
                    this->area_attack_receive_direct(t, &contact->recoil, attack);
                    hit = 1;
                }
            }
        }
    }
    return hit;
}

s32 TAttackCollider::call_vt13_with_default(const AreaAttackContact *contact, DirectAttackPayload *attack,
                                            AreaAttackHistory *history) {
    return area_attack_deliver_direct(contact, attack, history, 100.0f);
}

}

void TAttackCollider::set_position_from(const Vec *pos) { VecCopy(&this->position, pos); }

void TAttackCollider::set_owner(TObjBase *actor) {
    owner = actor;
    room = owner->room;
}

// Actors flagged 0x04000000 are out of its reach.
s32 TAttackCollider::is_target_eligible(u32 actor_flags) {
    return !(actor_flags & 0x04000000);
}

CollisionBody construct_collision_body_parts = {
    {0.0f, 0.0f, 0.0f}, 0.0f, 0.0f, 0, 0x9D03, {0.0f, 0.0f, 0.0f}, 0.0f
};

TAttackCollider::~TAttackCollider() {
    free_collision_body_parts(this);
}

TAttackCollider::TAttackCollider(TObject *parent, TObjBase *owner,
                           const CollisionBody *parts, s32 count)
    : TObjCollidable(parent) {
    init_collision_body_parts(this, parts, count);
    this->owner = owner;
}

TAttackCollider::TAttackCollider(TObject *parent, TObjBase *owner)
    : TObjCollidable(parent) {
    init_collision_body_parts(this, &construct_collision_body_parts, 1);
    if (owner != NULL) {
        set_owner(owner);
    } else {
        this->owner = NULL;
    }
}
