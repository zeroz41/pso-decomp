#include "types.h"
#include "pso/npc/TObjNpcMaleMacho.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/task/TMainTask.h"

#pragma readonly_strings on

const char *bm_n_emm_i_body_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_emm_i_body_model_names[2] = { "n_emm_i_body.nj", NULL };
BmlResourceDescriptor bm_n_emm_i_body_resource_descriptor = { "bm_n_emm_i_body.bml", bm_n_emm_i_body_model_names, bm_n_emm_i_body_motion_names, 1, 0 };
const char *TObjNpcMaleMacho__name = "TObjNpcMaleMacho";
BmlResource *TObjNpcMaleMacho__static_model_resource;

void *TObjNpcMaleMacho__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcMaleMacho(control, set_data);
}

void TObjNpcMaleMacho::close_dialog_window() {
    if (TObjNpcMaleMacho__static_model_resource != NULL) {
        delete TObjNpcMaleMacho__static_model_resource;
        TObjNpcMaleMacho__static_model_resource = NULL;
    }
}

void TObjNpcMaleMacho::load_static_resource() {
    BmlResource *resource = new BmlResource(1, &bm_n_emm_i_body_resource_descriptor, 0, 0, NULL);
    TObjNpcMaleMacho__static_model_resource = resource;
}

TObjNpcMaleMacho::~TObjNpcMaleMacho() {}

TObjNpcMaleMacho::TObjNpcMaleMacho(TObject *parent, void *set_data) : TUnk_804A9F50(parent) {
    this->m_name = TObjNpcMaleMacho__name;
    this->apply_set_data(set_data);
    init_position_vectors();
    this->model = (void *)TObjNpcMaleMacho__static_model_resource->models->model;
    this->texlist = (saddr)TObjNpcMaleMacho__static_model_resource->models->texlist;
    this->setup_common();
}
