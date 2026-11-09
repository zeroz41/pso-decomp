#include "types.h"
#include "pso/npc/TObjNpcMaleBase.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResourceLoader.h"
#include "pso/system/task/TMainTask.h"

#pragma readonly_strings on

const char *bm_n_ebm_i_body_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_ebm_i_body_model_names[2] = { "n_ebm_i_body_4.nj", NULL };
BmlResourceDescriptor bm_n_ebm_i_body_resource_descriptor = { "bm_n_ebm_i_body.bml", bm_n_ebm_i_body_model_names, bm_n_ebm_i_body_motion_names, 1, 0 };
const char *TObjNpcMaleBase__name = "TObjNpcMaleBase";
BmlResource *TObjNpcMaleBase__shared_bml_archive;

extern "C" s32 __vt__15TObjNpcMaleBase[];

void *TObjNpcMaleBase__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    void *npc = TObject::operator new(sizeof(TObjNpcMaleBase));
    if (npc != NULL) {
        npc = TObjNpcMaleBase__ct((TObjNpcMaleBase *)npc, control, set_data);
    }
    return npc;
}

void TObjNpcMaleBase::free_static_data() {
    if (TObjNpcMaleBase__shared_bml_archive != NULL) {
        free_bin_model_request(TObjNpcMaleBase__shared_bml_archive, 1);
        TObjNpcMaleBase__shared_bml_archive = NULL;
    }
}

void TObjNpcMaleBase::load_shared_resource() {
    void *memory = ::operator new(0x440);
    BmlResource *resource = (BmlResource *)memory;
    if (memory != NULL) {
        resource = load_resource_from_descriptor(memory, 1, &bm_n_ebm_i_body_resource_descriptor, 0, 0, 0);
    }
    TObjNpcMaleBase__shared_bml_archive = resource;
}

TObjNpcMaleBase::~TObjNpcMaleBase() {}

TObjNpcMaleBase *TObjNpcMaleBase__ct(TObjNpcMaleBase *npc, TObjControl *control, void *set_data) {
    npc->construct_male_npc_base();
    *(s32 **)((u8 *)npc + 0x18) = __vt__15TObjNpcMaleBase;
    npc->m_name = TObjNpcMaleBase__name;
    npc->apply_set_data(set_data);
    ((TObjPlayer *)npc)->init_position_vectors();
    npc->model = (void *)TObjNpcMaleBase__shared_bml_archive->models->model;
    npc->texlist = TObjNpcMaleBase__shared_bml_archive->models->m_c;
    npc->setup_common();
    return npc;
}
