#ifndef PSO_ENEMY_PANARMS_TOBJENEPANARMS_H
#define PSO_ENEMY_PANARMS_TOBJENEPANARMS_H

struct EnemyPlacement;

#include "types.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/render/RenderFadeState.h"

class ModelNodePositionCapture;
class TObjEnePanBARA;
struct BmlResource;
class TParticleCtrl;

struct TObjEnePanarms : public TObjEnemy {
    TObjEnePanarms(TObject *parent, EnemyPlacement *setData);
    virtual ~TObjEnePanarms();
    virtual void run_task();
    virtual void render();
    // State 10 (separated) when a half starts dying while the body is up; 1 if it switched.
    s32 check_half_dying();
    void run_death_reaction();
    void run_hit_reaction();
    void run_miss_reaction();
    s32 state; // index into the TU's {enter, update} state table
    Vec move_velocity; // added to position every frame (0x378)
    f32 ground_y; // height of the ground under the body (snap_to_ground); hidden, it waits 39.6 below it
    s32 state_timer; // countdown of the current state (wait_frames hidden, 0xA4 dead, 0x5A arm attacks)
    s32 step_right; // toggled by enter_move: 1 steps right (walkr), 0 left (walkl); picks the next state
    CollisionBody *collision_body_parts; // init_collision_body_parts / free_collision_body_parts
    TParticleCtrl *particle_handles[2]; // released by destroy_handles
    ModelNodePositionCapture *node_capture; // panarms_model_node_desc -> draw_positions
    Vec draw_positions[5];
    s32 visible; // nonzero: drawn, animated, targetable and on the minimap (run_task, render)
    s32 shadow_visible; // render draws the shadow; cleared while hidden and as the body sinks dead
    TObjEnePanBARA *halves[2]; // create_bara(index 0 / 1)
    s32 attack_count; // bit 0 / bit 1 pick the next arm attack
    s32 spin_count;
    s32 max_hp; // the split starts at max_hp / 3
    s32 has_split;
    s32 move_count; // moves since the last split check
    RenderFadeState fades[4]; // one per camera (render)
    f32 pad_470;
    s32 search_range; // range passed to find_nearest_visible_player while waiting hidden
    s32 wait_frames; // state timer start value of the hidden wait
    int find_nearest_enemy_with_flag(Vec *direction, f32 range);
    static void spawn_npc_pair();
    static TObjEnePanBARA *create_bara(EnemyPlacement *setData, s32 index);
    static s32 create(saddr setData);
    int get_state_flag();
    // State table (enter, update), named after the action each state plays (panarms_motion_param_table):
    // 0 idle (demo), 1 wait hidden under the ground, 2 rise out of it, 3 move (walkl / walkr),
    // 4 dead (deada / deadb), 5 charge the upper beam (btameu), 6 upper beam (beamup),
    // 7 charge the lower beam (btamed), 8 lower beam (beamdwn), 9 split (cry), 10 separated,
    // 11 merge, 12 rejoin (cry), 13 spin (walk).
    void enter_idle();
    void try_activate();
    void enter_wait_hidden();
    void update_wait_hidden();
    void enter_rise();
    void update_rise();
    void enter_move();
    void update_move();
    void enter_dead();
    void update_dead();
    void enter_charge_beam_up();
    void update_charge_beam_up();
    void enter_beam_up();
    void update_beam_up();
    void enter_charge_beam_down();
    void update_charge_beam_down();
    void enter_beam_down();
    void update_beam_down();
    void enter_split();
    void update_split();
    void enter_separated();
    void update_separated();
    void enter_merge();
    void update_merge();
    void enter_rejoin();
    void update_rejoin();
    void enter_spin();
    void update_spin();
    // Walks from the halves' midpoint toward the body until has_ground_around and both halves'
    // paths to the spot hold ground; moves the body there facing across the halves.
    s32 find_combine_position();
    s32 check_ground_along_path(Vec *from, Vec *to, f32 step, f32 rise);
    // Ground under pos and on the rings 10 and 20 units around it.
    s32 has_ground_around(Vec *pos);
    // 1 when no player stands within 500 units (update_move hides the body again).
    s32 is_far_from_players();
    // The split / merge burst (particle 0x106) above body_center.
    void spawn_split_effect(s32 a, s32 b);
    // Steps toward pos; when the ground or a wall stops it, retries turned 22.5, -45, 67.5, ... degrees.
    s32 try_warp_to_position(Vec *pos);
    void draw();
    void turn_toward_target(s32 max_step);
    u16 turn_to_nearest_player(s32 max_step, s32 mode);
    void snap_to_ground();
    void set_state(s32 next);
    void draw_shadow();
    void destroy_handles();
    static void free_data();
    static void load_and_spawn_npc();
};

// The Pan Arms bml (models and motions of the body and both halves).
extern BmlResource *TObjEnePanarms__entry_params_resource;

#endif
