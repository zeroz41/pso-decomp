#include "types.h"
#include "pso/boss/TBoss6Rock_80354A44.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/boss/TBoss6Rock.h"
#include "pso/misc/TLobby.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern char lbl_804791B8[];
extern char lbl_804791C8[];
extern char lbl_804791D8[];
extern char lbl_804791E8[];
extern char lbl_804791F8[];
extern char lbl_8047920C[];
extern char lbl_80479220[];
extern char lbl_80479238[];
extern const char *boss06_rock_dat_model_names[8];
extern BmlResourceDescriptor boss6_rock_resource_descriptor;
extern const char *boss06_rock_dat_motion_names[1];

extern "C" {
s32 create__10TBoss6RockFPv(s32);
extern s32 TBoss6Rock__instance_table[];
extern u32 TBoss6Rock__data_805D6EF0;
extern u32 TBoss6Rock__data_805D6EF4;
extern int TBoss6Rock__data_805D6EF8;
u32 load_resource_from_descriptor(u32, s32, void *, s32, s32, s32);
u8 *load_gvm_texture_file(s32 arg0);
void TBoss6Rock__sub_80354188(void);
extern u8 lbl_80479298[];
extern s32 lbl_805D6EFC;
void TLobby__sub_8001FE7C(void*, int);
s32 release_texture_list(void*);

void TBoss6Rock__sub_80354A44(void) { TBoss6Rock__data_805D6EF8 = 0; }

void TBoss6Rock::create_rock_pool(s32 arg0) {
    s32 i;
    if (TBoss6Rock__data_805D6EF0 == 0 || TBoss6Rock__data_805D6EF4 == 0) {
        return;
    }
    (*(s32 *)&TBoss6Rock__data_805D6EF8) = arg0;
    for (i = 0; i < 0x20; i++) {
        TBoss6Rock__instance_table[i] = create__10TBoss6RockFPv(i);
    }
}

void TBoss6Rock::free_data() {
    if ((u32) TBoss6Rock__data_805D6EF0 != 0U) {
        TLobby__sub_8001FE7C((void*)TBoss6Rock__data_805D6EF0, 1);
        TBoss6Rock__data_805D6EF0 = 0U;
    }
    if ((u32) TBoss6Rock__data_805D6EF4 != 0U) {
        release_texture_list((void*)TBoss6Rock__data_805D6EF4);
        TAdSinglePlyChrSelectGC::safe_free(TBoss6Rock__data_805D6EF4);
        TBoss6Rock__data_805D6EF4 = 0U;
    }
}
void TBoss6Rock::load_resources() {
    u32 r;
    s32 i;
    r = (int)::operator new(0x440);
    if (r != 0) {
        r = load_resource_from_descriptor(r, 5, &boss6_rock_resource_descriptor, 0, 0, 0);
    }
    TBoss6Rock__data_805D6EF0 = r;
    TBoss6Rock__data_805D6EF4 = (u32)load_gvm_texture_file((s32)lbl_80479298);
    if (TBoss6Rock__data_805D6EF0 == 0 || TBoss6Rock__data_805D6EF4 == 0) {
        return;
    }
    TBoss6Rock__sub_80354188();
    for (i = 0; i < 0x20; i++) {
        TBoss6Rock__instance_table[i] = 0;
    }
    lbl_805D6EFC = (s32)*(f32 *)((u8 *)TLobby::dispatch_shared_handler_a(0x2C) + 0xC);
    if (lbl_805D6EFC < 1) {
        lbl_805D6EFC = 0x14;
    }
}

__declspec(section ".data") const char *boss06_rock_dat_model_names[8] = { lbl_804791B8, lbl_804791C8, lbl_804791D8, lbl_804791E8, lbl_804791F8, lbl_8047920C, lbl_80479220, NULL };
BmlResourceDescriptor boss6_rock_resource_descriptor = { lbl_80479238, boss06_rock_dat_model_names, boss06_rock_dat_motion_names, 7, 0 };
__declspec(section ".sdata") const char *boss06_rock_dat_motion_names[1] = { NULL };
}
