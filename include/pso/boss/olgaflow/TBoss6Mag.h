#ifndef PSO_BOSS_OLGAFLOW_TBOSS6MAG_H
#define PSO_BOSS_OLGAFLOW_TBOSS6MAG_H

#include "types.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/player/PlayerAttackParams.h"

class BmlResource;
class ModelNodePositionCapture;
struct AnimationMotion;
struct TBoss6Type2;
struct TParticleCtrl;

// The spawn record TBoss6Type2 hands to create_mag: the enemy set data apply_set_data reads, then the mag's
// owner and placement.
struct TBoss6MagSpawnParams {
    s16 x;
    u8 pad_2[4];
    u16 z;
    s16 active;
    u8 pad_a[6];
    Vec pos;
    u8 pad_1c[0x24];
    TBoss6Type2 *owner;
    Vec origin;
    s32 rotation_y;
    s32 index;
    u32 flags;
    s32 variant;
};

struct TBoss6MagMotionTrack {
    AnimationMotion *motion;
    f32 frame;
    f32 speed;
    f32 blend;
    f32 blend_step;
    AnimationMotion *prev_motion;
    f32 prev_frame;

    void copy_state(TBoss6MagMotionTrack *src);
};

struct TBoss6MagMotion {
    s32 index;
    s32 mode;
    TBoss6MagMotionTrack track;

    TBoss6MagMotion *copy_from(const TBoss6MagMotion *src);
};

struct TBoss6MagRamp {
    f32 aim;
    f32 charge;
};

struct TBoss6MagTarget {
    u16 client_id;
    s32 on_shoulder;
};

struct TBoss6Mag : public TObjEnemy {
    TBoss6Mag(TObject *parent, TBoss6MagSpawnParams *params);
    virtual ~TBoss6Mag();
    virtual void run_task();
    virtual void render();
    virtual f32 receive_physical_attack(void *attacker, f32 scale);
    virtual f32 receive_direct_attack(void *attacker, DirectAttackPayload payload, void *collision, s32 tech, s32 flags);
    virtual void run_hit_reaction();
    virtual void run_death_reaction();

    void set_on_shoulder(s32 on_shoulder);
    void set_action_field_0x408(u16 client_id);
    void set_target_nodes(u32 flags, s32 variant);
    void set_anim_frame(TBoss6Mag *partner);
    s32 is_phase_active();
    void destroy_part_object(s32 index);
    void ensure_particle_emitter(s32 index);
    void update_effect_positions();
    void update_state_effects();
    void update_all_parts();
    void clear_particle_emitters();
    s32 step_angle_toward(s32 from, s32 to, s32 turn);
    s32 apply_direction_sign(s32 turn);
    f32 apply_direction_sign(f32 value);
    void enforce_min_distance();
    void push_out_from_points();
    void push_out_from_target();
    void compute_random_dir_vec(Vec *out, s32 yaw, s32 pitch);
    s32 calc_dir_angles(s32 *yaw, s32 *pitch, Vec *dir);
    s32 is_target_in_front_range();
    s32 is_action_ready();
    void update_rotation_ramp();
    void init_with_global_table();
    void spawn_mag_mines();
    void set_path_points(Vec *points, s32 count);
    static void set_path_points_by_index(s32 index, Vec *points, s32 count);
    void spawn_falling_rocks();
    void revive();
    void apply_random_drift();
    void turn_toward_target();
    s32 fly_toward_target();
    s32 snap_to_shoulder();
    void update_segment_angles();
    void init_segment_angle_range();
    void decay_glow_and_calc_hp_ratio();
    void sync_hp_apply_damage();
    void sync_hp();
    void draw_model_motion_blend();
    void change_motion(s32 motion);
    void update_motion_playback();
    void init_motion_state();
    void set_action(s32 action);
    void save_position();
    void render_body_effects();
    void spawn_trap_by_stat();

    void update_revival();
    void act_revival();
    void update_dead();
    void act_dead();
    void update_shoot();
    void act_shoot();
    void update_chase_pl();
    void act_chase_pl();
    void update_set_shoulder();
    void act_set_shoulder();
    void update_start();
    void act_start();

    BmlResource *scene_archive;
    TBoss6Type2 *owner;
    TBoss6Mag *partner;
    s32 action;
    s32 index;
    s32 attackable;
    s32 initial_hp;
    s32 segment_variant;
    ActorParamBlock param_copy;
    s16 value_max;
    s16 value_min;
    TBoss6MagRamp ramp;
    s32 dead_duration;
    f32 chase_speed_scale;
    s32 frame_counter;
    s32 action_timer;
    u8 pad_3d0[4];
    TBoss6MagMotion motion_state;
    f32 hit_flash;
    f32 hp_ratio;
    f32 fade;
    s32 synced_hp;
    TBoss6MagTarget chase_target;
    s32 mines_spawned;
    s32 mine_count;
    Vec mine_targets[3];
    TParticleCtrl *emitters[4];
    Vec node_positions[1];
    ModelNodePositionCapture *capture;
};

LAYOUT_ASSERT(TBoss6Mag_offset_param_copy, offsetof(TBoss6Mag, param_copy) == 0x394);
LAYOUT_ASSERT(TBoss6Mag_offset_motion_state, offsetof(TBoss6Mag, motion_state) == 0x3D4);
LAYOUT_ASSERT(TBoss6Mag_offset_chase_target, offsetof(TBoss6Mag, chase_target) == 0x408);
LAYOUT_ASSERT(TBoss6Mag_offset_capture, offsetof(TBoss6Mag, capture) == 0x458);
LAYOUT_ASSERT(TBoss6Mag_size, sizeof(TBoss6Mag) == 0x45C);

// One row per action: its name, the motion set_action starts, whether the mag can be hit, and the handlers
// set_action (enter) and run_task (update) call.
struct TBoss6MagAction {
    const char *name;
    s32 motion;
    s32 attackable;
    void (TBoss6Mag::*enter)();
    void (TBoss6Mag::*update)();
};

extern TBoss6MagAction boss6_type2_action_table[6];

void copy_mag_ramp(TBoss6MagRamp *dst, TBoss6MagRamp *src);
void copy_mag_target(TBoss6MagTarget *dst, TBoss6MagTarget *src);

#endif
