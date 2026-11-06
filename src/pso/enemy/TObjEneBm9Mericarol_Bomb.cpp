#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TUnk_804928CC.h"
#include "pso/enemy/TObjEneBm9Mericarol_Bomb.h"
#include "pso/system/vector.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TNowLoading.h"
#include "pso/unk/text_800BC4C8.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/TObjEneBm9Mericarol.h"
#include "pso/boss/TObjBoss2Tunnel.h"

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
    if (this->m_ac == 0) {
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
            if (obj_is_hit_receivable(obj) != 0 && (u32)obj != this->m_ac &&
                is_area_attack_target_eligible(this, *(u32 *)((s8 *)obj + 0x30)) != 0 &&
                !(fabs_float(unk_B8 - *(f32 *)((s8 *)obj + 0x300)) > 3e+01f)) {
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
    u8 *arg0 = (u8 *)this;
    if ((s32) *(s32 *)((s8 *)arg0 + 0x10C) != 0) {
        ((TObjEneDD *)(arg0 + 0x38))->draw_oriented_shadow((s32)(arg0 + 0xD8), 0, (u32)0);
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
    u8 *arg0 = (u8 *)this;
    Vec_802D14F4 v;
    Rot_802D14F4 r1;
    Rot_802D14F4 r2;
    Hit_802D14F4 *hit;
    f32 d;
    switch (this->m_100) {
    case 0:
        (*(s32 *)&this->unk_FC)++;
        if ((f32) *(s32 *)&this->unk_FC >= 1.5e+02f) {
            queue_destruction();
            return;
        }
        this->m_f8 -= 0.15f;
        VecCopy((Vec *)&v, (const Vec *)&this->m_b4);
        vec3_add_to(&v, (u8 *)&this->m_cc);
        v.y += this->m_f8 - 3.0f;
        if (csnVector((u8 *)&this->m_b4, &v, 0x1EFF) != 0) {
            queue_destruction();
            return;
        }
        this->m_b4 += *(f32 *)&this->unk_C0;
        this->unk_B8 += this->m_c4;
        this->m_bc += *(f32 *)((s8 *)arg0 + 0xC8);
        hit = (Hit_802D14F4 *)csnVecterUnder((s32)&this->m_b4, 0x16EF);
        if (hit != NULL) {
            *(f32 *)((s8 *)arg0 + 0x3C) = *(f32 *)((s8 *)hit->tri + 4);
            VecCopy((Vec *)(arg0 + 0xD8), (const Vec *)(hit->tri + 0xC));
            *(s32 *)&this->unk_10C = 1;
        } else {
            *(s32 *)&this->unk_10C = 0;
        }
        *(f32 *)((s8 *)arg0 + 0x38) = this->m_b4;
        *(f32 *)((s8 *)arg0 + 0x40) = this->m_bc;
        d = this->unk_B8 - *(f32 *)((s8 *)arg0 + 0x3C);
        if (d > 2e+01f) {
            *(s32 *)((s8 *)(*(u8 * *)&this->bodies) + 0x18) |= 4;
            *(s32 *)((s8 *)(*(u8 * *)&this->bodies) + 0x18) &= ~2;
        } else {
            *(s32 *)((s8 *)(*(u8 * *)&this->bodies) + 0x18) &= ~4;
            *(s32 *)((s8 *)(*(u8 * *)&this->bodies) + 0x18) |= 2;
        }
        *(f32 *)((s8 *)(*(u8 * *)&this->bodies) + 4) = d;
        if (((VObj_18_64db54 *)(arg0))->m14((u8 *)&this->m_e4, (u8 *)&this->unk_F0) != 0) {
            TObjEneBm9Mericarol__sub_802CED40(find_entity_by_id(*(u16 *)((s8 *)arg0 + 0xB0)));
            if (*(s32 *)((s8 *)arg0 + 0xF0) == 0 && this->m_108 != 0) {
                *(s32 *)((s8 *)arg0 + 0xF0) = 0x12;
                this->vfunc_16((u8 *)&this->m_e4, (u8 *)&this->unk_F0);
            }
            queue_destruction();
            return;
        }
    case 1:
    default:
        if (this->m_110 == NULL) {
            r1.x = 0;
            r1.y = this->m_ec + 0x4000;
            r1.z = 0;
            this->m_110 = (TParticleCtrl *)spawn_particle_effect_with_rotation(&this->m_b4, &r1, 0x207, 0x40);
            if (this->m_110 != NULL) {
                this->m_110->enable();
            }
        } else {
            this->m_110->set_position(&this->m_b4);
        }
        if (this->unk_114 == NULL) {
            r2.x = 0;
            r2.y = this->m_ec + 0x4000;
            r2.z = 0;
            this->unk_114 = (TParticleCtrl *)spawn_particle_effect_with_rotation(&this->m_b4, &r2, *(s32 *)&this->unk_104, 0x40);
            if (this->unk_114 != NULL) {
                this->unk_114->enable();
            }
        } else {
            this->unk_114->set_position(&this->m_b4);
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
extern const char *lbl_805D3F30;

}

TObjEneBm9Mericarol_Bomb::~TObjEneBm9Mericarol_Bomb() {
    if (m_110 != NULL) {
        m_110->queue_destruction();
        m_110 = NULL;
    }
    if (unk_114 != NULL) {
        unk_114->queue_destruction();
        unk_114 = NULL;
    }
}

#pragma push
#pragma fp_contract on

TObjEneBm9Mericarol_Bomb::TObjEneBm9Mericarol_Bomb(TObjEneBm9Mericarol *owner, Vec *pos, Vec *target, f32 farg0, f32 farg1, s32 arg4)
    : TUnk_804928CC(owner, owner) {
    Vec d;
    f32 k;
    m_name = lbl_805D3F30;
    if (TObjEneDD::check_v2_mode() != 0) {
        *(s32 *)((s8 *)this + 0xF0) = 5;
    } else {
        switch (owner->get_phase()) {
        case 1:
            *(s32 *)((s8 *)this + 0xF0) = 2;
            break;
        case 2:
            *(s32 *)((s8 *)this + 0xF0) = 3;
            break;
        case 0:
        default:
            m_108 = arg4;
            *(s32 *)((s8 *)this + 0xF0) = 0;
            break;
        }
    }
    m_f4 = farg0;
    switch (owner->get_phase()) {
    case 1:
        *(s32 *)((s8 *)this + 0x104) = 0x20A;
        break;
    case 2:
        *(s32 *)((s8 *)this + 0x104) = 0x209;
        break;
    case 0:
    default:
        *(s32 *)((s8 *)this + 0x104) = 0x208;
        break;
    }
    *(f32 *)((s8 *)bodies + 0xC) = 2.0f;
    *(s16 *)((s8 *)this + 0xB0) = get_entity_id(owner);
    VecCopy((Vec *)&m_b4, pos);
    VecCopy(&position, (Vec *)&m_b4);
    *(f32 *)((s8 *)this + 0xD8) = 0.0f;
    m_dc = 0.0f;
    *(f32 *)((s8 *)this + 0xE0) = 0.0f;
    d.x = target->x - pos->x;
    d.y = 12.0f + (target->y - pos->y);
    d.z = target->z - pos->z;
    if (0.0f != vector_length(&d)) {
        normalize_vector(&d);
    }
    *(f32 *)((s8 *)this + 0xC0) = d.x * farg1;
    k = 3.0f + farg1;
    m_c4 = d.y * farg1;
    *(f32 *)((s8 *)this + 0xC8) = d.z * farg1;
    m_cc = d.x * k;
    *(f32 *)((s8 *)this + 0xD0) = d.y * k;
    m_d4 = d.z * k;
    m_e4 = 0.0f;
    *(s32 *)((s8 *)this + 0xE8) = 1;
    m_f8 = 0.0f;
    *(s32 *)((s8 *)this + 0xFC) = 0;
    m_100 = 0;
    m_110 = NULL;
    unk_114 = NULL;
    *(s32 *)((s8 *)this + 0x10C) = 1;
}

#pragma pop
