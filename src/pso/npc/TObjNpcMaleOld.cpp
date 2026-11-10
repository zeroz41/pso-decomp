#include "types.h"
#include "pso/npc/TObjNpcMaleOld.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResourceLoader.h"
#include "pso/system/task/TMainTask.h"

#pragma readonly_strings on

const char *bm_n_eom_i_body_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_eom_i_body_model_names[2] = { "n_eom_i_body.nj", NULL };
BmlResourceDescriptor bm_n_eom_i_body_resource_descriptor = { "bm_n_eom_i_body.bml", bm_n_eom_i_body_model_names, bm_n_eom_i_body_motion_names, 1, 0 };
const char *TObjNpcMaleOld__name = "TObjNpcMaleOld";
BmlResource *TObjNpcMaleOld__shared_model_resource;

extern "C" s32 __vt__14TObjNpcMaleOld[];

void *TObjNpcMaleOld__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    void *npc = TObject::operator new(sizeof(TObjNpcMaleOld));
    if (npc != NULL) {
        npc = TObjNpcMaleOld__ct((TObjNpcMaleOld *)npc, control, set_data);
    }
    return npc;
}

void TObjNpcMaleOld::destroy_static_instance() {
    if (TObjNpcMaleOld__shared_model_resource != NULL) {
        free_bin_model_request(TObjNpcMaleOld__shared_model_resource, 1);
        TObjNpcMaleOld__shared_model_resource = NULL;
    }
}

void TObjNpcMaleOld::load_resource_instance() {
    void *memory = ::operator new(0x440);
    BmlResource *resource = (BmlResource *)memory;
    if (memory != NULL) {
        resource = load_resource_from_descriptor(memory, 1, &bm_n_eom_i_body_resource_descriptor, 0, 0, 0);
    }
    TObjNpcMaleOld__shared_model_resource = resource;
}

TObjNpcMaleOld::~TObjNpcMaleOld() {}

TObjNpcMaleOld *TObjNpcMaleOld__ct(TObjNpcMaleOld *npc, TObjControl *control, void *set_data) {
    npc->construct_male_npc_base();
    *(s32 **)((u8 *)npc + 0x18) = __vt__14TObjNpcMaleOld;
    npc->m_name = TObjNpcMaleOld__name;
    npc->apply_set_data(set_data);
    ((TObjPlayer *)npc)->init_position_vectors();
    npc->model = (void *)TObjNpcMaleOld__shared_model_resource->models->model;
    npc->texlist = TObjNpcMaleOld__shared_model_resource->models->m_c;
    npc->setup_common();
    return npc;
}
