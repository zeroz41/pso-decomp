#include "pso/system/memory.h"
#include "types.h"
#include "pso/render/GinjaTexture.h"
#include "pso/object/TObjControl.h"
#include "pso/npc/TObjNpcHFW01.h"
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

const char *TObjNpcHFW01::name = "TObjNpcHFW01";
void **TObjNpcHFW01::resource_node;
NJS_TEXLIST *TObjNpcHFW01::texture_handle;

void *TObjNpcHFW01::create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcHFW01(control, set_data);
}

void TObjNpcHFW01::free_static_resources() {
    if (texture_handle != NULL) {
        release_texture_list(texture_handle);
        safe_free(texture_handle);
        texture_handle = NULL;
    }
    if (resource_node != NULL) {
        TLobby::free_nodes_with_id(reinterpret_cast<uaddr>(resource_node));
        resource_node = NULL;
    }
}

void TObjNpcHFW01::load_resources() {
    resource_node = static_cast<void **>(create_named_object("npc_g01_data.rel"));
    texture_handle = load_gvm_texture_file("n_g01_e_body.gvm");
}

TObjNpcHFW01::~TObjNpcHFW01() {}

TObjNpcHFW01::TObjNpcHFW01(TObject *parent, void *set_data) : TObjNpcFomarl(parent) {
    this->m_name = name;
    this->apply_set_data(set_data);
    init_position_vectors();
    this->model = *resource_node;
    this->texlist = texture_handle;
    this->setup_common();
}

