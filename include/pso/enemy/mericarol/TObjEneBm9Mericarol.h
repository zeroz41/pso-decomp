#ifndef PSO_ENEMY_MERICAROL_TOBJENEBM9MERICAROL_H
#define PSO_ENEMY_MERICAROL_TOBJENEBM9MERICAROL_H

#include <stddef.h>
#include "types.h"

struct NJS_OBJECT;
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/render/RenderFadeState.h"
#include "pso/render/TUnk_80494938.h"
#include "pso/effect/TUnk_80494968.h"
#include "pso/enemy/AttackTargetHistory.h"
#include "pso/enemy/TObjEnemyCustom.h"

// What TObjEnemy::movementParameters points at.
struct TObjEneBm9MericarolMovementParameters {
    EnemyMoveParams move;
    u32 unknown_c[4];
};

class TObjPlayer;

struct TObjEneBm9MericarolParams {
    f32 m_0;
    f32 m_4;
    f32 m_8;
    f32 m_c;
    f32 m_10;
    f32 m_14;
    s32 m_18;
    s32 m_1c;
    s32 m_20;
    s32 m_24;
    s32 m_28;
    s32 m_2c;
};

struct TObjEneBm9Mericarol : public TObjEneDD_ST {
    TObjEneBm9Mericarol(TObject *parent, void *set_data);
    virtual ~TObjEneBm9Mericarol();
    virtual void run_task();
    virtual void render();
    virtual void dispatch_action(u32 state, s32 reason);
    virtual void update_body_colliders();
    virtual void run_demo_task();
    virtual void draw_color_variant();
    virtual void run_death_reaction();
    virtual void run_hit_reaction();
    virtual void run_miss_reaction();
    virtual void refresh_target();
    s32 get_phase();
    void init_size_tier_and_offsets();
    TObjPlayer *find_nearby_target();
    s32 try_set_mode8_if_flag2();
    void sync_center_position();
    static void load_resources();
    static void free_shared_instances();
    static void *create(void *set_data);
    static void update_particle_effect(NJS_OBJECT *);
    void sub_802CE68C(Vec *out, s32 node);
    void sub_802CED40();
    s32 get_clamped_level();
    void sub_802CEDA0(s32 reason);
    void handle_motion_event(s32 arg1);
    void handle_state_message(s32 msg);
    void state_burrow(s32 reason);
    void handle_event(s32 arg1);
    void handle_action(s32 arg1);
    void sub_802CF368(s32 reason);
    void sub_802CF4F8(s32 reason);
    s32 check_attack_hits();
    void sub_802CF7B4(s32 reason);
    void sub_802CFB64(s32 reason);
    void handle_shot_state(s32 reason);
    void sub_802D01D8(s32 reason);
    void sub_802D05BC(s32 reason);
    void sub_802D073C();
    void sub_802D093C();
    void sub_802D0940();
    TUnk_80494968 *m_3c0[2];
    RenderFadeState m_3c8[4];
    u32 m_438;
    f32 m_43c;
    f32 m_440;
    f32 m_444;
    f32 m_448;
    s32 m_44c;
    s32 m_450;
    s32 m_454;
    s32 m_458;
    s32 m_45c;
    Vec m_460;
    TUnk_80494938 m_46c;
    AreaAttackHistory *m_488;
    TObjCollidable *m_48c;
    s32 m_490;
    s32 m_494;
    s32 m_498;
    s32 m_49c;
    s32 m_4a0;
    f32 m_4a4;
    f32 m_4a8;
    TObject *m_4ac;
};

extern TObjEneBm9MericarolParams *mericarol_phase_param_table[3];

LAYOUT_ASSERT(TObjEneBm9MericarolParams_size, sizeof(TObjEneBm9MericarolParams) == 0x30);
LAYOUT_ASSERT(TObjEneBm9MericarolFadeOffset, offsetof(TObjEneBm9Mericarol, m_46c) == 0x46C);
LAYOUT_ASSERT(TObjEneBm9Mericarol_size, sizeof(TObjEneBm9Mericarol) == 0x4B0);
#endif
