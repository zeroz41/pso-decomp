#include "types.h"
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
#include "pso/render/GinjaTexture.h"

const char *TObjNpcARW00__name = "TObjNpcARW00";

extern "C" {
uaddr TObjNpcARW00__static_model;
NJS_TEXLIST *TObjNpcARW00__gvm_texture_handle;

void TObjNpcARW00::free_resources() {
    if (TObjNpcARW00__gvm_texture_handle != NULL) {
        release_texture_list(TObjNpcARW00__gvm_texture_handle);
        TAdSinglePlyChrSelectGC::safe_free((uaddr)TObjNpcARW00__gvm_texture_handle);
        TObjNpcARW00__gvm_texture_handle = NULL;
    }
    if ((u32) TObjNpcARW00__static_model != 0U) {
        TLobby::free_nodes_with_id((uaddr)((void*)TObjNpcARW00__static_model));
        TObjNpcARW00__static_model = 0U;
    }
}

void TObjNpcARW00::load_resources() {
    TObjNpcARW00__static_model = (u32)create_named_object("npc_f00_data.rel");
    TObjNpcARW00__gvm_texture_handle = load_gvm_texture_file("n_f00_w_body.gvm");
}

}
TObjNpcARW00::~TObjNpcARW00() {}


TObjNpcARW00::TObjNpcARW00(TObject *parent, void *arg2) : TUnk_804A8640(parent) {
    *(s32 *)((s8 *)this + 0) = (saddr) TObjNpcARW00__name;
    ((TObjNpcARW00 *)this)->apply_set_data(arg2);
    init_position_vectors();
    *(s32 *)((s8 *)this + 0x34) = (s32) *(*(s32 * *)&TObjNpcARW00__static_model);
    ((TObjNpcARW00 *)this)->texlist = TObjNpcARW00__gvm_texture_handle;
    ((TObjNpcBase *)this)->setup_common();
}

void TObjNpcARW00::play_voice() {
    saddr arg0 = (saddr)this;
    play_sound_effect(0x40004C15, (void *)(arg0 + 0x38), 0, 0);
}

