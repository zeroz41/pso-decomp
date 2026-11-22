#include "types.h"
#include "pso/boss/galgryphon/TBoss5GryphonLightningWing.h"

extern "C" {

int VecCopy__FP3VecPC3Vec(s32, s32, s32);

void TBoss5GryphonLightningWing::get_wing_position(Vec *out) {
    s32 self = (saddr)this;
    VecCopy__FP3VecPC3Vec((saddr)out, self + 0x2C, self);
}

}
