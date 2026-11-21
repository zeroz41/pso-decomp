#include "pso/system/BmlResource.h"
#include "pso/system/BmlAccessors.h"
#include "types.h"
#include "pso/object/TObjControl.h"
#include "pso/npc/TObjNpcHosa.h"
#include "pso/npc/TObjNpcKenkyuW.h"
#include "pso/npc/TUnk_804A9F50.h"

#include "pso/system/BmlResourceDescriptor.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcLappy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"

#pragma readonly_strings on

extern "C" {
extern const char *bm_npc_hosa_motion_names[1];
__declspec(section ".data") const char *bm_npc_hosa_model_names[2] = { "hosa_hone_body.nj", NULL };
BmlResourceDescriptor npc_hosa_resource_descriptor = { "bm_npc_hosa.bml", bm_npc_hosa_model_names, bm_npc_hosa_motion_names, 1, 0 };

const char *bm_npc_hosa_motion_names[1] = { NULL };
const char *TObjNpcHosa__name = "TObjNpcHosa";
BmlResource *TObjNpcHosa__static_model_resource;
}

extern "C" {



extern const char *TObjNpcHosa__name;

void TObjNpcHosa::destroy_static_instance() {
    if (TObjNpcHosa__static_model_resource != NULL) {
        delete TObjNpcHosa__static_model_resource;
        TObjNpcHosa__static_model_resource = NULL;
    }
}

void TObjNpcHosa::load_static_resource() {
    TObjNpcHosa__static_model_resource = new BmlResource(1, &npc_hosa_resource_descriptor, 0, 0, NULL);
}

}
TObjNpcHosa::~TObjNpcHosa() {}



TObjNpcHosa::TObjNpcHosa(TObject *parent, void *arg2) : TUnk_804A9F50(parent) {
    *(s32 *)((s8 *)this + 0) = (saddr) TObjNpcHosa__name;
    ((TObjNpcHosa *)this)->apply_set_data(arg2);
    ((TObjPlayer *)this)->init_position_vectors();
    model = get_bml_model(TObjNpcHosa__static_model_resource, 0);
    texlist = (saddr)get_bml_texlist(TObjNpcHosa__static_model_resource, 0);
    ((TObjNpcBase *)this)->setup_common();
}

void *TObjNpcKenkyuW__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcKenkyuW(control, set_data);
}

