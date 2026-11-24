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

const char *TObjNpcHRM00::name = "TObjNpcHRM00";
uaddr TObjNpcHRM00::named_object_resource;
NJS_TEXLIST *TObjNpcHRM00::body_texture_gvm;

void *TObjNpcHRM00::create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcHRM00(control, set_data);
}

void TObjNpcHRM00::destroy_resources() {
    if (body_texture_gvm != NULL) {
        release_texture_list(body_texture_gvm);
        TAdSinglePlyChrSelectGC::safe_free((uaddr)body_texture_gvm);
        body_texture_gvm = NULL;
    }
    if (named_object_resource != 0) {
        TLobby::free_nodes_with_id(named_object_resource);
        named_object_resource = 0;
    }
}

void TObjNpcHRM00::load_resources() {
    named_object_resource = create_named_object("npc_d00_data.rel");
    body_texture_gvm = load_gvm_texture_file("n_d00_w_body.gvm");
}

TObjNpcHRM00::~TObjNpcHRM00() {}

TObjNpcHRM00::TObjNpcHRM00(TObject *parent, void *set_data) : TObjNpcMale(parent) {
    this->m_name = name;
    this->apply_set_data(set_data);
    init_position_vectors();
    this->model = *(void **)named_object_resource;
    this->texlist = body_texture_gvm;
    this->setup_common();
}
