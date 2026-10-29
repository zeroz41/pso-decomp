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

struct VBase_18_0ab400 { char pad[0x18]; };

struct VObj_18_0ab400 : VBase_18_0ab400 {
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
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual s32 m19(s32, void *, s32);
};

extern "C" {
s32 obj_is_hit_receivable(u32);
f32 fabs_float(f32);
s32 is_area_attack_target_eligible(void *, u32);
s32 attack_target_history_add(s32, s32);

s32 TObjPlayer::apply_area_attack_hits(u8 *arg1, s32 arg2, u32 object, f32 range) {
    s32 hit;
    u32 mask;
    s32 obj;
    s32 i;
    s32 ok;
    hit = 0;
    mask = 0;
    if (this->extra == 0) {
        return 0;
    }
    TObjPlayer::init_all_slots();
    if (*(s32 *)((s8 *)arg1 + 4) & 1) {
        ((TUnk_804928CC *)((u8 *)this))->update_body_contact_flag(range);
        mask |= 0x80000;
    }
    if (*(s32 *)((s8 *)arg1 + 4) & 2) {
        this->mark_enemy_body_contacts();
        mask |= 0x100000;
    }
    if (*(u32 *)((s8 *)this->bodies + 0x18) & mask) {
        for (i = 0; i < 0x10; i++) {
            obj = TObjPlayer::get_battle_param(i);
            if (obj == 0) {
                break;
            }
            if (obj_is_hit_receivable(obj) != 0 && (u32)obj != this->extra &&
                is_area_attack_target_eligible(this, *(u32 *)((s8 *)obj + 0x30)) != 0 &&
                !(fabs_float(*(f32 *)((s8 *)((u8 *)this) + 0xB8) - *(f32 *)((s8 *)obj + 0x300)) > 3e+01f)) {
                ok = 1;
                if (object != 0 && attack_target_history_add(object, obj) == 0) {
                    ok = 0;
                }
                if (ok != 0) {
                    ((VObj_18_0ab400 *)(this))->m19(obj, arg1, arg2);
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
void queue_destruction__7TObjectFv(void *arg0);
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
            queue_destruction__7TObjectFv(arg0);
            return;
        }
        this->m_f8 -= 0.15f;
        VecCopy((Vec *)&v, (const Vec *)&this->m_b4);
        vec3_add_to(&v, (u8 *)&this->m_cc);
        v.y += this->m_f8 - 3.0f;
        if (csnVector((u8 *)&this->m_b4, &v, 0x1EFF) != 0) {
            queue_destruction__7TObjectFv(arg0);
            return;
        }
        this->m_b4 += *(f32 *)&this->unk_C0;
        *(f32 *)&this->unk_B8 += this->m_c4;
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
        d = *(f32 *)&this->unk_B8 - *(f32 *)((s8 *)arg0 + 0x3C);
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
            queue_destruction__7TObjectFv(arg0);
            return;
        }
    case 1:
    default:
        if (this->m_110 == NULL) {
            r1.x = 0;
            r1.y = this->m_ec + 0x4000;
            r1.z = 0;
            *(u32 *)&this->m_110 = (u32)spawn_particle_effect_with_rotation(&this->m_b4, &r1, 0x207, 0x40);
            if (this->m_110 != NULL) {
                ((TParticleCtrl *)(this->m_110))->enable();
            }
        } else {
            ((TParticleCtrl *)this->m_110)->set_position((u8 *)&this->m_b4);
        }
        if (*(void * *)&this->unk_114 == NULL) {
            r2.x = 0;
            r2.y = this->m_ec + 0x4000;
            r2.z = 0;
            *(u32 *)&this->unk_114 = (u32)spawn_particle_effect_with_rotation(&this->m_b4, &r2, *(s32 *)&this->unk_104, 0x40);
            if (*(void * *)&this->unk_114 != NULL) {
                ((TParticleCtrl *)(*(void * *)&this->unk_114))->enable();
            }
        } else {
            ((TParticleCtrl *)*(void * *)&this->unk_114)->set_position((u8 *)&this->m_b4);
        }
        break;
    }
}
#pragma pop

}

struct VBase_18_477421
{
  char pad[0x18];
};

struct Vec_802D1880 { f32 x, y, z; };

extern "C" {

s16 get_entity_id(void *);
f32 vector_length(Vec_802D1880 *);
s32 normalize_vector(Vec_802D1880 *);
extern s32 lbl_804E18A8[];
extern s32 lbl_805D3F30;

u8 *TObjEneBm9Mericarol__sub_802D1880(u8 *arg0, u8 *arg1, Vec_802D1880 *arg2, Vec_802D1880 *arg3, s32 arg4, f32 farg0, f32 farg1);
void __dl__7TObjectFPv(void *);

void *TObjEneBm9Mericarol_Bomb::dt(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = lbl_804E18A8;
        if (this->m_110 != NULL) { queue_destruction__7TObjectFv(this->m_110); this->m_110 = 0; }
        if (*(void * *)&this->unk_114 != NULL) { queue_destruction__7TObjectFv(*(void * *)&this->unk_114); *(s32 *)&this->unk_114 = 0; }
        __dt__13TUnk_804928CCFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

#pragma push
#pragma fp_contract on

u8 *TObjEneBm9Mericarol__sub_802D1880(u8 *ene_bm9_mericarol_bomb, u8 *ene_bm9_mericarol, Vec_802D1880 *arg2, Vec_802D1880 *arg3, s32 arg4, f32 farg0, f32 farg1) {
    Vec_802D1880 d;
    f32 k;
    __ct__13TUnk_804928CCFP7TObjectP8TObjBase((u8 *)ene_bm9_mericarol_bomb, (s32)ene_bm9_mericarol, (u32)ene_bm9_mericarol);
    *(s32 **)((s8 *)ene_bm9_mericarol_bomb + 0x18) = lbl_804E18A8;
    *(s32 *)((s8 *)ene_bm9_mericarol_bomb + 0) = lbl_805D3F30;
    if (TObjEneDD::check_v2_mode() != 0) {
        *(s32 *)((s8 *)ene_bm9_mericarol_bomb + 0xF0) = 5;
    } else {
        switch (((TObjEneBm9Mericarol *)ene_bm9_mericarol)->get_phase()) {
        case 1:
            *(s32 *)((s8 *)ene_bm9_mericarol_bomb + 0xF0) = 2;
            break;
        case 2:
            *(s32 *)((s8 *)ene_bm9_mericarol_bomb + 0xF0) = 3;
            break;
        case 0:
        default:
            ((TObjEneBm9Mericarol_Bomb *)ene_bm9_mericarol_bomb)->m_108 = arg4;
            *(s32 *)((s8 *)ene_bm9_mericarol_bomb + 0xF0) = 0;
            break;
        }
    }
    ((TObjEneBm9Mericarol_Bomb *)ene_bm9_mericarol_bomb)->m_f4 = farg0;
    switch (((TObjEneBm9Mericarol *)ene_bm9_mericarol)->get_phase()) {
    case 1:
        *(s32 *)((s8 *)ene_bm9_mericarol_bomb + 0x104) = 0x20A;
        break;
    case 2:
        *(s32 *)((s8 *)ene_bm9_mericarol_bomb + 0x104) = 0x209;
        break;
    case 0:
    default:
        *(s32 *)((s8 *)ene_bm9_mericarol_bomb + 0x104) = 0x208;
        break;
    }
    *(f32 *)((s8 *)(((TObjEneBm9Mericarol_Bomb *)ene_bm9_mericarol_bomb)->bodies) + 0xC) = 2.0f;
    *(s16 *)((s8 *)ene_bm9_mericarol_bomb + 0xB0) = get_entity_id(ene_bm9_mericarol);
    VecCopy((Vec *)(ene_bm9_mericarol_bomb + 0xB4), (const Vec *)arg2);
    VecCopy((Vec *)(ene_bm9_mericarol_bomb + 0x38), (const Vec *)(ene_bm9_mericarol_bomb + 0xB4));
    *(f32 *)((s8 *)ene_bm9_mericarol_bomb + 0xD8) = 0.0f;
    ((TObjEneBm9Mericarol_Bomb *)ene_bm9_mericarol_bomb)->m_dc = 0.0f;
    *(f32 *)((s8 *)ene_bm9_mericarol_bomb + 0xE0) = 0.0f;
    d.x = arg3->x - arg2->x;
    d.y = 12.0f + (arg3->y - arg2->y);
    d.z = arg3->z - arg2->z;
    if (0.0f != vector_length(&d)) {
        normalize_vector(&d);
    }
    *(f32 *)((s8 *)ene_bm9_mericarol_bomb + 0xC0) = d.x * farg1;
    k = 3.0f + farg1;
    ((TObjEneBm9Mericarol_Bomb *)ene_bm9_mericarol_bomb)->m_c4 = d.y * farg1;
    *(f32 *)((s8 *)ene_bm9_mericarol_bomb + 0xC8) = d.z * farg1;
    ((TObjEneBm9Mericarol_Bomb *)ene_bm9_mericarol_bomb)->m_cc = d.x * k;
    *(f32 *)((s8 *)ene_bm9_mericarol_bomb + 0xD0) = d.y * k;
    ((TObjEneBm9Mericarol_Bomb *)ene_bm9_mericarol_bomb)->m_d4 = d.z * k;
    ((TObjEneBm9Mericarol_Bomb *)ene_bm9_mericarol_bomb)->m_e4 = 0.0f;
    *(s32 *)((s8 *)ene_bm9_mericarol_bomb + 0xE8) = 1;
    ((TObjEneBm9Mericarol_Bomb *)ene_bm9_mericarol_bomb)->m_f8 = 0.0f;
    *(s32 *)((s8 *)ene_bm9_mericarol_bomb + 0xFC) = 0;
    ((TObjEneBm9Mericarol_Bomb *)ene_bm9_mericarol_bomb)->m_100 = 0;
    *(s32 *)((s8 *)ene_bm9_mericarol_bomb + 0x110) = 0;
    *(s32 *)((s8 *)ene_bm9_mericarol_bomb + 0x114) = 0;
    *(s32 *)((s8 *)ene_bm9_mericarol_bomb + 0x10C) = 1;
    return ene_bm9_mericarol_bomb;
}

typedef struct VBase_18_477421 VBase_18_477421;
#pragma pop

}
