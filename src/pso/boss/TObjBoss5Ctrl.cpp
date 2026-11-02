#include "pso/TObjBoss5Ctrl.h"
#include "pso/boss/TObjBoss5Ctrl.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/boss/TObjBoss5PillarDemo.h"
#pragma fp_contract on

extern s32 boss5_ctrl_instance;

extern "C" {
s32 play_sound_effect(int, int, int, int);
s32 rand();
s32 __ct__7TObjectFP7TObject(void *);
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
    if (m_28 != nullptr) { queue_destruction__7TObjectFv(m_28); m_28 = nullptr; }
    if (m_24 != nullptr) { queue_destruction__7TObjectFv(m_24); m_24 = nullptr; }
    if (m_20 != nullptr) { queue_destruction__7TObjectFv(m_20); m_20 = nullptr; }
    if (m_1c != nullptr) { queue_destruction__7TObjectFv(m_1c); m_1c = nullptr; }
    boss5_ctrl_instance = 0;
}

void *TObjBoss5Ctrl__ct(void *boss5_pillar_ctrl) {
    f32 temp_f2;
    f32 temp_f3;

    __ct__7TObjectFP7TObject(boss5_pillar_ctrl);
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
