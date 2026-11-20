#pragma defer_codegen on

#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/boss/barbaray/TBoss7PhotonPad.h"

#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8007E418.h"
#include "pso/boss/barbaray/TBoss7PhotonBullet_802EF26C.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_800BC4C8.h"
#include "pso/boss/barbaray/TBoss7PhotonBullet.h"
#include "pso/player/TUnk_804928CC.h"
#include "pso/unk/text_80087278.h"


#include "pso/boss/barbaray/TBoss7Joint.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"

#pragma fp_contract on
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
    virtual s32 m14(s32 *, void *);
};

struct V2_802EF2AC { s32 x; f32 y; };
struct Ent_802EF74C { s32 a; s32 b; s32 c; f32 d; };

// The bullet level table, the two hit-check arguments and the class names, in their original .rodata order.
extern const Ent_802EF74C boss7_photon_bullet_level_table[3] = {
    { 3, 1, 0x3000, 3.5f },
    { 5, 1, 0x2000, 5.0f },
    { 5, 1, 0x4000, 5.0f },
};
extern const V2_802EF2AC lbl_80474038[1] = { { 0, 3.0f } };
extern const s32 lbl_80474040[2] = { 0x40400000, 1 }; // 3.0f as raw bits, then 1
const char *TBoss7PhotonPad__name = "TBoss7PhotonPad";
const char *TBoss7PhotonBullet__name = "TBoss7PhotonBullet";

struct Bullet_802EF2AC {
    u8 pad0[0x38];
    f32 pos[3];
    u8 pad44[0xB0 - 0x44];
    f32 b0, b4, b8, bc;
    f32 c0, c4, c8;
    f32 cc[3];
    u8 padD8[0xE4 - 0xD8];
    s32 e4;
    u32 e8;
    f32 ec;
    void *f0[2];
};

extern "C" {
s32 VecCopy__FP3VecPC3Vec(void *, void *);
s32 project_actor_to_ground(void *, void *, void *);
extern const f32 lbl_805DEA00;
extern const f32 lbl_805DEA04;
void __dl__7TObjectFPv(void *);
void render_shadows__7TObjectFv(void);
}

typedef struct Pad_802EF604 {
    u8 pad0[0x10];
    void *parent;
    u8 pad14[8];
    s32 unk1C;
    u8 pos[8];
    u8 unk28[4];
    s32 level;
    s32 shots;
    s32 timer;
} Pad_802EF604;

TBoss7PhotonPad::TBoss7PhotonPad(s32 arg1, s32 arg2, s32 arg3, s32 arg4) : TObject((TObject *)arg1) {
    this->m_name = TBoss7PhotonPad__name;
    *(s32 *)((s8 *)this + 0x1C) = arg2;
    *(s32 *)((s8 *)this + 0x2C) = arg4;
    VecCopy__FP3VecPC3Vec(((u8 *)this) + 0x20, (void *)arg3);
    rotate_xz_pair_by_angle((f32 *)(((u8 *)this) + 0x20), (f32 *)(((u8 *)this) + 0x28), (s32)(-(boss7_photon_bullet_level_table[*(s32 *)((s8 *)this + 0x2C)].c / 2)));
    *(s32 *)((s8 *)this + 0x30) = boss7_photon_bullet_level_table[*(s32 *)((s8 *)this + 0x2C)].a;
    *(s32 *)((s8 *)this + 0x34) = 0;
}

TBoss7PhotonPad::~TBoss7PhotonPad() {}

void TBoss7PhotonPad::run_task() {
    Pad_802EF604 *self = (Pad_802EF604 *)this;
    s32 st;

    self->timer--;
    if (self->timer <= 0) {
        st = TBoss7Joint::get_state();
        if (st != 0) {
            new TBoss7PhotonBullet((TObject *)self->parent, (TObjBase *)st, (void *)self->unk1C, self->pos, 1.5f * boss7_photon_bullet_level_table[self->level].d);
        }
        self->timer = boss7_photon_bullet_level_table[self->level].b;
        rotate_xz_pair_by_angle((f32 *)self->pos, (f32 *)self->unk28, (s32)(boss7_photon_bullet_level_table[self->level].c / boss7_photon_bullet_level_table[self->level].a));
        self->shots--;
        if (self->shots == 0) {
            ((TObject *)self)->queue_destruction();
        }
    }
}

void TBoss7PhotonPad::render() {  }

