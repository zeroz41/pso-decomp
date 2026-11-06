#include "types.h"
#include "pso/npc/TObjNpcNFW00.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/GinjaTexture.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/text_800F9B84.h"

#pragma readonly_strings on

const char *TObjNpcNFW00__name = "TObjNpcNFW00";
u32 TObjNpcNFW00__named_object_resource;
u32 TObjNpcNFW00__texture_gvm_handle;

extern "C" s32 __vt__12TObjNpcNFW00[];

void *TObjNpcNFW00__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    void *npc = TObject::operator new(sizeof(TObjNpcNFW00));
    if (npc != NULL) {
        npc = TObjNpcNFW00__ct((TObjNpcNFW00 *)npc, control, set_data);
    }
    return npc;
}

void TObjNpcNFW00::free_resources() {
    if (TObjNpcNFW00__texture_gvm_handle != 0) {
        release_texture_list((GinjaTextureList *)TObjNpcNFW00__texture_gvm_handle);
        TAdSinglePlyChrSelectGC::safe_free(TObjNpcNFW00__texture_gvm_handle);
        TObjNpcNFW00__texture_gvm_handle = 0;
    }
    if (TObjNpcNFW00__named_object_resource != 0) {
        TLobby::free_nodes_with_id(TObjNpcNFW00__named_object_resource);
        TObjNpcNFW00__named_object_resource = 0;
    }
}

void TObjNpcNFW00::load_assets() {
    TObjNpcNFW00__named_object_resource = create_named_object((s32)"npc_i00_data.rel");
    TObjNpcNFW00__texture_gvm_handle = (u32)load_gvm_texture_file((s32)"n_i00_body.gvm");
}

TObjNpcNFW00::~TObjNpcNFW00() {}

TObjNpcNFW00 *TObjNpcNFW00__ct(TObjNpcNFW00 *npc, TObjControl *control, void *set_data) {
    npc->construct_female_base();
    *(s32 **)((u8 *)npc + 0x18) = __vt__12TObjNpcNFW00;
    npc->m_name = TObjNpcNFW00__name;
    npc->apply_set_data(set_data);
    ((TObjPlayer *)npc)->init_position_vectors();
    npc->model = *(void **)TObjNpcNFW00__named_object_resource;
    npc->texlist = TObjNpcNFW00__texture_gvm_handle;
    npc->setup_common();
    return npc;
}
