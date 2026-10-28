#include "types.h"
#include "pso/misc/TLobby_80082048.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/system/vector.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/misc/TUnk_8048E1A4.h"
#include "pso/system/BmlResourceDescriptor.h"

extern char lbl_80438E60[];
extern char lbl_80438E74[];
extern char lbl_80438E80[];
extern char lbl_80438E94[];
extern const char *bm_eff_ice_model_names[3];
extern const char *bm_eff_ice_motion_names[2];
extern BmlResourceDescriptor enemy_freeze_ice_resource_descriptor;

struct RecoveredGlobal_80082080_lbl_8048E194 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_80082080_lbl_8048E194_size[sizeof(RecoveredGlobal_80082080_lbl_8048E194) == 0x10 ? 1 : -1];

#include <stddef.h>
#include "pso/misc/TLobby.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
struct RecoveredFields_8008213C_arg0 {
    u8 unknown_0[0x18];
    s32 * field_18;
    u8 unknown_1C[0x18];
    s32 field_34;
    u8 unknown_38[0x28];
    s32 field_60;
    u8 unknown_64[0x4];
    f32 field_68;
    f32 field_6C;
    f32 field_70;
    u8 unknown_74[0x2C0];
    s32 field_334;
    f32 field_338;
    s32 field_33C;
    f32 field_340;
    f32 field_344;
    f32 field_348;
    f32 field_34C;
    s32 field_350;
    s32 field_354;
    s16 field_358;
};

struct RecoveredFields_8008213C_arg2 {
    u8 unknown_0[0xC];
    f32 field_C;
};

struct RecoveredFields_8008213C_arg1 {
    u8 unknown_0[0x60];
    s32 field_60;
    u8 unknown_64[0x40];
    u8 * field_A4;
};

struct RecoveredFields_8008213C_temp_r3 {
    u8 unknown_0[0x10];
    f32 field_10;
};

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern u32 freeze_shell_bml_resource;
s32 __ct__13TUnk_804806E8FP7TObject(void *, void *);
s16 get_entity_id(void *);
s32 get_bml_model(void *, int);
u8 *get_quest_id__12TQuestListVMFv(void *);
void *create_particle_emitter(void *pos, s32 id);
extern s32 lbl_8048E1A4[];
extern s32 tl_05;
extern const f32 lbl_805D9378;
extern const f32 lbl_805D9398;
extern const f32 lbl_805D939C;
extern const f32 lbl_805D93A0;
void TLobby__sub_8001FE7C(void*, int);
void __dl__7TObjectFPv(void *);

void TLobby::destroy_global_singleton() {
    if ((u32) freeze_shell_bml_resource != 0U) {
        TLobby__sub_8001FE7C((void*)freeze_shell_bml_resource, 1);
        freeze_shell_bml_resource = 0U;
    }
}

void TLobby::load_freeze_ice_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 5, &enemy_freeze_ice_resource_descriptor, 0, 0, 0));
    }
    (*(s32 *)&freeze_shell_bml_resource) = var_r0;
}

