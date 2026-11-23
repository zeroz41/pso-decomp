#include "pso/system/BmlAccessors.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/boss/goldragon/TBoss8Dragon_80065C90.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/boss/galgryphon/TBoss5Gryphon.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/boss/goldragon/TBoss8Dragon_8005D700.h"
#include "pso/boss/galgryphon/TBoss5GryphonShockWave.h"
#include "pso/boss/galgryphon/Boss5GryphonBehavior.h"
#include "pso/system/task/TObject_80019A50.h"

#include "pso/system/vector.h"
#include "pso/boss/galgryphon/TBoss5GryphonTornado.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/task/TObject.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/MatrixTransforms.h"

static const s32 lbl_80437F40[3] = {0x208, 0x20A, 0x20B};
const char *lbl_805D2818 = "TBoss5GryphonShockWave";

extern "C" {
const s32 *gryphon_shockwave_particle_ids_ptr;
}

void TBoss5GryphonShockWave::render() {  }


void TBoss5GryphonShockWave::run_task() {
    TParticleCtrl *particle;
    if (this->owner->get_flag_bit6() != 0) {
        this->queue_destruction();
        return;
    }
    switch (this->state) {
    case 0:
        this->state = 1;
    case 1:
        TBoss8Dragon::eval_bezier_curve(this->path, 3, 0, &this->position, (f32)this->frame / (f32)this->duration);
        if (this->trail == NULL) {
            this->trail = spawn_continuous_particle_effect_with_flags(&this->position,
                                                                       gryphon_shockwave_particle_ids_ptr[0], 0x40);
        }
        if (this->trail != NULL) {
            this->trail->set_position(&this->position);
        }
        if (this->frame++ > this->duration) {
            this->frame = 0;
            this->state = 2;
        }
        break;
    case 2:
        particle = spawn_particle_effect_with_flags(&this->position, gryphon_shockwave_particle_ids_ptr[1], 0x40);
        if (particle != NULL) {
            attach_particle_model(particle, get_bml_model(boss5_gryphon_bml_resource, 0), boss5_gryphon_texture_list,
                                  get_bml_motion(boss5_gryphon_bml_resource, 0), 0, 1.0f);
        }
        spawn_particle_effect_with_flags(&this->position, gryphon_shockwave_particle_ids_ptr[2], 0x40);
        play_sound_effect(0x40033C13, &this->position, 0, 0);
        TBoss5Gryphon::apply_shockwave_hit(TBoss5Gryphon::get_instance(), &this->position);
        TBoss5GryphonTornado::spawn(this->m_up, this->owner, &this->position, this->target_client_id);
        this->state = 3;
        this->queue_destruction();
        break;
    case 3:
        break;
    }
}

TBoss5GryphonShockWave::~TBoss5GryphonShockWave() {
    if (this->trail != NULL) {
        this->trail->queue_destruction();
        this->trail = NULL;
    }
}

TBoss5GryphonShockWave::TBoss5GryphonShockWave(TObject *parent, TBoss5Gryphon *owner, Vec *origin, Vec *target,
                                               Vec *velocity, u16 target_client_id)
    : TObject(parent) {
    Vec to_target;
    m_name = lbl_805D2818;
    VecCopy(&this->path[0].pos, origin);
    VecCopy(&this->path[1].pos, origin);
    vec3_add_to(&this->path[1].pos, velocity);
    VecCopy(&this->path[2].pos, target);
    this->path[2].pos.y = 5.0f;
    VecCopy(&this->position, &this->path[0].pos);
    this->target_client_id = target_client_id;
    this->owner = owner;
    this->trail = NULL;
    VecCopy(&to_target, &this->position);
    subtract_vector(&to_target, target);
    this->duration = 0.07f * normalize_vector_safe(&to_target);
    if (this->duration < 30) {
        this->duration = 30;
    }
    this->frame = 0;
    this->state = 0;
}

void TBoss5GryphonShockWave::release_particle_table() {  }
void TBoss5GryphonShockWave::select_particle_table() {
    switch (TBoss8Dragon__sub_8005D700()) {
    case 0:
        gryphon_shockwave_particle_ids_ptr = lbl_80437F40;
        break;
    }
}
