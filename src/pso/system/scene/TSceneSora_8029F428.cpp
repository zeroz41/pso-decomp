#include "types.h"
#include "pso/unk/text_803281B8.h"
#include "pso/system/scene/TSceneSora_8029F428.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/vector.h"
#include "pso/system/scene/TSceneSora.h"
#include "pso/unk/TUnk_804DC7C4.h"

#include <stddef.h>
#include "pso/system/scene/TScene.h"
struct RecoveredGlobal_80069094_camera_controller_registry { s32 value; u8 remaining[0x64]; };

struct RecoveredGlobal_80069024_TCameraCtrl__data_804FF634 {
    s32 value;
    u8 remaining[0x44];
};

struct RecoveredGlobal_80069024_lbl_804FF67C {
    s32 value;
    u8 remaining[0x44];
};

struct RecoveredGlobal_800695E8_TCameraCtrl__data_804FF628 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_800691C8_TCameraCtrl__data_804FF6D0 {
    s32 value;
    u8 remaining[0x2C];
};

struct RecoveredGlobal_800691C8_TCameraCtrl__data_804FF700 {
    s32 value;
    u8 remaining[0xBC];
};

struct RecoveredGlobal_800691C8_main_task {
    s32 value;
    u8 remaining[0x30];
};

struct RecoveredGlobal_800687E4_TCameraCtrl__data_804FF6C4 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_80069148_TCameraCtrl__data_804FF6D0 {
    s32 value;
    u8 remaining[0x2C];
};

struct RecoveredGlobal_80069148_TCameraCtrl__data_804FF700 {
    s32 value;
    u8 remaining[0xBC];
};

struct RecoveredGlobal_80069C94_camera_controller_registry {
    s32 value;
    u8 remaining[0x64];
};

struct RecoveredGlobal_80069C94_TCameraCtrl__data_804FF628 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_80069D04_camera_controller_registry {
    s32 value;
    u8 remaining[0x64];
};

struct RecoveredGlobal_80069D04_TCameraCtrl__data_804FF628 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_800687C8_TCameraCtrl__data_804FF6C4 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_80069304_TCameraCtrl__data_804FF628 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_8006961C_TCameraCtrl__data_804FF628 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_8006961C_TCameraCtrl__data_804FF634 {
    s32 value;
    u8 remaining[0x44];
};

struct RecoveredGlobal_8006961C_lbl_8058CA60 {
    s32 value;
    u8 remaining[0x54];
};

struct RecoveredGlobal_80069258_TCameraCtrl__data_804FF6D0 {
    s32 value;
    u8 remaining[0x2C];
};

struct RecoveredGlobal_80069258_TCameraCtrl__data_804FF700 {
    s32 value;
    u8 remaining[0xBC];
};

struct RecoveredGlobal_80069258_main_task {
    s32 value;
    u8 remaining[0x30];
};

struct RecoveredGlobal_80069A6C_camera_controller_registry {
    s32 value;
    u8 remaining[0x64];
};

struct RecoveredGlobal_80069A6C_TCameraCtrl__data_804FF628 {
    u8 value;
    u8 remaining[0xB];
};

