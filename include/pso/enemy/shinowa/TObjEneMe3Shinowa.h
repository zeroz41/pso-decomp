#ifndef PSO_ENEMY_SHINOWA_TOBJENEME3SHINOWA_H
#define PSO_ENEMY_SHINOWA_TOBJENEME3SHINOWA_H

#include "types.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/render/TUnk_80494938.h"

class TParticleCtrl;
class TUnk_80494968;

struct TObjEneMe3ShinowaParams {
    f32 m_0;
    f32 m_4;
    f32 m_8;
    f32 m_c;
    f32 m_10;
    u8 unk_14[0x4];
    s32 m_18;
    s32 m_1c;
    s32 m_20;
};

struct TObjEneMe3ShinowaMoveParams {
    f32 m_0;
    f32 m_4;
    s32 m_8;
    u8 unk_c[0x10];
};

struct TObjEneMe3Shinowa : public TObjEneDD_ST {
    TObjEneMe3Shinowa(TObject *parent);
    virtual ~TObjEneMe3Shinowa();
    virtual s32 acquire_target(f32);
    virtual void run_task();
    virtual void render();
    virtual void dispatch_action(u32 state, s32 reason);
    virtual void update_body_colliders();
    virtual void check_collisions();
    virtual void vfunc_105();
    virtual s32 can_hit_same_target();
    virtual void select_next_attack_state();
    virtual void update_player_state_default();
    virtual s32 update_effect();
    virtual void dispatch_if_active();
    virtual void on_target_lost();
    virtual void apply_effect_pair();
    virtual void action(s32);
    virtual void vfunc_114(s32);
    virtual void vfunc_115(s32);
    virtual void vfunc_116(s32);
    virtual void update_mirage();
    virtual void render_demo();
    void init_enemy();
    f32 get_node_world_y();
    s32 check_body_collision_at(s32, f32);
    s32 is_mirage_enabled();
    s32 is_gold_enabled();
    void select_gold_or_normal_variant();
    void sub_800E6BB8(s32);
    void run_death_reaction();
    void run_hit_reaction();
    void run_miss_reaction();
    void refresh_target();
    s32 kind_index;
    u32 behavior_flags;
    f32 body_y;
    f32 body_offset_y;
    u32 material_color;
    s32 m_3d4;
    s32 m_3d8;
    s16 m_3dc;
    TUnk_80494968 *m_3e0;
    TUnk_80494968 *m_3e4;
    TUnk_80494938 fade;
    s32 state_step;
    s32 state_timer;
    s32 m_40c;
    f32 m_410;
    f32 m_414;
    Vec m_418;
    TParticleCtrl *m_424;
    TParticleCtrl *m_428;
    void copy_position_vector();
    void fn_800E762C();
    s32 check_in_range(f32);
    void state_break_apart(s32 reason);
    void state_cast_support(s32 reason);
    void state_chase_target(s32 arg1);
    void update_by_distance();
    void sub_800E4FE8(s32 reason);
    void sub_800E50D8(s32 reason);
    void sub_800E5220(s32 reason);
    void sub_800E54E8(s32 reason);
    void sub_800E5CE4(s32 reason);
    void sub_800E5F64(s32 reason);
    void sub_800E66FC(s32 reason);
    void sub_800E69F0(s32 reason);
    void sub_800E6F0C();
    void sub_800E5950(s32 reason);
    void sub_800E7268();
};

LAYOUT_ASSERT(TObjEneMe3Shinowa_m_3e8, offsetof(TObjEneMe3Shinowa, fade) == 0x3E8);
LAYOUT_ASSERT(TObjEneMe3Shinowa_size, sizeof(TObjEneMe3Shinowa) == 0x42C);

#endif
