#include "types.h"
#include "pso/boss/derolle/TBoss2PhotonPad.h"

#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8007E418.h"
#include "pso/boss/derolle/TBoss2PhotonBullet_80038DCC.h"
#include "pso/unk/text_800BC4C8.h"
#include "pso/system/vector.h"
#include "pso/player/TUnk_804928CC.h"

#include <stddef.h>

#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"


struct VBase_18_39be15 { char pad[0x18]; };

struct VObj_18_39be15 : VBase_18_39be15 {
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
    virtual s32 m14(s32 *, s32 *);
};

typedef struct Pair_80038E2C { s32 a; f32 b; } Pair_80038E2C;
struct Rec_80039288 { s32 a, b, c; f32 d; };

// The bullet level table, the two hit-check arguments and the class names, in their original .rodata order.
extern const Rec_80039288 TBoss2PhotonPad__bullet_level_param_table[3] = {
    { 3, 1, 0x3000, 3.5f },
    { 5, 1, 0x2000, 5.0f },
    { 5, 1, 0x4000, 5.0f },
};
extern const Pair_80038E2C lbl_80435B38[1] = { { 0, 3.0f } };
extern const s32 lbl_80435B40[2] = { 0x40400000, 1 }; // 3.0f as raw bits, then 1
const char *TBoss2PhotonPad__name = "TBoss2PhotonPad";
const char *TBoss2PhotonBullet__name = "TBoss2PhotonBullet";

extern "C" {
void queue_destruction__7TObjectFv(void *);
f32 TBoss2DeRolLe__sub_80034CF8(void);
void *spawn_continuous_particle_effect_with_flags(void *parent, s32 idx, s32 flags);
s32 project_actor_to_ground(void *, void *, void *);
extern const f32 lbl_805D8268;
extern const f32 lbl_805D826C;
void __dl__7TObjectFPv(void *);
extern void *__vt__18TBoss2PhotonBullet[];
void render__18TBoss2PhotonBulletFv(u8 *arg0) {
    if (*(s32 *)((s8 *)arg0 + 0xDC) & 1) {
        Vec scale = { 1.0f, 1.0f, 1.0f };
        ((TObjEneDD *)(arg0 + 0x38))->draw_oriented_shadow((s32)(arg0 + 0xCC), 0, (u32)&scale);
    }
}
#pragma push
#pragma fp_contract on
void run_task__18TBoss2PhotonBulletFv(u8 *arg0) {
    if (*(f32 *)((s8 *)arg0 + 0xC4) > 8.7f) {
        *(f32 *)((s8 *)arg0 + 0xE0) += 0.05f;
        if (*(f32 *)((s8 *)arg0 + 0xE0) >= 3.0f) {
            *(f32 *)((s8 *)arg0 + 0xE0) = 3.0f;
        }
        *(f32 *)((s8 *)arg0 + 0xC4) = *(f32 *)((s8 *)arg0 + 0xC4) - *(f32 *)((s8 *)arg0 + 0xE0);
        *(f32 *)((s8 *)arg0 + 0xC0) = 2.0f * *(f32 *)((s8 *)arg0 + 0xB4) + *(f32 *)((s8 *)arg0 + 0xC0);
        *(f32 *)((s8 *)arg0 + 0xC8) = 2.0f * *(f32 *)((s8 *)arg0 + 0xBC) + *(f32 *)((s8 *)arg0 + 0xC8);
    } else {
        *(f32 *)((s8 *)arg0 + 0xC4) = 8.7f;
        *(f32 *)((s8 *)arg0 + 0xC0) = *(f32 *)((s8 *)arg0 + 0xB4) * *(f32 *)((s8 *)arg0 + 0xB0) + *(f32 *)((s8 *)arg0 + 0xC0);
        *(f32 *)((s8 *)arg0 + 0xC8) = *(f32 *)((s8 *)arg0 + 0xBC) * *(f32 *)((s8 *)arg0 + 0xB0) + *(f32 *)((s8 *)arg0 + 0xC8);
    }
    *(f32 *)((s8 *)arg0 + 0x38) = *(f32 *)((s8 *)arg0 + 0xC0);
    *(f32 *)((s8 *)arg0 + 0x40) = *(f32 *)((s8 *)arg0 + 0xC8);
    if (*(u32 *)((s8 *)arg0 + 0xE4) == 0) {
        *(u32 *)((s8 *)arg0 + 0xE4) = (u32)spawn_continuous_particle_effect_with_flags(arg0 + 0xC0, 0xDF, 0x40);
    } else {
        ((TParticleCtrl *)(void *)*(u32 *)((s8 *)arg0 + 0xE4))->set_position(arg0 + 0xC0);
    }
    if (*(s32 *)((s8 *)arg0 + 0xD8) % 15 == 0) {
        if (project_actor_to_ground(arg0, arg0 + 0x38, arg0 + 0xCC) != 0) {
            *(s32 *)((s8 *)arg0 + 0xDC) |= 1;
        } else {
            *(s32 *)((s8 *)arg0 + 0xDC) &= ~1;
        }
    }
    if (*(f32 *)((s8 *)arg0 + 0x38) <= lbl_805D8268 && *(f32 *)((s8 *)arg0 + 0x38) >= lbl_805D826C) {
        Pair_80038E2C p = lbl_80435B38[0];
        p.b = TBoss2DeRolLe__sub_80034CF8();
        if (((VObj_18_39be15 *)arg0)->m14((s32 *)lbl_80435B40, (s32 *)&p) != 0) {
            queue_destruction__7TObjectFv(arg0);
            return;
        }
    }
    (*(s32 *)((s8 *)arg0 + 0xD8))++;
    if (*(s32 *)((s8 *)arg0 + 0xD8) >= 0x78) {
        queue_destruction__7TObjectFv(arg0);
    }
}
#pragma pop

void *__dt__18TBoss2PhotonBulletFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(void ***)((s8 *)arg0 + 0x18) = __vt__18TBoss2PhotonBullet;
        if (*(void **)((s8 *)arg0 + 0xE4) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0xE4)); *(s32 *)((s8 *)arg0 + 0xE4) = 0; }
        __dt__13TUnk_804928CCFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
