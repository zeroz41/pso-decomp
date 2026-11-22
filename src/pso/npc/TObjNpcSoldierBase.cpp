#include "types.h"
#include "pso/npc/TObjNpcSoldierBase.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/task/TMainTask.h"

#pragma readonly_strings on

const char *bm_n_gunb2_i_body_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_gunb2_i_body_model_names[2] = { "n_gunb2_i_body.nj", NULL };
BmlResourceDescriptor TObjNpcSoldierBase__body_resource_desc = { "bm_n_gunb2_i_body.bml", bm_n_gunb2_i_body_model_names, bm_n_gunb2_i_body_motion_names, 1, 0 };
const char *TObjNpcSoldierBase__name = "TObjNpcSoldierBase";
BmlResource *TObjNpcSoldierBase__shared_model_resource;

void *TObjNpcSoldierBase__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcSoldierBase(control, set_data);
}

void TObjNpcSoldierBase::release_static_instance() {
    if (TObjNpcSoldierBase__shared_model_resource != NULL) {
        delete TObjNpcSoldierBase__shared_model_resource;
        TObjNpcSoldierBase__shared_model_resource = NULL;
    }
}

void TObjNpcSoldierBase::load_shared_resource() {
    BmlResource *resource = new BmlResource(1, &TObjNpcSoldierBase__body_resource_desc, 0, 0, NULL);
    TObjNpcSoldierBase__shared_model_resource = resource;
}

TObjNpcSoldierBase::~TObjNpcSoldierBase() {}

TObjNpcSoldierBase::TObjNpcSoldierBase(TObject *parent, void *set_data) : TUnk_804A9F50(parent) {
    this->m_name = TObjNpcSoldierBase__name;
    this->apply_set_data(set_data);
    init_position_vectors();
    this->model = (void *)TObjNpcSoldierBase__shared_model_resource->models->model;
    this->texlist = (saddr)TObjNpcSoldierBase__shared_model_resource->models->m_c;
    this->setup_common();
}
