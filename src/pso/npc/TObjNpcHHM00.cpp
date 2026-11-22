#include "types.h"
#include "pso/npc/TObjNpcHHM00.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/GinjaTexture.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/text_800F9B84.h"

#pragma readonly_strings on

const char *TObjNpcHHM00__name = "TObjNpcHHM00";
uaddr TObjNpcHHM00__model_object;
uaddr TObjNpcHHM00__body_texture_gvm_handle;

void *TObjNpcHHM00__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcHHM00(control, set_data);
}

void TObjNpcHHM00::free_resources() {
    if (TObjNpcHHM00__body_texture_gvm_handle != 0) {
        release_texture_list((GinjaTextureList *)TObjNpcHHM00__body_texture_gvm_handle);
        TAdSinglePlyChrSelectGC::safe_free(TObjNpcHHM00__body_texture_gvm_handle);
        TObjNpcHHM00__body_texture_gvm_handle = 0;
    }
    if (TObjNpcHHM00__model_object != 0) {
        TLobby::free_nodes_with_id(TObjNpcHHM00__model_object);
        TObjNpcHHM00__model_object = 0;
    }
}

void TObjNpcHHM00::load_resources() {
    TObjNpcHHM00__model_object = create_named_object((saddr)"npc_a00_data.rel");
    TObjNpcHHM00__body_texture_gvm_handle = (uaddr)load_gvm_texture_file((saddr)"n_a00_w_body.gvm");
}

TObjNpcHHM00::~TObjNpcHHM00() {}

TObjNpcHHM00::TObjNpcHHM00(TObject *parent, void *set_data) : TUnk_804A9F50(parent) {
    this->m_name = TObjNpcHHM00__name;
    this->apply_set_data(set_data);
    init_position_vectors();
    this->model = *(void **)TObjNpcHHM00__model_object;
    this->texlist = TObjNpcHHM00__body_texture_gvm_handle;
    this->setup_common();
}
