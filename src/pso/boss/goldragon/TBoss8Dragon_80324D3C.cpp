#include "types.h"
#include "pso/boss/galgryphon/TBoss5GryphonLightningWing.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/effect/particle/TParticleCtrl.h"

extern "C" {

s32 eval_bezier_curve__12TBoss8DragonFPviiPvf(void *, int, int, void *, f32);
int VecCopy__FP3VecPC3Vec(s32, s32, s32);

void TBoss5GryphonLightningWing::copy_position(void *out) {
    s32 self = (saddr)this;
    VecCopy__FP3VecPC3Vec((saddr)out, self + 0x20, self);
}

void TBoss5GryphonLightningWing::update_wing_segments() {
    u8 *self = (u8 *)this;
    eval_bezier_curve__12TBoss8DragonFPviiPvf(self + 0x48, (int) (*(s32 *)((s8 *)self + 0x90)), 0, self + 0x20, (f32) (*(f32 *)((s8 *)self + 0x88)));
    eval_bezier_curve__12TBoss8DragonFPviiPvf(self + 0x48, (int) (*(s32 *)((s8 *)self + 0x90)), 0, self + 0x2C, (f32) (*(f32 *)((s8 *)self + 0x8C)));
    if (this->m_38 != 0) {
        ((TParticleCtrl *)this->m_38)->set_position(self + 0x20);
    }
    if (this->m_3c != 0) {
        ((TParticleCtrl *)this->m_3c)->set_position(self + 0x20);
    }
    if (this->m_40 != 0) {
        ((TParticleCtrl *)this->m_40)->set_position(self + 0x2C);
    }
    if (this->m_44 != 0) {
        ((TParticleCtrl *)this->m_44)->set_position(self + 0x2C);
    }
}

}
