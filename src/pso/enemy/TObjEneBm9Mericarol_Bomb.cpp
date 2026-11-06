#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TUnk_804928CC.h"
#include "pso/enemy/TObjEneBm9Mericarol_Bomb.h"
#include "pso/system/vector.h"
#include "pso/effect/TParticleCtrl.h"
#include "pso/misc/TNowLoading.h"
#include "pso/unk/text_800BC4C8.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/TObjEneBm9Mericarol.h"
#include "pso/boss/TObjBoss2Tunnel.h"

const char *TObjEneBm9Mericarol_Bomb__class_name = "TObjEneBm9Mericarol_Bomb";

extern "C" {
s32 obj_is_hit_receivable(u32);
f32 fabs_float(f32);
s32 is_area_attack_target_eligible(void *, u32);
s32 attack_target_history_add(s32, s32);

s32 TObjEneBm9Mericarol_Bomb::area_attack_deliver_direct(void *recoil, s32 arg2, void *object, f32 range) {
    s32 hit;
    u32 mask;
    s32 obj;
    s32 i;
    s32 ok;
    hit = 0;
    mask = 0;
    if (this->owner == 0) {
        return 0;
    }
    TObjPlayer::init_all_slots();
    if (*(s32 *)((s8 *)recoil + 4) & 1) {
        update_body_contact_flag(range);
        mask |= 0x80000;
    }
    if (*(s32 *)((s8 *)recoil + 4) & 2) {
        mark_enemy_body_contacts();
        mask |= 0x100000;
    }
    if (*(u32 *)((s8 *)this->bodies + 0x18) & mask) {
        for (i = 0; i < 0x10; i++) {
            obj = TObjPlayer::get_battle_param(i);
            if (obj == 0) {
                break;
            }
            if (obj_is_hit_receivable(obj) != 0 && (u32)obj != this->owner &&
                is_area_attack_target_eligible(this, *(u32 *)((s8 *)obj + 0x30)) != 0 &&
                !(fabs_float(pos.y - *(f32 *)((s8 *)obj + 0x300)) > 3e+01f)) {
                ok = 1;
                if (object != 0 && attack_target_history_add((s32)object, obj) == 0) {
                    ok = 0;
                }
                if (ok != 0) {
                    area_attack_receive_direct((void *)obj, (f32 *)recoil, (void *)arg2);
                    hit = 1;
                }
            }
        }
    }
    return hit;
}

void TObjEneBm9Mericarol_Bomb::render() {
    if (shadow_visible != 0) {
        ((TObjEneDD *)&position)->draw_oriented_shadow((s32)&shadow_pos, 0, (u32)0);
    }
}

}

struct VBase_18_64db54 { char pad[0x18]; };

struct VObj_18_64db54 : VBase_18_64db54 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual s32 m14(void *, void *);
};

struct Vec_802D14F4 { f32 x, y, z; };

struct Rot_802D14F4 { s32 x, y, z; };

struct Hit_802D14F4 { u8 pad[4]; u8 *tri; };

extern "C" {
s32 *csnVecterUnder(s32 origin, s32 mask);
u32 csnVector(void *, void *, int);
void *spawn_particle_effect_with_rotation(void *pos, void *dir, s32 id, int e);
void *find_entity_by_id(u16 id);
void TObjEneBm9Mericarol__sub_802CED40(void *p);
s32 vec3_add_to(void *, void *);

#pragma push
#pragma opt_common_subs off
void TObjEneBm9Mericarol_Bomb::run_task() {
    Vec_802D14F4 v;
    Rot_802D14F4 r1;
    Rot_802D14F4 r2;
    Hit_802D14F4 *hit;
    f32 d;
    switch (state) {
    case 0:
        age++;
        if ((f32)age >= 1.5e+02f) {
            queue_destruction();
            return;
        }
        fall_speed -= 0.15f;
        VecCopy((Vec *)&v, &pos);
        vec3_add_to(&v, &look_ahead);
        v.y += fall_speed - 3.0f;
        if (csnVector(&pos, &v, 0x1EFF) != 0) {
            queue_destruction();
            return;
        }
        pos.x += velocity.x;
        pos.y += velocity.y;
        pos.z += velocity.z;
        hit = (Hit_802D14F4 *)csnVecterUnder((s32)&pos, 0x16EF);
        if (hit != NULL) {
            position.y = *(f32 *)((s8 *)hit->tri + 4);
            VecCopy(&shadow_pos, (const Vec *)(hit->tri + 0xC));
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
        if (((VObj_18_64db54 *)this)->m14((u8 *)&this->attack_power, (u8 *)&this->attack_type) != 0) {
            TObjEneBm9Mericarol__sub_802CED40(find_entity_by_id(owner_id));
            if (attack_type == 0 && this->m_108 != 0) {
                attack_type = 0x12;
                this->vfunc_16((u8 *)&this->attack_power, (u8 *)&this->attack_type);
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
#pragma pop

}

extern "C" {

s16 get_entity_id(void *);
f32 vector_length(Vec *);
s32 normalize_vector(Vec *);

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

#pragma push
#pragma fp_contract on

TObjEneBm9Mericarol_Bomb::TObjEneBm9Mericarol_Bomb(TObjEneBm9Mericarol *owner, Vec *start, Vec *target, f32 farg0, f32 farg1, s32 arg4)
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
            m_108 = arg4;
            attack_type = 0;
            break;
        }
    }
    m_f4 = farg0;
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
    owner_id = get_entity_id(owner);
    VecCopy(&pos, start);
    VecCopy(&position, &pos);
    shadow_pos.x = 0.0f;
    shadow_pos.y = 0.0f;
    shadow_pos.z = 0.0f;
    d.x = target->x - start->x;
    d.y = 12.0f + (target->y - start->y);
    d.z = target->z - start->z;
    if (0.0f != vector_length(&d)) {
        normalize_vector(&d);
    }
    velocity.x = d.x * farg1;
    k = 3.0f + farg1;
    velocity.y = d.y * farg1;
    velocity.z = d.z * farg1;
    look_ahead.x = d.x * k;
    look_ahead.y = d.y * k;
    look_ahead.z = d.z * k;
    attack_power = 0.0f;
    attack_flags = 1;
    fall_speed = 0.0f;
    age = 0;
    state = 0;
    effect = NULL;
    phase_effect = NULL;
    shadow_visible = 1;
}

#pragma pop
