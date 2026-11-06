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
u32 TObjNpcHRM00__named_object_resource;
u32 TObjNpcHRM00__body_texture_gvm;

extern "C" s32 __vt__12TObjNpcHRM00[];

void *TObjNpcHRM00__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    void *npc = TObject::operator new(sizeof(TObjNpcHRM00));
    if (npc != NULL) {
        npc = TObjNpcHRM00__ct((TObjNpcHRM00 *)npc, control, set_data);
    }
    return npc;
}

void TObjNpcHRM00::destroy_resources() {
    if (TObjNpcHRM00__body_texture_gvm != 0) {
        release_texture_list((GinjaTextureList *)TObjNpcHRM00__body_texture_gvm);
        TAdSinglePlyChrSelectGC::safe_free(TObjNpcHRM00__body_texture_gvm);
        TObjNpcHRM00__body_texture_gvm = 0;
    }
    if (TObjNpcHRM00__named_object_resource != 0) {
        TLobby::free_nodes_with_id(TObjNpcHRM00__named_object_resource);
        TObjNpcHRM00__named_object_resource = 0;
    }
}

void TObjNpcHRM00::load_resources() {
    TObjNpcHRM00__named_object_resource = create_named_object((s32)"npc_d00_data.rel");
    TObjNpcHRM00__body_texture_gvm = (u32)load_gvm_texture_file((s32)"n_d00_w_body.gvm");
}

TObjNpcHRM00::~TObjNpcHRM00() {}

TObjNpcHRM00 *TObjNpcHRM00__ct(TObjNpcHRM00 *npc, TObjControl *control, void *set_data) {
    npc->construct_male_npc_base();
    *(s32 **)((u8 *)npc + 0x18) = __vt__12TObjNpcHRM00;
    npc->m_name = TObjNpcHRM00__name;
    npc->apply_set_data(set_data);
    ((TObjPlayer *)npc)->init_position_vectors();
    npc->model = *(void **)TObjNpcHRM00__named_object_resource;
    npc->texlist = TObjNpcHRM00__body_texture_gvm;
    npc->setup_common();
    return npc;
}
