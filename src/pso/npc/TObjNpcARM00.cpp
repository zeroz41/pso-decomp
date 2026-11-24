#include "pso/system/SoundEffect.h"
#include "types.h"
#include "pso/object/TObjControl.h"
#include "pso/npc/TObjNpcARM00.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/npc/TObjNpcARW00.h"
#include "pso/unk/text_800F9B84.h"
#include "pso/npc/TUnk_804A9F50.h"

#include "pso/unk/TLobby.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcLappy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"

#pragma readonly_strings on


const char *TObjNpcARM00__name = "TObjNpcARM00";
uaddr TObjNpcARM00__model_resource;
NJS_TEXLIST *TObjNpcARM00__texture_list;

extern "C" {
void release_texture_list(void*);

void TObjNpcARM00::free_resources() {
    if (TObjNpcARM00__texture_list != NULL) {
        release_texture_list(TObjNpcARM00__texture_list);
        TAdSinglePlyChrSelectGC::safe_free((uaddr)TObjNpcARM00__texture_list);
        TObjNpcARM00__texture_list = NULL;
    }
    if ((u32) TObjNpcARM00__model_resource != 0U) {
        TLobby::free_nodes_with_id((uaddr)((void*)TObjNpcARM00__model_resource));
        TObjNpcARM00__model_resource = 0U;
    }
}

void TObjNpcARM00::load_resources() {
    TObjNpcARM00__model_resource = (u32)create_named_object("npc_e00_data.rel");
    TObjNpcARM00__texture_list = load_gvm_texture_file("n_e00_w_body.gvm");
}

}
TObjNpcARM00::~TObjNpcARM00() {}


TObjNpcARM00::TObjNpcARM00(TObject *parent, void *arg2) : TUnk_804A9F50(parent) {
    *(s32 *)((s8 *)this + 0) = (saddr) TObjNpcARM00__name;
    ((TObjNpcARM00 *)this)->apply_set_data(arg2);
    init_position_vectors();
    *(s32 *)((s8 *)this + 0x34) = (s32) *(*(s32 * *)&TObjNpcARM00__model_resource);
    ((TObjNpcARM00 *)this)->texlist = TObjNpcARM00__texture_list;
    ((TObjNpcBase *)this)->setup_common();
}

void TObjNpcARM00::play_voice() {
    saddr arg0 = (saddr)this;
    play_sound_effect(0x40003B08, reinterpret_cast<const Vec *>(arg0 + 0x38), 0, 0);
}


void *TObjNpcARW00__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcARW00(control, set_data);
}

