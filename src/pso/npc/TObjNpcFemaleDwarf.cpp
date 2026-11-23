#include "types.h"
#include "pso/npc/TObjNpcFemaleDwarf.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/task/TMainTask.h"

const char *bm_n_efsw_i_body_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_efsw_i_body_model_names[2] = { "n_efsw_i_body.nj", NULL };
BmlResourceDescriptor bm_n_efsw_i_body_resource_descriptor = { "bm_n_efsw_i_body.bml", bm_n_efsw_i_body_model_names, bm_n_efsw_i_body_motion_names, 1, 0 };
const char *TObjNpcFemaleDwarf__name = "TObjNpcFemaleDwarf";
BmlResource *TObjNpcFemaleDwarf__static_data;

void *TObjNpcFemaleDwarf__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcFemaleDwarf(control, set_data);
}

void TObjNpcFemaleDwarf::unload_static_data() {
    if (TObjNpcFemaleDwarf__static_data != NULL) {
        delete TObjNpcFemaleDwarf__static_data;
        TObjNpcFemaleDwarf__static_data = NULL;
    }
}

void TObjNpcFemaleDwarf::load_static_resource() {
    BmlResource *resource = new BmlResource(1, &bm_n_efsw_i_body_resource_descriptor, 0, 0, NULL);
    TObjNpcFemaleDwarf__static_data = resource;
}

TObjNpcFemaleDwarf::~TObjNpcFemaleDwarf() {}

TObjNpcFemaleDwarf::TObjNpcFemaleDwarf(TObject *parent, void *set_data) : TUnk_804A8640(parent) {
    this->m_name = TObjNpcFemaleDwarf__name;
    this->apply_set_data(set_data);
    init_position_vectors();
    this->model = (void *)TObjNpcFemaleDwarf__static_data->models->model;
    this->texlist = (saddr)TObjNpcFemaleDwarf__static_data->models->texlist;
    this->setup_common();
}