u8 *TBoss2PhotonBullet__ct(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3, u8 *arg4, f32 farg0) {
    __ct__13TUnk_804928CCFP7TObjectP8TObjBase((arg0), (arg1), (arg2));
    *(void ***)((s8 *)arg0 + 0x18) = __vt__18TBoss2PhotonBullet;
    *(const char **)((s8 *)arg0 + 0) = TBoss2PhotonBullet__name;
    VecCopy((Vec *)(arg0 + 0xC0), (const Vec *)(arg3));
    VecCopy((Vec *)(arg0 + 0x38), (const Vec *)(arg0 + 0xC0));
    VecCopy((Vec *)(arg0 + 0xB4), (const Vec *)(arg4));
    *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0xA4)) + 0xC) = 3.0f;
    *(f32 *)((s8 *)arg0 + 0xCC) = (0.0f);
    *(f32 *)((s8 *)arg0 + 0xD0) = (0.0f);
    *(f32 *)((s8 *)arg0 + 0xD4) = (0.0f);
    *(f32 *)((s8 *)arg0 + 0xB0) = farg0;
    *(s32 *)((s8 *)arg0 + 0xD8) = 0;
    *(s32 *)((s8 *)arg0 + 0xDC) = 0;
    *(f32 *)((s8 *)arg0 + 0xE0) = (0.0f);
    *(s32 *)((s8 *)arg0 + 0xE4) = 0;
    return arg0;
}

}


typedef struct Pad_80039140 {
    u8 pad0[0x10];
    void *parent;
    u8 pad14[8];
    s32 unk1C;
    u8 pos[8];
    u8 unk28[4];
    s32 level;
    s32 shots;
    s32 timer;
} Pad_80039140;

struct S_80039288 {
    const char *f0;
    u8 pad4[0x14];
    void *vt;
    s32 f1c;
    u8 v20[8];
    u8 v28[4];
    s32 f2c, f30, f34;
};

