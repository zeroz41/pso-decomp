#include "types.h"
#include "pso/object/TObjControl.h"
#include "pso/npc/TObjNpcAHM01.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/npc/TObjNpcARM00.h"
#include "pso/unk/text_800F9B84.h"
#include "pso/npc/TUnk_804A9F50.h"

#include "pso/unk/TLobby.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcLappy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/SoundEffect.h"
#include "pso/render/GinjaTexture.h"

#pragma readonly_strings on


const char *TObjNpcAHM01__name = "TObjNpcAHM01";
uaddr TObjNpcAHM01__shared_object;
NJS_TEXLIST *TObjNpcAHM01__texture_handle;

void TObjNpcAHM01::free_resources() {
    if (TObjNpcAHM01__texture_handle != NULL) {
        release_texture_list(TObjNpcAHM01__texture_handle);
        TAdSinglePlyChrSelectGC::safe_free((uaddr)TObjNpcAHM01__texture_handle);
        TObjNpcAHM01__texture_handle = NULL;
    }
    if ((u32) TObjNpcAHM01__shared_object != 0U) {
        TLobby::free_nodes_with_id((uaddr)((void*)TObjNpcAHM01__shared_object));
        TObjNpcAHM01__shared_object = 0U;
    }
}

void TObjNpcAHM01::load_resources() {
    TObjNpcAHM01__shared_object = (u32)create_named_object("npc_c01_data.rel");
    TObjNpcAHM01__texture_handle = load_gvm_texture_file("n_c01_e_body.gvm");
}

TObjNpcAHM01::~TObjNpcAHM01() {}


TObjNpcAHM01::TObjNpcAHM01(TObject *parent, void *arg2) : TUnk_804A9F50(parent) {
    *(s32 *)((s8 *)this + 0) = (saddr) TObjNpcAHM01__name;
    ((TObjNpcAHM01 *)this)->apply_set_data(arg2);
    init_position_vectors();
    *(s32 *)((s8 *)this + 0x34) = (s32) *(*(s32 * *)&TObjNpcAHM01__shared_object);
    ((TObjNpcAHM01 *)this)->texlist = TObjNpcAHM01__texture_handle;
    ((TObjNpcBase *)this)->setup_common();
}

void TObjNpcAHM01::play_voice() {
    saddr arg0 = (saddr)this;
    play_sound_effect(0x40004C15, reinterpret_cast<const Vec *>(arg0 + 0x38), 0, 0);
}

s32 TObjNpcBase::is_target_in_attack_range() { return 0; }


void *TObjNpcARM00__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcARM00(control, set_data);
}

