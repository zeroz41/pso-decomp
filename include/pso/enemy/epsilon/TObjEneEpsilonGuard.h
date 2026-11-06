#ifndef PSO_ENEMY_EPSILON_TOBJENEEPSILONGUARD_H
#define PSO_ENEMY_EPSILON_TOBJENEEPSILONGUARD_H

#include "types.h"
#include "pso/enemy/epsilon/TObjEneEpsilon.h"

struct TObjEneEpsilonGuard : public TObjEneEpsilon {
    virtual ~TObjEneEpsilonGuard();
    void sub_803626A8(s32, s32);
    void update_guard_state();
    void sub_8035EA90();
    void handle_event(s32);
    void render_guard_effect();
    virtual void vfunc_88();
    virtual void vfunc_89();
    virtual f32 receive_physical_attack(void *, f32);
    virtual f32 receive_weapon_special_attack(void *, void *);
    void vfunc_63();
    void vfunc_62();
    void vfunc_61();
    void vfunc_28();
    void render();
    void run_task();
    u8 pad_430[0x10];
    TObject *emitter;          // 0x440: queued for destruction with the guard
    u8 pad_444[0x18];
    TObjCollidable *collider;  // 0x45C: the second collision body (model_desc[1]), built in init_model_and_state
    u8 pad_460[0xC];
    s32 flags;                 // 0x46C: state bits; bit 4 while it follows the body
    u16 body_id;               // 0x470: entity id of the TObjEneEpsilonBody that spawned it
    u8 pad_472[0x32];
    void *create(void *arg1, void *arg2, void *arg3, void *arg4);
    void init_model_and_state();
    s32 all_children_gone();
    static void update_attack_pattern(void *arg0);
    static void record_camera_angle_samples();
    void draw_debug_line();
    static s32 create_damage_font(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    static void free_shared_resources();
    static void load_assets();
    u8 pad_4A4[0x34];
    s32 is_guard_active();
    s32 is_state_flag_set();
    s32 is_guard_ready();
    void clear_and_flag_state();
    void set_flag_8_and_notify();
    void set_target(s32 arg1, s32 arg2, s32 arg3);
    static void advance_camera_ctrl_step();
    void handle_message(s32 arg1);
    void handle_break_state(s32 arg1);
    void state_orbit(s32 arg1);
    void update_center_position();
    s32 calc_angle_to_target();
    void set_orbit_destination(s32 arg1);
    s32 assign_guard_targets();
    void handle_warp_state(s32 arg1);
};

typedef char TObjEneEpsilonGuard_size[sizeof(TObjEneEpsilonGuard) == 0x4D8 ? 1 : -1];
#endif
