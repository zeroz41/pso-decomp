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
const char *TObjNpcMaleChild::name = "TObjNpcMaleChild";
BmlResource *TObjNpcMaleChild::shared_model_resource;

void *TObjNpcMaleChild::create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcMaleChild(control, set_data);
}

void TObjNpcMaleChild::release_static_instance() {
    if (shared_model_resource != NULL) {
        delete shared_model_resource;
        shared_model_resource = NULL;
    }
}

void TObjNpcMaleChild::load_shared_resource() {
    BmlResource *resource = new BmlResource(1, &bm_n_ecm_i_body_resource_descriptor, 0, 0, NULL);
    shared_model_resource = resource;
}

TObjNpcMaleChild::~TObjNpcMaleChild() {}

TObjNpcMaleChild::TObjNpcMaleChild(TObject *parent, void *set_data) : TObjNpcMale(parent) {
    this->m_name = name;
    this->apply_set_data(set_data);
    init_position_vectors();
    this->model = (void *)shared_model_resource->models->model;
    this->texlist = shared_model_resource->models->texlist;
    this->setup_common();
}
