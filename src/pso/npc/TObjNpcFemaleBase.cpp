#include "types.h"
#include "pso/npc/TUnk_804A8640.h"
#include "pso/npc/TObjNpcFemaleBase.h"
#include "pso/npc/TObjNpcFemaleChild.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_80149DE0_lbl_804A87C0 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_80149DE0_lbl_804A87C0_size[sizeof(RecoveredGlobal_80149DE0_lbl_804A87C0) == 0x10 ? 1 : -1];

struct RecoveredGlobal_80149FB8_lbl_804A8950 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_80149FB8_lbl_804A8950_size[sizeof(RecoveredGlobal_80149FB8_lbl_804A8950) == 0x10 ? 1 : -1];

struct RecoveredGlobal_80149E88___vt__17TObjNpcFemaleBase {
    s32 value;
    u8 remaining[0x174];
};

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_80149DE0_lbl_804A87C0 bm_n_ebw_i_body_resource_descriptor;
extern u32 TObjNpcFemaleBase__shared_resource_obj;
extern RecoveredGlobal_80149FB8_lbl_804A8950 bm_n_ecw_i_body_resource_descriptor;
extern u32 TObjNpcFemaleChild__static_instance;
extern s32 __vt__17TObjNpcFemaleBase[];
extern s32 TObjNpcFemaleBase__name;
u8 *TObjNpcFemaleBase__ct(u8 *arg0, s32 arg1, s32 arg2);
void * TObjNpcFemaleBase__create(void *arg0);
void * TObjNpcFemaleChild__create(void *arg0);
void *__dt__17TObjNpcFemaleBaseFv(void *arg0, s16 arg1);
void TLobby__sub_8001FE7C(void*, int);
void *TObjControl__ct(void *, void *);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

extern void *tl_04;

void * TObjNpcFemaleBase__create(void *arg0) {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = TObjControl__ct(o, tl_04);
    }
    o2 = __nw__7TObjectFUl(0x3B8);
    if (o2 != NULL) {
        o2 = TObjNpcFemaleBase__ct((u8 *)o2, (s32)o, (s32)arg0);
    }
    return o2;
}

void TObjNpcFemaleBase::free_static_data() {
    if ((u32) TObjNpcFemaleBase__shared_resource_obj != 0U) {
        TLobby__sub_8001FE7C((void*)TObjNpcFemaleBase__shared_resource_obj, 1);
        TObjNpcFemaleBase__shared_resource_obj = 0U;
    }
}

void TObjNpcFemaleBase::load_shared_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &bm_n_ebw_i_body_resource_descriptor.value, 0, 0, 0));
    }
    (*(s32 *)&TObjNpcFemaleBase__shared_resource_obj) = var_r0;
}

void *__dt__17TObjNpcFemaleBaseFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__17TObjNpcFemaleBase;
        ((TUnk_804A8640 *)arg0)->destroy_npc_female_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

typedef char RecoveredGlobal_80149E88___vt__17TObjNpcFemaleBase_size[sizeof(RecoveredGlobal_80149E88___vt__17TObjNpcFemaleBase) == 0x178 ? 1 : -1];
u8 *TObjNpcFemaleBase__ct(u8 *arg0, s32 arg1, s32 arg2) {
    ((TUnk_804A8640 *)arg0)->construct_female_base();
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_80149E88___vt__17TObjNpcFemaleBase *)&__vt__17TObjNpcFemaleBase).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TObjNpcFemaleBase__name;
    ((TObjNpcFemaleBase *)(arg0))->apply_set_data((void *)arg2);
    ((TObjPlayer *)arg0)->init_position_vectors();
    *(s32 *)((s8 *)arg0 + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TObjNpcFemaleBase__shared_resource_obj) + 0x42C)) + 8);
    ((TObjNpcFemaleBase *)arg0)->texture_id = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TObjNpcFemaleBase__shared_resource_obj) + 0x42C)) + 0xC);
    ((TObjNpcBase *)arg0)->setup_common();
    return arg0;
}

void * TObjNpcFemaleChild__create(void *arg0) {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = TObjControl__ct(o, tl_04);
    }
    o2 = __nw__7TObjectFUl(0x3B8);
    if (o2 != NULL) {
        o2 = TObjNpcFemaleChild__ct((u8 *)o2, (s32)o, (s32)arg0);
    }
    return o2;
}

void TObjNpcFemaleChild::release_static_instance() {
    if ((u32) TObjNpcFemaleChild__static_instance != 0U) {
        TLobby__sub_8001FE7C((void*)TObjNpcFemaleChild__static_instance, 1);
        TObjNpcFemaleChild__static_instance = 0U;
    }
}
void TObjNpcFemaleChild::load_shared_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &bm_n_ecw_i_body_resource_descriptor.value, 0, 0, 0));
    }
    (*(s32 *)&TObjNpcFemaleChild__static_instance) = var_r0;
}

}
