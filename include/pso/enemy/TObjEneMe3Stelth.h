#ifndef PSO_ENEMY_TOBJENEME3STELTH_H
#define PSO_ENEMY_TOBJENEME3STELTH_H

#include "types.h"
#include "pso/enemy/TObjEneDD_ST.h"

struct TObjEneMe3Stelth : public TObjEneDD_ST {
    virtual ~TObjEneMe3Stelth();
    void handle_direct_attack(void *, void *, int, void *);
    virtual void vfunc_88();
    virtual void vfunc_95();
    virtual void vfunc_96();
    virtual void vfunc_89();
    virtual void attack_and_unequip();
    virtual u8 check_target_in_range();
    virtual void vfunc_107();
    virtual void vfunc_108();
    virtual s32 check_active_flag();
    virtual s32 check_flag();
    virtual void vfunc_111();
    virtual void vfunc_112();
    virtual void vfunc_113(s32);
    virtual void setup_move();
    virtual void draw_with_debug_info();
    void copy_pos_with_height_offset();
    void setup_move_bounds();
    f32 get_node_world_y();
    u8 test_body_collision(s32, f32);
    s32 sub_800F4850();
    s32 is_angle_in_range();
    u8 sub_800F47D4();
    void sub_800F4758();
    void sub_800F42B8(s32);
    void vfunc_63();
    void vfunc_62();
    void vfunc_61();
    void vfunc_28();
    void render();
    void run_task();
    u8 unk_374[0x2C];
    f32 m_3a0;
    u32 m_3c0;
    u8 _pad3C4[0x8];
    u32 m_3cc;
    u32 m_3d0;
    u8 unk_3D4[0x30];
    void* m_404;
    static void destroy_resources();
    s32 try_spawn_ground_effect(s32 arg1);
    void play_hit_effect();
    static void spawn_attack(s16 arg0, s32 arg1, s32 arg2, s32 arg3, f32 farg0, f32 farg1);
    static void add_instance();
    void update_distance_state();
    static void set_slot_min_clamped_value(s32 arg0, f32 farg0);
    static void free_shared_resources();
    int create_real();
    static void load_shared_resources();
    void handle_breakup_state(s32 arg1);
    void update_state_resta_cast(s32 arg1);
    void state_chase_target(s32 arg1);
    void update_state_drop(s32 arg1);
    void update_state_fade_in(s32 arg1);
    void state_chase(s32 arg1);
};

#endif
