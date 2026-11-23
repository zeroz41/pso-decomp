#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/boss/galgryphon/TBoss5GryphonLightning.h"
#include "pso/boss/galgryphon/TBoss5GryphonLightningEff.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/system/task/TObject_80019A50.h"
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include <dolphin/mtx/GeoTypes.h>
#include "pso/system/vector.h"
#include "pso/effect/particle/TParticleCtrl.h"

void TBoss5GryphonLightning::get_end_position(Vec *out) {
    VecCopy(out, &this->end);
}

void TBoss5GryphonLightning::get_start_position(Vec *out) {
    VecCopy(out, &this->start);
}

void TBoss5GryphonLightning::update_endpoints() {
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

#pragma fp_contract on
void TBoss5GryphonLightning::spawn_gryphon_lightning() {
    TBoss5GryphonLightningEff *eff;
    if (this->age++ % 2 == 0) {
        eff = new TBoss5GryphonLightningEff(tl_07, this->segments, this->segment_count, this->life_progress,
                                            this->grow_progress, this->scale);
        eff->set_two_sided();
    }
}

TBoss5GryphonLightning::~TBoss5GryphonLightning() {
    if (this->effects[3] != nullptr) { this->effects[3]->queue_destruction(); this->effects[3] = nullptr; }
    if (this->effects[2] != nullptr) { this->effects[2]->queue_destruction(); this->effects[2] = nullptr; }
    if (this->effects[1] != nullptr) { this->effects[1]->queue_destruction(); this->effects[1] = nullptr; }
    if (this->effects[0] != nullptr) { this->effects[0]->queue_destruction(); this->effects[0] = nullptr; }
}

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_dead_assignments off

extern "C" {
const char *lbl_805D4180 = "TBoss5GryphonLightning";
}

TBoss5GryphonLightning::TBoss5GryphonLightning(TObject *parent, Vec *pos, f32 scale) : TObject(parent) {
    s32 i;
    m_name = lbl_805D4180;
    VecCopy(&this->start, pos);
    VecCopy(&this->end, &this->start);
    this->scale = scale;
    this->age = 0;
    this->effects[0] = spawn_continuous_particle_effect_with_flags(&this->start, 0x20c, 0x40);
    this->effects[1] = spawn_continuous_particle_effect_with_flags(&this->start, 0x20e, 0x40);
    this->effects[2] = spawn_continuous_particle_effect_with_flags(&this->end, 0x20f, 0x40);
    this->effects[3] = spawn_continuous_particle_effect_with_flags(&this->end, 0x216, 0x40);
    for (i = 0; i < 4; i++) {
        VecCopy(&this->segments[i].pos, &this->start);
        this->segments[i].length = 0.0f;
    }
    this->life_progress = 0.0f;
    this->grow_progress = 0.0f;
    this->segment_count = 1;
}
#pragma pop
