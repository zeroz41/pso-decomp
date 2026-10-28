#include "types.h"
#include "pso/npc/TObjNpcMaleChild.h"
#include "pso/unk/text_8014B8A4.h"
#include "pso/npc/TUnk_804A9F50.h"
#include "pso/npc/TObjNpcMaleBase.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcLappy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_8014B9A4_lbl_804AA0D0 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_8014B9A4_lbl_804AA0D0_size[sizeof(RecoveredGlobal_8014B9A4_lbl_804AA0D0) == 0x10 ? 1 : -1];

struct RecoveredGlobal_8014BA4C___vt__15TObjNpcMaleBase {
    s32 value;
    u8 remaining[0x174];
};

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_8014B9A4_lbl_804AA0D0 bm_n_ebm_i_body_resource_descriptor;
extern u32 TObjNpcMaleBase__shared_bml_archive;
extern s32 __vt__15TObjNpcMaleBase[];
extern s32 TObjNpcMaleBase__name;
u8 *TObjNpcMaleBase__ct(u8 *arg0, s32 arg1, s32 arg2);
void * TObjNpcMaleChild__create(void *arg0);
void *__dt__15TObjNpcMaleBaseFv(void *arg0, s16 arg1);
void TLobby__sub_8001FE7C(void*, int);
void *TObjControl__ct(void *, void *);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

void TObjNpcMaleBase::free_static_data() {
    if ((u32) TObjNpcMaleBase__shared_bml_archive != 0U) {
        TLobby__sub_8001FE7C((void*)TObjNpcMaleBase__shared_bml_archive, 1);
        TObjNpcMaleBase__shared_bml_archive = 0U;
    }
}

void TObjNpcMaleBase::load_shared_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &bm_n_ebm_i_body_resource_descriptor.value, 0, 0, 0));
    }
    (*(s32 *)&TObjNpcMaleBase__shared_bml_archive) = var_r0;
}

void *__dt__15TObjNpcMaleBaseFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__15TObjNpcMaleBase;
        ((TUnk_804A9F50 *)arg0)->destroy_npc_lappy_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern void *tl_04;

typedef char RecoveredGlobal_8014BA4C___vt__15TObjNpcMaleBase_size[sizeof(RecoveredGlobal_8014BA4C___vt__15TObjNpcMaleBase) == 0x178 ? 1 : -1];
u8 *TObjNpcMaleBase__ct(u8 *player, s32 arg1, s32 arg2) {
    construct_male_npc_base((player));
    *(s32 **)((s8 *)player + 0x18) = &(*(RecoveredGlobal_8014BA4C___vt__15TObjNpcMaleBase *)&__vt__15TObjNpcMaleBase).value;
    *(s32 *)((s8 *)player + 0) = (s32) TObjNpcMaleBase__name;
    ((TObjNpcMaleBase *)(player))->apply_set_data((void *)arg2);
    ((TObjPlayer *)player)->init_position_vectors();
    *(s32 *)((s8 *)player + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TObjNpcMaleBase__shared_bml_archive) + 0x42C)) + 8);
    ((TObjNpcMaleBase *)player)->texlist = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TObjNpcMaleBase__shared_bml_archive) + 0x42C)) + 0xC);
    ((TObjNpcBase *)player)->setup_common();
    return player;
}

void * TObjNpcMaleChild__create(void *arg0) {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = TObjControl__ct(o, tl_04);
    }
    o2 = __nw__7TObjectFUl(0x3B8);
    if (o2 != NULL) {
        o2 = TObjNpcMaleChild__ct((u8 *)o2, (s32)o, (s32)arg0);
    }
    return o2;
}

}
