#include "types.h"
#include "pso/system/vector.h"
#include "pso/TParticleCtrl.h"
#include "pso/enemy/TObjEneRe2Flower_EffCurse3.h"
#include "pso/enemy/TUnk_80493450.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TUnk_804928CC.h"
#include "pso/player/TObjEneRe2Flower_Bomb.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/TObject.h"
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/enemy/TObjEneBeast.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/misc/TNowLoading.h"
#include "pso/player/TObjPlayer.h"
extern "C" { __declspec(section ".sdata2") extern const f32 lbl_805DA000[1] = { 30.0f }; }

typedef struct Vec_800C4A5C {
    f32 x, y, z;
} Vec_800C4A5C;

typedef struct Coll_800C4A5C {
    u8 pad0[0xC];
    f32 radius;
} Coll_800C4A5C;

typedef struct Obj_800C4A5C {
    s32 f0;
    u8 pad4[0x18 - 0x4];
    void *vptr;
    u8 pad1C[0x38 - 0x1C];
    Vec_800C4A5C pos;
    u8 pad44[0xA4 - 0x44];
    Coll_800C4A5C *coll;
    u8 padA8[0xB0 - 0xA8];
    u16 ownerId;
    u8 padB2[0xB4 - 0xB2];
    Vec_800C4A5C start;
    Vec_800C4A5C velA;
    Vec_800C4A5C velB;
    Vec_800C4A5C accel;
    f32 fE4;
    s32 fE8;
    s32 angle;
    f32 fF0;
    s32 fF4;
    s32 fF8;
    s32 fFC;
    s32 f100;
} Obj_800C4A5C;

typedef struct Vec_800C4B78 {
    f32 x, y, z;
} Vec_800C4B78;

typedef struct Ent_800C4B78 {
    u8 pad0[0x38];
    Vec_800C4B78 pos;
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

void __dl__7TObjectFPv(void *);
u16 get_entity_id(void *);
u8 *construct_collision_body(u8 *arg0, s32 arg1, u32 arg2);
f32 sin_table_lookup(int);
f32 cos_table_lookup(int);
Obj_800C4A5C *TObjPlayer__sub_800C4A5C(Obj_800C4A5C *o, void *owner, Vec_800C4A5C *start, s32 angle);
void queue_destruction__7TObjectFv(void *arg0);
void *destroy_and_free__21TObjEneRe2Flower_BombFs(void *arg0, s16 arg1);
void render__21TObjEneRe2Flower_BombFv(u8 *arg0);

}

typedef struct Vec_800C4754 {
    f32 x, y, z;
} Vec_800C4754;

typedef struct Rot_800C4754 {
    s32 x, y, z;
} Rot_800C4754;

typedef struct Coll_800C4754 {
    u8 pad0[0x4];
    f32 height;
    u8 pad8[0x18 - 0x8];
    s32 flags;
} Coll_800C4754;

typedef struct Hit_800C4754 {
    u8 pad0[0x4];
    u8 *tri;
} Hit_800C4754;

struct VBase_800C4754 { char pad[0x18]; };
struct Obj_800C4754 : VBase_800C4754 {
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
    virtual s32 m14(void *, const void *);
    u8 pad1C[0x38 - 0x1C];
    Vec_800C4754 pos;
    u8 pad44[0xA4 - 0x44];
    Coll_800C4754 *coll;
    u8 padA8[0xB0 - 0xA8];
    u16 ownerId;
    u8 padB2[0xB4 - 0xB2];
    Vec_800C4754 start;
    Vec_800C4754 velA;
    Vec_800C4754 velB;
    Vec_800C4754 accel;
    f32 fE4;
    s32 fE8;
    s32 angle;
    f32 fF0;
    s32 fF4;
    s32 fF8;
    void *fFC;
    s32 f100;
};

