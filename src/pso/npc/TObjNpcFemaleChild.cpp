#include "types.h"
#include "pso/npc/TObjNpcFemaleChild.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/task/TMainTask.h"

const char *bm_n_ecw_i_body_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_ecw_i_body_model_names[2] = { "n_ecw_i_body.nj", NULL };
BmlResourceDescriptor bm_n_ecw_i_body_resource_descriptor = { "bm_n_ecw_i_body.bml", bm_n_ecw_i_body_model_names, bm_n_ecw_i_body_motion_names, 1, 0 };
const char *TObjNpcFemaleChild::name = "TObjNpcFemaleChild";
BmlResource *TObjNpcFemaleChild::static_instance;

void *TObjNpcFemaleChild::create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcFemaleChild(control, set_data);
}

void TObjNpcFemaleChild::release_static_instance() {
    if (static_instance != NULL) {
        delete static_instance;
        static_instance = NULL;
    }
}

void TObjNpcFemaleChild::load_shared_resource() {
    BmlResource *resource = new BmlResource(1, &bm_n_ecw_i_body_resource_descriptor, 0, 0, NULL);
    static_instance = resource;
}

TObjNpcFemaleChild::~TObjNpcFemaleChild() {}

TObjNpcFemaleChild::TObjNpcFemaleChild(TObject *parent, void *set_data) : TObjNpcFemale(parent) {
    this->m_name = name;
    this->apply_set_data(set_data);
    init_position_vectors();
    this->model = (void *)static_instance->models->model;
    this->texlist = static_instance->models->texlist;
    this->setup_common();
}
