#include "types.h"
#include "pso/npc/TObjNpcFemaleOld.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResourceLoader.h"
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
        free_bin_model_request(TObjNpcFemaleOld__static_instance, 1);
        TObjNpcFemaleOld__static_instance = NULL;
    }
}

void TObjNpcFemaleOld::load_resource_instance() {
    void *memory = ::operator new(0x440);
    BmlResource *resource = (BmlResource *)memory;
    if (memory != NULL) {
        resource = load_resource_from_descriptor(memory, 1, &bm_n_eow_i_body_resource_descriptor, 0, 0, 0);
    }
    TObjNpcFemaleOld__static_instance = resource;
}

TObjNpcFemaleOld::~TObjNpcFemaleOld() {}

TObjNpcFemaleOld::TObjNpcFemaleOld(TObject *parent, void *set_data) : TUnk_804A8640(parent) {
    this->m_name = TObjNpcFemaleOld__name;
    this->apply_set_data(set_data);
    ((TObjPlayer *)this)->init_position_vectors();
    this->model = (void *)TObjNpcFemaleOld__static_instance->models->model;
    this->texlist = TObjNpcFemaleOld__static_instance->models->m_c;
    this->setup_common();
}
