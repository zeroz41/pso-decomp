#include "types.h"
#include "pso/npc/TObjNpcMaleFat.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResourceLoader.h"
#include "pso/system/task/TMainTask.h"

#pragma readonly_strings on

const char *bm_n_efm_i_body_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_efm_i_body_model_names[2] = { "n_efm_i_body.nj", NULL };
BmlResourceDescriptor bm_n_efm_i_body_resource_descriptor = { "bm_n_efm_i_body.bml", bm_n_efm_i_body_model_names, bm_n_efm_i_body_motion_names, 1, 0 };
const char *TObjNpcMaleFat__name = "TObjNpcMaleFat";
BmlResource *TObjNpcMaleFat__static_model_resource;

void *TObjNpcMaleFat__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcMaleFat(control, set_data);
}

void TObjNpcMaleFat::free_static_model() {
    if (TObjNpcMaleFat__static_model_resource != NULL) {
        free_bin_model_request(TObjNpcMaleFat__static_model_resource, 1);
        TObjNpcMaleFat__static_model_resource = NULL;
    }
}

void TObjNpcMaleFat::load_static_resource() {
    void *memory = ::operator new(0x440);
    BmlResource *resource = (BmlResource *)memory;
    if (memory != NULL) {
        resource = load_resource_from_descriptor(memory, 1, &bm_n_efm_i_body_resource_descriptor, 0, 0, 0);
    }
    TObjNpcMaleFat__static_model_resource = resource;
}

TObjNpcMaleFat::~TObjNpcMaleFat() {}

TObjNpcMaleFat::TObjNpcMaleFat(TObject *parent, void *set_data) : TUnk_804A9F50(parent) {
    this->m_name = TObjNpcMaleFat__name;
    this->apply_set_data(set_data);
    ((TObjPlayer *)this)->init_position_vectors();
    this->model = (void *)TObjNpcMaleFat__static_model_resource->models->model;
    this->texlist = TObjNpcMaleFat__static_model_resource->models->m_c;
    this->setup_common();
}
