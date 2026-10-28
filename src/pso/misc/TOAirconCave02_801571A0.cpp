#include "types.h"
#include "pso/misc/TOAirconCave02_801571A0.h"
#include "pso/misc/TUnk_804AFBF8.h"
#include "pso/misc/TOAirconCave02.h"
#include "pso/misc/TOKey.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_801571D8_lbl_804AF960 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_801571D8_lbl_804AF960_size[sizeof(RecoveredGlobal_801571D8_lbl_804AF960) == 0x10 ? 1 : -1];

struct RecoveredGlobal_80157280___vt__14TOAirconCave02 {
    s32 value;
    u8 remaining[0x34];
};

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_801571D8_lbl_804AF960 TOAirconCave02__shared_resource_desc;
extern u32 TOAirconCave02__bml_resource;
s32 init_map_object_base(void *, void *);
extern s32 __vt__14TOAirconCave02[];
extern s32 lbl_805D2E94;
extern const f32 lbl_805DB2C0;
extern const f32 lbl_805DB2C4;
void TLobby__sub_8001FE7C(void*, int);
void __dl__7TObjectFPv(void *);

void TOAirconCave02::release_static_resource() {
    if ((u32) TOAirconCave02__bml_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TOAirconCave02__bml_resource, 1);
        TOAirconCave02__bml_resource = 0U;
    }
}

void TOAirconCave02::load_shared_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &TOAirconCave02__shared_resource_desc.value, 0, 0, 0));
    }
    (*(s32 *)&TOAirconCave02__bml_resource) = var_r0;
}

void *__dt__14TOAirconCave02Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__14TOAirconCave02;
        ((TUnk_804AFBF8 *)arg0)->destroy_key_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_80157280___vt__14TOAirconCave02_size[sizeof(RecoveredGlobal_80157280___vt__14TOAirconCave02) == 0x38 ? 1 : -1];
u8 *TOAirconCave02__ct(u8 *aircon_cave02, s32 arg1, s32 arg2) {
    init_map_object_base((void *)aircon_cave02, (void *)arg1);
    *(s32 **)((s8 *)aircon_cave02 + 0x18) = &(*(RecoveredGlobal_80157280___vt__14TOAirconCave02 *)&__vt__14TOAirconCave02).value;
    *(s32 *)((s8 *)aircon_cave02 + 0) = (s32) lbl_805D2E94;
    ((TOAirconCave02 *)(aircon_cave02))->apply_object_set_data((void *)arg2);
    *(s32 *)((s8 *)aircon_cave02 + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TOAirconCave02__bml_resource) + 0x42C)) + 8);
    ((TOAirconCave02 *)aircon_cave02)->texlist = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TOAirconCave02__bml_resource) + 0x42C)) + 0xC);
    ((TOAirconCave02 *)aircon_cave02)->m_c0 = (f32) lbl_805DB2C0;
    *(f32 *)((s8 *)aircon_cave02 + 0xC4) = (f32) lbl_805DB2C4;
    return aircon_cave02;
}

}
