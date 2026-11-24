#include "types.h"
#include "pso/npc/TObjNpcMaleBase.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/task/TMainTask.h"

#pragma readonly_strings on

const char *bm_n_ebm_i_body_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_ebm_i_body_model_names[2] = { "n_ebm_i_body_4.nj", NULL };
BmlResourceDescriptor bm_n_ebm_i_body_resource_descriptor = { "bm_n_ebm_i_body.bml", bm_n_ebm_i_body_model_names, bm_n_ebm_i_body_motion_names, 1, 0 };
const char *TObjNpcMaleBase::name = "TObjNpcMaleBase";
BmlResource *TObjNpcMaleBase::shared_bml_archive;

void *TObjNpcMaleBase::create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcMaleBase(control, set_data);
}

void TObjNpcMaleBase::free_static_data() {
    if (shared_bml_archive != NULL) {
        delete shared_bml_archive;
        shared_bml_archive = NULL;
    }
}

void TObjNpcMaleBase::load_shared_resource() {
    BmlResource *resource = new BmlResource(1, &bm_n_ebm_i_body_resource_descriptor, 0, 0, NULL);
    shared_bml_archive = resource;
}

TObjNpcMaleBase::~TObjNpcMaleBase() {}

TObjNpcMaleBase::TObjNpcMaleBase(TObject *parent, void *set_data) : TObjNpcMale(parent) {
    this->m_name = name;
    this->apply_set_data(set_data);
    init_position_vectors();
    this->model = (void *)shared_bml_archive->models->model;
    this->texlist = shared_bml_archive->models->texlist;
    this->setup_common();
}
