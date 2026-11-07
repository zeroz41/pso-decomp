#include "types.h"
#include "pso/npc/TObjNpcHHM00.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/GinjaTexture.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/text_800F9B84.h"

#pragma readonly_strings on

const char *TObjNpcHHM00__name = "TObjNpcHHM00";
u32 TObjNpcHHM00__model_object;
u32 TObjNpcHHM00__body_texture_gvm_handle;

extern "C" s32 __vt__12TObjNpcHHM00[];

void *TObjNpcHHM00__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    void *npc = TObject::operator new(sizeof(TObjNpcHHM00));
    if (npc != NULL) {
        npc = TObjNpcHHM00__ct((TObjNpcHHM00 *)npc, control, set_data);
    }
    return npc;
}

void TObjNpcHHM00::free_resources() {
    if (TObjNpcHHM00__body_texture_gvm_handle != 0) {
        release_texture_list((GinjaTextureList *)TObjNpcHHM00__body_texture_gvm_handle);
        TAdSinglePlyChrSelectGC::safe_free(TObjNpcHHM00__body_texture_gvm_handle);
        TObjNpcHHM00__body_texture_gvm_handle = 0;
    }
    if (TObjNpcHHM00__model_object != 0) {
        TLobby::free_nodes_with_id(TObjNpcHHM00__model_object);
        TObjNpcHHM00__model_object = 0;
    }
}

void TObjNpcHHM00::load_resources() {
    TObjNpcHHM00__model_object = create_named_object((s32)"npc_a00_data.rel");
    TObjNpcHHM00__body_texture_gvm_handle = (u32)load_gvm_texture_file((s32)"n_a00_w_body.gvm");
}

TObjNpcHHM00::~TObjNpcHHM00() {}

TObjNpcHHM00 *TObjNpcHHM00__ct(TObjNpcHHM00 *npc, TObjControl *control, void *set_data) {
    npc->construct_male_npc_base();
    *(s32 **)((u8 *)npc + 0x18) = __vt__12TObjNpcHHM00;
    npc->m_name = TObjNpcHHM00__name;
    npc->apply_set_data(set_data);
    ((TObjPlayer *)npc)->init_position_vectors();
    npc->model = *(void **)TObjNpcHHM00__model_object;
    npc->texlist = TObjNpcHHM00__body_texture_gvm_handle;
    npc->setup_common();
    return npc;
}
