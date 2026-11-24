#ifndef PSO_ENEMY_GIBBLES_TOBJENEGIBBLES_H
#define PSO_ENEMY_GIBBLES_TOBJENEGIBBLES_H
#include "types.h"

struct NJS_OBJECT;
struct TObjPlayer;
#include <stddef.h>
#include "pso/enemy/TObjEnemy.h"
#include "pso/render/RenderFadeState.h"
#include "pso/render/TUnk_80494938.h"

// movementParameters (gibbles_move_params): 250.0f, 1.25f, 0x400
struct GibblesMoveParams {
    f32 radius;
    f32 speed;
    s32 turn_speed;
    s32 pad_0C[4];
};

// TObjEneGibbles__ai_parameters, TLobby::dispatch_shared_handler_a(0x3D) (names inferred)
struct GibblesAiParams {
    f32 pad_00;
    f32 attack_recovery;  // frames it rests after the three-hit attack
    f32 walk_speed;       // enemy_move_toward's speed while it chases
    f32 landing_speed;    // the landing action's play speed (at least 0.1)
    u8 pad_10[0x8];
    s32 wait_frames;      // frames it crouches before the jump attack
};

struct EnemyPlacement;

struct TObjEneGibbles : public TObjEnemy {
    TObjEneGibbles(TObject *parent, EnemyPlacement *setData);
    virtual void run_death_reaction();
    virtual ~TObjEneGibbles();
    // the run_task mode handlers are named after the motions they request
    // through gibbles_action_table (names inferred)
    void state_guard();
    virtual void render();
    virtual void run_hit_reaction();
    virtual void run_task();
    void select_model_record(s32 i);
    void update_wander();
    void state_appear();
    void state_chase_target();
    void state_jump_attack();
    void state_dead();
    virtual s32 update_action_hold_status();
    virtual s32 update_movement_status();
    virtual void run_idle_action();
    virtual void run_move_action();
    virtual s32 is_target_in_attack_range();
    virtual void run_attack_action();
    virtual int test_flag_256();
    virtual void run_miss_reaction();
    virtual void refresh_target();
    void *get_center();
    u32 resolve_sound_id(u32 sound_id);
    // (names inferred from their uses below)
    // state bits: 1 risen, 2 near the target, 4 on the ground, 8 armor broken
    // (slam attack), 0x10 jump attack chosen, 0x20 guarding, 0x40 hidden,
    // 0x80 jump queued after a hit, 0x100 attacking (hits do not stagger it)
    s32 status_flags;
    u32 target_class_mask;  // the player classes it prefers (1 << preferred_class), tested in refresh_target
    s16 attack_kind;  // row of gibbles_combat_stat_entries: 0 attack, 1 jump, 2 punch
    s16 combo_count;  // (name inferred) finished mode-5 attacks; two clear the 0x108 flags
    s32 armor_state;  // 0x101 full, 0x102 above half, 0x103 cracked, 0 broken; 0x107/0x10E on a guard/hit
    s32 reported_armor_state;  // armor_state as last copied by sync_state while on the ground
    s16 armor;      // 100 + parameters[0]; guarding wears it down, hits with the punch refill it
    s16 armor_max;
    f32 jump_height;  // added to the drawn and body_center y in modes 2, 6 and 10
    f32 jump_speed;   // per-frame change of jump_height
    f32 jump_attack_chance;  // parameters[2]: random_ratio odds of the 0x10 jump attack
    f32 hit_jump_chance;     // parameters[3]: random_ratio odds of jumping away after a hit
    s32 preferred_class;     // parameters[1] clamped to 0..8
    f32 state_timer;  // chase re-roll timer; the sink counter while dying
    s32 wait_timer;   // frames waited before the jump
    s32 wait_frames;  // ai parameters' wait_frames
    u8 pad_3ac[0x4];
    TObjPlayer *guarded_player;  // the attacker test_flag_256 turned to guard against
    // (name inferred) one-body collidables built from gibbles_collision_bodies[1]
    // and [2]; sub_802D9644/sub_802D9824 move [0] to a joint and hit with it
    TObjCollidable *attack_colliders[2];
    s32 head_angle;  // x turn of node 0x18, eased toward clamp_angle's target
    TUnk_80494938 fade;
    RenderFadeState fades[4];
    // sets gibbles_action_table[action].speed, at least 0.1 (this is unused)
    void set_min_clamped_entry_value(s32 action, f32 speed);
    s32 spawn_ground_impact_effects(const Vec *pos, f32 scale);
    s32 spawn_ground_contact_effect();
    void play_ground_contact_sound();
    void play_distance_sound();
    void update_shadow_height();
    void update_position();
    void sync_state();
    void update_move_state();
    void update_action_state();
    void update_death_sequence();
    void update_spawn_state();
    void init_state();
    void clamp_angle(s32 angle);
    void init_params();
    static void *create(void *setData);
    static void free_static();
    static void load_resources();
    void turn_toward_target();
    void slam_damage_players(s32 node);
    // shakes the camera when the local player is in Gibbles' room (landing)
    void shake_camera_in_room();
    void sub_802D7E3C();
    void sub_802D8034();
    void render_and_get_joint_pos(Vec *out, s32 node);
    bool attack_from_joint_31(s32 trigger_hit_reaction, f32 power);
    bool attack_from_joint_53(s32 trigger_hit_reaction, f32 power);
    void state_punch();
    void state_attack();
    s32 landing_damage_players();
};
LAYOUT_ASSERT(TObjEneGibbles_size, sizeof(TObjEneGibbles) ==0x44C);

void gibbles_render_node_callback(NJS_OBJECT *);
// hit the players touching attack_colliders[0] (moved to joint 0x1F / 0x35);
// arg 1 grows armor by the damage dealt
extern "C" {
}

#endif
