#include "types.h"
#include "pso/npc/TObjNpcNFM01.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/GinjaTexture.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/text_800F9B84.h"

#pragma readonly_strings on

const char *TObjNpcNFM01__name = "TObjNpcNFM01";
u32 TObjNpcNFM01__model_object;
u32 TObjNpcNFM01__texture_handle;

extern "C" s32 __vt__12TObjNpcNFM01[];

void *TObjNpcNFM01__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    void *npc = TObject::operator new(sizeof(TObjNpcNFM01));
    if (npc != NULL) {
        npc = TObjNpcNFM01__ct((TObjNpcNFM01 *)npc, control, set_data);
    }
    return npc;
}

void TObjNpcNFM01::free_resources() {
    if (TObjNpcNFM01__texture_handle != 0) {
        release_texture_list((GinjaTextureList *)TObjNpcNFM01__texture_handle);
        TAdSinglePlyChrSelectGC::safe_free(TObjNpcNFM01__texture_handle);
        TObjNpcNFM01__texture_handle = 0;
    }
    if (TObjNpcNFM01__model_object != 0) {
        TLobby::free_nodes_with_id(TObjNpcNFM01__model_object);
        TObjNpcNFM01__model_object = 0;
    }
}

void TObjNpcNFM01::load_resources() {
    TObjNpcNFM01__model_object = create_named_object((s32)"npc_h01_data.rel");
    TObjNpcNFM01__texture_handle = (u32)load_gvm_texture_file((s32)"n_h01_e_body.gvm");
}

TObjNpcNFM01::~TObjNpcNFM01() {}

TObjNpcNFM01 *TObjNpcNFM01__ct(TObjNpcNFM01 *npc, TObjControl *control, void *set_data) {
    npc->construct_male_npc_base();
    *(s32 **)((u8 *)npc + 0x18) = __vt__12TObjNpcNFM01;
    npc->m_name = TObjNpcNFM01__name;
    npc->apply_set_data(set_data);
    ((TObjPlayer *)npc)->init_position_vectors();
    npc->model = *(void **)TObjNpcNFM01__model_object;
    npc->texlist = TObjNpcNFM01__texture_handle;
    npc->setup_common();
    return npc;
}
