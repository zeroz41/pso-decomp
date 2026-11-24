#ifndef PSO_BOSS_OLGAFLOW_TBOSS6TYPE2_H
#define PSO_BOSS_OLGAFLOW_TBOSS6TYPE2_H

#include "pso/boss/Boss6ScrollStrips.h"
#include "types.h"
struct TBoss6Zanzo;
#include <stddef.h>
#include "pso/enemy/TObjEnemy.h"
#include "pso/player/PlayerAttackParams.h"
#include "pso/render/GinjaMaterialState.h"

class ModelNodePositionCapture;
struct OlgaFlowType2ActionMsg;
struct Boss6GridBytes;
struct NJS_OBJECT;
struct CollisionBody;
struct AnimationMotion;
struct TBoss6Mag;
struct TBoss6MagSpawnParams;
class TBoss6DPB;
struct TBoss6Type1;
struct TBoss6EffFlowSoul;
struct TBoss6PlotFalz;
struct TParticleCtrl;
struct BmlResource;
struct NJS_TEXLIST;

// One body model of the two the boss cross-fades between (state_progress).
struct TBoss6Type2Model {
    NJS_TEXLIST *texlist;
    NJS_OBJECT *model;
};

// One motion track; a change of motion blends from prev_motion over blend.
struct TBoss6Type2MotionTrack {
    AnimationMotion *motion;
    f32 frame;
    f32 speed;  // frames per update
    f32 blend;
    f32 blend_step;
    AnimationMotion *prev_motion;
    f32 prev_frame;
    void copy_from(TBoss6Type2MotionTrack *src);
};

// A head joint aim_toward_point turns: render adds aim_angle to the node's rest angle.
struct TBoss6Type2Joint {
    s32 *node_angle;  // Y angle of model node 0x28
    s32 rest_angle;
    s32 aim_angle;
};

struct Blk_802BCFD4;

// Where the body walks to: the heading and position a 6xA5 action decodes.
struct Boss6Type2MoveTarget {
    s32 heading;
    Vec position;
};

// A player's look: TObjPlayer's body, head and attachment texture lists and its body, head,
// hair and attachment models. grab_player saves the possessed player's look, draw draws it and
// restore_target_player_state puts it back; boss6_type2_player_snapshot_table keeps one per client.
struct Boss6PlayerLook {
    NJS_TEXLIST body_textures;
    NJS_TEXLIST head_textures;
    NJS_TEXLIST attachment_textures;
    void *model;
    void *head_model;
    void *hair_model;
    u32 attachment_model;
};

void copy_texlist(NJS_TEXLIST *dst, NJS_TEXLIST *src);

struct Boss6BodySpawnParams;

