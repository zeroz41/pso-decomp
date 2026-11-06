#include "types.h"
#include "pso/npc/TObjNpcHFW01.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/unk/text_800F9B84.h"
#include "pso/npc/TUnk_804A92A8.h"
#include "pso/unk/TLobby.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

#pragma readonly_strings on

extern "C" {
const char *TObjNpcHFW01__name = "TObjNpcHFW01";
u32 TObjNpcHFW01__resource_node;
u32 TObjNpcHFW01__texture_handle;
}

struct RecoveredGlobal_8014B020___vt__12TObjNpcHFW01 {
    s32 value;
    u8 remaining[0x174];
};

extern void *tl_04;
extern "C" {
extern s32 __vt__12TObjNpcHFW01[];
void release_texture_list(void*);
void *__ct__11TObjControlFP7TObject(void *, void *);
void *__nw__7TObjectFUl(int);

void * TObjNpcHFW01__create(void *arg0) {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = __ct__11TObjControlFP7TObject(o, tl_04);
    }
    o2 = __nw__7TObjectFUl(0x3B8);
    if (o2 != NULL) {
        o2 = TObjNpcHFW01__ct((u8 *)o2, (s32)o, (s32)arg0);
    }
    return o2;
}

void TObjNpcHFW01::free_static_resources() {
    if ((u32) TObjNpcHFW01__texture_handle != 0U) {
        release_texture_list((void*)TObjNpcHFW01__texture_handle);
        TAdSinglePlyChrSelectGC::safe_free(TObjNpcHFW01__texture_handle);
        TObjNpcHFW01__texture_handle = 0U;
    }
    if ((u32) TObjNpcHFW01__resource_node != 0U) {
        TLobby::free_nodes_with_id((u32)((void*)TObjNpcHFW01__resource_node));
        TObjNpcHFW01__resource_node = 0U;
    }
}

void TObjNpcHFW01::load_resources() {
    TObjNpcHFW01__resource_node = (u32)create_named_object((s32)"npc_g01_data.rel");
    TObjNpcHFW01__texture_handle = (u32)load_gvm_texture_file((s32)"n_g01_e_body.gvm");
}

}
TObjNpcHFW01::~TObjNpcHFW01() {}
extern "C" {

typedef char RecoveredGlobal_8014B020___vt__12TObjNpcHFW01_size[sizeof(RecoveredGlobal_8014B020___vt__12TObjNpcHFW01) == 0x178 ? 1 : -1];
u8 *TObjNpcHFW01__ct(u8 *player, s32 arg1, s32 arg2) {
    ((TUnk_804A92A8 *)player)->fn_8014AAC4();
    *(s32 **)((s8 *)player + 0x18) = &(*(RecoveredGlobal_8014B020___vt__12TObjNpcHFW01 *)&__vt__12TObjNpcHFW01).value;
    *(s32 *)((s8 *)player + 0) = (s32) TObjNpcHFW01__name;
    ((TObjNpcHFW01 *)(player))->apply_set_data((void *)arg2);
    ((TObjPlayer *)player)->init_position_vectors();
    *(s32 *)((s8 *)player + 0x34) = (s32) *(*(s32 * *)&TObjNpcHFW01__resource_node);
    ((TObjNpcHFW01 *)player)->texlist = (s32) (*(s32 *)&TObjNpcHFW01__texture_handle);
    ((TObjNpcBase *)player)->setup_common();
    return player;
}

}
