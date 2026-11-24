#include "pso/system/BmlResource.h"
#include "types.h"
#include "pso/object/TObjControl.h"
#include "pso/npc/TObjNpcGovernorBase.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/unk/text_800F9B84.h"
#include "pso/npc/TUnk_804A9F50.h"

#include "pso/npc/TObjNpcHFW00.h"
#include "pso/unk/TLobby.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcLappy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"

#pragma readonly_strings on

__declspec(section ".data") const char *bm_n_soutoku_i_body_model_names[2] = {"n_soutoku_i_body.nj", NULL};
const char *bm_n_soutoku_i_body_motion_names[] = {NULL};
BmlResourceDescriptor bm_n_soutoku_i_body_resource_descriptor = {
    "bm_n_soutoku_i_body.bml", bm_n_soutoku_i_body_model_names, bm_n_soutoku_i_body_motion_names, 1, 0,
};
const char *TObjNpcGovernorBase::name = "TObjNpcGovernorBase";
BmlResource *TObjNpcGovernorBase::shared_resource;


void *TObjNpcGovernorBase::create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcGovernorBase(control, set_data);
}

void TObjNpcGovernorBase::free_shared_data() {
    if (shared_resource != NULL) {
        delete shared_resource;
        shared_resource = NULL;
    }
}

void TObjNpcGovernorBase::load_shared_resource() {
    shared_resource = new BmlResource(1, &bm_n_soutoku_i_body_resource_descriptor, 0, 0, NULL);
}

TObjNpcGovernorBase::~TObjNpcGovernorBase() {}


TObjNpcGovernorBase::TObjNpcGovernorBase(TObject *parent, void *arg2) : TUnk_804A9F50(parent) {
    ((TObject *)this)->m_name = name;
    ((TObjNpcGovernorBase *)this)->apply_set_data(arg2);
    init_position_vectors();
    model = shared_resource->models->model;
    texlist = shared_resource->models->texlist;
    ((TObjNpcBase *)this)->setup_common();
}

