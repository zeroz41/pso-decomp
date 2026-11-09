#include "types.h"
#include "pso/npc/TObjNpcKenkyu.h"
#include "pso/npc/TObjNpcSoutokufu.h"
#include "pso/npc/TUnk_804A9F50.h"
#include "pso/npc/TUnk_804A9F50.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcLappy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/BmlResourceDescriptor.h"

#pragma readonly_strings on

extern "C" {
extern const char *bm_npc_kenkyu_motion_names[1];
extern const char *bm_npc_kenkyu_model_names[2];
const char *bm_npc_kenkyu_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_npc_kenkyu_model_names[2] = { "kenkyu_body.nj", NULL };
BmlResourceDescriptor bm_npc_kenkyu_resource_descriptor = { "bm_npc_kenkyu.bml", bm_npc_kenkyu_model_names, bm_npc_kenkyu_motion_names, 1, 0 };
const char *TObjNpcKenkyu__name = "TObjNpcKenkyu";
u32 TObjNpcKenkyu__static_model;
}

struct RecoveredGlobal_80289400_lbl_804D3190 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_80289400_lbl_804D3190_size[sizeof(RecoveredGlobal_80289400_lbl_804D3190) == 0x10 ? 1 : -1];

struct RecoveredGlobal_802894A8___vt__13TObjNpcKenkyu {
    s32 value;
    u8 remaining[0x174];
};

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
s32 TObjFish__sub_8001EDB0(int, int);
s32 get_bml_model(int, int);
extern s32 __vt__13TObjNpcKenkyu[];
void free_bin_model_request(void*, int);
void *__ct__11TObjControlFP7TObject(void *, void *);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

void TObjNpcKenkyu::free_static_model() {
    if ((u32) TObjNpcKenkyu__static_model != 0U) {
        free_bin_model_request((void*)TObjNpcKenkyu__static_model, 1);
        TObjNpcKenkyu__static_model = 0U;
    }
}

void TObjNpcKenkyu::load_shared_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &bm_npc_kenkyu_resource_descriptor, 0, 0, 0));
    }
    (*(s32 *)&TObjNpcKenkyu__static_model) = var_r0;
}

}
TObjNpcKenkyu::~TObjNpcKenkyu() {}
extern "C" {

extern void *tl_04;

typedef char RecoveredGlobal_802894A8___vt__13TObjNpcKenkyu_size[sizeof(RecoveredGlobal_802894A8___vt__13TObjNpcKenkyu) == 0x178 ? 1 : -1];
u8 *TObjNpcKenkyu__ct(u8 *player, s32 arg1, s32 arg2) {
    ((TUnk_804A9F50 *)player)->construct_male_npc_base();
    *(s32 **)((s8 *)player + 0x18) = &(*(RecoveredGlobal_802894A8___vt__13TObjNpcKenkyu *)&__vt__13TObjNpcKenkyu).value;
    *(s32 *)((s8 *)player + 0) = (s32) TObjNpcKenkyu__name;
    ((TObjNpcKenkyu *)(player))->apply_set_data((void *)arg2);
    ((TObjPlayer *)player)->init_position_vectors();
    *(s32 *)((s8 *)player + 0x34) = get_bml_model((int) ((*(s32 *)&TObjNpcKenkyu__static_model)), 0);
    ((TObjNpcKenkyu *)player)->texlist = TObjFish__sub_8001EDB0((int) ((*(s32 *)&TObjNpcKenkyu__static_model)), 0);
    ((TObjNpcBase *)player)->setup_common();
    return player;
}

void * TObjNpcSoutokufu__create(void *arg0) {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = __ct__11TObjControlFP7TObject(o, tl_04);
    }
    o2 = __nw__7TObjectFUl(0x3B8);
    if (o2 != NULL) {
        o2 = TObjNpcSoutokufu__ct((u8 *)o2, (s32)o, (s32)arg0);
    }
    return o2;
}

}
