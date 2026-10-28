#include "types.h"
#include "pso/misc/TLanguage_801E4874.h"
#include "pso/unk/text_800F9B84.h"
#include "pso/unk/text_8014B8A4.h"
#include "pso/npc/TUnk_804A9F50.h"
#include "pso/npc/TObjNpcGovernorBase.h"
#include "pso/npc/TObjNpcHFW00.h"
#include "pso/misc/TLobby.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcLappy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_8014ABC4_lbl_804A9428 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_8014ABC4_lbl_804A9428_size[sizeof(RecoveredGlobal_8014ABC4_lbl_804A9428) == 0x10 ? 1 : -1];

struct RecoveredGlobal_8014AC6C___vt__19TObjNpcGovernorBase {
    s32 value;
    u8 remaining[0x174];
};

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_8014ABC4_lbl_804A9428 bm_n_soutoku_i_body_resource_descriptor;
extern u32 TObjNpcGovernorBase__shared_resource;
extern s32 __vt__19TObjNpcGovernorBase[];
extern s32 TObjNpcGovernorBase__name;
extern u32 TObjNpcHFW00__shared_resource_obj;
extern u32 TObjNpcHFW00__texture_handle;
extern char lbl_8043FA38[];
extern char lbl_8043FA4C[];
void TLobby__sub_8001FE7C(void*, int);
void release_texture_list(void*);
void *TObjControl__ct(void *, void *);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

void TObjNpcGovernorBase::free_shared_data() {
    if ((u32) TObjNpcGovernorBase__shared_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TObjNpcGovernorBase__shared_resource, 1);
        TObjNpcGovernorBase__shared_resource = 0U;
    }
}

void TObjNpcGovernorBase::load_shared_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &bm_n_soutoku_i_body_resource_descriptor.value, 0, 0, 0));
    }
    (*(s32 *)&TObjNpcGovernorBase__shared_resource) = var_r0;
}

void *__dt__19TObjNpcGovernorBaseFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__19TObjNpcGovernorBase;
        ((TUnk_804A9F50 *)arg0)->destroy_npc_lappy_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern void *tl_04;

typedef char RecoveredGlobal_8014AC6C___vt__19TObjNpcGovernorBase_size[sizeof(RecoveredGlobal_8014AC6C___vt__19TObjNpcGovernorBase) == 0x178 ? 1 : -1];
u8 *TObjNpcGovernorBase__ct(u8 *player, s32 arg1, s32 arg2) {
    construct_male_npc_base((player));
    *(s32 **)((s8 *)player + 0x18) = &(*(RecoveredGlobal_8014AC6C___vt__19TObjNpcGovernorBase *)&__vt__19TObjNpcGovernorBase).value;
    *(s32 *)((s8 *)player + 0) = (s32) TObjNpcGovernorBase__name;
    ((TObjNpcGovernorBase *)(player))->apply_set_data((void *)arg2);
    ((TObjPlayer *)player)->init_position_vectors();
    *(s32 *)((s8 *)player + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TObjNpcGovernorBase__shared_resource) + 0x42C)) + 8);
    ((TObjNpcGovernorBase *)player)->texture_id = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TObjNpcGovernorBase__shared_resource) + 0x42C)) + 0xC);
    ((TObjNpcBase *)player)->setup_common();
    return player;
}

void * TObjNpcHFW00__create(void *arg0) {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = TObjControl__ct(o, tl_04);
    }
    o2 = __nw__7TObjectFUl(0x3B8);
    if (o2 != NULL) {
        o2 = TObjNpcHFW00__ct((u8 *)o2, (s32)o, (s32)arg0);
    }
    return o2;
}

void TObjNpcHFW00::free_resources() {
    if ((u32) TObjNpcHFW00__texture_handle != 0U) {
        release_texture_list((void*)TObjNpcHFW00__texture_handle);
        TAdSinglePlyChrSelectGC::safe_free(TObjNpcHFW00__texture_handle);
        TObjNpcHFW00__texture_handle = 0U;
    }
    if ((u32) TObjNpcHFW00__shared_resource_obj != 0U) {
        TLobby::free_nodes_with_id((u32)((void*)TObjNpcHFW00__shared_resource_obj));
        TObjNpcHFW00__shared_resource_obj = 0U;
    }
}
void TObjNpcHFW00::load_resources() {
    TObjNpcHFW00__shared_resource_obj = (u32)create_named_object((s32)lbl_8043FA38);
    TObjNpcHFW00__texture_handle = (u32)load_gvm_texture_file((s32)lbl_8043FA4C);
}

}
