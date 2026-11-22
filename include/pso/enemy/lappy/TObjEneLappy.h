#ifndef PSO_ENEMY_LAPPY_TOBJENELAPPY_H
#define PSO_ENEMY_LAPPY_TOBJENELAPPY_H

#include "types.h"
#include "pso/enemy/TObjEnemy.h"

struct LappyVec { f32 x, y, z; };

struct TObjEneLappy : public TObjEnemy {
    TObjEneLappy(TObject *parent, void *set_data);
    virtual ~TObjEneLappy();
    virtual void run_task();
    virtual void render();
    virtual s32 update_action_hold_status();
    virtual s32 update_movement_status();
    virtual void refresh_target();
    virtual int test_flag_256();
    virtual void run_idle_action();
    virtual void run_move_action();
    virtual void run_attack_action();
    virtual void run_miss_reaction();
    virtual void run_hit_reaction();
    virtual void run_death_reaction();
    void sub_800C20C0();
    void sub_800C20B0();
    void set_speed_params(s32);
    void update_invuln_timer();
    void apply_move_friction();
    void set_boss4_state();
    void apply_variant_speeds();
    void clear_flags_60();
    s32 advance_flee_step();
    void set_flag_and_notify();
    s16 m_374;
    u8 _pad376[0x2];
    u8 m_378;
    u8 m_379;
    s16 m_37a;
    u8 _pad37C[0x2];
    s16 m_37e;
    s16 m_380;
    s16 m_382;
    s16 m_384;
    u8 unk_386[0x2];
    s32 m_388;
    f32 wander_distance;  // set to 30 when a wander starts, reduced by the walk speed each frame (inferred)
    s32 m_390;
    s16 flee_turn_timer;  // frames since the fleeing rappy last turned away from a player (inferred)
    s16 m_396;
    void play_walk_sound();
    void update_hurt();
    void update_attacking();
    void update_moving();
    static void update_idle_state(void *ov);
    static void *create(void *set);
    static void load_resources();
    static void free_resources();
    s32 pad_398;
    f32 m_39c;
    u8 unk_3A0[0x4];
};

LAYOUT_ASSERT(TObjEneLappy_size, sizeof(TObjEneLappy) == 0x3A4);

// The rare and the normal Rappy texture archives TObjEneLappy::load_resources picks from. The unit
// defines them after that function, which reaches each with its own lis/addi.
extern const char re3_b_lappy_base_niji_gvm[];
extern const char re3_b_lappy_base_ao_gvm[];
#endif
