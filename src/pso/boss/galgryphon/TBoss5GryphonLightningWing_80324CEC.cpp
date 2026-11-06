#include "types.h"
#include "pso/boss/galgryphon/TBoss5GryphonLightningWing_80324CEC.h"
#include "pso/boss/galgryphon/TBoss5GryphonLightningWing.h"

extern "C" {

int VecCopy__FP3VecPC3Vec(s32, s32, s32);
f64 asin();

f32 TBoss5GryphonLightningWing__sub_80324CEC(void) {
    return (f32) asin();
}

void TBoss5GryphonLightningWing::get_wing_position(s32 arg1) {
    s32 arg0 = (s32)this;
    VecCopy__FP3VecPC3Vec(arg1, arg0 + 0x2C, arg0);
}

}
