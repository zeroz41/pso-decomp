#define TOBJECT_OUT_OF_LINE_HELPERS
#pragma readonly_strings on
#include "pso/boss/olgaflow/TBoss6EffFlowSoul.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/vector.h"

#include "types.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/boss/olgaflow/TBoss6Type2.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/effect/particle/TParticleCtrl_800874F4.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/system/task/TObject.h"

extern "C" {

const char *TBoss6EffFlowSoul__name = "TBoss6EffFlowSoul";

struct Soul_8036A6B0 {
    u8 pad0[0x1c];
    saddr f1c;
    void *f20;
    u16 player;
    u8 pad26[0x28 - 0x26];
    Vec pos;
    s32 duration;
    s32 age;
};

void subtract_vector(Vec *, Vec *);
void vec3_add_to(Vec *, Vec *);

void TBoss6EffFlowSoul::run_task() {
    Soul_8036A6B0 *self = (Soul_8036A6B0 *)this;
    Vec target;
    Vec d;
    u8 *p;
    f32 remain;
    f32 k;

    if (TObjEneDD::query_teammate_state() != 0) {
        return;
    }
    if (self->player == 0xFFFF) {
        ((TBoss6Type2 *)(self->f1c))->copy_pos_620((saddr)&target);
    } else {
        p = (u8 *)get_player_by_client_id(self->player);
        if (p != NULL && TBoss6PlotFalz::is_state_1f((TObjPlayer *)p) != 0) {
            VecCopy((Vec *)&target, (const Vec *)((Vec *)(p + 0x38)));
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
extern const char *TBoss6EffFlowSoul__name;
}

TBoss6EffFlowSoul::TBoss6EffFlowSoul(TObject *parent, Vec *pos, s32 player, s32 duration) : TObject(parent) {
    u8 *boss6_eff_flow_soul = (u8 *)this;
    u8 *particle_emitter;
    m_name = TBoss6EffFlowSoul__name;
    *(u8 **)((s8 *)boss6_eff_flow_soul + 0x1C) = (u8 *)parent;
    VecCopy((Vec *)(boss6_eff_flow_soul + 0x28), (const Vec *)pos);
    *(s16 *)((s8 *)boss6_eff_flow_soul + 0x24) = player;
    *(s32 *)((s8 *)boss6_eff_flow_soul + 0x34) = duration;
    particle_emitter = (u8 *)(create_particle_emitter((boss6_eff_flow_soul + 0x28), 0x225));
    m_20 = particle_emitter;
    if (particle_emitter != NULL) {
        ((TParticleCtrl *)m_20)->set_flags(0x40);
    }
    *(s32 *)((s8 *)boss6_eff_flow_soul + 0x38) = 0;
}