struct TBoss6Type2 : public TObjEnemy
{
    void update_collision_bodies();
    TBoss6Type2(TObject *parent, Boss6BodySpawnParams *params);
    virtual ~TBoss6Type2();
    virtual void run_task();
    virtual void render();
    virtual f32 receive_physical_attack(void *attacker, f32 scale);
    virtual f32 receive_direct_attack(void *attacker, DirectAttackPayload payload, void *collision, s32 tech, s32 flags);
    virtual void apply_poison_status();
    virtual void apply_paralysis();
    virtual void apply_slow_status();
    virtual void apply_confusion_status();
    virtual void apply_movement_ailment(s32);
    virtual void apply_shock_status();
    virtual void clear_harmful_statuses();
    virtual void run_hit_reaction();
    virtual void run_death_reaction();
    s32 is_active();
    void decay_glow_and_calc_hp_ratio();
    void update_head_aim();
    void update_camera();
    void update_possess_target();
    void restore_target_player_state();
    void reset_fish_fields();
    void damage_possessed_player();
    void aim_toward_point(const Vec *point);
    void render_body_effects();
    s32 action_state;  // row of boss6_type2_battle_actions (set_action_state)
    s32 action_history[32];  // set_action_state shifts the last 32 states in
    TBoss6PlotFalz *plot_falz;
    BmlResource *archive;  // TBoss6PlotFalz::get_scene_archive
    TBoss6Type2Model body_models[2];
    TBoss6Mag *mags[2];
    s32 berserk;  // CHG_TO_BSK sets it when its timer runs out, CHG_TO_CMN clears it
    f32 state_progress;  // 1 - state_timer / state_duration
    u32 berserk_wait_count;  // B_WAIT / B_BJ_WAIT entries since CHG_TO_BSK
    s32 low_hp;  // set once hp_ratio drops below 1/3 (trigger_screen_pos)
    u32 target_mode;   // OlgaFlowType2ActionMsg::target_mode
    s32 variant;       // boss6_type2_variant_id_table; set_target_state's second value
    u32 target_state;  // OlgaFlowType2ActionMsg::target_state
    // init_segment_range copies param_block here and points param_block at it.
    ActorParamBlock params_copy;
    s16 segment_max;  // the largest of the set entry's five segment values
    s16 segment_min;  // the smallest
    TBoss6Zanzo *trail_effect;
    saddr state_duration;  // what state_timer was last set to
    s32 state_timer;     // counts down to 0 in the state handlers
    u16 possess_target;  // CHG_TO_BSK's flow soul and TBoss6EffHyoui go to it; grab_player's id
    u16 target_client;   // pick_target_client; pick_walk_target walks to it
    u16 first_action_client;   // mags[0]'s (OlgaFlowType2ActionMsg)
    u16 second_action_client;  // mags[1]'s
    s32 last_walk_def;  // 1 after a WALK_DEF* state, 0 after WALK_CMN*: the walks alternate
    s32 iai_count;      // IAI_* entries since the last BKJUMP (should_back_jump at 3)
    u32 action_flags;  // the action row's flags (update_parts_flags)
    u8 random_factor;  // OlgaFlowType2ActionMsg::random_factor
    u8 unk_479[0x3];
    u32 next_motion;   // OlgaFlowType2ActionMsg::next_motion
    Boss6Type2MoveTarget move_target;
    s32 motion_index;  // row of TBoss6Type2__motion_table
    s32 motion_mode;   // that row's mode
    TBoss6Type2MotionTrack motion_tracks[1];
    s32 rock_damage;            // base damage of a rock pushed into a player, name inferred
    s32 possessed_damage;       // what a hit on the boss does to the possessed player, name inferred
    s32 dpb_damage_threshold;   // should_use_dpb: damage_total at which the DPB state is used
    s32 berserk_damage;         // damage since latched_hp that sends the boss berserk
    s32 release_damage;         // is_phase_complete: damage since latched_hp that ends berserk
    s32 kamae_duration;         // KAMAE's state_timer
    s32 iai_x2_percent;         // choose_random_motion's chance of the x2 IAI rows
    s32 iai_x3_percent;         // and of the x3 rows
    s32 bj_wait_duration;       // B_BJ_WAIT's state_timer
    f32 base_walk_speed;        // set_screen_pos's walk and turn motion speeds
    f32 base_turn_speed;
    f32 low_hp_walk_speed;
    f32 low_hp_turn_speed;
    f32 berserk_damage_scale;  // scales rock_damage while berserk
    s32 info_stat_duration;     // INFO_STAT's state_timer
    s32 latched_hp;    // copy_anim_state stores hp; calc_field4f0_delta returns the damage since
    s32 damage_total;  // add_damage sums it (doubled in some states)
    u32 prev_hp;       // last update's hp
    f32 hit_flash;     // run_hit_reaction sets 1, it fades out over 15 updates
    f32 hp_ratio;      // hp / referenceHp
    s32 turn_done;     // turn_toward_target_position finished
    s32 turn_sound_played;  // the full-speed turn sound plays once
    Vec move_origin;   // where the move to boss6_arena_center starts
    s32 switch_timer;  // attribute switch countdown (set_state_0x34, update_countdown)
    s32 switch_pending;
    s32 lower_contact_index;
    Vec lower_contact_delta;
    Vec previous_lower_contact;
    TBoss6Type2Joint aim_joints[2];  // one per body model
    s32 foot_grounded[2];  // update_footstep_effects: set when a foot comes down (footstep sound), cleared when it lifts
    u16 possessed_client;  // grab_player's player; 0xFFFF when none
    u8 unk_55E[0x2];
    // BML entries 0xB and 0xA (cache_fish_params); grab_player puts them on the grabbed player.
    NJS_TEXLIST *grab_texlists[2];
    NJS_OBJECT *grab_models[2];
    char *grab_appearance;  // the possessed player's name block, the appearance boss6type2_draw_models takes
    Boss6PlayerLook saved_look;
    Vec node_positions[19];       // body node positions, captured each draw
    Vec prev_node_positions[19];  // last update's node_positions
    ModelNodePositionCapture *node_capture[1];
    Boss6ScrollStrips scroll_strips;
    TParticleCtrl *particle_emitters[14];

