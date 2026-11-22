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
struct GinjaTextureList;
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
    f32 unk_00;                   // the laser's attack power (handle_laser_attack_state)
    f32 target_pos_y;             // TBoss7PhotonBullet::get_target_pos_y
    u8 pad_08[0x10];
    s32 unk_18;
    s32 shell_max_hp;             // TBoss7Joint_get_shell_max_hp
    s32 unk_20;
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
    void set_state_and_send(s32);
    static GinjaTextureList *get_archive_textures();
    static NJS_OBJECT *get_archive_model(s32 index);
    void emit_hit_effect(const Vec *position);
    s32 is_ready();                // name from the TBoss2DeRolLe twin
    void sub_802ECAA4();
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
    void sub_802ECC44();
    void sub_802ECBDC();
    void apply_damage_and_set_effect(s32 damage, u16);
    void set_hooked_effect_target();
    void play_sound_at(s32 id, Vec *pos);
    void play_persistent_sound_at(s32 id, Vec *pos);
    void spawn_particle_201(Vec *pos);
    void set_position_index(s32 index);
    void set_swim_direction(s32);
    f32 sub_802ED3E4();
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
    void sub_802E8EEC(u32 event, s32);
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
    void sub_802EC52C(TParticleCtrl *ctrl);
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
    void reset_action_sequence();  // zeroes unk_6B0 and action_index (inferred name)
    void handle_side_jump_state(u32 event, s32 position_index, s32 next_index);
    void handle_tentacle_volley_state(u32 event, s32 position_index);
    CollisionBody unk_3C0;        // copy of boss7_derolle_c_collision_body, the body's collision sphere
    Vec unk_3EC[20];
    Vec unk_4DC[4];
    Vec unk_50C[3];               // effect source passed to TObjFish::set_effect_target_position
    Vec joint_positions[10];      // one per TBoss7Joint in joints (field names from the TBoss2DeRolLe twin)
    s16 *joint_polygons[10];      // polygon lists of the boss7_derolle_c_joint_node_ids nodes, saved by the ctor
    s16 *shell_polygons[10];      // polygon lists of the boss7_derolle_c_shell_node_ids nodes
    TBoss7Joint *joints[10];
    TBoss7DeRolLeCParams *unk_620; // TLobby::dispatch_shared_handler_a(15)
    ControllerInputContext *debug_pad; // controller_input_state.controllers[1], read by handle_debug_pad_input
    s32 state_flags;              // 0x4, 0x8, 0x40, 0x80, 0x8000 tested
    s32 unk_62C;                  // the stat phase reload_stats_for_phase restores after a hit
    TUnk_80036250 motion_x;       // drives position.x (handle_position_travel_state)
    TUnk_80036250 motion_y;       // drives position.y
    TUnk_80036250 motion_z;       // drives position.z
    TObject part_group;           // embedded task group: the ctor builds it with TObject(TObject *), run_task/render walk it
    s32 unk_6AC;
    s32 unk_6B0;
    s32 action_index;             // step in boss7_derolle_c_difficulty_actions[difficulty][], advanced by advance_action_sequence
    s32 unk_6B8;
    s32 unk_6BC;
    s32 position_slot;            // the boss7_derolle_c_position_points point the body is at or leaves (inferred name)
    s32 next_position_slot;       // the boss7_derolle_c_position_points point it moves to (handle_position_travel_state)
    s32 unk_6C8;
    s32 unk_6CC;
    s32 unk_6D0;
    GC_Mtx *unk_6D4;                 // 12 matrices, mem_alloc'd by the ctor (freed by the destructor)
    GC_Mtx *tentacle_matrices;    // 4 matrices, one per tentacle root (freed by the destructor)
    TBoss7Tentacle *tentacles[4]; // released by the destructor
    Vec unk_6EC;
    s32 unk_6F8;
    s32 unk_6FC;
    s32 unk_700;
    s32 unk_704;
    TBoss7LaserLight *laser_light;
    Vec laser_light_pos;          // the position the laser light follows
    AreaAttackHistory *attack_history;
    TUnk_804E4788 *unk_71C;       // ring trail of the laser's hit point
    TUnk_804E4788 *unk_720;
    s32 unk_724;
    s32 unk_728;                  // state step (handle_position_travel_state: 1 = arrived)
    s32 unk_72C;
    s32 unk_730;
    s32 unk_734;
    s32 unk_738;
    s32 unk_73C;
    s32 unk_740;
    f32 unk_744;
    f32 unk_748;
    f32 unk_74C;
    f32 unk_750;
    f32 unk_754;
    f32 unk_758;
    f32 unk_75C;
    f32 unk_760;
    f32 unk_764;
    f32 unk_768;
    Vec unk_76C;                  // where the laser aims (the target's position, or the origin)
    Vec unk_778;                  // where the laser beam hits
    TParticleCtrl *unk_784;       // released by the destructor
    TParticleCtrl *unk_788[6];    // splash emitters kept on the joints (update_particle_ctrls); released by the destructor
    s32 unk_7A0;
    TObject *crawfish_parent;     // the group spawned crawfish are children of
    TBoss7LaserPtcl *unk_7A8;
    TUnk_804F1C58 *unk_7AC;
    TParticleCtrl *unk_7B0;       // destroy_child releases it, update_attached_orientation aims it
    Vec unk_7B4;                  // where unk_7B0 sits
    Vec unk_7C0;                  // the point unk_7B0 is aimed away from
    u16 needle_targets[4];        // client ids of the players handle_tentacle_needle_barrage_state sends a TBoss7TentacleNeedle under
    static void load_resources();
    static void run_exit_callbacks();
    static void *create(void *set_data);
};

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
