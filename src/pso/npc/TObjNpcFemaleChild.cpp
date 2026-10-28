#include "types.h"
#include "pso/npc/TObjNpcFemaleChild.h"
#include "pso/npc/TUnk_804A8640.h"
#include "pso/npc/TObjNpcFemaleDwarf.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcFemaleBase.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_8014A190_lbl_804A8AE0 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_8014A190_lbl_804A8AE0_size[sizeof(RecoveredGlobal_8014A190_lbl_804A8AE0) == 0x10 ? 1 : -1];

struct RecoveredGlobal_8014A060___vt__18TObjNpcFemaleChild {
    s32 value;
    u8 remaining[0x174];
};

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_8014A190_lbl_804A8AE0 bm_n_efsw_i_body_resource_descriptor;
extern u32 TObjNpcFemaleDwarf__static_data;
extern s32 __vt__18TObjNpcFemaleChild[];
extern s32 TObjNpcFemaleChild__name;
extern u8 *TObjNpcFemaleChild__static_instance;
void TLobby__sub_8001FE7C(void*, int);
void *TObjControl__ct(void *, void *);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

void *__dt__18TObjNpcFemaleChildFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__18TObjNpcFemaleChild;
        ((TUnk_804A8640 *)arg0)->destroy_npc_female_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern void *tl_04;

typedef char RecoveredGlobal_8014A060___vt__18TObjNpcFemaleChild_size[sizeof(RecoveredGlobal_8014A060___vt__18TObjNpcFemaleChild) == 0x178 ? 1 : -1];
u8 *TObjNpcFemaleChild__ct(u8 *arg0, s32 arg1, s32 arg2) {
    ((TUnk_804A8640 *)arg0)->construct_female_base();
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8014A060___vt__18TObjNpcFemaleChild *)&__vt__18TObjNpcFemaleChild).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TObjNpcFemaleChild__name;
    ((TObjNpcFemaleChild *)(arg0))->apply_set_data((void *)arg2);
    ((TObjPlayer *)arg0)->init_position_vectors();
    *(s32 *)((s8 *)arg0 + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)TObjNpcFemaleChild__static_instance + 0x42C)) + 8);
    ((TObjNpcFemaleChild *)arg0)->texlist = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)TObjNpcFemaleChild__static_instance + 0x42C)) + 0xC);
    ((TObjNpcBase *)arg0)->setup_common();
    return arg0;
}

void * TObjNpcFemaleDwarf__create(void *arg0) {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = TObjControl__ct(o, tl_04);
    }
    o2 = __nw__7TObjectFUl(0x3B8);
    if (o2 != NULL) {
        o2 = TObjNpcFemaleDwarf__ct((u8 *)o2, (s32)o, (s32)arg0);
    }
    return o2;
}

void TObjNpcFemaleDwarf::unload_static_data() {
    if ((u32) TObjNpcFemaleDwarf__static_data != 0U) {
        TLobby__sub_8001FE7C((void*)TObjNpcFemaleDwarf__static_data, 1);
        TObjNpcFemaleDwarf__static_data = 0U;
    }
}
void TObjNpcFemaleDwarf::load_static_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &bm_n_efsw_i_body_resource_descriptor.value, 0, 0, 0));
    }
    (*(s32 *)&TObjNpcFemaleDwarf__static_data) = var_r0;
}

}
