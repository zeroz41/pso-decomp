#include "types.h"
#include "pso/boss/galgryphon/TBoss5GryphonLightningWing.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/effect/particle/TParticleCtrl.h"

extern "C" {

int VecCopy__FP3VecPC3Vec(s32, s32, s32);

void TBoss5GryphonLightningWing::copy_position(void *out) {
    s32 self = (saddr)this;
    VecCopy__FP3VecPC3Vec((saddr)out, self + 0x20, self);
}

void TBoss5GryphonLightningWing::update_wing_segments() {
    TBoss8Dragon::eval_bezier_curve(this->segments, this->segment_count, 0, &this->start, this->life_progress);
    TBoss8Dragon::eval_bezier_curve(this->segments, this->segment_count, 0, &this->end, this->grow_progress);
    if (this->effects[0] != 0) {
        this->effects[0]->set_position(&this->start);
    }
    if (this->effects[1] != 0) {
        this->effects[1]->set_position(&this->start);
    }
    if (this->effects[2] != 0) {
        this->effects[2]->set_position(&this->end);
    }
    if (this->effects[3] != 0) {
        this->effects[3]->set_position(&this->end);
    }
}

}
