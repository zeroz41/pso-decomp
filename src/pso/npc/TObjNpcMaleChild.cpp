#include "types.h"
#include "pso/npc/TObjNpcMaleChild.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/task/TMainTask.h"

#pragma readonly_strings on

const char *bm_n_ecm_i_body_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_ecm_i_body_model_names[2] = { "n_ecm_i_body.nj", NULL };
BmlResourceDescriptor bm_n_ecm_i_body_resource_descriptor = { "bm_n_ecm_i_body.bml", bm_n_ecm_i_body_model_names, bm_n_ecm_i_body_motion_names, 1, 0 };
const char *TObjNpcMaleChild__name = "TObjNpcMaleChild";
BmlResource *TObjNpcMaleChild__shared_model_resource;

void *TObjNpcMaleChild__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcMaleChild(control, set_data);
}

void TObjNpcMaleChild::release_static_instance() {
    if (TObjNpcMaleChild__shared_model_resource != NULL) {
        delete TObjNpcMaleChild__shared_model_resource;
        TObjNpcMaleChild__shared_model_resource = NULL;
    }
}

void TObjNpcMaleChild::load_shared_resource() {
    BmlResource *resource = new BmlResource(1, &bm_n_ecm_i_body_resource_descriptor, 0, 0, NULL);
    TObjNpcMaleChild__shared_model_resource = resource;
}

TObjNpcMaleChild::~TObjNpcMaleChild() {}

TObjNpcMaleChild::TObjNpcMaleChild(TObject *parent, void *set_data) : TUnk_804A9F50(parent) {
    this->m_name = TObjNpcMaleChild__name;
    this->apply_set_data(set_data);
    init_position_vectors();
    this->model = (void *)TObjNpcMaleChild__shared_model_resource->models->model;
    this->texlist = (saddr)TObjNpcMaleChild__shared_model_resource->models->m_c;
    this->setup_common();
}
