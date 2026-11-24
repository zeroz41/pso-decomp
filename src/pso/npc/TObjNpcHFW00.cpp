#include "types.h"
#include "pso/object/TObjControl.h"
#include "pso/npc/TObjNpcHFW00.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/unk/text_800F9B84.h"
#include "pso/npc/TUnk_804A92A8.h"
#include "pso/unk/TLobby.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"

#pragma readonly_strings on


const char *TObjNpcHFW00::name = "TObjNpcHFW00";
uaddr TObjNpcHFW00::shared_resource_obj;
NJS_TEXLIST *TObjNpcHFW00::texture_handle;

extern "C" {
void release_texture_list(void*);

void *TObjNpcHFW00::create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcHFW00(control, set_data);
}

void TObjNpcHFW00::free_resources() {
    if (texture_handle != NULL) {
        release_texture_list(texture_handle);
        TAdSinglePlyChrSelectGC::safe_free((uaddr)texture_handle);
        texture_handle = NULL;
    }
    if ((u32) shared_resource_obj != 0U) {
        TLobby::free_nodes_with_id((uaddr)((void*)shared_resource_obj));
        shared_resource_obj = 0U;
    }
}

void TObjNpcHFW00::load_resources() {
    shared_resource_obj = (u32)create_named_object("npc_g00_data.rel");
    texture_handle = load_gvm_texture_file("n_g00_body.gvm");
}

}
TObjNpcHFW00::~TObjNpcHFW00() {}


TObjNpcHFW00::TObjNpcHFW00(TObject *parent, void *arg2) : TUnk_804A92A8(parent) {
    *(s32 *)((s8 *)this + 0) = (saddr) name;
    ((TObjNpcHFW00 *)this)->apply_set_data(arg2);
    init_position_vectors();
    *(s32 *)((s8 *)this + 0x34) = (s32) *(*(s32 * *)&shared_resource_obj);
    ((TObjNpcHFW00 *)this)->texlist = texture_handle;
    ((TObjNpcBase *)this)->setup_common();
}

