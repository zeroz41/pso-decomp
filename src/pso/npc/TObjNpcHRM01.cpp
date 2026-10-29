#include "types.h"
#include "pso/misc/TLanguage_801E4874.h"
#include "pso/unk/text_800F9B84.h"
#include "pso/unk/text_8014B8A4.h"
#include "pso/npc/TUnk_804A9F50.h"
#include "pso/npc/TObjNpcHRM01.h"
#include "pso/misc/TLobby.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcLappy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

#pragma readonly_strings on

extern "C" {
const char *TObjNpcHRM01__name = "TObjNpcHRM01";
u32 TObjNpcHRM01__shared_object_resource;
u32 TObjNpcHRM01__body_texture_gvm_handle;
}

struct RecoveredGlobal_8014B59C___vt__12TObjNpcHRM01 {
    s32 value;
    u8 remaining[0x174];
};

extern "C" {
extern s32 __vt__12TObjNpcHRM01[];
void release_texture_list(void*);
void *__ct__11TObjControlFP7TObject(void *, void *);
u8 *TObjNpcLappy__ct(u8 *self, void *parent, s32 arg2);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

void TObjNpcHRM01::free_shared_objects() {
    if ((u32) TObjNpcHRM01__body_texture_gvm_handle != 0U) {
        release_texture_list((void*)TObjNpcHRM01__body_texture_gvm_handle);
        TAdSinglePlyChrSelectGC::safe_free(TObjNpcHRM01__body_texture_gvm_handle);
        TObjNpcHRM01__body_texture_gvm_handle = 0U;
    }
    if ((u32) TObjNpcHRM01__shared_object_resource != 0U) {
        TLobby::free_nodes_with_id((u32)((void*)TObjNpcHRM01__shared_object_resource));
        TObjNpcHRM01__shared_object_resource = 0U;
    }
}

void TObjNpcHRM01::load_resources() {
    TObjNpcHRM01__shared_object_resource = (u32)create_named_object((s32)"npc_d01_data.rel");
    TObjNpcHRM01__body_texture_gvm_handle = (u32)load_gvm_texture_file((s32)"n_d01_e_body.gvm");
}

void *__dt__12TObjNpcHRM01Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__12TObjNpcHRM01;
        ((TUnk_804A9F50 *)arg0)->destroy_npc_lappy_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

typedef char RecoveredGlobal_8014B59C___vt__12TObjNpcHRM01_size[sizeof(RecoveredGlobal_8014B59C___vt__12TObjNpcHRM01) == 0x178 ? 1 : -1];
u8 *TObjNpcHRM01__ct(u8 *player, s32 arg1, s32 arg2) {
    construct_male_npc_base((player));
    *(s32 **)((s8 *)player + 0x18) = &(*(RecoveredGlobal_8014B59C___vt__12TObjNpcHRM01 *)&__vt__12TObjNpcHRM01).value;
    *(s32 *)((s8 *)player + 0) = (s32) TObjNpcHRM01__name;
    ((TObjNpcHRM01 *)(player))->apply_set_data((void *)arg2);
    ((TObjPlayer *)player)->init_position_vectors();
    *(s32 *)((s8 *)player + 0x34) = (s32) *(*(s32 * *)&TObjNpcHRM01__shared_object_resource);
    ((TObjNpcHRM01 *)player)->texlist = (s32) (*(s32 *)&TObjNpcHRM01__body_texture_gvm_handle);
    ((TObjNpcBase *)player)->setup_common();
    return player;
}

void TObjNpcLappy::vfunc_88() {
    if ((s16) this->mode != 2) {
        this->requested_action = 0;
        return;
    }
    this->requested_action = 1;
}

extern void *tl_04;

void * TObjNpcLappy__create(void *arg0) {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = __ct__11TObjControlFP7TObject(o, tl_04);
    }
    o2 = __nw__7TObjectFUl(0x3B8);
    if (o2 != NULL) {
        o2 = TObjNpcLappy__ct((u8 *)o2, o, (s32)arg0);
    }
    return o2;
}

}
