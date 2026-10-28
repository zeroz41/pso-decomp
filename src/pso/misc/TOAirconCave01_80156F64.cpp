#include "types.h"
#include "pso/misc/TOAirconCave01_80156F64.h"
#include "pso/misc/TUnk_804AFBF8.h"
#include "pso/misc/TOAirconCave01.h"
#include "pso/misc/TOKey.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_80156F9C_lbl_804AF910 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_80156F9C_lbl_804AF910_size[sizeof(RecoveredGlobal_80156F9C_lbl_804AF910) == 0x10 ? 1 : -1];

struct RecoveredGlobal_80157044___vt__14TOAirconCave01 {
    s32 value;
    u8 remaining[0x34];
};

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_80156F9C_lbl_804AF910 TOAirconCave01__shared_resource_desc;
extern u32 TOAirconCave01__model_archive;
s32 init_map_object_base(void *, void *);
extern s32 __vt__14TOAirconCave01[];
extern s32 lbl_805D2E8C;
extern const f32 lbl_805DB2B8;
extern const f32 lbl_805DB2BC;
void TLobby__sub_8001FE7C(void*, int);
void __dl__7TObjectFPv(void *);

void TOAirconCave01::release_static_resource() {
    if ((u32) TOAirconCave01__model_archive != 0U) {
        TLobby__sub_8001FE7C((void*)TOAirconCave01__model_archive, 1);
        TOAirconCave01__model_archive = 0U;
    }
}

void TOAirconCave01::load_shared_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &TOAirconCave01__shared_resource_desc.value, 0, 0, 0));
    }
    (*(s32 *)&TOAirconCave01__model_archive) = var_r0;
}

void *__dt__14TOAirconCave01Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__14TOAirconCave01;
        ((TUnk_804AFBF8 *)arg0)->destroy_key_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_80157044___vt__14TOAirconCave01_size[sizeof(RecoveredGlobal_80157044___vt__14TOAirconCave01) == 0x38 ? 1 : -1];
u8 *TOAirconCave01__ct(u8 *aircon_cave01, s32 arg1, s32 arg2) {
    init_map_object_base((void *)aircon_cave01, (void *)arg1);
    *(s32 **)((s8 *)aircon_cave01 + 0x18) = &(*(RecoveredGlobal_80157044___vt__14TOAirconCave01 *)&__vt__14TOAirconCave01).value;
    *(s32 *)((s8 *)aircon_cave01 + 0) = (s32) lbl_805D2E8C;
    ((TOAirconCave01 *)(aircon_cave01))->apply_object_set_data((void *)arg2);
    *(s32 *)((s8 *)aircon_cave01 + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TOAirconCave01__model_archive) + 0x42C)) + 8);
    ((TOAirconCave01 *)aircon_cave01)->texture_id = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TOAirconCave01__model_archive) + 0x42C)) + 0xC);
    ((TOAirconCave01 *)aircon_cave01)->m_c0 = (f32) lbl_805DB2B8;
    *(f32 *)((s8 *)aircon_cave01 + 0xC4) = (f32) lbl_805DB2BC;
    return aircon_cave01;
}

}
