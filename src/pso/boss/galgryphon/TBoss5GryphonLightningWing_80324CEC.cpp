#include "types.h"
#include "pso/boss/galgryphon/TBoss5GryphonLightningWing_80324CEC.h"
#include "pso/boss/galgryphon/TBoss5GryphonLightningWing.h"

extern "C" {

int VecCopy__FP3VecPC3Vec(s32, s32, s32);
f64 asin(f64);

f32 TBoss5GryphonLightningWing__sub_80324CEC(f32 x) {
    return (f32) asin(x);
}

void TBoss5GryphonLightningWing::get_wing_position(saddr arg1) {
    s32 arg0 = (saddr)this;
    VecCopy__FP3VecPC3Vec(arg1, arg0 + 0x2C, arg0);
}

}
