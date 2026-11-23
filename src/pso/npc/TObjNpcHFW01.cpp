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


const char *TObjNpcHFW01__name = "TObjNpcHFW01";
uaddr TObjNpcHFW01__resource_node;
uaddr TObjNpcHFW01__texture_handle;

extern "C" {
void release_texture_list(void*);

void *TObjNpcHFW01__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcHFW01(control, set_data);
}

void TObjNpcHFW01::free_static_resources() {
    if ((u32) TObjNpcHFW01__texture_handle != 0U) {
        release_texture_list((void*)TObjNpcHFW01__texture_handle);
        TAdSinglePlyChrSelectGC::safe_free(TObjNpcHFW01__texture_handle);
        TObjNpcHFW01__texture_handle = 0U;
    }
    if ((u32) TObjNpcHFW01__resource_node != 0U) {
        TLobby::free_nodes_with_id((uaddr)((void*)TObjNpcHFW01__resource_node));
        TObjNpcHFW01__resource_node = 0U;
    }
}

void TObjNpcHFW01::load_resources() {
    TObjNpcHFW01__resource_node = (u32)create_named_object((saddr)"npc_g01_data.rel");
    TObjNpcHFW01__texture_handle = (uaddr)load_gvm_texture_file("n_g01_e_body.gvm");
}

}
TObjNpcHFW01::~TObjNpcHFW01() {}


TObjNpcHFW01::TObjNpcHFW01(TObject *parent, void *arg2) : TUnk_804A92A8(parent) {
    *(s32 *)((s8 *)this + 0) = (saddr) TObjNpcHFW01__name;
    ((TObjNpcHFW01 *)this)->apply_set_data(arg2);
    init_position_vectors();
    *(s32 *)((s8 *)this + 0x34) = (s32) *(*(s32 * *)&TObjNpcHFW01__resource_node);
    ((TObjNpcHFW01 *)this)->texlist = (s32) (*(s32 *)&TObjNpcHFW01__texture_handle);
    ((TObjNpcBase *)this)->setup_common();
}

