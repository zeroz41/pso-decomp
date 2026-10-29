#include "types.h"
#include "pso/object/TObjMapObject.h"
#include "pso/misc/TOAirconCave02.h"
#include "pso/misc/TOKey.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_801571D8_lbl_804AF960 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_801571D8_lbl_804AF960_size[sizeof(RecoveredGlobal_801571D8_lbl_804AF960) == 0x10 ? 1 : -1];

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_801571D8_lbl_804AF960 TOAirconCave02__shared_resource_desc;
extern u32 TOAirconCave02__bml_resource;
extern const char *lbl_805D2E94;
extern const f32 lbl_805DB2C0;
extern const f32 lbl_805DB2C4;
void TLobby__sub_8001FE7C(void*, int);
}

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

TOAirconCave02::~TOAirconCave02() {}

TOAirconCave02::TOAirconCave02(TObject *parent, void *set_data) : TObjMapObject(parent) {
    m_name = lbl_805D2E94;
    apply_object_set_data(set_data);
    model = (void *)*(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TOAirconCave02__bml_resource) + 0x42C)) + 8);
    texlist = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TOAirconCave02__bml_resource) + 0x42C)) + 0xC);
    m_c0 = lbl_805DB2C0;
    model_radius = lbl_805DB2C4;
}
