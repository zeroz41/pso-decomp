#include "types.h"
#include "pso/misc/TLanguage_801E4874.h"
#include "pso/unk/text_800F9B84.h"
#include "pso/unk/text_8014B8A4.h"
#include "pso/npc/TObjNpcNFM00.h"
#include "pso/npc/TUnk_804A9F50.h"
#include "pso/npc/TObjNpcNFM01.h"
#include "pso/misc/TLobby.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcLappy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_8014C9D4___vt__12TObjNpcNFM00 {
    s32 value;
    u8 remaining[0x174];
};

extern "C" {
extern s32 __vt__12TObjNpcNFM00[];
extern s32 TObjNpcNFM00__name;
extern s32 *TObjNpcNFM00__shared_named_model_object;
extern s32 TObjNpcNFM00__texture_gvm_handle;
u8 *TObjNpcNFM00__ct(u8 *arg0, s32 arg1, s32 arg2);
extern u32 TObjNpcNFM01__model_object;
extern u32 TObjNpcNFM01__texture_handle;
extern char lbl_8043FD58[];
extern char lbl_8043FD6C[];
void * TObjNpcNFM01__create(void *arg0);
void *__dt__12TObjNpcNFM00Fv(void *arg0, s16 arg1);
void release_texture_list(void*);
void *TObjControl__ct(void *, void *);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

void *__dt__12TObjNpcNFM00Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__12TObjNpcNFM00;
        ((TUnk_804A9F50 *)arg0)->destroy_npc_lappy_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern void *tl_04;

typedef char RecoveredGlobal_8014C9D4___vt__12TObjNpcNFM00_size[sizeof(RecoveredGlobal_8014C9D4___vt__12TObjNpcNFM00) == 0x178 ? 1 : -1];
u8 *TObjNpcNFM00__ct(u8 *player, s32 arg1, s32 arg2) {
    construct_male_npc_base((player));
    *(s32 **)((s8 *)player + 0x18) = &(*(RecoveredGlobal_8014C9D4___vt__12TObjNpcNFM00 *)&__vt__12TObjNpcNFM00).value;
    *(s32 *)((s8 *)player + 0) = (s32) TObjNpcNFM00__name;
    ((TObjNpcNFM00 *)(player))->apply_set_data((void *)arg2);
    ((TObjPlayer *)player)->init_position_vectors();
    *(s32 *)((s8 *)player + 0x34) = (s32) *TObjNpcNFM00__shared_named_model_object;
    ((TObjNpcNFM00 *)player)->texlist = (s32) TObjNpcNFM00__texture_gvm_handle;
    ((TObjNpcBase *)player)->setup_common();
    return player;
}

void * TObjNpcNFM01__create(void *arg0) {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = TObjControl__ct(o, tl_04);
    }
    o2 = __nw__7TObjectFUl(0x3B8);
    if (o2 != NULL) {
        o2 = TObjNpcNFM01__ct((u8 *)o2, (s32)o, (s32)arg0);
    }
    return o2;
}

void TObjNpcNFM01::free_resources() {
    if ((u32) TObjNpcNFM01__texture_handle != 0U) {
        release_texture_list((void*)TObjNpcNFM01__texture_handle);
        TAdSinglePlyChrSelectGC::safe_free(TObjNpcNFM01__texture_handle);
        TObjNpcNFM01__texture_handle = 0U;
    }
    if ((u32) TObjNpcNFM01__model_object != 0U) {
        TLobby::free_nodes_with_id((u32)((void*)TObjNpcNFM01__model_object));
        TObjNpcNFM01__model_object = 0U;
    }
}
void TObjNpcNFM01::load_resources() {
    TObjNpcNFM01__model_object = (u32)create_named_object((s32)lbl_8043FD58);
    TObjNpcNFM01__texture_handle = (u32)load_gvm_texture_file((s32)lbl_8043FD6C);
}

}
