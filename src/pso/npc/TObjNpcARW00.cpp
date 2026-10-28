#include "types.h"
#include "pso/misc/TLanguage_801E4874.h"
#include "pso/unk/text_800F9B84.h"
#include "pso/npc/TUnk_804A8640.h"
#include "pso/npc/TObjNpcARW00.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/misc/TLobby.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcFemaleBase.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_80148038___vt__12TObjNpcARW00 {
    s32 value;
    u8 remaining[0x174];
};

struct Npc_801480FC {
    u8 pad0[0x60];
    s32 f60;
    u8 pad64[0x358 - 0x64];
    f32 f358;
    f32 f35C;
    f32 f360;
    f32 f364;
    u8 pad368[0x384 - 0x368];
    s32 f384;
    u8 pad388[0x38C - 0x388];
    s32 f38C;
    u8 pad390[0x3A0 - 0x390];
    s32 f3A0;
    s32 f3A4;
    s32 f3A8;
    s32 f3AC;
};

extern "C" {
s32 play_sound_effect(int, void *, int, int);
extern s32 __vt__12TObjNpcARW00[];
extern s32 TObjNpcARW00__name;
extern u32 TObjNpcARW00__static_model;
extern u32 TObjNpcARW00__gvm_texture_handle;
extern char lbl_8043F4A8[];
extern char lbl_8043F4BC[];
void debug_printf_at(s32, const char *, ...);
extern char lbl_8043F4DC[];
extern char lbl_8043F4F8[];
extern char lbl_8043F514[];
extern char lbl_8043F52C[];
extern const f32 lbl_805DB1B8;
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

void *__dt__12TObjNpcARW00Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__12TObjNpcARW00;
        ((TUnk_804A8640 *)arg0)->destroy_npc_female_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

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

void TObjNpcBase::vfunc_92() {  }
void TObjNpcBase::vfunc_91() {  }
void TObjNpcBase::draw_debug_info() {
    Npc_801480FC *o = (Npc_801480FC *)this;
    o->f384 = o->f60;
    o->f38C = 0;
    if (lbl_805DB1B8 <= o->f358) {
        o->f38C = 1;
        o->f3A0 = o->f358 - lbl_805DB1B8;
    } else {
        o->f3A0 = o->f358;
    }
    if (lbl_805DB1B8 <= o->f35C) {
        o->f38C = 1;
        o->f3A4 = o->f35C - lbl_805DB1B8;
    } else {
        o->f3A4 = o->f35C;
    }
    o->f3A8 = o->f364;
    o->f3AC = o->f360;
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x1A001D, lbl_8043F4DC, o->f358);
    debug_printf_at(0x1A001E, lbl_8043F4F8, o->f35C);
    debug_printf_at(0x1A001F, lbl_8043F514, o->f3AC);
    debug_printf_at(0x1A0020, lbl_8043F52C, o->f3A8);
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}

}
