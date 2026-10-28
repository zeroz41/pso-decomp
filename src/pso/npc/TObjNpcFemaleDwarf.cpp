#include "types.h"
#include "pso/npc/TObjNpcFemaleDwarf.h"
#include "pso/npc/TUnk_804A8640.h"
#include "pso/npc/TObjNpcFemaleFat.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcFemaleBase.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_8014A368_lbl_804A8C70 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_8014A368_lbl_804A8C70_size[sizeof(RecoveredGlobal_8014A368_lbl_804A8C70) == 0x10 ? 1 : -1];

struct RecoveredGlobal_8014A238___vt__18TObjNpcFemaleDwarf {
    s32 value;
    u8 remaining[0x174];
};

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_8014A368_lbl_804A8C70 bm_n_efw_i_body_resource_descriptor;
extern u32 TObjNpcFemaleFat__static_model;
extern s32 __vt__18TObjNpcFemaleDwarf[];
extern s32 TObjNpcFemaleDwarf__name;
extern u8 *TObjNpcFemaleDwarf__static_data;
void TLobby__sub_8001FE7C(void*, int);
void *TObjControl__ct(void *, void *);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

void *__dt__18TObjNpcFemaleDwarfFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__18TObjNpcFemaleDwarf;
        ((TUnk_804A8640 *)arg0)->destroy_npc_female_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern void *tl_04;

typedef char RecoveredGlobal_8014A238___vt__18TObjNpcFemaleDwarf_size[sizeof(RecoveredGlobal_8014A238___vt__18TObjNpcFemaleDwarf) == 0x178 ? 1 : -1];
u8 *TObjNpcFemaleDwarf__ct(u8 *arg0, s32 arg1, s32 arg2) {
    ((TUnk_804A8640 *)arg0)->construct_female_base();
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8014A238___vt__18TObjNpcFemaleDwarf *)&__vt__18TObjNpcFemaleDwarf).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TObjNpcFemaleDwarf__name;
    ((TObjNpcFemaleDwarf *)(arg0))->apply_set_data((void *)arg2);
    ((TObjPlayer *)arg0)->init_position_vectors();
    *(s32 *)((s8 *)arg0 + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)TObjNpcFemaleDwarf__static_data + 0x42C)) + 8);
    ((TObjNpcFemaleDwarf *)arg0)->texlist = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)TObjNpcFemaleDwarf__static_data + 0x42C)) + 0xC);
    ((TObjNpcBase *)arg0)->setup_common();
    return arg0;
}

void * TObjNpcFemaleFat__create(void *arg0) {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = TObjControl__ct(o, tl_04);
    }
    o2 = __nw__7TObjectFUl(0x3B8);
    if (o2 != NULL) {
        o2 = TObjNpcFemaleFat__ct((u8 *)o2, (s32)o, (s32)arg0);
    }
    return o2;
}

void TObjNpcFemaleFat::free_static_model() {
    if ((u32) TObjNpcFemaleFat__static_model != 0U) {
        TLobby__sub_8001FE7C((void*)TObjNpcFemaleFat__static_model, 1);
        TObjNpcFemaleFat__static_model = 0U;
    }
}
void TObjNpcFemaleFat::load_static_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &bm_n_efw_i_body_resource_descriptor.value, 0, 0, 0));
    }
    (*(s32 *)&TObjNpcFemaleFat__static_model) = var_r0;
}

}
