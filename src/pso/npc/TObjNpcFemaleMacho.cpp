#include "types.h"
#include "pso/npc/TObjNpcFemaleMacho.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/task/TMainTask.h"

const char *bm_n_emw_i_body_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_emw_i_body_model_names[2] = { "n_emw_i_body.nj", NULL };
BmlResourceDescriptor bm_n_emw_i_body_resource_descriptor = { "bm_n_emw_i_body.bml", bm_n_emw_i_body_model_names, bm_n_emw_i_body_motion_names, 1, 0 };
const char *TObjNpcFemaleMacho__name = "TObjNpcFemaleMacho";
BmlResource *TObjNpcFemaleMacho__lobby_resource;

void *TObjNpcFemaleMacho__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcFemaleMacho(control, set_data);
}

void TObjNpcFemaleMacho::close_dialog_window() {
    if (TObjNpcFemaleMacho__lobby_resource != NULL) {
        delete TObjNpcFemaleMacho__lobby_resource;
        TObjNpcFemaleMacho__lobby_resource = NULL;
    }
}

void TObjNpcFemaleMacho::load_resources() {
    BmlResource *resource = new BmlResource(1, &bm_n_emw_i_body_resource_descriptor, 0, 0, NULL);
    TObjNpcFemaleMacho__lobby_resource = resource;
}

TObjNpcFemaleMacho::~TObjNpcFemaleMacho() {}

TObjNpcFemaleMacho::TObjNpcFemaleMacho(TObject *parent, void *set_data) : TUnk_804A8640(parent) {
    this->m_name = TObjNpcFemaleMacho__name;
    this->apply_set_data(set_data);
    init_position_vectors();
    this->model = (void *)TObjNpcFemaleMacho__lobby_resource->models->model;
    this->texlist = (saddr)TObjNpcFemaleMacho__lobby_resource->models->texlist;
    this->setup_common();
}
