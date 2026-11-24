#include "types.h"
#include "pso/npc/TObjNpcFemaleTall.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/task/TMainTask.h"

const char *bm_n_etw_i_body_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_etw_i_body_model_names[2] = { "n_etw_i_body.nj", NULL };
BmlResourceDescriptor bm_n_etw_i_body_resource_descriptor = { "bm_n_etw_i_body.bml", bm_n_etw_i_body_model_names, bm_n_etw_i_body_motion_names, 1, 0 };
const char *TObjNpcFemaleTall::name = "TObjNpcFemaleTall";
BmlResource *TObjNpcFemaleTall::instance;

void *TObjNpcFemaleTall::create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcFemaleTall(control, set_data);
}

void TObjNpcFemaleTall::destroy_instance() {
    if (instance != NULL) {
        delete instance;
        instance = NULL;
    }
}

void TObjNpcFemaleTall::load_resource_instance() {
    BmlResource *resource = new BmlResource(1, &bm_n_etw_i_body_resource_descriptor, 0, 0, NULL);
    instance = resource;
}

TObjNpcFemaleTall::~TObjNpcFemaleTall() {}

TObjNpcFemaleTall::TObjNpcFemaleTall(TObject *parent, void *set_data) : TObjNpcFemale(parent) {
    this->m_name = name;
    this->apply_set_data(set_data);
    init_position_vectors();
    this->model = (void *)instance->models->model;
    this->texlist = instance->models->texlist;
    this->setup_common();
}