void *__dt__13TUnk_8048E1A4Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_8048E1A4;
        if (((TUnk_8048E1A4 *)arg0)->m_350 != NULL) { TBoss4Type2::request_destroy((u32)(((TUnk_8048E1A4 *)arg0)->m_350)); }
        ((TUnk_804806E8 *)arg0)->destroy_motion_object(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

#pragma push
#pragma fp_contract on
typedef char RecoveredFields_8008213C_arg0_18_offset[offsetof(RecoveredFields_8008213C_arg0, field_18) == 0x18 ? 1 : -1];
typedef char RecoveredFields_8008213C_arg0_34_offset[offsetof(RecoveredFields_8008213C_arg0, field_34) == 0x34 ? 1 : -1];
typedef char RecoveredFields_8008213C_arg0_60_offset[offsetof(RecoveredFields_8008213C_arg0, field_60) == 0x60 ? 1 : -1];
typedef char RecoveredFields_8008213C_arg0_68_offset[offsetof(RecoveredFields_8008213C_arg0, field_68) == 0x68 ? 1 : -1];
typedef char RecoveredFields_8008213C_arg0_6C_offset[offsetof(RecoveredFields_8008213C_arg0, field_6C) == 0x6C ? 1 : -1];
typedef char RecoveredFields_8008213C_arg0_70_offset[offsetof(RecoveredFields_8008213C_arg0, field_70) == 0x70 ? 1 : -1];
typedef char RecoveredFields_8008213C_arg0_334_offset[offsetof(RecoveredFields_8008213C_arg0, field_334) == 0x334 ? 1 : -1];
typedef char RecoveredFields_8008213C_arg0_338_offset[offsetof(RecoveredFields_8008213C_arg0, field_338) == 0x338 ? 1 : -1];
typedef char RecoveredFields_8008213C_arg0_33C_offset[offsetof(RecoveredFields_8008213C_arg0, field_33C) == 0x33C ? 1 : -1];
typedef char RecoveredFields_8008213C_arg0_340_offset[offsetof(RecoveredFields_8008213C_arg0, field_340) == 0x340 ? 1 : -1];
typedef char RecoveredFields_8008213C_arg0_344_offset[offsetof(RecoveredFields_8008213C_arg0, field_344) == 0x344 ? 1 : -1];
typedef char RecoveredFields_8008213C_arg0_348_offset[offsetof(RecoveredFields_8008213C_arg0, field_348) == 0x348 ? 1 : -1];
typedef char RecoveredFields_8008213C_arg0_34C_offset[offsetof(RecoveredFields_8008213C_arg0, field_34C) == 0x34C ? 1 : -1];
typedef char RecoveredFields_8008213C_arg0_350_offset[offsetof(RecoveredFields_8008213C_arg0, field_350) == 0x350 ? 1 : -1];
typedef char RecoveredFields_8008213C_arg0_354_offset[offsetof(RecoveredFields_8008213C_arg0, field_354) == 0x354 ? 1 : -1];
typedef char RecoveredFields_8008213C_arg0_358_offset[offsetof(RecoveredFields_8008213C_arg0, field_358) == 0x358 ? 1 : -1];
typedef char RecoveredFields_8008213C_arg2_C_offset[offsetof(RecoveredFields_8008213C_arg2, field_C) == 0xC ? 1 : -1];
typedef char RecoveredFields_8008213C_arg1_60_offset[offsetof(RecoveredFields_8008213C_arg1, field_60) == 0x60 ? 1 : -1];
typedef char RecoveredFields_8008213C_arg1_A4_offset[offsetof(RecoveredFields_8008213C_arg1, field_A4) == 0xA4 ? 1 : -1];
typedef char RecoveredFields_8008213C_temp_r3_10_offset[offsetof(RecoveredFields_8008213C_temp_r3, field_10) == 0x10 ? 1 : -1];
u8 *TObjPlayer::construct_freeze_shell(u8 *arg1, u8 *arg2) {
    u8 *temp_r3;
    __ct__13TUnk_804806E8FP7TObject(this, (void *)tl_05);
    ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_18 = lbl_8048E1A4;
    ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_34 = get_bml_model((void *) ((*(s32 *)&freeze_shell_bml_resource)), 1);
    if (arg1 != NULL) {
        ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_358 = get_entity_id(arg1);
        VecCopy((Vec *)(((u8 *)this) + 0x35C), (const Vec *)(arg1 + 0x38));
        if (arg2 != NULL) {
            VecCopy((Vec *)(((u8 *)this) + 0x38), (const Vec *)(arg2 + 0x1C));
            ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_338 = (f32) (lbl_805D9398 * ((RecoveredFields_8008213C_arg2 *)arg2)->field_C);
        } else if ((void *) ((RecoveredFields_8008213C_arg1 *)arg1)->field_A4 != NULL) {
            ((TUnk_804AF8A0 *)arg1)->refresh_collision_body_centers();
            VecCopy((Vec *)(((u8 *)this) + 0x38), (const Vec *)(((RecoveredFields_8008213C_arg1 *)arg1)->field_A4 + 0x1C));
            ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_338 = (f32) (lbl_805D9398 * *(f32 *)((s8 *)(((RecoveredFields_8008213C_arg1 *)arg1)->field_A4) + 0xC));
        } else {
            VecCopy((Vec *)(((u8 *)this) + 0x38), (const Vec *)(arg1 + 0x2FC));
            temp_r3 = get_quest_id__12TQuestListVMFv(arg1);
            if (temp_r3 != NULL) {
                ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_338 = (f32) (lbl_805D939C * ((RecoveredFields_8008213C_temp_r3 *)temp_r3)->field_10);
            } else {
                ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_338 = (f32) lbl_805D93A0;
            }
        }
        ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_60 = (s32) ((RecoveredFields_8008213C_arg1 *)arg1)->field_60;
        ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_70 = (f32) (*(const f32 *)&lbl_805D9378);
        ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_6C = (f32) (*(const f32 *)&lbl_805D9378);
        ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_68 = (f32) (*(const f32 *)&lbl_805D9378);
        ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_334 = 0;
        ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_33C = 0;
        ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_340 = (f32) (*(const f32 *)&lbl_805D9378);
        ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_344 = (f32) (*(const f32 *)&lbl_805D9378);
        ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_348 = (f32) (*(const f32 *)&lbl_805D9378);
        ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_34C = (f32) (*(const f32 *)&lbl_805D9378);
        ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_350 = (s32)create_particle_emitter((((u8 *)this) + 0x38), 0x12E);
        ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_354 = 0;
    } else {
        ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_350 = 0;
        queue_destruction__7TObjectFv((this));
    }
    return ((u8 *)this);
}
#pragma pop

s32 TUnk_8048E1A4::select_melee_contact_body(void *, f32) { return 1; }
int TUnk_8048E1A4::calc_distance_accuracy_penalty(void *, void *, void *, float) { return 1; }

f32 TUnk_8048E1A4::receive_direct_attack(void *, DirectAttackPayload, void *, s32, s32) {
    return lbl_805D9378;
}

f32 TUnk_8048E1A4::receive_weapon_special_attack(void *, void *) {
    return lbl_805D9378;
}

__declspec(section ".data") const char *bm_eff_ice_model_names[3] = { lbl_80438E60, lbl_80438E74, NULL };
__declspec(section ".data") const char *bm_eff_ice_motion_names[2] = { lbl_80438E80, NULL };
BmlResourceDescriptor enemy_freeze_ice_resource_descriptor = { lbl_80438E94, bm_eff_ice_model_names, bm_eff_ice_motion_names, 2, 1 };
}
