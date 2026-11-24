#include "pso/system/memory.h"
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

const char *TObjNpcNHW00::name = "TObjNpcNHW00";
void **TObjNpcNHW00::shared_named_model_object;
NJS_TEXLIST *TObjNpcNHW00::texture_gvm_handle;

void *TObjNpcNHW00::create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcNHW00(control, set_data);
}

void TObjNpcNHW00::free_static_resources() {
    if (texture_gvm_handle != NULL) {
        release_texture_list(texture_gvm_handle);
        safe_free(texture_gvm_handle);
        texture_gvm_handle = NULL;
    }
    if (shared_named_model_object != NULL) {
        TLobby::free_nodes_with_id(reinterpret_cast<uaddr>(shared_named_model_object));
        shared_named_model_object = NULL;
    }
}

void TObjNpcNHW00::load_resources() {
    shared_named_model_object = static_cast<void **>(create_named_object("npc_b00_data.rel"));
    texture_gvm_handle = load_gvm_texture_file("n_b00_body.gvm");
}

TObjNpcNHW00::~TObjNpcNHW00() {}

TObjNpcNHW00::TObjNpcNHW00(TObject *parent, void *set_data) : TObjNpcFemale(parent) {
    this->m_name = name;
    this->apply_set_data(set_data);
    init_position_vectors();
    this->model = *shared_named_model_object;
    this->texlist = texture_gvm_handle;
    this->setup_common();
}
