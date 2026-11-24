#ifndef PSO_NPC_TNPCPLAYER_H
#define PSO_NPC_TNPCPLAYER_H

#include "types.h"
#include "pso/player/TechniqueFlags.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjMotion.h"

class TObjPlayer;

// One entry of NpcPlayerView's sorted list of nearby targets.
struct NpcPlayerViewTarget {
    void copy(NpcPlayerViewTarget *src);

    u32 entity_id;
    s32 collider;     // collision body index
    f32 distance_sq;  // squared horizontal distance
};

// NpcPlayerView::condition bits, rebuilt every frame by update_conditions,
// update_hp_change and can_recover.
enum NpcPlayerCondition {
    NPC_CONDITION_STATUS_AILMENT     = 0x2,     // actorFlags 1, 2 or 0x10 set
    NPC_CONDITION_HP_LOW             = 0x8,     // HP <= 25% with enemies in range, <= 75% without
    NPC_CONDITION_TP_LOW             = 0x10,    // TP <= 20%
    NPC_CONDITION_HAS_RECOVERY_ITEM  = 0x20,    // can_recover found the item in the inventory
    NPC_CONDITION_BIG_DAMAGE         = 0x40,    // lost more than 30% of max HP since the last check
    NPC_CONDITION_MEDIUM_DAMAGE      = 0x80,    // more than 20%
    NPC_CONDITION_SMALL_DAMAGE       = 0x100,   // more than 1%
    NPC_CONDITION_HEALED             = 0x200,   // HP went up
    NPC_CONDITION_HP_CRITICAL        = 0x800,   // HP <= 10%
    NPC_CONDITION_HP_HURT_IN_COMBAT  = 0x1000,  // HP <= 75% with enemies in range
};

// NpcPlayerView::status bits (0x80, a probe contact with an actor flagged
// 0x20000000, has no name yet).
enum NpcPlayerStatus {
    NPC_STATUS_MOVED             = 0x1,   // moved more than 0.4 since the last check
    NPC_STATUS_ENEMIES_IN_RANGE  = 0x2,
    NPC_STATUS_NEEDS_RECOVERY    = 0x4,   // set with any HP, TP or ailment condition
    NPC_STATUS_OBSTACLE_AHEAD    = 0x20,  // probe_obstacles hit an object to walk around
};

// TNpcPlayer::ai_flags bits.
enum NpcAiFlag {
    NPC_AI_DETOUR_WAYPOINT       = 0x1,      // a waypoint around a wall is chosen
    NPC_AI_DETOUR_OVERSHOOT      = 0x2,      // steering 40 units past that waypoint
    NPC_AI_CHATTER_PENDING       = 0x4,      // request_chatter queued a new line
    NPC_AI_RUNNING               = 0x8,      // runs until it leaves ai state 1
    NPC_AI_ATTACK_STATE          = 0x10,     // set on entering ai state 2
    NPC_AI_MOVE_STATE            = 0x20,     // set on entering ai state 1 or 16
    NPC_AI_NO_CLEAR_TARGET       = 0x40,     // no target in range has a clear line
    NPC_AI_ATTACK_BLOCKER        = 0x80,     // an enemy within block_range blocks the way
    NPC_AI_RETURNING_TO_LEADER   = 0x100,
    NPC_AI_SELF_NEEDS_RECOVERY   = 0x200,
    NPC_AI_TARGET_IN_REACH       = 0x1000,   // target within attack_range + 10
    NPC_AI_SURROUNDED            = 0x2000,   // three or more targets in range
    NPC_AI_STUCK                 = 0x4000,   // stuck_frames passed 30
    NPC_AI_DOUBLE_AGGRESSION     = 0x8000,   // doubles the attack probability
    NPC_AI_CAST_RESTA            = 0x10000,  // skips the healed chatter once
};

// What a partner NPC tracks about one player: its own (self_view) or the one it follows
// (leader_view): the enemies in range, its condition flags and an obstacle probe.
struct NpcPlayerView {
    NpcPlayerView(s32 id);
    ~NpcPlayerView();
    s32 is_player_lost();
    s32 update_hp_change();
    s32 update_conditions();
    s32 can_recover(s32 kind, s32 allow_item);
    s32 scan_targets(f32 range);
    s32 check_moved();
    s32 is_target_line_clear(u32 id);
    s32 scan_nearby_enemies(Vec *pos, f32 range);
    void sort_targets(NpcPlayerViewTarget *entries, s32 lo, s32 hi);
    s32 partition_targets(NpcPlayerViewTarget *a, int lo, int hi);
    s32 probe_obstacles();
    s32 get_target_collider();
    u32 get_target_id();
    u16 get_client_id();
    u32 get_prev_target_id();
    u32 get_condition();
    void copy_target(NpcPlayerViewTarget *src, NpcPlayerViewTarget *dst);
    u32 get_status();
    void clear_flags();
    NpcPlayerView *target_list();
    void set_target(u32 id, s32 collider);

    s32 target_count;
    NpcPlayerViewTarget targets[10];  // nearest first (sort_targets)
    u32 target_id;        // entity the player attacks
    u32 prev_target_id;
    s32 target_collider;  // collision body index of target_id
    s16 last_hp;
    u16 client_id;        // client id of the player it watches
    u32 status;           // NpcPlayerStatus bits
    u32 condition;        // NpcPlayerCondition bits
    TObjPlayer *player;
    s32 goal_angle;       // heading from the player to its goal
    Vec last_position;    // where the player last moved from
    TObjCollidable *probe;      // collider swept ahead of the player
    CollisionBody probe_body;
    CollisionBody obstacle_body;  // body of the obstacle probe hit
    s32 obstacle_angle;
};
LAYOUT_ASSERT(NpcPlayerView_size, sizeof(NpcPlayerView) == 0x108);

