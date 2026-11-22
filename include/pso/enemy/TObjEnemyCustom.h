#ifndef PSO_ENEMY_TOBJENEMYCUSTOM_H
#define PSO_ENEMY_TOBJENEMYCUSTOM_H

#include "types.h"
#include "pso/enemy/TObjEnemy.h"

struct Vec;
struct NJS_OBJECT;

// What TObjEnemy::movementParameters points at for the custom enemies.
struct EnemyMoveParams {
    f32 max_distance;
    f32 min_distance;
    s32 turn_speed;
};

struct TObjEnemyCustom : public TObjEnemy {
    TObjEnemyCustom(TObject *parent);
    virtual ~TObjEnemyCustom();
    u16 find_nearest_enemy(Vec *out, f32 radius);
    BOOL select_nearest_target(f32 radius);
    bool has_target() const { return target != NULL; }
    BOOL find_target_in_range(f32 radius);
    u16 pick_random_nearby_player(f32 radius);
    void pick_open_direction(f32 *dir, f32 reach, f32 radius);
    void move_along_ground_avoiding_walls(Vec dest, f32 speed, f32 probe);
    s32 turn_toward_point(Vec *point, s32 max_step, s32 angle_offset);
    void render_anim_model_at_pos();
    void run_demo_task();
    // Enters action 7 (the subclass's appear / fade-in) with the action lock set.
    void start_appear();
    void release_destroyed_target();
    // Clears the actorFlags bits set_flags_30 sets (0x04040000).
    void clear_flags_30();
    void set_flags_30();
    virtual void apply_enemy_state(s32 *);
    virtual void get_anim_node_position(s32 node, Vec *out);
    virtual void run_death_reaction();
    virtual void run_hit_reaction();
    virtual void run_miss_reaction();
    virtual void run_attack_action();
    virtual void run_move_action();
    virtual void run_idle_action();
    virtual void refresh_target();
    virtual void render();
    virtual void run_task();
    s32 next_action;
    u32 resume_action;  // the action to go back to after a reaction (Gyaranzo update_if_active(resume_action))
    u32 state;
    u32 previous_action;  // set_state stores the mode it leaves
    s32 state_timer;  // frames left in the current state
    // Bit 0 locks the action (hit, death and appear set it, update_if_active then
    // requests nothing); the other bits belong to each subclass.
    u32 behavior_flags;
    void update_if_active(s32 action);
    void set_state(s32 action);
    void update_dying_state();
    void update_knockback_state();
    void update_state_machine();
    void update();
    void update_wander_state();
    void update_state();
    void dispatch_state();
};

LAYOUT_ASSERT(TObjEnemyCustom_size, sizeof(TObjEnemyCustom) == 0x38C);

// Ninja node helpers (NJD_EVAL_HIDE on NULL-terminated node lists).
void hide_model_nodes(NJS_OBJECT **nodes);
void show_model_nodes(NJS_OBJECT **nodes);
// Every visible node with a model under `root` (not its siblings), NULL-terminated.
s32 collect_visible_nodes(NJS_OBJECT *root, NJS_OBJECT **out);

#endif
