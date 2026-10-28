#include "types.h"
#include "pso/npc/TObjNpcSoldierBase.h"
#include "pso/npc/TUnk_804A8640.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/npc/TObjNpcSecretaryBase.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcFemaleBase.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern char lbl_8043FEA0[];
extern char lbl_8043FEB4[];
extern const char *bm_n_hisyo_i_body_model_names[2];
extern BmlResourceDescriptor secretary_body_resource_descriptor;
extern const char *bm_n_hisyo_i_body_motion_names[1];

struct RecoveredGlobal_8014D5F4_lbl_804AB7E8 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_8014D5F4_lbl_804AB7E8_size[sizeof(RecoveredGlobal_8014D5F4_lbl_804AB7E8) == 0x10 ? 1 : -1];

struct RecoveredGlobal_8014D69C___vt__20TObjNpcSecretaryBase {
    s32 value;
    u8 remaining[0x174];
};

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern u32 TObjNpcSecretaryBase__static_model_resource;
extern s32 __vt__20TObjNpcSecretaryBase[];
extern s32 TObjNpcSecretaryBase__name;
void TLobby__sub_8001FE7C(void*, int);
void *TObjControl__ct(void *, void *);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

void TObjNpcSecretaryBase::free_static_data() {
    if ((u32) TObjNpcSecretaryBase__static_model_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TObjNpcSecretaryBase__static_model_resource, 1);
        TObjNpcSecretaryBase__static_model_resource = 0U;
    }
}

void TObjNpcSecretaryBase::load_static_data() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &secretary_body_resource_descriptor, 0, 0, 0));
    }
    (*(s32 *)&TObjNpcSecretaryBase__static_model_resource) = var_r0;
}

void *__dt__20TObjNpcSecretaryBaseFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__20TObjNpcSecretaryBase;
        ((TUnk_804A8640 *)arg0)->destroy_npc_female_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern void *tl_04;

typedef char RecoveredGlobal_8014D69C___vt__20TObjNpcSecretaryBase_size[sizeof(RecoveredGlobal_8014D69C___vt__20TObjNpcSecretaryBase) == 0x178 ? 1 : -1];
u8 *TObjNpcSecretaryBase__ct(u8 *arg0, s32 arg1, s32 arg2) {
    ((TUnk_804A8640 *)arg0)->construct_female_base();
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8014D69C___vt__20TObjNpcSecretaryBase *)&__vt__20TObjNpcSecretaryBase).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TObjNpcSecretaryBase__name;
    ((TObjNpcSecretaryBase *)(arg0))->apply_set_data((void *)arg2);
    ((TObjPlayer *)arg0)->init_position_vectors();
    *(s32 *)((s8 *)arg0 + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TObjNpcSecretaryBase__static_model_resource) + 0x42C)) + 8);
    ((TObjNpcSecretaryBase *)arg0)->texlist = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TObjNpcSecretaryBase__static_model_resource) + 0x42C)) + 0xC);
    ((TObjNpcBase *)arg0)->setup_common();
    return arg0;
}

void * TObjNpcSoldierBase__create(void *arg0) {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = TObjControl__ct(o, tl_04);
    }
    o2 = __nw__7TObjectFUl(0x3B8);
    if (o2 != NULL) {
        o2 = TObjNpcSoldierBase__ct((u8 *)o2, (s32)o, (s32)arg0);
    }
    return o2;
}

__declspec(section ".data") const char *bm_n_hisyo_i_body_model_names[2] = { lbl_8043FEA0, NULL };
BmlResourceDescriptor secretary_body_resource_descriptor = { lbl_8043FEB4, bm_n_hisyo_i_body_model_names, bm_n_hisyo_i_body_motion_names, 1, 0 };
__declspec(section ".sdata") const char *bm_n_hisyo_i_body_motion_names[1] = { NULL };
}
