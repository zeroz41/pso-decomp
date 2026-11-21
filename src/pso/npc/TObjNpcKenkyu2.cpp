#include "pso/system/BmlResource.h"
#include "pso/system/BmlAccessors.h"
#include "types.h"
#include "pso/object/TObjControl.h"
#include "pso/npc/TObjNpcKenkyu2.h"
#include "pso/npc/TObjNpcKenkyu2_802FEA38.h"
#include "pso/npc/TObjNpcHosa2.h"
#include "pso/npc/TUnk_804A9F50.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcLappy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/task/TObject.h"
#pragma readonly_strings on

extern "C" {


extern void *tl_04;

void *TObjNpcKenkyu2__create(void *set_data) {
    TObjControl *control = new TObjControl((TObject *)tl_04);
    return new TObjNpcKenkyu2(control, set_data);
}

}

extern const char *bm_npc_kenkyu2_model_names[2];
extern BmlResourceDescriptor TObjNpcKenkyu2__resource_descriptor;
extern const char *bm_npc_kenkyu2_motion_names[1];

extern "C" {
extern BmlResource *TObjNpcKenkyu2__shared_model_resource;


extern const char *TObjNpcKenkyu2__name;

void TObjNpcKenkyu2::free_static_model() {
    if (TObjNpcKenkyu2__shared_model_resource != NULL) {
        delete TObjNpcKenkyu2__shared_model_resource;
        TObjNpcKenkyu2__shared_model_resource = NULL;
    }
}

void TObjNpcKenkyu2::load_shared_resource() {
    TObjNpcKenkyu2__shared_model_resource = new BmlResource(1, &TObjNpcKenkyu2__resource_descriptor, 0, 0, NULL);
}

}
TObjNpcKenkyu2::~TObjNpcKenkyu2() {}
extern "C" {


TObjNpcKenkyu2::TObjNpcKenkyu2(TObject *parent, void *arg2) : TUnk_804A9F50(parent) {
    *(s32 *)((s8 *)this + 0) = (saddr) TObjNpcKenkyu2__name;
    ((TObjNpcKenkyu2 *)this)->apply_set_data(arg2);
    ((TObjPlayer *)this)->init_position_vectors();
    model = get_bml_model(TObjNpcKenkyu2__shared_model_resource, 0);
    texlist = (saddr)get_bml_texlist(TObjNpcKenkyu2__shared_model_resource, 0);
    ((TObjNpcBase *)this)->setup_common();
}

void *TObjNpcHosa2__create(void *set_data) {
    TObjControl *control = new TObjControl((TObject *)tl_04);
    return new TObjNpcHosa2(control, set_data);
}
}

__declspec(section ".data") const char *bm_npc_kenkyu2_model_names[2] = { "kenkyu2_body.nj", NULL };
BmlResourceDescriptor TObjNpcKenkyu2__resource_descriptor = { "bm_npc_kenkyu2.bml", bm_npc_kenkyu2_model_names, bm_npc_kenkyu2_motion_names, 1, 0 };
__declspec(section ".sdata") const char *bm_npc_kenkyu2_motion_names[1] = { NULL };
extern "C" {

const char *TObjNpcKenkyu2__name = "TObjNpcKenkyu2";
BmlResource *TObjNpcKenkyu2__shared_model_resource;
}
