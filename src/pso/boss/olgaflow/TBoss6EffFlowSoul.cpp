#define TOBJECT_OUT_OF_LINE_HELPERS
#pragma readonly_strings on
#include "pso/boss/olgaflow/TBoss6EffFlowSoul.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/vector.h"

#include "types.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/boss/olgaflow/TBoss6Type2.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/effect/particle/TParticleCtrl_800874F4.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/system/task/TObject.h"

extern "C" {
extern s32 __vt__17TBoss6EffFlowSoul[];

const char *TBoss6EffFlowSoul__name = "TBoss6EffFlowSoul";

struct Vec_8036A6B0 { f32 x, y, z; };

struct Soul_8036A6B0 {
    u8 pad0[0x1c];
    s32 f1c;
    void *f20;
    u16 player;
    u8 pad26[0x28 - 0x26];
    Vec_8036A6B0 pos;
    s32 duration;
    s32 age;
};

s32 is_state_1f__14TBoss6PlotFalzFUi(u32 arg0);
void subtract_vector(Vec_8036A6B0 *, Vec_8036A6B0 *);
void vec3_add_to(Vec_8036A6B0 *, Vec_8036A6B0 *);

void TBoss6EffFlowSoul::run_task() {
    Soul_8036A6B0 *self = (Soul_8036A6B0 *)this;
    Vec_8036A6B0 target;
    Vec_8036A6B0 d;
    u8 *p;
    f32 remain;
    f32 k;

    if (((TObjEneDD *)self)->query_teammate_state() != 0) {
        return;
    }
    if (self->player == 0xFFFF) {
        ((TBoss6Type2 *)(self->f1c))->copy_pos_620((s32)&target);
    } else {
        p = (u8 *)get_player_by_client_id(self->player);
        if (p != NULL && is_state_1f__14TBoss6PlotFalzFUi((u32)p) != 0) {
            VecCopy((Vec *)&target, (const Vec *)((Vec_8036A6B0 *)(p + 0x38)));
            target.y += 10.0f;
        } else {
            ((TObject *)self)->queue_destruction();
            return;
        }
    }
    remain = (f32)(self->duration - self->age);
    if (remain <= 1e-05f) {
        VecCopy((Vec *)&self->pos, (const Vec *)&target);
    } else {
        VecCopy((Vec *)&d, (const Vec *)&target);
        subtract_vector(&d, &self->pos);
        k = 1.0f / remain;
        d.x *= k;
        d.y *= k;
        d.z *= k;
        vec3_add_to(&self->pos, &d);
    }
    if (self->f20 != NULL) {
        ((TParticleCtrl *)self->f20)->set_position(&self->pos);
    }
    self->age++;
    if (self->age > self->duration) {
        ((TObject *)self)->queue_destruction();
    }
}

}

TBoss6EffFlowSoul::~TBoss6EffFlowSoul() {
    if (m_20 != nullptr) TParticleCtrl::release(m_20);
}

extern "C" {
void __ct__7TObjectFP7TObject(void *, void *);
extern const char *TBoss6EffFlowSoul__name;
u8 *TBoss6EffFlowSoul__ct(u8 *boss6_eff_flow_soul, u8 *arg1, u8 *arg2, s16 arg3, s32 arg4) {
    u8 *particle_emitter;
    __ct__7TObjectFP7TObject(boss6_eff_flow_soul, arg1);
    *(s32 **)((s8 *)boss6_eff_flow_soul + 0x18) = __vt__17TBoss6EffFlowSoul;
    *(s32 *)((s8 *)boss6_eff_flow_soul + 0) = (s32) TBoss6EffFlowSoul__name;
    *(u8 **)((s8 *)boss6_eff_flow_soul + 0x1C) = arg1;
    VecCopy((Vec *)(boss6_eff_flow_soul + 0x28), (const Vec *)arg2);
    *(s16 *)((s8 *)boss6_eff_flow_soul + 0x24) = arg3;
    *(s32 *)((s8 *)boss6_eff_flow_soul + 0x34) = arg4;
    particle_emitter = (u8 *)(create_particle_emitter((boss6_eff_flow_soul + 0x28), 0x225));
    ((TBoss6EffFlowSoul *)boss6_eff_flow_soul)->m_20 = particle_emitter;
    if (particle_emitter != NULL) {
        ((TParticleCtrl *)(((TBoss6EffFlowSoul *)boss6_eff_flow_soul)->m_20))->set_flags(0x40);
    }
    *(s32 *)((s8 *)boss6_eff_flow_soul + 0x38) = 0;
    return boss6_eff_flow_soul;
}

}
