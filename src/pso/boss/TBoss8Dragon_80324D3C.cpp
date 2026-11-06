#include "types.h"
#include "pso/boss/TBoss5GryphonLightningWing.h"
#include "pso/boss/TBoss8Dragon.h"
#include "pso/misc/TNowLoading.h"
#include "pso/effect/TParticleCtrl.h"

extern "C" {

s32 eval_bezier_curve__12TBoss8DragonFPviiPvf(void *, int, int, void *, f32);
int VecCopy__FP3VecPC3Vec(s32, s32, s32);

void TBoss8Dragon::copy_position(s32 arg1) {
    s32 arg0 = (s32)this;
    VecCopy__FP3VecPC3Vec(arg1, arg0 + 0x20, arg0);
}

void TBoss5GryphonLightningWing::update_wing_segments() {
    u8 *arg0 = (u8 *)this;
    eval_bezier_curve__12TBoss8DragonFPviiPvf(arg0 + 0x48, (int) (*(s32 *)((s8 *)arg0 + 0x90)), 0, arg0 + 0x20, (f32) (*(f32 *)((s8 *)arg0 + 0x88)));
    eval_bezier_curve__12TBoss8DragonFPviiPvf(arg0 + 0x48, (int) (*(s32 *)((s8 *)arg0 + 0x90)), 0, arg0 + 0x2C, (f32) (*(f32 *)((s8 *)arg0 + 0x8C)));
    if (this->m_38 != 0) {
        ((TParticleCtrl *)this->m_38)->set_position(arg0 + 0x20);
    }
    if (this->m_3c != 0) {
        ((TParticleCtrl *)this->m_3c)->set_position(arg0 + 0x20);
    }
    if (this->m_40 != 0) {
        ((TParticleCtrl *)this->m_40)->set_position(arg0 + 0x2C);
    }
    if (this->m_44 != 0) {
        ((TParticleCtrl *)this->m_44)->set_position(arg0 + 0x2C);
    }
}

}
