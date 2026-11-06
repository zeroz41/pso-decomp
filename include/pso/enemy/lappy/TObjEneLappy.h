#ifndef PSO_ENEMY_LAPPY_TOBJENELAPPY_H
#define PSO_ENEMY_LAPPY_TOBJENELAPPY_H

#include "types.h"
#include "pso/enemy/TObjEnemy.h"

struct LappyVec { f32 x, y, z; };

struct TObjEneLappy : public TObjEnemy {
    virtual ~TObjEneLappy();
    virtual void run_task();
    virtual void render();
    virtual s32 update_action_hold_status();
    virtual s32 update_movement_status();
    virtual void vfunc_28();
    virtual int test_flag_256();
    virtual void vfunc_58();
    virtual void vfunc_59();
    virtual void vfunc_60();
    virtual void vfunc_61();
    virtual void vfunc_62();
    virtual void vfunc_63();
    void sub_800C20C0();
    void sub_800C20B0();
    void set_speed_params(s32);
    void update_invuln_timer();
    s32 apply_move_friction();
    void set_boss4_state();
    void apply_variant_speeds();
    void clear_flags_60();
    s32 advance_flee_step();
    s16 m_374;
    u8 _pad376[0x2];
    u8 m_378;
    u8 m_379;
    u16 m_37a;
    u8 _pad37C[0x2];
    u16 m_37e;
    u16 m_380;
    u16 m_382;
    u16 m_384;
    u8 unk_386[0x2];
    s32 m_388;
    u8 unk_38C[0x4];
    s32 m_390;
    u8 unk_394[0x2];
    u16 m_396;
    void play_walk_sound();
    void update_hurt();
    void update_attacking();
    void update_moving();
    static void update_idle_state(void *ov);
    static void *create(void *arg0);
    static void load_resources();
    u8 unk_398[0x4];
    f32 m_39c;
    u8 unk_3A0[0x4];
};

typedef char TObjEneLappy_size[sizeof(TObjEneLappy) == 0x3A4 ? 1 : -1];
#endif
