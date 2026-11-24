#include "types.h"
#include "pso/npc/TObjNpcMaleDwarf.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/task/TMainTask.h"

#pragma readonly_strings on

const char *bm_n_efsm_i_body_3_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_efsm_i_body_3_model_names[2] = { "n_efsm_i_body_3.nj", NULL };
BmlResourceDescriptor bm_n_efsm_i_body_3_resource_descriptor = { "bm_n_efsm_i_body_3.bml", bm_n_efsm_i_body_3_model_names, bm_n_efsm_i_body_3_motion_names, 1, 0 };
const char *TObjNpcMaleDwarf::name = "TObjNpcMaleDwarf";
BmlResource *TObjNpcMaleDwarf::shared_model_resource;

void *TObjNpcMaleDwarf::create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcMaleDwarf(control, set_data);
}

void TObjNpcMaleDwarf::unload_static_data() {
    if (shared_model_resource != NULL) {
        delete shared_model_resource;
        shared_model_resource = NULL;
    }
}

void TObjNpcMaleDwarf::load_shared_resource() {
    BmlResource *resource = new BmlResource(1, &bm_n_efsm_i_body_3_resource_descriptor, 0, 0, NULL);
    shared_model_resource = resource;
}

TObjNpcMaleDwarf::~TObjNpcMaleDwarf() {}

TObjNpcMaleDwarf::TObjNpcMaleDwarf(TObject *parent, void *set_data) : TObjNpcMale(parent) {
    this->m_name = name;
    this->apply_set_data(set_data);
    init_position_vectors();
    this->model = (void *)shared_model_resource->models->model;
    this->texlist = shared_model_resource->models->texlist;
    this->setup_common();
}
