#include "types.h"
#include "pso/npc/TObjNpcMaleFat.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/task/TMainTask.h"

#pragma readonly_strings on

const char *bm_n_efm_i_body_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_efm_i_body_model_names[2] = { "n_efm_i_body.nj", NULL };
BmlResourceDescriptor bm_n_efm_i_body_resource_descriptor = { "bm_n_efm_i_body.bml", bm_n_efm_i_body_model_names, bm_n_efm_i_body_motion_names, 1, 0 };
const char *TObjNpcMaleFat::name = "TObjNpcMaleFat";
BmlResource *TObjNpcMaleFat::static_model_resource;

void *TObjNpcMaleFat::create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcMaleFat(control, set_data);
}

void TObjNpcMaleFat::free_static_model() {
    if (static_model_resource != NULL) {
        delete static_model_resource;
        static_model_resource = NULL;
    }
}

void TObjNpcMaleFat::load_static_resource() {
    BmlResource *resource = new BmlResource(1, &bm_n_efm_i_body_resource_descriptor, 0, 0, NULL);
    static_model_resource = resource;
}

TObjNpcMaleFat::~TObjNpcMaleFat() {}

TObjNpcMaleFat::TObjNpcMaleFat(TObject *parent, void *set_data) : TObjNpcMale(parent) {
    this->m_name = name;
    this->apply_set_data(set_data);
    init_position_vectors();
    this->model = (void *)static_model_resource->models->model;
    this->texlist = static_model_resource->models->texlist;
    this->setup_common();
}
