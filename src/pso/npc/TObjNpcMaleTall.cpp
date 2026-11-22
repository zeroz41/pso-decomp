#include "types.h"
#include "pso/npc/TObjNpcMaleTall.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/task/TMainTask.h"

#pragma readonly_strings on

const char *bm_n_etm_i_body_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_etm_i_body_model_names[2] = { "n_etm_i_body.nj", NULL };
BmlResourceDescriptor bm_n_etm_i_body_resource_descriptor = { "bm_n_etm_i_body.bml", bm_n_etm_i_body_model_names, bm_n_etm_i_body_motion_names, 1, 0 };
const char *TObjNpcMaleTall__name = "TObjNpcMaleTall";
BmlResource *TObjNpcMaleTall__shared_model_resource;

void *TObjNpcMaleTall__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcMaleTall(control, set_data);
}

void TObjNpcMaleTall::destroy_instance() {
    if (TObjNpcMaleTall__shared_model_resource != NULL) {
        delete TObjNpcMaleTall__shared_model_resource;
        TObjNpcMaleTall__shared_model_resource = NULL;
    }
}

void TObjNpcMaleTall::load_resource_instance() {
    BmlResource *resource = new BmlResource(1, &bm_n_etm_i_body_resource_descriptor, 0, 0, NULL);
    TObjNpcMaleTall__shared_model_resource = resource;
}

TObjNpcMaleTall::~TObjNpcMaleTall() {}

TObjNpcMaleTall::TObjNpcMaleTall(TObject *parent, void *set_data) : TUnk_804A9F50(parent) {
    this->m_name = TObjNpcMaleTall__name;
    this->apply_set_data(set_data);
    init_position_vectors();
    this->model = (void *)TObjNpcMaleTall__shared_model_resource->models->model;
    this->texlist = (saddr)TObjNpcMaleTall__shared_model_resource->models->m_c;
    this->setup_common();
}
