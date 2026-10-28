#include "types.h"
#include "pso/misc/TLanguage_801E4874.h"
#include "pso/npc/TObjNpcHRM01.h"
#include "pso/unk/text_800F9B84.h"
#include "pso/unk/text_8014B8A4.h"
#include "pso/npc/TUnk_804A9F50.h"
#include "pso/npc/TObjNpcHRM00.h"
#include "pso/misc/TLobby.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcLappy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_8014B3C8___vt__12TObjNpcHRM00 {
    s32 value;
    u8 remaining[0x174];
};

extern "C" {
extern s32 __vt__12TObjNpcHRM00[];
extern s32 TObjNpcHRM00__name;
extern u32 TObjNpcHRM00__named_object_resource;
extern u32 TObjNpcHRM00__body_texture_gvm;
extern char TObjNpcHRM00__data_filename[];
extern char TObjNpcHRM00__body_texture_filename[];
void release_texture_list(void*);
void *TObjControl__ct(void *, void *);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

void TObjNpcHRM00::destroy_resources() {
    if ((u32) TObjNpcHRM00__body_texture_gvm != 0U) {
        release_texture_list((void*)TObjNpcHRM00__body_texture_gvm);
        TAdSinglePlyChrSelectGC::safe_free(TObjNpcHRM00__body_texture_gvm);
        TObjNpcHRM00__body_texture_gvm = 0U;
    }
    if ((u32) TObjNpcHRM00__named_object_resource != 0U) {
        TLobby::free_nodes_with_id((u32)((void*)TObjNpcHRM00__named_object_resource));
        TObjNpcHRM00__named_object_resource = 0U;
    }
}

void TObjNpcHRM00::load_resources() {
    TObjNpcHRM00__named_object_resource = (u32)create_named_object((s32)TObjNpcHRM00__data_filename);
    TObjNpcHRM00__body_texture_gvm = (u32)load_gvm_texture_file((s32)TObjNpcHRM00__body_texture_filename);
}

void *__dt__12TObjNpcHRM00Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__12TObjNpcHRM00;
        ((TUnk_804A9F50 *)arg0)->destroy_npc_lappy_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern void *tl_04;

typedef char RecoveredGlobal_8014B3C8___vt__12TObjNpcHRM00_size[sizeof(RecoveredGlobal_8014B3C8___vt__12TObjNpcHRM00) == 0x178 ? 1 : -1];
u8 *TObjNpcHRM00__ct(u8 *player, s32 arg1, s32 arg2) {
    construct_male_npc_base((player));
    *(s32 **)((s8 *)player + 0x18) = &(*(RecoveredGlobal_8014B3C8___vt__12TObjNpcHRM00 *)&__vt__12TObjNpcHRM00).value;
    *(s32 *)((s8 *)player + 0) = (s32) TObjNpcHRM00__name;
    ((TObjNpcHRM00 *)(player))->apply_set_data((void *)arg2);
    ((TObjPlayer *)player)->init_position_vectors();
    *(s32 *)((s8 *)player + 0x34) = (s32) *(*(s32 * *)&TObjNpcHRM00__named_object_resource);
    ((TObjNpcHRM00 *)player)->texlist = (s32) (*(s32 *)&TObjNpcHRM00__body_texture_gvm);
    ((TObjNpcBase *)player)->setup_common();
    return player;
}

void * TObjNpcHRM01__create(void *arg0) {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = TObjControl__ct(o, tl_04);
    }
    o2 = __nw__7TObjectFUl(0x3B8);
    if (o2 != NULL) {
        o2 = TObjNpcHRM01__ct((u8 *)o2, (s32)o, (s32)arg0);
    }
    return o2;
}

}
