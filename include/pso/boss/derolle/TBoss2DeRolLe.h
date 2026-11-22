#ifndef PSO_BOSS_DEROLLE_TBOSS2DEROLLE_H
#define PSO_BOSS_DEROLLE_TBOSS2DEROLLE_H

#include "types.h"

struct NJS_OBJECT;
struct BmlResource;
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/derolle/TUnk_80036250.h"
#include "pso/system/ControllerInputState.h"
#include "pso/system/NinjaTypes.h"
#include <dolphin/mtx.h>
#include "pso/network/protocol/protocol_types.h"

struct TBoss2Joint;
class TBoss2Tentacle;
class TBoss2Fin;
class TObjChara;
class TParticleCtrl;
struct TBoss2LaserLight;
class TUnk_80482EC0;
class TUnk_80482D04;
class TUnk_80482C58;
class AreaAttackHistory;

// The boss's models and motions, loaded from bm_boss2_de_rol_le(_a).bml by load_resources.
extern BmlResource *boss2_derolle_resource;

// The 6x13 subcommand: the boss's new action state (handle_6x13_de_rol_le_boss_actions).
struct DeRolLeActionPacket {
    G_ClientIDHeader header;
    s16 state;
    s16 sequence_index;
};

// The 6x14 subcommand: 6x13 plus the target (handle_6x14_de_rol_le_boss_actions_with_target).
struct DeRolLeActionTargetPacket {
    G_ClientIDHeader header;
    s16 state;
    s16 sequence_index;
    s32 target_id;
};

// Boss parameter block 15 from TLobby::dispatch_shared_handler_a (TBoss7DeRolLeCParams is its twin).
struct TBoss2DeRolLeParams {
    f32 laser_power;              // the laser hit's attack power
    f32 bullet_power;             // TBoss2PhotonBullet's attack power
    f32 mine_power;               // TBoss2Mine's hit power
    f32 ceil_junk_drift;          // x drift per elapsed frame of a dropped TObjBoss2CeilJunk
    f32 ceil_junk_chance;         // per-frame chance of dropping one during the ceiling run
    u8 pad_14[4];
    s32 body_hp;                  // TBoss2DeRolLe::body_hp's start
    s32 shell_max_hp;             // TBoss2Joint's shell hp
    s32 shell_hp;                 // TBoss2DeRolLe::shell_hp's start
    s32 volley_interval;          // frames between tentacle volleys in v2 mode (else 180)
    s32 volley_hold_time;         // start_attack_at_target's hold_time in v2 mode (else 120)
};

