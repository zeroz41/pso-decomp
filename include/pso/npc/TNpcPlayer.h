#ifndef PSO_NPC_TNPCPLAYER_H
#define PSO_NPC_TNPCPLAYER_H

#include "types.h"
#include "pso/player/TechniqueFlags.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjMotion.h"

class TObjPlayer;

// One entry of Unk_8014F844's sorted list of nearby targets.
struct Unk_8014F844Entry {
    u32 m_0;  // entity id
    s32 m_4;  // collision body index
    f32 m_8;  // squared distance
};

// The 0x108-byte record TNpcPlayer allocates twice (m_74, m_78).
struct Unk_8014F844 {
    s32 m_0;
    Unk_8014F844Entry m_4[10];
    s32 m_7c;
    s32 m_80;
    s32 m_84;
    s16 m_88;
    u16 m_8a;  // client id of the player it follows
    u32 m_8c;
    u32 m_90;
    TObjPlayer *m_94;
    s32 m_98;
    Vec m_9c;
    TObjCollidable *m_a8;
    CollisionBody m_ac;
    CollisionBody m_d8;
    s32 m_104;
};
LAYOUT_ASSERT(Unk_8014F844_size, sizeof(Unk_8014F844) == 0x108);

struct Vec;

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

    virtual ~TNpcPlayer();
    void deliver_partner_action();
    virtual void run_task();
    virtual void render();
    void partner_request_physical_attack();
    void send_partner_attack_stage_request();
    s32 m_1c;
    s32 m_20;
    s32 m_24;
    s32 m_28;
    s16 m_2c;  // row of TNpcPlayer__template_table
    u8 _pad2E[0x2];
    AiParams ai_params;
    f32 m_58;
    s16 m_5c[11];
    u8 _pad72[0x2];
    Unk_8014F844 *m_74;
    Unk_8014F844 *m_78;
    u32 m_7c;
    u32 m_80;
    s32 m_84;
    f32 m_88;
    s8 m_8c;
    s8 m_8d;
    s16 m_8e;
    s16 m_90;
    s16 m_92;
    Vec m_94;
    Vec m_a0;
    Vec m_ac;
    u8 _padB8[0xC];
    s32 m_c4;
    s32 m_c8;
    s32 m_cc;
    Vec m_d0;
    Vec m_dc;
    void dispatch_action(s32 arg1);
    void change_ai_state(u32 arg1);
    void handle_action(s32 arg1);
    void request_chatter(u32 arg1);
    static void quick_sort(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    static bool is_small_obstacle(f32 size);
    static bool is_hp_low(f32 hp, f32 max_hp);
    void *dt(s16 arg1);
    s32 try_attack(s32 arg1, s32 arg2);
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
    static u8 *build_npc_player_record(s32 arg0);
    static void ensure_rock_singleton();
    s32 get_npc_state();
    s32 get_condition();
    s32 get_action_state();
    void reset_fields_8c();
    void*init();
    void update();
    void update_players();
    void update_lobby();
    void finalize_and_send_packet();
    void byteswap_positions();
    void *init_cast_technique_cmd();
    void reset_model();
    void init_model();
    void reset_move_state();
    void sync_from_lobby();
    void swap_endian();
    void set_field2(s16 v);
    void set_field_0(s16 v);
    void set_state(s32 v);
    void byteswap_pos();
    void *get_valid_target_player();
    void send_6x3E();
    void bswap_6x3E();
    void init_6x3E_packet();
    void init_equipment();
    static s32 send_command(s32 arg0, s8 arg1, s32 arg2, s32 arg3, s8 *arg4);
    static u8 *get_lobby_entry_ptr();
    static void send_warp_toward_player(u16 id, const Vec *destination);
    static void send_code_45_to_player(int arg0);
    static void play_effect(int arg0);
    static void send_stop_at_position(u16 id, void *pos, s32 arg);
    static void enable_partner_chatter();
    static void disable_partner_chatter();
    static void enable_all_battle_ctrl();
    static void send_6x3e_to_all_players(void *pos, s32 arg);
    static void apply_to_players(s32 value, void *arg1, s32 heading);
    static void send_inter_level_warp_all(s32 value);
    static void send_npc_control_6x69(s32 arg0);
    static void send_npc_stop_6x69(s32 arg0);
    static void send_npc_control_create(u16 arg0, u16 arg1, s32 arg2, u8 *arg3, s32 arg4);
    static void create_companion(u16 leader, u16 slot, s32 appearance, f32 *p, s32 heading);
    static void create_default_companion(u16 leader, s32 appearance, u8 *pos, s32 heading);
    static void send_npc_control_notify_players(s32 arg0, s32 arg1, s32 arg2);
    static void send_npc_create(s32 arg0, s32 arg1);
    static void reset_player_lobby_model(u16 arg0);
    static void update_player_field(u16 arg0, s32 frames);
    static void end_camera_pan_for_client(u16 arg0);
    static void apply_to_battle_player_slot(u16 arg0, s16 arg1);
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
#endif
