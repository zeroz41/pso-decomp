#include "types.h"
#include "pso/object/TObjControl.h"
#include "pso/system/task/TMainTask.h"
#include "pso/npc/TObjNpcARW00.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/unk/text_800F9B84.h"
#include "pso/npc/TUnk_804A8640.h"
#include "pso/unk/TLobby.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcFemaleBase.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/SoundEffect.h"

void *TObjNpcARW00::create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcARW00(control, set_data);
}

const char *TObjNpcARW00::name = "TObjNpcARW00";

extern "C" {
uaddr TObjNpcARW00::static_model;
NJS_TEXLIST *TObjNpcARW00::gvm_texture_handle;
void release_texture_list(void*);

void TObjNpcARW00::free_resources() {
    if (gvm_texture_handle != NULL) {
        release_texture_list(gvm_texture_handle);
        TAdSinglePlyChrSelectGC::safe_free((uaddr)gvm_texture_handle);
        gvm_texture_handle = NULL;
    }
    if ((u32) static_model != 0U) {
        TLobby::free_nodes_with_id((uaddr)((void*)static_model));
        static_model = 0U;
    }
}

void TObjNpcARW00::load_resources() {
    static_model = (u32)create_named_object("npc_f00_data.rel");
    gvm_texture_handle = load_gvm_texture_file("n_f00_w_body.gvm");
}

}
TObjNpcARW00::~TObjNpcARW00() {}


TObjNpcARW00::TObjNpcARW00(TObject *parent, void *arg2) : TUnk_804A8640(parent) {
    *(s32 *)((s8 *)this + 0) = (saddr) name;
    ((TObjNpcARW00 *)this)->apply_set_data(arg2);
    init_position_vectors();
    *(s32 *)((s8 *)this + 0x34) = (s32) *(*(s32 * *)&static_model);
    ((TObjNpcARW00 *)this)->texlist = gvm_texture_handle;
    ((TObjNpcBase *)this)->setup_common();
}

void TObjNpcARW00::play_voice() {
    saddr arg0 = (saddr)this;
    play_sound_effect(0x40004C15, (void *)(arg0 + 0x38), 0, 0);
}

