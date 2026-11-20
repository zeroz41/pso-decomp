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
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern u32 TObjNpcKenkyu2__shared_model_resource;
s32 get_bml_texlist(int, int);
s32 get_bml_model(int, int);
extern const char *TObjNpcKenkyu2__name;
void free_bin_model_request(void*, int);

void TObjNpcKenkyu2::free_static_model() {
    if ((u32) TObjNpcKenkyu2__shared_model_resource != 0U) {
        free_bin_model_request((void*)TObjNpcKenkyu2__shared_model_resource, 1);
        TObjNpcKenkyu2__shared_model_resource = 0U;
    }
}

void TObjNpcKenkyu2::load_shared_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &TObjNpcKenkyu2__resource_descriptor, 0, 0, 0));
    }
    (*(s32 *)&TObjNpcKenkyu2__shared_model_resource) = var_r0;
}

}
TObjNpcKenkyu2::~TObjNpcKenkyu2() {}
extern "C" {


TObjNpcKenkyu2::TObjNpcKenkyu2(TObject *parent, void *arg2) : TUnk_804A9F50(parent) {
    *(s32 *)((s8 *)this + 0) = (s32) TObjNpcKenkyu2__name;
    ((TObjNpcKenkyu2 *)this)->apply_set_data(arg2);
    ((TObjPlayer *)this)->init_position_vectors();
    *(s32 *)((s8 *)this + 0x34) = get_bml_model((int) ((*(s32 *)&TObjNpcKenkyu2__shared_model_resource)), 0);
    ((TObjNpcKenkyu2 *)this)->texlist = get_bml_texlist((int) ((*(s32 *)&TObjNpcKenkyu2__shared_model_resource)), 0);
    ((TObjNpcBase *)this)->setup_common();
}

void *TObjNpcHosa2__create(void *set_data) {
    TObjControl *control = new TObjControl((TObject *)tl_04);
    return new TObjNpcHosa2(control, set_data);
}

__declspec(section ".data") const char *bm_npc_kenkyu2_model_names[2] = { "kenkyu2_body.nj", NULL };
BmlResourceDescriptor TObjNpcKenkyu2__resource_descriptor = { "bm_npc_kenkyu2.bml", bm_npc_kenkyu2_model_names, bm_npc_kenkyu2_motion_names, 1, 0 };
__declspec(section ".sdata") const char *bm_npc_kenkyu2_motion_names[1] = { NULL };

const char *TObjNpcKenkyu2__name = "TObjNpcKenkyu2";
u32 TObjNpcKenkyu2__shared_model_resource;
}
