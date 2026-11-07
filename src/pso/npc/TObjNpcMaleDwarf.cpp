#include "types.h"
#include "pso/npc/TObjNpcMaleDwarf.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResourceLoader.h"
#include "pso/system/task/TMainTask.h"

#pragma readonly_strings on

const char *bm_n_efsm_i_body_3_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_efsm_i_body_3_model_names[2] = { "n_efsm_i_body_3.nj", NULL };
BmlResourceDescriptor bm_n_efsm_i_body_3_resource_descriptor = { "bm_n_efsm_i_body_3.bml", bm_n_efsm_i_body_3_model_names, bm_n_efsm_i_body_3_motion_names, 1, 0 };
const char *TObjNpcMaleDwarf__name = "TObjNpcMaleDwarf";
BmlResource *TObjNpcMaleDwarf__shared_model_resource;

extern "C" s32 __vt__16TObjNpcMaleDwarf[];

void *TObjNpcMaleDwarf__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    void *npc = TObject::operator new(sizeof(TObjNpcMaleDwarf));
    if (npc != NULL) {
        npc = TObjNpcMaleDwarf__ct((TObjNpcMaleDwarf *)npc, control, set_data);
    }
    return npc;
}

void TObjNpcMaleDwarf::unload_static_data() {
    if (TObjNpcMaleDwarf__shared_model_resource != NULL) {
        TLobby__sub_8001FE7C(TObjNpcMaleDwarf__shared_model_resource, 1);
        TObjNpcMaleDwarf__shared_model_resource = NULL;
    }
}

void TObjNpcMaleDwarf::load_shared_resource() {
    void *memory = ::operator new(0x440);
    BmlResource *resource = (BmlResource *)memory;
    if (memory != NULL) {
        resource = load_resource_from_descriptor(memory, 1, &bm_n_efsm_i_body_3_resource_descriptor, 0, 0, 0);
    }
    TObjNpcMaleDwarf__shared_model_resource = resource;
}

TObjNpcMaleDwarf::~TObjNpcMaleDwarf() {}

TObjNpcMaleDwarf *TObjNpcMaleDwarf__ct(TObjNpcMaleDwarf *npc, TObjControl *control, void *set_data) {
    npc->construct_male_npc_base();
    *(s32 **)((u8 *)npc + 0x18) = __vt__16TObjNpcMaleDwarf;
    npc->m_name = TObjNpcMaleDwarf__name;
    npc->apply_set_data(set_data);
    ((TObjPlayer *)npc)->init_position_vectors();
    npc->model = (void *)TObjNpcMaleDwarf__shared_model_resource->models->model;
    npc->texlist = TObjNpcMaleDwarf__shared_model_resource->models->m_c;
    npc->setup_common();
    return npc;
}
