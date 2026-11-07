#include "types.h"
#include "pso/npc/TObjNpcSoldierBase.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResourceLoader.h"
#include "pso/system/task/TMainTask.h"

#pragma readonly_strings on

const char *bm_n_gunb2_i_body_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_gunb2_i_body_model_names[2] = { "n_gunb2_i_body.nj", NULL };
BmlResourceDescriptor TObjNpcSoldierBase__body_resource_desc = { "bm_n_gunb2_i_body.bml", bm_n_gunb2_i_body_model_names, bm_n_gunb2_i_body_motion_names, 1, 0 };
const char *TObjNpcSoldierBase__name = "TObjNpcSoldierBase";
BmlResource *TObjNpcSoldierBase__shared_model_resource;

extern "C" s32 __vt__18TObjNpcSoldierBase[];

void *TObjNpcSoldierBase__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    void *npc = TObject::operator new(sizeof(TObjNpcSoldierBase));
    if (npc != NULL) {
        npc = TObjNpcSoldierBase__ct((TObjNpcSoldierBase *)npc, control, set_data);
    }
    return npc;
}

void TObjNpcSoldierBase::release_static_instance() {
    if (TObjNpcSoldierBase__shared_model_resource != NULL) {
        TLobby__sub_8001FE7C(TObjNpcSoldierBase__shared_model_resource, 1);
        TObjNpcSoldierBase__shared_model_resource = NULL;
    }
}

void TObjNpcSoldierBase::load_shared_resource() {
    void *memory = ::operator new(0x440);
    BmlResource *resource = (BmlResource *)memory;
    if (memory != NULL) {
        resource = load_resource_from_descriptor(memory, 1, &TObjNpcSoldierBase__body_resource_desc, 0, 0, 0);
    }
    TObjNpcSoldierBase__shared_model_resource = resource;
}

TObjNpcSoldierBase::~TObjNpcSoldierBase() {}

TObjNpcSoldierBase *TObjNpcSoldierBase__ct(TObjNpcSoldierBase *npc, TObjControl *control, void *set_data) {
    npc->construct_male_npc_base();
    *(s32 **)((u8 *)npc + 0x18) = __vt__18TObjNpcSoldierBase;
    npc->m_name = TObjNpcSoldierBase__name;
    npc->apply_set_data(set_data);
    ((TObjPlayer *)npc)->init_position_vectors();
    npc->model = (void *)TObjNpcSoldierBase__shared_model_resource->models->model;
    npc->texlist = TObjNpcSoldierBase__shared_model_resource->models->m_c;
    npc->setup_common();
    return npc;
}
