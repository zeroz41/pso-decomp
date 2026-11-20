#include "types.h"
#include "pso/npc/TObjNpcARM00.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/npc/TObjNpcARW00.h"
#include "pso/unk/text_800F9B84.h"
#include "pso/npc/TUnk_804A9F50.h"

#include "pso/unk/TLobby.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcLappy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/task/TObject.h"

#pragma readonly_strings on


const char *TObjNpcARM00__name = "TObjNpcARM00";
uaddr TObjNpcARM00__model_resource;
uaddr TObjNpcARM00__texture_list;

extern "C" {
extern s32 __vt__12TObjNpcARM00[];
s32 play_sound_effect(s32, s32, s32, s32);
void release_texture_list(void*);
void *__ct__11TObjControlFP7TObject(void *, void *);

void TObjNpcARM00::free_resources() {
    if ((u32) TObjNpcARM00__texture_list != 0U) {
        release_texture_list((void*)TObjNpcARM00__texture_list);
        TAdSinglePlyChrSelectGC::safe_free(TObjNpcARM00__texture_list);
        TObjNpcARM00__texture_list = 0U;
    }
    if ((u32) TObjNpcARM00__model_resource != 0U) {
        TLobby::free_nodes_with_id((uaddr)((void*)TObjNpcARM00__model_resource));
        TObjNpcARM00__model_resource = 0U;
    }
}

void TObjNpcARM00::load_resources() {
    TObjNpcARM00__model_resource = (u32)create_named_object((saddr)"npc_e00_data.rel");
    TObjNpcARM00__texture_list = (uaddr)load_gvm_texture_file((saddr)"n_e00_w_body.gvm");
}

}
TObjNpcARM00::~TObjNpcARM00() {}


u8 *TObjNpcARM00__ct(u8 *player, s32 arg1, saddr arg2) {
    ((TUnk_804A9F50 *)player)->construct_male_npc_base();
    *(s32 **)((s8 *)player + 0x18) = __vt__12TObjNpcARM00;
    *(s32 *)((s8 *)player + 0) = (saddr) TObjNpcARM00__name;
    ((TObjNpcARM00 *)(player))->apply_set_data((void *)arg2);
    ((TObjPlayer *)player)->init_position_vectors();
    *(s32 *)((s8 *)player + 0x34) = (s32) *(*(s32 * *)&TObjNpcARM00__model_resource);
    ((TObjNpcARM00 *)player)->texlist = (s32) (*(s32 *)&TObjNpcARM00__texture_list);
    ((TObjNpcBase *)player)->setup_common();
    return player;
}

void TObjNpcARM00::play_voice() {
    saddr arg0 = (saddr)this;
    play_sound_effect(0x40003B08, arg0 + 0x38, 0, 0);
}

extern void *tl_04;

void * TObjNpcARW00__create(void *arg0) {
    void *o;
    void *o2;
    o = TObject::operator new(0x20);
    if (o != NULL) {
        o = __ct__11TObjControlFP7TObject(o, tl_04);
    }
    o2 = TObject::operator new(0x3B8);
    if (o2 != NULL) {
        o2 = TObjNpcARW00__ct((u8 *)o2, (saddr)o, (saddr)arg0);
    }
    return o2;
}

