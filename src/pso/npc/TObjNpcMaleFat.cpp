#include "types.h"
#include "pso/npc/TObjNpcMaleFat.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResourceLoader.h"
#include "pso/system/task/TMainTask.h"

#pragma readonly_strings on

const char *bm_n_efm_i_body_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_efm_i_body_model_names[2] = { "n_efm_i_body.nj", NULL };
BmlResourceDescriptor bm_n_efm_i_body_resource_descriptor = { "bm_n_efm_i_body.bml", bm_n_efm_i_body_model_names, bm_n_efm_i_body_motion_names, 1, 0 };
const char *TObjNpcMaleFat__name = "TObjNpcMaleFat";
BmlResource *TObjNpcMaleFat__static_model_resource;

extern "C" s32 __vt__14TObjNpcMaleFat[];

void *TObjNpcMaleFat__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    void *npc = TObject::operator new(sizeof(TObjNpcMaleFat));
    if (npc != NULL) {
        npc = TObjNpcMaleFat__ct((TObjNpcMaleFat *)npc, control, set_data);
    }
    return npc;
}

void TObjNpcMaleFat::free_static_model() {
    if (TObjNpcMaleFat__static_model_resource != NULL) {
        TLobby__sub_8001FE7C(TObjNpcMaleFat__static_model_resource, 1);
        TObjNpcMaleFat__static_model_resource = NULL;
    }
}

void TObjNpcMaleFat::load_static_resource() {
    void *memory = ::operator new(0x440);
    BmlResource *resource = (BmlResource *)memory;
    if (memory != NULL) {
        resource = load_resource_from_descriptor(memory, 1, &bm_n_efm_i_body_resource_descriptor, 0, 0, 0);
    }
    TObjNpcMaleFat__static_model_resource = resource;
}

TObjNpcMaleFat::~TObjNpcMaleFat() {}

TObjNpcMaleFat *TObjNpcMaleFat__ct(TObjNpcMaleFat *npc, TObjControl *control, void *set_data) {
    npc->construct_male_npc_base();
    *(s32 **)((u8 *)npc + 0x18) = __vt__14TObjNpcMaleFat;
    npc->m_name = TObjNpcMaleFat__name;
    npc->apply_set_data(set_data);
    ((TObjPlayer *)npc)->init_position_vectors();
    npc->model = (void *)TObjNpcMaleFat__static_model_resource->models->model;
    npc->texlist = TObjNpcMaleFat__static_model_resource->models->m_c;
    npc->setup_common();
    return npc;
}
