#include "types.h"
#include "pso/object/TObjControl.h"
#include "pso/npc/TObjNpcAHM01.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/npc/TObjNpcARM00.h"
#include "pso/unk/text_800F9B84.h"
#include "pso/npc/TObjNpcMale.h"

#include "pso/unk/TLobby.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcLappy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/SoundEffect.h"

#pragma readonly_strings on

void *TObjNpcAHM01::create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcAHM01(control, set_data);
}

const char *TObjNpcAHM01::name = "TObjNpcAHM01";
uaddr TObjNpcAHM01::shared_object;
NJS_TEXLIST *TObjNpcAHM01::texture_handle;

extern "C" {
void release_texture_list(void*);

void TObjNpcAHM01::free_resources() {
    if (texture_handle != NULL) {
        release_texture_list(texture_handle);
        TAdSinglePlyChrSelectGC::safe_free((uaddr)texture_handle);
        texture_handle = NULL;
    }
    if ((u32) shared_object != 0U) {
        TLobby::free_nodes_with_id((uaddr)((void*)shared_object));
        shared_object = 0U;
    }
}

void TObjNpcAHM01::load_resources() {
    shared_object = (u32)create_named_object("npc_c01_data.rel");
    texture_handle = load_gvm_texture_file("n_c01_e_body.gvm");
}

}
TObjNpcAHM01::~TObjNpcAHM01() {}

TObjNpcAHM01::TObjNpcAHM01(TObject *parent, void *arg2) : TObjNpcMale(parent) {
    *(s32 *)((s8 *)this + 0) = (saddr) name;
    ((TObjNpcAHM01 *)this)->apply_set_data(arg2);
    init_position_vectors();
    *(s32 *)((s8 *)this + 0x34) = (s32) *(*(s32 * *)&shared_object);
    ((TObjNpcAHM01 *)this)->texlist = texture_handle;
    ((TObjNpcBase *)this)->setup_common();
}

void TObjNpcAHM01::play_voice() {
    saddr arg0 = (saddr)this;
    play_sound_effect(0x40004C15, (void *)(arg0 + 0x38), 0, 0);
}

s32 TObjNpcBase::is_target_in_attack_range() { return 0; }

