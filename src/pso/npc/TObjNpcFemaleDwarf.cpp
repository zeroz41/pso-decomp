#include "types.h"
#include "pso/npc/TObjNpcFemaleDwarf.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResourceLoader.h"
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
        free_bin_model_request(TObjNpcFemaleDwarf__static_data, 1);
        TObjNpcFemaleDwarf__static_data = NULL;
    }
}

void TObjNpcFemaleDwarf::load_static_resource() {
    void *memory = ::operator new(0x440);
    BmlResource *resource = (BmlResource *)memory;
    if (memory != NULL) {
        resource = load_resource_from_descriptor(memory, 1, &bm_n_efsw_i_body_resource_descriptor, 0, 0, 0);
    }
    TObjNpcFemaleDwarf__static_data = resource;
}

TObjNpcFemaleDwarf::~TObjNpcFemaleDwarf() {}

TObjNpcFemaleDwarf::TObjNpcFemaleDwarf(TObject *parent, void *set_data) : TUnk_804A8640(parent) {
    this->m_name = TObjNpcFemaleDwarf__name;
    this->apply_set_data(set_data);
    ((TObjPlayer *)this)->init_position_vectors();
    this->model = (void *)TObjNpcFemaleDwarf__static_data->models->model;
    this->texlist = TObjNpcFemaleDwarf__static_data->models->m_c;
    this->setup_common();
}
