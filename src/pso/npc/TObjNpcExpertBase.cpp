#include "types.h"
#include "pso/npc/TObjNpcExpertBase.h"
#include "pso/unk/text_8014B8A4.h"
#include "pso/npc/TUnk_804A9F50.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcLappy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/system/BmlResourceDescriptor.h"

#pragma readonly_strings on

extern "C" {
extern const char *bm_n_hakase_i_body_motion_names[1];
extern const char *bm_n_hakase_i_body_model_names[2];
const char *bm_n_hakase_i_body_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_hakase_i_body_model_names[2] = { "n_hakase_i_body.nj", NULL };
BmlResourceDescriptor bm_n_hakase_i_body_resource_descriptor = { "bm_n_hakase_i_body.bml", bm_n_hakase_i_body_model_names, bm_n_hakase_i_body_motion_names, 1, 0 };
const char *TObjNpcExpertBase__name = "TObjNpcExpertBase";
u32 TObjNpcExpertBase__shared_resource;
}

struct RecoveredGlobal_80149B0C_lbl_804A84B8 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_80149B0C_lbl_804A84B8_size[sizeof(RecoveredGlobal_80149B0C_lbl_804A84B8) == 0x10 ? 1 : -1];

struct RecoveredGlobal_80149BB4___vt__17TObjNpcExpertBase {
    s32 value;
    u8 remaining[0x174];
};

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern s32 __vt__17TObjNpcExpertBase[];
void TLobby__sub_8001FE7C(void*, int);
void __dl__7TObjectFPv(void *);

void TObjNpcExpertBase::free_shared_data() {
    if ((u32) TObjNpcExpertBase__shared_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TObjNpcExpertBase__shared_resource, 1);
        TObjNpcExpertBase__shared_resource = 0U;
    }
}

void TObjNpcExpertBase::load_shared_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &bm_n_hakase_i_body_resource_descriptor, 0, 0, 0));
    }
    (*(s32 *)&TObjNpcExpertBase__shared_resource) = var_r0;
}

}
TObjNpcExpertBase::~TObjNpcExpertBase() {}
extern "C" {
typedef char RecoveredGlobal_80149BB4___vt__17TObjNpcExpertBase_size[sizeof(RecoveredGlobal_80149BB4___vt__17TObjNpcExpertBase) == 0x178 ? 1 : -1];
u8 *TObjNpcExpertBase__ct(u8 *player, s32 arg1, s32 arg2) {
    construct_male_npc_base((player));
    *(s32 **)((s8 *)player + 0x18) = &(*(RecoveredGlobal_80149BB4___vt__17TObjNpcExpertBase *)&__vt__17TObjNpcExpertBase).value;
    *(s32 *)((s8 *)player + 0) = (s32) TObjNpcExpertBase__name;
    ((TObjNpcExpertBase *)(player))->apply_set_data((void *)arg2);
    ((TObjPlayer *)player)->init_position_vectors();
    *(s32 *)((s8 *)player + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TObjNpcExpertBase__shared_resource) + 0x42C)) + 8);
    ((TObjNpcExpertBase *)player)->texlist = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TObjNpcExpertBase__shared_resource) + 0x42C)) + 0xC);
    ((TObjNpcBase *)player)->setup_common();
    return player;
}

}
