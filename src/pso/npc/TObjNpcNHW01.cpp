#include "types.h"
#include "pso/npc/TObjNpcNHW01.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/GinjaTexture.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/text_800F9B84.h"

#pragma readonly_strings on

const char *TObjNpcNHW01__name = "TObjNpcNHW01";
u32 TObjNpcNHW01__model_object;
u32 TObjNpcNHW01__texture_handle;

extern "C" s32 __vt__12TObjNpcNHW01[];

void *TObjNpcNHW01__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    void *npc = TObject::operator new(sizeof(TObjNpcNHW01));
    if (npc != NULL) {
        npc = TObjNpcNHW01__ct((TObjNpcNHW01 *)npc, control, set_data);
    }
    return npc;
}

void TObjNpcNHW01::free_resources() {
    if (TObjNpcNHW01__texture_handle != 0) {
        release_texture_list((GinjaTextureList *)TObjNpcNHW01__texture_handle);
        TAdSinglePlyChrSelectGC::safe_free(TObjNpcNHW01__texture_handle);
        TObjNpcNHW01__texture_handle = 0;
    }
    if (TObjNpcNHW01__model_object != 0) {
        TLobby::free_nodes_with_id(TObjNpcNHW01__model_object);
        TObjNpcNHW01__model_object = 0;
    }
}

void TObjNpcNHW01::load_resources() {
    TObjNpcNHW01__model_object = create_named_object((s32)"npc_b01_data.rel");
    TObjNpcNHW01__texture_handle = (u32)load_gvm_texture_file((s32)"n_b01_e_body.gvm");
}

TObjNpcNHW01::~TObjNpcNHW01() {}

TObjNpcNHW01 *TObjNpcNHW01__ct(TObjNpcNHW01 *npc, TObjControl *control, void *set_data) {
    npc->construct_female_base();
    *(s32 **)((u8 *)npc + 0x18) = __vt__12TObjNpcNHW01;
    npc->m_name = TObjNpcNHW01__name;
    npc->apply_set_data(set_data);
    ((TObjPlayer *)npc)->init_position_vectors();
    npc->model = *(void **)TObjNpcNHW01__model_object;
    npc->texlist = TObjNpcNHW01__texture_handle;
    npc->setup_common();
    return npc;
}
