#include "pso/system/BmlResource.h"
#include "pso/system/BmlAccessors.h"
#include "types.h"
#include "pso/object/TObjControl.h"
#include "pso/npc/TObjNpcKenkyu.h"
#include "pso/npc/TObjNpcSoutokufu.h"
#include "pso/npc/TUnk_804A9F50.h"

#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcLappy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"

#pragma readonly_strings on

extern "C" {
extern const char *bm_npc_kenkyu_motion_names[1];
extern const char *bm_npc_kenkyu_model_names[2];
const char *bm_npc_kenkyu_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_npc_kenkyu_model_names[2] = { "kenkyu_body.nj", NULL };
BmlResourceDescriptor bm_npc_kenkyu_resource_descriptor = { "bm_npc_kenkyu.bml", bm_npc_kenkyu_model_names, bm_npc_kenkyu_motion_names, 1, 0 };
const char *TObjNpcKenkyu__name = "TObjNpcKenkyu";
BmlResource *TObjNpcKenkyu__static_model;
void TObjNpcKenkyu::free_static_model() {
    if (TObjNpcKenkyu__static_model != NULL) {
        delete TObjNpcKenkyu__static_model;
        TObjNpcKenkyu__static_model = NULL;
    }
}

void TObjNpcKenkyu::load_shared_resource() {
    TObjNpcKenkyu__static_model = new BmlResource(1, &bm_npc_kenkyu_resource_descriptor, 0, 0, NULL);
}

}
TObjNpcKenkyu::~TObjNpcKenkyu() {}


TObjNpcKenkyu::TObjNpcKenkyu(TObject *parent, void *arg2) : TUnk_804A9F50(parent) {
    *(s32 *)((s8 *)this + 0) = (saddr) TObjNpcKenkyu__name;
    ((TObjNpcKenkyu *)this)->apply_set_data(arg2);
    init_position_vectors();
    model = get_bml_model(TObjNpcKenkyu__static_model, 0);
    texlist = (saddr)get_bml_texlist(TObjNpcKenkyu__static_model, 0);
    ((TObjNpcBase *)this)->setup_common();
}

void *TObjNpcSoutokufu__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcSoutokufu(control, set_data);
}

