#include "types.h"
#include "pso/npc/TObjNpcFemaleFat.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/task/TMainTask.h"

const char *bm_n_efw_i_body_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_efw_i_body_model_names[2] = { "n_efw_i_body.nj", NULL };
BmlResourceDescriptor bm_n_efw_i_body_resource_descriptor = { "bm_n_efw_i_body.bml", bm_n_efw_i_body_model_names, bm_n_efw_i_body_motion_names, 1, 0 };
const char *TObjNpcFemaleFat__name = "TObjNpcFemaleFat";
BmlResource *TObjNpcFemaleFat__static_model;

void *TObjNpcFemaleFat__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcFemaleFat(control, set_data);
}

void TObjNpcFemaleFat::free_static_model() {
    if (TObjNpcFemaleFat__static_model != NULL) {
        delete TObjNpcFemaleFat__static_model;
        TObjNpcFemaleFat__static_model = NULL;
    }
}

void TObjNpcFemaleFat::load_static_resource() {
    BmlResource *resource = new BmlResource(1, &bm_n_efw_i_body_resource_descriptor, 0, 0, NULL);
    TObjNpcFemaleFat__static_model = resource;
}

TObjNpcFemaleFat::~TObjNpcFemaleFat() {}

TObjNpcFemaleFat::TObjNpcFemaleFat(TObject *parent, void *set_data) : TUnk_804A8640(parent) {
    this->m_name = TObjNpcFemaleFat__name;
    this->apply_set_data(set_data);
    init_position_vectors();
    this->model = (void *)TObjNpcFemaleFat__static_model->models->model;
    this->texlist = (saddr)TObjNpcFemaleFat__static_model->models->texlist;
    this->setup_common();
}