struct TBoss2DeRolLe : public TObjEneDD_ST {
    TBoss2DeRolLe(TObject *parent, void *set_data);
    virtual ~TBoss2DeRolLe();
    virtual void run_task();
    virtual void render();
    virtual void refresh_target();
    virtual void apply_poison_status();
    virtual void apply_paralysis();
    virtual void apply_slow_status();
    virtual void apply_confusion_status();
    virtual void apply_movement_ailment(s32);
    virtual void apply_shock_status();
    virtual void clear_harmful_statuses();
    virtual void run_miss_reaction();
    virtual void run_hit_reaction();
    virtual void run_death_reaction();
    virtual void dispatch_action(u32 state, s32 reason);
    virtual void update_body_colliders();           // refreshes the colliders from the body's offsets
    virtual void enable_body_collision();
    virtual int vfunc_105();
    virtual void render_body();
    static TBoss2DeRolLe *get_instance();
    static void *create(void *set_data);
    static void load_resources();
    static void reset_parts();
    void advance_phase_wrap();
    void backup_pos();
    // Plays sound id at pos as a persistent sound owned by owner.
    static s32 spawn_trap(s32 id, void *owner, Vec *pos);
    void clear_play_flags();
    s32 update_phase_is_done();
    void init_movement();
    s32 update_phase_settling();
    void init_move_params();
    s32 update_state();
    void init_wave_params();
    s32 update_phase_rising();
    void spawn_photon_pad(s32 joint, s32 level);
    void calc_offset_position();
    void activate_laser_light();
    void free_laser();
    void apply_hp_damage_with_sound(s32 damage, u16);
    void set_flags_play_sound();
    static void spawn_offset_particle(Vec *position, f32 height, f32 distance);
    void set_state_and_send(s32 state);
    s32 is_ready();
    void start_death_sequence();  // once is_ready: the death or deep-sink state, unless one runs (inferred name)
    void advance_action_sequence();
    void update_or_dispatch();
    void set_position_index(s32 index);
    void pick_random_target();
    void set_all_intangible();  // the body and its ten joints (inferred name)
    void clear_all_intangible();  // the body and its ten joints (inferred name)
    void handle_opening_state(u32 reason);
    void handle_surface_state(u32 reason, s32 arg2);  // undoes handle_deep_sink_state (inferred name)
    void handle_deep_sink_state(u32 reason);
    void handle_despawn_state(u32 reason);
    void reload_stats_for_phase(s32 kind);
    void set_move_target_point(s32 index);
    void update_angle();
    void init_head_params();
    void state_photon_pads(u32 reason, s32 position);
    void state_launch_mines(u32 reason, s32 state);
    void state_ceiling_attack(u32 reason);
    void spawn_ceil_junk(Vec *pos);
    void update_particle_ctrls();
    void release_splash_particles(TParticleCtrl *ctrl);
    void update_projectile_spawns();
    void sub_800338BC();
    void update_pulsing_colors();
    void handle_roll_dive_state(u32 reason, s32 side);
    void set_move_direction(s32 side);
    void handle_tentacle_volley_state(u32 reason, s32 side);
    void handle_ceiling_pass_state(u32 reason);
    void handle_debug_pad_input(u32 reason);
    void handle_position_travel_state(u32 reason, s32 from, s32 to);
    f32 calc_node_height();
    void get_node_world_pos(Vec *out);
    void handle_side_jump_state(u32 reason, s32 from, s32 to);
    void handle_forward_jump_state(u32 reason);
    void handle_bite_state(u32 reason, s32 side);
    void handle_death_state(u32 reason);
    void handle_intro_camera_state(u32 reason);
    void handle_laser_attack_state(u32 reason);
    static void forward_switch_phase_stats(TObjChara *victim);
    // The parameter block's attack powers and shell hp, for the parts the boss spawns.
    static f32 get_bullet_power();
    static f32 get_mine_power();
    static s32 get_shell_max_hp();
    void switch_phase_stats(TObjChara *victim);
    void emit_effect_and_step(Vec *pos);
    // 6x13/6x14 senders and receivers (the TBoss7DeRolLeC twin's are G_BarbaRayBossActions_6xA9/6xAA members)
    static void init_6x14(DeRolLeActionTargetPacket *packet);
    static void update_and_send(DeRolLeActionTargetPacket *packet);
    static void init_6x13(DeRolLeActionPacket *packet);
    static void send_6x13(DeRolLeActionPacket *packet);
    static void swap_6x13_fields(DeRolLeActionPacket *packet);
    static void swap_endian(DeRolLeActionTargetPacket *packet);
    void init_from_param(DeRolLeActionPacket *packet);
    void set_params(DeRolLeActionTargetPacket *packet);
    void reset_action_sequence();
    s32 state_flags;                   // 0x8 shell broken, 0x40/0x80 breakup pieces, 0x8000 already beaten
    s32 stat_phase;                    // the stat phase reload_stats_for_phase restores after a hit
    s32 debug_pad_active;              // handle_debug_pad_input drives the boss from debug_pad when set
    ControllerInputContext *debug_pad; // controller_input_state.controllers[1]
    s32 pad_3D0;
    s32 action_index;                  // the action sequence step, sent in the 6x13/6x14 packets
    TObject part_group;                // parent of the tentacles, mines, fin and laser light
    s32 run_mode;                      // 0 runs the action sequence, 1 holds it (lobby not ready), 2 checks is_ready only
    Vec node_positions[20];            // the derolle_position_node_ids nodes, recorded while the body draws
    Vec part_points[4];                // derolle_part_transform_template placed on node 0x33; [1] made relative to [0]
    Vec sound_origins[3];              // project_sound_origin_from_camera of position and node 18, and their midpoint
    s32 loop_sound_frames;             // frames the body's looping sound has played (update_projectile_spawns)
    Vec joint_positions[10];           // one per TBoss2Joint in joints
    s32 pad_5B8[10];
    TBoss2Joint *joints[10];
    NJS_ARGB body_color;               // white; copied to derolle_capture_color while the body draws
    GC_Mtx *node_matrices;             // 12 matrices of nodes 0x4D-0x58, recorded while the body draws
    GC_Mtx *tentacle_matrices;         // one per tentacle root
    TBoss2Tentacle *tentacles[4];
    TUnk_80482EC0 *mines[5];
    TUnk_80482D04 *target_mines[3];  // launched at the target (init_launch)
    TBoss2Fin *fin;
    s32 position_index;
    s32 next_position_index;           // where the running move ends; it becomes position_index
    s32 travel_step_zx;                // step of the moves that run motion_z, then motion_x (update_phase_is_done)
    s32 travel_step_xz;                // step of the moves that run motion_x, then motion_z
    TUnk_80036250 motion_x;            // drives position.x (TBoss7DeRolLeC's motion_x)
    TUnk_80036250 motion_z;            // drives position.z
    f32 height_offset;                 // body height the render matrix is translated by (render)
    s32 body_max_hp;                   // derolle_params[0]->body_hp
    s32 body_hp;                       // drained by hits once the shell is broken; at 0 is_ready turns true
    s32 shell_hp;                      // drained by hits while the shell is whole; at 0 the shell breaks (state_flags 0x88)
    s32 photon_pad_level;              // 0-2, cycled by state_photon_pads; TBoss2PhotonPad's level
    TBoss2LaserLight *laser_light;
    Vec laser_light_pos;               // the position the laser light follows
    AreaAttackHistory *attack_history;
    TUnk_80482C58 *hit_trail;          // ring trail of the laser's hit point (limit 6, effect 0x124)
    TUnk_80482C58 *hit_trail_long;     // the same with limit 15, effect 0x125
    f32 pulse_phase;                   // 0..2, advanced by pulse_speed (advance_phase_wrap)
    f32 pulse_speed;
    s32 laser_shot_count;              // laser shots since the state that clears it; 4 ends the laser runs
    s32 state_step;                    // the running state's step (every state handler switches on it)
    s32 state_ints[6];                 // per-state scratch: each state handler gives them its own meaning
    f32 state_floats[10];              // per-state scratch, as state_ints
    Vec state_vectors[2];              // per-state scratch: handle_intro_camera_state's node offset; the laser's aim and hit point
    TParticleCtrl *state_emitter;      // the running state's emitter: 0x161 on nodes 7/8 (bite), 0x122/0x177 (laser)
    TParticleCtrl *splash_ctrls[6];    // splash emitters kept on the joints (update_particle_ctrls)
    s32 splash_joint;                  // when set, the joint the first splash pair moves to for one update
};

LAYOUT_ASSERT(TBoss2DeRolLe_size, sizeof(TBoss2DeRolLe) == 0x75C);
extern "C" {
void derolle_capture_node_points(NJS_OBJECT *);
void derolle_begin_node_capture(TBoss2DeRolLe *boss);
void handle_6x13_de_rol_le_boss_actions(void *arg0);
void handle_6x14_de_rol_le_boss_actions_with_target(void *arg0);
s32 play_sound(s32 id, Vec *position);
}


#endif