extern "C" {
extern s32 lbl_805D65F0;
extern RecoveredGlobal_800687E4_TCameraCtrl__data_804FF6C4 sora_reflection_ray_direction;
s32 __ct__7TObjectFP7TObject();
s32 __dl__7TObjectFPv(void *);
s32 __dt__7TObjectFv(void *, s32);
void *__nw__7TObjectFUl(s32);

extern s32 lbl_804DC7C4[];
extern s16 scene_sora_reflect_active;
extern s8 scene_sora_recon_active_flag;

void *TUnk_804DC7C4::destroy(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = lbl_804DC7C4;
        scene_sora_reflect_active = 0;
        scene_sora_recon_active_flag = 0;
        lbl_805D65F0 = 0;
        if ((u32) this->m_20 != 0U) {
            queue_destruction__7TObjectFv(*(void * *)&this->m_20);
            this->m_20 = 0U;
        }
        TScene::set_id(0);
        TScene::set_active_scene(0);
        TScene::set_instance(0);
        __dt__7TObjectFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

extern s32 tl_05;
extern void *scene_sora_instance;
extern s32 scene_sora_recon_object;
extern const f32 lbl_805DDD8C;
extern const f32 lbl_805DDD90;

void *create_instance__10TSceneSoraFPv(void *arg0) {
    void *obj;

    __ct__7TObjectFP7TObject();
    *(s32 **)((s8 *)arg0 + 0x18) = lbl_804DC7C4;
    scene_sora_reflect_active = 0;
    scene_sora_recon_active_flag = 0;
    if ((void *) scene_sora_instance != NULL) {
        return arg0;
    }
    scene_sora_instance = arg0;
    *(s32 *)((s8 *)arg0 + 0x1C) = (s32) scene_sora_recon_object;
    obj = __nw__7TObjectFUl(0x20);
    if (obj != NULL) {
        obj = construct_indirect_effect_task((u8 *)obj, 0x28, 1, (u8 *)tl_05);
    }
    *(void **)((s8 *)arg0 + 0x20) = obj;
    *(f32 *)((s8 *)arg0 + 0x24) = (f32) lbl_805DDD8C;
    ((TUnk_804DC7C4 *)arg0)->m_28 = (f32) lbl_805DDD8C;
    *(f32 *)((s8 *)arg0 + 0x2C) = (f32) lbl_805DDD8C;
    ((TUnk_804DC7C4 *)arg0)->m_30 = (f32) lbl_805DDD8C;
    *(f32 *)((s8 *)arg0 + 0x34) = (f32) lbl_805DDD90;
    ((TUnk_804DC7C4 *)arg0)->m_38 = (f32) lbl_805DDD8C;
    return arg0;
}
s32 TSceneSora::get_state() { return *(s32*)((char*)this + 0x20); }
void TSceneSora::set_scene_flag(int a0) { (*(int *)&lbl_805D65F0) = a0; }
void TSceneSora::copy_reflection_vec(u8 *arg0) {
    VecCopy((Vec *)(&sora_reflection_ray_direction.value), (const Vec *)(arg0));
}

typedef char RecoveredGlobal_80069094_camera_controller_registry_size[sizeof(RecoveredGlobal_80069094_camera_controller_registry) == 0x68 ? 1 : -1];
typedef char RecoveredGlobal_800687E4_TCameraCtrl__data_804FF6C4_size[sizeof(RecoveredGlobal_800687E4_TCameraCtrl__data_804FF6C4) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_800687C8_TCameraCtrl__data_804FF6C4_size[sizeof(RecoveredGlobal_800687C8_TCameraCtrl__data_804FF6C4) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_80069024_TCameraCtrl__data_804FF634_size[sizeof(RecoveredGlobal_80069024_TCameraCtrl__data_804FF634) == 0x48 ? 1 : -1];
typedef char RecoveredGlobal_80069024_lbl_804FF67C_size[sizeof(RecoveredGlobal_80069024_lbl_804FF67C) == 0x48 ? 1 : -1];
typedef char RecoveredGlobal_800691C8_TCameraCtrl__data_804FF6D0_size[sizeof(RecoveredGlobal_800691C8_TCameraCtrl__data_804FF6D0) == 0x30 ? 1 : -1];
typedef char RecoveredGlobal_800691C8_TCameraCtrl__data_804FF700_size[sizeof(RecoveredGlobal_800691C8_TCameraCtrl__data_804FF700) == 0xC0 ? 1 : -1];
typedef char RecoveredGlobal_800691C8_main_task_size[sizeof(RecoveredGlobal_800691C8_main_task) == 0x34 ? 1 : -1];
typedef char RecoveredGlobal_80069148_TCameraCtrl__data_804FF6D0_size[sizeof(RecoveredGlobal_80069148_TCameraCtrl__data_804FF6D0) == 0x30 ? 1 : -1];
typedef char RecoveredGlobal_80069148_TCameraCtrl__data_804FF700_size[sizeof(RecoveredGlobal_80069148_TCameraCtrl__data_804FF700) == 0xC0 ? 1 : -1];
typedef char RecoveredGlobal_80069258_TCameraCtrl__data_804FF6D0_size[sizeof(RecoveredGlobal_80069258_TCameraCtrl__data_804FF6D0) == 0x30 ? 1 : -1];
typedef char RecoveredGlobal_80069258_TCameraCtrl__data_804FF700_size[sizeof(RecoveredGlobal_80069258_TCameraCtrl__data_804FF700) == 0xC0 ? 1 : -1];
typedef char RecoveredGlobal_80069258_main_task_size[sizeof(RecoveredGlobal_80069258_main_task) == 0x34 ? 1 : -1];
typedef char RecoveredGlobal_800695E8_TCameraCtrl__data_804FF628_size[sizeof(RecoveredGlobal_800695E8_TCameraCtrl__data_804FF628) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_80069304_TCameraCtrl__data_804FF628_size[sizeof(RecoveredGlobal_80069304_TCameraCtrl__data_804FF628) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_8006961C_TCameraCtrl__data_804FF628_size[sizeof(RecoveredGlobal_8006961C_TCameraCtrl__data_804FF628) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_8006961C_TCameraCtrl__data_804FF634_size[sizeof(RecoveredGlobal_8006961C_TCameraCtrl__data_804FF634) == 0x48 ? 1 : -1];
typedef char RecoveredGlobal_8006961C_lbl_8058CA60_size[sizeof(RecoveredGlobal_8006961C_lbl_8058CA60) == 0x58 ? 1 : -1];
typedef char RecoveredGlobal_80069A6C_camera_controller_registry_size[sizeof(RecoveredGlobal_80069A6C_camera_controller_registry) == 0x68 ? 1 : -1];
typedef char RecoveredGlobal_80069A6C_TCameraCtrl__data_804FF628_size[sizeof(RecoveredGlobal_80069A6C_TCameraCtrl__data_804FF628) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_80069C94_camera_controller_registry_size[sizeof(RecoveredGlobal_80069C94_camera_controller_registry) == 0x68 ? 1 : -1];
typedef char RecoveredGlobal_80069C94_TCameraCtrl__data_804FF628_size[sizeof(RecoveredGlobal_80069C94_TCameraCtrl__data_804FF628) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_80069D04_camera_controller_registry_size[sizeof(RecoveredGlobal_80069D04_camera_controller_registry) == 0x68 ? 1 : -1];
typedef char RecoveredGlobal_80069D04_TCameraCtrl__data_804FF628_size[sizeof(RecoveredGlobal_80069D04_TCameraCtrl__data_804FF628) == 0xC ? 1 : -1];

}
