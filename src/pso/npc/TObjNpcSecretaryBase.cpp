#include "types.h"
#include "pso/npc/TObjNpcSecretaryBase.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResourceLoader.h"
#include "pso/system/task/TMainTask.h"

#pragma readonly_strings on

const char *bm_n_hisyo_i_body_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_hisyo_i_body_model_names[2] = { "n_hisyo_i_body.nj", NULL };
BmlResourceDescriptor secretary_body_resource_descriptor = { "bm_n_hisyo_i_body.bml", bm_n_hisyo_i_body_model_names, bm_n_hisyo_i_body_motion_names, 1, 0 };
const char *TObjNpcSecretaryBase__name = "TObjNpcSecretaryBase";
BmlResource *TObjNpcSecretaryBase__static_model_resource;

extern "C" s32 __vt__20TObjNpcSecretaryBase[];

void *TObjNpcSecretaryBase__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    void *npc = TObject::operator new(sizeof(TObjNpcSecretaryBase));
    if (npc != NULL) {
        npc = TObjNpcSecretaryBase__ct((TObjNpcSecretaryBase *)npc, control, set_data);
    }
    return npc;
}

void TObjNpcSecretaryBase::free_static_data() {
    if (TObjNpcSecretaryBase__static_model_resource != NULL) {
        free_bin_model_request(TObjNpcSecretaryBase__static_model_resource, 1);
        TObjNpcSecretaryBase__static_model_resource = NULL;
    }
}

void TObjNpcSecretaryBase::load_static_data() {
    void *memory = ::operator new(0x440);
    BmlResource *resource = (BmlResource *)memory;
    if (memory != NULL) {
        resource = load_resource_from_descriptor(memory, 1, &secretary_body_resource_descriptor, 0, 0, 0);
    }
    TObjNpcSecretaryBase__static_model_resource = resource;
}

TObjNpcSecretaryBase::~TObjNpcSecretaryBase() {}

TObjNpcSecretaryBase *TObjNpcSecretaryBase__ct(TObjNpcSecretaryBase *npc, TObjControl *control, void *set_data) {
    npc->construct_female_base();
    *(s32 **)((u8 *)npc + 0x18) = __vt__20TObjNpcSecretaryBase;
    npc->m_name = TObjNpcSecretaryBase__name;
    npc->apply_set_data(set_data);
    ((TObjPlayer *)npc)->init_position_vectors();
    npc->model = (void *)TObjNpcSecretaryBase__static_model_resource->models->model;
    npc->texlist = TObjNpcSecretaryBase__static_model_resource->models->m_c;
    npc->setup_common();
    return npc;
}
