#include "types.h"
#include "pso/npc/TObjNpcNurseBase.h"
#include "pso/misc/TLanguage_801E4874.h"
#include "pso/unk/text_800F9B84.h"
#include "pso/npc/TUnk_804A8640.h"
#include "pso/npc/TObjNpcNHW01.h"
#include "pso/misc/TLobby.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcFemaleBase.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_8014D2F8___vt__12TObjNpcNHW01 {
    s32 value;
    u8 remaining[0x174];
};

extern "C" {
extern s32 __vt__12TObjNpcNHW01[];
extern s32 TObjNpcNHW01__name;
extern u32 TObjNpcNHW01__model_object;
extern u32 TObjNpcNHW01__texture_handle;
extern char lbl_8043FE38[];
extern char lbl_8043FE4C[];
void release_texture_list(void*);
void *TObjControl__ct(void *, void *);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

void TObjNpcNHW01::free_resources() {
    if ((u32) TObjNpcNHW01__texture_handle != 0U) {
        release_texture_list((void*)TObjNpcNHW01__texture_handle);
        TAdSinglePlyChrSelectGC::safe_free(TObjNpcNHW01__texture_handle);
        TObjNpcNHW01__texture_handle = 0U;
    }
    if ((u32) TObjNpcNHW01__model_object != 0U) {
        TLobby::free_nodes_with_id((u32)((void*)TObjNpcNHW01__model_object));
        TObjNpcNHW01__model_object = 0U;
    }
}

void TObjNpcNHW01::load_resources() {
    TObjNpcNHW01__model_object = (u32)create_named_object((s32)lbl_8043FE38);
    TObjNpcNHW01__texture_handle = (u32)load_gvm_texture_file((s32)lbl_8043FE4C);
}

void *__dt__12TObjNpcNHW01Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__12TObjNpcNHW01;
        ((TUnk_804A8640 *)arg0)->destroy_npc_female_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern void *tl_04;

typedef char RecoveredGlobal_8014D2F8___vt__12TObjNpcNHW01_size[sizeof(RecoveredGlobal_8014D2F8___vt__12TObjNpcNHW01) == 0x178 ? 1 : -1];
u8 *TObjNpcNHW01__ct(u8 *arg0, s32 arg1, s32 arg2) {
    ((TUnk_804A8640 *)arg0)->construct_female_base();
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8014D2F8___vt__12TObjNpcNHW01 *)&__vt__12TObjNpcNHW01).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TObjNpcNHW01__name;
    ((TObjNpcNHW01 *)(arg0))->apply_set_data((void *)arg2);
    ((TObjPlayer *)arg0)->init_position_vectors();
    *(s32 *)((s8 *)arg0 + 0x34) = (s32) *(*(s32 * *)&TObjNpcNHW01__model_object);
    ((TObjNpcNHW01 *)arg0)->texlist = (s32) (*(s32 *)&TObjNpcNHW01__texture_handle);
    ((TObjNpcBase *)arg0)->setup_common();
    return arg0;
}

void * TObjNpcNurseBase__create(void *arg0) {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = TObjControl__ct(o, tl_04);
    }
    o2 = __nw__7TObjectFUl(0x3B8);
    if (o2 != NULL) {
        o2 = TObjNpcNurseBase__ct((u8 *)o2, (s32)o, (s32)arg0);
    }
    return o2;
}

}
