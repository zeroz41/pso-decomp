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
const char *TObjNpcFemaleFat::name = "TObjNpcFemaleFat";
BmlResource *TObjNpcFemaleFat::static_model;

void *TObjNpcFemaleFat::create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcFemaleFat(control, set_data);
}

void TObjNpcFemaleFat::free_static_model() {
    if (static_model != NULL) {
        delete static_model;
        static_model = NULL;
    }
}

void TObjNpcFemaleFat::load_static_resource() {
    BmlResource *resource = new BmlResource(1, &bm_n_efw_i_body_resource_descriptor, 0, 0, NULL);
    static_model = resource;
}

TObjNpcFemaleFat::~TObjNpcFemaleFat() {}

TObjNpcFemaleFat::TObjNpcFemaleFat(TObject *parent, void *set_data) : TObjNpcFemale(parent) {
    this->m_name = name;
    this->apply_set_data(set_data);
    init_position_vectors();
    this->model = (void *)static_model->models->model;
    this->texlist = static_model->models->texlist;
    this->setup_common();
}