#define arg0 ((u8 *)this)
TBoss7PhotonBullet::TBoss7PhotonBullet(TObject *parent, TObjBase *owner, void *arg3, void *arg4, f32 farg0) : TUnk_804928CC(parent, owner) {
    m_name = TBoss7PhotonBullet__name;
    VecCopy__FP3VecPC3Vec(arg0 + 0x38, (void *) (VecCopy__FP3VecPC3Vec(arg0 + 0xC0, (void *)arg3)));
    VecCopy__FP3VecPC3Vec(arg0 + 0xB4, (void *)arg4);
    *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0xA4)) + 0xC) = 3.0f;
    *(f32 *)((s8 *)arg0 + 0xCC) = 0.0f;
    *(f32 *)((s8 *)arg0 + 0xD0) = 0.0f;
    *(f32 *)((s8 *)arg0 + 0xD4) = 0.0f;
    *(f32 *)((s8 *)arg0 + 0xD8) = 1.0f;
    *(f32 *)((s8 *)arg0 + 0xDC) = 1.0f;
    *(f32 *)((s8 *)arg0 + 0xE0) = 1.0f;
    *(f32 *)((s8 *)arg0 + 0xB0) = farg0;
    *(s32 *)((s8 *)arg0 + 0xE4) = 0;
    *(s32 *)((s8 *)arg0 + 0xE8) = 0;
    *(f32 *)((s8 *)arg0 + 0xEC) = 0.0f;
    *(s32 *)((s8 *)arg0 + 0xF0) = (s32)spawn_continuous_particle_effect_with_flags((arg0 + 0xC0), 0x202, 0x40);
    *(s32 *)((s8 *)arg0 + 0xF4) = (s32)spawn_continuous_particle_effect_with_flags((arg0 + 0xC0), 0x203, 0x40);
}
#undef arg0


TBoss7PhotonBullet::~TBoss7PhotonBullet() {
#define arg0 ((u8 *)this)
    if (*(void **)((s8 *)arg0 + 0xF0) != NULL) { ((TObject *)(*(void **)((s8 *)arg0 + 0xF0)))->queue_destruction(); }
    if (*(void **)((s8 *)arg0 + 0xF4) != NULL) { ((TObject *)(*(void **)((s8 *)arg0 + 0xF4)))->queue_destruction(); }
#undef arg0
}

#pragma push
#pragma opt_loop_invariants off
void TBoss7PhotonBullet::run_task() {
    Bullet_802EF2AC *arg0 = (Bullet_802EF2AC *)this;
    s32 i;
    if (arg0->c4 > 18.7f) {
        arg0->ec += 0.05f;
        if (arg0->ec >= 3.0f) {
            arg0->ec = 3.0f;
        }
        arg0->c4 -= arg0->ec;
        arg0->c0 = (2.0f) * arg0->b4 + arg0->c0;
        arg0->c8 = (2.0f) * arg0->bc + arg0->c8;
    } else {
        arg0->c4 = 18.7f;
        arg0->c0 = arg0->b4 * arg0->b0 + arg0->c0;
        arg0->c8 = arg0->bc * arg0->b0 + arg0->c8;
    }
    arg0->pos[0] = arg0->c0;
    arg0->pos[2] = arg0->c8;
    for (i = 0; i != 2; i++) {
        if (arg0->f0[i] != 0) {
            ((TParticleCtrl *)arg0->f0[i])->set_position(&arg0->c0);
        }
    }
    if (arg0->e4 % 16 == 0) {
        if (project_actor_to_ground(arg0, arg0->pos, arg0->cc) != 0) {
            arg0->e8 |= 1;
        } else {
            arg0->e8 &= ~1;
        }
    }
    if (arg0->pos[0] <= lbl_805DEA00 && arg0->pos[0] >= lbl_805DEA04) {
        V2_802EF2AC v = lbl_80474038[0];
        v.y = TBoss7PhotonBullet::get_target_pos_y();
        if (((VObj_18_39be15 *)(arg0))->m14((s32 *)lbl_80474040, &v) != 0) {
            ((TObject *)arg0)->queue_destruction();
            return;
        }
    }
    arg0->e4++;
    if (arg0->e4 >= 0x78) {
        ((TObject *)arg0)->queue_destruction();
    }
}
#pragma pop


#define arg0 ((u8 *)this)
void TBoss7PhotonBullet::render() {
    if (*(s32 *)((s8 *)arg0 + 0xE8) & 1) {
        TObjEneDD::draw_oriented_shadow((const Vec *)(arg0 + 0x38), (const Vec *)(arg0 + 0xCC), 0, (const Vec *)(arg0 + 0xD8));
    }
}
#undef arg0

