#ifndef PSO_ENEMY_STELTH_TOBJENEME3STELTH_H
#define PSO_ENEMY_STELTH_TOBJENEME3STELTH_H

#include "types.h"
#include <stddef.h>
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
    virtual s32 acquire_target(f32);
    virtual f32 receive_direct_attack(void *source, DirectAttackPayload payload, void *collider, s32 technique, s32 flags);
    virtual void dispatch_action(u32 state, s32 reason);
    virtual void update_body_colliders();
    virtual void set_intangible();
    virtual void clear_intangible();
    virtual void check_collisions();
    virtual void attack_and_unequip();
    virtual s32 check_target_in_range();
    virtual void select_next_attack_state();
    virtual void vfunc_108();
    virtual s32 check_active_flag();
    virtual s32 check_flag();
    virtual void on_target_lost();
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
    void run_death_reaction();
    void run_hit_reaction();
    void run_miss_reaction();
    void refresh_target();
    void render();
    void run_task();
    // TObjEneDD fields its header does not declare yet (TObjEneBm5Wolf declares the same ones).
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
    s32 try_spawn_ground_effect(const Vec *origin);
    void play_hit_effect();
    void spawn_ground_effect_on_frame_23();
    static void add_instance(NJS_OBJECT *node);
    void update_distance_state();
    static void set_slot_min_clamped_value(s32 arg0, f32 farg0);
    static void free_shared_resources();
    void *create_real();
    static void load_shared_resources();
    void handle_breakup_state(s32 reason);
    void update_state_resta_cast(s32 reason);
    void state_chase_target(s32 arg1);
    void update_state_drop(s32 reason);
    void update_state_fade_in(s32 reason);
    void state_chase(s32 arg1);
    void create_resta_effect();
    void run_walk_state(s32 reason);
    void exec(s32 arg1);
    void handle_message(s32 arg1);
};

LAYOUT_ASSERT(TObjEneMe3StelthFadeOffset, offsetof(TObjEneMe3Stelth, m_404) == 0x404);
LAYOUT_ASSERT(TObjEneMe3Stelth_size, sizeof(TObjEneMe3Stelth) == 0x44C);

extern "C" {
void TObjEneMe3Stelth__sub_800F0C90(TObjEneMe3Stelth *stelth);
s32 TObjEneMe3Stelth__sub_800F0F84(TObjEneMe3Stelth *stelth, Vec *pos);
void TObjEneMe3Stelth__sub_800F1098(TObjEneMe3Stelth *stelth, s32 reason);
void TObjEneMe3Stelth__sub_800F1440(TObjEneMe3Stelth *stelth, s32 reason);
void exec__16TObjEneMe3StelthFl(TObjEneMe3Stelth *stelth, s32 arg1);
}

#endif
