#include "types.h"
#include "pso/npc/TObjNpcSoldierMacho.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResourceLoader.h"
#include "pso/system/task/TMainTask.h"

#pragma readonly_strings on

const char *bm_n_gunm_i_body_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_gunm_i_body_model_names[2] = { "n_gunm_i_body.nj", NULL };
BmlResourceDescriptor TObjNpcSoldierMacho__body_resource_desc = { "bm_n_gunm_i_body.bml", bm_n_gunm_i_body_model_names, bm_n_gunm_i_body_motion_names, 1, 0 };
const char *TObjNpcSoldierMacho__name = "TObjNpcSoldierMacho";
BmlResource *TObjNpcSoldierMacho__shared_model_resource;

extern "C" s32 __vt__19TObjNpcSoldierMacho[];

void *TObjNpcSoldierMacho__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    void *npc = TObject::operator new(sizeof(TObjNpcSoldierMacho));
    if (npc != NULL) {
        npc = TObjNpcSoldierMacho__ct((TObjNpcSoldierMacho *)npc, control, set_data);
    }
    return npc;
}

void TObjNpcSoldierMacho::unload_static_data() {
    if (TObjNpcSoldierMacho__shared_model_resource != NULL) {
        free_bin_model_request(TObjNpcSoldierMacho__shared_model_resource, 1);
        TObjNpcSoldierMacho__shared_model_resource = NULL;
    }
}

void TObjNpcSoldierMacho::load_shared_resource() {
    void *memory = ::operator new(0x440);
    BmlResource *resource = (BmlResource *)memory;
    if (memory != NULL) {
        resource = load_resource_from_descriptor(memory, 1, &TObjNpcSoldierMacho__body_resource_desc, 0, 0, 0);
    }
    TObjNpcSoldierMacho__shared_model_resource = resource;
}

TObjNpcSoldierMacho::~TObjNpcSoldierMacho() {}

TObjNpcSoldierMacho *TObjNpcSoldierMacho__ct(TObjNpcSoldierMacho *npc, TObjControl *control, void *set_data) {
    npc->construct_male_npc_base();
    *(s32 **)((u8 *)npc + 0x18) = __vt__19TObjNpcSoldierMacho;
    npc->m_name = TObjNpcSoldierMacho__name;
    npc->apply_set_data(set_data);
    ((TObjPlayer *)npc)->init_position_vectors();
    npc->model = (void *)TObjNpcSoldierMacho__shared_model_resource->models->model;
    npc->texlist = TObjNpcSoldierMacho__shared_model_resource->models->m_c;
    npc->setup_common();
    return npc;
}
