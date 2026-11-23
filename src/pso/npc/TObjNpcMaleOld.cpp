#include "types.h"
#include "pso/npc/TObjNpcMaleOld.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/task/TMainTask.h"

#pragma readonly_strings on

const char *bm_n_eom_i_body_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_eom_i_body_model_names[2] = { "n_eom_i_body.nj", NULL };
BmlResourceDescriptor bm_n_eom_i_body_resource_descriptor = { "bm_n_eom_i_body.bml", bm_n_eom_i_body_model_names, bm_n_eom_i_body_motion_names, 1, 0 };
const char *TObjNpcMaleOld__name = "TObjNpcMaleOld";
BmlResource *TObjNpcMaleOld__shared_model_resource;

void *TObjNpcMaleOld__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcMaleOld(control, set_data);
}

void TObjNpcMaleOld::destroy_static_instance() {
    if (TObjNpcMaleOld__shared_model_resource != NULL) {
        delete TObjNpcMaleOld__shared_model_resource;
        TObjNpcMaleOld__shared_model_resource = NULL;
    }
}

void TObjNpcMaleOld::load_resource_instance() {
    BmlResource *resource = new BmlResource(1, &bm_n_eom_i_body_resource_descriptor, 0, 0, NULL);
    TObjNpcMaleOld__shared_model_resource = resource;
}

TObjNpcMaleOld::~TObjNpcMaleOld() {}

TObjNpcMaleOld::TObjNpcMaleOld(TObject *parent, void *set_data) : TUnk_804A9F50(parent) {
    this->m_name = TObjNpcMaleOld__name;
    this->apply_set_data(set_data);
    init_position_vectors();
    this->model = (void *)TObjNpcMaleOld__shared_model_resource->models->model;
    this->texlist = TObjNpcMaleOld__shared_model_resource->models->texlist;
    this->setup_common();
}
