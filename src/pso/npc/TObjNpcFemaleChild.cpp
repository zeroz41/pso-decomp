#include "types.h"
#include "pso/npc/TObjNpcFemaleChild.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResourceLoader.h"
#include "pso/system/task/TMainTask.h"

const char *bm_n_ecw_i_body_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_ecw_i_body_model_names[2] = { "n_ecw_i_body.nj", NULL };
BmlResourceDescriptor bm_n_ecw_i_body_resource_descriptor = { "bm_n_ecw_i_body.bml", bm_n_ecw_i_body_model_names, bm_n_ecw_i_body_motion_names, 1, 0 };
const char *TObjNpcFemaleChild__name = "TObjNpcFemaleChild";
BmlResource *TObjNpcFemaleChild__static_instance;

extern "C" s32 __vt__18TObjNpcFemaleChild[];

void *TObjNpcFemaleChild__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    void *npc = TObject::operator new(sizeof(TObjNpcFemaleChild));
    if (npc != NULL) {
        npc = TObjNpcFemaleChild__ct((TObjNpcFemaleChild *)npc, control, set_data);
    }
    return npc;
}

void TObjNpcFemaleChild::release_static_instance() {
    if (TObjNpcFemaleChild__static_instance != NULL) {
        free_bin_model_request(TObjNpcFemaleChild__static_instance, 1);
        TObjNpcFemaleChild__static_instance = NULL;
    }
}

void TObjNpcFemaleChild::load_shared_resource() {
    void *memory = ::operator new(0x440);
    BmlResource *resource = (BmlResource *)memory;
    if (memory != NULL) {
        resource = load_resource_from_descriptor(memory, 1, &bm_n_ecw_i_body_resource_descriptor, 0, 0, 0);
    }
    TObjNpcFemaleChild__static_instance = resource;
}

TObjNpcFemaleChild::~TObjNpcFemaleChild() {}

TObjNpcFemaleChild *TObjNpcFemaleChild__ct(TObjNpcFemaleChild *npc, TObjControl *control, void *set_data) {
    npc->construct_female_base();
    *(s32 **)((u8 *)npc + 0x18) = __vt__18TObjNpcFemaleChild;
    npc->m_name = TObjNpcFemaleChild__name;
    npc->apply_set_data(set_data);
    ((TObjPlayer *)npc)->init_position_vectors();
    npc->model = (void *)TObjNpcFemaleChild__static_instance->models->model;
    npc->texlist = TObjNpcFemaleChild__static_instance->models->m_c;
    npc->setup_common();
    return npc;
}
