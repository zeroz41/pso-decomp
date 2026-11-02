#pragma readonly_strings on
#include "pso/TBoss6EffFlowSoul.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/system/vector.h"

#include "types.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/boss/TBoss6Type2.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/misc/TNowLoading.h"
#include "pso/TParticleCtrl.h"

extern "C" {

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

void *get_player_by_client_id(s32 i);
s32 is_state_1f__14TBoss6PlotFalzFUi(u32 arg0);
void subtract_vector(Vec_8036A6B0 *, Vec_8036A6B0 *);
void vec3_add_to(Vec_8036A6B0 *, Vec_8036A6B0 *);
extern const f32 lbl_805E0370;
extern const f32 lbl_805E0374;
extern const f32 lbl_805E0378;

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
            target.y += lbl_805E0370;
        } else {
            queue_destruction__7TObjectFv(self);
            return;
        }
    }
    remain = (f32)(self->duration - self->age);
    if (remain <= lbl_805E0374) {
        VecCopy((Vec *)&self->pos, (const Vec *)&target);
    } else {
        VecCopy((Vec *)&d, (const Vec *)&target);
        subtract_vector(&d, &self->pos);
        k = lbl_805E0378 / remain;
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
        queue_destruction__7TObjectFv(self);
    }
}

}

TBoss6EffFlowSoul::~TBoss6EffFlowSoul() {
    if (m_20 != nullptr) TParticleCtrl::release(m_20);
}
