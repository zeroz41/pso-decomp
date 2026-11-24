#ifndef PSO_BOSS_DARKFALZ_TBOSS4TYPE1_H
#define PSO_BOSS_DARKFALZ_TBOSS4TYPE1_H

#include "types.h"

struct BmlResource;
struct TBoss4FormSetData;
#include "pso/enemy/TObjEnemy.h"
#include "pso/unk/ModelNodeTables.h"
#include <stddef.h>

class ModelNodePositionCapture;
class TParticleCtrl;
struct CollisionBody;

struct TBoss4DarkFalz;

struct TBoss4Type1 : public TObjEnemy
{
    TBoss4Type1(TObject *parent, TBoss4FormSetData *set_data);
    virtual ~TBoss4Type1();
    virtual void run_task();
    virtual void render();
    virtual void apply_poison_status();
    virtual void apply_paralysis();
    virtual void apply_slow_status();
    virtual void apply_confusion_status();
    virtual void apply_movement_ailment(s32);
    virtual void apply_shock_status();
    virtual void clear_harmful_statuses();
    virtual void run_hit_reaction();
    virtual void run_death_reaction();
    // First-form phase dispatch and state helpers.
    void check_state_transition();
    void calc_target_position();
    void set_map_position(Vec *pos);
    void pick_target_position(Vec *target);
    void choose_next_attack();
    void apply_packed_state(u32 code);
    void send_darkfalz_code(s32 next_state, s32 next_slot, s32 next_turn);
    void send_state_to_target(s32 next_state);
    void calc_scaled_field(s32 from_angle, s32 to_angle);
    f32 calc_wave_offset(f32 t);
    void set_motion_index(s32 index);
    void calc_scale_slot_indices(s32 *next_slot, s32 *next_turn);
    void set_state(s32 next_state);
    void update_tenchu();
    void advance_tenchu();
    void init_timer();
    void update_tech_charge();
    void update_scale_state();
    void init_child_and_set_timer();
    void update_attack_countdown();
    void update_state();
    void set_motion_for_state();
    void tick_countdown_set_state7();
    void update_spawn_uro();
    void start_motion_for_index();
    void tick_state_398_timer();
    void update_dead_idle();
    void init_dead_state();
    void update_move_stnd_pos();
    void update_state_transition();
    void init_movestndpos_state();
    void update_flag800_state();
    void update_appear();
    void check_state_if_idle();
    void init_appear_state();
    void update_effect_positions();
    void send_move_stnd_pos();
    s32 calc_slot_angle(s32 slot, s32 turn);
    void set_pos_from_scaled_offset(Vec *from, Vec *to);
    void update_radar_markers();
    void snapshot_position();
    void render_effects();
    void update_boss4_phase_timer();
    void draw_parts();
    void push_players_out_of_colliders();
    void update_collision_bodies();
    void update_follow_camera_offsets();
    static TBoss4Type1 *create(TBoss4FormSetData *set_data);
    s32 get_state();

    // Field names inferred from their uses in TBoss4Type1.cpp; the twin TBoss4Type2 corroborates
    // owner/archive/collision_body_parts, grid_*, hit, half_hp, hit_flash, hp_ratio and anim*.
    s32 state;                    // row of the boss4_type1_states state table (set_state)
    ModelNodeTables model_nodes;
    TBoss4DarkFalz *owner;        // params[0], the Dark Falz that spawns it; run_task waits on it
    BmlResource *archive;
    CollisionBody *collision_body_parts; // init_collision_body_parts(boss4_type1_collision_body_desc, 3)
    s32 state_timer;              // frames left in the current state
    f32 move_ratio;               // calc_wave_offset of the move progress, 0 at prev_slot
    s32 slot;                     // one of the four stand positions (boss4_type2_motion_vec_table)
    s32 prev_slot;
    s32 turn;                     // 0..2: quarter turn left, none, right (calc_slot_angle)
    s32 prev_turn;
    s32 grid_x;                   // set_map_position: grid cell x
    s32 grid_z;                   // set_map_position: grid cell z
    Vec grid_target;              // calc_target_position; Ra Barta / Ra Foie aim here
    s32 uro_limit;                // shared boss param 0x39 +0x18, clamped to 1..6
    s32 uro_count;                // Uros spawned in the current HAKILOOP
    s32 move_frames;              // boss param move_seconds (1..60, else 25) times 30
    s32 collider_count;           // boss4_type1_xz_offset_table rows pushing players out
    s32 hit;                      // set by run_hit_reaction, cleared once drawn
    s32 half_hp;                  // half the starting hp
    f32 hit_flash;
    f32 hp_ratio;                 // run_task: hp / referenceHp
    s32 anim;                     // row of boss4_type1_motion_states
    f32 anim_frame;
    f32 anim_speed;
    s32 anim_mode;
    s32 anim_looped;
    TParticleCtrl *parts[13];     // particle effects, released by the dt
    ModelNodePositionCapture *node_captures[3];
    Vec node_positions[3][2];     // node_captures' captured node positions
    ModelNodePositionCapture *core_capture;
    Vec core_positions[2];        // core_capture's captured node positions
};

LAYOUT_ASSERT(TBoss4Type1_parts, offsetof(TBoss4Type1, parts) == 0x3F8);
LAYOUT_ASSERT(TBoss4Type1_grid_target_offset, offsetof(TBoss4Type1, grid_target) == 0x3B8);
LAYOUT_ASSERT(TBoss4Type1_anim_offset, offsetof(TBoss4Type1, anim) == 0x3E4);
LAYOUT_ASSERT(TBoss4Type1_size, sizeof(TBoss4Type1) == 0x49C);

extern "C" {
void pick_tenchu_furu_spots();
void pick_tenchu_furu_spots_around(const Vec *center, f32 min_dist);
}

// Scene archive ids of the six Dark Falz body models.
extern s32 boss4_type1_model_ids[];

#endif
