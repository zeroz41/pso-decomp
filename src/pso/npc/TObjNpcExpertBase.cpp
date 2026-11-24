#include "pso/system/BmlResource.h"
#include "pso/object/TObjControl.h"
#include "pso/system/task/TMainTask.h"
#include "types.h"
#include "pso/npc/TObjNpcExpertBase.h"
#include "pso/npc/TObjNpcMale.h"

#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcLappy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/BmlResourceDescriptor.h"

#pragma readonly_strings on

void *TObjNpcExpertBase::create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcExpertBase(control, set_data);
}

const char *bm_n_hakase_i_body_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_hakase_i_body_model_names[2] = { "n_hakase_i_body.nj", NULL };
BmlResourceDescriptor bm_n_hakase_i_body_resource_descriptor = { "bm_n_hakase_i_body.bml", bm_n_hakase_i_body_model_names, bm_n_hakase_i_body_motion_names, 1, 0 };
const char *TObjNpcExpertBase::name = "TObjNpcExpertBase";
BmlResource *TObjNpcExpertBase::shared_resource;
void TObjNpcExpertBase::free_shared_data() {
    if (shared_resource != NULL) {
        delete shared_resource;
        shared_resource = NULL;
    }
}

void TObjNpcExpertBase::load_shared_resource() {
    shared_resource = new BmlResource(1, &bm_n_hakase_i_body_resource_descriptor, 0, 0, NULL);
}

TObjNpcExpertBase::~TObjNpcExpertBase() {}

TObjNpcExpertBase::TObjNpcExpertBase(TObject *parent, void *set_data) : TObjNpcMale(parent) {
    this->m_name = name;
    this->apply_set_data(set_data);
    init_position_vectors();
    model = shared_resource->models->model;
    texlist = shared_resource->models->texlist;
    this->setup_common();
}

