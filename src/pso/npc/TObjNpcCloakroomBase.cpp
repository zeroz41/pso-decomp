#include "types.h"
#include "pso/npc/TObjNpcConnoisseur.h"
#include "pso/npc/TUnk_804A8640.h"
#include "pso/npc/TObjNpcCloakroomBase.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcFemaleBase.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/map/CurrentArea.h"

struct RecoveredGlobal_80149738_lbl_804A8098 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_80149738_lbl_804A8098_size[sizeof(RecoveredGlobal_80149738_lbl_804A8098) == 0x10 ? 1 : -1];

struct RecoveredGlobal_801497E0___vt__20TObjNpcCloakroomBase {
    s32 value;
    u8 remaining[0x174];
};

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_80149738_lbl_804A8098 bm_n_trunk_i_body_resource_descriptor;
extern u32 TObjNpcCloakroomBase__static_instance;
extern s32 __vt__20TObjNpcCloakroomBase[];
extern s32 TObjNpcCloakroomBase__name;
s32 play_sound_effect(s32, s32, s32, s32);
void TLobby__sub_8001FE7C(void*, int);
void *TObjControl__ct(void *, void *);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

void TObjNpcCloakroomBase::play_voice() {
    s32 arg0 = (s32)this;
    if (get_current_area() != 5) {
        play_sound_effect(0x40003804, arg0 + 0x38, 0, 0);
        return;
    }
    play_sound_effect(0x40003802, arg0 + 0x38, 0, 0);
}

extern void *tl_04;

void *TObjNpcCloakroomBase::create(void *arg0) {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = TObjControl__ct(o, tl_04);
    }
    o2 = __nw__7TObjectFUl(0x3B8);
    if (o2 != NULL) {
        o2 = TObjNpcCloakroomBase__ct((u8 *)o2, (s32)o, (s32)arg0);
    }
    return o2;
}

void TObjNpcCloakroomBase::destroy_static_instance() {
    if ((u32) TObjNpcCloakroomBase__static_instance != 0U) {
        TLobby__sub_8001FE7C((void*)TObjNpcCloakroomBase__static_instance, 1);
        TObjNpcCloakroomBase__static_instance = 0U;
    }
}

void TObjNpcCloakroomBase::load_shared_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &bm_n_trunk_i_body_resource_descriptor.value, 0, 0, 0));
    }
    (*(s32 *)&TObjNpcCloakroomBase__static_instance) = var_r0;
}

void *__dt__20TObjNpcCloakroomBaseFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__20TObjNpcCloakroomBase;
        ((TUnk_804A8640 *)arg0)->destroy_npc_female_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern f32 lbl_805DB1E8;

typedef char RecoveredGlobal_801497E0___vt__20TObjNpcCloakroomBase_size[sizeof(RecoveredGlobal_801497E0___vt__20TObjNpcCloakroomBase) == 0x178 ? 1 : -1];
u8 *TObjNpcCloakroomBase__ct(u8 *arg0, s32 arg1, s32 arg2) {
    ((TUnk_804A8640 *)arg0)->construct_female_base();
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_801497E0___vt__20TObjNpcCloakroomBase *)&__vt__20TObjNpcCloakroomBase).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TObjNpcCloakroomBase__name;
    ((TObjNpcCloakroomBase *)(arg0))->apply_set_data((void *)arg2);
    ((TObjPlayer *)arg0)->init_position_vectors();
    *(s32 *)((s8 *)arg0 + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TObjNpcCloakroomBase__static_instance) + 0x42C)) + 8);
    ((TObjNpcCloakroomBase *)arg0)->texture_id = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TObjNpcCloakroomBase__static_instance) + 0x42C)) + 0xC);
    ((TObjNpcBase *)arg0)->setup_common();
    return arg0;
}

f32 TObjNpcCloakroomBase::receive_direct_attack(void *, DirectAttackPayload, void *, s32, s32) {
    return lbl_805DB1E8;
}

void * TObjNpcConnoisseur__create(void *arg0) {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = TObjControl__ct(o, tl_04);
    }
    o2 = __nw__7TObjectFUl(0x3B8);
    if (o2 != NULL) {
        o2 = TObjNpcConnoisseur__ct((u8 *)o2, (s32)o, (s32)arg0);
    }
    return o2;
}

}
