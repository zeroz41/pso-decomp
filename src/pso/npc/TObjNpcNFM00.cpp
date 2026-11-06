#include "types.h"
#include "pso/npc/TObjNpcNFM00.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/GinjaTexture.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/text_800F9B84.h"

#pragma readonly_strings on

const char *TObjNpcNFM00__name = "TObjNpcNFM00";
u32 TObjNpcNFM00__shared_named_model_object;
u32 TObjNpcNFM00__texture_gvm_handle;

extern "C" s32 __vt__12TObjNpcNFM00[];

void *TObjNpcNFM00__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    void *npc = TObject::operator new(sizeof(TObjNpcNFM00));
    if (npc != NULL) {
        npc = TObjNpcNFM00__ct((TObjNpcNFM00 *)npc, control, set_data);
    }
    return npc;
}

void TObjNpcNFM00::free_resources() {
    if (TObjNpcNFM00__texture_gvm_handle != 0) {
        release_texture_list((GinjaTextureList *)TObjNpcNFM00__texture_gvm_handle);
        TAdSinglePlyChrSelectGC::safe_free(TObjNpcNFM00__texture_gvm_handle);
        TObjNpcNFM00__texture_gvm_handle = 0;
    }
    if (TObjNpcNFM00__shared_named_model_object != 0) {
        TLobby::free_nodes_with_id(TObjNpcNFM00__shared_named_model_object);
        TObjNpcNFM00__shared_named_model_object = 0;
    }
}

void TObjNpcNFM00::load_assets() {
    TObjNpcNFM00__shared_named_model_object = create_named_object((s32)"npc_h00_data.rel");
    TObjNpcNFM00__texture_gvm_handle = (u32)load_gvm_texture_file((s32)"n_h00_body.gvm");
}

TObjNpcNFM00::~TObjNpcNFM00() {}

TObjNpcNFM00 *TObjNpcNFM00__ct(TObjNpcNFM00 *npc, TObjControl *control, void *set_data) {
    npc->construct_male_npc_base();
    *(s32 **)((u8 *)npc + 0x18) = __vt__12TObjNpcNFM00;
    npc->m_name = TObjNpcNFM00__name;
    npc->apply_set_data(set_data);
    ((TObjPlayer *)npc)->init_position_vectors();
    npc->model = *(void **)TObjNpcNFM00__shared_named_model_object;
    npc->texlist = TObjNpcNFM00__texture_gvm_handle;
    npc->setup_common();
    return npc;
}
