#ifndef PSO_ENEMY_GYARANZO_TOBJENEGYARANZO_H
#define PSO_ENEMY_GYARANZO_TOBJENEGYARANZO_H

#include "types.h"
#include "dolphin/mtx.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/render/RenderFadeState.h"
#include "pso/render/TUnk_80494938.h"

struct TObjEneGyaranzo : public TObjEnemyCustom {
    virtual ~TObjEneGyaranzo();
    void sub_800D2A68();
    void select_targets();
    virtual void run_task();
    virtual void render();
    void sub_800D37F4();
    void sub_800D2900();
    void init_params_from_table();
    virtual void run_hit_reaction();
    virtual void run_death_reaction();
    virtual void run_idle_action();
    virtual s32 is_target_in_attack_range();
    virtual void run_move_action();
    virtual void run_miss_reaction();
    void spawn_missile();
    u32 m_38c;
    u8 _pad390[0x18];
    u32 m_3a8;
    u32 m_3ac;
    u32 m_3b0;
    u32 m_3b4;
    u32 m_3b8;
    u8 unk_3BC[0x4];
    s32 m_3c0;
    u8 unk_3C4[0x4];
    s32 m_3c8;
    u8 unk_3CC[0x4];
    TUnk_80494938 m_3d0;
    RenderFadeState m_3ec[4];
    static void *create(void *arg0);
    static void free_static_instances();
};

LAYOUT_ASSERT(TObjEneGyaranzo_size, sizeof(TObjEneGyaranzo) == 0x45C);
#endif
