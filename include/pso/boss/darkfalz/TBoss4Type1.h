#ifndef PSO_BOSS_DARKFALZ_TBOSS4TYPE1_H
#define PSO_BOSS_DARKFALZ_TBOSS4TYPE1_H

#include "types.h"

struct BmlResource;
#include "pso/enemy/TObjEnemy.h"
#include "pso/unk/ModelNodeTables.h"

class ModelNodePositionCapture;

struct TBoss4DarkFalz;

struct TBoss4Type1 : public TObjEnemy
{
    TBoss4Type1(TObject *parent, saddr *params);
    virtual ~TBoss4Type1();
    virtual void run_task();
    virtual void render();
    virtual void apply_poison_status();
    virtual void apply_paralysis();
    virtual void apply_slow_status();
    virtual void apply_confusion_status();
    virtual void apply_movement_ailment(s32);
    virtual void apply_shock_status();
    virtual void clear_harmful_statuses();
    virtual void run_hit_reaction();
    virtual void run_death_reaction();
    // First-form phase dispatch and state helpers.
    void check_state_transition();
    void calc_target_position();
    void set_map_position(void *);
    void pick_target_position(Vec *target);
    void choose_next_attack();
    void apply_packed_state(u32 arg1);
    void send_darkfalz_code(s32 arg1, s32 arg2, s32 arg3);
    void send_state_to_target(s32 arg1);
    void calc_scaled_field(s32 arg1, s32 arg2);
    f32 calc_wave_offset(f32);
    void set_motion_index(s32 arg1);
    void calc_scale_slot_indices(s32 *a, s32 *b);
    void set_state(s32 arg1);
    void sub_800525AC();
    void sub_800528B8();
    void init_timer();
    void update_tech_charge();
    void update_scale_state();
    void init_child_and_set_timer();
    void update_attack_countdown();
    void update_state();
    void set_motion_for_state();
    void tick_countdown_set_state7();
    void update_spawn_uro();
    void start_motion_for_index();
    void tick_state_398_timer();
    void update_dead_idle();
    void init_dead_state();
    void sub_80052EF8();
    void update_state_transition();
    void init_movestndpos_state();
    void update_flag800_state();
    void sub_800530C0();
    void check_state_if_idle();
    void init_appear_state();
    void sub_80053440();
    void sub_80053670();
    void snapshot_position();
    void render_effects();
    void update_boss4_phase_timer();
    void draw_parts();
    void push_players_out_of_colliders();
    void sub_80053D4C();
    void update_follow_camera_offsets();
    static s32 create(saddr arg0);
    s32 get_state();
    s32 state;                    // index into the lbl_80485C48 state table
    ModelNodeTables model_nodes;
    TBoss4DarkFalz *owner;        // params[0], the Dark Falz that spawns it; run_task waits on it
    BmlResource *archive;
    s32 unk_394;                  // init_collision_body_parts(lbl_80485E2C, 3)
    u8 pad_398[0x8];
    s32 unk_3a0;
    s32 unk_3a4;
    s32 unk_3a8;
    s32 unk_3ac;
    u8 pad_3b0[0x14];
    s32 unk_3c4;                  // shared boss param 0x39 +0x18, clamped to 1..6
    s32 unk_3c8;
    s32 move_frames;              // boss param move_seconds (1..60, else 25) times 30
    s32 unk_3d0;
    s32 unk_3d4;
    s32 unk_3d8;                  // half the starting hp
    f32 unk_3dc;
    f32 hp_ratio;                 // run_task: hp / referenceHp
    u8 pad_3e4[0x8];
    f32 unk_3ec;
    u8 pad_3f0[0x8];
    void *parts[13];              // particle effects, released by the dt
    ModelNodePositionCapture *fx[3];
    Vec unk_438[3][2];
    ModelNodePositionCapture *unk_480;
    Vec unk_484[2];
};

LAYOUT_ASSERT(TBoss4Type1_size, sizeof(TBoss4Type1) == 0x49C);

extern "C" {
void TBoss4Type2__sub_80055300(void);
}

#endif
