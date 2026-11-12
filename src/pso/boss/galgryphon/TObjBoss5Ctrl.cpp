#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/boss/galgryphon/TObjBoss5Ctrl.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/boss/galgryphon/TObjBoss5PillarDemo.h"
#include "pso/system/SoundEffect.h"
#include <stdlib.h>
#include "pso/system/task/TObject.h"
#pragma fp_contract on

extern s32 boss5_ctrl_instance;

extern "C" {
s32 __ct__7TObjectFP7TObject(void *, void *);
s32 get_current_floor(f32, f32, f32);
s32 is_room_enemy_set_cleared(s32, s32);
u32 create__19TObjBoss5FloorStoneFv();
u32 create__19TObjBoss5FloorGrassFv();
u32 create__19TObjBoss5PillarCtrlFv(void *);
s32 is_split_screen();
extern void *__vt__13TObjBoss5Ctrl[];
extern s32 lbl_805D2828;
}

void TObjBoss5Ctrl::run_task() {
    if ((*(s16 *)((s8 *)this + 0x2C))-- <= 0) {
        play_sound_effect(0x40033215, 0, 0, 0);
        *(s16 *)((s8 *)this + 0x2C) = (s16) (60.0f * (3.0517578e-05f * (f32) rand()) + 90.0f);
    }
}

TObjBoss5Ctrl::~TObjBoss5Ctrl() {
    if (m_28 != nullptr) { ((TObject *)m_28)->queue_destruction(); m_28 = nullptr; }
    if (m_24 != nullptr) { ((TObject *)m_24)->queue_destruction(); m_24 = nullptr; }
    if (m_20 != nullptr) { ((TObject *)m_20)->queue_destruction(); m_20 = nullptr; }
    if (m_1c != nullptr) { ((TObject *)m_1c)->queue_destruction(); m_1c = nullptr; }
    boss5_ctrl_instance = 0;
}

void *TObjBoss5Ctrl__ct(void *boss5_pillar_ctrl, void *parent) {
    f32 temp_f2;
    f32 temp_f3;

    __ct__7TObjectFP7TObject(boss5_pillar_ctrl, parent);
    *(void **)((s8 *)boss5_pillar_ctrl + 0x18) = __vt__13TObjBoss5Ctrl;
    *(s32 *)((s8 *)boss5_pillar_ctrl + 0) = (s32) lbl_805D2828;
    *(u32 *)((s8 *)boss5_pillar_ctrl + 0x1C) = 0U;
    *(u32 *)((s8 *)boss5_pillar_ctrl + 0x20) = 0U;
    *(u32 *)((s8 *)boss5_pillar_ctrl + 0x24) = 0U;
    *(u32 *)((s8 *)boss5_pillar_ctrl + 0x28) = 0U;
    temp_f3 = (f32) rand();
    temp_f2 = 3.0517578e-05f * temp_f3;
    *(s16 *)((s8 *)boss5_pillar_ctrl + 0x2C) = (s16) (60.0f * temp_f2 + 90.0f);
    if (is_room_enemy_set_cleared(get_current_floor(60.0f, temp_f2, temp_f3), 1) == 0) {
        if (is_split_screen() == 0) {
            if ((u32) *(u32 *)((s8 *)boss5_pillar_ctrl + 0x1C) == 0U) {
                *(u32 *)((s8 *)boss5_pillar_ctrl + 0x1C) = create__19TObjBoss5FloorGrassFv();
            }
            if ((u32) *(u32 *)((s8 *)boss5_pillar_ctrl + 0x20) == 0U) {
                *(u32 *)((s8 *)boss5_pillar_ctrl + 0x20) = create__19TObjBoss5FloorStoneFv();
            }
            if ((u32) *(u32 *)((s8 *)boss5_pillar_ctrl + 0x24) == 0U) {
                *(u32 *)((s8 *)boss5_pillar_ctrl + 0x24) = create__19TObjBoss5PillarCtrlFv(boss5_pillar_ctrl);
            }
        }
        if ((u32) *(u32 *)((s8 *)boss5_pillar_ctrl + 0x28) == 0U) {
            *(u32 *)((s8 *)boss5_pillar_ctrl + 0x28) = TObjBoss5PillarDemo::create();
        }
    }
    return boss5_pillar_ctrl;
}
