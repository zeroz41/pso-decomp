#include "types.h"
#include "pso/npc/TObjNpcFemaleMacho.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResourceLoader.h"
#include "pso/system/task/TMainTask.h"

const char *bm_n_emw_i_body_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_emw_i_body_model_names[2] = { "n_emw_i_body.nj", NULL };
BmlResourceDescriptor bm_n_emw_i_body_resource_descriptor = { "bm_n_emw_i_body.bml", bm_n_emw_i_body_model_names, bm_n_emw_i_body_motion_names, 1, 0 };
const char *TObjNpcFemaleMacho__name = "TObjNpcFemaleMacho";
BmlResource *TObjNpcFemaleMacho__lobby_resource;

extern "C" s32 __vt__18TObjNpcFemaleMacho[];

void *TObjNpcFemaleMacho__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    void *npc = TObject::operator new(sizeof(TObjNpcFemaleMacho));
    if (npc != NULL) {
        npc = TObjNpcFemaleMacho__ct((TObjNpcFemaleMacho *)npc, control, set_data);
    }
    return npc;
}

void TObjNpcFemaleMacho::close_dialog_window() {
    if (TObjNpcFemaleMacho__lobby_resource != NULL) {
        free_bin_model_request(TObjNpcFemaleMacho__lobby_resource, 1);
        TObjNpcFemaleMacho__lobby_resource = NULL;
    }
}

void TObjNpcFemaleMacho::load_resources() {
    void *memory = ::operator new(0x440);
    BmlResource *resource = (BmlResource *)memory;
    if (memory != NULL) {
        resource = load_resource_from_descriptor(memory, 1, &bm_n_emw_i_body_resource_descriptor, 0, 0, 0);
    }
    TObjNpcFemaleMacho__lobby_resource = resource;
}

TObjNpcFemaleMacho::~TObjNpcFemaleMacho() {}

TObjNpcFemaleMacho *TObjNpcFemaleMacho__ct(TObjNpcFemaleMacho *npc, TObjControl *control, void *set_data) {
    npc->construct_female_base();
    *(s32 **)((u8 *)npc + 0x18) = __vt__18TObjNpcFemaleMacho;
    npc->m_name = TObjNpcFemaleMacho__name;
    npc->apply_set_data(set_data);
    ((TObjPlayer *)npc)->init_position_vectors();
    npc->model = (void *)TObjNpcFemaleMacho__lobby_resource->models->model;
    npc->texlist = TObjNpcFemaleMacho__lobby_resource->models->m_c;
    npc->setup_common();
    return npc;
}
