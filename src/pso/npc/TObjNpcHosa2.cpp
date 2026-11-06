#include "types.h"
#include "pso/npc/TObjNpcHosa2.h"
#include "pso/npc/TUnk_804A9F50.h"
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
u32 TObjNpcHosa2__shared_model_resource;
}

struct RecoveredGlobal_802FECB0_lbl_804E63D8 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_802FECB0_lbl_804E63D8_size[sizeof(RecoveredGlobal_802FECB0_lbl_804E63D8) == 0x10 ? 1 : -1];

struct RecoveredGlobal_802FED58___vt__12TObjNpcHosa2 {
    s32 value;
    u8 remaining[0x174];
};

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);

extern u32 TObjNpcHosa2__shared_model_resource;
s32 TObjFish__sub_8001EDB0(int, int);
s32 get_bml_model(int, int);
extern s32 __vt__12TObjNpcHosa2[];
extern const char *TObjNpcHosa2__name;
void TLobby__sub_8001FE7C(void*, int);
void __dl__7TObjectFPv(void *);

void TObjNpcHosa2::close_dialog_window() {
    if ((u32) TObjNpcHosa2__shared_model_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TObjNpcHosa2__shared_model_resource, 1);
        TObjNpcHosa2__shared_model_resource = 0U;
    }
}

void TObjNpcHosa2::load_shared_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &npc_hosa2_resource_descriptor, 0, 0, 0));
    }
    (*(s32 *)&TObjNpcHosa2__shared_model_resource) = var_r0;
}

}
TObjNpcHosa2::~TObjNpcHosa2() {}
extern "C" {
typedef char RecoveredGlobal_802FED58___vt__12TObjNpcHosa2_size[sizeof(RecoveredGlobal_802FED58___vt__12TObjNpcHosa2) == 0x178 ? 1 : -1];
u8 *TObjNpcHosa2__ct(u8 *player, s32 arg1, s32 arg2) {
    ((TUnk_804A9F50 *)player)->construct_male_npc_base();
    *(s32 **)((s8 *)player + 0x18) = &(*(RecoveredGlobal_802FED58___vt__12TObjNpcHosa2 *)&__vt__12TObjNpcHosa2).value;
    *(s32 *)((s8 *)player + 0) = (s32) TObjNpcHosa2__name;
    ((TObjNpcHosa2 *)(player))->apply_set_data((void *)arg2);
    ((TObjPlayer *)player)->init_position_vectors();
    *(s32 *)((s8 *)player + 0x34) = get_bml_model((int) ((*(s32 *)&TObjNpcHosa2__shared_model_resource)), 0);
    ((TObjNpcHosa2 *)player)->texlist = TObjFish__sub_8001EDB0((int) ((*(s32 *)&TObjNpcHosa2__shared_model_resource)), 0);
    ((TObjNpcBase *)player)->setup_common();
    return player;
}

}
