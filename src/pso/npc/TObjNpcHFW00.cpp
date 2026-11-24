#include "pso/system/memory.h"
#include "types.h"
#include "pso/render/GinjaTexture.h"
#include "pso/object/TObjControl.h"
#include "pso/npc/TObjNpcHFW00.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/unk/text_800F9B84.h"
#include "pso/npc/TObjNpcFomarl.h"
#include "pso/unk/TLobby.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/render/GinjaTexture.h"

#pragma readonly_strings on

const char *TObjNpcHFW00::name = "TObjNpcHFW00";
void **TObjNpcHFW00::shared_resource_obj;
NJS_TEXLIST *TObjNpcHFW00::texture_handle;

void *TObjNpcHFW00::create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcHFW00(control, set_data);
}

void TObjNpcHFW00::free_resources() {
    if (texture_handle != NULL) {
        release_texture_list(texture_handle);
        safe_free(texture_handle);
        texture_handle = NULL;
    }
    if (shared_resource_obj != NULL) {
        TLobby::free_nodes_with_id(reinterpret_cast<uaddr>(shared_resource_obj));
        shared_resource_obj = NULL;
    }
}

void TObjNpcHFW00::load_resources() {
    shared_resource_obj = static_cast<void **>(create_named_object("npc_g00_data.rel"));
    texture_handle = load_gvm_texture_file("n_g00_body.gvm");
}

TObjNpcHFW00::~TObjNpcHFW00() {}

TObjNpcHFW00::TObjNpcHFW00(TObject *parent, void *set_data) : TObjNpcFomarl(parent) {
    this->m_name = name;
    this->apply_set_data(set_data);
    init_position_vectors();
    this->model = *shared_resource_obj;
    this->texlist = texture_handle;
    this->setup_common();
}

