#include "types.h"
#include "pso/npc/TObjNpcSecretaryBase.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResourceLoader.h"
#include "pso/system/task/TMainTask.h"

#pragma readonly_strings on

const char *bm_n_hisyo_i_body_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_hisyo_i_body_model_names[2] = { "n_hisyo_i_body.nj", NULL };
BmlResourceDescriptor secretary_body_resource_descriptor = { "bm_n_hisyo_i_body.bml", bm_n_hisyo_i_body_model_names, bm_n_hisyo_i_body_motion_names, 1, 0 };
const char *TObjNpcSecretaryBase__name = "TObjNpcSecretaryBase";
BmlResource *TObjNpcSecretaryBase__static_model_resource;

void *TObjNpcSecretaryBase__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcSecretaryBase(control, set_data);
}

void TObjNpcSecretaryBase::free_static_data() {
    if (TObjNpcSecretaryBase__static_model_resource != NULL) {
        free_bin_model_request(TObjNpcSecretaryBase__static_model_resource, 1);
        TObjNpcSecretaryBase__static_model_resource = NULL;
    }
}

void TObjNpcSecretaryBase::load_static_data() {
    void *memory = ::operator new(0x440);
    BmlResource *resource = (BmlResource *)memory;
    if (memory != NULL) {
        resource = load_resource_from_descriptor(memory, 1, &secretary_body_resource_descriptor, 0, 0, 0);
    }
    TObjNpcSecretaryBase__static_model_resource = resource;
}

TObjNpcSecretaryBase::~TObjNpcSecretaryBase() {}

TObjNpcSecretaryBase::TObjNpcSecretaryBase(TObject *parent, void *set_data) : TUnk_804A8640(parent) {
    this->m_name = TObjNpcSecretaryBase__name;
    this->apply_set_data(set_data);
    ((TObjPlayer *)this)->init_position_vectors();
    this->model = (void *)TObjNpcSecretaryBase__static_model_resource->models->model;
    this->texlist = TObjNpcSecretaryBase__static_model_resource->models->m_c;
    this->setup_common();
}
