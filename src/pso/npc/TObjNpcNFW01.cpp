#include "types.h"
#include "pso/npc/TObjNpcNFW01.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/GinjaTexture.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/text_800F9B84.h"

#pragma readonly_strings on

const char *TObjNpcNFW01__name = "TObjNpcNFW01";
u32 TObjNpcNFW01__shared_object_resource;
u32 TObjNpcNFW01__texture_gvm;

extern "C" s32 __vt__12TObjNpcNFW01[];

void *TObjNpcNFW01__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    void *npc = TObject::operator new(sizeof(TObjNpcNFW01));
    if (npc != NULL) {
        npc = TObjNpcNFW01__ct((TObjNpcNFW01 *)npc, control, set_data);
    }
    return npc;
}

void TObjNpcNFW01::free_resources() {
    if (TObjNpcNFW01__texture_gvm != 0) {
        release_texture_list((GinjaTextureList *)TObjNpcNFW01__texture_gvm);
        TAdSinglePlyChrSelectGC::safe_free(TObjNpcNFW01__texture_gvm);
        TObjNpcNFW01__texture_gvm = 0;
    }
    if (TObjNpcNFW01__shared_object_resource != 0) {
        TLobby::free_nodes_with_id(TObjNpcNFW01__shared_object_resource);
        TObjNpcNFW01__shared_object_resource = 0;
    }
}

void TObjNpcNFW01::load_resources() {
    TObjNpcNFW01__shared_object_resource = create_named_object((s32)"npc_i01_data.rel");
    TObjNpcNFW01__texture_gvm = (u32)load_gvm_texture_file((s32)"n_i01_e_body.gvm");
}

TObjNpcNFW01::~TObjNpcNFW01() {}

TObjNpcNFW01 *TObjNpcNFW01__ct(TObjNpcNFW01 *npc, TObjControl *control, void *set_data) {
    npc->construct_female_base();
    *(s32 **)((u8 *)npc + 0x18) = __vt__12TObjNpcNFW01;
    npc->m_name = TObjNpcNFW01__name;
    npc->apply_set_data(set_data);
    ((TObjPlayer *)npc)->init_position_vectors();
    npc->model = *(void **)TObjNpcNFW01__shared_object_resource;
    npc->texlist = TObjNpcNFW01__texture_gvm;
    npc->setup_common();
    return npc;
}
