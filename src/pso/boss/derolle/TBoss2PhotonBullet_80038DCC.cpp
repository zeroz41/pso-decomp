#pragma defer_codegen on

#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/boss/derolle/TBoss2DeRolLe.h"

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

#include "pso/unk/text_80087278.h"

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
f32 TBoss2DeRolLe__sub_80034CF8(void);

s32 project_actor_to_ground(void *, void *, void *);

extern const f32 lbl_805D8268;

extern const f32 lbl_805D826C;

void __dl__7TObjectFPv(void *);
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




void render_shadows__7TObjectFv(void);

}
#define o ((S_80039288 *)this)
TBoss2PhotonPad::TBoss2PhotonPad(TObject *parent, Vec *start, Vec *dir, s32 level) : TObject(parent) {
    o->f0 = TBoss2PhotonPad__name;
    o->f1c = (saddr)start;
    o->f2c = level;
    VecCopy((Vec *)o->v20, dir);
    rotate_xz_pair_by_angle((f32 *)o->v20, (f32 *)o->v28, (s32)(-(TBoss2PhotonPad__bullet_level_param_table[o->f2c].c / 2)));
    o->f30 = TBoss2PhotonPad__bullet_level_param_table[o->f2c].a;
    o->f34 = 0;
}
#undef o

TBoss2PhotonPad::~TBoss2PhotonPad() {

}
extern "C" {
void TBoss2PhotonPad::run_task() {
    Pad_80039140 *self = (Pad_80039140 *)this;
    void *inst;
    void *p;

    self->timer--;
    if (self->timer <= 0) {
        inst = (void *)TBoss2DeRolLe::get_instance();
        if (inst != NULL) {
            new TBoss2PhotonBullet((TObject *)self->parent, (TObjBase *)inst, (Vec *)self->unk1C, (Vec *)self->pos, (1.5f) * TBoss2PhotonPad__bullet_level_param_table[self->level].d);
        }
        self->timer = TBoss2PhotonPad__bullet_level_param_table[self->level].b;
        rotate_xz_pair_by_angle((f32 *)self->pos, (f32 *)self->unk28, (s32)(TBoss2PhotonPad__bullet_level_param_table[self->level].c / TBoss2PhotonPad__bullet_level_param_table[self->level].a));
        self->shots--;
        if (self->shots == 0) {
            ((TObject *)self)->queue_destruction();
        }
    }
}

void TBoss2PhotonPad::render() {  }
}

#define arg0 ((u8 *)this)
TBoss2PhotonBullet::TBoss2PhotonBullet(TObject *parent, TObjBase *owner, Vec *pos, Vec *dir, f32 speed) : TUnk_804928CC(parent, owner) {
    *(const char **)((s8 *)arg0 + 0) = TBoss2PhotonBullet__name;
    VecCopy((Vec *)(arg0 + 0xC0), (const Vec *)(pos));
    VecCopy((Vec *)(arg0 + 0x38), (const Vec *)(arg0 + 0xC0));
    VecCopy((Vec *)(arg0 + 0xB4), (const Vec *)(dir));
    *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0xA4)) + 0xC) = 3.0f;
    *(f32 *)((s8 *)arg0 + 0xCC) = (0.0f);
    *(f32 *)((s8 *)arg0 + 0xD0) = (0.0f);
    *(f32 *)((s8 *)arg0 + 0xD4) = (0.0f);
    *(f32 *)((s8 *)arg0 + 0xB0) = speed;
    *(s32 *)((s8 *)arg0 + 0xD8) = 0;
    *(s32 *)((s8 *)arg0 + 0xDC) = 0;
    *(f32 *)((s8 *)arg0 + 0xE0) = (0.0f);
    *(s32 *)((s8 *)arg0 + 0xE4) = 0;
}

TBoss2PhotonBullet::~TBoss2PhotonBullet() {
    if (*(void **)((s8 *)arg0 + 0xE4) != NULL) { ((TObject *)(*(void **)((s8 *)arg0 + 0xE4)))->queue_destruction(); *(s32 *)((s8 *)arg0 + 0xE4) = 0; }
}

#pragma push
#pragma fp_contract on
void TBoss2PhotonBullet::run_task() {
    u8 *object = (u8 *)this;
    if (*(f32 *)((s8 *)object + 0xC4) > 8.7f) {
        *(f32 *)((s8 *)object + 0xE0) += 0.05f;
        if (*(f32 *)((s8 *)object + 0xE0) >= 3.0f) {
            *(f32 *)((s8 *)object + 0xE0) = 3.0f;
        }
        *(f32 *)((s8 *)object + 0xC4) = *(f32 *)((s8 *)object + 0xC4) - *(f32 *)((s8 *)object + 0xE0);
        *(f32 *)((s8 *)object + 0xC0) = 2.0f * *(f32 *)((s8 *)object + 0xB4) + *(f32 *)((s8 *)object + 0xC0);
        *(f32 *)((s8 *)object + 0xC8) = 2.0f * *(f32 *)((s8 *)object + 0xBC) + *(f32 *)((s8 *)object + 0xC8);
    } else {
        *(f32 *)((s8 *)object + 0xC4) = 8.7f;
        *(f32 *)((s8 *)object + 0xC0) = *(f32 *)((s8 *)object + 0xB4) * *(f32 *)((s8 *)object + 0xB0) + *(f32 *)((s8 *)object + 0xC0);
        *(f32 *)((s8 *)object + 0xC8) = *(f32 *)((s8 *)object + 0xBC) * *(f32 *)((s8 *)object + 0xB0) + *(f32 *)((s8 *)object + 0xC8);
    }
    *(f32 *)((s8 *)object + 0x38) = *(f32 *)((s8 *)object + 0xC0);
    *(f32 *)((s8 *)object + 0x40) = *(f32 *)((s8 *)object + 0xC8);
    if (*(u32 *)((s8 *)object + 0xE4) == 0) {
        *(u32 *)((s8 *)object + 0xE4) = (uaddr)spawn_continuous_particle_effect_with_flags(object + 0xC0, 0xDF, 0x40);
    } else {
        ((TParticleCtrl *)(void *)*(uaddr *)((s8 *)object + 0xE4))->set_position(object + 0xC0);
    }
    if (*(s32 *)((s8 *)object + 0xD8) % 15 == 0) {
        if (project_actor_to_ground(object, object + 0x38, object + 0xCC) != 0) {
            *(s32 *)((s8 *)object + 0xDC) |= 1;
        } else {
            *(s32 *)((s8 *)object + 0xDC) &= ~1;
        }
    }
    if (*(f32 *)((s8 *)object + 0x38) <= lbl_805D8268 && *(f32 *)((s8 *)object + 0x38) >= lbl_805D826C) {
        Pair_80038E2C p = lbl_80435B38[0];
        p.b = TBoss2DeRolLe__sub_80034CF8();
        if (((VObj_18_39be15 *)object)->m14((s32 *)lbl_80435B40, (s32 *)&p) != 0) {
            ((TObject *)object)->queue_destruction();
            return;
        }
    }
    (*(s32 *)((s8 *)object + 0xD8))++;
    if (*(s32 *)((s8 *)object + 0xD8) >= 0x78) {
        ((TObject *)object)->queue_destruction();
    }
}

#pragma pop
void TBoss2PhotonBullet::render() {
    if (*(s32 *)((s8 *)arg0 + 0xDC) & 1) {
        Vec scale = { 1.0f, 1.0f, 1.0f };
        TObjEneDD::draw_oriented_shadow((const Vec *)(arg0 + 0x38), (const Vec *)(arg0 + 0xCC), 0, &scale);
    }
}
#undef arg0
