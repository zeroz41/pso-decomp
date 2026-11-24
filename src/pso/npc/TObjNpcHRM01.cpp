#include "pso/system/memory.h"
#include "types.h"
#include "pso/npc/TObjNpcHRM01.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/GinjaTexture.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/text_800F9B84.h"

#pragma readonly_strings on

const char *TObjNpcHRM01::name = "TObjNpcHRM01";
void **TObjNpcHRM01::shared_object_resource;
NJS_TEXLIST *TObjNpcHRM01::body_texture_gvm_handle;

void *TObjNpcHRM01::create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcHRM01(control, set_data);
}

void TObjNpcHRM01::free_shared_objects() {
    if (body_texture_gvm_handle != NULL) {
        release_texture_list(body_texture_gvm_handle);
        safe_free(body_texture_gvm_handle);
        body_texture_gvm_handle = NULL;
    }
    if (shared_object_resource != NULL) {
        TLobby::free_nodes_with_id(reinterpret_cast<uaddr>(shared_object_resource));
        shared_object_resource = NULL;
    }
}

void TObjNpcHRM01::load_resources() {
    shared_object_resource = static_cast<void **>(create_named_object("npc_d01_data.rel"));
    body_texture_gvm_handle = load_gvm_texture_file("n_d01_e_body.gvm");
}

TObjNpcHRM01::~TObjNpcHRM01() {}

TObjNpcHRM01::TObjNpcHRM01(TObject *parent, void *set_data) : TObjNpcMale(parent) {
    this->m_name = name;
    this->apply_set_data(set_data);
    init_position_vectors();
    this->model = *shared_object_resource;
    this->texlist = body_texture_gvm_handle;
    this->setup_common();
}
