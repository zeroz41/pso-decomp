#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/BmlResource.h"
#include "pso/enemy/morfos/TObjEneMorfosArm.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/enemy/morfos/TObjEneMorfos.h"
#include "pso/system/task/TObject.h"
#include "pso/system/MatrixStack.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/object/base/TObjBase.h"

#pragma readonly_strings on

extern "C" {
const char *TObjEneMorfosArm__name = "TObjEneMorfosArm";
TObjMotionAction morfos_arm_motion_params[1] = {
    { MOTION_MODE_ONCE, 0, 0, 0.7f, 0x4 },
};
extern const char *TObjEneMorfosArm__name;
BmlResource *TObjEneMorfosArm__parent_morfos_instance;
}

void TObjEneMorfosArm::render() {
    if (TObjEneMorfosArm__parent_morfos_instance == NULL) {
        queue_destruction();
        return;
    }
    push_matrix();
    post_translate_matrix(&this->position.x);
    rotate_matrix_y(0, this->rotation_y);
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(this->texlist));
    TObjPlayer::toggle_particle_effect();
    draw();
    TParticleCtrl::end_effect_render();
    pop_matrix();
}

void TObjEneMorfosArm::run_task() {
    advance_animation();
    if (morfos == NULL) {
        queue_destruction();
        return;
    }
    VecCopy(&position, morfos->get_arm_point());
    rotation_y = morfos->get_rotation_y();
    if (motion_flags & 0x10) {
        queue_destruction();
    }
}

TObjEneMorfosArm::~TObjEneMorfosArm() {

}

TObjEneMorfosArm::TObjEneMorfosArm(TObject *parent, TObjEneMorfos *owner) : TObjMotion(parent) {
    BmlModelEntry *resource;
    m_name = TObjEneMorfosArm__name;
    morfos = owner;
    morfos_id = morfos->get_entity_id();
    VecCopy(&position, morfos->get_arm_point());
    rotation_y = morfos->get_rotation_y();
    model = TObjEneMorfosArm__parent_morfos_instance->models[0].model;
    resource = TObjEneMorfosArm__parent_morfos_instance->models;
    texlist = resource->texlist;
    set_action_table(morfos_arm_motion_params);
    set_motion_list(TObjEneMorfosArm__parent_morfos_instance->motions);
    requested_action = 0;
    set_animation(requested_action);
    set_requested_action(requested_action);
}


void TObjEneMorfosArm::free_global() {  }


TObjEneMorfosArm *TObjEneMorfosArm::create(TObject *parent, TObjEneMorfos *owner) {
    return new TObjEneMorfosArm(parent, owner);
}

void TObjEneMorfosArm::init_global() {
    TObjEneMorfosArm__parent_morfos_instance = TObjEneMorfos::get_instance();
}

