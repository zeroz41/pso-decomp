#include "types.h"
#include "pso/system/BmlResource.h"
#include "pso/unk/text_802F0E24.h"
#include "pso/unk/TLobby.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/render/GinjaTexture.h"

#define ARRAY_COUNT(arr) (sizeof(arr) / sizeof((arr)[0]))


#pragma readonly_strings on
const char *bm_obj_boss7_common_model_names[] = {
    "boss07_001_obj001.gj",
    "boss07_001_obj002.gj",
    "boss07_001_obj004.gj",
    "boss07_002_obj001.gj",
    "boss07_002_obj002.gj",
    "boss07_002_obj003.gj",
    "boss07_002_obj004.gj",
    "boss07_003_obj001.gj",
    "boss07_003_obj002.gj",
    "boss07_003_obj004.gj",
    "boss07_004_obj001.gj",
    "boss07_004_obj002.gj",
    "boss07_004_obj004.gj",
    "boss07_005_obj001.gj",
    "boss07_005_obj002.gj",
    "boss07_005_obj003.gj",
    "boss07_005_obj004.gj",
    "de_obj999_mtn060_bosstenkyu01.gj",
    "de_obj999_mtn061_bosstenkyu02.gj",
    "de_obj999_mtn062_bosstenkyu03.gj",
    NULL,
};

const char *bm_obj_boss7_common_motion_names[] = {
    "mtn060_bosstenkyu01.njm",
    "mtn061_bosstenkyu02.njm",
    "mtn062_bosstenkyu03.njm",
    NULL,
};

BmlResourceDescriptor boss7_common_resource_descriptor = {
    "bm_obj_boss7_common.bml",
    bm_obj_boss7_common_model_names,
    bm_obj_boss7_common_motion_names,
    ARRAY_COUNT(bm_obj_boss7_common_model_names) - 1,
    ARRAY_COUNT(bm_obj_boss7_common_motion_names) - 1
};

u32 boss7_dermt_slot_table[7];
BmlResource *boss7_common_bml_resource;
NJS_TEXLIST *boss7_common_texture_list;
__declspec(section ".sdata2") const f32 boss7_tunnel_max_scroll_speed = 9.259259f;

void free_boss7_common_resources(void) {
    s32 i;
    TParticleCtrl::free_heap();
    for (i = 0; i < 7; i++) {
        boss7_dermt_slot_table[i] = 0;
    }
    if (boss7_common_texture_list != 0) {
        release_texture_list(boss7_common_texture_list);
        boss7_common_texture_list = 0;
    }
    delete boss7_common_bml_resource;
    boss7_common_bml_resource = 0;
}

void load_boss7_common_resources(void) {
    BmlResource *resource = new BmlResource(5, &boss7_common_resource_descriptor, 0, 0, NULL);
    boss7_common_bml_resource = resource;
    boss7_common_texture_list = resource->models[0].texlist;

    TLobby::load_texture_pvm_file("obj_boss7_common.gvm", boss7_common_texture_list);
    TParticleCtrl::init_heap(0x50000);
}
