#ifndef PSO_ENEMY_STELTH_TOBJENEME3STELTH_H
#define PSO_ENEMY_STELTH_TOBJENEME3STELTH_H

#include "types.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/render/TUnk_80494938.h"

// One variant's row of the parameter table TLobby hands load_shared_resources.
struct StelthBehaviorParams {
    f32 m_00;
    u8 unk_04[0x4];
    f32 m_08;
    f32 m_0c;
    f32 m_10;
    f32 m_14;
    s32 support_tech_level;  // Resta, Shifta and Deband
    s32 m_1c;
    s32 m_20;
    s32 attack_tech_level;   // Rafoie and Gifoie
};

// The record movementParameters points at.
struct StelthMovementParams {
    s32 unk_0;
    f32 speed;
    s32 turn;
};

struct TObjEneMe3Stelth : public TObjEneDD_ST {
    TObjEneMe3Stelth(TObject *parent);
    virtual ~TObjEneMe3Stelth();
    virtual s32 vfunc_104(f32);
    virtual f32 receive_direct_attack(void *source, DirectAttackPayload payload, void *collider, s32 technique, s32 flags);
    virtual void dispatch_action(u32 state, s32 reason);
    virtual void vfunc_88();
    virtual void vfunc_95();
    virtual void vfunc_96();
    virtual void vfunc_89();
    virtual void attack_and_unequip();
    virtual s32 check_target_in_range();
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
    s32 test_body_collision(s32, f32);
    s32 sub_800F4850();
    s32 is_angle_in_range();
    s32 sub_800F47D4();
    void sub_800F4758();
    void sub_800F42B8(s32);
    void vfunc_63();
    void vfunc_62();
    void vfunc_61();
    void vfunc_28();
    void render();
    void run_task();
    // TObjEneDD fields its header does not declare yet (TObjEneBm5Wolf declares the same ones).
    u8 unk_374[0x4];
    s32 m_378;
    f32 m_37c;
    u8 unk_380[0x10];
    TObjChara *target;
    Vec m_394;
    f32 m_3a0;
    u8 unk_3A4[0x4];
    f32 m_3a8;
    f32 m_3ac;
    u8 unk_3B0[0x10];
    s32 m_3c0;
    s32 m_3c4;
    s32 m_3c8;
    s32 m_3cc;
    f32 m_3d0;
    f32 m_3d4;
    f32 m_3d8;
    f32 m_3dc;
    f32 m_3e0;
    f32 m_3e4;
    s32 m_3e8;
    s32 m_3ec;
    s32 m_3f0;
    s16 m_3f4;
    u8 unk_3F6[0x2];
    Vec m_3f8;
    TUnk_80494938 m_404;
    s32 m_420;
    s32 m_424;
    s32 m_428;
    s32 m_42c;
    f32 m_430;
    f32 m_434;
    f32 m_438;
    f32 m_43c;
    f32 m_440;
    TObject *m_444;
    TObject *m_448;
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

typedef char TObjEneMe3Stelth_size[sizeof(TObjEneMe3Stelth) == 0x44C ? 1 : -1];

extern "C" {
void TObjEneMe3Stelth__sub_800F0C90(TObjEneMe3Stelth *stelth);
s32 TObjEneMe3Stelth__sub_800F0F84(TObjEneMe3Stelth *stelth, Vec *pos);
void TObjEneMe3Stelth__sub_800F1098(TObjEneMe3Stelth *stelth, s32 arg1);
void TObjEneMe3Stelth__sub_800F1440(TObjEneMe3Stelth *stelth, s32 arg1);
void exec__16TObjEneMe3StelthFPvi(TObjEneMe3Stelth *stelth, s32 arg1);
}

#endif
