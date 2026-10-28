#include "types.h"
#include "pso/unk/text_8014B8A4.h"
#include "pso/npc/TObjNpcMoja.h"
#include "pso/npc/TUnk_804A9F50.h"
#include "pso/npc/TObjNpcMaleTall.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcLappy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_8014C4B4_lbl_804AAA30 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_8014C4B4_lbl_804AAA30_size[sizeof(RecoveredGlobal_8014C4B4_lbl_804AAA30) == 0x10 ? 1 : -1];

struct RecoveredGlobal_8014C55C___vt__15TObjNpcMaleTall {
    s32 value;
    u8 remaining[0x174];
};

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_8014C4B4_lbl_804AAA30 bm_n_etm_i_body_resource_descriptor;
extern u32 TObjNpcMaleTall__shared_model_resource;
extern s32 __vt__15TObjNpcMaleTall[];
extern s32 TObjNpcMaleTall__name;
void TLobby__sub_8001FE7C(void*, int);
void __dl__7TObjectFPv(void *);

void TObjNpcMaleTall::destroy_instance() {
    if ((u32) TObjNpcMaleTall__shared_model_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TObjNpcMaleTall__shared_model_resource, 1);
        TObjNpcMaleTall__shared_model_resource = 0U;
    }
}

void TObjNpcMaleTall::load_resource_instance() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &bm_n_etm_i_body_resource_descriptor.value, 0, 0, 0));
    }
    (*(s32 *)&TObjNpcMaleTall__shared_model_resource) = var_r0;
}

void *__dt__15TObjNpcMaleTallFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__15TObjNpcMaleTall;
        ((TUnk_804A9F50 *)arg0)->destroy_npc_lappy_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

typedef char RecoveredGlobal_8014C55C___vt__15TObjNpcMaleTall_size[sizeof(RecoveredGlobal_8014C55C___vt__15TObjNpcMaleTall) == 0x178 ? 1 : -1];
u8 *TObjNpcMaleTall__ct(u8 *player, s32 arg1, s32 arg2) {
    construct_male_npc_base((player));
    *(s32 **)((s8 *)player + 0x18) = &(*(RecoveredGlobal_8014C55C___vt__15TObjNpcMaleTall *)&__vt__15TObjNpcMaleTall).value;
    *(s32 *)((s8 *)player + 0) = (s32) TObjNpcMaleTall__name;
    ((TObjNpcMaleTall *)(player))->apply_set_data((void *)arg2);
    ((TObjPlayer *)player)->init_position_vectors();
    *(s32 *)((s8 *)player + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TObjNpcMaleTall__shared_model_resource) + 0x42C)) + 8);
    ((TObjNpcMaleTall *)player)->texlist = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TObjNpcMaleTall__shared_model_resource) + 0x42C)) + 0xC);
    ((TObjNpcBase *)player)->setup_common();
    return player;
}

void TObjNpcMoja::vfunc_88() {
    if ((s16) this->mode != 2) {
        this->m_b8 = 0;
        return;
    }
    this->m_b8 = 1;
}

}
