#ifndef PSO_BOSS_BARBARAY_TBOSS7DEROLLEC_H
#define PSO_BOSS_BARBARAY_TBOSS7DEROLLEC_H

#include "types.h"

struct NJS_OBJECT;
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/derolle/TUnk_80036250.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/ControllerInputState.h"
#include <dolphin/mtx.h>

struct AnimationMotion;
struct NJS_TEXLIST;
struct TBoss7Joint;
class TBoss7Tentacle;
class TBoss7LaserLight;
class AreaAttackHistory;
class TUnk_804F1C58;
class TParticleCtrl;
class TUnk_804E4788;
struct G_BarbaRayBossActions_6xA9;
struct G_BarbaRayBossActions_6xAA;
struct TBoss7LaserPtcl;

// Boss parameter block 15 from TLobby::dispatch_shared_handler_a.
struct TBoss7DeRolLeCParams {
    f32 laser_power;              // the laser hit's attack power (handle_laser_attack_state)
    f32 target_pos_y;             // TBoss7PhotonBullet::get_target_pos_y
    u8 pad_08[0x10];
    s32 body_hp;                  // TBoss7DeRolLeC::body_hp's start
    s32 shell_max_hp;             // TBoss7Joint_get_shell_max_hp
    s32 shell_hp;                 // TBoss7DeRolLeC::shell_hp's start
};

// An s32 rotation triple (x, y, z) as a set entry stores it.
struct Boss7Angles { s32 x, y, z; };

