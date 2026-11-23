#include "types.h"
#include "pso/npc/TObjNpcFemaleOld.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/task/TMainTask.h"

const char *bm_n_eow_i_body_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_eow_i_body_model_names[2] = { "n_eow_i_body_2.nj", NULL };
BmlResourceDescriptor bm_n_eow_i_body_resource_descriptor = { "bm_n_eow_i_body.bml", bm_n_eow_i_body_model_names, bm_n_eow_i_body_motion_names, 1, 0 };
const char *TObjNpcFemaleOld__name = "TObjNpcFemaleOld";
BmlResource *TObjNpcFemaleOld__static_instance;

void *TObjNpcFemaleOld__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcFemaleOld(control, set_data);
}

void TObjNpcFemaleOld::destroy_static_instance() {
    if (TObjNpcFemaleOld__static_instance != NULL) {
        delete TObjNpcFemaleOld__static_instance;
        TObjNpcFemaleOld__static_instance = NULL;
    }
}

void TObjNpcFemaleOld::load_resource_instance() {
    BmlResource *resource = new BmlResource(1, &bm_n_eow_i_body_resource_descriptor, 0, 0, NULL);
    TObjNpcFemaleOld__static_instance = resource;
}

TObjNpcFemaleOld::~TObjNpcFemaleOld() {}

TObjNpcFemaleOld::TObjNpcFemaleOld(TObject *parent, void *set_data) : TUnk_804A8640(parent) {
    this->m_name = TObjNpcFemaleOld__name;
    this->apply_set_data(set_data);
    init_position_vectors();
    this->model = (void *)TObjNpcFemaleOld__static_instance->models->model;
    this->texlist = (saddr)TObjNpcFemaleOld__static_instance->models->texlist;
    this->setup_common();
}
