#include "pso/system/memory.h"
#include "types.h"
#include "pso/npc/TObjNpcHHM00.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/GinjaTexture.h"
#include "pso/render/psoLoadTexture.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/network/TLobby.h"
#include "pso/system/MallocLoadFilePrc.h"

#pragma readonly_strings on

const char *TObjNpcHHM00::name = "TObjNpcHHM00";
NJS_OBJECT **TObjNpcHHM00::model_object;
NJS_TEXLIST *TObjNpcHHM00::body_texture_gvm_handle;

void *TObjNpcHHM00::create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcHHM00(control, set_data);
}

void TObjNpcHHM00::free_resources() {
    if (body_texture_gvm_handle != NULL) {
        release_texture_list(body_texture_gvm_handle);
        safe_free(body_texture_gvm_handle);
        body_texture_gvm_handle = NULL;
    }
    if (model_object != NULL) {
        TLobby::free_nodes_with_id(model_object);
        model_object = NULL;
    }
}

void TObjNpcHHM00::load_resources() {
    model_object = static_cast<NJS_OBJECT **>(create_named_object("npc_a00_data.rel"));
    body_texture_gvm_handle = LoadPvmFileTls("n_a00_w_body.gvm");
}

TObjNpcHHM00::~TObjNpcHHM00() {}

TObjNpcHHM00::TObjNpcHHM00(TObject *parent, void *set_data) : TObjNpcMale(parent) {
    this->m_name = name;
    this->apply_set_data(set_data);
    init_position_vectors();
    this->model = (NJS_OBJECT *)*model_object;
    this->texlist = body_texture_gvm_handle;
    this->setup_common();
}
