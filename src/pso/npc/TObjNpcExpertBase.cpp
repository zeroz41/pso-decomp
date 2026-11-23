#include "pso/system/BmlResource.h"
#include "types.h"
#include "pso/npc/TObjNpcExpertBase.h"
#include "pso/npc/TUnk_804A9F50.h"

#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcLappy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/BmlResourceDescriptor.h"

#pragma readonly_strings on

extern "C" {
extern const char *bm_n_hakase_i_body_motion_names[1];
extern const char *bm_n_hakase_i_body_model_names[2];
const char *bm_n_hakase_i_body_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_hakase_i_body_model_names[2] = { "n_hakase_i_body.nj", NULL };
BmlResourceDescriptor bm_n_hakase_i_body_resource_descriptor = { "bm_n_hakase_i_body.bml", bm_n_hakase_i_body_model_names, bm_n_hakase_i_body_motion_names, 1, 0 };
const char *TObjNpcExpertBase__name = "TObjNpcExpertBase";
BmlResource *TObjNpcExpertBase__shared_resource;
void TObjNpcExpertBase::free_shared_data() {
    if (TObjNpcExpertBase__shared_resource != NULL) {
        delete TObjNpcExpertBase__shared_resource;
        TObjNpcExpertBase__shared_resource = NULL;
    }
}

void TObjNpcExpertBase::load_shared_resource() {
    TObjNpcExpertBase__shared_resource = new BmlResource(1, &bm_n_hakase_i_body_resource_descriptor, 0, 0, NULL);
}

}
TObjNpcExpertBase::~TObjNpcExpertBase() {}

TObjNpcExpertBase::TObjNpcExpertBase(TObject *parent, void *arg2) : TUnk_804A9F50(parent) {
    *(s32 *)((s8 *)this + 0) = (saddr) TObjNpcExpertBase__name;
    ((TObjNpcExpertBase *)this)->apply_set_data(arg2);
    init_position_vectors();
    model = TObjNpcExpertBase__shared_resource->models->model;
    texlist = TObjNpcExpertBase__shared_resource->models->texlist;
    ((TObjNpcBase *)this)->setup_common();
}

