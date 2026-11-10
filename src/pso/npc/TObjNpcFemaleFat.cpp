#include "types.h"
#include "pso/npc/TObjNpcFemaleFat.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResourceLoader.h"
#include "pso/system/task/TMainTask.h"

const char *bm_n_efw_i_body_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_efw_i_body_model_names[2] = { "n_efw_i_body.nj", NULL };
BmlResourceDescriptor bm_n_efw_i_body_resource_descriptor = { "bm_n_efw_i_body.bml", bm_n_efw_i_body_model_names, bm_n_efw_i_body_motion_names, 1, 0 };
const char *TObjNpcFemaleFat__name = "TObjNpcFemaleFat";
BmlResource *TObjNpcFemaleFat__static_model;

extern "C" s32 __vt__16TObjNpcFemaleFat[];

void *TObjNpcFemaleFat__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    void *npc = TObject::operator new(sizeof(TObjNpcFemaleFat));
    if (npc != NULL) {
        npc = TObjNpcFemaleFat__ct((TObjNpcFemaleFat *)npc, control, set_data);
    }
    return npc;
}

void TObjNpcFemaleFat::free_static_model() {
    if (TObjNpcFemaleFat__static_model != NULL) {
        free_bin_model_request(TObjNpcFemaleFat__static_model, 1);
        TObjNpcFemaleFat__static_model = NULL;
    }
}

void TObjNpcFemaleFat::load_static_resource() {
    void *memory = ::operator new(0x440);
    BmlResource *resource = (BmlResource *)memory;
    if (memory != NULL) {
        resource = load_resource_from_descriptor(memory, 1, &bm_n_efw_i_body_resource_descriptor, 0, 0, 0);
    }
    TObjNpcFemaleFat__static_model = resource;
}

TObjNpcFemaleFat::~TObjNpcFemaleFat() {}

TObjNpcFemaleFat *TObjNpcFemaleFat__ct(TObjNpcFemaleFat *npc, TObjControl *control, void *set_data) {
    npc->construct_female_base();
    *(s32 **)((u8 *)npc + 0x18) = __vt__16TObjNpcFemaleFat;
    npc->m_name = TObjNpcFemaleFat__name;
    npc->apply_set_data(set_data);
    ((TObjPlayer *)npc)->init_position_vectors();
    npc->model = (void *)TObjNpcFemaleFat__static_model->models->model;
    npc->texlist = TObjNpcFemaleFat__static_model->models->m_c;
    npc->setup_common();
    return npc;
}
