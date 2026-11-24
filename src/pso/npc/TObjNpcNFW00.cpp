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

const char *TObjNpcNFW00::name = "TObjNpcNFW00";
uaddr TObjNpcNFW00::named_object_resource;
NJS_TEXLIST *TObjNpcNFW00::texture_gvm_handle;

void *TObjNpcNFW00::create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcNFW00(control, set_data);
}

void TObjNpcNFW00::free_resources() {
    if (texture_gvm_handle != NULL) {
        release_texture_list(texture_gvm_handle);
        TAdSinglePlyChrSelectGC::safe_free((uaddr)texture_gvm_handle);
        texture_gvm_handle = NULL;
    }
    if (named_object_resource != 0) {
        TLobby::free_nodes_with_id(named_object_resource);
        named_object_resource = 0;
    }
}

void TObjNpcNFW00::load_assets() {
    named_object_resource = create_named_object("npc_i00_data.rel");
    texture_gvm_handle = load_gvm_texture_file("n_i00_body.gvm");
}

TObjNpcNFW00::~TObjNpcNFW00() {}

TObjNpcNFW00::TObjNpcNFW00(TObject *parent, void *set_data) : TUnk_804A8640(parent) {
    this->m_name = name;
    this->apply_set_data(set_data);
    init_position_vectors();
    this->model = *(void **)named_object_resource;
    this->texlist = texture_gvm_handle;
    this->setup_common();
}
