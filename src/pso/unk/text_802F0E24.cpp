#include "types.h"
#include "pso/unk/text_802F0E24.h"
#include "pso/misc/TLobby.h"
#include "pso/TParticleCtrl.h"
#include "pso/system/BmlResourceDescriptor.h"

#define ARRAY_COUNT(arr) (sizeof(arr) / sizeof((arr)[0]))

struct BmlModelEntry {
    u32 flags;
    s32 unk4;
    void *model;
    void *texture_list;
};

struct BmlResource {
    u8 pad0[0x42C];
    BmlModelEntry *models;
};

extern "C" {
void release_texture_list(void *);
void TLobby__sub_8001FE7C(void *, int);
void *load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
}

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
void *boss7_common_bml_resource;
void *boss7_common_texture_list;

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
    TLobby__sub_8001FE7C(boss7_common_bml_resource, 1);
    boss7_common_bml_resource = 0;
}

void load_boss7_common_resources(void) {
    void *p;

    p = ::operator new(0x440);
    if (p != NULL) {
        p = load_resource_from_descriptor(p, 5, &boss7_common_resource_descriptor, 0, 0, 0);
    }

    boss7_common_bml_resource = p;
    boss7_common_texture_list = ((BmlResource *)p)->models[0].texture_list;

    TLobby::load_texture_pvm_file("obj_boss7_common.gvm", (s32)boss7_common_texture_list);
    TParticleCtrl::init_heap((void *)0x50000);
}
