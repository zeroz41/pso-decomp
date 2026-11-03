#ifndef PSO_ENEMY_TOBJENESLIMEONE_H
#define PSO_ENEMY_TOBJENESLIMEONE_H

#include "types.h"
#include "pso/enemy/TObjEnemy.h"
#include "dolphin/mtx.h"

struct TObjEneSlimeOne : public TObjEnemy {
    virtual ~TObjEneSlimeOne();
    void initialize_slime_instance_state();
    void sub_800E9090();
    virtual void vfunc_63();
    virtual void vfunc_62();
    virtual void vfunc_61();
    virtual f32 receive_direct_attack(void *, DirectAttackPayload, void *, s32, s32);
    virtual void render();
    virtual void run_task();
    u8 unk_374[0xC];
    u8 * m_380;
    u32 m_384;
    u32 m_388;
    void *collision_body_parts;  // init_collision_body_parts / free_collision_body_parts
    s32 m_390;
    u8 unk_394[0x4];
    f32 m_398;
    s32 m_39c;
    f32 m_3a0;
    u8 unk_3A4[0x4];
    void* m_3a8;
    u8 unk_3AC[0x4];
    f32 m_3b0;
    f32 m_3b4;
    f32 m_3b8;
    f32 m_3bc;
    f32 m_3c0;
    u8 unk_3C4[0x4];
    s32 m_3c8;
    s32 m_3cc;
    u8 unk_3D0[0xC];
    Vec m_3dc;
    void * m_3e8;
    u32 m_3ec;
    u32 m_3f0;
    s32 get_attack_target();
    s32 is_in_water_bomb_states();
    static int get_instance();
    int is_timer_active();
    int find_nearest_enemy_with_flag(s32 arg1, f32 farg0);
    int check_player_field_7cc();
    void draw_part(s32 arg1);
    void advance_animation_state();
    s32 is_reached_target_depth();
    void set_motion_state(s32 arg1);
    void copy_position();
    void set_random_timer_15();
    void clear_child_flag();
    void set_target_flag_bit0();
    static s32 create(s32 arg0, s32 arg1, s32 arg2);
    static s32 create(s32 arg0, s32 arg1);
    void set_state(s32 arg1);
    s32 try_spawn_child(void *arg1);
    void sub_800E92D8();
    void sub_800E9538();
    void update_effect_fade_lifetime();
    void sub_800E95F4();
    void sub_800E969C();
    void init_split_effect();
    void update_tick();
    void reset_display_state();
    void tick_timer();
    void start_tail_attack();
    void update_water_bomb_timer();
    void begin_appear();
    void sub_800E9BCC();
    void sub_800E9D7C();
    void sub_800E9DC8();
    void init_slime_state();
    void sub_800E9EFC();
    void sub_800EA120();
    void update_dive_timer();
    void enter_appear_state();
    void update_slime_timer();
    void enter_slime_state();
    void sub_800EA364();
    void sub_800EA56C();
    void sub_800EA678();
    void init_slime_display();
    void sub_800EA820();
    void reset_display();
    void update_wait_search();
    void init_state();
};

typedef char TObjEneSlimeOne_size[sizeof(TObjEneSlimeOne) == 0x3F4 ? 1 : -1];
#endif
