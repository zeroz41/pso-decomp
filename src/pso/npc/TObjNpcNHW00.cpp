#include "types.h"
#include "pso/npc/TObjNpcNHW00.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/GinjaTexture.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/text_800F9B84.h"

#pragma readonly_strings on

const char *TObjNpcNHW00__name = "TObjNpcNHW00";
uaddr TObjNpcNHW00__shared_named_model_object;
NJS_TEXLIST *TObjNpcNHW00__texture_gvm_handle;

void *TObjNpcNHW00__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcNHW00(control, set_data);
}

void TObjNpcNHW00::free_static_resources() {
    if (TObjNpcNHW00__texture_gvm_handle != NULL) {
        release_texture_list(TObjNpcNHW00__texture_gvm_handle);
        TAdSinglePlyChrSelectGC::safe_free((uaddr)TObjNpcNHW00__texture_gvm_handle);
        TObjNpcNHW00__texture_gvm_handle = NULL;
    }
    if (TObjNpcNHW00__shared_named_model_object != 0) {
        TLobby::free_nodes_with_id(TObjNpcNHW00__shared_named_model_object);
        TObjNpcNHW00__shared_named_model_object = 0;
    }
}

void TObjNpcNHW00::load_resources() {
    TObjNpcNHW00__shared_named_model_object = create_named_object("npc_b00_data.rel");
    TObjNpcNHW00__texture_gvm_handle = load_gvm_texture_file("n_b00_body.gvm");
}

TObjNpcNHW00::~TObjNpcNHW00() {}

TObjNpcNHW00::TObjNpcNHW00(TObject *parent, void *set_data) : TUnk_804A8640(parent) {
    this->m_name = TObjNpcNHW00__name;
    this->apply_set_data(set_data);
    init_position_vectors();
    this->model = *(void **)TObjNpcNHW00__shared_named_model_object;
    this->texlist = TObjNpcNHW00__texture_gvm_handle;
    this->setup_common();
}
