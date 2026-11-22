#include "types.h"
#include "pso/npc/TObjNpcNurseBase.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/task/TMainTask.h"

#pragma readonly_strings on

const char *bm_n_nurse_i_body_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_nurse_i_body_model_names[2] = { "n_nurse_i_body.nj", NULL };
BmlResourceDescriptor bm_n_nurse_i_body_resource_descriptor = { "bm_n_nurse_i_body.bml", bm_n_nurse_i_body_model_names, bm_n_nurse_i_body_motion_names, 1, 0 };
const char *TObjNpcNurseBase__name = "TObjNpcNurseBase";
BmlResource *TObjNpcNurseBase__shared_model_resource;

void *TObjNpcNurseBase__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcNurseBase(control, set_data);
}

void TObjNpcNurseBase::free_shared_data() {
    if (TObjNpcNurseBase__shared_model_resource != NULL) {
        delete TObjNpcNurseBase__shared_model_resource;
        TObjNpcNurseBase__shared_model_resource = NULL;
    }
}

void TObjNpcNurseBase::load_shared_data() {
    BmlResource *resource = new BmlResource(1, &bm_n_nurse_i_body_resource_descriptor, 0, 0, NULL);
    TObjNpcNurseBase__shared_model_resource = resource;
}

TObjNpcNurseBase::~TObjNpcNurseBase() {}

TObjNpcNurseBase::TObjNpcNurseBase(TObject *parent, void *set_data) : TUnk_804A8640(parent) {
    this->m_name = TObjNpcNurseBase__name;
    this->apply_set_data(set_data);
    init_position_vectors();
    this->model = (void *)TObjNpcNurseBase__shared_model_resource->models->model;
    this->texlist = (saddr)TObjNpcNurseBase__shared_model_resource->models->m_c;
    this->setup_common();
}
