#include "pso/system/memory.h"
#include "types.h"
#include "pso/render/GinjaTexture.h"
#include "pso/object/TObjControl.h"
#include "pso/npc/TObjNpcAHM01.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/npc/TObjNpcARM00.h"
#include "pso/unk/text_800F9B84.h"
#include "pso/npc/TObjNpcMale.h"

#include "pso/unk/TLobby.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcLappy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/SoundEffect.h"
#include "pso/render/GinjaTexture.h"

#pragma readonly_strings on

void *TObjNpcAHM01::create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcAHM01(control, set_data);
}

const char *TObjNpcAHM01::name = "TObjNpcAHM01";
void **TObjNpcAHM01::shared_object;
NJS_TEXLIST *TObjNpcAHM01::texture_handle;

void TObjNpcAHM01::free_resources() {
    if (texture_handle != NULL) {
        release_texture_list(texture_handle);
        safe_free(texture_handle);
        texture_handle = NULL;
    }
    if (shared_object != NULL) {
        TLobby::free_nodes_with_id(reinterpret_cast<uaddr>(shared_object));
        shared_object = NULL;
    }
}

void TObjNpcAHM01::load_resources() {
    shared_object = static_cast<void **>(create_named_object("npc_c01_data.rel"));
    texture_handle = load_gvm_texture_file("n_c01_e_body.gvm");
}

TObjNpcAHM01::~TObjNpcAHM01() {}

TObjNpcAHM01::TObjNpcAHM01(TObject *parent, void *set_data) : TObjNpcMale(parent) {
    this->m_name = name;
    this->apply_set_data(set_data);
    init_position_vectors();
    this->model = *shared_object;
    this->texlist = texture_handle;
    this->setup_common();
}

void TObjNpcAHM01::play_voice() {
    play_sound_effect(0x40004C15, &position, 0, 0);
}