    void update_lower_contact_delta();
    void set_screen_pos();
    s32 calc_field4f0_delta();
    s32 snap_to_ground();
    void request_player_camera_offsets(f32 a, f32 b);
    void init_parts();
    s32 turn_toward_target_position();
    static TBoss6DPB *create_dpb(TObject *parent, const Vec *position, f32 radius);
    s32 get_phase();
    static s32 is_player_in_rock_area(u16 client_id);
    void spawn_hit_effects();
    void destroy_part(s32 slot);
    void spawn_particle_slot(s32 slot);
    void update_part_positions();
    void update_footstep_effects();
    void set_fields_554();
    void restore_effect_values();
    void sum_offsets();
    void init_collected_entries();
    s32 grab_player(u16 client_id);
    s32 check_target();
    u16 is_falz_ready();
    void reset_counters();
    void cache_fish_params();
    void update_zako();
    s32 is_ready_to_attack();
    s32 is_phase_complete();
    void trigger_screen_pos();
    void spawn_rocks_around_players();
    void drop_random_rocks(s32 force);
    static void request_default_follow_camera();
    void init_range();
    void update_target();
    s32 push_players_away(const Vec *target, f32 range);
    void set_owner_flag_bit0();
    void set_child_flags();
    void clear_part_flags();
    void update_parts_flags();
    void advance_position();
    void copy_vec_array();
    void update_segments();
    void init_segment_range();
    s32 choose_turn_motion();
    s32 choose_random_motion();
    s32 is_target_valid();
    void update_attack_switch();
    void play_phase_sound();
    void play_sound_if_no_target();
    void update_countdown();
    void set_state_0x34();
    void start_countdown_sound_state();
    void reset_indices();
    s32 get_hit_count();
    void add_damage(s32 diff);
    void reset_attack_counter();
    void copy_anim_state();
    void load_battle_params();
    void draw_body_models();
    void update_motion_tracks();
    void init_motion_entries();
    void set_action_state(s32 action);
    void copy_pos_620(Vec *out);
    void get_push_points(Vec *first, Vec *second);
    void copy_pos_59c(Vec *out);
    void apply_damage(s32 diff);
    s32 get_rotation_timer();
    s32 count_matching_values(s32 action, s32 depth);
    void set_target_state(s32 mode, s32 new_variant);
    s32 choose_next_index();
    s32 pick_random_other_index();
    static s32 find_index_in_table(u32 v);
    static int get_table_entry(int a0);
    void update_attack_target();
    void update_action_state();
    void send_action_packet_if_idle(s32 action, Boss6GridBytes *grid);
    void parse_action_packet(OlgaFlowType2ActionMsg *packet);
    static TBoss6Type2 *create(Boss6BodySpawnParams *params);
    void draw();
    void select_action();
    void update_zako_timer();
    void update_rock_spawn_state();
    void tick_timer_0x460();
    void select_next_state();
    void init_speed_from_ratio();
    void start_flow_soul_effect();
    void spawn_death_soul();
    void check_state_0x460_eq4();
    void init_timer();
    void update_attack_sequence();
    void update_state_34();
    void init_timers_and_copy_pos();
    void update_timer();
    void update_when_timer_zero();
    void start_death_sequence();
    void update_zako_spawn_timer();
    void reset_timers_and_spawn_particle();
    void update_zako_phase();
    void init_attack_params();
    void check_state_0x460_eq0();
    void tick_action_timer();
    void pick_next_zako();
    void init_timer_and_play_sound();
    void reset_state_timers();
    void tick_timer_460();
    void select_attack_state();
    static TBoss6Mag *create_mag(TBoss6MagSpawnParams *params);
    void on_mag_dead();
    void get_shoulder_point(s32 index, Vec *pos, s32 *rotation);
    static void send_6xAD_grid_positions(s32 index, saddr points, s32 count);
    static void send_subordinate_actions(s32 kind, saddr ids, s32 n, s32 force, s32 unused);
    static TBoss6EffFlowSoul *create_flow_soul(TObject *parent, Vec *pos, s32 player, s32 duration);
    s32 get_state();
    s32 get_variant();
    void apply_rock_hits_to_players();
    void get_phase_values(u16 *a, u16 *b, u16 *out);
    void send_state_action_packet();
    void send_action_packet(s32 action);  // callers pass full words (choose_random_motion, next_motion)
    void build_state_packet(OlgaFlowType2ActionMsg *message);
    void update_charge_timer();
    void init_attack_timers();
    void send_state_action();
    void turn_toward_target();
    // Battle action handlers (enter / idle / update; table rows: enter / idle / update)
    void update_attack_timer();
    void update_death_sequence();
    void idle_b_walk();
    void act_b_walk();
    void act_b_bj_wait();
    void act_bsk_again();
    void update_chg_to_bsk();
    void update_iai();
    void idle_bkjump();
    void update_niramu();
    void act_niramu();
    void update_info_stat();
    void act_wait();
    static Blk_802BCFD4 *copy_block(Blk_802BCFD4 *d, const Blk_802BCFD4 *s);
    void pick_walk_target(Boss6GridBytes *grid);
    void change_motion(s32 motion);
    void spawn_sword_wave();
    void create_mags(f32);
    void release_mags();
    void call_mags_to_shoulders();
    u16 pick_target_client();
    void pick_action_clients(u16 *first, u16 *second);
    void clear_head_aim();
    void create_dpbs();
    s32 should_back_jump();
    s32 should_use_dpb();
    void update_leg_ground_effects();
    void reset_lower_contact();
    void move_to_arena_center(s32 timer, s32 duration);
    void clear_particle_emitters();
    static void world_to_grid_pos(Vec *pos, s8 *grid_x, s8 *grid_z);
    static void grid_to_world_pos(s8 grid_x, s8 grid_z, Vec *pos);
    static TBoss6EffFlowSoul *spawn_flow_soul(TObject *parent, Vec *pos, s32 duration);
};

