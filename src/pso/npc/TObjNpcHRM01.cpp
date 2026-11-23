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

const char *TObjNpcHRM01__name = "TObjNpcHRM01";
uaddr TObjNpcHRM01__shared_object_resource;
uaddr TObjNpcHRM01__body_texture_gvm_handle;

void *TObjNpcHRM01__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcHRM01(control, set_data);
}

void TObjNpcHRM01::free_shared_objects() {
    if (TObjNpcHRM01__body_texture_gvm_handle != 0) {
        release_texture_list((NJS_TEXLIST *)TObjNpcHRM01__body_texture_gvm_handle);
        TAdSinglePlyChrSelectGC::safe_free(TObjNpcHRM01__body_texture_gvm_handle);
        TObjNpcHRM01__body_texture_gvm_handle = 0;
    }
    if (TObjNpcHRM01__shared_object_resource != 0) {
        TLobby::free_nodes_with_id(TObjNpcHRM01__shared_object_resource);
        TObjNpcHRM01__shared_object_resource = 0;
    }
}

void TObjNpcHRM01::load_resources() {
    TObjNpcHRM01__shared_object_resource = create_named_object("npc_d01_data.rel");
    TObjNpcHRM01__body_texture_gvm_handle = (uaddr)load_gvm_texture_file("n_d01_e_body.gvm");
}

TObjNpcHRM01::~TObjNpcHRM01() {}

TObjNpcHRM01::TObjNpcHRM01(TObject *parent, void *set_data) : TUnk_804A9F50(parent) {
    this->m_name = TObjNpcHRM01__name;
    this->apply_set_data(set_data);
    init_position_vectors();
    this->model = *(void **)TObjNpcHRM01__shared_object_resource;
    this->texlist = TObjNpcHRM01__body_texture_gvm_handle;
    this->setup_common();
}
