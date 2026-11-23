#include "types.h"
#include "pso/npc/TObjNpcSoldierMacho.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/task/TMainTask.h"

#pragma readonly_strings on

const char *bm_n_gunm_i_body_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_gunm_i_body_model_names[2] = { "n_gunm_i_body.nj", NULL };
BmlResourceDescriptor TObjNpcSoldierMacho__body_resource_desc = { "bm_n_gunm_i_body.bml", bm_n_gunm_i_body_model_names, bm_n_gunm_i_body_motion_names, 1, 0 };
const char *TObjNpcSoldierMacho__name = "TObjNpcSoldierMacho";
BmlResource *TObjNpcSoldierMacho__shared_model_resource;

void *TObjNpcSoldierMacho__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcSoldierMacho(control, set_data);
}

void TObjNpcSoldierMacho::unload_static_data() {
    if (TObjNpcSoldierMacho__shared_model_resource != NULL) {
        delete TObjNpcSoldierMacho__shared_model_resource;
        TObjNpcSoldierMacho__shared_model_resource = NULL;
    }
}

void TObjNpcSoldierMacho::load_shared_resource() {
    BmlResource *resource = new BmlResource(1, &TObjNpcSoldierMacho__body_resource_desc, 0, 0, NULL);
    TObjNpcSoldierMacho__shared_model_resource = resource;
}

TObjNpcSoldierMacho::~TObjNpcSoldierMacho() {}

TObjNpcSoldierMacho::TObjNpcSoldierMacho(TObject *parent, void *set_data) : TUnk_804A9F50(parent) {
    this->m_name = TObjNpcSoldierMacho__name;
    this->apply_set_data(set_data);
    init_position_vectors();
    this->model = (void *)TObjNpcSoldierMacho__shared_model_resource->models->model;
    this->texlist = TObjNpcSoldierMacho__shared_model_resource->models->texlist;
    this->setup_common();
}
