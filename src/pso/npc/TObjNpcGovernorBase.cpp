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
const char *TObjNpcGovernorBase__name = "TObjNpcGovernorBase";
uaddr TObjNpcGovernorBase__shared_resource;


void *TObjNpcGovernorBase__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcGovernorBase(control, set_data);
}

void TObjNpcGovernorBase::free_shared_data() {
    if ((u32) TObjNpcGovernorBase__shared_resource != 0U) {
        delete (BmlResource *)TObjNpcGovernorBase__shared_resource;
        TObjNpcGovernorBase__shared_resource = 0U;
    }
}

void TObjNpcGovernorBase::load_shared_resource() {
    saddr temp_r3;
    s32 var_r0;
    var_r0 = (saddr)new BmlResource(1, &bm_n_soutoku_i_body_resource_descriptor, 0, 0, NULL);
    (*(s32 *)&TObjNpcGovernorBase__shared_resource) = var_r0;
}

TObjNpcGovernorBase::~TObjNpcGovernorBase() {}


TObjNpcGovernorBase::TObjNpcGovernorBase(TObject *parent, void *arg2) : TUnk_804A9F50(parent) {
    ((TObject *)this)->m_name = TObjNpcGovernorBase__name;
    ((TObjNpcGovernorBase *)this)->apply_set_data(arg2);
    ((TObjPlayer *)this)->init_position_vectors();
    *(s32 *)((s8 *)this + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TObjNpcGovernorBase__shared_resource) + 0x42C)) + 8);
    ((TObjNpcGovernorBase *)this)->texlist = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TObjNpcGovernorBase__shared_resource) + 0x42C)) + 0xC);
    ((TObjNpcBase *)this)->setup_common();
}

