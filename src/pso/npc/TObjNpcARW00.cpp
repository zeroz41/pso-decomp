#include "types.h"
#include "pso/npc/TObjNpcARW00.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/unk/text_800F9B84.h"
#include "pso/npc/TUnk_804A8640.h"
#include "pso/unk/TLobby.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcFemaleBase.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_80148038___vt__12TObjNpcARW00 {
    s32 value;
    u8 remaining[0x174];
};

extern "C" {
s32 play_sound_effect(int, void *, int, int);
extern s32 __vt__12TObjNpcARW00[];
extern s32 TObjNpcARW00__name;
extern u32 TObjNpcARW00__static_model;
extern u32 TObjNpcARW00__gvm_texture_handle;
extern char lbl_8043F4A8[];
extern char lbl_8043F4BC[];
void release_texture_list(void*);
void __dl__7TObjectFPv(void *);

void TObjNpcARW00::free_resources() {
    if ((u32) TObjNpcARW00__gvm_texture_handle != 0U) {
        release_texture_list((void*)TObjNpcARW00__gvm_texture_handle);
        TAdSinglePlyChrSelectGC::safe_free(TObjNpcARW00__gvm_texture_handle);
        TObjNpcARW00__gvm_texture_handle = 0U;
    }
    if ((u32) TObjNpcARW00__static_model != 0U) {
        TLobby::free_nodes_with_id((u32)((void*)TObjNpcARW00__static_model));
        TObjNpcARW00__static_model = 0U;
    }
}

void TObjNpcARW00::load_resources() {
    TObjNpcARW00__static_model = (u32)create_named_object((s32)lbl_8043F4A8);
    TObjNpcARW00__gvm_texture_handle = (u32)load_gvm_texture_file((s32)lbl_8043F4BC);
}

}
TObjNpcARW00::~TObjNpcARW00() {}
extern "C" {

typedef char RecoveredGlobal_80148038___vt__12TObjNpcARW00_size[sizeof(RecoveredGlobal_80148038___vt__12TObjNpcARW00) == 0x178 ? 1 : -1];
u8 *TObjNpcARW00__ct(u8 *arg0, s32 arg1, s32 arg2) {
    ((TUnk_804A8640 *)arg0)->construct_female_base();
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_80148038___vt__12TObjNpcARW00 *)&__vt__12TObjNpcARW00).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TObjNpcARW00__name;
    ((TObjNpcARW00 *)(arg0))->apply_set_data((void *)arg2);
    ((TObjPlayer *)arg0)->init_position_vectors();
    *(s32 *)((s8 *)arg0 + 0x34) = (s32) *(*(s32 * *)&TObjNpcARW00__static_model);
    ((TObjNpcARW00 *)arg0)->texlist = (s32) (*(s32 *)&TObjNpcARW00__gvm_texture_handle);
    ((TObjNpcBase *)arg0)->setup_common();
    return arg0;
}

void TObjNpcARW00::play_voice() {
    s32 arg0 = (s32)this;
    play_sound_effect(0x40004C15, (void *)(arg0 + 0x38), 0, 0);
}

}
