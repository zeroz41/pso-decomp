#include "types.h"
#include "pso/object/TObjControl.h"
#include "pso/npc/TObjNpcARM00.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/npc/TObjNpcARW00.h"
#include "pso/unk/text_800F9B84.h"
#include "pso/npc/TObjNpcMale.h"

#include "pso/unk/TLobby.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcLappy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"

#pragma readonly_strings on

void *TObjNpcARM00::create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcARM00(control, set_data);
}

const char *TObjNpcARM00::name = "TObjNpcARM00";
uaddr TObjNpcARM00::model_resource;
NJS_TEXLIST *TObjNpcARM00::texture_list;

extern "C" {
s32 play_sound_effect(s32, s32, s32, s32);
void release_texture_list(void*);

void TObjNpcARM00::free_resources() {
    if (texture_list != NULL) {
        release_texture_list(texture_list);
        TAdSinglePlyChrSelectGC::safe_free((uaddr)texture_list);
        texture_list = NULL;
    }
    if ((u32) model_resource != 0U) {
        TLobby::free_nodes_with_id((uaddr)((void*)model_resource));
        model_resource = 0U;
    }
}

void TObjNpcARM00::load_resources() {
    model_resource = (u32)create_named_object("npc_e00_data.rel");
    texture_list = load_gvm_texture_file("n_e00_w_body.gvm");
}

}
TObjNpcARM00::~TObjNpcARM00() {}

TObjNpcARM00::TObjNpcARM00(TObject *parent, void *arg2) : TObjNpcMale(parent) {
    *(s32 *)((s8 *)this + 0) = (saddr) name;
    ((TObjNpcARM00 *)this)->apply_set_data(arg2);
    init_position_vectors();
    *(s32 *)((s8 *)this + 0x34) = (s32) *(*(s32 * *)&model_resource);
    ((TObjNpcARM00 *)this)->texlist = texture_list;
    ((TObjNpcBase *)this)->setup_common();
}

void TObjNpcARM00::play_voice() {
    saddr arg0 = (saddr)this;
    play_sound_effect(0x40003B08, arg0 + 0x38, 0, 0);
}

