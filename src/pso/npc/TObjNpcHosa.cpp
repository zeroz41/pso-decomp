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

#pragma readonly_strings on

extern "C" {
extern const char *bm_npc_hosa_motion_names[1];
__declspec(section ".data") const char *bm_npc_hosa_model_names[2] = { "hosa_hone_body.nj", NULL };
BmlResourceDescriptor npc_hosa_resource_descriptor = { "bm_npc_hosa.bml", bm_npc_hosa_model_names, bm_npc_hosa_motion_names, 1, 0 };

const char *bm_npc_hosa_motion_names[1] = { NULL };
const char *TObjNpcHosa__name = "TObjNpcHosa";
u32 TObjNpcHosa__static_model_resource;
}

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);

s32 get_bml_texlist(int, int);
s32 get_bml_model(int, int);
extern const char *TObjNpcHosa__name;
void free_bin_model_request(void*, int);

void TObjNpcHosa::destroy_static_instance() {
    if ((u32) TObjNpcHosa__static_model_resource != 0U) {
        free_bin_model_request((void*)TObjNpcHosa__static_model_resource, 1);
        TObjNpcHosa__static_model_resource = 0U;
    }
}

void TObjNpcHosa::load_static_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &npc_hosa_resource_descriptor, 0, 0, 0));
    }
    (*(s32 *)&TObjNpcHosa__static_model_resource) = var_r0;
}

}
TObjNpcHosa::~TObjNpcHosa() {}


extern void *tl_04;

TObjNpcHosa::TObjNpcHosa(TObject *parent, void *arg2) : TUnk_804A9F50(parent) {
    *(s32 *)((s8 *)this + 0) = (s32) TObjNpcHosa__name;
    ((TObjNpcHosa *)this)->apply_set_data(arg2);
    ((TObjPlayer *)this)->init_position_vectors();
    *(s32 *)((s8 *)this + 0x34) = get_bml_model((int) ((*(s32 *)&TObjNpcHosa__static_model_resource)), 0);
    ((TObjNpcHosa *)this)->texlist = get_bml_texlist((int) ((*(s32 *)&TObjNpcHosa__static_model_resource)), 0);
    ((TObjNpcBase *)this)->setup_common();
}

void *TObjNpcKenkyuW__create(void *set_data) {
    TObjControl *control = new TObjControl((TObject *)tl_04);
    return new TObjNpcKenkyuW(control, set_data);
}

