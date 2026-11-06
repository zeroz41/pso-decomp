#include "types.h"
#include "pso/unk/text_800870BC.h"
#include "pso/system/task/TObject_8001A448.h"
#include "pso/weapon/shoot/TItemShootParticle.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/effect/particle/TParticleCtrl.h"

struct TItemShootParticle_8011B77C { u8 pad[0x18]; void *vt; u8 pad1c[0x58 - 0x1c]; u32 parts[2]; };

struct TItemShootParticle_8011B7FC { u32 f0; u8 pad4[0x14]; void *vt; u8 pad1c[0x58 - 0x1c]; void *parts[2]; s16 s60; };

extern "C" {
void __dt__10TItemShootFv(void *self, s32 flag);
void __dl__7TObjectFPv(void *p);
extern void *__vt__18TItemShootParticle[];
TItemShootParticle_8011B77C *__dt__18TItemShootParticleFv(TItemShootParticle_8011B77C *self, s16 flag);
void __ct__10TItemShootFPvPC3VecPC3Vecf(void *self, void *a, void *b, void *c, f32 f);
extern u32 item_shoot_particle_class_name;
TItemShootParticle_8011B7FC *TItemShootParticle__ct(TItemShootParticle_8011B7FC *self, void *a, void *b, void *c, f32 f);
#pragma push
#pragma opt_propagation off
s32 TItemShootParticle::spawn_slot_emitter(s32 arg1, s32 arg2) {
    s32 temp_r31;
    if ((arg2 >= 0) && (arg2 < 2)) {
        temp_r31 = (arg2 * 4) + 0x58;
        TParticleCtrl::release((void *)*(s32 *)((s8 *)((u8 *)this) + temp_r31));
        *(s32 *)((s8 *)((u8 *)this) + temp_r31) = (s32)spawn_particle_effect_with_rotation((((u8 *)this) + 0x1C), (((u8 *)this) + 0x28), arg1, (s32) (u16) (this->m_60 | 0x40));
        return *(s32 *)((s8 *)((u8 *)this) + temp_r31);
    }
    return 0;
}
#pragma pop

TItemShootParticle_8011B77C *__dt__18TItemShootParticleFv(TItemShootParticle_8011B77C *self, s16 flag) {
    s32 i;
    if (self != 0) {
        self->vt = __vt__18TItemShootParticle;
        for (i = 0; i != 2; i++) {
            TParticleCtrl::release((void *)self->parts[i]);
        }
        __dt__10TItemShootFv(self, 0);
        if (flag > 0) {
            __dl__7TObjectFPv(self);
        }
    }
    return self;
}
TItemShootParticle_8011B7FC *TItemShootParticle__ct(TItemShootParticle_8011B7FC *self, void *a, void *b, void *c, f32 f) {
    s32 i;
    __ct__10TItemShootFPvPC3VecPC3Vecf(self, a, b, c, f);
    self->vt = __vt__18TItemShootParticle;
    self->f0 = item_shoot_particle_class_name;
    self->s60 = 0;
    for (i = 0; i < 2; i++) {
        self->parts[i] = 0;
    }
    disallow_rendering__7TObjectFv((TObject *)self);
    return self;
}

}
