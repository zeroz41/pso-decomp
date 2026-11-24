#include "pso/system/memory.h"
#include "pso/system/SoundEffect.h"
#include "types.h"
#include "pso/render/GinjaTexture.h"
#include "pso/object/TObjControl.h"
#include "pso/npc/TObjNpcARM00.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/npc/TObjNpcARW00.h"
#include "pso/unk/text_800F9B84.h"
#include "pso/npc/TObjNpcMale.h"

#include "pso/unk/TLobby.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcLappy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/render/GinjaTexture.h"
#include "pso/system/SoundEffect.h"

#pragma readonly_strings on

void *TObjNpcARM00::create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcARM00(control, set_data);
}

const char *TObjNpcARM00::name = "TObjNpcARM00";
void **TObjNpcARM00::model_resource;
NJS_TEXLIST *TObjNpcARM00::texture_list;

void TObjNpcARM00::free_resources() {
    if (texture_list != NULL) {
        release_texture_list(texture_list);
        safe_free(texture_list);
        texture_list = NULL;
    }
    if (model_resource != NULL) {
        TLobby::free_nodes_with_id(reinterpret_cast<uaddr>(model_resource));
        model_resource = NULL;
    }
}

void TObjNpcARM00::load_resources() {
    model_resource = static_cast<void **>(create_named_object("npc_e00_data.rel"));
    texture_list = load_gvm_texture_file("n_e00_w_body.gvm");
}

TObjNpcARM00::~TObjNpcARM00() {}

TObjNpcARM00::TObjNpcARM00(TObject *parent, void *set_data) : TObjNpcMale(parent) {
    this->m_name = name;
    this->apply_set_data(set_data);
    init_position_vectors();
    this->model = *model_resource;
    this->texlist = texture_list;
    this->setup_common();
}

void TObjNpcARM00::play_voice() {
    play_sound_effect(0x40003B08, &position, 0, 0);
}

