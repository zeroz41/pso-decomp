#include "types.h"
#include "pso/npc/TObjNpcNFW00.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/GinjaTexture.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/text_800F9B84.h"

#pragma readonly_strings on

const char *TObjNpcNFW00__name = "TObjNpcNFW00";
uaddr TObjNpcNFW00__named_object_resource;
uaddr TObjNpcNFW00__texture_gvm_handle;

void *TObjNpcNFW00__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcNFW00(control, set_data);
}

void TObjNpcNFW00::free_resources() {
    if (TObjNpcNFW00__texture_gvm_handle != 0) {
        release_texture_list((GinjaTextureList *)TObjNpcNFW00__texture_gvm_handle);
        TAdSinglePlyChrSelectGC::safe_free(TObjNpcNFW00__texture_gvm_handle);
        TObjNpcNFW00__texture_gvm_handle = 0;
    }
    if (TObjNpcNFW00__named_object_resource != 0) {
        TLobby::free_nodes_with_id(TObjNpcNFW00__named_object_resource);
        TObjNpcNFW00__named_object_resource = 0;
    }
}

void TObjNpcNFW00::load_assets() {
    TObjNpcNFW00__named_object_resource = create_named_object((saddr)"npc_i00_data.rel");
    TObjNpcNFW00__texture_gvm_handle = (uaddr)load_gvm_texture_file((saddr)"n_i00_body.gvm");
}

TObjNpcNFW00::~TObjNpcNFW00() {}

TObjNpcNFW00::TObjNpcNFW00(TObject *parent, void *set_data) : TUnk_804A8640(parent) {
    this->m_name = TObjNpcNFW00__name;
    this->apply_set_data(set_data);
    init_position_vectors();
    this->model = *(void **)TObjNpcNFW00__named_object_resource;
    this->texlist = TObjNpcNFW00__texture_gvm_handle;
    this->setup_common();
}
