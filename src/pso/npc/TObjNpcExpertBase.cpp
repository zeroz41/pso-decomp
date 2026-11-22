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
uaddr TObjNpcExpertBase__shared_resource;
void TObjNpcExpertBase::free_shared_data() {
    if ((u32) TObjNpcExpertBase__shared_resource != 0U) {
        delete (BmlResource *)TObjNpcExpertBase__shared_resource;
        TObjNpcExpertBase__shared_resource = 0U;
    }
}

void TObjNpcExpertBase::load_shared_resource() {
    saddr temp_r3;
    s32 var_r0;
    var_r0 = (saddr)new BmlResource(1, &bm_n_hakase_i_body_resource_descriptor, 0, 0, NULL);
    (*(s32 *)&TObjNpcExpertBase__shared_resource) = var_r0;
}

}
TObjNpcExpertBase::~TObjNpcExpertBase() {}

TObjNpcExpertBase::TObjNpcExpertBase(TObject *parent, void *arg2) : TUnk_804A9F50(parent) {
    *(s32 *)((s8 *)this + 0) = (saddr) TObjNpcExpertBase__name;
    ((TObjNpcExpertBase *)this)->apply_set_data(arg2);
    ((TObjPlayer *)this)->init_position_vectors();
    *(s32 *)((s8 *)this + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TObjNpcExpertBase__shared_resource) + 0x42C)) + 8);
    ((TObjNpcExpertBase *)this)->texlist = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TObjNpcExpertBase__shared_resource) + 0x42C)) + 0xC);
    ((TObjNpcBase *)this)->setup_common();
}

