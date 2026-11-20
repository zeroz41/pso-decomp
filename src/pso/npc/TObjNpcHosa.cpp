#include "types.h"
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
uaddr TObjNpcHosa__static_model_resource;
}

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);

s32 get_bml_texlist(int, int);
saddr get_bml_model(int, int);
extern s32 __vt__11TObjNpcHosa[];
extern const char *TObjNpcHosa__name;
void free_bin_model_request(void*, int);
void *__ct__11TObjControlFP7TObject(void *, void *);

void TObjNpcHosa::destroy_static_instance() {
    if ((u32) TObjNpcHosa__static_model_resource != 0U) {
        free_bin_model_request((void*)TObjNpcHosa__static_model_resource, 1);
        TObjNpcHosa__static_model_resource = 0U;
    }
}

void TObjNpcHosa::load_static_resource() {
    saddr temp_r3;
    s32 var_r0;
    temp_r3 = (saddr)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &npc_hosa_resource_descriptor, 0, 0, 0));
    }
    (*(s32 *)&TObjNpcHosa__static_model_resource) = var_r0;
}

}
TObjNpcHosa::~TObjNpcHosa() {}


extern void *tl_04;

u8 *TObjNpcHosa__ct(u8 *player, s32 arg1, saddr arg2) {
    ((TUnk_804A9F50 *)player)->construct_male_npc_base();
    *(s32 **)((s8 *)player + 0x18) = __vt__11TObjNpcHosa;
    *(s32 *)((s8 *)player + 0) = (saddr) TObjNpcHosa__name;
    ((TObjNpcHosa *)(player))->apply_set_data((void *)arg2);
    ((TObjPlayer *)player)->init_position_vectors();
    *(s32 *)((s8 *)player + 0x34) = get_bml_model((int) ((*(s32 *)&TObjNpcHosa__static_model_resource)), 0);
    ((TObjNpcHosa *)player)->texlist = get_bml_texlist((int) ((*(s32 *)&TObjNpcHosa__static_model_resource)), 0);
    ((TObjNpcBase *)player)->setup_common();
    return player;
}

void * TObjNpcKenkyuW__create(void *arg0) {
    void *o;
    void *o2;
    o = TObject::operator new(0x20);
    if (o != NULL) {
        o = __ct__11TObjControlFP7TObject(o, tl_04);
    }
    o2 = TObject::operator new(0x3B8);
    if (o2 != NULL) {
        o2 = TObjNpcKenkyuW__ct((u8 *)o2, (saddr)o, (saddr)arg0);
    }
    return o2;
}

