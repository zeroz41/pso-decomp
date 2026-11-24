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

const char *TObjNpcNFW01__name = "TObjNpcNFW01";
void **TObjNpcNFW01__shared_object_resource;
NJS_TEXLIST *TObjNpcNFW01__texture_gvm;

void *TObjNpcNFW01__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcNFW01(control, set_data);
}

void TObjNpcNFW01::free_resources() {
    if (TObjNpcNFW01__texture_gvm != NULL) {
        release_texture_list(TObjNpcNFW01__texture_gvm);
        safe_free(TObjNpcNFW01__texture_gvm);
        TObjNpcNFW01__texture_gvm = NULL;
    }
    if (TObjNpcNFW01__shared_object_resource != NULL) {
        TLobby::free_nodes_with_id(reinterpret_cast<uaddr>(TObjNpcNFW01__shared_object_resource));
        TObjNpcNFW01__shared_object_resource = NULL;
    }
}

void TObjNpcNFW01::load_resources() {
    TObjNpcNFW01__shared_object_resource = static_cast<void **>(create_named_object("npc_i01_data.rel"));
    TObjNpcNFW01__texture_gvm = load_gvm_texture_file("n_i01_e_body.gvm");
}

TObjNpcNFW01::~TObjNpcNFW01() {}

TObjNpcNFW01::TObjNpcNFW01(TObject *parent, void *set_data) : TUnk_804A8640(parent) {
    this->m_name = TObjNpcNFW01__name;
    this->apply_set_data(set_data);
    init_position_vectors();
    model = *TObjNpcNFW01__shared_object_resource;
    this->texlist = TObjNpcNFW01__texture_gvm;
    this->setup_common();
}
