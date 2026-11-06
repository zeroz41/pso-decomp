#include "types.h"
#include "pso/npc/TObjNpcNHW00.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/GinjaTexture.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/text_800F9B84.h"

#pragma readonly_strings on

const char *TObjNpcNHW00__name = "TObjNpcNHW00";
u32 TObjNpcNHW00__shared_named_model_object;
u32 TObjNpcNHW00__texture_gvm_handle;

extern "C" s32 __vt__12TObjNpcNHW00[];

void *TObjNpcNHW00__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    void *npc = TObject::operator new(sizeof(TObjNpcNHW00));
    if (npc != NULL) {
        npc = TObjNpcNHW00__ct((TObjNpcNHW00 *)npc, control, set_data);
    }
    return npc;
}

void TObjNpcNHW00::free_static_resources() {
    if (TObjNpcNHW00__texture_gvm_handle != 0) {
        release_texture_list((GinjaTextureList *)TObjNpcNHW00__texture_gvm_handle);
        TAdSinglePlyChrSelectGC::safe_free(TObjNpcNHW00__texture_gvm_handle);
        TObjNpcNHW00__texture_gvm_handle = 0;
    }
    if (TObjNpcNHW00__shared_named_model_object != 0) {
        TLobby::free_nodes_with_id(TObjNpcNHW00__shared_named_model_object);
        TObjNpcNHW00__shared_named_model_object = 0;
    }
}

void TObjNpcNHW00::load_resources() {
    TObjNpcNHW00__shared_named_model_object = create_named_object((s32)"npc_b00_data.rel");
    TObjNpcNHW00__texture_gvm_handle = (u32)load_gvm_texture_file((s32)"n_b00_body.gvm");
}

TObjNpcNHW00::~TObjNpcNHW00() {}

TObjNpcNHW00 *TObjNpcNHW00__ct(TObjNpcNHW00 *npc, TObjControl *control, void *set_data) {
    npc->construct_female_base();
    *(s32 **)((u8 *)npc + 0x18) = __vt__12TObjNpcNHW00;
    npc->m_name = TObjNpcNHW00__name;
    npc->apply_set_data(set_data);
    ((TObjPlayer *)npc)->init_position_vectors();
    npc->model = *(void **)TObjNpcNHW00__shared_named_model_object;
    npc->texlist = TObjNpcNHW00__texture_gvm_handle;
    npc->setup_common();
    return npc;
}
