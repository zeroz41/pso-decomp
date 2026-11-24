#include "pso/system/memory.h"
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

const char *TObjNpcNHW01::name = "TObjNpcNHW01";
void **TObjNpcNHW01::model_object;
NJS_TEXLIST *TObjNpcNHW01::texture_handle;

void *TObjNpcNHW01::create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcNHW01(control, set_data);
}

void TObjNpcNHW01::free_resources() {
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

void TObjNpcNHW01::load_resources() {
    model_object = static_cast<void **>(create_named_object("npc_b01_data.rel"));
    texture_handle = load_gvm_texture_file("n_b01_e_body.gvm");
}

TObjNpcNHW01::~TObjNpcNHW01() {}

TObjNpcNHW01::TObjNpcNHW01(TObject *parent, void *set_data) : TObjNpcFemale(parent) {
    this->m_name = name;
    this->apply_set_data(set_data);
    init_position_vectors();
    this->model = *model_object;
    this->texlist = texture_handle;
    this->setup_common();
}
