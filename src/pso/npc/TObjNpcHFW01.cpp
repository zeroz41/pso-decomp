#include "pso/system/memory.h"
#include "types.h"
#include "pso/render/GinjaTexture.h"
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
void **TObjNpcHFW01__resource_node;
NJS_TEXLIST *TObjNpcHFW01__texture_handle;

extern "C" {

void *TObjNpcHFW01__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcHFW01(control, set_data);
}

void TObjNpcHFW01::free_static_resources() {
    if (TObjNpcHFW01__texture_handle != NULL) {
        release_texture_list(TObjNpcHFW01__texture_handle);
        safe_free(TObjNpcHFW01__texture_handle);
        TObjNpcHFW01__texture_handle = NULL;
    }
    if (TObjNpcHFW01__resource_node != NULL) {
        TLobby::free_nodes_with_id(reinterpret_cast<uaddr>(TObjNpcHFW01__resource_node));
        TObjNpcHFW01__resource_node = NULL;
    }
}

void TObjNpcHFW01::load_resources() {
    TObjNpcHFW01__resource_node = static_cast<void **>(create_named_object("npc_g01_data.rel"));
    TObjNpcHFW01__texture_handle = load_gvm_texture_file("n_g01_e_body.gvm");
}

}
TObjNpcHFW01::~TObjNpcHFW01() {}


TObjNpcHFW01::TObjNpcHFW01(TObject *parent, void *arg2) : TUnk_804A92A8(parent) {
    *(s32 *)((s8 *)this + 0) = (saddr) TObjNpcHFW01__name;
    ((TObjNpcHFW01 *)this)->apply_set_data(arg2);
    init_position_vectors();
    model = *TObjNpcHFW01__resource_node;
    ((TObjNpcHFW01 *)this)->texlist = TObjNpcHFW01__texture_handle;
    ((TObjNpcBase *)this)->setup_common();
}

