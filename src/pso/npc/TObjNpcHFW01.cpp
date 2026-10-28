#include "types.h"
#include "pso/npc/TObjNpcHHM00.h"
#include "pso/unk/text_8014AAC4.h"
#include "pso/npc/TObjNpcHFW01.h"
#include "pso/npc/TUnk_804A92A8.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcFemaleTall.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_8014B020___vt__12TObjNpcHFW01 {
    s32 value;
    u8 remaining[0x174];
};

extern "C" {
extern s32 __vt__12TObjNpcHFW01[];
extern s32 TObjNpcHFW01__name;
extern s32 *TObjNpcHFW01__resource_node;
extern s32 TObjNpcHFW01__texture_handle;
void *TObjControl__ct(void *, void *);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

void *__dt__12TObjNpcHFW01Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__12TObjNpcHFW01;
        ((TUnk_804A92A8 *)arg0)->destroy(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern void *tl_04;

typedef char RecoveredGlobal_8014B020___vt__12TObjNpcHFW01_size[sizeof(RecoveredGlobal_8014B020___vt__12TObjNpcHFW01) == 0x178 ? 1 : -1];
u8 *TObjNpcHFW01__ct(u8 *player, s32 arg1, s32 arg2) {
    fn_8014AAC4((player));
    *(s32 **)((s8 *)player + 0x18) = &(*(RecoveredGlobal_8014B020___vt__12TObjNpcHFW01 *)&__vt__12TObjNpcHFW01).value;
    *(s32 *)((s8 *)player + 0) = (s32) TObjNpcHFW01__name;
    ((TObjNpcHFW01 *)(player))->apply_set_data((void *)arg2);
    ((TObjPlayer *)player)->init_position_vectors();
    *(s32 *)((s8 *)player + 0x34) = (s32) *TObjNpcHFW01__resource_node;
    ((TObjNpcHFW01 *)player)->texlist = (s32) TObjNpcHFW01__texture_handle;
    ((TObjNpcBase *)player)->setup_common();
    return player;
}

void * TObjNpcHHM00__create(void *arg0) {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = TObjControl__ct(o, tl_04);
    }
    o2 = __nw__7TObjectFUl(0x3B8);
    if (o2 != NULL) {
        o2 = TObjNpcHHM00__ct((u8 *)o2, (s32)o, (s32)arg0);
    }
    return o2;
}

}
