#ifndef PSO_ENEMY_TOBJENEPANBARA_H
#define PSO_ENEMY_TOBJENEPANBARA_H
#include "types.h"
#include "pso/enemy/TObjEnemy.h"

// One Pan Arms half (0x470 bytes, TObjEnePanarms::create_bara); 0x37C points at the
// body and 0x380 is the half's index (create_bara's second argument).
extern "C" {
// Links a half to the body (0x39C) and to the other half (0x3A0).
void TObjEnePanarms__sub_800E1C8C(void *arg0, s32 arg1, s32 arg2);
}

class TObjEnePanBARA : public TObjEnemy {
public:
    virtual ~TObjEnePanBARA();
    void calc_part_position(u8 *, s32 *);
    virtual void vfunc_63();
    virtual void vfunc_62();
    virtual void vfunc_61();
    void set_random_action_timer(int minimum, int range);
    void update_action_timer();
    void init_attack_state();
    void init_open_state();
    void update_move_timer();
    void start_phase3_timer12();
    void start_phase2_timer150();
    void update_attack();
    void init_attack_state2();
    void init_action();
    void update_chase_target();
    void init_state_2();
    void apply_effect_if_flagged();
    void update_hit_state();
    void restore_from_linked_object();
    void init_state_16();
    void update_move_to_target();
    void init_state_1();
    void start_action();
    void handle_split_flag();
    void init_split();
    void snap_to_parent_position();
    void reset_state();
    void spawn_periodic_particle();
    void update_offset_from_parent();
    void reset_split();
    void init_state();
    void update_linked_effect();
    void draw();
    int find_nearest_enemy_with_flag_alt_target(s32 arg1, f32 farg0);
    void attack_target_player(s32 arg1);
    void draw_with_fade();
    s32 state;
    s32 m_378;
    u8 unk_37C[0x4];
    s32 m_380;
    u8 unk_384[0x4];
    s32 m_388;
    s32 m_38c;
    u32 m_390;
    u8 unk_394[0x4];
    s32 m_398;
    u8 *m_39c;
    void* m_3a0;
    u8 unk_3A4[0x4];
    f32 m_3a8;
    u8 unk_3AC[0x4];
    f32 m_3b0;
    s32 action_timer;
    u8 unk_3B8[0x4];
    s32 m_3bc;
    u8 unk_3C0[0x4];
    s32 m_3c4;
    u8 unk_3C8[0x4];
    s32 m_3cc;
    u8 unk_3D0[0x4];
    s32 m_3d4;
    u8 unk_3D8[0x4];
    void* m_3dc;
    u8 unk_3E0[0x4];
    u8 unk_3E4[0x78];
    s32 m_45c;
    u8 unk_460[0x4];
    f32 m_464;
    u8 unk_468[0x4];
    f32 m_46c;
};

#endif
