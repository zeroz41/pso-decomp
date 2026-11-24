#include "pso/object/base/HitEligibility.h"
#include "pso/system/vector.h"
#include "types.h"
#include "pso/boss/goldragon/TBoss8Dragon_800BC53C.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/AreaAttackContact.h"
#include "pso/player/TUnk_804928CC.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/object/base/TObjChara.h"


extern "C" {
void subtract_vector(Vec *a, Vec *b);
s32 is_area_attack_target_eligible(void *, int);


void TUnk_804928CC::apply_hit_if_active(void *chara, f32 *arg2) {
    ((TObjChara *)chara)->receive_physical_attack(owner, 1.0f);
    if (((TObjChara *)chara)->obj_isState2_324() == 0) {
        this->area_attack_apply_recoil(chara, *arg2);
    }
}

void TUnk_804928CC::area_attack_receive_direct(void *dst, f32 *recoil, void *desc) {
    s32 i;
    CollisionBody *rec;
    for (i = 0; i < ((TObjChara *)dst)->body_count; i++) {
        rec = &((TObjChara *)dst)->bodies[i];
        if (rec->flags & 0x04000000) {
            ((TObjChara *)dst)->receive_direct_attack(owner, *(DirectAttackPayload *)desc, rec, -1, -1);
            if (((TObjChara *)dst)->obj_isState2_324() == 0) {
                area_attack_apply_recoil(dst, *recoil);
            }
            return;
        }
    }
}

#pragma push
#pragma fp_contract on
void TUnk_804928CC::area_attack_apply_recoil(void *b_arg, f32 s) {
    TObjChara *target = static_cast<TObjChara *>(b_arg);
    Vec v;
    VecCopy(&v, &target->position);
    subtract_vector(&v, &position);
    normalize_vector_xz(&v);
    target->velocity.x = v.x * s + target->velocity.x;
    target->velocity.z = v.z * s + target->velocity.z;
}
#pragma pop

void TUnk_804928CC::vfunc_19(void *arg1) {
    this->call_vt16_with_default(arg1, 0);
}

s32 TUnk_804928CC::area_attack_deliver_physical(void *arg1, void *object, f32 range) {
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
    TObjPlayer::init_all_slots();
    if (static_cast<AreaAttackContact *>(arg1)->contact_flags & 1) {
        update_body_contact_flag(range);
        mask |= 0x80000;
    }
    if (static_cast<AreaAttackContact *>(arg1)->contact_flags & 2) {
        mark_enemy_body_contacts();
        mask |= 0x100000;
    }
    if (bodies->flags & mask) {
        for (i = 0; i < 0x10; i++) {
            t = reinterpret_cast<TObjChara *>(TObjPlayer::get_battle_param(i));
            if (t == NULL) {
                break;
            }
            if (obj_is_hit_receivable(t) != 0 && t != owner && is_area_attack_target_eligible(this, t->actorFlags) != 0) {
                ok = 1;
                if (object != NULL && attack_target_history_add((AreaAttackHistory *)object, t) == 0) {
                    ok = 0;
                }
                if (ok != 0) {
                    this->apply_hit_if_active(t, (f32 *)((AreaAttackContact *)arg1));
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
void TUnk_804928CC::call_vt16_with_default(void *contact, void *history) {
    area_attack_deliver_physical(contact, history, 100.0f);
}
#pragma pop

s32 TUnk_804928CC::vfunc_16(void *recoil, void *attack) {
    return call_vt13_with_default(recoil, attack, 0);
}

s32 TUnk_804928CC::area_attack_deliver_direct(void *recoil, saddr arg2, void *object, f32 range) {
    s32 hit = 0;
    s32 mask = 0;
    TObjChara *t;
    s32 i;
    s32 ok;
    if (owner == NULL) {
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
    if (bodies->flags & mask) {
        for (i = 0; i < 0x10; i++) {
            t = reinterpret_cast<TObjChara *>(TObjPlayer::get_battle_param(i));
            if (t == NULL) {
                break;
            }
            if (obj_is_hit_receivable(t) != 0 && t != owner && is_area_attack_target_eligible(this, t->actorFlags) != 0) {
                ok = 1;
                if (object != NULL && attack_target_history_add((AreaAttackHistory *)object, t) == 0) {
                    ok = 0;
                }
                if (ok != 0) {
                    this->area_attack_receive_direct((void *)t, (f32 *)((AreaAttackContact *)recoil), (void *)arg2);
                    hit = 1;
                }
            }
        }
    }
    return hit;
}

s32 TUnk_804928CC::call_vt13_with_default(void *recoil, void *attack, saddr history) {
    return area_attack_deliver_direct(recoil, reinterpret_cast<saddr>(attack), reinterpret_cast<void *>(history), 100.0f);
}

}
