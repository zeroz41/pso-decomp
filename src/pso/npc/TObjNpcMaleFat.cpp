#include "types.h"
#include "pso/npc/TObjNpcMaleMacho.h"
#include "pso/unk/text_8014B8A4.h"
#include "pso/npc/TObjNpcMaleFat.h"
#include "pso/npc/TUnk_804A9F50.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcLappy.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_8014BFD4___vt__14TObjNpcMaleFat {
    s32 value;
    u8 remaining[0x174];
};

extern "C" {
extern s32 __vt__14TObjNpcMaleFat[];
extern s32 TObjNpcMaleFat__name;
extern u8 *TObjNpcMaleFat__static_model_resource;
void *TObjControl__ct(void *, void *);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

void *__dt__14TObjNpcMaleFatFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__14TObjNpcMaleFat;
        ((TUnk_804A9F50 *)arg0)->destroy_npc_lappy_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern void *tl_04;

typedef char RecoveredGlobal_8014BFD4___vt__14TObjNpcMaleFat_size[sizeof(RecoveredGlobal_8014BFD4___vt__14TObjNpcMaleFat) == 0x178 ? 1 : -1];
u8 *TObjNpcMaleFat__ct(u8 *player, s32 arg1, s32 arg2) {
    construct_male_npc_base((player));
    *(s32 **)((s8 *)player + 0x18) = &(*(RecoveredGlobal_8014BFD4___vt__14TObjNpcMaleFat *)&__vt__14TObjNpcMaleFat).value;
    *(s32 *)((s8 *)player + 0) = (s32) TObjNpcMaleFat__name;
    ((TObjNpcMaleFat *)(player))->apply_set_data((void *)arg2);
    ((TObjPlayer *)player)->init_position_vectors();
    *(s32 *)((s8 *)player + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)TObjNpcMaleFat__static_model_resource + 0x42C)) + 8);
    ((TObjNpcMaleFat *)player)->texlist = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)TObjNpcMaleFat__static_model_resource + 0x42C)) + 0xC);
    ((TObjNpcBase *)player)->setup_common();
    return player;
}

void * TObjNpcMaleMacho__create(void *arg0) {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = TObjControl__ct(o, tl_04);
    }
    o2 = __nw__7TObjectFUl(0x3B8);
    if (o2 != NULL) {
        o2 = TObjNpcMaleMacho__ct((u8 *)o2, (s32)o, (s32)arg0);
    }
    return o2;
}

}
