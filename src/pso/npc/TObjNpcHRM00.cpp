#include "pso/system/memory.h"
#include "types.h"
#include "pso/npc/TObjNpcHRM00.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/GinjaTexture.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/text_800F9B84.h"

#pragma readonly_strings on

const char *TObjNpcHRM00__name = "TObjNpcHRM00";
void **TObjNpcHRM00__named_object_resource;
NJS_TEXLIST *TObjNpcHRM00__body_texture_gvm;

void *TObjNpcHRM00__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcHRM00(control, set_data);
}

void TObjNpcHRM00::destroy_resources() {
    if (TObjNpcHRM00__body_texture_gvm != NULL) {
        release_texture_list(TObjNpcHRM00__body_texture_gvm);
        safe_free(TObjNpcHRM00__body_texture_gvm);
        TObjNpcHRM00__body_texture_gvm = NULL;
    }
    if (TObjNpcHRM00__named_object_resource != NULL) {
        TLobby::free_nodes_with_id(reinterpret_cast<uaddr>(TObjNpcHRM00__named_object_resource));
        TObjNpcHRM00__named_object_resource = NULL;
    }
}

void TObjNpcHRM00::load_resources() {
    TObjNpcHRM00__named_object_resource = static_cast<void **>(create_named_object("npc_d00_data.rel"));
    TObjNpcHRM00__body_texture_gvm = load_gvm_texture_file("n_d00_w_body.gvm");
}

TObjNpcHRM00::~TObjNpcHRM00() {}

TObjNpcHRM00::TObjNpcHRM00(TObject *parent, void *set_data) : TUnk_804A9F50(parent) {
    this->m_name = TObjNpcHRM00__name;
    this->apply_set_data(set_data);
    init_position_vectors();
    model = *TObjNpcHRM00__named_object_resource;
    this->texlist = TObjNpcHRM00__body_texture_gvm;
    this->setup_common();
}