// Eleven per-action counters the partner AI steps and tests.
struct PartnerCounters {
    PartnerCounters();
    void clear();
    s32 clamp(s32 index, s32 limit);
    void set(s32 index, s16 value);
    s32 is_reached(s32 index, s32 value);
    s32 reset_if_reached(s32 index, s32 limit);
    s16 get(s32 index);
    void increment(s32 index);
    void reset(s32 index);

    s16 count[11];
};

struct Vec;

class TPlyInventoryItem;
class TPlyCharData;
struct disp_data_part2;

extern disp_data_part2 *npc_player_char_data_buffer;
extern int partner_chatter_flags;

struct TNpcPlayer : public TObject {
    struct AiParams {
        u16 npc_id;
        u16 base_level;
        TechniqueFlags technique_flags;
        f32 enemy_lock_on_range;
        f32 min_distance_from_player;  // inferred: read nowhere; 10.0 in every template, below max_distance_from_player
        f32 max_distance_from_player;
        f32 enemy_unlock_range;
        f32 block_range;
        f32 attack_range;
        u8 attack_technique_level;
        u8 support_technique_level;
        u8 attack_probability;
        u8 attack_technique_probability;
        f32 escort_keep_distance;  // inferred: calc_follow_goal holds an escort partner this far short of its goal
        void copy(AiParams *src);
        void copy_entry_by_index(s32 index);
    };

    TNpcPlayer(u16 leader_id, u16 self_id, int template_id, TObject *parent);
    TNpcPlayer(u16 leader_id, u16 self_id, int template_id, s32 escort, TObject *parent);
    virtual ~TNpcPlayer();
    void deliver_partner_action();
    virtual void run_task();
    virtual void render();
    void partner_request_physical_attack();
    void send_partner_attack_stage_request();
    void partner_request_technique_cast(s32 kind);
    s32 in_combat;
    s32 zeroed_word;  // written 0 by both constructors, read nowhere
    s32 chatter_id;
    s32 init_step;
    s16 template_index;  // row of npc_player_ai_templates
    u8 _pad2E[0x2];
    AiParams ai_params;
    f32 leader_distance_sq;
    PartnerCounters partner_counters;
    u8 _pad72[0x2];
    NpcPlayerView *leader_view;  // the player the partner follows
    NpcPlayerView *self_view;    // the partner's own player
    u32 ai_state;
    u32 ai_flags;  // NpcAiFlag bits
    s32 escort_leader;
    f32 escort_distance_sq;
    s8 stuck_frames;
    s8 still_frames;
    s16 attack_delay;
    s16 detour_frames;
    s16 recovery_action;
    Vec waypoint_dir;
    Vec waypoint;
    Vec move_target;
    u8 _padB8[0xC];
    s32 zeroed_words[3];  // written 0 by both constructors, read nowhere
    Vec steer_point;
    Vec goal;
    void dispatch_action(s32 action);
    void change_ai_state(u32 state);
    void handle_action(s32 action);
    void request_chatter(u32 id);
    static const char *name;
    static bool is_small_obstacle(f32 size);
    static bool is_hp_low(f32 hp, f32 max_hp);
    s32 check_movement_progress();
    s32 needs_movement();
    void select_path_waypoint();
    s32 partner_find_wall_segment(Vec *from, Vec *to, Vec *point, Vec *normal);
    s32 partner_route_around_wall(Vec *from, Vec *to, Vec *d, Vec *out, Vec *out2);
    void partner_compute_stalled_detour(Vec *from, Vec *to, Vec *d, Vec *out);
    s32 partner_clip_path_point(Vec *from, Vec *to, Vec *out);
    void deliver_partner_chatter();
    void partner_observe_surroundings();
    void init_follow_target();
    void update_condition_flags();
    void init_state();
    void send_run_request();
    void send_walk_request();
    s32 calc_follow_goal();
    s32 choose_attack_target();
    s32 check_return_to_leader();
    s32 update_follow_target();
    void decide_action();
    static TPlyCharData *build_npc_player_record(s32 index);
    static void ensure_rock_singleton();
    void init_equipment();
    static s32 send_command(s32 cls, s32 count, const TPlyInventoryItem *source, s32 level, TPlyCharData *character);
    void update_combat_action();
    void request_technique_cast(s32 kind);
    s32 select_recovery_action(s32 check_leader);
    s32 route_around_object(Vec *out);
    void calc_box_escape_axis(Vec *a, Vec *b, Vec *c, Vec *d, Vec *pos, Vec *axis, f32 *reach);
};

LAYOUT_ASSERT(TNpcPlayer_size, sizeof(TNpcPlayer) == 0xE8);

// Builds the character record of NPC template index, scaled to the selected difficulty.
TPlyCharData *load_npc_player_template(s32 index);
// The NPC AI parameter rows, indexed by TNpcPlayer::AiParams::copy_entry_by_index.
extern TNpcPlayer::AiParams npc_player_ai_templates[64];
extern s32 quest_npc_visual_pending;
// Sets quest_npc_visual_pending for the quest opcode that shows the quest NPCs.
void enable_quest_npc_visual();
#endif
