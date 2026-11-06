#ifndef PSO_BOSS_VOLOPT_TBOSS3VOLOPTP02_H
#define PSO_BOSS_VOLOPT_TBOSS3VOLOPTP02_H

#include "types.h"
#include "dolphin/mtx.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/render/RenderFadeState.h"
#include "pso/system/BmlResource.h"

// The 6x85 message: Vol Opt ver.2 phase-2 commands (mode 0 carries the P02 wave delays).
struct VoloptPhase2Message {
    u8 command;
    u8 size;
    u8 pad_2[0x2];
    s16 mode;
    s16 delays[7];

    void init();
    void swap();
    void send();
};

// The 6x18 message: the P02 part HP, which breaks the parts that reached zero.
struct VoloptPartsMessage {
    u8 command;
    u8 size;
    u16 entity_id;
    s16 part_hp[4];

    void init();
    void swap();
    void send();
};

struct VoloptP02Params {
    f32 float_params[6];
    s32 int_params[6];
};

class TBoss3VoloptP02 : public TObjEnemyCustom {
public:
    TBoss3VoloptP02(TObject *parent, void *set_data);
    virtual ~TBoss3VoloptP02();
    virtual void run_task();
    virtual void render();
    virtual f32 receive_physical_attack(void *, f32);
    virtual f32 receive_direct_attack(void *source, DirectAttackPayload payload, void *collider, s32 technique, s32 flags);
    virtual void vfunc_79(s32 *);

    void clear_flag_08000000();
    void set_flag_08000000();
    void distribute_part_damage();
    void destroy_sub_objects();
    void spawn_sub_objects();
    void fn_80044680();
    void apply_hit_reaction(f32 delay);
    static void copy_phase2_positions_to_global(const VoloptPhase2Message *message);
    static void send_random_params();
    s32 count_dead_parts();
    void collect_targets_in_arc();
    void rebuild_parts();
    void destroy_children();
    void push_players_out_of_radius();
    void broadcast_values();
    u16 find_facing_player();
    s16 collect_targets_in_front();
    void trigger_breakup();
    void apply_broken_part_visibility();
    void fn_800456E4();
    void fn_800457A0();
    void spawn_breakup_models();
    void reset_visual_state();
    void spawn_ambient_particles();
    void update_death_sequence();
    void update_fade_state();
    void update_pillar_heal_state();
    void fn_80046260();
    void check_and_notify();
    void fn_800465B0();
    void fn_80046CB8();
    void fn_800472D4();
    void update_state();
    void dispatch_state();
    void set_action_wait(u16 target_id);
    void set_motion(u16 target_id);
    void check_and_trigger();
    void set_action(u16 target_id);
    BOOL is_mode_0();
    BOOL can_set_motion();
    BOOL can_trigger();
    BOOL can_action();
    BOOL can_action_wait();
    void run_state();
    static void free_resources();
    static void load_resources();
    static void *create(void *set_data);
    void init_params();
    void load_params_from_table(s32 index);
    static f32 get_float_param(s32 index);
    static s32 get_int_param(s32 index);

    u16 front_target_ids[4];
    s16 front_target_count;
    s16 volley_count;
    s16 cycle_count;
    s16 wave_index;
    s16 arc_target_count;
    u16 arc_target_ids[4];
    u8 pad_3A6[0x2];
    Vec arc_target_positions[4];
    Vec line_origin;
    TObject *arc_lines[4];
    Vec chain_positions[10];
    s32 hit_timer;
    s32 saved_state;
    TObject *heal_emitter;
    TObject *emitter;
    s32 pulse_angle;
    s32 pulse_speed;
    f32 pulse_color[3];
    RenderFadeState fade;
    s16 part_hp[4];
    s16 part_hp_max[4];
    u8 pad_4BC[0x4];
    s32 ring_angle;
    s32 ring_timer;
    Vec ring_positions[4];
    TObject *ring_lines[4];
    f32 ring_radius;
    s32 ring_phase;
};

extern BmlResource *lbl_805D4CE4;
extern VoloptP02Params *volopt_p02_params;

typedef char TBoss3VoloptP02_size[sizeof(TBoss3VoloptP02) == 0x510 ? 1 : -1];

#endif
