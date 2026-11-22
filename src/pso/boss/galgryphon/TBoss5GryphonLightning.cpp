#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/boss/galgryphon/TBoss5GryphonLightning.h"
#include "pso/boss/galgryphon/TBoss5GryphonLightningWing.h"
#include "pso/boss/galgryphon/TBoss5GryphonLightningEff.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/system/task/TObject_80019A50.h"
#include "types.h"
#include "pso/unk/text_80087278.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx/GeoTypes.h>
#include "pso/system/vector.h"
#include "pso/effect/particle/TParticleCtrl.h"

void TBoss5GryphonLightningWing::get_wing_position(Vec *out) {
    VecCopy(out, &this->end);
}

void TBoss5GryphonLightningWing::copy_position(void *out) {
    VecCopy((Vec *)out, &this->start);
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

extern "C" {
u8 *__ct__25TBoss5GryphonLightningEffFv(void *, s32, s32, s32, f32, f32, f32);
extern s32 tl_07;
#pragma fp_contract on
void TBoss5GryphonLightning::spawn_gryphon_lightning() {
    u8 *self = (u8 *)this;
  unsigned char temp_r3;
  u32 temp_r4;
  u8 *temp_r3_2;
  u8 *var_r0;
  temp_r4 = *((u32 *) (((s8 *) self) + 0x94));
  temp_r3 = temp_r4 >> 0x1FU;
  *((u32 *) (((s8 *) self) + 0x94)) = (temp_r4 + 1);
  if ((((temp_r4 & 1) ^ temp_r3) - temp_r3) == 0)
  {
    temp_r3_2 = (u8 *) (u8 *)TObject::operator new(0x264);
    var_r0 = (u8 *) temp_r3_2;
    if (var_r0 != 0)
    {
      var_r0 = (u8 *) __ct__25TBoss5GryphonLightningEffFv(temp_r3_2, tl_07, (saddr)(self + 0x48), *((s32 *) (((s8 *) self) + 0x90)), *((f32 *) (((s8 *) self) + 0x88)), *((f32 *) (((s8 *) self) + 0x8C)), *((f32 *) (((s8 *) self) + 0x1C)));
    }
    TBoss5GryphonLightningEff__sub_80325064(var_r0);
  }
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
        this->segments[i].w = 0.0f;
    }
    this->life_progress = 0.0f;
    this->grow_progress = 0.0f;
    this->segment_count = 1;
}
#pragma pop