struct TBoss7DeRolLeC : public TObjEneDD_ST {
    TBoss7DeRolLeC(TObject *parent, void *set_data);
    virtual ~TBoss7DeRolLeC();
    void update_projectile_spawns();
    virtual void run_task();
    virtual void render();
    virtual void dispatch_action(u32 state, s32 reason);
    void update_or_dispatch();
    void flee_if_disturbed();
    void set_state_and_send(s32 state);
    static NJS_TEXLIST *get_archive_textures();
    static NJS_OBJECT *get_archive_model(s32 index);
    void emit_hit_effect(const Vec *position);
    s32 is_ready();                // name from the TBoss2DeRolLe twin
    void start_death_sequence();  // once is_ready: the death or deep-sink state, unless one runs (inferred name)
    void handle_position_travel_state(u32 event, s32 mode, s32 next_mode);
    void advance_action_sequence();
    // Resets the node-walk state that record_node_transforms advances during a draw.
    void reset_node_transforms();
    // Draw callback of the body model: counts the nodes and records the points and
    // matrices of the ones the boss tracks.
    static void record_node_transforms(NJS_OBJECT *node);
    void set_flag_800();
    virtual void update_body_colliders();
    virtual void render_shadows();
    void run_death_reaction();
    void run_hit_reaction();
    void run_miss_reaction();
    void clear_harmful_statuses();
    void apply_shock_status();
    void apply_movement_ailment(s32);
    void apply_confusion_status();
    void apply_slow_status();
    void apply_paralysis();
    void apply_poison_status();
    void refresh_target();
    void sync_position_vectors();
    void update_wobble_angle();
    s32 is_all_parts_done();
    u32 update_anim_state();
    u32 update_phase_settling();
    u32 update_tail_anim_state();
    u32 update_phase_rising();
    void turn_on_laser_light();
    void turn_off_laser_light();
    void pick_random_target();
    void set_all_intangible();  // the body and its ten joints (inferred name)
    void clear_all_intangible();  // the body and its ten joints (inferred name)
    void apply_damage_and_set_effect(s32 damage, u16);
    void set_hooked_effect_target();
    void play_sound_at(s32 id, Vec *pos);
    void play_persistent_sound_at(s32 id, Vec *pos);
    void spawn_particle_201(Vec *pos);
    void set_position_index(s32 index);
    void set_swim_direction(s32);
    f32 calc_node_height();
    void destroy_child();
    void update_attached_orientation();
    void handle_death_state(u32 event);
    void handle_despawn_state(u32 event);
    void handle_opening_state(u32 event);
    void handle_retract_tentacles_state(u32 event);
    void handle_extend_tentacles_state(u32 event);
    void handle_tentacle_needle_barrage_state(u32 event);
    void retract_all_tentacles();
    void extend_all_tentacles();
    void handle_surface_state(u32 event, s32);  // undoes handle_deep_sink_state (inferred name)
    void handle_deep_sink_state(u32 event);
    void handle_crawfish_spawn_state(u32 event, s32 variant);
    void handle_crawfish_drain_state(u32 event);
    void handle_wait_state(u32 event);
    void spawn_photon_pad(s32 joint, s32 shot_level);
    void handle_photon_pad_spawn_state(u32 event, s32 position_index);
    void handle_ceiling_attack_state(u32 event);
    void calc_offset_position();   // name from the TBoss2DeRolLe twin: laser_light_pos = 30 units along the head axis
    void handle_laser_attack_state(u32 event);
    void handle_tentacle_attack_state(u32 event, s32 position_index);
    void handle_roll_dive_state(u32 event, s32 position_index);
    void sub_802EC32C();
    void reload_stats_for_phase(s32 phase);
    void update_particle_ctrls();
    void release_splash_particles(TParticleCtrl *ctrl);
    // The ten joints' model nodes: save_joint_polygons keeps their polygon lists, hide_joint_polygons
    // clears one joint's pair while it draws, restore_joint_polygons puts them back.
    void save_joint_polygons();
    void hide_joint_polygons(s32 joint);
    void restore_joint_polygons();
    void calc_joint_positions();
    s16 find_free_crawfish_slot();
    void spawn_crawfish_child(s16 slot, const Vec *position, Boss7Angles *angle, s32 flags);
    void try_spawn_pattern_crawfish(s32 variant, s32 index);
    void handle_intro_camera_state(u32 event);
    void handle_debug_pad_input(u32 event); // name from the TBoss2DeRolLe twin; reads controller 2 (debug_pad)
    void handle_forward_jump_state(u32 event);
    void handle_bite_state(u32 event, s32 position_index);
    // 6xA9/6xAA receivers; names from the TBoss2DeRolLe twin (init_from_param, set_params)
    void init_from_param(G_BarbaRayBossActions_6xA9 *cmd);
    void set_params(G_BarbaRayBossActions_6xAA *cmd);
    // a particle at pos, lifted and pulled back along the camera's view (name from the TBoss2DeRolLe twin)
    static void spawn_offset_particle(const Vec *pos, f32 lift, f32 back);
    void reset_action_sequence();  // zeroes pad_6B0 and action_index (inferred name)
    void handle_side_jump_state(u32 event, s32 position_index, s32 next_index);
    void handle_tentacle_volley_state(u32 event, s32 position_index);
    CollisionBody collision_body; // copy of boss7_derolle_c_collision_body, the body's collision sphere
    Vec node_positions[20];       // the boss7_derolle_c_body_point_node_ids nodes, recorded while the body draws
    Vec part_points[4];           // boss7_derolle_c_part_points: [0] the head, [1] its axis (calc_offset_position)
    Vec sound_origins[3];         // project_sound_origin_from_camera of position and node 18, and their midpoint
    Vec joint_positions[10];      // one per TBoss7Joint in joints (field names from the TBoss2DeRolLe twin)
    s16 *joint_polygons[10];      // polygon lists of the boss7_derolle_c_joint_node_ids nodes, saved by the ctor
    s16 *shell_polygons[10];      // polygon lists of the boss7_derolle_c_shell_node_ids nodes
    TBoss7Joint *joints[10];
    TBoss7DeRolLeCParams *boss_params; // TLobby::dispatch_shared_handler_a(15)
    ControllerInputContext *debug_pad; // controller_input_state.controllers[1], read by handle_debug_pad_input
    s32 state_flags;              // 0x4, 0x8 shell broken, 0x40/0x80 breakup pieces, 0x8000 already beaten
    s32 stat_phase;               // the stat phase reload_stats_for_phase restores after a hit
    TUnk_80036250 motion_x;       // drives position.x (handle_position_travel_state)
    TUnk_80036250 motion_y;       // drives position.y
    TUnk_80036250 motion_z;       // drives position.z
    TObject part_group;           // embedded task group: the ctor builds it with TObject(TObject *), run_task/render walk it
    s32 debug_pad_active;         // run_task steps run_mode from debug_pad when set
    s32 pad_6B0;
    s32 action_index;             // step in boss7_derolle_c_difficulty_actions[difficulty][], advanced by advance_action_sequence
    s32 run_mode;                 // 0 runs the action sequence, 1 holds it (lobby not ready), 2 checks is_ready only
    s32 loop_sound_frames;        // frames the body's looping sound has played (update_projectile_spawns)
    s32 position_slot;            // the boss7_derolle_c_position_points point the body is at or leaves (inferred name)
    s32 next_position_slot;       // the boss7_derolle_c_position_points point it moves to (handle_position_travel_state)
    s32 travel_step_zx;           // step of the moves that run motion_z, then motion_x (update_anim_state)
    s32 motion_y_done;            // set once motion_y finishes the running move
    s32 travel_step_xz;           // step of the moves that run motion_x, then motion_z (update_phase_settling)
    GC_Mtx *node_matrices;        // 12 matrices, mem_alloc'd by the ctor (freed by the destructor)
    GC_Mtx *tentacle_matrices;    // 4 matrices, one per tentacle root (freed by the destructor)
    TBoss7Tentacle *tentacles[4]; // released by the destructor
    Vec body_offset;              // added to position for the body's model matrix (run_task)
    s32 body_max_hp;              // boss_params->body_hp
    s32 body_hp;                  // drained by hits once the shell is broken; at 0 is_ready turns true
    s32 shell_hp;                 // drained by hits while the shell is whole; at 0 set_hooked_effect_target breaks it
    s32 photon_pad_level;         // 0-2, cycled by handle_photon_pad_spawn_state; spawn_photon_pad's shot_level
    TBoss7LaserLight *laser_light;
    Vec laser_light_pos;          // the position the laser light follows
    AreaAttackHistory *attack_history;
    TUnk_804E4788 *hit_trail;     // ring trail of the laser's hit point (limit 6, effect 0x208)
    TUnk_804E4788 *hit_trail_long; // the same with limit 15, effect 0x209
    s32 laser_shot_count;         // laser shots since the state that clears it
    s32 state_step;               // the running state's step (every state handler switches on it)
    s32 state_ints[6];            // per-state scratch: each state handler gives them its own meaning
    f32 state_floats[10];         // per-state scratch, as state_ints
    Vec state_vectors[2];         // the laser's aim (the target's position, or the origin) and the beam's hit point
    TParticleCtrl *state_emitter; // the running state's emitter (0x161 on nodes 7/8 in handle_bite_state); released by the destructor
    TParticleCtrl *splash_ctrls[6]; // splash emitters kept on the joints (update_particle_ctrls); released by the destructor
    s32 splash_joint;             // when set, the joint the first splash pair moves to for one update
    TObject *crawfish_parent;     // the group spawned crawfish are children of
    TBoss7LaserPtcl *laser_ptcl;
    TUnk_804F1C58 *node_recorder; // walks the body model with record_node_transforms each run_task
    TParticleCtrl *aimed_emitter; // effect 0x20F; destroy_child releases it, update_attached_orientation aims it
    Vec emitter_points[2];        // boss7_derolle_c_emitter_points: where aimed_emitter sits, and the point it is aimed away from
    u16 needle_targets[4];        // client ids of the players handle_tentacle_needle_barrage_state sends a TBoss7TentacleNeedle under
    static void load_resources();
    static void run_exit_callbacks();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TBoss7DeRolLeCCollisionBody, offsetof(TBoss7DeRolLeC, collision_body) == 0x3C0);
