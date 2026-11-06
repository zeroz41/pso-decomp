#include "types.h"
#include "pso/npc/TObjNpcSoldierMacho.h"
#include "pso/unk/text_8014B8A4.h"
#include "pso/npc/TUnk_804A9F50.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcLappy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/BmlResourceDescriptor.h"

#pragma readonly_strings on

extern "C" {
extern const char *bm_n_gunm_i_body_motion_names[1];
extern const char *bm_n_gunm_i_body_model_names[2];
const char *bm_n_gunm_i_body_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_gunm_i_body_model_names[2] = { "n_gunm_i_body.nj", NULL };
BmlResourceDescriptor TObjNpcSoldierMacho__body_resource_desc = { "bm_n_gunm_i_body.bml", bm_n_gunm_i_body_model_names, bm_n_gunm_i_body_motion_names, 1, 0 };
const char *TObjNpcSoldierMacho__name = "TObjNpcSoldierMacho";
u32 TObjNpcSoldierMacho__shared_model_resource;
}

struct RecoveredGlobal_8014D9A4_lbl_804ABB08 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_8014D9A4_lbl_804ABB08_size[sizeof(RecoveredGlobal_8014D9A4_lbl_804ABB08) == 0x10 ? 1 : -1];

struct RecoveredGlobal_8014DA4C___vt__19TObjNpcSoldierMacho {
    s32 value;
    u8 remaining[0x174];
};

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern s32 __vt__19TObjNpcSoldierMacho[];
void TLobby__sub_8001FE7C(void*, int);
void __dl__7TObjectFPv(void *);

void TObjNpcSoldierMacho::unload_static_data() {
    if ((u32) TObjNpcSoldierMacho__shared_model_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TObjNpcSoldierMacho__shared_model_resource, 1);
        TObjNpcSoldierMacho__shared_model_resource = 0U;
    }
}

void TObjNpcSoldierMacho::load_shared_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &TObjNpcSoldierMacho__body_resource_desc, 0, 0, 0));
    }
    (*(s32 *)&TObjNpcSoldierMacho__shared_model_resource) = var_r0;
}

}
TObjNpcSoldierMacho::~TObjNpcSoldierMacho() {}
extern "C" {
typedef char RecoveredGlobal_8014DA4C___vt__19TObjNpcSoldierMacho_size[sizeof(RecoveredGlobal_8014DA4C___vt__19TObjNpcSoldierMacho) == 0x178 ? 1 : -1];
u8 *TObjNpcSoldierMacho__ct(u8 *player, s32 arg1, s32 arg2) {
    construct_male_npc_base((player));
    *(s32 **)((s8 *)player + 0x18) = &(*(RecoveredGlobal_8014DA4C___vt__19TObjNpcSoldierMacho *)&__vt__19TObjNpcSoldierMacho).value;
    *(s32 *)((s8 *)player + 0) = (s32) TObjNpcSoldierMacho__name;
    ((TObjNpcSoldierMacho *)(player))->apply_set_data((void *)arg2);
    ((TObjPlayer *)player)->init_position_vectors();
    *(s32 *)((s8 *)player + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TObjNpcSoldierMacho__shared_model_resource) + 0x42C)) + 8);
    ((TObjNpcSoldierMacho *)player)->texlist = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TObjNpcSoldierMacho__shared_model_resource) + 0x42C)) + 0xC);
    ((TObjNpcBase *)player)->setup_common();
    return player;
}

}
