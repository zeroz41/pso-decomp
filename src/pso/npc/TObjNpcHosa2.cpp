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
uaddr TObjNpcHosa2__shared_model_resource;
}

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);

extern uaddr TObjNpcHosa2__shared_model_resource;
saddr get_bml_texlist(int, int);
saddr get_bml_model(int, int);
extern s32 __vt__12TObjNpcHosa2[];
extern const char *TObjNpcHosa2__name;
void free_bin_model_request(void*, int);

void TObjNpcHosa2::close_dialog_window() {
    if ((u32) TObjNpcHosa2__shared_model_resource != 0U) {
        free_bin_model_request((void*)TObjNpcHosa2__shared_model_resource, 1);
        TObjNpcHosa2__shared_model_resource = 0U;
    }
}

void TObjNpcHosa2::load_shared_resource() {
    saddr temp_r3;
    s32 var_r0;
    temp_r3 = (saddr)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &npc_hosa2_resource_descriptor, 0, 0, 0));
    }
    (*(s32 *)&TObjNpcHosa2__shared_model_resource) = var_r0;
}

}
TObjNpcHosa2::~TObjNpcHosa2() {}

u8 *TObjNpcHosa2__ct(u8 *player, s32 arg1, saddr arg2) {
    ((TUnk_804A9F50 *)player)->construct_male_npc_base();
    *(s32 **)((s8 *)player + 0x18) = __vt__12TObjNpcHosa2;
    *(s32 *)((s8 *)player + 0) = (saddr) TObjNpcHosa2__name;
    ((TObjNpcHosa2 *)(player))->apply_set_data((void *)arg2);
    ((TObjPlayer *)player)->init_position_vectors();
    *(s32 *)((s8 *)player + 0x34) = get_bml_model((int) ((*(s32 *)&TObjNpcHosa2__shared_model_resource)), 0);
    ((TObjNpcHosa2 *)player)->texlist = get_bml_texlist((int) ((*(s32 *)&TObjNpcHosa2__shared_model_resource)), 0);
    ((TObjNpcBase *)player)->setup_common();
    return player;
}

