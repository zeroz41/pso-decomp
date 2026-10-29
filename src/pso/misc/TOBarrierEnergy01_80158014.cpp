#include "types.h"
#include "pso/misc/TLanguage_801E4874.h"
#include "pso/misc/TOBarrierEnergy01_80158014.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TODoorBase.h"
#include "pso/object/TObjMapObject.h"
#include "pso/misc/TOBarrierEnergy01.h"
#include "pso/misc/TODoorAncient01.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_80158078_lbl_80440200 { char value[0x17]; };
typedef char RecoveredGlobal_80158078_lbl_80440200_size[sizeof(RecoveredGlobal_80158078_lbl_80440200) == 0x17 ? 1 : -1];

struct RecoveredGlobal_80158078_lbl_804AFB24 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_80158078_lbl_804AFB24_size[sizeof(RecoveredGlobal_80158078_lbl_804AFB24) == 0x10 ? 1 : -1];

struct RecoveredGlobal_80158188_lbl_804AFB34 {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_80158188___vt__17TOBarrierEnergy01 {
    s32 value;
    u8 remaining[0x50];
};

extern "C" {
s32 TObjFish__sub_8001EDB0(void *, s32);
s32 get_bml_model(void *, s32);
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
void *mem_alloc(u32 size);
extern RecoveredGlobal_80158078_lbl_80440200 lbl_80440200;
extern RecoveredGlobal_80158078_lbl_804AFB24 bm_fs_obj_lazerguard_resource_descriptor;
extern u32 barrier_energy_shared_bml_archive;
extern s32 *TOBarrierEnergy01__texture_lists;
extern s32 barrier_energy_model;
u8 *get_bml_motion(s32, s32);
s32 init_collision_body_parts(void *, void *, int);
void *__ct__10TODoorBaseFP7TObject(void *a0);
extern RecoveredGlobal_80158188_lbl_804AFB34 barrier_energy01_collision_body_parts;
extern s32 __vt__17TOBarrierEnergy01[];
extern s32 lbl_805D2EA0;
extern const f32 lbl_805DB2D8;
extern const f32 lbl_805DB2DC;
extern const f32 lbl_805DB2E0;
extern const f32 lbl_805DB2E4;
void TLobby__sub_8001FE7C(void*, int);
s32 free_collision_body_parts(void *);
s32 __dl__7TObjectFPv(void *);
void mem_free(void *p);

void TOBarrierEnergy01::free_resources() {
    if ((s32 *) TOBarrierEnergy01__texture_lists != NULL) {
        TObjPlayer::free_if_valid(*TOBarrierEnergy01__texture_lists);
        if ((s32 *) TOBarrierEnergy01__texture_lists != NULL) {
            mem_free(TOBarrierEnergy01__texture_lists);
            TOBarrierEnergy01__texture_lists = NULL;
        }
    }
    if ((u32) barrier_energy_shared_bml_archive != 0U) {
        TLobby__sub_8001FE7C((void*)barrier_energy_shared_bml_archive, 1);
        barrier_energy_shared_bml_archive = 0U;
    }
}

void TOBarrierEnergy01::load_resources() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &bm_fs_obj_lazerguard_resource_descriptor.value, 0, 0, 0));
    }
    (*(u8 * *)&barrier_energy_shared_bml_archive) = (unsigned char *) ((void *) var_r0);
    barrier_energy_model = get_bml_model((void *) var_r0, 0);
    (*(s32 *)&TOBarrierEnergy01__texture_lists) = (s32)mem_alloc((u32)((void *)0xC));
    *(u8 **)((s8 *)(*(s32 *)&TOBarrierEnergy01__texture_lists) + 0) = load_gvm_texture_file((s32) &lbl_80440200.value);
    *(s32 *)((s8 *)(*(s32 *)&TOBarrierEnergy01__texture_lists) + 4) = TObjFish__sub_8001EDB0((*(u8 * *)&barrier_energy_shared_bml_archive), 1);
    *(s32 *)((s8 *)(*(s32 *)&TOBarrierEnergy01__texture_lists) + 8) = TObjFish__sub_8001EDB0((*(u8 * *)&barrier_energy_shared_bml_archive), 0);
}

void *__dt__17TOBarrierEnergy01Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__17TOBarrierEnergy01;
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__10TODoorBaseFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

typedef char RecoveredGlobal_80158188_lbl_804AFB34_size[sizeof(RecoveredGlobal_80158188_lbl_804AFB34) == 0x2C ? 1 : -1];
typedef char RecoveredGlobal_80158188___vt__17TOBarrierEnergy01_size[sizeof(RecoveredGlobal_80158188___vt__17TOBarrierEnergy01) == 0x54 ? 1 : -1];
u8 *TOBarrierEnergy01__ct(u8 *arg0, s32 arg1, s32 arg2) {
    __ct__10TODoorBaseFP7TObject((arg0));
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_80158188___vt__17TOBarrierEnergy01 *)&__vt__17TOBarrierEnergy01).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) lbl_805D2EA0;
    ((TOBarrierEnergy01 *)(arg0))->apply_object_set_data((void *)arg2);
    *(s32 *)((s8 *)arg0 + 0x34) = get_bml_model((void *)((void *) ((*(s32 *)&barrier_energy_shared_bml_archive))), 1);
    ((TOBarrierEnergy01 *)arg0)->texlist = (s32) *TOBarrierEnergy01__texture_lists;
    *(u8 **)((s8 *)arg0 + 0xBC) = get_bml_motion((*(s32 *)&barrier_energy_shared_bml_archive), 0);
    *(f32 *)((s8 *)arg0 + 0xB4) = (f32) ((f32) *(u32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0xBC)) + 4) - lbl_805DB2D8);
    ((TOBarrierEnergy01 *)arg0)->m_b8 = (f32) lbl_805DB2DC;
    init_collision_body_parts(arg0, &barrier_energy01_collision_body_parts.value, 1);
    ((TObjCollidable *)arg0)->refresh_collision_body_centers();
    ((TObjPlayer *)arg0)->register_object_by_id();
    ((TOBarrierEnergy01 *)(arg0))->init_door_switch_binding();
    ((TOBarrierEnergy01 *)arg0)->m_c0 = (f32) lbl_805DB2E0;
    *(f32 *)((s8 *)arg0 + 0xC4) = (f32) lbl_805DB2E4;
    return arg0;
}


}
