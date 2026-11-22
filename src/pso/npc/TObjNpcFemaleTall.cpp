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
const char *TObjNpcFemaleTall__name = "TObjNpcFemaleTall";
BmlResource *TObjNpcFemaleTall__instance;

void *TObjNpcFemaleTall__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcFemaleTall(control, set_data);
}

void TObjNpcFemaleTall::destroy_instance() {
    if (TObjNpcFemaleTall__instance != NULL) {
        delete TObjNpcFemaleTall__instance;
        TObjNpcFemaleTall__instance = NULL;
    }
}

void TObjNpcFemaleTall::load_resource_instance() {
    BmlResource *resource = new BmlResource(1, &bm_n_etw_i_body_resource_descriptor, 0, 0, NULL);
    TObjNpcFemaleTall__instance = resource;
}

TObjNpcFemaleTall::~TObjNpcFemaleTall() {}

TObjNpcFemaleTall::TObjNpcFemaleTall(TObject *parent, void *set_data) : TUnk_804A8640(parent) {
    this->m_name = TObjNpcFemaleTall__name;
    this->apply_set_data(set_data);
    init_position_vectors();
    this->model = (void *)TObjNpcFemaleTall__instance->models->model;
    this->texlist = (saddr)TObjNpcFemaleTall__instance->models->m_c;
    this->setup_common();
}
