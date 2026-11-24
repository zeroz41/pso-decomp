#include "pso/system/memory.h"
#include "types.h"
#include "pso/render/GinjaTexture.h"
#include "pso/object/TObjControl.h"
#include "pso/system/task/TMainTask.h"
#include "pso/npc/TObjNpcARW00.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/unk/text_800F9B84.h"
#include "pso/npc/TObjNpcFemale.h"
#include "pso/unk/TLobby.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcFemaleBase.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/SoundEffect.h"
#include "pso/render/GinjaTexture.h"

void *TObjNpcARW00::create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcARW00(control, set_data);
}

const char *TObjNpcARW00::name = "TObjNpcARW00";

void **TObjNpcARW00::static_model;
NJS_TEXLIST *TObjNpcARW00::gvm_texture_handle;

void TObjNpcARW00::free_resources() {
    if (gvm_texture_handle != NULL) {
        release_texture_list(gvm_texture_handle);
        safe_free(gvm_texture_handle);
        gvm_texture_handle = NULL;
    }
    if (static_model != NULL) {
        TLobby::free_nodes_with_id(reinterpret_cast<uaddr>(static_model));
        static_model = NULL;
    }
}

void TObjNpcARW00::load_resources() {
    static_model = static_cast<void **>(create_named_object("npc_f00_data.rel"));
    gvm_texture_handle = load_gvm_texture_file("n_f00_w_body.gvm");
}

TObjNpcARW00::~TObjNpcARW00() {}

TObjNpcARW00::TObjNpcARW00(TObject *parent, void *set_data) : TObjNpcFemale(parent) {
    this->m_name = name;
    this->apply_set_data(set_data);
    init_position_vectors();
    this->model = *static_model;
    this->texlist = gvm_texture_handle;
    this->setup_common();
}

void TObjNpcARW00::play_voice() {
    play_sound_effect(0x40004C15, &position, 0, 0);
}

