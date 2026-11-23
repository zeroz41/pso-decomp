#ifndef PSO_ENEMY_DELLBITER_TOBJENEDELLBITER_H
#define PSO_ENEMY_DELLBITER_TOBJENEDELLBITER_H

#include "types.h"

struct NJS_OBJECT;
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/render/TUnk_80490470.h"
#include "pso/render/RenderFadeState.h"

class TNowLoading;
class TParticleCtrl;
class AreaAttackHistory;
class TUnk_804928CC;
class TAttackTraceStrip;

struct DelbiterInitialParameters {
    f32 max_distance;
    f32 min_distance;
    s32 turn_speed;
    u32 unknown_c[4];
};

struct DelbiterContactAttack {
    f32 power;
    s32 flags;
};

// What TLobby::spawn_npc_enemy animates the NPC copy with (laid out like MojaAnimationBinding).
struct DelbiterAttackDefinition {
    void *motion;
    TObjMotionAction *actions;
    u32 unknown_08;
    u16 action_count;
    u16 pad_0E;
};

struct DelbiterMovementParameters {
    f32 rush_speed;
    f32 walk_speed;
    f32 animation_speed_4;
    f32 animation_speed_5;
    f32 rush_distance;
    f32 rush_start_distance;
    s32 state_duration;
    s32 powered_attack_power;
    s32 attack_power;
    s32 tp_attack_power;
    s32 attack_distance;
    s32 effect_duration;
};

struct TObjEneDellBiter : public TObjEneDD_ST {
    TObjEneDellBiter(TObject *parent, void *set_data);
    virtual ~TObjEneDellBiter();
    static void *create(void *set_data);
    void retarget_attacker();
    s32 render_model_if_visible();
    virtual void update_body_colliders();
    virtual s32 acquire_target(f32);
    virtual void run_demo_task();
    virtual void dispatch_action(u32, s32);
    virtual void render_demo();
    void run_death_reaction();
    void run_hit_reaction();
    void run_miss_reaction();
    void refresh_target();
    void render();
    void run_task();
    u32 flags;
    u32 flags_3c4;
    Vec reflection_position;
    TUnk_80490470 fade;
    RenderFadeState camera_fades[4];
    Vec part_positions[3];
    s32 part_rotation_x;
    s32 combo_count;
    s32 rush_count;
    s32 effect_timer;
    TUnk_804928CC *attack_bodies[2];
    TObjCollidable *rush_body;
    AreaAttackHistory *attack_history;
    TAttackTraceStrip *saver;
    f32 howl_chance;
    f32 confuse_chance;
    f32 confuse_distance;
    f32 laser_chance;
    f32 change_chance;
    s32 run_type;
    TParticleCtrl *effect;
    TParticleCtrl *status_effects[2];
    s32 state_timer;
    s32 step;
    s32 drained_tp;
    s32 target_angle;
    f32 current_speed;
    f32 rush_traveled;
    s32 try_howl();
    s32 try_laser();
    void state_death(s32 reason);
    void update_attack_state(s32 reason);
    void update_emerge_walk_state(s32 reason);
    void update_hidden_state(s32 reason);
    void update_damage_state(s32 reason);
    void update_laser_state(s32 reason);
    void update_change_state(s32 reason);
    void update_howl_state(s32 reason);
    void update_rush_state(s32 reason);
    void update_walk_state(s32 reason);
    void update_wait_state(s32 reason);
    void update_emerge_run_state(s32 reason);
    s32 check_rush_collisions();
    void update_contact_attacks();
    s32 select_farthest_visible_player();
    s32 validate_or_update_target();
    void fn_803058DC();
    void play_step_effect();
    void fn_80305684();
    void confuse_nearby_players();
    static void step_demo_script(NJS_OBJECT *);
    void update_state(s32 reason);
    s32 check_low_hp_transition();
    s32 fn_803059BC(const Vec *origin);
    void spawn_front_particle();
    void update_attack_effect();
    void init_target_offsets();
    void update_particle_emitters();
    void set_effect_pos_above_self();
    void init_params();
    static void set_min_clamped_entry_value(s32 index, f32 speed);
    static void destroy_static_instance();
    static void load_resources();
};

LAYOUT_ASSERT(TObjEneDellBiter_size, sizeof(TObjEneDellBiter) == 0x4E4);

#endif
