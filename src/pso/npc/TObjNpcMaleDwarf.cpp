#include "types.h"
#include "pso/unk/text_8014B8A4.h"
#include "pso/npc/TUnk_804A9F50.h"
#include "pso/npc/TObjNpcMaleDwarf.h"
#include "pso/npc/TObjNpcMaleFat.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcLappy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_8014BD54_lbl_804AA3F0 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_8014BD54_lbl_804AA3F0_size[sizeof(RecoveredGlobal_8014BD54_lbl_804AA3F0) == 0x10 ? 1 : -1];

struct RecoveredGlobal_8014BF2C_lbl_804AA580 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_8014BF2C_lbl_804AA580_size[sizeof(RecoveredGlobal_8014BF2C_lbl_804AA580) == 0x10 ? 1 : -1];

struct RecoveredGlobal_8014BDFC___vt__16TObjNpcMaleDwarf {
    s32 value;
    u8 remaining[0x174];
};

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_8014BD54_lbl_804AA3F0 bm_n_efsm_i_body_3_resource_descriptor;
extern u32 TObjNpcMaleDwarf__shared_model_resource;
extern RecoveredGlobal_8014BF2C_lbl_804AA580 bm_n_efm_i_body_resource_descriptor;
extern u32 TObjNpcMaleFat__static_model_resource;
extern s32 __vt__16TObjNpcMaleDwarf[];
extern s32 TObjNpcMaleDwarf__name;
void TLobby__sub_8001FE7C(void*, int);
void *TObjControl__ct(void *, void *);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

void TObjNpcMaleDwarf::unload_static_data() {
    if ((u32) TObjNpcMaleDwarf__shared_model_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TObjNpcMaleDwarf__shared_model_resource, 1);
        TObjNpcMaleDwarf__shared_model_resource = 0U;
    }
}

void TObjNpcMaleDwarf::load_shared_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &bm_n_efsm_i_body_3_resource_descriptor.value, 0, 0, 0));
    }
    (*(s32 *)&TObjNpcMaleDwarf__shared_model_resource) = var_r0;
}

void *__dt__16TObjNpcMaleDwarfFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__16TObjNpcMaleDwarf;
        ((TUnk_804A9F50 *)arg0)->destroy_npc_lappy_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern void *tl_04;

typedef char RecoveredGlobal_8014BDFC___vt__16TObjNpcMaleDwarf_size[sizeof(RecoveredGlobal_8014BDFC___vt__16TObjNpcMaleDwarf) == 0x178 ? 1 : -1];
u8 *TObjNpcMaleDwarf__ct(u8 *player, s32 arg1, s32 arg2) {
    construct_male_npc_base((player));
    *(s32 **)((s8 *)player + 0x18) = &(*(RecoveredGlobal_8014BDFC___vt__16TObjNpcMaleDwarf *)&__vt__16TObjNpcMaleDwarf).value;
    *(s32 *)((s8 *)player + 0) = (s32) TObjNpcMaleDwarf__name;
    ((TObjNpcMaleDwarf *)(player))->apply_set_data((void *)arg2);
    ((TObjPlayer *)player)->init_position_vectors();
    *(s32 *)((s8 *)player + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TObjNpcMaleDwarf__shared_model_resource) + 0x42C)) + 8);
    ((TObjNpcMaleDwarf *)player)->texlist = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TObjNpcMaleDwarf__shared_model_resource) + 0x42C)) + 0xC);
    ((TObjNpcBase *)player)->setup_common();
    return player;
}

void * TObjNpcMaleFat__create(void *arg0) {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = TObjControl__ct(o, tl_04);
    }
    o2 = __nw__7TObjectFUl(0x3B8);
    if (o2 != NULL) {
        o2 = TObjNpcMaleFat__ct((u8 *)o2, (s32)o, (s32)arg0);
    }
    return o2;
}

void TObjNpcMaleFat::free_static_model() {
    if ((u32) TObjNpcMaleFat__static_model_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TObjNpcMaleFat__static_model_resource, 1);
        TObjNpcMaleFat__static_model_resource = 0U;
    }
}
void TObjNpcMaleFat::load_static_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &bm_n_efm_i_body_resource_descriptor.value, 0, 0, 0));
    }
    (*(s32 *)&TObjNpcMaleFat__static_model_resource) = var_r0;
}

}
