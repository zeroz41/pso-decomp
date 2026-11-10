#include "types.h"
#include "pso/npc/TObjNpcFemaleTall.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResourceLoader.h"
#include "pso/system/task/TMainTask.h"

const char *bm_n_etw_i_body_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_etw_i_body_model_names[2] = { "n_etw_i_body.nj", NULL };
BmlResourceDescriptor bm_n_etw_i_body_resource_descriptor = { "bm_n_etw_i_body.bml", bm_n_etw_i_body_model_names, bm_n_etw_i_body_motion_names, 1, 0 };
const char *TObjNpcFemaleTall__name = "TObjNpcFemaleTall";
BmlResource *TObjNpcFemaleTall__instance;

extern "C" s32 __vt__17TObjNpcFemaleTall[];

void *TObjNpcFemaleTall__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    void *npc = TObject::operator new(sizeof(TObjNpcFemaleTall));
    if (npc != NULL) {
        npc = TObjNpcFemaleTall__ct((TObjNpcFemaleTall *)npc, control, set_data);
    }
    return npc;
}

void TObjNpcFemaleTall::destroy_instance() {
    if (TObjNpcFemaleTall__instance != NULL) {
        free_bin_model_request(TObjNpcFemaleTall__instance, 1);
        TObjNpcFemaleTall__instance = NULL;
    }
}

void TObjNpcFemaleTall::load_resource_instance() {
    void *memory = ::operator new(0x440);
    BmlResource *resource = (BmlResource *)memory;
    if (memory != NULL) {
        resource = load_resource_from_descriptor(memory, 1, &bm_n_etw_i_body_resource_descriptor, 0, 0, 0);
    }
    TObjNpcFemaleTall__instance = resource;
}

TObjNpcFemaleTall::~TObjNpcFemaleTall() {}

TObjNpcFemaleTall *TObjNpcFemaleTall__ct(TObjNpcFemaleTall *npc, TObjControl *control, void *set_data) {
    npc->construct_female_base();
    *(s32 **)((u8 *)npc + 0x18) = __vt__17TObjNpcFemaleTall;
    npc->m_name = TObjNpcFemaleTall__name;
    npc->apply_set_data(set_data);
    ((TObjPlayer *)npc)->init_position_vectors();
    npc->model = (void *)TObjNpcFemaleTall__instance->models->model;
    npc->texlist = TObjNpcFemaleTall__instance->models->m_c;
    npc->setup_common();
    return npc;
}
