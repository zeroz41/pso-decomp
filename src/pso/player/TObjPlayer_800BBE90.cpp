#include "pso/system/vector.h"
#include "pso/math/MatrixTransforms.h"
#include "types.h"
#include "pso/boss/goldragon/TBoss8Dragon_800BC53C.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TUnk_804928CC.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/object/base/TObjChara.h"


struct VBase { char pad[0x18]; };

struct VObj : VBase { virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11(); virtual void m12(); virtual void m13(f32); virtual void m14(); virtual void m15(); virtual void m16(f32); };

struct Obj_800BBFD0 { u8 pad[0x38]; Vec pos; u8 pad2[0x308 - 0x44]; f32 f308; f32 f30c; f32 f310; };

struct Rec_800BC080 { u8 pad0[0x18]; s32 flags; u8 pad1C[0x2C - 0x1C]; };

struct Tgt_800BC080 { u8 pad[0x30]; s32 x30; u8 pad2[0xA4 - 0x34]; Rec_800BC080 *recs; s32 nrecs; };

struct Arg_800BC080 { s32 x0; s32 flags; };

struct Info_800BC080 { u8 pad[0x18]; s32 mask; };

struct VB_800BC080 { char pad[0x18]; };

struct P_800BC080 : VB_800BC080 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(Tgt_800BC080 *, Arg_800BC080 *);
    u8 pad1c[0xA4 - 0x1C];
    Info_800BC080 *info;
    u8 padA8[4];
    Tgt_800BC080 *self_tgt;
};

struct Tgt_800BC250 { u8 pad[0x30]; s32 x30; };

struct Arg_800BC250 { s32 x0; s32 flags; };

struct Info_800BC250 { u8 pad[0x18]; s32 mask; };

struct VB_800BC250 { char pad[0x18]; };

struct P_800BC250 : VB_800BC250 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18();
    virtual void m19(Tgt_800BC250 *, Arg_800BC250 *, s32);
    u8 pad1c[0xA4 - 0x1C];
    Info_800BC250 *info;
    u8 padA8[4];
    Tgt_800BC250 *self_tgt;
};

extern "C" {
s32 obj_is_hit_receivable();
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
    Obj_800BBFD0 *a = (Obj_800BBFD0 *)this;
    Obj_800BBFD0 *b = (Obj_800BBFD0 *)b_arg;
    Vec v;
    VecCopy((Vec *)&v, (const Vec *)&b->pos);
    subtract_vector(&v, &a->pos);
    normalize_vector_xz((Vec *)(&v));
    b->f308 = v.x * s + b->f308;
    b->f310 = v.z * s + b->f310;
}
#pragma pop

void TUnk_804928CC::vfunc_19(void *arg1) {
    this->call_vt16_with_default(arg1, 0);
}

s32 TUnk_804928CC::area_attack_deliver_physical(void *arg1, void *object, f32 range) {
    s32 hit = 0;
    s32 mask = 0;
    Tgt_800BC080 *t;
    s32 i;
    s32 ok;
    s32 j;
    s32 n;
    if (((P_800BC080 *)this)->self_tgt == NULL) {
        return 0;
    }
    TObjPlayer::init_all_slots();
    if (((Arg_800BC080 *)arg1)->flags & 1) {
        ((TUnk_804928CC *)((P_800BC080 *)this))->update_body_contact_flag(range);
        mask |= 0x80000;
    }
    if (((Arg_800BC080 *)arg1)->flags & 2) {
        ((TObjCollidable *)((P_800BC080 *)this))->mark_enemy_body_contacts();
        mask |= 0x100000;
    }
    if (((P_800BC080 *)this)->info->mask & mask) {
        for (i = 0; i < 0x10; i++) {
            t = (Tgt_800BC080 *)TObjPlayer::get_battle_param(i);
            if (t == NULL) {
                break;
            }
            if (obj_is_hit_receivable() != 0 && t != ((P_800BC080 *)this)->self_tgt && is_area_attack_target_eligible(((P_800BC080 *)this), t->x30) != 0) {
                ok = 1;
                if (object != NULL && attack_target_history_add((AreaAttackHistory *)object, (TObjChara *)t) == 0) {
                    ok = 0;
                }
                if (ok != 0) {
                    this->apply_hit_if_active(t, (f32 *)((Arg_800BC080 *)arg1));
                    hit = 1;
                } else {
                    n = t->nrecs;
                    for (j = 0; j < n; j++) {
                        t->recs[j].flags &= ~0x04000000;
                    }
                }
            }
        }
    }
    return hit;
}

#pragma push
#pragma fp_contract on
void TUnk_804928CC::call_vt16_with_default(void *, void *) {
    u8 *arg0 = (u8 *)this;
    ((VObj *)arg0)->m16(100.0f);
}
#pragma pop

s32 TUnk_804928CC::vfunc_16(void *recoil, void *attack) {
    return call_vt13_with_default(recoil, attack, 0);
}

s32 TUnk_804928CC::area_attack_deliver_direct(void *recoil, saddr arg2, void *object, f32 range) {
    s32 hit = 0;
    s32 mask = 0;
    Tgt_800BC250 *t;
    s32 i;
    s32 ok;
    if (((P_800BC250 *)this)->self_tgt == NULL) {
        return 0;
    }
    TObjPlayer::init_all_slots();
    if (((Arg_800BC250 *)recoil)->flags & 1) {
        ((TUnk_804928CC *)((P_800BC250 *)this))->update_body_contact_flag(range);
        mask |= 0x80000;
    }
    if (((Arg_800BC250 *)recoil)->flags & 2) {
        ((TObjCollidable *)((P_800BC250 *)this))->mark_enemy_body_contacts();
        mask |= 0x100000;
    }
    if (((P_800BC250 *)this)->info->mask & mask) {
        for (i = 0; i < 0x10; i++) {
            t = ((Tgt_800BC250 *)TObjPlayer::get_battle_param(i));
            if (t == NULL) {
                break;
            }
            if (obj_is_hit_receivable() != 0 && t != ((P_800BC250 *)this)->self_tgt && is_area_attack_target_eligible(((P_800BC250 *)this), t->x30) != 0) {
                ok = 1;
                if (object != NULL && attack_target_history_add((AreaAttackHistory *)object, (TObjChara *)t) == 0) {
                    ok = 0;
                }
                if (ok != 0) {
                    this->area_attack_receive_direct((void *)t, (f32 *)((Arg_800BC250 *)recoil), (void *)arg2);
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
