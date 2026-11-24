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
const char *TObjNpcFemaleMacho::name = "TObjNpcFemaleMacho";
BmlResource *TObjNpcFemaleMacho::lobby_resource;

void *TObjNpcFemaleMacho::create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcFemaleMacho(control, set_data);
}

void TObjNpcFemaleMacho::close_dialog_window() {
    if (lobby_resource != NULL) {
        delete lobby_resource;
        lobby_resource = NULL;
    }
}

void TObjNpcFemaleMacho::load_resources() {
    BmlResource *resource = new BmlResource(1, &bm_n_emw_i_body_resource_descriptor, 0, 0, NULL);
    lobby_resource = resource;
}

TObjNpcFemaleMacho::~TObjNpcFemaleMacho() {}

TObjNpcFemaleMacho::TObjNpcFemaleMacho(TObject *parent, void *set_data) : TObjNpcFemale(parent) {
    this->m_name = name;
    this->apply_set_data(set_data);
    init_position_vectors();
    this->model = (void *)lobby_resource->models->model;
    this->texlist = lobby_resource->models->texlist;
    this->setup_common();
}
