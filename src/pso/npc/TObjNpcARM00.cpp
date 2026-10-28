#include "types.h"
#include "pso/misc/TLanguage_801E4874.h"
#include "pso/npc/TObjNpcARW00.h"
#include "pso/unk/text_800F9B84.h"
#include "pso/unk/text_8014B8A4.h"
#include "pso/npc/TUnk_804A9F50.h"
#include "pso/npc/TObjNpcARM00.h"
#include "pso/misc/TLobby.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcLappy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_80147E2C___vt__12TObjNpcARM00 {
    s32 value;
    u8 remaining[0x174];
};

extern "C" {
extern s32 __vt__12TObjNpcARM00[];
extern s32 TObjNpcARM00__name;
extern u32 TObjNpcARM00__model_resource;
extern u32 TObjNpcARM00__texture_list;
extern char lbl_8043F470[];
extern char lbl_8043F484[];
s32 play_sound_effect(s32, s32, s32, s32);
void release_texture_list(void*);
void *TObjControl__ct(void *, void *);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

void TObjNpcARM00::free_resources() {
    if ((u32) TObjNpcARM00__texture_list != 0U) {
        release_texture_list((void*)TObjNpcARM00__texture_list);
        TAdSinglePlyChrSelectGC::safe_free(TObjNpcARM00__texture_list);
        TObjNpcARM00__texture_list = 0U;
    }
    if ((u32) TObjNpcARM00__model_resource != 0U) {
        TLobby::free_nodes_with_id((u32)((void*)TObjNpcARM00__model_resource));
        TObjNpcARM00__model_resource = 0U;
    }
}

void TObjNpcARM00::load_resources() {
    TObjNpcARM00__model_resource = (u32)create_named_object((s32)lbl_8043F470);
    TObjNpcARM00__texture_list = (u32)load_gvm_texture_file((s32)lbl_8043F484);
}

void *__dt__12TObjNpcARM00Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__12TObjNpcARM00;
        ((TUnk_804A9F50 *)arg0)->destroy_npc_lappy_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

typedef char RecoveredGlobal_80147E2C___vt__12TObjNpcARM00_size[sizeof(RecoveredGlobal_80147E2C___vt__12TObjNpcARM00) == 0x178 ? 1 : -1];
u8 *TObjNpcARM00__ct(u8 *player, s32 arg1, s32 arg2) {
    construct_male_npc_base((player));
    *(s32 **)((s8 *)player + 0x18) = &(*(RecoveredGlobal_80147E2C___vt__12TObjNpcARM00 *)&__vt__12TObjNpcARM00).value;
    *(s32 *)((s8 *)player + 0) = (s32) TObjNpcARM00__name;
    ((TObjNpcARM00 *)(player))->apply_set_data((void *)arg2);
    ((TObjPlayer *)player)->init_position_vectors();
    *(s32 *)((s8 *)player + 0x34) = (s32) *(*(s32 * *)&TObjNpcARM00__model_resource);
    ((TObjNpcARM00 *)player)->texlist = (s32) (*(s32 *)&TObjNpcARM00__texture_list);
    ((TObjNpcBase *)player)->setup_common();
    return player;
}

void TObjNpcARM00::play_voice() {
    s32 arg0 = (s32)this;
    play_sound_effect(0x40003B08, arg0 + 0x38, 0, 0);
}

extern void *tl_04;

void * TObjNpcARW00__create(void *arg0) {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = TObjControl__ct(o, tl_04);
    }
    o2 = __nw__7TObjectFUl(0x3B8);
    if (o2 != NULL) {
        o2 = TObjNpcARW00__ct((u8 *)o2, (s32)o, (s32)arg0);
    }
    return o2;
}

}
