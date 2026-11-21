#include "pso/system/BmlResource.h"
#include "pso/system/BmlAccessors.h"
#include "types.h"
#include "pso/npc/TObjNpcHosa2.h"
#include "pso/npc/TUnk_804A9F50.h"

#include "pso/system/BmlResourceDescriptor.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcLappy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

#pragma readonly_strings on

extern "C" {
extern const char *bm_npc_hosa2_motion_names[1];
__declspec(section ".data") const char *bm_npc_hosa2_model_names[2] = { "hosa_hone2_body.nj", NULL };
BmlResourceDescriptor npc_hosa2_resource_descriptor = { "bm_npc_hosa2.bml", bm_npc_hosa2_model_names, bm_npc_hosa2_motion_names, 1, 0 };

const char *bm_npc_hosa2_motion_names[1] = { NULL };
const char *TObjNpcHosa2__name = "TObjNpcHosa2";
BmlResource *TObjNpcHosa2__shared_model_resource;
}

extern "C" {

extern BmlResource *TObjNpcHosa2__shared_model_resource;


extern const char *TObjNpcHosa2__name;

void TObjNpcHosa2::close_dialog_window() {
    if (TObjNpcHosa2__shared_model_resource != NULL) {
        delete TObjNpcHosa2__shared_model_resource;
        TObjNpcHosa2__shared_model_resource = NULL;
    }
}

void TObjNpcHosa2::load_shared_resource() {
    TObjNpcHosa2__shared_model_resource = new BmlResource(1, &npc_hosa2_resource_descriptor, 0, 0, NULL);
}

}
TObjNpcHosa2::~TObjNpcHosa2() {}

TObjNpcHosa2::TObjNpcHosa2(TObject *parent, void *arg2) : TUnk_804A9F50(parent) {
    *(s32 *)((s8 *)this + 0) = (saddr) TObjNpcHosa2__name;
    ((TObjNpcHosa2 *)this)->apply_set_data(arg2);
    ((TObjPlayer *)this)->init_position_vectors();
    model = get_bml_model(TObjNpcHosa2__shared_model_resource, 0);
    texlist = (saddr)get_bml_texlist(TObjNpcHosa2__shared_model_resource, 0);
    ((TObjNpcBase *)this)->setup_common();
}

