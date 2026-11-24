#include "pso/system/memory.h"
#include "types.h"
#include "pso/render/GinjaTexture.h"
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


const char *TObjNpcHFW00__name = "TObjNpcHFW00";
void **TObjNpcHFW00__shared_resource_obj;
NJS_TEXLIST *TObjNpcHFW00__texture_handle;

extern "C" {

void *TObjNpcHFW00__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcHFW00(control, set_data);
}

void TObjNpcHFW00::free_resources() {
    if (TObjNpcHFW00__texture_handle != NULL) {
        release_texture_list(TObjNpcHFW00__texture_handle);
        safe_free(TObjNpcHFW00__texture_handle);
        TObjNpcHFW00__texture_handle = NULL;
    }
    if (TObjNpcHFW00__shared_resource_obj != NULL) {
        TLobby::free_nodes_with_id(reinterpret_cast<uaddr>(TObjNpcHFW00__shared_resource_obj));
        TObjNpcHFW00__shared_resource_obj = NULL;
    }
}

void TObjNpcHFW00::load_resources() {
    TObjNpcHFW00__shared_resource_obj = static_cast<void **>(create_named_object("npc_g00_data.rel"));
    TObjNpcHFW00__texture_handle = load_gvm_texture_file("n_g00_body.gvm");
}

}
TObjNpcHFW00::~TObjNpcHFW00() {}


TObjNpcHFW00::TObjNpcHFW00(TObject *parent, void *arg2) : TUnk_804A92A8(parent) {
    *(s32 *)((s8 *)this + 0) = (saddr) TObjNpcHFW00__name;
    ((TObjNpcHFW00 *)this)->apply_set_data(arg2);
    init_position_vectors();
    model = *TObjNpcHFW00__shared_resource_obj;
    ((TObjNpcHFW00 *)this)->texlist = TObjNpcHFW00__texture_handle;
    ((TObjNpcBase *)this)->setup_common();
}