extern "C" {
void __ct__7TObjectFP7TObject(void *, void *);

extern void *__vt__15TBoss2PhotonPad[];
s32 get_instance__13TBoss2DeRolLeFv(void);
void *__nw__7TObjectFUl(u32);
S_80039288 *__ct__15TBoss2PhotonPadFv(S_80039288 *o, void *parent, s32 arg2, void *arg3, s32 arg4);
void render_shadows__7TObjectFv(void);

void TBoss2PhotonPad::render() {  }
void TBoss2PhotonPad::run_task() {
    Pad_80039140 *self = (Pad_80039140 *)this;
    void *inst;
    void *p;

    self->timer--;
    if (self->timer <= 0) {
        inst = (void *)get_instance__13TBoss2DeRolLeFv();
        if (inst != NULL) {
            p = __nw__7TObjectFUl(0xE8);
            if (p != NULL) {
                ((void *(*)(void *, void *, void *, s32, void *, f32))TBoss2PhotonBullet__ct)(p, self->parent, inst, self->unk1C, self->pos, (1.5f) * TBoss2PhotonPad__bullet_level_param_table[self->level].d);
            }
        }
        self->timer = TBoss2PhotonPad__bullet_level_param_table[self->level].b;
        rotate_xz_pair_by_angle((f32 *)self->pos, (f32 *)self->unk28, (s32)(TBoss2PhotonPad__bullet_level_param_table[self->level].c / TBoss2PhotonPad__bullet_level_param_table[self->level].a));
        self->shots--;
        if (self->shots == 0) {
            queue_destruction__7TObjectFv(self);
        }
    }
}
}
TBoss2PhotonPad::~TBoss2PhotonPad() {

}
extern "C" {
S_80039288 *__ct__15TBoss2PhotonPadFv(S_80039288 *o, void *parent, s32 arg2, void *arg3, s32 arg4) {
    __ct__7TObjectFP7TObject(o, parent);
    o->vt = (void *)__vt__15TBoss2PhotonPad;
    o->f0 = TBoss2PhotonPad__name;
    o->f1c = arg2;
    o->f2c = arg4;
    VecCopy((Vec *)o->v20, (const Vec *)arg3);
    rotate_xz_pair_by_angle((f32 *)o->v20, (f32 *)o->v28, (s32)(-(TBoss2PhotonPad__bullet_level_param_table[o->f2c].c / 2)));
    o->f30 = TBoss2PhotonPad__bullet_level_param_table[o->f2c].a;
    o->f34 = 0;
    return o;
}

void vfunc_6__8TObjBaseFPsl(); void apply_object_set_data__8TObjBaseFPv(); void reset_motion_fields__14TObjCollidableFv();
void get_center__8TObjBaseFv(); void update_object_view_visibility__8TObjBaseFff(); void classify_actor_view_detail__8TObjBaseFfff();
void get_name__8TObjBaseFv(); void interact__14TObjCollidableFl(); void call_vt13_with_default__13TUnk_804928CCFPvPvl();
void area_attack_deliver_direct__13TUnk_804928CCFPvlPvf(); void vfunc_16__13TUnk_804928CCFPvPv(); void call_vt16_with_default__13TUnk_804928CCFPvPv();
void area_attack_deliver_physical__13TUnk_804928CCFPvPvf(); void vfunc_19__13TUnk_804928CCFPv(); void area_attack_apply_recoil__13TUnk_804928CCFPvf();
void area_attack_receive_direct__13TUnk_804928CCFPvPfPv(); void apply_hit_if_active__13TUnk_804928CCFPvPf();
void *__vt__18TBoss2PhotonBullet[23] = {
    0, 0, (void *)__dt__18TBoss2PhotonBulletFv, (void *)run_task__18TBoss2PhotonBulletFv, (void *)render__18TBoss2PhotonBulletFv, (void *)render_shadows__7TObjectFv, (void *)vfunc_6__8TObjBaseFPsl, (void *)apply_object_set_data__8TObjBaseFPv, (void *)reset_motion_fields__14TObjCollidableFv, (void *)get_center__8TObjBaseFv, (void *)update_object_view_visibility__8TObjBaseFff, (void *)classify_actor_view_detail__8TObjBaseFfff, (void *)get_name__8TObjBaseFv, (void *)interact__14TObjCollidableFl, (void *)call_vt13_with_default__13TUnk_804928CCFPvPvl, (void *)area_attack_deliver_direct__13TUnk_804928CCFPvlPvf, (void *)vfunc_16__13TUnk_804928CCFPvPv, (void *)call_vt16_with_default__13TUnk_804928CCFPvPv, (void *)area_attack_deliver_physical__13TUnk_804928CCFPvPvf, (void *)vfunc_19__13TUnk_804928CCFPv, (void *)area_attack_apply_recoil__13TUnk_804928CCFPvf, (void *)area_attack_receive_direct__13TUnk_804928CCFPvPfPv, (void *)apply_hit_if_active__13TUnk_804928CCFPvPf
};
}
