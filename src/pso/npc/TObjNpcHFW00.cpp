#include "types.h"
#include "pso/npc/TObjNpcHFW00.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/unk/text_800F9B84.h"
#include "pso/npc/TUnk_804A92A8.h"
#include "pso/unk/TLobby.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/task/TObject.h"

#pragma readonly_strings on


const char *TObjNpcHFW00__name = "TObjNpcHFW00";
uaddr TObjNpcHFW00__shared_resource_obj;
uaddr TObjNpcHFW00__texture_handle;

extern void *tl_04;
extern "C" {
extern s32 __vt__12TObjNpcHFW00[];
void release_texture_list(void*);
void *__ct__11TObjControlFP7TObject(void *, void *);

void * TObjNpcHFW00__create(void *arg0) {
    void *o;
    void *o2;
    o = TObject::operator new(0x20);
    if (o != NULL) {
        o = __ct__11TObjControlFP7TObject(o, tl_04);
    }
    o2 = TObject::operator new(0x3B8);
    if (o2 != NULL) {
        o2 = TObjNpcHFW00__ct((u8 *)o2, (saddr)o, (saddr)arg0);
    }
    return o2;
}

void TObjNpcHFW00::free_resources() {
    if ((u32) TObjNpcHFW00__texture_handle != 0U) {
        release_texture_list((void*)TObjNpcHFW00__texture_handle);
        TAdSinglePlyChrSelectGC::safe_free(TObjNpcHFW00__texture_handle);
        TObjNpcHFW00__texture_handle = 0U;
    }
    if ((u32) TObjNpcHFW00__shared_resource_obj != 0U) {
        TLobby::free_nodes_with_id((uaddr)((void*)TObjNpcHFW00__shared_resource_obj));
        TObjNpcHFW00__shared_resource_obj = 0U;
    }
}

void TObjNpcHFW00::load_resources() {
    TObjNpcHFW00__shared_resource_obj = (u32)create_named_object((saddr)"npc_g00_data.rel");
    TObjNpcHFW00__texture_handle = (uaddr)load_gvm_texture_file((saddr)"n_g00_body.gvm");
}

}
TObjNpcHFW00::~TObjNpcHFW00() {}


u8 *TObjNpcHFW00__ct(u8 *player, s32 arg1, saddr arg2) {
    ((TUnk_804A92A8 *)player)->fn_8014AAC4();
    *(s32 **)((s8 *)player + 0x18) = __vt__12TObjNpcHFW00;
    *(s32 *)((s8 *)player + 0) = (saddr) TObjNpcHFW00__name;
    ((TObjNpcHFW00 *)(player))->apply_set_data((void *)arg2);
    ((TObjPlayer *)player)->init_position_vectors();
    *(s32 *)((s8 *)player + 0x34) = (s32) *(*(s32 * *)&TObjNpcHFW00__shared_resource_obj);
    ((TObjNpcHFW00 *)player)->texlist = (s32) (*(s32 *)&TObjNpcHFW00__texture_handle);
    ((TObjNpcBase *)player)->setup_common();
    return player;
}

