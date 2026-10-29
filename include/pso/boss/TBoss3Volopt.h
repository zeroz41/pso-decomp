#ifndef PSO_BOSS_TBOSS3VOLOPT_H
#define PSO_BOSS_TBOSS3VOLOPT_H

#include "types.h"
#include <dolphin/mtx.h>
#include "pso/enemy/TObjEnemyCustom.h"

struct BmlResource;
class TBoss3VoloptCore;
struct TObjPlayer;
struct VoloptPhase2Message;

// The 6x15 Vol Opt boss action message: action selects what the part with the
// matching id does (see handle_6x15_vol_opt_boss_actions).
struct TBoss3VoloptActionPacket {
    u8 command;
    u8 size;
    u16 id;
    s16 action;
    u16 target_id;
    s16 param;
    s16 param2;

    void init();
    void swap();
    void send();
};

// The 6x16 message: the shuffled P01 order and how many of them to make primary.
struct TBoss3VoloptTargetsPacket {
    u8 command;
    u8 size;
    u16 id;
    s8 order[6];
    s16 count;

    void init();
    void swap();
    void send();
};

// The 6x84 message: the 6x16 targets plus the technique the primary P01s cast.
struct TBoss3VoloptAttackPacket {
    u8 command;
    u8 size;
    u16 id;
    s8 order[6];
    s16 count;
    s16 tech;
    s16 reserved;

    void init();
    void swap();
    void send();
};

// The 6x17 message: moves the entity id to pos facing rotation_y.
struct TBoss3VoloptPositionPacket {
    u8 command;
    u8 size;
    u16 id;
    Vec pos;
    s32 rotation_y;

    void init();
    void swap();
    void send();
};

struct TBoss3Volopt : public TObjEnemyCustom {
    TBoss3Volopt(void *set_data);
    virtual ~TBoss3Volopt();
    virtual void render();
    virtual void run_task();

    static void *create(void *set_data);
    static void free_parts();
    static void load_resources();

    static u16 find_strongest_player();
    static u16 find_random_player();
    static s32 collect_candidate_players();
    static void update_phase();
    static void stop_rumble();
    static void start_rumble();
    static BOOL is_death_active();
    static void send_position(TObjPlayer *player, Vec *pos, s32 rotation_y);
    static void push_actors_out(s32 phase2);
    static void set_camera_focus(Vec *pos);
    static Vec *get_camera_focus();
    static void set_primary_p01s(s32 count);
    s32 shuffle_p01_order();
    BOOL is_dead();
    BOOL are_p01s_broken();
    static BOOL is_p02_idle();
    static BOOL are_p01s_idle();
    void spawn_parts();
    void update_phase2();
    void update_phase2_intro();
    void update_phase1();
    void update_intro_cutscene();
    void start_phase2();
    void start_phase1();
    void select_phase2_attack();
    void select_phase1_attack();
    static void move_to_arena(s32 phase2);
    void dispatch_mode();
    static BOOL is_v2_mode();
    s32 get_part_group(s32 index);
    u16 get_part_id(s32 index);
    u16 find_attack_target();
    void reset_photon_effect();
    s32 get_field_3e0();

    // Defined in other units; most are helpers of other classes filed under
    // TBoss3Volopt.
    static void create_breakup_mdl(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
    void play_area_variant_sound();
    void play_area_se_with_particle();
    void play_area_sound_effect();
    static s32 remap_area_sound_id(s32 arg0);
    void create_cage(u16 target_id);

    u8 pad_38C[0x18];
    s32 core_slot;
    s32 in_phase2;
    u8 pad_3AC[0x10];
    u32 m_3bc;
    u8 pad_3C0[0x20];
    s32 m_3e0;
    u8 pad_3E4[0xC];
    s16 attack_step;
    s16 attack_delay;
    s16 pad_3f4;
    u8 pad_3F6[0x2];
    s16 breakup_tries;
    s16 pad_3fa;
    s16 max_targets;
    u8 pad_3FE[0x2];
    s32 pad_400;
    s32 attack_count;

    static TObjPlayer *candidate_players[5];
};

typedef char TBoss3Volopt_size[sizeof(TBoss3Volopt) == 0x408 ? 1 : -1];

void handle_6x85_vol_opt_phase2_boss_actions(VoloptPhase2Message *message);
void handle_6x84_vol_opt_boss_actions(TBoss3VoloptAttackPacket *packet);
void handle_6x17_set_entity_position_and_angle(TBoss3VoloptPositionPacket *packet);
void handle_6x16_vol_opt_boss_actions(TBoss3VoloptTargetsPacket *packet);
void handle_6x15_vol_opt_boss_actions(TBoss3VoloptActionPacket *packet);
void clear_volopt_cage_flag();

extern "C" TBoss3VoloptCore *fn_8003F468(TBoss3Volopt *parent, u16 id, s32 group);

extern u16 volopt_cage_id;
extern s32 volopt_cage_group;
extern u16 volopt_p02_id;
extern u16 volopt_hiraisin_id;
extern u16 volopt_core_id;
extern BmlResource *boss3_volopt_resources;
extern s32 vol_opt_active_hit_zone;
extern u16 boss3_volopt_monitor_base_actor_id;
extern s32 volopt_death_active;
extern s32 volopt_breakup_flag;
extern s32 volopt_resources_loaded;
extern s32 boss3_volopt_cage_flag;
extern s32 volopt_p01_tech;
extern Vec boss3_volopt_spawn_pos;

#endif
