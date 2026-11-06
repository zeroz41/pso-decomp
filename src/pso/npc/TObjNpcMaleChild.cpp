#include "types.h"
#include "pso/npc/TObjNpcMaleChild.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResourceLoader.h"
#include "pso/system/task/TMainTask.h"

#pragma readonly_strings on

const char *bm_n_ecm_i_body_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_ecm_i_body_model_names[2] = { "n_ecm_i_body.nj", NULL };
BmlResourceDescriptor bm_n_ecm_i_body_resource_descriptor = { "bm_n_ecm_i_body.bml", bm_n_ecm_i_body_model_names, bm_n_ecm_i_body_motion_names, 1, 0 };
const char *TObjNpcMaleChild__name = "TObjNpcMaleChild";
BmlResource *TObjNpcMaleChild__shared_model_resource;

extern "C" s32 __vt__16TObjNpcMaleChild[];

void *TObjNpcMaleChild__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    void *npc = TObject::operator new(sizeof(TObjNpcMaleChild));
    if (npc != NULL) {
        npc = TObjNpcMaleChild__ct((TObjNpcMaleChild *)npc, control, set_data);
    }
    return npc;
}

void TObjNpcMaleChild::release_static_instance() {
    if (TObjNpcMaleChild__shared_model_resource != NULL) {
        TLobby__sub_8001FE7C(TObjNpcMaleChild__shared_model_resource, 1);
        TObjNpcMaleChild__shared_model_resource = NULL;
    }
}

void TObjNpcMaleChild::load_shared_resource() {
    void *memory = ::operator new(0x440);
    BmlResource *resource = (BmlResource *)memory;
    if (memory != NULL) {
        resource = load_resource_from_descriptor(memory, 1, &bm_n_ecm_i_body_resource_descriptor, 0, 0, 0);
    }
    TObjNpcMaleChild__shared_model_resource = resource;
}

TObjNpcMaleChild::~TObjNpcMaleChild() {}

TObjNpcMaleChild *TObjNpcMaleChild__ct(TObjNpcMaleChild *npc, TObjControl *control, void *set_data) {
    npc->construct_male_npc_base();
    *(s32 **)((u8 *)npc + 0x18) = __vt__16TObjNpcMaleChild;
    npc->m_name = TObjNpcMaleChild__name;
    npc->apply_set_data(set_data);
    ((TObjPlayer *)npc)->init_position_vectors();
    npc->model = (void *)TObjNpcMaleChild__shared_model_resource->models->model;
    npc->texlist = TObjNpcMaleChild__shared_model_resource->models->m_c;
    npc->setup_common();
    return npc;
}
