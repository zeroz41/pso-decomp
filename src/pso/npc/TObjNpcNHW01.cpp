#include "types.h"
#include "pso/npc/TObjNpcNHW01.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/GinjaTexture.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/text_800F9B84.h"

#pragma readonly_strings on

const char *TObjNpcNHW01__name = "TObjNpcNHW01";
uaddr TObjNpcNHW01__model_object;
uaddr TObjNpcNHW01__texture_handle;

void *TObjNpcNHW01__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcNHW01(control, set_data);
}

void TObjNpcNHW01::free_resources() {
    if (TObjNpcNHW01__texture_handle != 0) {
        release_texture_list((GinjaTextureList *)TObjNpcNHW01__texture_handle);
        TAdSinglePlyChrSelectGC::safe_free(TObjNpcNHW01__texture_handle);
        TObjNpcNHW01__texture_handle = 0;
    }
    if (TObjNpcNHW01__model_object != 0) {
        TLobby::free_nodes_with_id(TObjNpcNHW01__model_object);
        TObjNpcNHW01__model_object = 0;
    }
}

void TObjNpcNHW01::load_resources() {
    TObjNpcNHW01__model_object = create_named_object((saddr)"npc_b01_data.rel");
    TObjNpcNHW01__texture_handle = (uaddr)load_gvm_texture_file((saddr)"n_b01_e_body.gvm");
}

TObjNpcNHW01::~TObjNpcNHW01() {}

TObjNpcNHW01::TObjNpcNHW01(TObject *parent, void *set_data) : TUnk_804A8640(parent) {
    this->m_name = TObjNpcNHW01__name;
    this->apply_set_data(set_data);
    init_position_vectors();
    this->model = *(void **)TObjNpcNHW01__model_object;
    this->texlist = TObjNpcNHW01__texture_handle;
    this->setup_common();
}
