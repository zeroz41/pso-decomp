#include "types.h"
#include "pso/unk/text_8014B8A4.h"
#include "pso/npc/TUnk_804A9F50.h"
#include "pso/npc/TObjNpcExpertBase.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcLappy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_80149B0C_lbl_804A84B8 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_80149B0C_lbl_804A84B8_size[sizeof(RecoveredGlobal_80149B0C_lbl_804A84B8) == 0x10 ? 1 : -1];

struct RecoveredGlobal_80149BB4___vt__17TObjNpcExpertBase {
    s32 value;
    u8 remaining[0x174];
};

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_80149B0C_lbl_804A84B8 bm_n_hakase_i_body_resource_descriptor;
extern u32 TObjNpcExpertBase__shared_resource;
extern s32 __vt__17TObjNpcExpertBase[];
extern s32 TObjNpcExpertBase__name;
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
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &bm_n_hakase_i_body_resource_descriptor.value, 0, 0, 0));
    }
    (*(s32 *)&TObjNpcExpertBase__shared_resource) = var_r0;
}

void *__dt__17TObjNpcExpertBaseFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__17TObjNpcExpertBase;
        ((TUnk_804A9F50 *)arg0)->destroy_npc_lappy_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_80149BB4___vt__17TObjNpcExpertBase_size[sizeof(RecoveredGlobal_80149BB4___vt__17TObjNpcExpertBase) == 0x178 ? 1 : -1];
u8 *TObjNpcExpertBase__ct(u8 *player, s32 arg1, s32 arg2) {
    construct_male_npc_base((player));
    *(s32 **)((s8 *)player + 0x18) = &(*(RecoveredGlobal_80149BB4___vt__17TObjNpcExpertBase *)&__vt__17TObjNpcExpertBase).value;
    *(s32 *)((s8 *)player + 0) = (s32) TObjNpcExpertBase__name;
    ((TObjNpcExpertBase *)(player))->apply_set_data((void *)arg2);
    ((TObjPlayer *)player)->init_position_vectors();
    *(s32 *)((s8 *)player + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TObjNpcExpertBase__shared_resource) + 0x42C)) + 8);
    ((TObjNpcExpertBase *)player)->texture_id = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TObjNpcExpertBase__shared_resource) + 0x42C)) + 0xC);
    ((TObjNpcBase *)player)->setup_common();
    return player;
}

}
