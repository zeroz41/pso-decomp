#include "pso/system/memory.h"
#include "types.h"
#include "pso/npc/TObjNpcNFM01.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/GinjaTexture.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/text_800F9B84.h"

#pragma readonly_strings on

const char *TObjNpcNFM01::name = "TObjNpcNFM01";
void **TObjNpcNFM01::model_object;
NJS_TEXLIST *TObjNpcNFM01::texture_handle;

void *TObjNpcNFM01::create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcNFM01(control, set_data);
}

void TObjNpcNFM01::free_resources() {
    if (texture_handle != NULL) {
        release_texture_list(texture_handle);
        safe_free(texture_handle);
        texture_handle = NULL;
    }
    if (model_object != NULL) {
        TLobby::free_nodes_with_id(reinterpret_cast<uaddr>(model_object));
        model_object = NULL;
    }
}

void TObjNpcNFM01::load_resources() {
    model_object = static_cast<void **>(create_named_object("npc_h01_data.rel"));
    texture_handle = load_gvm_texture_file("n_h01_e_body.gvm");
}

TObjNpcNFM01::~TObjNpcNFM01() {}

TObjNpcNFM01::TObjNpcNFM01(TObject *parent, void *set_data) : TObjNpcMale(parent) {
    this->m_name = name;
    this->apply_set_data(set_data);
    init_position_vectors();
    this->model = *model_object;
    this->texlist = texture_handle;
    this->setup_common();
}
