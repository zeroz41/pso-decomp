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
    u32 status;           // 1 moved, 2 enemies in range, 4 needs help, 0x20 obstacle ahead
    u32 condition;        // hp, tp and damage flags
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
        f32 unknown_0C;
        f32 max_distance_from_player;
        f32 enemy_unlock_range;
        f32 block_range;
        f32 attack_range;
        u8 attack_technique_level;
        u8 support_technique_level;
        u8 attack_probability;
        u8 attack_technique_probability;
        f32 unknown_24;
        void copy(AiParams *src);
        void copy_entry_by_index(s32 arg1);
    };

    TNpcPlayer(u16 a, u16 b, int kind, TObject *parent);
    TNpcPlayer(u16 a, u16 b, int kind, s32 arg4, TObject *parent);
    virtual ~TNpcPlayer();
    void deliver_partner_action();
    virtual void run_task();
    virtual void render();
    void partner_request_physical_attack();
    void send_partner_attack_stage_request();
    s32 in_combat;
    s32 m_20;
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
    u32 ai_flags;
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
    s32 m_c4;
    s32 m_c8;
    s32 m_cc;
    Vec steer_point;
    Vec goal;
    void dispatch_action(s32 arg1);
    void change_ai_state(u32 arg1);
    void handle_action(s32 arg1);
    void request_chatter(u32 arg1);
    static const char *name;
    static bool is_small_obstacle(f32 size);
    static bool is_hp_low(f32 hp, f32 max_hp);
    s32 check_movement_progress();
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
    static TPlyCharData *build_npc_player_record(s32 arg0);
    static void ensure_rock_singleton();
    void update();
    void update_players();
    void update_lobby();
    void finalize_and_send_packet();
    void byteswap_positions();
    void reset_model();
    void init_model();
    void reset_move_state();
    void sync_from_lobby();
    void swap_endian();
    void set_field2(s16 v);
    void set_field_0(s16 v);
    void set_state(s32 v);
    void byteswap_pos();
    void send_6x3E();
    void bswap_6x3E();
    void init_6x3E_packet();
    void init_equipment();
    static s32 send_command(s32 cls, s32 count, const TPlyInventoryItem *source, s32 level, TPlyCharData *character);
    void byteswap_header();
    void send_state_60();
    void update_combat_action();
    u8 *destroy_and_materialize_player(s16 arg1);
    void request_technique_cast(s32 kind);
    s32 select_recovery_action(s32 arg1);
    s32 route_around_object(Vec *out);
    void calc_box_escape_axis(Vec *a, Vec *b, Vec *c, Vec *d, Vec *pos, Vec *axis, f32 *reach);
};

LAYOUT_ASSERT(TNpcPlayer_size, sizeof(TNpcPlayer) == 0xE8);

// Builds the character record of NPC template index, scaled to the selected difficulty.
TPlyCharData *load_npc_player_template(s32 index);
// The NPC AI parameter rows, indexed by TNpcPlayer::AiParams::copy_entry_by_index.
extern TNpcPlayer::AiParams npc_player_ai_templates[64];
extern s32 quest_npc_visual_pending;
// Clears a 6x40 walk-to-position packet and sets its header (subcommand 0x40, size 4).
void init_6x40_walk_packet(void *cmd);
#endif
