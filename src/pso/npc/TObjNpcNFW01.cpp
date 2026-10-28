#include "types.h"
#include "pso/npc/TObjNpcNHW00.h"
#include "pso/npc/TObjNpcNFW01.h"
#include "pso/npc/TUnk_804A8640.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcFemaleBase.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_8014CF50___vt__12TObjNpcNFW01 {
    s32 value;
    u8 remaining[0x174];
};

extern "C" {
extern s32 __vt__12TObjNpcNFW01[];
extern s32 TObjNpcNFW01__name;
extern s32 *TObjNpcNFW01__shared_object_resource;
extern s32 TObjNpcNFW01__texture_gvm;
void *TObjControl__ct(void *, void *);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

void *__dt__12TObjNpcNFW01Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__12TObjNpcNFW01;
        ((TUnk_804A8640 *)arg0)->destroy_npc_female_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern void *tl_04;

typedef char RecoveredGlobal_8014CF50___vt__12TObjNpcNFW01_size[sizeof(RecoveredGlobal_8014CF50___vt__12TObjNpcNFW01) == 0x178 ? 1 : -1];
u8 *TObjNpcNFW01__ct(u8 *arg0, s32 arg1, s32 arg2) {
    ((TUnk_804A8640 *)arg0)->construct_female_base();
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8014CF50___vt__12TObjNpcNFW01 *)&__vt__12TObjNpcNFW01).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TObjNpcNFW01__name;
    ((TObjNpcNFW01 *)(arg0))->apply_set_data((void *)arg2);
    ((TObjPlayer *)arg0)->init_position_vectors();
    *(s32 *)((s8 *)arg0 + 0x34) = (s32) *TObjNpcNFW01__shared_object_resource;
    ((TObjNpcNFW01 *)arg0)->texlist = (s32) TObjNpcNFW01__texture_gvm;
    ((TObjNpcBase *)arg0)->setup_common();
    return arg0;
}

void * TObjNpcNHW00__create(void *arg0) {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = TObjControl__ct(o, tl_04);
    }
    o2 = __nw__7TObjectFUl(0x3B8);
    if (o2 != NULL) {
        o2 = TObjNpcNHW00__ct((u8 *)o2, (s32)o, (s32)arg0);
    }
    return o2;
}

}
