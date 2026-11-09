#include "types.h"
#include "pso/npc/TObjNpcNurseBase.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResourceLoader.h"
#include "pso/system/task/TMainTask.h"

#pragma readonly_strings on

const char *bm_n_nurse_i_body_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_nurse_i_body_model_names[2] = { "n_nurse_i_body.nj", NULL };
BmlResourceDescriptor bm_n_nurse_i_body_resource_descriptor = { "bm_n_nurse_i_body.bml", bm_n_nurse_i_body_model_names, bm_n_nurse_i_body_motion_names, 1, 0 };
const char *TObjNpcNurseBase__name = "TObjNpcNurseBase";
BmlResource *TObjNpcNurseBase__shared_model_resource;

extern "C" s32 __vt__16TObjNpcNurseBase[];

void *TObjNpcNurseBase__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    void *npc = TObject::operator new(sizeof(TObjNpcNurseBase));
    if (npc != NULL) {
        npc = TObjNpcNurseBase__ct((TObjNpcNurseBase *)npc, control, set_data);
    }
    return npc;
}

void TObjNpcNurseBase::free_shared_data() {
    if (TObjNpcNurseBase__shared_model_resource != NULL) {
        free_bin_model_request(TObjNpcNurseBase__shared_model_resource, 1);
        TObjNpcNurseBase__shared_model_resource = NULL;
    }
}

void TObjNpcNurseBase::load_shared_data() {
    void *memory = ::operator new(0x440);
    BmlResource *resource = (BmlResource *)memory;
    if (memory != NULL) {
        resource = load_resource_from_descriptor(memory, 1, &bm_n_nurse_i_body_resource_descriptor, 0, 0, 0);
    }
    TObjNpcNurseBase__shared_model_resource = resource;
}

TObjNpcNurseBase::~TObjNpcNurseBase() {}

TObjNpcNurseBase *TObjNpcNurseBase__ct(TObjNpcNurseBase *npc, TObjControl *control, void *set_data) {
    npc->construct_female_base();
    *(s32 **)((u8 *)npc + 0x18) = __vt__16TObjNpcNurseBase;
    npc->m_name = TObjNpcNurseBase__name;
    npc->apply_set_data(set_data);
    ((TObjPlayer *)npc)->init_position_vectors();
    npc->model = (void *)TObjNpcNurseBase__shared_model_resource->models->model;
    npc->texlist = TObjNpcNurseBase__shared_model_resource->models->m_c;
    npc->setup_common();
    return npc;
}