LAYOUT_ASSERT(TBoss7DeRolLeCPartGroup, offsetof(TBoss7DeRolLeC, part_group) == 0x690);
LAYOUT_ASSERT(TBoss7DeRolLeCActionIndex, offsetof(TBoss7DeRolLeC, action_index) == 0x6B4);
LAYOUT_ASSERT(TBoss7DeRolLeCTentacleMatrices, offsetof(TBoss7DeRolLeC, tentacle_matrices) == 0x6D8);
LAYOUT_ASSERT(TBoss7DeRolLeCTentacles, offsetof(TBoss7DeRolLeC, tentacles) == 0x6DC);
LAYOUT_ASSERT(TBoss7DeRolLeCNodeRecorder, offsetof(TBoss7DeRolLeC, node_recorder) == 0x7AC);
LAYOUT_ASSERT(TBoss7DeRolLeC_size, sizeof(TBoss7DeRolLeC) == 0x7D4);

// Globals of the De Rol Le C translation unit (802E7888-802EE814; .sbss/.bss).
extern "C" {
// 11 empty nodes chained through child (evalflags 0xF, the last 0x1F); render hangs
// them under model node 0x4D in place of its own child while state_flags & 0x40.
extern NJS_OBJECT boss7_derolle_light_pool[11];

void TObjPlayer__sub_802ED984(void);
}

// Functions defined in TBoss7DeRolLeC.cpp.
struct TObjEneDD;
s32 TBoss7Joint_get_shell_max_hp(void);
void handle_6xA9_barba_ray_boss_actions(void *arg0);
void handle_6xAA_barba_ray_boss_actions(void *arg0);
extern "C" {
AnimationMotion *get_boss7_motion(s32 kind);
}

#endif
