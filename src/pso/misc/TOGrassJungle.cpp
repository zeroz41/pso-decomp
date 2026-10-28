#include "types.h"
#include "pso/misc/TLanguage_801E4874.h"
#include "pso/misc/TOGrassJungle_8029CD90.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/misc/TOGrassJungle.h"
#include "pso/misc/TMotorcycle.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern char lbl_80465938[];
extern char lbl_80465950[];
extern char lbl_80465964[];
extern const char *bm_o_grass_jungle_model_names[3];
extern BmlResourceDescriptor ograss_jungle_resource_descriptor;
extern const char *bm_o_grass_jungle_motion_names[1];

struct RecoveredGlobal_8029CD0C_lbl_8046598C { char value[0x13]; };
typedef char RecoveredGlobal_8029CD0C_lbl_8046598C_size[sizeof(RecoveredGlobal_8029CD0C_lbl_8046598C) == 0x13 ? 1 : -1];

struct RecoveredGlobal_8029CD0C_lbl_804DC534 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_8029CD0C_lbl_804DC534_size[sizeof(RecoveredGlobal_8029CD0C_lbl_804DC534) == 0x10 ? 1 : -1];

extern "C" {
s32 get_bml_model(void *, s32);
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_8029CD0C_lbl_8046598C lbl_8046598C;
extern u32 TOGrassJungle__bml_resource;
extern u32 TOGrassJungle__grass_gvm_texture;
extern const f32 lbl_805DDD28;
extern const f32 lbl_805DDD2C;
void TLobby__sub_8001FE7C(void*, int);
s32 release_texture_list(void*);
void *__nw__7TObjectFUl(int);

extern void *tl_05;

void *TOGrassJungle__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x94);
    if (o != NULL) {
        o = TOGrassJungle__ct((TOGrassJungle *)((u8 *)o), (s32)tl_05, (s32)arg0);
    }
    return o;
}

void TOGrassJungle::release_static_instance() {
    if ((u32) TOGrassJungle__grass_gvm_texture != 0U) {
        release_texture_list((void*)TOGrassJungle__grass_gvm_texture);
        TAdSinglePlyChrSelectGC::safe_free(TOGrassJungle__grass_gvm_texture);
        TOGrassJungle__grass_gvm_texture = 0U;
    }
    if ((u32) TOGrassJungle__bml_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TOGrassJungle__bml_resource, 1);
        TOGrassJungle__bml_resource = 0U;
    }
}
void TOGrassJungle::load_resources() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &ograss_jungle_resource_descriptor, 0, 0, 0));
    }
    (*(u8 * *)&TOGrassJungle__bml_resource) = (unsigned char *) ((void *) var_r0);
    (*(u8 * *)&TOGrassJungle__grass_gvm_texture) = load_gvm_texture_file((s32) &lbl_8046598C.value);
    TMotorcycle::add_entry(0x3F, (int) (get_bml_model((*(u8 * *)&TOGrassJungle__bml_resource), 0)), (int) ((*(u8 * *)&TOGrassJungle__grass_gvm_texture)), lbl_805DDD28, lbl_805DDD2C);
}

__declspec(section ".data") const char *bm_o_grass_jungle_model_names[3] = { lbl_80465938, lbl_80465950, NULL };
BmlResourceDescriptor ograss_jungle_resource_descriptor = { lbl_80465964, bm_o_grass_jungle_model_names, bm_o_grass_jungle_motion_names, 2, 0 };
__declspec(section ".sdata") const char *bm_o_grass_jungle_motion_names[1] = { NULL };
}
