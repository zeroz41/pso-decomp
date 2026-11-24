#include "types.h"
#include "pso/npc/TObjNpcFemaleBase.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/task/TMainTask.h"

const char *bm_n_ebw_i_body_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_ebw_i_body_model_names[2] = { "n_ebw_i_body.nj", NULL };
BmlResourceDescriptor bm_n_ebw_i_body_resource_descriptor = { "bm_n_ebw_i_body.bml", bm_n_ebw_i_body_model_names, bm_n_ebw_i_body_motion_names, 1, 0 };
const char *TObjNpcFemaleBase::name = "TObjNpcFemaleBase";
BmlResource *TObjNpcFemaleBase::shared_resource_obj;

void *TObjNpcFemaleBase::create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcFemaleBase(control, set_data);
}

void TObjNpcFemaleBase::free_static_data() {
    if (shared_resource_obj != NULL) {
        delete shared_resource_obj;
        shared_resource_obj = NULL;
    }
}

void TObjNpcFemaleBase::load_shared_resource() {
    BmlResource *resource = new BmlResource(1, &bm_n_ebw_i_body_resource_descriptor, 0, 0, NULL);
    shared_resource_obj = resource;
}

TObjNpcFemaleBase::~TObjNpcFemaleBase() {}

TObjNpcFemaleBase::TObjNpcFemaleBase(TObject *parent, void *set_data) : TObjNpcFemale(parent) {
    this->m_name = name;
    this->apply_set_data(set_data);
    init_position_vectors();
    this->model = (void *)shared_resource_obj->models->model;
    this->texlist = shared_resource_obj->models->texlist;
    this->setup_common();
}
