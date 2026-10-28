#include "types.h"
#include "pso/misc/TLanguage_801E4874.h"
#include "pso/npc/TObjNpcARM00.h"
#include "pso/unk/text_800F9B84.h"
#include "pso/unk/text_8014B8A4.h"
#include "pso/npc/TUnk_804A9F50.h"
#include "pso/npc/TObjNpcAHM01.h"
#include "pso/misc/TLobby.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcLappy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_80147C18___vt__12TObjNpcAHM01 {
    s32 value;
    u8 remaining[0x174];
};

extern "C" {
s32 play_sound_effect(int, void *, int, int);
extern s32 __vt__12TObjNpcAHM01[];
extern s32 TObjNpcAHM01__name;
extern u32 TObjNpcAHM01__shared_object;
extern u32 TObjNpcAHM01__texture_handle;
extern char lbl_8043F438[];
extern char lbl_8043F44C[];
void release_texture_list(void*);
void *TObjControl__ct(void *, void *);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

void TObjNpcAHM01::free_resources() {
    if ((u32) TObjNpcAHM01__texture_handle != 0U) {
        release_texture_list((void*)TObjNpcAHM01__texture_handle);
        TAdSinglePlyChrSelectGC::safe_free(TObjNpcAHM01__texture_handle);
        TObjNpcAHM01__texture_handle = 0U;
    }
    if ((u32) TObjNpcAHM01__shared_object != 0U) {
        TLobby::free_nodes_with_id((u32)((void*)TObjNpcAHM01__shared_object));
        TObjNpcAHM01__shared_object = 0U;
    }
}

void TObjNpcAHM01::load_resources() {
    TObjNpcAHM01__shared_object = (u32)create_named_object((s32)lbl_8043F438);
    TObjNpcAHM01__texture_handle = (u32)load_gvm_texture_file((s32)lbl_8043F44C);
}

void *__dt__12TObjNpcAHM01Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__12TObjNpcAHM01;
        ((TUnk_804A9F50 *)arg0)->destroy_npc_lappy_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

typedef char RecoveredGlobal_80147C18___vt__12TObjNpcAHM01_size[sizeof(RecoveredGlobal_80147C18___vt__12TObjNpcAHM01) == 0x178 ? 1 : -1];
u8 *TObjNpcAHM01__ct(u8 *player, s32 arg1, s32 arg2) {
    construct_male_npc_base((player));
    *(s32 **)((s8 *)player + 0x18) = &(*(RecoveredGlobal_80147C18___vt__12TObjNpcAHM01 *)&__vt__12TObjNpcAHM01).value;
    *(s32 *)((s8 *)player + 0) = (s32) TObjNpcAHM01__name;
    ((TObjNpcAHM01 *)(player))->apply_set_data((void *)arg2);
    ((TObjPlayer *)player)->init_position_vectors();
    *(s32 *)((s8 *)player + 0x34) = (s32) *(*(s32 * *)&TObjNpcAHM01__shared_object);
    ((TObjNpcAHM01 *)player)->texlist = (s32) (*(s32 *)&TObjNpcAHM01__texture_handle);
    ((TObjNpcBase *)player)->setup_common();
    return player;
}

void TObjNpcAHM01::play_voice() {
    s32 arg0 = (s32)this;
    play_sound_effect(0x40004C15, (void *)(arg0 + 0x38), 0, 0);
}

s32 TObjNpcBase::is_target_in_attack_range() { return 0; }

extern void *tl_04;

void * TObjNpcARM00__create(void *arg0) {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = TObjControl__ct(o, tl_04);
    }
    o2 = __nw__7TObjectFUl(0x3B8);
    if (o2 != NULL) {
        o2 = TObjNpcARM00__ct((u8 *)o2, (s32)o, (s32)arg0);
    }
    return o2;
}

}
