#include "types.h"
#include "pso/misc/TLanguage_801E4874.h"
#include "pso/unk/text_800F9B84.h"
#include "pso/unk/text_8014AAC4.h"
#include "pso/npc/TObjNpcHFW00.h"
#include "pso/npc/TUnk_804A92A8.h"
#include "pso/npc/TObjNpcHFW01.h"
#include "pso/misc/TLobby.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcFemaleTall.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_8014AE4C___vt__12TObjNpcHFW00 {
    s32 value;
    u8 remaining[0x174];
};

extern "C" {
extern s32 __vt__12TObjNpcHFW00[];
extern s32 TObjNpcHFW00__name;
extern s32 *TObjNpcHFW00__shared_resource_obj;
extern s32 TObjNpcHFW00__texture_handle;
extern u32 TObjNpcHFW01__resource_node;
extern u32 TObjNpcHFW01__texture_handle;
extern char lbl_8043FA70[];
extern char TObjNpcHFW01__texture_filename[];
void release_texture_list(void*);
void *TObjControl__ct(void *, void *);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

void *__dt__12TObjNpcHFW00Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__12TObjNpcHFW00;
        ((TUnk_804A92A8 *)arg0)->destroy(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern void *tl_04;

typedef char RecoveredGlobal_8014AE4C___vt__12TObjNpcHFW00_size[sizeof(RecoveredGlobal_8014AE4C___vt__12TObjNpcHFW00) == 0x178 ? 1 : -1];
u8 *TObjNpcHFW00__ct(u8 *player, s32 arg1, s32 arg2) {
    fn_8014AAC4((player));
    *(s32 **)((s8 *)player + 0x18) = &(*(RecoveredGlobal_8014AE4C___vt__12TObjNpcHFW00 *)&__vt__12TObjNpcHFW00).value;
    *(s32 *)((s8 *)player + 0) = (s32) TObjNpcHFW00__name;
    ((TObjNpcHFW00 *)(player))->apply_set_data((void *)arg2);
    ((TObjPlayer *)player)->init_position_vectors();
    *(s32 *)((s8 *)player + 0x34) = (s32) *TObjNpcHFW00__shared_resource_obj;
    ((TObjNpcHFW00 *)player)->texlist = (s32) TObjNpcHFW00__texture_handle;
    ((TObjNpcBase *)player)->setup_common();
    return player;
}

void * TObjNpcHFW01__create(void *arg0) {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = TObjControl__ct(o, tl_04);
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
    TObjNpcHFW01__resource_node = (u32)create_named_object((s32)lbl_8043FA70);
    TObjNpcHFW01__texture_handle = (u32)load_gvm_texture_file((s32)TObjNpcHFW01__texture_filename);
}

}
