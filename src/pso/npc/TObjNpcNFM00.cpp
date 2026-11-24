#include "pso/system/memory.h"
#include "types.h"
#include "pso/npc/TObjNpcNFM00.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/GinjaTexture.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/text_800F9B84.h"

#pragma readonly_strings on

const char *TObjNpcNFM00__name = "TObjNpcNFM00";
void **TObjNpcNFM00__shared_named_model_object;
NJS_TEXLIST *TObjNpcNFM00__texture_gvm_handle;

void *TObjNpcNFM00__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcNFM00(control, set_data);
}

void TObjNpcNFM00::free_resources() {
    if (TObjNpcNFM00__texture_gvm_handle != NULL) {
        release_texture_list(TObjNpcNFM00__texture_gvm_handle);
        safe_free(TObjNpcNFM00__texture_gvm_handle);
        TObjNpcNFM00__texture_gvm_handle = NULL;
    }
    if (TObjNpcNFM00__shared_named_model_object != NULL) {
        TLobby::free_nodes_with_id(reinterpret_cast<uaddr>(TObjNpcNFM00__shared_named_model_object));
        TObjNpcNFM00__shared_named_model_object = NULL;
    }
}

void TObjNpcNFM00::load_assets() {
    TObjNpcNFM00__shared_named_model_object = static_cast<void **>(create_named_object("npc_h00_data.rel"));
    TObjNpcNFM00__texture_gvm_handle = load_gvm_texture_file("n_h00_body.gvm");
}

TObjNpcNFM00::~TObjNpcNFM00() {}

TObjNpcNFM00::TObjNpcNFM00(TObject *parent, void *set_data) : TUnk_804A9F50(parent) {
    this->m_name = TObjNpcNFM00__name;
    this->apply_set_data(set_data);
    init_position_vectors();
    model = *TObjNpcNFM00__shared_named_model_object;
    this->texlist = TObjNpcNFM00__texture_gvm_handle;
    this->setup_common();
}
