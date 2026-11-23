#ifndef PSO_ENEMY_SHINOWA_TOBJENEME3SHINOWA_H
#define PSO_ENEMY_SHINOWA_TOBJENEME3SHINOWA_H

#include "types.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/render/TUnk_80494938.h"

class TParticleCtrl;
class TAttackTraceStrip;

struct TObjEneMe3ShinowaParams {
    f32 m_0;
    f32 m_4;
    f32 dist;
    f32 sword_motion_speed; // motion slot 6 (shinowa_sword_motion) speed, at least 0.1
    f32 m_10;
    u8 unk_14[0x4];
    s32 support_tech_level; // Resta, Shifta and Deband
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
    virtual void apply_sword_hits();  // inferred: hits at frames 9 and 19 of the sword motion; empty on mirages
    virtual s32 can_hit_same_target();
    virtual void select_next_attack_state();
    virtual void update_player_state_default();
    virtual s32 update_effect();
    virtual void dispatch_if_active();
    virtual void on_target_lost();
    virtual void apply_effect_pair();
    virtual void action(s32);
    // inferred: states 14-16. 14 plays the transform motion and sends the mirages out (Real), 15 fades a mirage out
    // and parks it (Mirage), 16 plays the transform motion and toggles the cloak (behavior_flags 0x80000, Real).
    virtual void state_split_mirages(s32);
    virtual void state_fade_out(s32);
    virtual void state_toggle_cloak(s32);
    virtual void update_mirage();
    virtual void render_demo();
    void init_enemy();
    f32 get_node_world_y();
    s32 check_body_collision_at(s32 angle, f32 length);
    s32 is_mirage_enabled();
    s32 is_gold_enabled();
    void select_gold_or_normal_variant();
    void state_fade_appear(s32);
    void run_death_reaction();
    void run_hit_reaction();
    void run_miss_reaction();
    void refresh_target();
    s32 kind_index;
    u32 behavior_flags;
    f32 body_y;
    f32 body_offset_y;
    u32 material_color;
    s32 mirage_index;  // formation slot 0..4; the real one picks one, the mirages take the rest
    s32 attack_count;  // attacks since the mirages left; the second spawns them again
    s16 m_3dc;
    TAttackTraceStrip *attack_traces[2];  // fed from the two motion sample tables in apply_effect_pair
    TUnk_80494938 fade;
    s32 state_step;
    s32 state_timer;
    s32 target_angle;
    f32 move_speed;
    f32 m_414;
    Vec start_position;  // position on entering state_scatter
    TParticleCtrl *particle_emitters[2];  // particles 0x115 / 0x116 of state_scatter
    void copy_position_vector();
    void fn_800E762C();
    s32 check_in_range(f32);
    void state_break_apart(s32 reason);
    void state_cast_support(s32 reason);
    void state_chase_target(s32 mode);
    void update_by_distance();
    // inferred: state handlers named after the motion they request (action table -> bm_ene_me3_shinowa_motion_names):
    // fade_appear/drop_appear apper, t_wait t_wait, f_attack f_attack, sword_attack sword, backstep backstep,
    // wait wait, damage damage; scatter spreads each body by its mirage_index from start_position.
    void state_damage(s32 reason);
    void sub_800E50D8(s32 reason);
    void state_wait(s32 reason);
    void state_scatter(s32 reason);
    void state_sword_attack(s32 reason);
    void state_f_attack(s32 reason);
    void state_drop_appear(s32 reason);
    void state_t_wait(s32 reason);
    void cast_resta();
    void state_backstep(s32 reason);
    void sub_800E7268();
};

LAYOUT_ASSERT(TObjEneMe3Shinowa_m_3e8, offsetof(TObjEneMe3Shinowa, fade) == 0x3E8);
LAYOUT_ASSERT(TObjEneMe3Shinowa_size, sizeof(TObjEneMe3Shinowa) == 0x42C);

#endif