LAYOUT_ASSERT(TBoss6Type2ActionHistoryOffset, offsetof(TBoss6Type2, action_history) == 0x378);
LAYOUT_ASSERT(TBoss6Type2_offset_action_state, (offsetof(TBoss6Type2, action_state) == 0x374));
LAYOUT_ASSERT(TBoss6Type2_offset_target_position, (offsetof(TBoss6Type2, move_target) == 0x480));
LAYOUT_ASSERT(TBoss6Type2_offset_lower_contact_index, (offsetof(TBoss6Type2, lower_contact_index) == 0x520));
LAYOUT_ASSERT(TBoss6Type2_offset_lower_contact_delta, (offsetof(TBoss6Type2, lower_contact_delta) == 0x524));
LAYOUT_ASSERT(TBoss6Type2_offset_previous_lower_contact, (offsetof(TBoss6Type2, previous_lower_contact) == 0x530));
LAYOUT_ASSERT(TBoss6Type2_offset_node_positions, (offsetof(TBoss6Type2, node_positions) == 0x59c));
LAYOUT_ASSERT(TBoss6Type2_offset_node_capture, (offsetof(TBoss6Type2, node_capture) == 0x764));
LAYOUT_ASSERT(TBoss6Type2_offset_scroll_strips, (offsetof(TBoss6Type2, scroll_strips) == 0x768));

LAYOUT_ASSERT(TBoss6Type2_size, sizeof(TBoss6Type2) == 0x7B4);

#endif
