#include "pso/system/memory.h"
#include "types.h"
#include "pso/npc/TObjNpcNFW01.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/GinjaTexture.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/text_800F9B84.h"

#pragma readonly_strings on

const char *TObjNpcNFW01::name = "TObjNpcNFW01";
void **TObjNpcNFW01::shared_object_resource;
NJS_TEXLIST *TObjNpcNFW01::texture_gvm;

void *TObjNpcNFW01::create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcNFW01(control, set_data);
}

void TObjNpcNFW01::free_resources() {
    if (texture_gvm != NULL) {
        release_texture_list(texture_gvm);
        safe_free(texture_gvm);
        texture_gvm = NULL;
    }
    if (shared_object_resource != NULL) {
        TLobby::free_nodes_with_id(reinterpret_cast<uaddr>(shared_object_resource));
        shared_object_resource = NULL;
    }
}

void TObjNpcNFW01::load_resources() {
    shared_object_resource = static_cast<void **>(create_named_object("npc_i01_data.rel"));
    texture_gvm = load_gvm_texture_file("n_i01_e_body.gvm");
}

TObjNpcNFW01::~TObjNpcNFW01() {}

TObjNpcNFW01::TObjNpcNFW01(TObject *parent, void *set_data) : TObjNpcFemale(parent) {
    this->m_name = name;
    this->apply_set_data(set_data);
    init_position_vectors();
    this->model = *shared_object_resource;
    this->texlist = texture_gvm;
    this->setup_common();
}
