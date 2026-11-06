#include "types.h"
#include "pso/npc/TObjNpcFemaleOld.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResourceLoader.h"
#include "pso/system/task/TMainTask.h"

const char *bm_n_eow_i_body_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_eow_i_body_model_names[2] = { "n_eow_i_body_2.nj", NULL };
BmlResourceDescriptor bm_n_eow_i_body_resource_descriptor = { "bm_n_eow_i_body.bml", bm_n_eow_i_body_model_names, bm_n_eow_i_body_motion_names, 1, 0 };
const char *TObjNpcFemaleOld__name = "TObjNpcFemaleOld";
BmlResource *TObjNpcFemaleOld__static_instance;

extern "C" s32 __vt__16TObjNpcFemaleOld[];

void *TObjNpcFemaleOld__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    void *npc = TObject::operator new(sizeof(TObjNpcFemaleOld));
    if (npc != NULL) {
        npc = TObjNpcFemaleOld__ct((TObjNpcFemaleOld *)npc, control, set_data);
    }
    return npc;
}

void TObjNpcFemaleOld::destroy_static_instance() {
    if (TObjNpcFemaleOld__static_instance != NULL) {
        TLobby__sub_8001FE7C(TObjNpcFemaleOld__static_instance, 1);
        TObjNpcFemaleOld__static_instance = NULL;
    }
}

void TObjNpcFemaleOld::load_resource_instance() {
    void *memory = ::operator new(0x440);
    BmlResource *resource = (BmlResource *)memory;
    if (memory != NULL) {
        resource = load_resource_from_descriptor(memory, 1, &bm_n_eow_i_body_resource_descriptor, 0, 0, 0);
    }
    TObjNpcFemaleOld__static_instance = resource;
}

TObjNpcFemaleOld::~TObjNpcFemaleOld() {}

TObjNpcFemaleOld *TObjNpcFemaleOld__ct(TObjNpcFemaleOld *npc, TObjControl *control, void *set_data) {
    npc->construct_female_base();
    *(s32 **)((u8 *)npc + 0x18) = __vt__16TObjNpcFemaleOld;
    npc->m_name = TObjNpcFemaleOld__name;
    npc->apply_set_data(set_data);
    ((TObjPlayer *)npc)->init_position_vectors();
    npc->model = (void *)TObjNpcFemaleOld__static_instance->models->model;
    npc->texlist = TObjNpcFemaleOld__static_instance->models->m_c;
    npc->setup_common();
    return npc;
}