extern "C" {

s32 *csnVecterUnder(s32 origin, s32 mask);
u32 csnVector(void *, void *, int);
void *spawn_particle_effect_with_rotation(void *pos, void *dir, s32 id, int e);
void TObjEneDD__sub_800C2618(void *p);
void *find_entity_by_id(u16 id);

void vfunc_6__8TObjBaseFPsl();
void interact__14TObjCollidableFl();
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
void run_task__21TObjEneRe2Flower_BombFv(Obj_800C4754 *o);
extern const u32 lbl_8043BC10[5] = { 0xF, 0x40000000, 0x40000000, 0x0, 0x1 };
extern const char lbl_8043BC24[] = "TObjEneRe2Flower_Bomb";
s32 lbl_805D2A50 = (s32)lbl_8043BC24;
void *lbl_804933D8[24] = {
    (void *)0x0, (void *)0x0, (void *)&destroy_and_free__21TObjEneRe2Flower_BombFs, (void *)&run_task__21TObjEneRe2Flower_BombFv,
    (void *)&render__21TObjEneRe2Flower_BombFv, (void *)&render_shadows__7TObjectFv, (void *)&vfunc_6__8TObjBaseFPsl, (void *)&apply_object_set_data__8TObjBaseFPv,
    (void *)&reset_motion_fields__14TObjCollidableFv, (void *)&get_center__8TObjBaseFv, (void *)&update_object_view_visibility__8TObjBaseFff, (void *)&classify_actor_view_detail__8TObjBaseFfff,
    (void *)&get_name__8TObjBaseFv, (void *)&interact__14TObjCollidableFl, (void *)&call_vt13_with_default__13TUnk_804928CCFPvPvl, (void *)&area_attack_deliver_direct__21TObjEneRe2Flower_BombFPvlPvf,
    (void *)&vfunc_16__13TUnk_804928CCFPvPv, (void *)&call_vt16_with_default__13TUnk_804928CCFPvPv, (void *)&area_attack_deliver_physical__13TUnk_804928CCFPvPvf, (void *)&vfunc_19__13TUnk_804928CCFPv,
    (void *)&area_attack_apply_recoil__13TUnk_804928CCFPvf, (void *)&area_attack_receive_direct__13TUnk_804928CCFPvPfPv, (void *)&apply_hit_if_active__13TUnk_804928CCFPvPf, (void *)0x0,
};
#define lbl_8043BC10 ((const Vec_800C4A5C *)lbl_8043BC10)
#define lbl_804933D8 ((s32 *)lbl_804933D8)
void TObjEneRe2Flower_Bomb::render() {
    u8 *arg0 = (u8 *)this;
    if ((s32) this->m_100 != 0) {
        ((TObjEneDD *)(arg0 + 0x38))->draw_oriented_shadow((s32)(arg0 + 0xD8), 0, (u32)0);
    }
}
void TObjEneRe2Flower_Bomb::run_task() {
    Obj_800C4754 *o = (Obj_800C4754 *)this;
    Vec_800C4754 tmp;
    Rot_800C4754 rot;
    Hit_800C4754 *hit;
    f32 d;

    switch (o->fF8) {
    case 0:
        o->fF4++;
        if ((f32)o->fF4 >= (1.5e+02f)) {
            queue_destruction__7TObjectFv(o);
            return;
        }
        if (o->fF4 >= 0x12) {
            o->fF0 -= (0.1f);
        }
        VecCopy((Vec *)&tmp, (const Vec *)&o->start);
        vec3_add_to(&tmp, &o->velB);
        tmp.y += o->fF0 - (3.0f);
        if (csnVector(&o->start, &tmp, 0x1EFF) != 0) {
            queue_destruction__7TObjectFv(o);
            return;
        }
        o->start.x += o->velA.x;
        o->start.y += o->fF0;
        o->start.z += o->velA.z;
        hit = (Hit_800C4754 *)csnVecterUnder((s32)&o->start, 0x16EF);
        if (hit != NULL) {
            o->pos.y = *(f32 *)(hit->tri + 4);
            VecCopy((Vec *)&o->accel, (const Vec *)(hit->tri + 0xC));
            o->f100 = 1;
        } else {
            o->f100 = 0;
        }
        o->pos.x = o->start.x;
        o->pos.z = o->start.z;
        d = o->start.y - o->pos.y;
        if (d > (2e+01f)) {
            o->coll->flags |= 4;
            o->coll->flags &= ~2;
        } else {
            o->coll->flags &= ~4;
            o->coll->flags |= 2;
        }
        o->coll->height = d;
        if (o->fF4 >= 0x14) {
            o->fE8 |= 2;
        }
        if (o->m14(&o->fE4, lbl_8043BC10) != 0) {
            TObjEneDD__sub_800C2618(find_entity_by_id(o->ownerId));
            queue_destruction__7TObjectFv(o);
            return;
        }
    case 1:
        break;
    }
    if (o->fFC == NULL) {
        rot.x = 0x8000;
        rot.y = o->angle;
        rot.z = 0;
        o->fFC = spawn_particle_effect_with_rotation(&o->start, &rot, 0xD0, 0x40);
        if (o->fFC != NULL) {
            ((TParticleCtrl *)(o->fFC))->enable();
        }
    } else {
        ((TNowLoading *)((int)o->fFC))->copy_pos(&o->start);
    }
}

void *TObjEneRe2Flower_Bomb::destroy_and_free(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = lbl_804933D8;
        if (this->m_fc != NULL) { queue_destruction__7TObjectFv((this->m_fc)); this->m_fc = 0; }
        this->destroy_enemy_object(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

Obj_800C4A5C *TObjPlayer__sub_800C4A5C(Obj_800C4A5C *o, void *owner, Vec_800C4A5C *start, s32 angle) {
    f32 s;
    f32 c;
    construct_collision_body((u8 *)o, (s32)owner, (u32)owner);
    o->vptr = lbl_804933D8;
    o->f0 = lbl_805D2A50;
    o->coll->radius = lbl_8043BC10[0].z;
    o->angle = angle;
    o->ownerId = get_entity_id(owner);
    VecCopy((Vec *)&o->start, (const Vec *)start);
    VecCopy((Vec *)&o->pos, (const Vec *)&o->start);
    o->accel.x = (0.0f);
    o->accel.y = (0.0f);
    o->accel.z = (0.0f);
    s = sin_table_lookup(o->angle);
    c = cos_table_lookup(o->angle);
    o->velA.x = (4.0f) * s;
    o->velA.y = (0.0f);
    o->velA.z = (4.0f) * c;
    o->velB.x = (7.0f) * s;
    o->velB.y = (0.0f);
    o->velB.z = (7.0f) * c;
    o->fE4 = (0.0f);
    o->fE8 = 1;
    o->fF0 = (0.0f);
    o->fF4 = 0;
    o->fF8 = 0;
    o->fFC = 0;
    o->f100 = 1;
    return o;
}

}
