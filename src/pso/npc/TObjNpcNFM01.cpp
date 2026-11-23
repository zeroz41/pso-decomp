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

const char *TObjNpcNFM01__name = "TObjNpcNFM01";
uaddr TObjNpcNFM01__model_object;
NJS_TEXLIST *TObjNpcNFM01__texture_handle;

void *TObjNpcNFM01__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcNFM01(control, set_data);
}

void TObjNpcNFM01::free_resources() {
    if (TObjNpcNFM01__texture_handle != NULL) {
        release_texture_list(TObjNpcNFM01__texture_handle);
        TAdSinglePlyChrSelectGC::safe_free((uaddr)TObjNpcNFM01__texture_handle);
        TObjNpcNFM01__texture_handle = NULL;
    }
    if (TObjNpcNFM01__model_object != 0) {
        TLobby::free_nodes_with_id(TObjNpcNFM01__model_object);
        TObjNpcNFM01__model_object = 0;
    }
}

void TObjNpcNFM01::load_resources() {
    TObjNpcNFM01__model_object = create_named_object("npc_h01_data.rel");
    TObjNpcNFM01__texture_handle = load_gvm_texture_file("n_h01_e_body.gvm");
}

TObjNpcNFM01::~TObjNpcNFM01() {}

TObjNpcNFM01::TObjNpcNFM01(TObject *parent, void *set_data) : TUnk_804A9F50(parent) {
    this->m_name = TObjNpcNFM01__name;
    this->apply_set_data(set_data);
    init_position_vectors();
    this->model = *(void **)TObjNpcNFM01__model_object;
    this->texlist = TObjNpcNFM01__texture_handle;
    this->setup_common();
}
