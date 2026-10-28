#include "types.h"
#include "pso/npc/TObjNpcSoutokufu.h"
#include "pso/unk/text_8014B8A4.h"
#include "pso/npc/TUnk_804A9F50.h"
#include "pso/npc/TObjNpcKenkyu.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcLappy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_80289400_lbl_804D3190 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_80289400_lbl_804D3190_size[sizeof(RecoveredGlobal_80289400_lbl_804D3190) == 0x10 ? 1 : -1];

struct RecoveredGlobal_802894A8___vt__13TObjNpcKenkyu {
    s32 value;
    u8 remaining[0x174];
};

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_80289400_lbl_804D3190 bm_npc_kenkyu_resource_descriptor;
extern u32 TObjNpcKenkyu__static_model;
s32 TObjFish__sub_8001EDB0(int, int);
s32 get_bml_model(int, int);
extern s32 __vt__13TObjNpcKenkyu[];
extern s32 TObjNpcKenkyu__name;
void TLobby__sub_8001FE7C(void*, int);
void *TObjControl__ct(void *, void *);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

void TObjNpcKenkyu::free_static_model() {
    if ((u32) TObjNpcKenkyu__static_model != 0U) {
        TLobby__sub_8001FE7C((void*)TObjNpcKenkyu__static_model, 1);
        TObjNpcKenkyu__static_model = 0U;
    }
}

void TObjNpcKenkyu::load_shared_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &bm_npc_kenkyu_resource_descriptor.value, 0, 0, 0));
    }
    (*(s32 *)&TObjNpcKenkyu__static_model) = var_r0;
}

void *__dt__13TObjNpcKenkyuFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__13TObjNpcKenkyu;
        ((TUnk_804A9F50 *)arg0)->destroy_npc_lappy_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern void *tl_04;

typedef char RecoveredGlobal_802894A8___vt__13TObjNpcKenkyu_size[sizeof(RecoveredGlobal_802894A8___vt__13TObjNpcKenkyu) == 0x178 ? 1 : -1];
u8 *TObjNpcKenkyu__ct(u8 *player, s32 arg1, s32 arg2) {
    construct_male_npc_base((player));
    *(s32 **)((s8 *)player + 0x18) = &(*(RecoveredGlobal_802894A8___vt__13TObjNpcKenkyu *)&__vt__13TObjNpcKenkyu).value;
    *(s32 *)((s8 *)player + 0) = (s32) TObjNpcKenkyu__name;
    ((TObjNpcKenkyu *)(player))->apply_set_data((void *)arg2);
    ((TObjPlayer *)player)->init_position_vectors();
    *(s32 *)((s8 *)player + 0x34) = get_bml_model((int) ((*(s32 *)&TObjNpcKenkyu__static_model)), 0);
    ((TObjNpcKenkyu *)player)->texture_id = TObjFish__sub_8001EDB0((int) ((*(s32 *)&TObjNpcKenkyu__static_model)), 0);
    ((TObjNpcBase *)player)->setup_common();
    return player;
}

void * TObjNpcSoutokufu__create(void *arg0) {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = TObjControl__ct(o, tl_04);
    }
    o2 = __nw__7TObjectFUl(0x3B8);
    if (o2 != NULL) {
        o2 = TObjNpcSoutokufu__ct((u8 *)o2, (s32)o, (s32)arg0);
    }
    return o2;
}

}
