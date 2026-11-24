#include "types.h"
#include "pso/object/TObjControl.h"
#include "pso/npc/TObjNpcHFW01.h"
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


const char *TObjNpcHFW01::name = "TObjNpcHFW01";
uaddr TObjNpcHFW01::resource_node;
NJS_TEXLIST *TObjNpcHFW01::texture_handle;

extern "C" {
void release_texture_list(void*);

void *TObjNpcHFW01::create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcHFW01(control, set_data);
}

void TObjNpcHFW01::free_static_resources() {
    if (texture_handle != NULL) {
        release_texture_list(texture_handle);
        TAdSinglePlyChrSelectGC::safe_free((uaddr)texture_handle);
        texture_handle = NULL;
    }
    if ((u32) resource_node != 0U) {
        TLobby::free_nodes_with_id((uaddr)((void*)resource_node));
        resource_node = 0U;
    }
}

void TObjNpcHFW01::load_resources() {
    resource_node = (u32)create_named_object("npc_g01_data.rel");
    texture_handle = load_gvm_texture_file("n_g01_e_body.gvm");
}

}
TObjNpcHFW01::~TObjNpcHFW01() {}


TObjNpcHFW01::TObjNpcHFW01(TObject *parent, void *arg2) : TUnk_804A92A8(parent) {
    *(s32 *)((s8 *)this + 0) = (saddr) name;
    ((TObjNpcHFW01 *)this)->apply_set_data(arg2);
    init_position_vectors();
    *(s32 *)((s8 *)this + 0x34) = (s32) *(*(s32 * *)&resource_node);
    ((TObjNpcHFW01 *)this)->texlist = texture_handle;
    ((TObjNpcBase *)this)->setup_common();
}

