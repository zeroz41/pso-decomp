#include "types.h"
#include "pso/npc/TObjNpcFemaleBase.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResourceLoader.h"
#include "pso/system/task/TMainTask.h"

const char *bm_n_ebw_i_body_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_ebw_i_body_model_names[2] = { "n_ebw_i_body.nj", NULL };
BmlResourceDescriptor bm_n_ebw_i_body_resource_descriptor = { "bm_n_ebw_i_body.bml", bm_n_ebw_i_body_model_names, bm_n_ebw_i_body_motion_names, 1, 0 };
const char *TObjNpcFemaleBase__name = "TObjNpcFemaleBase";
BmlResource *TObjNpcFemaleBase__shared_resource_obj;

extern "C" s32 __vt__17TObjNpcFemaleBase[];

void *TObjNpcFemaleBase__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    void *npc = TObject::operator new(sizeof(TObjNpcFemaleBase));
    if (npc != NULL) {
        npc = TObjNpcFemaleBase__ct((TObjNpcFemaleBase *)npc, control, set_data);
    }
    return npc;
}

void TObjNpcFemaleBase::free_static_data() {
    if (TObjNpcFemaleBase__shared_resource_obj != NULL) {
        free_bin_model_request(TObjNpcFemaleBase__shared_resource_obj, 1);
        TObjNpcFemaleBase__shared_resource_obj = NULL;
    }
}

void TObjNpcFemaleBase::load_shared_resource() {
    void *memory = ::operator new(0x440);
    BmlResource *resource = (BmlResource *)memory;
    if (memory != NULL) {
        resource = load_resource_from_descriptor(memory, 1, &bm_n_ebw_i_body_resource_descriptor, 0, 0, 0);
    }
    TObjNpcFemaleBase__shared_resource_obj = resource;
}

TObjNpcFemaleBase::~TObjNpcFemaleBase() {}

TObjNpcFemaleBase *TObjNpcFemaleBase__ct(TObjNpcFemaleBase *npc, TObjControl *control, void *set_data) {
    npc->construct_female_base();
    *(s32 **)((u8 *)npc + 0x18) = __vt__17TObjNpcFemaleBase;
    npc->m_name = TObjNpcFemaleBase__name;
    npc->apply_set_data(set_data);
    ((TObjPlayer *)npc)->init_position_vectors();
    npc->model = (void *)TObjNpcFemaleBase__shared_resource_obj->models->model;
    npc->texlist = TObjNpcFemaleBase__shared_resource_obj->models->m_c;
    npc->setup_common();
    return npc;
}
