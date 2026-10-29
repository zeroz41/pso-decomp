#include "types.h"
#include "pso/object/TObjMapObject.h"
#include "pso/misc/TOAirconCave01.h"
#include "pso/misc/TOKey.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_80156F9C_lbl_804AF910 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_80156F9C_lbl_804AF910_size[sizeof(RecoveredGlobal_80156F9C_lbl_804AF910) == 0x10 ? 1 : -1];

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_80156F9C_lbl_804AF910 TOAirconCave01__shared_resource_desc;
extern u32 TOAirconCave01__model_archive;
extern const char *lbl_805D2E8C;
extern const f32 lbl_805DB2B8;
extern const f32 lbl_805DB2BC;
void TLobby__sub_8001FE7C(void*, int);
}

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

TOAirconCave01::~TOAirconCave01() {}

TOAirconCave01::TOAirconCave01(TObject *parent, void *set_data) : TObjMapObject(parent) {
    m_name = lbl_805D2E8C;
    apply_object_set_data(set_data);
    model = (void *)*(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TOAirconCave01__model_archive) + 0x42C)) + 8);
    texlist = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TOAirconCave01__model_archive) + 0x42C)) + 0xC);
    m_c0 = lbl_805DB2B8;
    model_radius = lbl_805DB2BC;
}
